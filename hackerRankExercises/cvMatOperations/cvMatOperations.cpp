
#include <iostream>
#include <opencv2/opencv.hpp>
#include "user_interface.h"


int main(int argc, const char** argv)
{
	cv::Mat testImage;
	cv::Mat binaryImage;
	
	testImage = cv::imread("C:\\Users\\Tamas Nemeth\\Downloads\\7.jpg", cv::IMREAD_COLOR);
	
	std::cout << std::endl << testImage.type() << std::endl;



	
	if (testImage.empty()) {
		std::cout << "Can't open the source image!" << std::endl;
	}

	cv::cvtColor(testImage, testImage, cv::COLOR_BGR2GRAY);

	cv::resize(testImage, testImage, cv::Size(25, 40));
	
	//  SET PIXELS TO 0 - GET BLACK IMAGE
	//cv::Mat g = cv::Mat::zeros(cv::Size(testImage.cols, testImage.rows), CV_8UC1);
	//cv::imshow("G", g);

	// CREATE GRAY IMAGE (1 CHANNEL)
	//cv::cvtColor(testImage, testImage, cv::COLOR_BGR2GRAY);

		//WRITE OUT THE PIXEL VALUES WHEN GRAYSCALE

	for (int i = 0; i < testImage.rows; i++) {
		for (int j = 0; j <testImage.cols; j++) {
			int k = testImage.at<uchar>(i, j);
			std::cout << k << "\t";
		}
		std::cout << std::endl;
	}
	std::cin.get();
	
	/* cv::Mat g = cv::Mat::zeros(cv::Size(testImage.cols, testImage.rows), CV_8UC3);
	
	std::vector<cv::Mat> RGBChannels[2];
	cv::split(testImage, RGBChannels[2]);

	cv::imwrite("blue.png", RGBChannels[0]); 
	cv::imwrite("green.png", RGBChannels[1]); 
	cv::imwrite("red.png", RGBChannels[2]); 

	cv::imshow("blue.png", RGBChannels[0]); 
	cv::imshow("green.png", RGBChannels[1]); 
	cv::imshow("red.png", RGBChannels[2]); 
	
	*/

	cv::threshold(testImage, binaryImage, 120, 255, cv::THRESH_BINARY);
	std::cout << std::endl << testImage.type() << std::endl;
	cv::cvtColor(testImage, testImage, cv::COLOR_GRAY2RGB);
	std::cout << std::endl << testImage.type() << std::endl;

	cv::imshow("binary", binaryImage);
	cv::imshow("auto", testImage);
	cv::namedWindow("auto", cv::WINDOW_GUI_NORMAL);

	
	
	cv::waitKey();
	
}
