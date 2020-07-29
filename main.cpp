#include <iostream>
#include <bitset>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core/core.hpp>

int main() {
	std::string data;
	getline(std::cin, data);
	int* bit = new int[data.size() * 8];           //fix

	for (int i = 0; i < data.size(); i++) {
		std::bitset<8> b = data[i];
		for (int j = 0; j < 8; j++) {
			bit[j + i * 8] = b[(7 - j)];             //fix
			std::cout << bit[j + 8 * i];
		}
		std::cout << std::endl;
	}
}
