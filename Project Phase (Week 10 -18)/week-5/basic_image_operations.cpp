#include "basic_image_operations.h"

cv::Mat addImage(cv::Mat image, cv::Mat image2);
cv::Mat subtractImage(cv::Mat image, cv::Mat image2);
cv::Mat multiplyImage(cv::Mat image, cv::Mat image2);
cv::Mat divideImage(cv::Mat image, cv::Mat image2);
cv::Mat cartoonEffect(cv::Mat image);
cv::Mat histogramBeforeAndAfterChanging(cv::Mat originalImage, double contrastModifier = 1, int brightnessModifier = 0);
cv::Mat createHistogram(cv::Mat grayScaleImage);
cv::Mat decolorImage(cv::Mat image);
cv::Mat corners(cv::Mat image);
cv::Mat detectEdges(cv::Mat image);
cv::Mat resizerotateImage(cv::Mat image, double scale, int angle);
cv::Mat erodeImage(cv::Mat image);
cv::Mat dilateImage(cv::Mat image);
cv::Mat closingImage(cv::Mat image);
cv::Mat openingImage(cv::Mat image);
cv::Mat sharpen(cv::Mat image);
cv::Mat panorama(std::vector<cv::Mat> imagesVector);
cv::Mat reduceColor(cv::Mat originalImage);
cv::Mat saltEffect(cv::Mat image);
cv::Mat separateColor(cv::Mat image);
cv::Mat waveEffect(cv::Mat image);

void addParser(int argc, const char** argv)
{
	cv::Mat originalImage;
	cv::Mat originalImage2;
	cv::Mat resultImage;
	std::string additionalArgumentFirst = argv[2];
	bool saving = (additionalArgumentFirst == "-s");

	switch (saving)
	{
	case true:
		switch (argc)
		{
		case 4:
			resultImage = addImage(originalImage, originalImage2);
			break;
		case 5:
			originalImage = cv::imread(argv[3]);
			originalImage2 = cv::imread(argv[4]);
			resultImage = addImage(originalImage, originalImage2);
			cv::imwrite("../../img/add_image.jpg", resultImage);
			break;

		default:
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		originalImage2 = cv::imread(argv[3]);
		resultImage = addImage(originalImage, originalImage2);
		break;
	default:
		break;
	}

	cv::namedWindow("Add Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Add Image", resultImage);
	cv::waitKey(0);
}

void subtractParser(int argc, const char** argv)
{
	cv::Mat originalImage;
	cv::Mat originalImage2;
	cv::Mat resultImage;
	std::string additionalArgumentFirst = argv[2];
	bool saving = (additionalArgumentFirst == "-s");

	switch (saving)
	{
	case true:
		switch (argc)
		{
		case 4:
			resultImage = subtractImage(originalImage, originalImage2);
			break;
		case 5:
			originalImage = cv::imread(argv[3]);
			originalImage2 = cv::imread(argv[4]);
			resultImage = subtractImage(originalImage, originalImage2);
			cv::imwrite("../../img/subtract_image.jpg", resultImage);
			break;
		default:
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		originalImage2 = cv::imread(argv[3]);
		resultImage = subtractImage(originalImage, originalImage2);
		break;
	default:
		break;
	}

	cv::namedWindow("Subtract Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Subtract Image", resultImage);
	cv::waitKey(0);
}

void multiplyParser(int argc, const char** argv)
{
	cv::Mat originalImage;
	cv::Mat originalImage2;
	cv::Mat resultImage;
	std::string additionalArgumentFirst = argv[2];
	bool saving = (additionalArgumentFirst == "-s");

	switch (saving)
	{
	case true:
		switch (argc)
		{
		case 4:
			resultImage = multiplyImage(originalImage, originalImage2);
			break;
		case 5:
			originalImage = cv::imread(argv[3]);
			originalImage2 = cv::imread(argv[4]);
			resultImage = multiplyImage(originalImage, originalImage2);
			cv::imwrite("../../img/multiply_image.jpg", resultImage);
			break;
		default:
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		originalImage2 = cv::imread(argv[3]);
		resultImage = multiplyImage(originalImage, originalImage2);
		break;
	default:
		break;
	}

	cv::namedWindow("Multiply Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Multiply Image", resultImage);
	cv::waitKey(0);
}

void divideParser(int argc, const char** argv)
{
	cv::Mat originalImage;
	cv::Mat originalImage2;
	cv::Mat resultImage;
	std::string additionalArgumentFirst = argv[2];
	bool saving = (additionalArgumentFirst == "-s");

	switch (saving)
	{
	case true:
		switch (argc)
		{
		case 4:
			resultImage = divideImage(originalImage, originalImage2);
			break;
		case 5:
			originalImage = cv::imread(argv[3]);
			originalImage2 = cv::imread(argv[4]);
			resultImage = divideImage(originalImage, originalImage2);
			cv::imwrite("../../img/divide_image.jpg", resultImage);
			break;
		default:
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		originalImage2 = cv::imread(argv[3]);
		resultImage = divideImage(originalImage, originalImage2);
		break;
	default:
		break;
	}

	cv::namedWindow("Divide Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Divide Image", resultImage);
	cv::waitKey(0);
}

void cartoonParser(int argc, const char** argv)
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
		case 4:
			originalImage = cv::imread(argv[3]);
			resultImage = cartoonEffect(originalImage);
			cv::imwrite("../../img/cartoon_effect.jpg", resultImage);
			break;
		case 3:
			resultImage = cartoonEffect(originalImage);
			break;
		default:
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = cartoonEffect(originalImage);
		break;
	default:
		break;
	}
	cv::namedWindow("Cartoon Effect", cv::WINDOW_AUTOSIZE);
	cv::imshow("Cartoon Effect", resultImage);
	cv::waitKey(0);
}

void createHistogramParser(int argc, const char** argv)
{
	cv::Mat originalImage;
	cv::Mat resultImage;
	
	switch (argc)
	{
	case 8:
	{
		std::string additionalArgumentFirst = argv[3];
		std::string additionalArgumentThird = argv[5];		
		std::string additionalArgumentFifth = argv[7];

		if (((std::string)argv[3]).find("-c") != std::string::npos &&
			((std::string)argv[5]).find("-b") != std::string::npos &&
			((std::string)argv[7]).find("-s") != std::string::npos) {
			double additionalArgumentSecond = std::stod(argv[4]);
			int additionalArguemntFourth = std::stoi(argv[6]);
			originalImage = cv::imread(argv[2]);
			resultImage = histogramBeforeAndAfterChanging(originalImage, additionalArgumentSecond, additionalArguemntFourth);
			cv::imwrite("../../img/recontrastedbrighnessed_image.jpg", resultImage);
			break;
		} else {
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
	}
	case 7:
	{
		std::string additionalArgumentFirst = argv[3];
		std::string additionalArgumentThird = argv[5];		

		if (((std::string)argv[3]).find("-c") != std::string::npos &&
			((std::string)argv[5]).find("-b") != std::string::npos) {
			double additionalArgumentSecond = std::stod(argv[4]);
			int additionalArguemntFourth = std::stoi(argv[6]);
			originalImage = cv::imread(argv[2]);
			resultImage = histogramBeforeAndAfterChanging(originalImage, additionalArgumentSecond, additionalArguemntFourth);
			break;
		} else {
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
	}
	case 6:
	{
		std::string additionalArgumentFirst = argv[3];
		std::string additionalArgumentThird = argv[5];

		if (((std::string)argv[3]).find("-c") != std::string::npos &&
			((std::string)argv[5]).find("-s") != std::string::npos) {
			double additionalArgumentSecond = std::stod(argv[4]);
			originalImage = cv::imread(argv[2]);
			resultImage = histogramBeforeAndAfterChanging(originalImage, additionalArgumentSecond, 0);
			cv::imwrite("../../img/recontrasted_image.jpg", resultImage);
			break;
		} else if (((std::string)argv[3]).find("-b") != std::string::npos &&
			((std::string)argv[5]).find("-s") != std::string::npos) {
			int additionalArgumentSecond = std::stoi(argv[4]);
			originalImage = cv::imread(argv[2]);
			resultImage = histogramBeforeAndAfterChanging(originalImage, 1, additionalArgumentSecond);
			cv::imwrite("../../img/rebrightnessed_image.jpg", resultImage);
			break;
		} else {
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
	}
	case 5:
	{
		std::string additionalArgumentFirst = argv[3];
		
		if (((std::string)argv[3]).find("-c") != std::string::npos) {
			double additionalArgumentSecond = std::stod(argv[4]);
			originalImage = cv::imread(argv[2]);
			resultImage = histogramBeforeAndAfterChanging(originalImage, additionalArgumentSecond, 0);
			break;
		} else if (((std::string)argv[3]).find("-b") != std::string::npos) {
			int additionalArgumentSecond = std::stoi(argv[4]);
			originalImage = cv::imread(argv[2]);
			resultImage = histogramBeforeAndAfterChanging(originalImage, 1, additionalArgumentSecond);
			break;
		} else {
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
	}
	default:
		std::cout << "Unexpected error!" << std::endl;
		std::cin.get();
		break;
	}
	cv::namedWindow("Histogram", cv::WINDOW_AUTOSIZE);
	cv::imshow("Histogram", resultImage);
	cv::waitKey(0);
}

void decolorParser(int argc, const char** argv)
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
			resultImage = decolorImage(originalImage);
			break;
		case 4:
			originalImage = cv::imread(argv[3]);
			resultImage = decolorImage(originalImage);
			imwrite("../../img/decolor_image.jpg", resultImage);
			break;
		default:
			std::cout << "Unexpected error" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = decolorImage(originalImage);
		break;
	default:
		break;
	}
	cv::namedWindow("Decolorized image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Decolorized image", resultImage);
	cv::waitKey(0);
}

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

void detectEdgesParser(int argc, const char** argv)
{
	cv::Mat originalImage;
	cv::Mat resultImage;
	std::string additionalArgumentFirst = argv[2];
	bool saving = (additionalArgumentFirst == "-s");

	switch (saving)
	{	
	case true:
		switch(argc) 
		{
		case 3:
			resultImage = detectEdges(originalImage);
			break;
		case 4:
			originalImage = cv::imread(argv[3]);
			resultImage = detectEdges(originalImage);
			imwrite("../../img/detect_edge_image.jpg", resultImage);
			break;
		default:
			std::cout << "Unexpected error" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = detectEdges(originalImage);
		break;
	default:
		break;
	}

	cv::namedWindow("Canny image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Canny image", resultImage);
	cv::waitKey(0);
}

void geometryParser(int argc, const char** argv) {
	cv::Mat originalImage;
	cv::Mat resultImage;

	switch (argc)
	{
	case 8:
		{
		std::string additionalArgumentFirst = argv[3];
		double additionalArgumentSecond = std::stod(argv[4]);
		std::string additionalArgumentThird = argv[5];
		int additionalArguemntFourth = std::stoi(argv[6]);
		std::string additionalArgumentFifth = argv[7];

		if (((std::string)argv[3]).find("-resize") != std::string::npos &&
			((std::string)argv[5]).find("-rotate") != std::string::npos &&
			((std::string)argv[7]).find("-s") != std::string::npos) {
			originalImage = cv::imread(argv[2]);
			resultImage = resizerotateImage(originalImage, additionalArgumentSecond, additionalArguemntFourth);
			cv::imwrite("../../img/resizerotated_image.jpg", resultImage);
			break;
		} else {
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		}
	case 7:
		{
		std::string additionalArgumentFirst = argv[3];
		double additionalArgumentSecond = std::stod(argv[4]);
		std::string additionalArgumentThird = argv[5];
		int additionalArguemntFourth = std::stoi(argv[6]);

		if (((std::string)argv[3]).find("-resize") != std::string::npos &&
			((std::string)argv[5]).find("-rotate") != std::string::npos) {
			originalImage = cv::imread(argv[2]);
			resultImage = resizerotateImage(originalImage, additionalArgumentSecond, additionalArguemntFourth);
			break;
		} else {
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		}
	case 6:
		{
		std::string additionalArgumentFirst = argv[3];
		double additionalArgumentSecond = std::stod(argv[4]);
		std::string additionalArgumentThird = argv[5];

		if (((std::string)argv[3]).find("-resize") != std::string::npos &&
			((std::string)argv[5]).find("-s") != std::string::npos) {
			originalImage = cv::imread(argv[2]);
			resultImage = resizerotateImage(originalImage, additionalArgumentSecond, 0);
			cv::imwrite("../../img/resizerotated_image.jpg", resultImage);
			break;
		} else if (((std::string)argv[3]).find("-rotate") != std::string::npos &&
		((std::string)argv[5]).find("-s") != std::string::npos) {
			originalImage = cv::imread(argv[2]);
			resultImage = resizerotateImage(originalImage, 1, additionalArgumentSecond);
			cv::imwrite("../../img/resizerotated_image.jpg", resultImage);
			break;
		} else {
		std::cout << "Unexpected error!" << std::endl;
		std::cin.get();
		break;
		}
		}
	case 5:
		{
		std::string additionalArgumentFirst = argv[3];
		double additionalArgumentSecond = std::stod(argv[4]);

		if (((std::string)argv[3]).find("-resize") != std::string::npos) {
			originalImage = cv::imread(argv[2]);
			resultImage = resizerotateImage(originalImage, additionalArgumentSecond, 0);
			break;
		} else if (((std::string)argv[3]).find("-rotate") != std::string::npos) {
			originalImage = cv::imread(argv[2]);
			resultImage = resizerotateImage(originalImage, 1, additionalArgumentSecond);
			break;
		} else {
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		}
	default:
		std::cout << "Unexpected error!" << std::endl;
		std::cin.get();
		break;
	}

		cv::namedWindow("Geometry Image", cv::WINDOW_AUTOSIZE);
		cv::imshow("Geometry Image", resultImage);
		cv::waitKey(0);
}

void erodeParser(int argc, const char** argv)
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
		case 4:
			originalImage = cv::imread(argv[3]);
			resultImage = erodeImage(originalImage);
			cv::imwrite("../../img/erosion.jpg", resultImage);
			break;
		case 3:
			resultImage = erodeImage(originalImage);
			break;
		default:
			std::cout << "Unexpected error" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = erodeImage(originalImage);
		break;
	default:
		break;
	}
	cv::namedWindow("Eroded Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Eroded Image", resultImage);
	cv::waitKey(0);
}

void dilateParser(int argc, const char** argv)
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
		case 4:
			originalImage = cv::imread(argv[3]);
			resultImage = dilateImage(originalImage);
			cv::imwrite("../../img/dilate.jpg", resultImage);
			break;
		case 3:
			resultImage = dilateImage(originalImage);
			break;
		default:
			std::cout << "Unexpected error" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = dilateImage(originalImage);
		break;
	default:
		break;
	}
	cv::namedWindow("Dilated Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Dilated Image", resultImage);
	cv::waitKey(0);
}

void closingParser(int argc, const char** argv)
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
		case 4:
			originalImage = cv::imread(argv[3]);
			resultImage = closingImage(originalImage);
			cv::imwrite("../../img/closed.jpg", resultImage);
			break;
		case 3:
			resultImage = closingImage(originalImage);
			break;
		default:
			std::cout << "Unexpected error" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = closingImage(originalImage);
		break;
	default:
		break;
	}
	cv::namedWindow("Closed Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Closed Image", resultImage);
	cv::waitKey(0);
}

void openingParser(int argc, const char** argv)
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
		case 4:
			originalImage = cv::imread(argv[3]);
			resultImage = openingImage(originalImage);
			cv::imwrite("../../img/opened.jpg", resultImage);
			break;
		case 3:
			resultImage = openingImage(originalImage);
			break;
		default:
			std::cout << "Unexpected error" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = openingImage(originalImage);
		break;
	default:
		break;
	}
	cv::namedWindow("Opened Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Opened Image", resultImage);
	cv::waitKey(0);
}

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

void reduceColorParser(int argc, const char** argv)
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
		case 4:
			originalImage = cv::imread(argv[3]);
			resultImage = reduceColor(originalImage);
			cv::imwrite("../../img/reduced_color_image.jpg", resultImage);
			break;
		case 3:
			resultImage = reduceColor(originalImage);
			break;
		default:
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false: 
		originalImage = cv::imread(argv[2]);
		resultImage = reduceColor(originalImage);	
		break;	
	default: 
		break;
	}
	
	cv::namedWindow("Reduced Color Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Reduced Color Image", resultImage);
	cv::waitKey(0);
	cv::destroyWindow("Reduced Color Image");
}

void saltParser(int argc, const char** argv)
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
		case 4:
			originalImage = cv::imread(argv[3]);
			resultImage = saltEffect(originalImage);
			cv::imwrite("../../img/salt_effect.jpg", resultImage);
			break;
		case 3:
			resultImage = saltEffect(originalImage);
			break;
		default:
			std::cout << "Unexpected error" << std::endl;
			std::cin.get();
		break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = saltEffect(originalImage);
		break;
	default:
		break;
	}
	cv::namedWindow("Salt Effect", cv::WINDOW_AUTOSIZE);
	cv::imshow("Salt Effect", resultImage);
	cv::waitKey(0);
}

void separateParser(int argc, const char** argv)
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
			resultImage = separateColor(originalImage);
			break;
		
		case 4:
			originalImage = cv::imread(argv[3]);
			resultImage = separateColor(originalImage);
			cv::imwrite("../../img/colored_image.jpg", resultImage);
			break;

		default:
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		break;		
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = separateColor(originalImage);
		break;
	default:
		break;
	}
	
	cv::namedWindow("Separate Color", cv::WINDOW_AUTOSIZE);
	cv::imshow("Separate Color", resultImage);
	cv::waitKey(0);
}

void waveParser(int argc, const char** argv)
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
			resultImage = waveEffect(originalImage);
			break;
		case 4:
			originalImage = cv::imread(argv[3]);
			resultImage = waveEffect(originalImage);
			imwrite("../../img/waving_effect_image.jpg", resultImage);
			break;
		default:
			std::cout << "Unexpected error" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = waveEffect(originalImage);
		break;
	default:
		break;
	}
	cv::namedWindow("Remapped image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Remapped image", resultImage);
	cv::waitKey(0);
}

cv::Mat addImage(cv::Mat image, cv::Mat image2) 
{
	if (image.empty() || image2.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat result(250, 250, CV_8UC1);
		cv::putText(result, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
		
		return result;
	}

	cv::Mat resultImage;
	cv::addWeighted(image, 0.5, image2, 0.5, 0.0, resultImage);
	
	return resultImage;
}

cv::Mat subtractImage(cv::Mat image, cv::Mat image2) 
{
	if (image.empty() || image2.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat result(250, 250, CV_8UC1);
		cv::putText(result, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
		
		return result;
	}

	cv::Mat resultImage;
	cv::subtract(image, image2, resultImage);
	
	return resultImage;
}

cv::Mat multiplyImage(cv::Mat image, cv::Mat image2) 
{
	if (image.empty() || image2.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat result(250, 250, CV_8UC1);
		cv::putText(result, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
		
		return result;
	}

	cv::Mat resultImage;
	cv::multiply(image, image2, resultImage, 1);
	
	return resultImage;
}

cv::Mat divideImage(cv::Mat image, cv::Mat image2) 
{
	if (image.empty() || image2.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat result(250, 250, CV_8UC1);
		cv::putText(result, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
		
		return result;
	}

	cv::Mat resultImage;
	cv::divide(image, image2, resultImage, 1);
	
	return resultImage;
}

cv::Mat cartoonEffect(cv::Mat image)
{
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);

		return errorImage;
	}
	
	cv::Mat blurImage;
	cv::medianBlur(image, blurImage, 3);

	cv::Mat edgesImage;
	cv::Canny(blurImage, edgesImage, 90, 270);
	cv::bitwise_not(edgesImage, edgesImage);

	cv::Mat kernel = cv::Mat::ones(2, 2, CV_32F);
	cv::morphologyEx(edgesImage, edgesImage, cv::MORPH_ERODE, kernel);

	cv::medianBlur(blurImage, blurImage, 17);
	blurImage = blurImage / 32;
	blurImage *= 32;
	
	cv::Mat resultImage;
	cv::bitwise_and(blurImage, blurImage, resultImage, edgesImage);

	return resultImage;
}

cv::Mat histogramBeforeAndAfterChanging(cv::Mat originalImage, double contrastModifier, int brightnessModifier)
{
	if (originalImage.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);

		return errorImage;
	} else {
		cv::Mat grayScaleImage;
		cv::cvtColor(originalImage, grayScaleImage, cv::COLOR_BGR2GRAY);
		cv::Mat grayScaleImageHistogramImage = createHistogram(grayScaleImage);

		cv::Mat modifiedGrayScaleImage;
		grayScaleImage.convertTo(modifiedGrayScaleImage, -1, contrastModifier, brightnessModifier);
		cv::Mat modifiedGrayScaleImageHistogramImage = createHistogram(modifiedGrayScaleImage);
	
		cv::Mat horizontalConcatGrayScaleImages;
		cv::hconcat(grayScaleImage, modifiedGrayScaleImage, horizontalConcatGrayScaleImages);

		cv::Mat horizontalConcatGrayScaleHistogramImages;
		cv::hconcat(grayScaleImageHistogramImage, modifiedGrayScaleImageHistogramImage, horizontalConcatGrayScaleHistogramImages);
	   
		cv::Mat resultImage;
		cv::vconcat(horizontalConcatGrayScaleImages, horizontalConcatGrayScaleHistogramImages, resultImage);

		return resultImage;
	}
}

cv::Mat createHistogram (cv::Mat grayScaleImage) 
{
	int bins = grayScaleImage.cols;
	int histogramSize[] = {bins};
	float range[] = {0, 255};
	const float* histogramRange[] = {range};

	cv::Mat grayScaleImageHistogram;

	int channels[] = {0};
	int const histogramHeight = 256;

	cv::Mat1b grayScaleImageHistogramImage = cv::Mat1b::zeros(histogramHeight, bins);
	cv::calcHist(&grayScaleImage, 1, channels, cv::Mat(), grayScaleImageHistogram, 1, histogramSize, histogramRange, true, false);

	double maximumValue = 0;
	minMaxLoc(grayScaleImageHistogram, 0, &maximumValue);

	for (int i = 0; i < bins; i++) {
		float const binValueGrayScaleImage = grayScaleImageHistogram.at<float>(i);
		int   const heightGrayScaleImage = cvRound(binValueGrayScaleImage * histogramHeight / maximumValue);
		cv::line
		(grayScaleImageHistogramImage
			, cv::Point(i, histogramHeight - heightGrayScaleImage), cv::Point(i, histogramHeight)
			, cv::Scalar::all(255)
		);
	}

	return grayScaleImageHistogramImage;
}

cv::Mat decolorImage(cv::Mat image)
{
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage = cv::Mat(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);

		return errorImage;
	}
	cv::Mat resultImage, supportImage;
	cv::decolor(image, resultImage, supportImage);

	return resultImage;
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

cv::Mat detectEdges(cv::Mat image)
{
	cv::Mat resultImage;
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage = cv::Mat(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);

		return errorImage;
	}
	cv::Canny(image, resultImage, 90, 270, 3);

	return resultImage;
}

cv::Mat resizerotateImage(cv::Mat image, double scale, int angle) {
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
		
		return errorImage;
	}

	cv::Mat resultImage;
	cv::resize(image, resultImage, cv::Size(), scale, scale);

	cv::Point2f pt(resultImage.cols / 2., resultImage.rows / 2.);
	cv::Mat r = cv::getRotationMatrix2D(pt, angle, 1.0);
	cv::warpAffine(resultImage, resultImage, r, cv::Size(resultImage.cols, resultImage.rows));
	
	return resultImage;
}

cv::Mat erodeImage(cv::Mat image)
{
	cv::Mat resultImage;
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);

		return errorImage;
	}

	cv::Mat kernel = cv::Mat::ones(3, 3, CV_32F);
	cv::morphologyEx(image, resultImage, cv::MORPH_ERODE, kernel);

	return resultImage;
}

cv::Mat dilateImage(cv::Mat image)
{
	cv::Mat resultImage;
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);

		return errorImage;
	}

	cv::Mat kernel = cv::Mat::ones(3, 3, CV_32F);
	cv::morphologyEx(image, resultImage, cv::MORPH_DILATE, kernel);

	return resultImage;
}

cv::Mat closingImage(cv::Mat image)
{
	cv::Mat resultImage;
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);

		return errorImage;
	}

	cv::Mat kernel = cv::Mat::ones(3, 3, CV_32F);
	cv::morphologyEx(image, resultImage, cv::MORPH_CLOSE, kernel);

	return resultImage;
}

cv::Mat openingImage(cv::Mat image)
{
	cv::Mat resultImage;
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);

		return errorImage;
	}

	cv::Mat kernel = cv::Mat::ones(3, 3, CV_32F);
	cv::morphologyEx(image, resultImage, cv::MORPH_OPEN, kernel);

	return resultImage;
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

cv::Mat reduceColor(cv::Mat originalImage)
{
	cv::Mat resultImage;
	if (originalImage.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
		
		return errorImage;
	} else {
		resultImage = originalImage / 127;
		resultImage *= 127;

		return resultImage;
	}
}

cv::Mat saltEffect(cv::Mat image)
{
	cv::Mat resultImage = image.clone();
	if (resultImage.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
		
		return errorImage;
	}
	cv::RNG randomNumber; 
	float salt_strongness = 0.02;
	int strongness = resultImage.rows * resultImage.cols * salt_strongness; 

	cv::Vec<uchar, 3> whitePixel = { 255, 255, 255 };
	
	for (int i = 0; i < strongness; i++) {
		resultImage.at<cv::Vec3b>(randomNumber.uniform(0, resultImage.rows), randomNumber.uniform(0, resultImage.cols)) = whitePixel;
	}

	return resultImage;
}

cv::Mat separateColor(cv::Mat image)
{
	cv::Mat blue_img;
	cv::Mat green_img;
	cv::Mat red_img;
	cv::Mat images;
	cv::Mat g = cv::Mat::zeros(cv::Size(image.cols, image.rows), CV_8UC1);
	
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
		return errorImage;
	}

	std::vector<cv::Mat> RGBchannels(3);
	cv::split(image, RGBchannels);

	{
		std::vector<cv::Mat> channels;
		channels.push_back(RGBchannels[0]);
		channels.push_back(g);
		channels.push_back(g);
		merge(channels, blue_img);
	}

	{
		std::vector<cv::Mat> channels;
		channels.push_back(g);
		channels.push_back(RGBchannels[1]);
		channels.push_back(g);
		merge(channels, green_img);
	}

	{
		std::vector<cv::Mat> channels;
		channels.push_back(g);
		channels.push_back(g);
		channels.push_back(RGBchannels[2]);
		merge(channels, red_img);
	}
		
	cv::hconcat(blue_img, green_img, images);
	cv::hconcat(images, red_img, images);
	
	return images;
}

cv::Mat waveEffect(cv::Mat image)
{
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage = cv::Mat(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);

		return errorImage;
	}
	cv::Mat resultImage, matX, matY;
	double yo;
	
	resultImage.create(image.size(), image.type());
	matX.create(image.size(), CV_32FC1);
	matY.create(image.size(), CV_32FC1);
	
	for (int j = 0; j < image.rows; j++) {
		for (int i = 0; i < image.cols; i++) {
			yo = (8.0 * sin(2.0 * 3.14 * i / 64.0));
			matX.at<float>(j, i) = i;
			matY.at<float>(j, i) = j + yo;
		}
	}
	cv::remap(image, resultImage, matX, matY, cv::INTER_LINEAR, cv::BORDER_DEFAULT, cv::Scalar(0, 0, 0));

	return resultImage;
}
