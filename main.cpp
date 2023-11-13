#include <iostream>
#include <functional>
#include <random>
#include <string>
#include <Windows.h>

typedef void (*pFunc)(std::string&, int);

int DiceRoll(std::mt19937& randomEngine) {
	std::uniform_int_distribution<> distribution(1, 6);
	return distribution(randomEngine);
}

void DispResult(std::string& answer, int result) {
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

void SetTimeout(pFunc p, int second, std::string& answer, int result) {
	Sleep(second * 1000);
	p(answer, result);
}

int main() {
	//ランダム関数の初期化
	std::random_device seedGenerator;
	std::mt19937 randomEngine(seedGenerator());

	//止める秒数
	int second = 3;

	//std::function
	std::function<void(pFunc p, int second, std::string& answer, int result)> fx = SetTimeout;

	//ラムダ式
	[fx,second,&randomEngine]() {
		std::cout << "奇数か偶数を選んでください" << std::endl;
		std::string str;
		std::cin >> str;
		void (*pFunc)(std::string&, int) = &DispResult;
		int result = DiceRoll(randomEngine);
		fx(pFunc, second, str, result);
	}();

	return 0;
}