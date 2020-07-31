#include <iostream>
#include <bitset>
#include <cmath>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

int main() {
	int Y = 0;
	cv::Mat image(400, 1081, CV_8UC1);
	for (int i = 0; i < image.rows; i++)
		for (int j = 0; j < image.cols; j++)
				image.at<uchar>(i, j) = 0;

	int square = sqrt(pow(image.rows, 2) + pow(image.cols, 2));

	for (int i = 0; i < image.rows; i++) {
		image.at<uchar>(i, image.cols / 2) = 255;
	}
	for (int i = 0; i < image.cols; i++) {
		image.at<uchar>(image.rows / 2, i) = 255;
	}
	for (int i = 0; i < image.cols; i++) {
		if (i % (image.cols / 2) != 0) {
			Y = image.rows / 2 - sin(((float)i - (image.cols / 2)) / 100) / cos(((float)i - (image.cols / 2)) / 100) * 100;
			if ((Y < image.rows) && (Y >= 0)) {
				image.at<uchar>(Y, i) = 255;
			}
		}
	}
	cv::imshow("Out", image);
	cv::waitKey(10000);
}
