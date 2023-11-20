#include <iostream>
#include <functional>
#include <random>
#include <string>
#include <Windows.h>

typedef void (*pFunc)(std::string&);

int DiceRoll() {
	std::random_device seedGenerator;
	std::mt19937 randomEngine(seedGenerator());
	std::uniform_int_distribution<> distribution(1, 6);
	return distribution(randomEngine);
}

void DispResult(std::string& answer) {
	int result = DiceRoll();
	if (result % 2 == 0) {
		if (answer == "奇数") {
			std::cout << "サイコロの出目:" << result << " " << "不正解" << std::endl;
		}
		else if (answer == "偶数") {
			std::cout << "サイコロの出目:" << result << " " << "正解" << std::endl;
		}
	}
	else if (result % 2 == 1) {
		if (answer == "奇数") {
			std::cout << "サイコロの出目:" << result << " " << "正解" << std::endl;
		}
		else if (answer == "偶数") {
			std::cout << "サイコロの出目:" << result << " " << "不正解" << std::endl;
		}
	}
}

void SetTimeout(pFunc p, int second, std::string& answer) {
	Sleep(second * 1000);
	p(answer);
}

int main() {
	std::function<void()> fx = []() {
		std::cout << "奇数か偶数を選んでください" << std::endl;
		std::string answer;
		std::cin >> answer;
		SetTimeout(DispResult, 3, answer);
	};

	fx();

	return 0;
}