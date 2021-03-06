// VisionLab1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include "opencv2\opencv.hpp"
#include "CGrabber.h"

using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap(0);
	CGrabber grab;

	if (!cap.isOpened()) {
		cout << "No camera found";
		return -1;
	}

	
	
	
	for (;;)
	{
		Mat frame;
		cap >> frame;
		frame = grab.CheckColorRed(frame);
		frame = grab.CheckColorGreen(frame);
		frame = grab.CheckColorYellow(frame);
		imshow("picture", frame);
		if (waitKey(40) >= 0) break;
	}

	return 0;
}
