#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/stitching.hpp" 
#include <opencv2/photo.hpp>
#include <string>
#include <vector> 

#ifndef H_BASIC_IMAGE_OPERATIONS
#define H_BASIC_IMAGE_OPERATIONS

void addParser(int argc, const char** argv);
void multiplyParser(int argc, const char** argv);
void divideParser(int argc, const char** argv);
void subtractParser(int argc, const char** argv);
void cartoonParser(int argc, const char** argv);
void createHistogramParser(int argc, const char** argv);
void decolorParser(int argc, const char** argv);
void cornersParser(int argc, const char** argv);
void detectEdgesParser(int argc, const char** argv);
void geometryParser(int argc, const char** argv);
void closingParser(int argc, const char** argv);
void dilateParser(int argc, const char** argv);
void erodeParser(int argc, const char** argv);
void openingParser(int argc, const char** argv);
void sharpenParser(int argc, const char** argv);
void panoramaParser(int argc, const char** argv);
void reduceColorParser(int argc, const char** argv);
void saltParser(int argc,const char** argv);
void separateParser(int argc, const char** argv);
void waveParser(int argc, const char** argv);

#endif H_BASIC_IMAGE_OPERATIONS
