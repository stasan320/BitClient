#include <iostream>
#include <bitset>
#include <cmath>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

int main() {
	int Y = 0, addvar = 1;
	cv::Mat image(700, 1000, CV_8UC1);
	int control = image.rows;
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
	/*for (int i = 0; i < image.cols; i++) {
		Y = image.rows / 2 - sin(((float)i - (image.cols / 2)) / 100) / cos(((float)i - (image.cols / 2)) / 100) * 100;
		if ((Y < image.rows) && (Y >= 0)) {
			image.at<uchar>(Y, i) = 255;
		}
	}*/
	std::string data, per;
	getline(std::cin, data);
	float a = 0, b = 0, power = 0, var = 0;
	int i = 0;

	for(int i = 0; i < data.size(); i++){
		int dop = 1;
		if (data[0] == '-') {
			dop = -1;
			//i++;
		}
		if (data[i] != 'x') {
			addvar++;
			per = data[i];
			a = a * pow(10, i) + atof(per.c_str());
		}
		else {
			var = i;
			a = a * dop;
			if (i == 0)
				a = 1;
			break;
		}
	}
	/*for (int i = (var + 1); i < data.size(); i++) {
		if ((data[i] != '+') || (data[i] != '-')) {
			addvar++;
			per = data[i];
			b = b * pow(10, i) + atof(per.c_str());
		}
		else {
			if (i == (var + 1))
				b = 1;
			break;
		}
	}*/

	for (int i = (var + 1); i < data.size(); i++) {
		int dop = 1;
		if (data[var + 1] == '-') {
			dop = -1;
			//i++;
		}
		if (data[i] != 'x') {
			addvar++;
			per = data[i];
			power = power * pow(10, (i - var - 1)) + atof(per.c_str());
		}
		else {
			var = i;
			power = power * dop;
			if (i == 0)
				power = 1;
			break;
		}
	}
	for (int i = 0; i < image.cols; i++) {
		Y = image.rows / 2 - (pow(((float)i - image.cols / 2) / 20, power) * a);
		if ((Y < image.rows) && (Y >= 0))
			image.at<uchar>(Y, i) = 255;
	}
	cv::imshow("Out", image);
	cv::waitKey(10000);
}
