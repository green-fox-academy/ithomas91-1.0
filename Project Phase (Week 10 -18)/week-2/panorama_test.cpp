#include "gtest/gtest.h"
#include "../opencv/panorama.cpp"

class TestPanorama : public testing::Test
{
protected:

	std::vector<cv::Mat> imagesVector;
	cv::Mat originalImage;
	cv::Mat originalImage2;
	cv::Mat originalImage3;
	cv::Mat originalImage4;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/img1.jpg");
		originalImage2 = cv::imread("../../../img/img2.jpg");
		originalImage3 = cv::imread("../../../img/img3.jpg");
		originalImage4 = cv::imread("../../../img/img4.jpg");
		imagesVector.push_back(originalImage);
		imagesVector.push_back(originalImage2);
		imagesVector.push_back(originalImage3);
		imagesVector.push_back(originalImage4);
	}
};

TEST_F(TestPanorama, filesAreOpen) {
	cv::Mat resultImage = panorama(imagesVector);
	EXPECT_TRUE(!resultImage.empty());
}

TEST_F(TestPanorama, rowNumber) {
	cv::Mat resultImage = panorama(imagesVector);
	for (int i = 0; i < imagesVector.size(); i++){
		EXPECT_TRUE(resultImage.rows > imagesVector[i].rows);	
	}
}

TEST_F(TestPanorama, EqualOrLessThan) {
	cv::Mat resultImage = panorama(imagesVector);
	int sizeOfPartsTogether = 0;
	for (int i = 0; i < imagesVector.size(); i++) {
		sizeOfPartsTogether += imagesVector[i].rows;
	}
	EXPECT_TRUE(resultImage.rows <= sizeOfPartsTogether);
}
