#include <iostream>
#include <functional>
#include <random>
#include <string>
#include <Windows.h>

void Game(std::function<int(std::mt19937&)> func, std::mt19937& randomEngine) {
	std::cout << "奇数か偶数を選んでください" << "\n" << std::endl;
	std::string num;
	std::cin >> num;
	Sleep(3 * 1000);
	int result = func(randomEngine);

	if (result % 2 == 0) {
		if (num == "奇数") {
			std::cout << "サイコロの出目" << " " << result << "\n" << "GameOver" << std::endl;
		}
		else if (num == "偶数") {
			std::cout << "サイコロの出目" << " " << result << "\n" << "GameClear" << std::endl;
		}
	}
	else if (result % 2 == 1) {
		if (num == "奇数") {
			std::cout << "サイコロの出目" << " " << result << "\n" << "GameClear" << std::endl;
		}
		else if (num == "偶数") {
			std::cout << "サイコロの出目" << " " << result << "\n" << "GameOver" << std::endl;
		}
	}
}

int main() {

	//ランダム関数の初期化
	std::random_device seedGenerator;
	std::mt19937 randomEngine(seedGenerator());

	std::function<int(std::mt19937&)> dice =
		[&](std::mt19937& randomEngine) {
		std::uniform_int_distribution<> distribution(1, 6);
		return distribution(randomEngine);
	};

	Game(dice, randomEngine);

	return 0;
}