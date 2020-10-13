std::wstring s2ws(const std::string& str) {
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.from_bytes(str);
}

std::string Dir() {
	std::string AppDataPath = getenv("APPDATA");
	std::wstring stemp = s2ws(AppDataPath);
	LPCWSTR AppDataPathL = stemp.c_str();

	//std::cout << userName;
	WIN32_FIND_DATAW wfd;
	HANDLE const hFind = FindFirstFileW(AppDataPathL, &wfd);
	setlocale(LC_ALL, "");

	if (INVALID_HANDLE_VALUE != hFind) {
		do {
			std::wcout << &wfd.cFileName[0] << std::endl;
		} 
		while (NULL != FindNextFileW(hFind, &wfd));

		FindClose(hFind);
	}
	return AppDataPath;
}
