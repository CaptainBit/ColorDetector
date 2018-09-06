#pragma once
#include "opencv2\opencv.hpp"

using namespace cv;


class CGrabber
{
public:

	Mat CheckColorRed(Mat img);
	Mat CheckColorGreen(Mat img);
	Mat CheckColorYellow(Mat img);
};

