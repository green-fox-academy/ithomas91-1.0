#include "img_sharpening.h"

cv::Mat sharpen(cv::Mat image);

void sharpenParser(int argc, const char** argv)
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
			resultImage = sharpen(originalImage);
			break;
		case 4:
			originalImage = cv::imread(argv[3]);
			resultImage = sharpen(originalImage);
			cv::imwrite("../../img/sharpen_image.jpg", resultImage);
			break;
		default:
			std::cout << "Unexpected error!"<<std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = sharpen(originalImage);
		break;
	default:
		break;
	}
	cv::namedWindow("Sharpen_image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Sharpen_image", resultImage);
	cv::waitKey(0);
}

cv::Mat sharpen(cv::Mat image)
{
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
		
		return errorImage;
	}

	cv::Mat resultImage;
	cv::GaussianBlur(image, resultImage, cv::Size(0, 0), 1);
	cv::addWeighted(image, 7.0, resultImage, -6.0, 0, resultImage);

	return resultImage;
}

