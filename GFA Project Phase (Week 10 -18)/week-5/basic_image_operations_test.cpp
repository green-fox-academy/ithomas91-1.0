#include "gtest/gtest.h"
#include "../opencv/basic_image_operations.cpp"

class TestAddImage : public testing::Test
{
protected:

	cv::Mat originalImage;
	cv::Mat originalImage2;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/new_york.jpg");
		originalImage2 = cv::imread("../../../img/speaker.jpg");
	}
};

class TestSubtractImage : public TestAddImage 
{
};

class TestMultiplyImage : public TestSubtractImage 
{
};

class TestDivideImage : public TestMultiplyImage 
{
};

TEST_F(TestAddImage, fileReadAdd) {
	cv::Mat resultImage = addImage(originalImage, originalImage2);
	EXPECT_FALSE(resultImage.empty());
}

TEST_F(TestSubtractImage, fileReadSubtract) {
	cv::Mat resultImage = subtractImage(originalImage, originalImage2);
	EXPECT_FALSE(resultImage.empty());
}

TEST_F(TestMultiplyImage, fileReadMultiply) {
	cv::Mat resultImage = multiplyImage(originalImage, originalImage2);
	EXPECT_FALSE(resultImage.empty());
}

TEST_F(TestDivideImage, fileReadDivide) {
	cv::Mat resultImage = divideImage(originalImage, originalImage2);
	EXPECT_FALSE(resultImage.empty());
}

TEST_F(TestAddImage, sizeOfOriginalAndOutputFileAdd) {
	cv::Mat resultImage = addImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.size == originalImage.size);
}

TEST_F(TestSubtractImage, sizeOfOriginalAndOutputFileSubtract) {
	cv::Mat resultImage = subtractImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.size == originalImage.size);
}

TEST_F(TestMultiplyImage, sizeOfOriginalAndOutputFileMultiply) {
	cv::Mat resultImage = multiplyImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.size == originalImage.size);
}

TEST_F(TestDivideImage, sizeOfOriginalAndOutputFileDivide) {
	cv::Mat resultImage = divideImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.size == originalImage.size);
}

TEST_F(TestAddImage, rowsOfOriginalAndOutputFileAdd) {
	cv::Mat resultImage = addImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.rows == originalImage.rows);
}

TEST_F(TestSubtractImage, rowsOfOriginalAndOutputFileSubtract) {
	cv::Mat resultImage = subtractImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.rows == originalImage.rows);
}

TEST_F(TestMultiplyImage, rowsOfOriginalAndOutputFileMultiply) {
	cv::Mat resultImage = multiplyImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.rows == originalImage.rows);
}

TEST_F(TestDivideImage, rowsOfOriginalAndOutputFileDivide) {
	cv::Mat resultImage = divideImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.rows == originalImage.rows);
}

TEST_F(TestAddImage, colsOfOriginalAndOutputFileAdd) {
	cv::Mat resultImage = addImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.cols == originalImage.cols);
}

TEST_F(TestSubtractImage, colsOfOriginalAndOutputFileSubtract) {
	cv::Mat resultImage = subtractImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.cols == originalImage.cols);
}

TEST_F(TestMultiplyImage, colsOfOriginalAndOutputFileMultiply) {
	cv::Mat resultImage = multiplyImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.cols == originalImage.cols);
}

TEST_F(TestDivideImage, colsOfOriginalAndOutputFileDivide) {
	cv::Mat resultImage = divideImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.cols == originalImage.cols);
}

class TestCartoonEffect : public testing::Test
{
protected:

	cv::Mat originalImage;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/speed_sign.jpg");
	}
};

TEST_F(TestCartoonEffect, wrongImagePath) {
	cv::Mat wrongImage = cv::imread("wrong_image_path");
	cv::Mat resultImage = cartoonEffect(wrongImage);

	std::string errorMessage = "Could not open or find the image!";
	cv::Mat errorImage(250, 250, CV_8UC1);
	cv::putText(errorImage, errorMessage, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
	bool imagesAreEqual = (cv::sum(errorImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_TRUE(imagesAreEqual);
}

TEST_F(TestCartoonEffect, resultIsDifferent) {
	cv::Mat resultImage = cartoonEffect(originalImage);
	bool imagesAreEqual = (cv::sum(originalImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_FALSE(imagesAreEqual);
}

TEST_F(TestCartoonEffect, moreBlackPixelOnOutput) {
	cv::Mat resultImage = cartoonEffect(originalImage);

	int blackOnOriginal = 0;
	int blackOnResult = 0;
	cv::Vec<uchar, 3> blackPixel = { 0, 0, 0 };
	for (int i = 0; i < originalImage.rows; i++) {
		for (int j = 0; j < originalImage.cols;j++) {
			if (originalImage.at<cv::Vec3b>(i, j) == blackPixel) {
				blackOnOriginal++;
			}
			if (resultImage.at<cv::Vec3b>(i, j) == blackPixel) {
				blackOnResult++;
			}
		}
	}

	EXPECT_TRUE(blackOnOriginal < blackOnResult);
}

TEST_F(TestCartoonEffect, expectedRemainderValue) {
	cv::Mat resultImage = cartoonEffect(originalImage);
	cv::Vec<uchar, 3> blackPixel = { 0, 0, 0 };
	cv::Scalar sumChannels = sum(resultImage != blackPixel);
	int remainderOfAllChannels = ((int)sumChannels[0] + (int)sumChannels[1] + (int)sumChannels[2]) % 34;
	
	EXPECT_EQ(0, remainderOfAllChannels);
}

class TestCreateHistogram : public testing::Test
{
protected:

	const char* wrongPath = "Wrong path";
	const char* correctPath = "../../../img/speed_sign.jpg";
	cv::Mat originalImage;
	cv::Mat resultImage;
	int originalImageRowNumber;
	int originalImageColumnNumber;
	int resultImageRowNumber;
	int resultImageColumnNumber;
};

TEST_F(TestCreateHistogram, isErrorImageWithWrongPath) {
	originalImage = cv::imread(wrongPath);
	resultImage = histogramBeforeAndAfterChanging(originalImage);
	bool isCorrectRows = resultImage.rows == 250;
	bool isCorrectColumns = resultImage.cols == 250;
	bool isCorrectErrorImageSize = isCorrectRows && isCorrectColumns;
	ASSERT_EQ(true, isCorrectErrorImageSize);
}

TEST_F(TestCreateHistogram, isNotEmptyImageWithCorrectPath) {
	originalImage = cv::imread(correctPath);
	resultImage = histogramBeforeAndAfterChanging(originalImage);
	bool isEmpty = resultImage.empty();
	ASSERT_EQ(false, isEmpty);
}

TEST_F(TestCreateHistogram, isExpectedImageSize) {
	originalImage = cv::imread(correctPath);
	resultImage = histogramBeforeAndAfterChanging(originalImage);
	bool isMoreRows = resultImage.rows == originalImage.rows + 256;
	bool isCorrectColumns = resultImage.cols == originalImage.cols * 2;
	bool isExpectedGrowth = isMoreRows && isCorrectColumns;
	ASSERT_EQ(true, isExpectedGrowth);
}

class TestDecolor : public testing::Test
{
protected:

	cv::Mat originalImage;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/speed_sign.jpg");
	}
};

TEST_F(TestDecolor, readFileTrue)
{
	cv::Mat resultImage = decolorImage(originalImage);
	EXPECT_TRUE(!resultImage.empty());
}

TEST_F(TestDecolor, wrongImagePath)
{
	std::string error = "Could not open or find the image!";
	cv::Mat errorImage = cv::Mat(250, 250, CV_8UC1);
	cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
	originalImage = cv::imread("../../../img/wrong_image_path.jpg");
	cv::Mat resultImage = decolorImage(originalImage);
	bool correctErrorImage = sum(errorImage) == sum(resultImage);

	EXPECT_TRUE(correctErrorImage);
}

TEST_F(TestDecolor, colNumberTestTrue)
{
	cv::Mat resultImage = decolorImage(originalImage);
	bool isSameCols = originalImage.cols == resultImage.cols;
	EXPECT_TRUE(isSameCols);
}

TEST_F(TestDecolor, rowNumberTestTrue)
{
	cv::Mat resultImage = decolorImage(originalImage);
	bool isSameRows = originalImage.rows == resultImage.rows;
	EXPECT_TRUE(isSameRows);
}

TEST_F(TestDecolor, sameImageTrue)
{
	cv::Mat resultImage = decolorImage(originalImage);
	bool  isSameImage = sum(resultImage) == sum(resultImage);
	EXPECT_TRUE(isSameImage);
}

TEST_F(TestDecolor, sameImageFalse)
{
	cv::Mat resultImage = decolorImage(originalImage);
	bool  isSameImage = sum(originalImage) == sum(resultImage);
	EXPECT_FALSE(isSameImage);
}

TEST_F(TestDecolor, grayScaleImageFalse)
{
	cv::Mat resultImage = decolorImage(originalImage);
	cv::Mat grayScaleImage;
	cv::cvtColor(originalImage, grayScaleImage, cv::COLOR_BGR2GRAY);
	bool  isGrayScaleImage = sum(grayScaleImage) == sum(resultImage);
	EXPECT_FALSE(isGrayScaleImage);
}

class TestDetectCorners : public testing::Test
{
protected:

	cv::Mat originalImage;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/diamond.jpg");
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

class TestDetectEdges : public testing::Test
{
protected:

	cv::Mat originalImage;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/speed_sign.jpg");
	}
};

TEST_F(TestDetectEdges, countBlackPixels)
{

	cv::Mat resultImage = detectEdges(originalImage);
	cv::Scalar numberOfBlackPixels = sum(resultImage) / 255;
	int blackPixelCounter = 0;
	for (int i = 0; i < resultImage.rows; ++i) {
		for (int j = 0; j < resultImage.cols; ++j) {
			if (resultImage.at<uchar>(i, j) == 255) {
				blackPixelCounter++;
			}
		}
	}

	EXPECT_EQ(numberOfBlackPixels[0], blackPixelCounter);
}

TEST_F(TestDetectEdges, notGrayscaleImage)
{
	cv::Mat resultImage = detectEdges(originalImage);
	cv::Mat grayScaleImage;
	cv::cvtColor(originalImage, grayScaleImage, cv::COLOR_BGR2GRAY);
	EXPECT_NE(sum(resultImage), sum(grayScaleImage));
}

TEST_F(TestDetectEdges, readFileTrue)
{
	cv::Mat resultImage = detectEdges(originalImage);
	EXPECT_TRUE(!resultImage.empty());
}

TEST_F(TestDetectEdges, wrongImagePath)
{
	std::string error = "Could not open or find the image!";
	cv::Mat errorImage = cv::Mat(250, 250, CV_8UC1);
	cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
	originalImage = cv::imread("../../../img/wrong_image_path.jpg");
	cv::Mat resultImage = detectEdges(originalImage);
	bool correctErrorImage = sum(errorImage) == sum(resultImage);

	EXPECT_TRUE(correctErrorImage);
}

TEST_F(TestDetectEdges, colNumberTestTrue)
{
	cv::Mat resultImage = detectEdges(originalImage);
	bool isSameCols = originalImage.cols == resultImage.cols;
	EXPECT_TRUE(isSameCols);
}

TEST_F(TestDetectEdges, rowNumberTestTrue)
{
	cv::Mat resultImage = detectEdges(originalImage);
	bool isSameRows = originalImage.rows == resultImage.rows;
	EXPECT_TRUE(isSameRows);
}

TEST_F(TestDetectEdges, pixelNumberTestTrue)
{
	cv::Mat resultImage = detectEdges(originalImage);
	int numberOfWhitePixels = 0;
	int numberOfBlackPixels = 0;
	int numberOfAllPixel = 0;
	for (int y = 0; y < resultImage.rows; y++) 
	{
		for (int x = 0; x < resultImage.cols; x++)
		{
			if (resultImage.at<uchar>(y, x) == 255) {
				numberOfWhitePixels++;
			} else if (resultImage.at<uchar>(y, x) == 0) {
				numberOfBlackPixels++;
			} else {
				numberOfAllPixel++;
			}
			numberOfAllPixel++;
		}
	}
	bool isSamePixel = numberOfAllPixel == (numberOfWhitePixels + numberOfBlackPixels);
	EXPECT_TRUE(isSamePixel);
}

class TestGeometryImage : public testing::Test
{
protected:

	cv::Mat originalImage;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/speed_sign.jpg");
	}
};

TEST_F(TestGeometryImage, fileRead) {
	cv::Mat resultImage = resizerotateImage(originalImage, 1, 0);
	EXPECT_FALSE(resultImage.empty());
}

TEST_F(TestGeometryImage, sizeOfOriginalAndOutputFileResize1) {
	cv::Mat resultImage = resizerotateImage(originalImage, 1, 0);
	EXPECT_TRUE(resultImage.size == originalImage.size);
}

TEST_F(TestGeometryImage, sizeOfOriginalAndOutputFileResize2) {
	cv::Mat resultImage = resizerotateImage(originalImage, 2, 0);
	EXPECT_FALSE(resultImage.size == originalImage.size);
}

TEST_F(TestGeometryImage, sizeOfOriginalAndOutputFileRotate) {
	cv::Mat resultImage = resizerotateImage(originalImage, 1, 30);
	EXPECT_TRUE(resultImage.size == originalImage.size);
}

TEST_F(TestGeometryImage, ratioOfOriginalAndOutputFileResize) {
	cv::Mat resultImage = resizerotateImage(originalImage, 2, 0);
	EXPECT_TRUE(resultImage.cols / resultImage.rows == originalImage.cols / originalImage.rows);
}

TEST_F(TestGeometryImage, ratioOfOriginalAndOutputFileRotate) {
	cv::Mat resultImage = resizerotateImage(originalImage, 1, 40);
	EXPECT_TRUE(resultImage.cols / resultImage.rows == originalImage.cols / originalImage.rows);
}

class TestErodeMorphology : public testing::Test
{
protected:

	cv::Mat originalImage;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/number.jpg");
	}
};

TEST_F(TestErodeMorphology, wrongImagePath) {
	cv::Mat wrongImage = cv::imread("wrong_image_path");
	cv::Mat resultImage = erodeImage(wrongImage);

	std::string errorMessage = "Could not open or find the image!";
	cv::Mat errorImage(250, 250, CV_8UC1);
	cv::putText(errorImage, errorMessage, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
	bool imagesAreEqual = (cv::sum(errorImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_TRUE(imagesAreEqual);
}

TEST_F(TestErodeMorphology, resultIsDifferent) {
	cv::Mat resultImage = erodeImage(originalImage);
	bool imagesAreEqual = (cv::sum(originalImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_FALSE(imagesAreEqual);
}


TEST_F(TestErodeMorphology, sizeAreTheSame) {
	cv::Mat resultImage = erodeImage(originalImage);
	bool sameSize = ((resultImage.rows == originalImage.rows) && (resultImage.cols == originalImage.cols));

	EXPECT_TRUE(sameSize);
}

class TestDilateMorphology : public TestErodeMorphology
{
};

TEST_F(TestDilateMorphology, wrongImagePath) {
	cv::Mat wrongImage = cv::imread("wrong_image_path");
	cv::Mat resultImage = dilateImage(wrongImage);

	std::string errorMessage = "Could not open or find the image!";
	cv::Mat errorImage(250, 250, CV_8UC1);
	cv::putText(errorImage, errorMessage, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
	bool imagesAreEqual = (cv::sum(errorImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_TRUE(imagesAreEqual);
}
TEST_F(TestDilateMorphology, resultIsDifferent) {
	cv::Mat resultImage = dilateImage(originalImage);
	bool imagesAreEqual = (cv::sum(originalImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_FALSE(imagesAreEqual);
}

TEST_F(TestDilateMorphology, sizeAreTheSame) {
	cv::Mat resultImage = dilateImage(originalImage);
	bool sameSize = ((resultImage.rows == originalImage.rows) && (resultImage.cols == originalImage.cols));

	EXPECT_TRUE(sameSize);
}

class TestClosingMorphology : public TestErodeMorphology
{
};

TEST_F(TestClosingMorphology, wrongImagePath) {
	cv::Mat wrongImage = cv::imread("wrong_image_path");
	cv::Mat resultImage = closingImage(wrongImage);

	std::string errorMessage = "Could not open or find the image!";
	cv::Mat errorImage(250, 250, CV_8UC1);
	cv::putText(errorImage, errorMessage, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
	bool imagesAreEqual = (cv::sum(errorImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_TRUE(imagesAreEqual);
}
TEST_F(TestClosingMorphology, resultIsDifferent) {
	cv::Mat resultImage = closingImage(originalImage);
	bool imagesAreEqual = (cv::sum(originalImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_FALSE(imagesAreEqual);
}

TEST_F(TestClosingMorphology, sizeAreTheSame) {
	cv::Mat resultImage = closingImage(originalImage);
	bool sameSize = ((resultImage.rows == originalImage.rows) && (resultImage.cols == originalImage.cols));

	EXPECT_TRUE(sameSize);
}

class TestOpeningMorphology : public TestErodeMorphology
{
};

TEST_F(TestOpeningMorphology, wrongImagePath) {
	cv::Mat wrongImage = cv::imread("wrong_image_path");
	cv::Mat resultImage = openingImage(wrongImage);

	std::string errorMessage = "Could not open or find the image!";
	cv::Mat errorImage(250, 250, CV_8UC1);
	cv::putText(errorImage, errorMessage, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
	bool imagesAreEqual = (cv::sum(errorImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_TRUE(imagesAreEqual);
}
TEST_F(TestOpeningMorphology, resultIsDifferent) {
	cv::Mat resultImage = openingImage(originalImage);
	bool imagesAreEqual = (cv::sum(originalImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_FALSE(imagesAreEqual);
}

TEST_F(TestOpeningMorphology, sizeAreTheSame) {
	cv::Mat resultImage = openingImage(originalImage);
	bool sameSize = ((resultImage.rows == originalImage.rows) && (resultImage.cols == originalImage.cols));

	EXPECT_TRUE(sameSize);
}

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
		originalImage = cv::imread("../../../img/pan1.jpg");
		originalImage2 = cv::imread("../../../img/pan2.jpg");
		originalImage3 = cv::imread("../../../img/pan3.jpg");
		originalImage4 = cv::imread("../../../img/pan4.jpg");
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

TEST_F(TestPanorama, colNumber) {
	cv::Mat resultImage = panorama(imagesVector);
	for (int i = 0; i < imagesVector.size(); i++){
		EXPECT_TRUE(resultImage.cols > imagesVector[i].cols);	
	}
}

TEST_F(TestPanorama, EqualOrLessThan) {
	cv::Mat resultImage = panorama(imagesVector);
	int sizeOfPartsTogether = 0;
	for (int i = 0; i < imagesVector.size(); i++) {
		sizeOfPartsTogether += imagesVector[i].cols;
	}
	EXPECT_TRUE(resultImage.cols <= sizeOfPartsTogether);
}

class TestReduceColor : public testing::Test
{
protected:

	const char* wrongPath = "Wrong path";
	const char* correctPath = "../../../img/speed_sign.jpg";
	cv::Mat originalImage;
	cv::Mat resultImage;
	int originalImageRowNumber;
	int originalImageColumnNumber;
	int resultImageRowNumber;
	int resultImageColumnNumber;

	virtual void SetUp()
	{
		originalImage = cv::imread("C:\\img\\highway.jpg");
	}
};


TEST_F(TestReduceColor, isEmptyImageWithWrongPath) {
	
	originalImage = cv::imread(wrongPath);
	 resultImage = reduceColor(originalImage);
	bool isEmpty = resultImage.empty();
	ASSERT_EQ(false, isEmpty);
}

TEST_F(TestReduceColor, isNotEmptyImageWithCorrectPath) {
	originalImage = cv::imread(correctPath);
	resultImage = reduceColor(originalImage);
	bool isEmpty = resultImage.empty();
	ASSERT_EQ(false, isEmpty);
}

TEST_F(TestReduceColor, isDifferentFromOriginalImage) {
	originalImage = cv::imread(correctPath);
	resultImage = reduceColor(originalImage);
	bool imagesAreSame = (sum(originalImage != resultImage) == cv::Scalar(0, 0, 0));
	ASSERT_EQ(false, imagesAreSame);
}

TEST_F(TestReduceColor, isSameNumberOfRows) {
	originalImage = cv::imread(correctPath);
	originalImageRowNumber = originalImage.rows;
	resultImage = reduceColor(originalImage);
	resultImageRowNumber = resultImage.rows;
	bool isEqualRows = (originalImageRowNumber == resultImageRowNumber);
	ASSERT_EQ(true, isEqualRows);
}

TEST_F(TestReduceColor, isSameNumberOfColumns) {
	originalImage = cv::imread(correctPath);
	originalImageColumnNumber = originalImage.cols;
	resultImage = reduceColor(originalImage);
	resultImageColumnNumber = resultImage.cols;
	bool isEqualColumns = (originalImageColumnNumber == resultImageColumnNumber);
	ASSERT_EQ(true, isEqualColumns);
}

TEST_F(TestReduceColor, expectedRemainderValue) {
	originalImage = cv::imread(correctPath);
	resultImage = reduceColor(originalImage);
	cv::Scalar sumChannels = sum(resultImage);
	int remainderOfAllChannels = ((int)sumChannels[0] + (int)sumChannels[1] + (int)sumChannels[2]) % 127;
	ASSERT_EQ(0, remainderOfAllChannels);
}

class TestSaltEffect : public testing::Test
{
protected:

	cv::Mat originalImage;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/speed_sign.jpg");
	}
};

TEST_F(TestSaltEffect, goodImagePath) {
	cv::Mat resultImage = saltEffect(originalImage);

	EXPECT_FALSE(resultImage.empty());
}

TEST_F(TestSaltEffect, wrongImagePath) {
	cv::Mat wrongImage = cv::imread("wrong_image_path");
	cv::Mat resultImage = saltEffect(wrongImage);

	std::string errorMessage = "Could not open or find the image!";
	cv::Mat errorImage(250, 250, CV_8UC1);
	cv::putText(errorImage, errorMessage, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
	bool imagesAreEqual = (cv::sum(errorImage != resultImage) == cv::Scalar(0, 0, 0));
	
	EXPECT_TRUE(imagesAreEqual);
}

TEST_F(TestSaltEffect, resultIsDifferent) {
	cv::Mat resultImage = saltEffect(originalImage);
	bool imagesAreEqual = (cv::sum(originalImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_FALSE(imagesAreEqual);
}

TEST_F(TestSaltEffect, pixelValueIncrease) {
	cv::Mat result = saltEffect(originalImage);
	cv::Scalar originalColors = cv::sum(originalImage);
	cv::Scalar resultColors = cv::sum(result);
	
	bool resultBlueIsBigger = resultColors[0] > originalColors[0];
	bool resultGreenIsBigger = resultColors[1] > originalColors[1];
	bool resultRedIsBigger = resultColors[2] > originalColors[2];

	EXPECT_TRUE(resultBlueIsBigger);
	EXPECT_TRUE(resultGreenIsBigger);
	EXPECT_TRUE(resultRedIsBigger);
}

TEST_F(TestSaltEffect, whitePixelsOnBlackImage)
{
	cv::Mat blackImage(20, 20, CV_8UC3, cv::Scalar(0, 0, 0));
	cv::Mat resultImage = saltEffect(blackImage);
	int numberOfColoredPixels = 0;
	cv::Vec<uchar, 3> whitePixel = { 255, 255, 255 };
	cv::Vec<uchar, 3> blackPixel = { 0, 0, 0 };
	for (int y = 0; y < resultImage.rows; y++)
	{
		for (int x = 0; x < resultImage.cols; x++)
		{
			if (resultImage.at<cv::Vec3b>(y, x) != whitePixel && resultImage.at<cv::Vec3b>(y, x) != blackPixel) {
				numberOfColoredPixels++;
			}
		}
	}
	EXPECT_TRUE(numberOfColoredPixels == 0);
}

class TestSeparateColor : public testing::Test
{
protected:

	cv::Mat originalImage;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/speed_sign.jpg");
	}
};

TEST_F(TestSeparateColor, fileRead) {
	cv::Mat resultImage = separateColor(originalImage);
	EXPECT_FALSE(resultImage.empty());
}

TEST_F(TestSeparateColor, sizeOfOriginalAndOutputFile) {
	cv::Mat resultImage = separateColor(originalImage);
	EXPECT_FALSE(resultImage.size == originalImage.size);
}

TEST_F(TestSeparateColor, rowsOfOriginalAndOutputFile) {
	cv::Mat resultImage = separateColor(originalImage);
	EXPECT_TRUE(resultImage.rows == originalImage.rows);
}

TEST_F(TestSeparateColor, colsOfOriginalAndOutputFile) {
	cv::Mat resultImage = separateColor(originalImage);
	EXPECT_FALSE(resultImage.cols == originalImage.cols);
}

TEST_F(TestSeparateColor, exactNumberOfCols) {
	cv::Mat resultImage = separateColor(originalImage);
	EXPECT_TRUE(resultImage.cols == originalImage.cols * 3);
}

TEST_F(TestSeparateColor, blueColorChannel) {
	cv::Mat resultImage = separateColor(originalImage);

	for (int i = 0; i < originalImage.cols; i++)
	{
		for (int j = 0; j < originalImage.rows; j++)
		{
			EXPECT_TRUE(int(resultImage.at<cv::Vec3b>(j, i)[0]) == int(originalImage.at<cv::Vec3b>(j, i)[0]));
		}
	}
}

TEST_F(TestSeparateColor, greenColorChannel) {
	cv::Mat resultImage = separateColor(originalImage);

	for (int i = 0; i < originalImage.cols; i++)
	{
		for (int j = 0; j < originalImage.rows; j++)
		{
			EXPECT_TRUE(int(resultImage.at<cv::Vec3b>(j, i + originalImage.cols)[1]) == int(originalImage.at<cv::Vec3b>(j, i)[1]));
		}
	}
}

TEST_F(TestSeparateColor, redColorChannel) {
	cv::Mat resultImage = separateColor(originalImage);

	for (int i = 0; i < originalImage.cols; i++)
	{
		for (int j = 0; j < originalImage.rows; j++)
		{
			EXPECT_TRUE(int(resultImage.at<cv::Vec3b>(j, i + originalImage.cols * 2)[2]) == int(originalImage.at<cv::Vec3b>(j, i)[2]));
		}
	}
}

class TestWavingEffect : public testing::Test
{
protected:

	cv::Mat originalImage;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/speed_sign.jpg");
	}
};

TEST_F(TestWavingEffect, readFileFalse)
{
	cv::Mat resultImage = waveEffect(originalImage);
	EXPECT_FALSE(resultImage.empty());
}

TEST_F(TestWavingEffect, readFileEqual)
{
	cv::Mat resultImage = waveEffect(originalImage);
	EXPECT_EQ(0, resultImage.empty());
}

TEST_F(TestWavingEffect, readFileNotEqual)
{
	cv::Mat resultImage = waveEffect(originalImage);
	EXPECT_NE(1, resultImage.empty());
}

TEST_F(TestWavingEffect, readFileTrue)
{
	cv::Mat resultImage = waveEffect(originalImage);
	EXPECT_TRUE(!resultImage.empty());
}

TEST_F(TestWavingEffect, wrongImagePath)
{
	std::string error = "Could not open or find the image!";
	cv::Mat errorImage = cv::Mat(250, 250, CV_8UC1);
	cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
	originalImage = cv::imread("../../../img/wrong_image_path.jpg");
	cv::Mat resultImage = waveEffect(originalImage);
	bool correctErrorImage = sum(errorImage) == sum(resultImage);

	EXPECT_TRUE(correctErrorImage);
}

TEST_F(TestWavingEffect, colNumberTestTrue)
{
	cv::Mat resultImage = waveEffect(originalImage);
	bool isSameCols = originalImage.cols == resultImage.cols;
	EXPECT_TRUE(isSameCols);
}

TEST_F(TestWavingEffect, rowNumberTestTrue)
{
	cv::Mat resultImage = waveEffect(originalImage);
	bool isSameRows = originalImage.rows == resultImage.rows;
	EXPECT_TRUE(isSameRows);
}

TEST_F(TestWavingEffect, sameImageTrue)
{
	cv::Mat resultImage = waveEffect(originalImage);
	bool  isSameImage = sum(resultImage) == sum(resultImage);
	EXPECT_TRUE(isSameImage);
}

TEST_F(TestWavingEffect, sameImageFalse)
{
	cv::Mat resultImage = waveEffect(originalImage);
	bool  isSameImage = sum(originalImage) == sum(resultImage);
	EXPECT_FALSE(isSameImage);
}
