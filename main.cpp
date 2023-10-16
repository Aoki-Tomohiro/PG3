#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

int Recursive(int recursive, int hour) {

	if (1072 < recursive) {
		return 1;
	}

	return hour + Recursive(recursive * 2 - 50, 1);
}

int main() {

	int result = Recursive(100, 1);

	std::cout << result << "時間働くと再帰的な資金体系のほうが儲かる\n" << std::endl;

	std::ofstream writingFile;
	std::string fileName = "answer.md";
	writingFile.open(fileName, std::ios::out);
	writingFile << result << "時間働くと再帰的な資金体系のほうが儲かる\n" << std::endl;
	writingFile.close();

	return 0;
}