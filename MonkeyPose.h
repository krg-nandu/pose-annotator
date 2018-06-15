#ifndef MONKEYPOSE_HPP_
#define MONKEYPOSE_HPP_

#include "MonkeyRender.h"
#include <OGRE/OgreManualObject.h>
#include <fstream>
#include <GL/freeglut.h>
#include <vector>
#include "Utility.h"
#include <opencv2/opencv.hpp>

namespace MonkeyPose_
{
	using namespace Ogre;
	using namespace std;

    struct MonkeyPose
	{
		// the tiny ogre renderer
        MonkeyRenderer monkey_renderer;
		// storing the index of the joints to be controlled
		std::vector<int> backbone;
		// number of bones (technically!)
		int nJoint;

		SceneNode *root;
        SceneNode* monkey_node;
        Entity* monkey_entity;
		SceneManager *sceneMgr;
		Skeleton* skeleton;

		std::vector<ManualObject*> vec_axis;
		std::vector<SceneNode*> vec_node;
		std::vector<Quaternion> vec_jointBase;
		std::vector<Quaternion> vec_jointRotate;
		Ogre::Vector3 orgscale;

		IplImage *depth;
		IplImage *rgb;
		IplImage *shortdepth;

		ManualObject *depthmap;

        MonkeyPose(float focal, int width = 512, int height = 424) :
			depthmap(0)
		{

			// init render
            monkey_renderer.Init();

			depth = cvCreateImage(cvSize(width, height), 32, 1);
			rgb = cvCreateImage(cvSize(width, height), 8, 3);
			shortdepth = cvCreateImage(cvSize(width, height), 16, 1);

			// init camera
			float fovy = atan(height/2/focal) * 2;
			std::cout << fovy << std::endl;
            monkey_renderer.mCamera->setFOVy(Radian(fovy));
            monkey_renderer.mCamera->setPosition(0, 0, 0);
            monkey_renderer.mCamera->lookAt(0, 0, -1);

            // init monkey_node
            monkey_node = monkey_renderer.monkeyNode;
            Utility_Check(monkey_node);

            sceneMgr = monkey_renderer.mSceneMgr;
			root = sceneMgr->getRootSceneNode();
            monkey_entity = monkey_renderer.monkeyEntity;

            Utility_Check(monkey_entity);
            Utility_Check(monkey_entity->hasSkeleton());

			// obtaining the skeleton
            skeleton = monkey_entity->getSkeleton();

			nJoint = skeleton->getNumBones();
			cout << "nJoint: "<< nJoint << endl;

            orgscale = monkey_node->getScale();

			for (int i = 0; i < nJoint; i++)
			{
				// set manually operate
				skeleton->getBone(i)->setManuallyControlled(true);

				//setting inherit orientation
				//skeleton->getBone(i)->setInheritOrientation(true);

				//cout << skeleton->getBone(i)->getName() << endl;

				// all joints to be controlled (for now)
				backbone.push_back(i);
			}

			// init axis
			float sz_axis = 50; //100
			for (int i = 0; i < nJoint + 1; i++)
			{
				char buf[128];
				sprintf(buf, "axis%d", i);
				vec_axis.push_back(sceneMgr->createManualObject(buf));

				vec_axis[i]->begin("BaseWhiteNoLighting",
					RenderOperation::OT_LINE_LIST);

				vec_axis[i]->position(0, 0, 0);
				vec_axis[i]->colour(1, 0, 0, 1);
				vec_axis[i]->position(sz_axis, 0, 0);
				vec_axis[i]->colour(1, 0, 0, 1);
				vec_axis[i]->position(0, 0, 0);
				vec_axis[i]->colour(0, 1, 0, 1);
				vec_axis[i]->position(0, sz_axis, 0);
				vec_axis[i]->colour(0, 1, 0, 1);
				vec_axis[i]->position(0, 0, 0);
				vec_axis[i]->colour(0, 0, 1, 1);
				vec_axis[i]->position(0, 0, sz_axis);
				vec_axis[i]->colour(0, 0, 1, 1);
				vec_axis[i]->end();

				sprintf(buf, "node%d", i);
				vec_node.push_back(root->createChildSceneNode(buf));
				vec_node[i]->attachObject(vec_axis[i]);
				vec_node[i]->setVisible(false);
			}

			// init jointBase and jointRotate
			for (int i = 0; i < nJoint; i++)
			{
				Bone* bone = skeleton->getBone(i);
				Utility_Check(bone);

				vec_jointBase.push_back(bone->getOrientation());
				//cout << i << ": " << bone->getPosition() << endl;
				vec_jointRotate.push_back(Quaternion::IDENTITY);
			}

		}

        ~MonkeyPose()
		{
			if (shortdepth)
			{
				cvReleaseImage(&shortdepth);
			}
			if (depth)
			{
				cvReleaseImage(&depth);
			}
			if (rgb)
			{
				cvReleaseImage(&rgb);
			}
		}

		void Render()
		{
            monkey_renderer.RenderOneFrame();
			glReadPixels(0, 0, depth->width, depth->height, GL_DEPTH_COMPONENT,
				GL_FLOAT, depth->imageData);
			glReadPixels(0, 0, rgb->width, rgb->height, GL_BGR_EXT, GL_UNSIGNED_BYTE,
				rgb->imageData);
			cvFlip(rgb, rgb, 0);
			cvFlip(depth, depth, 0);
            float d1 = monkey_renderer.mCamera->getNearClipDistance();
            float d2 = monkey_renderer.mCamera->getFarClipDistance();
			cvConvertScale(depth, shortdepth, d2 - d1, d1);
		}

		void ShowJoints(int i)
		{
			Bone* bone = skeleton->getBone(i);			
			Vector3 a = bone->convertLocalToWorldPosition(Vector3::ZERO);
            a = monkey_node->convertLocalToWorldPosition(a);
			
			cout << a << endl;

			Quaternion b = bone->convertLocalToWorldOrientation(Quaternion::IDENTITY);

			vec_node[i]->setPosition(a);
			vec_node[i]->setOrientation(vec_jointBase[i]*b);
			vec_node[i]->setVisible(true);
		}

		void HideJoints()
		{
			for (int i = 0; i < nJoint; i++)
			{
				vec_node[i]->setVisible(false);
			}
		}

		double fRand (double fMin, double fMax)
		{
			double f = (double)rand()/(RAND_MAX + 1);
			return fMin + f*(fMax - fMin);
		}

		void SetPose(std::vector<float> &param, bool inPlane)
		{
			// Just randomize scale for now. Later add to param properly
			double scale = fRand(0.8,1.1);
            monkey_node->setScale(orgscale * scale);

			int idx;
			cout << "Entering SETPOSE... \n";
			for (int i = 0; i < param.size(); i++)
			{
				float ang = param[i];
				Matrix3 mat;

				idx = backbone[i];
				//cout << "IDX: " << idx << "ANG: " << ang <<"\n";

				if (!inPlane && i==0) {
					float opAngle = ((double) 120*rand()/(RAND_MAX)) - 60;
					mat.FromEulerAnglesXYZ(Degree(ang), Degree(0), Degree(opAngle));
				}
				else {
					mat.FromEulerAnglesXYZ(Degree(ang), Degree(0), Degree(0));
				}
				
				vec_jointRotate[idx].FromRotationMatrix(mat);
				skeleton->getBone(idx)->setOrientation( vec_jointBase[idx] * vec_jointRotate[idx] );
				//if (ang != 0)
				//	ShowJoints(i);
			}
		}

		Ogre::Vector3 GetJointPosition(int joint)
		{
			Bone* bone = skeleton->getBone(joint);			
			Vector3 pos = bone->convertLocalToWorldPosition(Vector3::ZERO);
            pos = monkey_node->convertLocalToWorldPosition(pos);
			return pos;
		}

		void SetJointOrientation(int joint, float x, float y, float z)
		{
			Matrix3 mat;
			mat.FromEulerAnglesXYZ(Degree(x), Degree(y), Degree(z));
			vec_jointRotate[joint].FromRotationMatrix(mat);
			skeleton->getBone(joint)->setOrientation( vec_jointBase[joint] * vec_jointRotate[joint] );	

		}

		/*
		std::vector<float> GetParam(const char *filename)///?
		{
		std::vector<float> param;
		ifstream f(filename);

		for (int i = 0; i < 1; i++)
		{
		char buf[512];
		f.getline(buf, 512);
		istringstream s(buf);
		float b1, b2, b3;
		s >> b1 >> b2 >> b3;
		param.push_back(b1);
		param.push_back(b2);
		param.push_back(b3);
		}
		return param;
		}

		void ReadParam(const char *filename)///?
		{
		ifstream f(filename);
		for (int i = 0; i < 1; i++)
		{
		char buf[512];
		f.getline(buf, 512);
		istringstream s(buf);
		float b1, b2, b3;
		s >> b1 >> b2 >> b3;
		cout << b1 << "," << b2 << "," << b3 << endl;

		int idx = idxFinger[i];
		Matrix3 mat;

		mat.FromEulerAnglesXYZ(Degree(b1), Degree(0), Degree(0));
		vec_jointRotate[idx].FromRotationMatrix(mat);
		skeleton->getBone(idx)->setOrientation(
		vec_jointBase[idx] * vec_jointRotate[idx]);

		idx++;
		mat.FromEulerAnglesXYZ(Degree(b2), Degree(0), Degree(0));
		vec_jointRotate[idx].FromRotationMatrix(mat);
		skeleton->getBone(idx)->setOrientation(
		vec_jointBase[idx] * vec_jointRotate[idx]);

		idx++;
		mat.FromEulerAnglesXYZ(Degree(b3), Degree(0), Degree(0));
		vec_jointRotate[idx].FromRotationMatrix(mat);
		skeleton->getBone(idx)->setOrientation(
		vec_jointBase[idx] * vec_jointRotate[idx]);
		}
		}

		void WriteParam(const char *filename)
		{
		ofstream f(filename);
		Radian x, y, z;
		Matrix3 mat;
		for (int i = 0; i < 1; i++)
		{
		int idx = idxFinger[i];

		vec_jointRotate[idx].ToRotationMatrix(mat);
		mat.ToEulerAnglesXYZ(x, y, z);
		f << Degree(z).valueDegrees() << "\t" << Degree(x).valueDegrees()
		<< "\t";

		vec_jointRotate[idx + 1].ToRotationMatrix(mat);
		mat.ToEulerAnglesXYZ(x, y, z);
		f << Degree(x).valueDegrees() << "\t";

		vec_jointRotate[idx + 2].ToRotationMatrix(mat);
		mat.ToEulerAnglesXYZ(x, y, z);
		f << Degree(x).valueDegrees() << endl;
		}
		}
		*/

		//! mix two poses by weight
		static std::vector<float> MixParam(std::vector<float> &a,
			std::vector<float> &b, float w)
		{
			int n = a.size();
			std::vector<float> c(n);
			Utility_Check(a.size() == b.size());
			for (int i = 0; i < n; i++)
			{
				c[i] = a[i] * (1 - w) + b[i] * w;
			}
			return c;
		}

		//! mix two poses by a list of weights
		static std::vector<float> MixParam(std::vector<float> &a,
			std::vector<float> &b, std::vector<float> &w)
		{
			int n = a.size();
			std::vector<float> c(n);
			Utility_Check(a.size() == b.size());
			Utility_Check(a.size() == w.size());
			for (int i = 0; i < n; i++)
			{
				c[i] = a[i] * (1 - w[i]) + b[i] * w[i];
			}
			return c;
		}
	};

	inline Quaternion EulerXYZ(Radian x, Radian y, Radian z)
	{
		Matrix3 mat;
		mat.FromEulerAnglesXYZ(x, y, z);
		Quaternion rot;
		rot.FromRotationMatrix(mat);
		return rot;
	}
}
#endif /* MONKEYPOSE_HPP_ */
