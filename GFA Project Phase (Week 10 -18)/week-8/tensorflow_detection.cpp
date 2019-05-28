#include "tensorflow_detection.h"

void postprocess(cv::Mat& frame, const std::vector<cv::Mat>& outs);

void detectObjectTensorfloParser(const char** argv) {
	cv::Mat originalImage = cv::imread(argv[2]);
	int result;
	switch (originalImage.empty())
	{
	case false:
		result = 0;
			detectObjectTensorflow(originalImage);
		if (result == 0) {
			std::cout << "No object detected." << std::endl;
		}
		else {
			cv::waitKey(0);
		}
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

void detectObjectTensorflow(cv::Mat image)
{
	//cv::resize(image, image, cv::Size(300, 300));
	std::string model = "C:\\tensorflow\\tensorflow_inception_graph.pb";
	
	cv::dnn::Net net = cv::dnn::readNetFromTensorflow(model);

	net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
	net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);

	if (net.empty()) {
		std::cout << "Net can't be loaded" << std::endl;
		std::cin.get();
	} else {
		std::cout << "Net loaded!" << std::endl;
		std::cin.get();
	}

	
	std::vector<std::string> fileBuffer;
	std::string line;
	std::ifstream fileName;
	fileName.open("C:\\tensorflow\\imagenet_comp_graph_label_strings.txt");

	if (!fileName.is_open()) {
		std::cout<<" File can't be opened!"<<std::endl;
		std::cin.get();
	}
	while (!fileName.eof()) {
		std::getline(fileName, line);
		fileBuffer.push_back(line);
	}
	
	std::cout << "inde: " << fileBuffer[102] << std::endl;

	int cols = image.cols;
	int rows = image.rows;
	std::cout << cols << " " << rows << std::endl;
	
	cv::Mat blob = cv::dnn::blobFromImage(image, 1.0 , cv::Size(224, 224), cv::Scalar(), true, false);
	net.setInput(blob);

	std::cout << "after blob" << std::endl;
	std::cin.get();

	//std::vector<cv::Mat> outs;

	cv::Mat outs;
	 net.forward(outs); 

	 float percentMatch = outs.at<float>(0, 0);
	 int index;

	 for (int i = 1; i < outs.cols; i++) {
		 if (outs.at<float>(0, i) > percentMatch) {
			 percentMatch = outs.at<float>(0, i);
			 index = i;
		 }
	 }

	 std::cout << percentMatch * 100 << std::endl;
	 std::cout << index << std::endl;

	std::cout << "after forward" << std::endl;
	std::cin.get();

	/*postprocess(image, outs);
	std::cin.get();

	std::cout << outs.size() << std::endl;

	for (int i = 0; i < outs.size(); i++) {
		cv::Mat detection;
		detection = outs[i];
		float* data = (float*)outs[i].data;
		float score = float(detection.data[2]);
		std::cout << score << std::endl;
		if (score >= 0.0) {
			int left = detection.data[3];// * cols;
			int top = detection.data[4];//* rows;
			int right = detection.data[5];//* cols;
			int bottom = detection.data[6]; //* rows;
			cv::rectangle(image, cv::Point(int(left), int(top)), cv::Point(int(right), int(bottom)), (23, 230, 210), 2);         
			std::cout << detection.data[1] << std::endl;;
			std::cout << " "<< left << " " << top << " " << right << " " << bottom << std::endl;
		}
	}
	*/

	cv::imshow("img", image);
	cv::waitKey();

}

void postprocess(cv::Mat& frame, const std::vector<cv::Mat>& outs)
{
	cv::Mat outDetections = outs[0];
	cv::Mat outMasks = outs[1];
	float confThreshold = 0.5;
	float maskThreshold = 0.3;

	// Output size of masks is NxCxHxW where
	// N - number of detected boxes
	// C - number of classes (excluding background)
	// HxW - segmentation shape
	const int numDetections = outDetections.size[2];
	const int numClasses = outMasks.size[1];

	outDetections = outDetections.reshape(1, outDetections.total() / 7);
	for (int i = 0; i < numDetections; ++i)
	{
		float score = outDetections.at<float>(i, 2);
		if (score > confThreshold)
		{
			// Extract the bounding box
			int classId = static_cast<int>(outDetections.at<float>(i, 1));
			int left = static_cast<int>(frame.cols * outDetections.at<float>(i, 3));
			int top = static_cast<int>(frame.rows * outDetections.at<float>(i, 4));
			int right = static_cast<int>(frame.cols * outDetections.at<float>(i, 5));
			int bottom = static_cast<int>(frame.rows * outDetections.at<float>(i, 6));

			left = cv::max(0, cv::min(left, frame.cols - 1));
			top = cv::max(0, cv::min(top, frame.rows - 1));
			right = cv::max(0, cv::min(right, frame.cols - 1));
			bottom = cv::max(0, cv::min(bottom, frame.rows - 1));
			cv::Rect box = cv::Rect(left, top, right - left + 1, bottom - top + 1);

			// Extract the mask for the object
			cv::Mat objectMask(outMasks.size[2], outMasks.size[3], CV_32F, outMasks.ptr<float>(i, classId));

			// Draw bounding box, colorize and show the mask on the image
			//drawBox(frame, classId, score, box, objectMask);
			std::cout << classId << std::endl;
		}
	}
}