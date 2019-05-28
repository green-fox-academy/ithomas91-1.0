**MEGALOTIS OpenCV-SAPPHIRE**
======
_created by_ László Bogár, Tamás Németh, Zoltán Németh, Márton Porkoláb, Lilla Tóth

# **Project documentation**

We have been creating a program that is able to detect and modify shapes and text on images.<br/> <br/>
We use the following technologies:
* C++14
* SQLite
* OpenCV library
* Google Test<br/>

## **Basic image processing** <br/>
List of available functions, their definitions, and short descriptions:

- ### **arithmetic operations**

	- add images
	- divide images
	- multiply images
	- substract image

 `cv::Mat addImage(cv::Mat image, cv::Mat image2)`<br/>

The function takes 2 color images as input and adds them. This is known as blending as well.<br/>

 `cv::Mat subtractImage(cv::Mat image, cv::Mat image2)`<br/>

The function takes 2 color images as input and substracts them.<br/>


`cv::Mat multiplyImage(cv::Mat image, cv::Mat image2)`<br/>

The function takes 2 color images as input and multiplies them.<br/>
	
`cv::Mat divideImage(cv::Mat image, cv::Mat image2)`<br/>

The function takes 2 color images as input and divides them.<br/>

- ### **cartoon effect**

`cv::Mat cartoonEffect(cv::Mat image)`<br/>

First of all it blurs the original image a bit, than detects the edges, and it saves the inverted stronger edges into  a mask image. After that it makes it more blurrier, and reduce the avaliable pixel's colors and puts the mask with the edges on that. <br/>

- ### **create histogram**

`cv::Mat histogramBeforeAndAfterChanging(cv::Mat originalImage, double contrastModifier, int brightnessModifier);`<br/>

The color image as input is grayscaled first, after grayscaling the user can change the contrast value or brightness value or both value of the grayscaled image. Contrast value have to be a positive double, and the original contrast value is multiplied with this value. Brightness value is an unsigned integer value which is added to the original brightness value. At the end of the function it gives back the original and modified grayscaled images with their histograms.

Use the following technologies:<br/>

	* -histogram ../../img/speed_sign.jpg -c 1.8 -b 35 -s 
	* -histogram ../../img/speed_sign.jpg -c 1.8 -b 35
	* -histogram ../../img/speed_sign.jpg -c 1.8 -s
	* -histogram ../../img/speed_sign.jpg -b 35 -s
	* -hsitogram ../../img/speed_sign.jpg -c 1.8
	* -histogram ../../img/speed_sign.jpg -b 35

- ### **decolor**

`cv::Mat decolorImage(cv::Mat image)`<br/>

Input is a three-color-channel image, the output image is saveable. If the image path is not correct, the function creates a picture with an error message. The function create a one-channel grayscale image, but it is not equal with cv::cvtColor(image, grayscaleImage, cv::COLOR_BGR2GRAY) function.<br/>

- ### **detect corners**

`cv::Mat corners(cv::Mat image)`<br/>

Corners function iterates through an image, and looks for corners. First, cornerHarris() function is working on grayscale images. It computes the horizontal and vertical edges of an image, and then it performs cross correlation on the edges to highlight corners. As a result, all pixel values become less than 1 and you get a black image, however cv::normalise function helps to show the result. It divides every pixel value by the sum of absolute values of all the pixels in the image. After that the main function draws circles around the corners.  <br/>

- ### **detect edges**

`cv::Mat detectEdges(cv::Mat image)`<br/>

Input is a three-color-channel image, the output image is saveable. If the image path is not correct, the function creates a picture with an error message. The function detects the main edges on the input picture by setting two threshold parameters, which determine the distance between detected edges. In this function the ratio of threshold parameters is 3:1 constantly. The function uses three-times-three kernel matrix for image manipulation.<br/>

- ### **image geometry**

`cv::Mat resizerotateImage(cv::Mat image);`<br/>

The color image as input is resized, or rotated, or resized and rotated at the same time by user-defined values. Due to the complexity of the parser, the command line argument sytaxis:

Use the following technologies:<br/>

	* -geometry ../../img/speed_sign.jpg -resize 1.8 -rotate 35 -s
	* -geometry ../../img/speed_sign.jpg -resize 1.8 -rotate 35
	* -geometry ../../img/speed_sign.jpg -resize 1.8 -s
	* -geometry ../../img/speed_sign.jpg -rotate 35 -s
	* -geometry ../../img/speed_sign.jpg -resize 1.8
	* -geometry ../../img/speed_sign.jpg -rotate 35

- ### **image morphology**

	- closing image
	- dilate image
	- erode image
	- opening image

`cv::Mat erodeImage(cv::Mat image)`<br/>

Increase the area of black or darker shapes and also decrease the number of white pixels on the image.<br/>

`cv::Mat dilateImage(cv::Mat image)`<br/>

Increase the area of white or brighter shapes and also decrease the number of darker pixels on the image.<br/>

`cv::Mat openingImage(cv::Mat image)`<br/>

Find small white areas on the image and change the color of them into the color of closed pixels.<br/>

`cv::Mat closingImage(cv::Mat image)`<br/>

Find small black areas on the image and change the color of them into the color of closed pixels.<br/>

- ### **panorama**

`cv::Mat panorama(std::vector<cv::Mat> imagesVector)`<br/>

This function is intended to create a panorama by stitching images together using OpenCV library. It is looking for common areas or shared common patch of pixels in the input images and saves the resultant stitched image.
<br/>

- ### **reduce color**

`cv::Mat reduceColor(cv::Mat originalImage)`<br/>

Input and output are three-color-channel image. The function reduces the number of different colors of the input image. The maximum value of the reduced color number is 27. <br/>

- ### **salt effect**

`cv::Mat saltEffect(cv::Mat image)`<br/>

It makes randomly placed white pixels (salt noise) on the image.<br/> 

- ### **separate color**

`cv::Mat separateColor(cv::Mat image);`<br/>

The color image as input is split according to its RGB channels. The output is an image that consist of 3 subimages representing only the R, G, and B channels of the original image.<br/>

- ### **sharpen image**

`cv::Mat sharpen(cv::Mat image);` <br/>

GaussianBlur and addWeighted functions are needed together to get a sharper image. Those functions are substruct the smoother image from the original one. To get sharper image, in addWeighted increase alpha as well as reduce beta. The sum of them has to be 1.<br/>

- ### **waving effect**

`cv::Mat waveEffect(cv::Mat image)`<br/>

Input is a three-color-channel image, the output image is saveable. If the image path is not correct, the function creates a picture with an error message. The function reorganizes the values of pixels of the original image with the help of two support matrices, and returns a wave effecting image. In this function only the support matrix of rows gets new values. By changing the value of reorganizing algoritm, the amplitude of waves is variable.<br/> <br/>


## **Sorting algorithms** <br/>
List of available functions, their definitions, and short descriptions:


- ### **bubble sort**
`std::vector<int> bubbleSort(std::vector<int> list, bool isAscending)`<br/>

The function takes a list of unsorted numbers as a vector and sorts the numbers according to the <a href="https://upload.wikimedia.org/wikipedia/commons/c/c8/Bubble-sort-example-300px.gif">bubble sort</a> algorithm. If isAscending is true, the function sorts the numbers ascending order, and vice versa.

- ### **counting sort**
`std::vector<int> countSort(std::vector<int> list, bool isAscending)`<br/>

The function takes a list of unsorted numbers as a vector and sorts the numbers according to the <a href="https://upload.wikimedia.org/wikipedia/commons/6/60/Counting_Sort_Animation.gif">counting sort</a> algorithm. If isAscending is true, the function sorts the numbers ascending order, and vice versa.

- ### **heap sort**
`std::vector<int> heapSort(std::vector<int> list, bool isAscending)`<br/>

The function takes a list of unsorted numbers as a vector and sorts the numbers according to the <a href="https://upload.wikimedia.org/wikipedia/commons/1/1b/Sorting_heapsort_anim.gif">heap sort</a> algorithm. If isAscending is true, the function sorts the numbers ascending order, and vice versa.

- ### **insertion sort**
`std::vector<int> insertionSort(std::vector<int> list, bool isAscending)`<br/>

The function takes a list of unsorted numbers as a vector and sorts the numbers according to the <a href="https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif">insertion sort</a> algorithm. If isAscending is true, the function sorts the numbers ascending order, and vice versa.

- ### **merge sort**
`std::vector<int> mergeSort(std::vector<int> &list, bool isAscending)`<br/>

The function takes a list of unsorted numbers as a vector and sorts the numbers according to the <a href="https://upload.wikimedia.org/wikipedia/commons/thumb/c/c5/Merge_sort_animation2.gif/220px-Merge_sort_animation2.gif">merge sort</a> algorithm. If isAscending is true, the function sorts the numbers ascending order, and vice versa.

- ### **pancake sort**
`std::vector<int> pancakeSort(std::vector<int> list, bool isAscending)`<br/>

The function takes a list of unsorted numbers as a vector and sorts the numbers according to the <a href="https://rosettacode.org/mw/images/c/ce/Pancake.gif">pancake sort</a> algorithm. If isAscending is true, the function sorts the numbers ascending order, and vice versa.

- ### **quick sort**
`std::vector<int> quickSort(std::vector<int> list, bool isAscending)`<br/>

The function takes a list of unsorted numbers as a vector and sorts the numbers according to the <a href="https://upload.wikimedia.org/wikipedia/commons/6/6a/Sorting_quicksort_anim.gif">quick sort</a> algorithm. If isAscending is true, the function sorts the numbers ascending order, and vice versa.

- ### **selection sort**
`std::vector<int> selectionSort(std::vector<int> list, bool isAscending)`<br/>

The function takes a list of unsorted numbers as a vector and sorts the numbers according to the <a href="https://upload.wikimedia.org/wikipedia/commons/f/f6/Selection_Sort_Animation.gif">selection sort</a> algorithm. If isAscending is true, the function sorts the numbers ascending order, and vice versa.

- ### **shaker sort**
`std::vector<int> shakerSort(std::vector<int> list, bool isAscending)`<br/>

The function takes a list of unsorted numbers as a vector and sorts the numbers according to the <a href="https://upload.wikimedia.org/wikipedia/commons/e/ef/Sorting_shaker_sort_anim.gif">shaker sort</a> algorithm. If isAscending is true, the function sorts the numbers ascending order, and vice versa.

- ### **shell sort**
`std::vector<int> shellSort(std::vector<int> list, bool isAscending)`<br/>

The function takes a list of unsorted numbers as a vector and sorts the numbers according to the <a href="https://upload.wikimedia.org/wikipedia/commons/d/d8/Sorting_shellsort_anim.gif">shell sort</a> algorithm. If isAscending is true, the function sorts the numbers ascending order, and vice versa.