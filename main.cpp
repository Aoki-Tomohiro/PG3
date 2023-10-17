#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

int Normal(int wage, int hour) {

	if (hour <= 1) {
		return wage;
	}

	return wage + Normal(1072, hour - 1);
}

int Recursive(int wage, int hour) {

	if (hour <= 1) {
		return wage;
	}

	return wage + Recursive(wage * 2 - 50, hour - 1);
}

int main() {

	int hour = 0;
	int normalResult = 0;
	int recursiveResult = 0;

	while (recursiveResult <= normalResult) {
		hour++;
		normalResult = Normal(1072, hour);
		recursiveResult = Recursive(100, hour);
	}

	std::cout << hour << "時間働いた場合" << std::endl;
	std::cout << "通常資金" << " " << normalResult << std::endl;
	std::cout << "再帰的資金" << " " << recursiveResult << std::endl;

	std::ofstream writingFile;
	std::string fileName = "answer.md";
	writingFile.open(fileName, std::ios::out);
	writingFile << hour << "時間働くと再帰的な資金体系のほうが儲かる" << std::endl;
	writingFile.close();

	return 0;
}