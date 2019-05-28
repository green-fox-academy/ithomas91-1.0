#include "object_detection.h"

void featureMatching(cv::Mat image, cv::Mat image2);

void featureMatchingParser(const char** argv)
{
	cv::Mat originalImage = cv::imread(argv[2]);
	cv::Mat originalImage2 = cv::imread(argv[3]);

	switch (originalImage.empty() || originalImage2.empty())
	{
	case false:
		featureMatching(originalImage, originalImage2);
		cv::waitKey(0);
		std::cin.get();
		break;
	case true:
		std::cout << "Could not open or find the image!" << std::endl;
		std::cin.get();
		break;
	default:
		std::cout << "Unexpected error" << std::endl;
		std::cin.get();
		break;
	}
}

void featureMatching(cv::Mat image, cv::Mat image2)
{
	cv::Mat objectImage = image;
	cv::Mat sceneImage = image2;

	std::vector<cv::KeyPoint> objectKeypoints;
	std::vector<cv::KeyPoint> sceneKeypoints;

	cv::Mat descriptorsImage;
	cv::Mat descriptorsImage2;
	cv::Mat matchesImage;

	auto detector = cv::ORB::create();
	detector->detectAndCompute(objectImage, {}, objectKeypoints, descriptorsImage);
	detector->detectAndCompute(sceneImage, {}, sceneKeypoints, descriptorsImage2);

	auto matcher = cv::DescriptorMatcher::create("BruteForce");
	std::vector<cv::DMatch> matches;
	matcher->match(descriptorsImage, descriptorsImage2, matches);
	int topCount = int(0.1	*matches.size());

	std::sort(matches.begin(), matches.end(), [](auto& lhs, auto& rhs) { return lhs.distance < rhs.distance; });
	matches.resize(topCount);
	drawMatches(objectImage, objectKeypoints, sceneImage, sceneKeypoints, matches, matchesImage);
	
	cv::namedWindow("Top matches", cv::WINDOW_NORMAL);
	imshow("Top matches", matchesImage);

	cv::Mat img_matches = matchesImage;
	std::vector<cv::Point2f> obj;
	std::vector<cv::Point2f> scene;

	for (int i = 0; i < matches.size(); i++)
	{
		obj.push_back(objectKeypoints[matches[i].queryIdx].pt);
		scene.push_back(sceneKeypoints[matches[i].trainIdx].pt);
	}

	cv::Mat H = findHomography(obj, scene, cv::RANSAC);

	std::vector<cv::Point2f> obj_corners(4);
	obj_corners[0] = cv::Point(0, 0); obj_corners[1] = cv::Point(objectImage.cols, 0);
	obj_corners[2] = cv::Point(objectImage.cols, objectImage.rows); obj_corners[3] = cv::Point(0, objectImage.rows);
	std::vector<cv::Point2f> scene_corners(4);

	perspectiveTransform(obj_corners, scene_corners, H);
	
	line(img_matches, scene_corners[0] + cv::Point2f(objectImage.cols-1, 0), scene_corners[1] + cv::Point2f(objectImage.cols-1, 0), cv::Scalar(0, 255, 0), 4);
	line(img_matches, scene_corners[1] + cv::Point2f(objectImage.cols-1, 0), scene_corners[2] + cv::Point2f(objectImage.cols-1, 0), cv::Scalar(0, 255, 0), 4);
	line(img_matches, scene_corners[2] + cv::Point2f(objectImage.cols-1, 0), scene_corners[3] + cv::Point2f(objectImage.cols-1, 0), cv::Scalar(0, 255, 0), 4);
	line(img_matches, scene_corners[3] + cv::Point2f(objectImage.cols-1, 0), scene_corners[0] + cv::Point2f(objectImage.cols-1, 0), cv::Scalar(0, 255, 0), 4);
	
	cv::namedWindow("Good Matches & Object detection", cv::WINDOW_NORMAL);
	cv::imshow("Good Matches & Object detection", img_matches);
}
