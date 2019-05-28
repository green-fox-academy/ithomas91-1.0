#include "detect_corners.h"

cv::Mat corners(cv::Mat image);

void cornersParser(int argc, const char** argv)
{
	cv::Mat originalImage;
	cv::Mat resultImage;
	std::string additionalArgumentFirst = argv[2];
	bool saving = (additionalArgumentFirst == "-s");

	switch (saving)
	{
	case true:
		switch (argc)
		{
		case 3:
			resultImage = corners(originalImage);
			break;
		case 4:
			originalImage = cv::imread(argv[3]);
			resultImage = corners(originalImage);
			cv::imwrite("../../img/corners.jpg", resultImage);
			break;
		default:
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = corners(originalImage);
		break;
	default:
		break;
	}
	cv::namedWindow("Corners", cv::WINDOW_AUTOSIZE);
	cv::imshow("Corners", resultImage);
	cv::waitKey(0);
}

cv::Mat corners(cv::Mat image)
{
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);

		return errorImage;
	}

	cv::Mat grayImage;
	cv::Mat resultImage;
	cv::Mat normalizeImage;
	cv::Mat scaledImage;

	cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
	resultImage = cv::Mat::zeros(resultImage.size(), CV_32FC1);
	cv::cornerHarris(grayImage, resultImage, 7, 5, 0.05, cv::BORDER_DEFAULT);

	cv::normalize(resultImage, normalizeImage, 0, 255, cv::NORM_MINMAX, CV_32FC1, cv::Mat());
	cv::convertScaleAbs(normalizeImage, scaledImage);

	for (int j = 0; j < normalizeImage.rows; j++) {
		for (int i = 0; i < normalizeImage.cols; i++) {
			if ((int)normalizeImage.at<float>(j, i) > 200) {
				circle(scaledImage, cv::Point(i, j), 10, cv::Scalar(255, 255, 255), 1, 8, 0);
			}
		}
	}

	return scaledImage;
}
