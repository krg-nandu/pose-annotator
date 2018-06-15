#ifndef __TinyOgre_h_
#define __TinyOgre_h_

#include <OGRE/OgreRoot.h>
#include <OGRE/OgreCamera.h>
#include <OGRE/OgreSceneManager.h>
#include <OGRE/OgreRenderWindow.h>
#include <OGRE/OgreLogManager.h>
#include <OGRE/OgreViewport.h>
#include <OGRE/OgreConfigFile.h>
#include <OGRE/OgreEntity.h>
#include <OGRE/OgreWindowEventUtilities.h>

struct MonkeyRenderer
{
	Ogre::Root *mRoot;
	Ogre::Camera* mCamera;
	Ogre::SceneManager* mSceneMgr;
	Ogre::RenderWindow* mWindow;
    Ogre::Entity* monkeyEntity;
    Ogre::SceneNode* monkeyNode;

    MonkeyRenderer(void) :
		mRoot(0), mCamera(0), mSceneMgr(0), mWindow(0)
	{
	}
	
    virtual ~MonkeyRenderer(void) {
		delete mRoot;
	}

	bool Init(void)
	{
		mRoot = new Ogre::Root("plugins.cfg");
		Ogre::ConfigFile cf;
		// load the resources file
		cf.load("resources.cfg");

		Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
		Ogre::String secName, typeName, archName;
		while (seci.hasMoreElements())
		{
			secName = seci.peekNextKey();
			Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
			Ogre::ConfigFile::SettingsMultiMap::iterator i;
			for (i = settings->begin(); i != settings->end(); ++i)
			{
				typeName = i->first;
				archName = i->second;
				Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
					archName, typeName, secName);
			}
		}
		
		if (mRoot->restoreConfig() || mRoot->showConfigDialog())
		{
			// If returned true, user clicked OK so initialise
			// Here we choose to let the system create a default rendering window by passing 'true'
			mWindow = mRoot->initialise(true, "Monkey Render Window");
		}
		else
		{
			return false;
		}

		//-------------------------------------------------------------------------------------
		// choose scenemanager
		// Get the SceneManager, in this case a generic one
		mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);
		// Create a camera
		mCamera = mSceneMgr->createCamera("MonkeyCamera");

		//mCamera->setPosition(Ogre::Vector3(0, 0, 0));
		//mCamera->lookAt(Ogre::Vector3(0, 0, -1));

		mCamera->setPosition(Ogre::Vector3(0, 0, 0));
		//mCamera->lookAt(Ogre::Vector3(-1, 0, 0));
		mCamera->lookAt(Ogre::Vector3(0, 0, -1));

		mCamera->setNearClipDistance(5);

		Ogre::Viewport* vp = mWindow->addViewport(mCamera);
		vp->setBackgroundColour(Ogre::ColourValue(1, 1, 1));
		mCamera->setAspectRatio(
			Ogre::Real(vp->getActualWidth())
			/ Ogre::Real(vp->getActualHeight()));
		//-------------------------------------------------------------------------------------
		// Set default mipmap level (NB some APIs ignore this)
		Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
		Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
		
        monkeyEntity = mSceneMgr->createEntity("Monkey", "MonkeyMESHMesh.mesh"); ///
        monkeyNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		
        monkeyNode->attachObject(monkeyEntity);
        //monkeyNode->setPosition(-1200, 0, 0);
        monkeyNode->setPosition(0, 0, -1200);

        //monkeyNode->setScale(40, 40, 40);
        //monkeyNode->setScale(500, 500, 500);
        //monkeyNode->setScale(7.5, 7.5, 7.5);
        monkeyNode->setScale(6., 6., 6.);

		// Set ambient light
		mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

		return true;
	}

	bool RenderOneFrame()
	{
		Ogre::WindowEventUtilities::messagePump();

		if (mWindow->isClosed())
		{
			return false;
		}

		// Render a frame
		return mRoot->renderOneFrame();
	}
};

#endif // #ifndef __TinyOgre_h_
