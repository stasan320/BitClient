#include <iostream>
#include <bitset>
#include <cmath>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

int main() {
	cv::Mat image(400, 600, CV_8UC1);
	for (int i = 0; i < image.rows; i++)
		for (int j = 0; j < image.cols; j++)
				image.at<uchar>(i, j) = 0;
        
	for (int i = 0; i < image.rows; i++) {
		image.at<uchar>(i, image.cols / 2) = 255;
	}
	for (int i = 0; i < image.cols; i++) {
		image.at<uchar>(image.rows / 2, i) = 255;
	}
  
	for (float i = 0; i < image.cols; i++) {
		//std::cout << sin(i / 30) * 100 << std::endl;
		int Y = image.rows / 2 + ceil(sin((- image.cols / 2 + i) / 50) * 100);
		//std::cout << Y << std::endl;
		image.at<uchar>(Y, i) = 255;
	}
	cv::imshow("Out", image);
	cv::waitKey(10000);
}
