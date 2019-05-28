#include "panorama.h"

cv::Mat panorama(std::vector<cv::Mat> imagesVector);

void panoramaParser(int argc, const char** argv)
{

	std::vector<cv::Mat> imagesVector;
	cv::Mat resultImage;

	std::string additionalArgumentFirst = argv[2];
	bool saving = (additionalArgumentFirst == "-s");
	switch (saving)
	{
	case true:
		switch (argc)
		{
		case 3:
		case 4:
		case 5:
		case 6:
			resultImage = panorama(imagesVector);
			break;
		case 7:
			for (int  i = 3; i < 7; i++) {
				cv::Mat originalImage = cv::imread(argv[i]);
				imagesVector.push_back(originalImage);
			}
			resultImage = panorama(imagesVector);
			cv::imwrite("../../img/panorama.jpg", resultImage);
			break;
		default:
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		switch (argc)
		{
		case 3:
		case 4:
		case 5:
			resultImage = panorama(imagesVector);
			break;
		case 6:
			for (int i = 2; i < 6; i++) {
				cv::Mat originalImage = cv::imread(argv[i]);
				imagesVector.push_back(originalImage);
			}
			resultImage = panorama(imagesVector);
			break;
		default:
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
	default:
		break;
	}
	cv::namedWindow("Result Panorama_image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Result Panorama_image", resultImage);
	cv::waitKey(0);
}

cv::Mat panorama(std::vector<cv::Mat> imagesVector) 
{
	for (int i = 0; i < imagesVector.size(); i++) {
		if (imagesVector[i].empty()) {
			std::string error = "Could not open or find the image!";
			cv::Mat errorImage(250, 250, CV_8UC1);
			cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);

			return errorImage;
		}
	}

	cv::Mat panorama;
	cv::Stitcher::Mode mode = cv::Stitcher::PANORAMA;
	cv::Ptr<cv::Stitcher> stitcher = cv::Stitcher::create(mode);
	cv::Stitcher::Status status = stitcher->stitch(imagesVector, panorama);

	return panorama;
}
