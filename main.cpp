#include <iostream>
#include <random>
#include <string>
#include <Windows.h>

typedef int (*pRandom)(std::mt19937&);

int Dice(std::mt19937& randomEngine) {
	std::uniform_int_distribution<> distribution(1, 6);
	return distribution(randomEngine);
}

void Game(pRandom func, int second, std::mt19937& randomEngine) {

	std::cout << "奇数 : 1  偶数 : 2" << std::endl;
	std::string num;
	std::cin >> num;
	Sleep(second * 1000);
	int result = func(randomEngine);
	if (result % 2 == 0) {
		if (num == "1") {
			std::cout << result << " " << "GameOver" << std::endl;
		}
		else if (num == "2") {
			std::cout << result << " " << "GameClear" << std::endl;
		}
	}
	else if(result % 2 == 1) {
		if (num == "1") {
			std::cout << result << " " << "GameClear" << std::endl;
		}
		else if (num == "2") {
			std::cout << result << " " << "GameOver" << std::endl;
		}
	}
}

int main() {

	//ランダム関数の初期化
	std::random_device seedGenerator;
	std::mt19937 randomEngine(seedGenerator());
	
	//関数ポインタ
	int (*pFunc)(std::mt19937 & randomEngine) = &Dice;

	//コールバック関数の呼び出し
	Game(pFunc, 3, randomEngine);

	return 0;
}