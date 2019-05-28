#include "gtest/gtest.h"
#include "../opencv/img_sharpening.cpp"

class TestImageSharpening : public testing::Test
{
protected:

	cv::Mat originalImage;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/speed_sign.jpg");
	}
};


TEST_F(TestImageSharpening, fileIsOpen) {
	cv::Mat resultImage = sharpen(originalImage);
	EXPECT_TRUE(!resultImage.empty());
}

TEST_F(TestImageSharpening, rowNumberTest) {
	cv::Mat resultImage = sharpen(originalImage);
	EXPECT_TRUE(originalImage.rows == resultImage.rows);
}

TEST_F(TestImageSharpening, columnNumberTest) {
	cv::Mat resultImage = sharpen(originalImage);
	EXPECT_TRUE(originalImage.cols == resultImage.cols);
}

TEST_F(TestImageSharpening, equalTest) {
	cv::Mat resultImage = sharpen(originalImage);
	bool isEqual = (cv::sum(resultImage) == cv::sum(resultImage));
	EXPECT_TRUE(isEqual);
}

TEST_F(TestImageSharpening, differenceTest) {
	cv::Mat resultImage = sharpen(originalImage);
	bool isEqual = (cv::sum(originalImage) == cv::sum(resultImage));
	EXPECT_FALSE(isEqual);
}
