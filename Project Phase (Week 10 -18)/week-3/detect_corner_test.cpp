#include "gtest/gtest.h"
#include "../opencv/detect_corners.cpp"


class TestDetectCorners : public testing::Test
{
protected:

	cv::Mat originalImage;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/corner.jpg");
	}
};

TEST_F(TestDetectCorners, fileIsOpen) {
	cv::Mat resultImage = corners(originalImage);
	EXPECT_TRUE(!resultImage.empty());
}

TEST_F(TestDetectCorners, differenceTest) {
	cv::Mat resultImage = corners(originalImage);
	bool isEqual = (cv::sum(originalImage) == cv::sum(resultImage));
	EXPECT_FALSE(isEqual);
}

TEST_F(TestDetectCorners, rowNumberTest) {
	cv::Mat resultImage = corners(originalImage);
	EXPECT_TRUE(originalImage.rows == resultImage.rows);
}

TEST_F(TestDetectCorners, columnNumberTest) {
	cv::Mat resultImage = corners(originalImage);
	EXPECT_TRUE(originalImage.cols == resultImage.cols);
}
