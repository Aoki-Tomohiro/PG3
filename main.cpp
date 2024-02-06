#include <iostream>
#include <chrono>

int main() {
	//文字列
	std::string a(100000, 'a');

	//コピー
	auto copyStartTime = std::chrono::high_resolution_clock::now();
	std::string copyStr = a;
	auto copyEndTime = std::chrono::high_resolution_clock::now();
	auto copyDuration = std::chrono::duration_cast<std::chrono::microseconds>(copyEndTime - copyStartTime);

	//移動
	auto moveStartTime = std::chrono::high_resolution_clock::now();
	std::string moveStr = std::move(a);
	auto moveEndTime = std::chrono::high_resolution_clock::now();
	auto moveDuration = std::chrono::duration_cast<std::chrono::microseconds>(moveEndTime - moveStartTime);

	//表示
	std::cout << "100,000文字を移動とコピーで比較しました。" << std::endl;
	std::cout << "コピー : " << copyDuration.count() << "μs" << std::endl;
	std::cout << "移動 : " << moveDuration.count() << "μs" << std::endl;

	return 0;
}