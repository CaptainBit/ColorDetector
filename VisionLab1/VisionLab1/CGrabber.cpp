#include "pch.h"
#include "CGrabber.h"
#include "opencv2\opencv.hpp"

using namespace cv;
using namespace std;

Mat CGrabber::CheckColorRed(Mat img)
{	

	Mat hsv_image;
	Mat imgThreshold;

	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	int largestArea = 0;
	int largestContourIndex = 0;


	cvtColor(img, hsv_image, COLOR_BGR2HSV);

	inRange(hsv_image, Scalar(0, 100, 100), Scalar(10, 255, 255), imgThreshold);

	

	findContours(imgThreshold, contours, hierarchy,CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	for (int i = 0; i < contours.size(); i++)
	{
		double area = contourArea(contours[i]);
		if (area > largestArea) {
			largestArea = area;
			largestContourIndex = i;
		}
	}
	drawContours(img, contours, largestContourIndex, Scalar(0,0,255), 2, 8, hierarchy, 0, Point());
	return img;
}
Mat CGrabber::CheckColorGreen(Mat img)
{
	Mat hsv_image;
	Mat imgThreshold;

	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	int largestArea = 0;
	int largestContourIndex = 0;
	int secondLargestArea = 0;
	int secondContourIndex = 0;
	cvtColor(img, hsv_image, COLOR_BGR2HSV);

	inRange(hsv_image, Scalar(30, 50, 30), Scalar(80, 255, 255), imgThreshold);



	findContours(imgThreshold, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	for (int i = 0; i < contours.size(); i++)
	{
		double area = contourArea(contours[i]);
		if (area > largestArea ) {
			largestArea = area;
			largestContourIndex = i;
		}
		else {
			if (area > secondLargestArea) {
				secondLargestArea = area;
				secondContourIndex = i;
			}
		}
	}
	drawContours(img, contours, largestContourIndex, Scalar(0, 255, 0), 2, 8, hierarchy, 0, Point());
	drawContours(img, contours, secondContourIndex, Scalar(0, 255, 0), 2, 8, hierarchy, 0, Point());
	return img;
}
Mat CGrabber::CheckColorYellow(Mat img)
{

	Mat hsv_image;
	Mat imgThreshold;

	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	int largestArea = 0;
	int largestContourIndex = 0;


	cvtColor(img, hsv_image, COLOR_BGR2HSV);

	inRange(hsv_image, Scalar(20, 100, 100), Scalar(30, 255, 255), imgThreshold);



	findContours(imgThreshold, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	for (int i = 0; i < contours.size(); i++)
	{
		double area = contourArea(contours[i]);
		if (area > largestArea) {
			largestArea = area;
			largestContourIndex = i;
		}
	}
	drawContours(img, contours, largestContourIndex, Scalar(0, 255, 255), 2, 8, hierarchy, 0, Point());
	return img;
}
