#ifndef IMGPROC_HPP_
#define IMGPROC_HPP_

#include <stdio.h>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <fstream>

namespace IMGShow
{
// set short or float image
inline cv::Mat cvtimage(cv::Mat img, double a = 0, double b = 0)
{
    if (a == 0 && b == 0)
        cv::minMaxLoc(img, &a, &b);

    double alpha = 255 / (b - a);
    double beta = -a * 255 / (b - a);
    cv::Mat color;
    img.convertTo(color, CV_8UC3, alpha, beta);

    if (color.channels() == 1)
        cv::cvtColor(color, color, CV_GRAY2BGR);

    return color;
}
inline cv::Mat colormap(cv::Mat img, double a = 0, double b = 0, bool gray = false)
{
    cv::Mat color;
    if (img.depth() == CV_8UC3 || img.depth() == CV_8UC1)
        color = img.clone();
    else
        color = cvtimage(img, a, b);
    if (gray) {
        cv::applyColorMap(color, color, cv::COLORMAP_BONE);
    }
    else {
        cv::applyColorMap(color, color, cv::COLORMAP_JET);
    }
    return color;
}

inline void ShowFloatImage(const char * winname, IplImage *f, float a = 0,
                           float b = 0)
{
    if (a == 0 && b == 0)
    {
        double da, db;
        cv::minMaxLoc(cv::Mat(f), &da, &db);
        a = da;
        b = db;
    }
    float scale = 255 / (b - a);
    float base = -a * 255 / (b - a);
    IplImage *c = cvCreateImage(cvGetSize(f), 8, f->nChannels);
    cvConvertScale(f, c, scale, base);
    cvShowImage(winname, c);
    cvReleaseImage(&c);
}
inline void ShowShortImage(const char * winname, IplImage *src, float a = 0,
                           float b = 0)
{
    if (a == 0 && b == 0)
    {
        double da, db;
        cv::minMaxLoc(cv::Mat(src), &da, &db);
        a = da;
        b = db;
    }
    float scale = 255 / (b - a);
    float base = -a * 255 / (b - a);
    IplImage *c = cvCreateImage(cvGetSize(src), 8, src->nChannels);
    cvConvertScale(src, c, scale, base);
    cvShowImage(winname, c);
    cvReleaseImage(&c);
}
inline void ShowShortImage(const char * winname, IplImage src, float a = 0,
                           float b = 0)
{
    ShowShortImage(winname, &src, a, b);
}
inline void ShowFloatImage(const char * winname, IplImage src, float a = 0,
                           float b = 0)
{
    ShowFloatImage(winname, &src, a, b);
}

inline void CvtFloatImage(IplImage *src, IplImage *dst, double a = 0, double b =
        0)
{
    if (a == 0 && b == 0)
    {
        cv::minMaxLoc(cv::Mat(src), &a, &b);
    }
    float scale = 255 / (b - a);
    float base = -a * 255 / (b - a);
    cvConvertScale(src, dst, scale, base);
}

inline void CvtFloatImage(cv::Mat &src, cv::Mat &dst, double a = 0,
                          double b = 0)
{
    if (a == 0 && b == 0)
    {
        cv::minMaxLoc(src, &a, &b);
    }
    double scale = 255 / (b - a);
    double base = -a * 255 / (b - a);
    src.convertTo(dst, CV_8UC1, scale, base);
}

inline void CvtShortImage(IplImage *src, IplImage *dst, double a = 0, double b =
        0)
{
    if (a == 0 && b == 0)
    {
        cv::minMaxLoc(cv::Mat(src), &a, &b);
    }
    double scale = 255 / (b - a);
    double base = -a * 255 / (b - a);
    cvConvertScale(src, dst, scale, base);
}

inline void CvtShortImage(cv::Mat &src, cv::Mat &dst, double a = 0,
                          double b = 0)
{
    if (a == 0 && b == 0)
    {
        cv::minMaxLoc(src, &a, &b);
    }
    double scale = 255 / (b - a);
    double base = -a * 255 / (b - a);
    src.convertTo(dst, CV_8UC1, scale, base);
}

//inline void CvtShortImageColor(IplImage *src, IplImage *dst, double a = 0,
//                               double b = 0)
//{
//    if (a == 0 && b == 0)
//    {
//        cv::minMaxLoc(cv::Mat(src), &a, &b);
//    }
//    double scale = 255 / (b - a);
//    double base = -a * 255 / (b - a);
//    IMGT<uchar> gray(cvGetSize(src), 8, 1);
//    cvConvertScale(src, gray, scale, base);
//    cvCvtColor(gray, dst, CV_GRAY2BGR);
//}

inline IplImage* OverlapImages(IplImage *src1, IplImage *src2)
{
    Utility_Check(src1->nChannels == src2->nChannels);
    Utility_Check(src1->depth == src2->depth);
    Utility_Check(src1->width == src2->width);
    Utility_Check(src1->height == src2->height);

    IplImage *dst = cvCreateImage(cvGetSize(src1), src1->depth,
                                  src1->nChannels);
    cvZero(dst);

    if (src1->depth == 8)
    {
        uchar *p1 = (uchar*) src1->imageData;
        uchar *p2 = (uchar*) src2->imageData;
        uchar *p3 = (uchar*) dst->imageData;
        for (int row = 0; row < src1->height; row++)
        {
            for (int col = 0; col < src1->widthStep; col++)
            {
                p3[col] = 0.5 * p1[col] + 0.5 * p2[col];
            }
            p1 += src1->widthStep;
            p2 += src1->widthStep;
            p3 += src1->widthStep;
        }
    }
    else if (src1->depth == IPL_DEPTH_16S)
    {
        short *p1 = (short*) src1->imageData;
        short *p2 = (short*) src2->imageData;
        short *p3 = (short*) dst->imageData;
        for (int row = 0; row < src1->height; row++)
        {
            for (int col = 0; col < src1->widthStep / 2; col++)
            {
                p3[col] = 0.5 * p1[col] + 0.5 * p2[col];
            }
            p1 += src1->widthStep;
            p2 += src1->widthStep;
            p3 += src1->widthStep;
        }
    }
    else if (src1->depth == IPL_DEPTH_32F)
    {
        float *p1 = (float*) src1->imageData;
        float *p2 = (float*) src2->imageData;
        float *p3 = (float*) dst->imageData;
        for (int row = 0; row < src1->height; row++)
        {
            for (int col = 0; col < src1->widthStep / 4; col++)
            {
                p3[col] = 0.5 * p1[col] + 0.5 * p2[col];
            }
            p1 += src1->widthStep;
            p2 += src1->widthStep;
            p3 += src1->widthStep;
        }
    }

    return dst;
}

//! merge 2 image side-by-side (flag = 0), or up-down (flag = 1)
inline IplImage* MergeImages(IplImage *src1, IplImage *src2, int flag = 0)
{
    Utility_Check(src1->nChannels == src2->nChannels);
    Utility_Check(src1->depth == src2->depth);

    IplImage *dst;

    if (flag == 0) // merge images side-by-side
    {
        int width = src1->width + src2->width;
        int height = MAX(src1->height, src2->height);

        dst = cvCreateImage(cvSize(width, height), src1->depth,
                            src1->nChannels);
        cvZero(dst);

        cvSetImageROI(dst, cvRect(0, 0, src1->width, src1->height));
        cvCopy(src1, dst);
        cvResetImageROI(dst);
        cvSetImageROI(dst, cvRect(src1->width, 0, src2->width, src2->height));
        cvCopy(src2, dst);
        cvResetImageROI(dst);
    }
    else if (flag == 1) // merge images up-down
    {
        int width = MAX(src1->width, src2->width);
        int height = src1->height + src2->height;

        dst = cvCreateImage(cvSize(width, height), src1->depth,
                            src1->nChannels);
        cvZero(dst);

        cvSetImageROI(dst, cvRect(0, 0, src1->width, src1->height));
        cvCopy(src1, dst);
        cvResetImageROI(dst);
        cvSetImageROI(dst, cvRect(0, src1->height, src2->width, src2->height));
        cvCopy(src2, dst);
        cvResetImageROI(dst);
    }

    return dst;
}

inline IplImage* MergeImages(IplImage src1, IplImage src2, int flag = 0)
{
    return MergeImages(&src1, &src2, flag);
}
}

struct vec3f
{
	union
	{
		struct
		{
			float x, y, z;
		};
		float val[3];
	};
	vec3f()
	{
	}
	vec3f(float x_, float y_, float z_)
	{
		val[0] = x_;
		val[1] = y_;
		val[2] = z_;
	}
	/*
	vec3f(Eigen::Vector3f pos)
	{
		memcpy(val, pos.data(), sizeof(vec3f));
	}
	operator Eigen::Vector3f()
	{
		Eigen::Vector3f pos;
		memcpy(pos.data(), val, sizeof(vec3f));
		return pos;
	}
	*/
	float& operator [](int i)
	{
		return val[i];
	}
	vec3f cross(vec3f b)
	{
		vec3f c;
		c[0] = val[1] * b[2] - val[2] * b[1];
		c[1] = val[2] * b[0] - val[0] * b[2];
		c[2] = val[0] * b[1] - val[1] * b[0];
		return c;
	}
	vec3f scale(vec3f b)
	{
		vec3f c;
		c.x = x * b.x;
		c.y = y * b.y;
		c.z = z * b.z;
		return c;
	}
	vec3f operator *(float b)
	{
		vec3f c;
		c[0] = val[0] * b;
		c[1] = val[1] * b;
		c[2] = val[2] * b;
		return c;
	}
	void operator *=(float b)
	{
		val[0] *= b;
		val[1] *= b;
		val[2] *= b;
	}
	vec3f operator -(vec3f b)
	{
		vec3f c;
		c[0] = val[0] - b[0];
		c[1] = val[1] - b[1];
		c[2] = val[2] - b[2];
		return c;
	}
	vec3f operator +(vec3f b)
	{
		vec3f c;
		c[0] = val[0] + b[0];
		c[1] = val[1] + b[1];
		c[2] = val[2] + b[2];
		return c;
	}
	void operator +=(vec3f b)
	{
		val[0] += b[0];
		val[1] += b[1];
		val[2] += b[2];
	}
    void operator -=(vec3f b)
    {
        val[0] -= b[0];
        val[1] -= b[1];
        val[2] -= b[2];
    }
	float normalize()
	{
		float n = norm();
		float invn = 1.f / n;
		val[0] *= invn;
		val[1] *= invn;
		val[2] *= invn;
		return n;
	}
	float norm() const
	{
		return sqrt(val[0] * val[0] + val[1] * val[1] + val[2] * val[2]);
	}
	float dot(vec3f b)
	{
		return b[0] * val[0] + b[1] * val[1] + b[2] * val[2];
	}
	float DistTo(vec3f b)
	{
		float dx = x - b.x;
		float dy = y - b.y;
		float dz = z - b.z;
		return sqrt(dx * dx + dy * dy + dz * dz);
	}
};

//! An operation structure for IplImage
struct IMG
{
	IplImage *img;
	bool auto_release; //!< whether to release img when IMG is destroyed, it is 0 by default
	int pixel_size; //!< size of a pixel, for example, for a float image, pixel_size = sizeof(float)*nChannels
	IplImage MatImg;

	//! \param [in] src IplImage
	//! \param [in] auto_release_ whether to release img when IMG is destroyed
	IMG(IplImage *src = NULL, bool auto_release_ = false) :
			img(src), auto_release(auto_release_)
	{
		if (src)
			CalPixelSize();
	}

	IMG(cv::Mat &src)
	{
		auto_release = false;
		MatImg = src;
		img = &MatImg;
		CalPixelSize();
	}

	IMG(CvSize sz, int depth, int channels, bool auto_release_ = true)
	{
		img = cvCreateImage(sz, depth, channels);
		auto_release = auto_release_;
		CalPixelSize();
	}

	void Create(CvSize sz, int depth, int channels, bool auto_release_ = true)
	{
		Clear();
		img = cvCreateImage(sz, depth, channels);
		auto_release = auto_release_;
		CalPixelSize();
	}

	void Resize(CvSize sz)
	{
        if (sz.width == img->width && sz.height == img->height)
            return;

        Create(sz, img->depth, img->nChannels, auto_release);
	}

	void Clone(IplImage *src)
	{
		Clear();
		img = cvCloneImage(src);
		auto_release = true;
		CalPixelSize();
	}

	void ReferTo(IplImage *src)
	{
		Clear();
		img = src;
		auto_release = false;
		CalPixelSize();
	}

	~IMG()
	{
		Clear();
	}

	//! convert to IplImage*
	operator IplImage*()
	{
		return img;
	}

	//! access a given pixel in image
	inline uchar* operator ()(int row, int col, const int check = 0)
	{
		if (check)
			ValidPixel(row, col);
		return (uchar *) img->imageData + row * img->widthStep + col * pixel_size;
	}

	//! access a given line in image
	inline uchar *Line(int row)
	{
		return (uchar *) img->imageData + row * img->widthStep;
	}

	void ValidPixel(int &row, int &col)
	{
		row = MAX(0,row);
		col = MAX(0,col);
		row = MIN(img->height-1,row);
		col = MIN(img->width-1,col);
	}
private:
	void CalPixelSize()
	{
		pixel_size = img->nChannels;
		if (img->depth == IPL_DEPTH_16S || img->depth == IPL_DEPTH_16U)
			pixel_size = 2 * img->nChannels;
		if (img->depth == IPL_DEPTH_32S || img->depth == IPL_DEPTH_32F)
			pixel_size = 4 * img->nChannels;
		if (img->depth == IPL_DEPTH_64F)
			pixel_size = 8 * img->nChannels;
	}
	void Clear()
	{
		if (auto_release && img)
			cvReleaseImage(&img);
	}
};

template<class T>
struct IMGT: IMG
{
	IMGT(IplImage *src = NULL, bool auto_release_ = false) :
			IMG(src, auto_release_)
	{
	}

	IMGT(CvSize sz, int depth, int channels, bool auto_release_ = true) :
			IMG(sz, depth, channels, auto_release_)
	{
	}

	IMGT(cv::Mat &src) :
			IMG(src)
	{
	}

	inline T& operator ()(int row, int col, const int check = 0)
	{
		if (check)
			ValidPixel(row, col);
		return *(T *) (img->imageData + row * img->widthStep + col * pixel_size);
	}

	inline T *Line(int row)
	{
		return (T *) img->imageData + row * img->widthStep;
	}

	inline T *Ptr()
	{
		return (T*) img->imageData;
	}
};


namespace ImgProcDepth
{
//! convert depthmap from cameracenter to kinect format
//! \param [in] depthKN short image
//! \param [out] depthCC float image
//! \param [in] focal
inline void CvtDepthKN2CC(IplImage *depthKN, IplImage *depthCC, const float focal)
{
	//Utility_Check( (depthKN->depth == 16) && (depthCC->depth == IPL_DEPTH_32F));

	const int width = depthCC->width;
	const int height = depthCC->height;
	const float cx = float(width) * 0.5f;
	const float cy = float(height) * 0.5f;
	const float invFocal = 1.f / focal;
	IMGT<float> CC(depthCC);
	IMGT<short> KN(depthKN);
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			vec3f pt(col - cx, row - cy, focal);
			pt *= invFocal * KN(row, col);
			CC(row, col) = pt.norm();
		}
	}
}
//! convert depthmap from cameracenter to kinect format
//! \param [in] depthCC float image
//! \param [out] depthKN short image
//! \param [in] focal
inline void CvtDepthCC2KN(IplImage *depthCC, IplImage *depthKN, const float focal)
{
	//Utility_Check( (depthKN->depth == 16) && (depthCC->depth == IPL_DEPTH_32F));

	const int width = depthCC->width;
	const int height = depthCC->height;
	const float cx = float(width) * 0.5f;
	const float cy = float(height) * 0.5f;
	IMGT<float> CC(depthCC);
	IMGT<short> KN(depthKN);
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			vec3f pt(col - cx, row - cy, focal);
			//pt *= CC(row, col) / pt.norm();
			pt *= CC(row, col) / focal;
			//std::cout << pt.norm() << std::endl;
			KN(row, col) = pt.z;
		}
	}
}
//! convert depthmap from opengl to cameracenter format
//! \param [in] depthGL
//! \param [out] depthCC
//! \param [in] d1 near plane
//! \param [in] d2 far plane
inline void CvtDepthGL2CC(IplImage *depthGL, IplImage *depthCC, const float d1, const float d2)
{
	//Utility_Check( depthGL->depth == IPL_DEPTH_32F && depthCC->depth == IPL_DEPTH_32F);
	
	const int width = depthGL->width;
	const int height = depthGL->height;
	const float d1d2 = d1 * d2;
	const float dd12 = d2 - d1;
	IMGT<float> GL(depthGL), CC(depthCC);
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			CC(row, col) = d1d2 / (d2 - GL(row, col) * dd12);
		}
	}
}
//! convert depthmap from opengl to kinect format
//! \param [in] depthGL
//! \param [in] depthKN
//! \param [in] d1 near plane
//! \param [in] d2 far plane
//! \param [in] focal
inline void CvtDepthGL2KN(IplImage *depthGL, IplImage *depthKN, const float d1, const float d2, const float focal)
{
	//Utility_Check( depthGL->depth == IPL_DEPTH_32F && depthKN->depth == 16);

	IplImage *depthCC = cvCloneImage(depthGL);
	CvtDepthGL2CC(depthGL, depthCC, d1, d2);
	CvtDepthCC2KN(depthCC, depthKN, focal);
	{
		float *pGL = (float*) depthGL->imageData;
		short *pKN = (short*) depthKN->imageData;
		const int sz = depthGL->width * depthGL->height;
		for (int i = 0; i < sz; i++)
			if (pGL[i] > 0.999)
				pKN[i] = d2;
	}
	cvReleaseImage(&depthCC);
}

//inline void PyrSmooth(IplImage *depth)
//{
//	int w = (depth->width + 1) / 2;
//	int h = (depth->height + 1) / 2;
//	IplImage *dst = cvCreateImage(cvSize(w, h), depth->depth, depth->nChannels);
//	cvPyrDown(depth, dst);
//	cv::Mat dst1(dst);
//	cv::medianBlur(dst1,dst1,3);
//	//cv::GaussianBlur(dst1, dst1, cvSize(7, 7), 3, 0);
//    dst = cvCloneImage(&(IplImage)dst1);
//	cvPyrUp(dst,depth);
//	cvReleaseImage(&dst);
//}

}

#endif /* IMGPROC_HPP_ */
