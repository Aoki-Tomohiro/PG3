#include <iostream>
#include <list>

int main() {
	//駅のリスト
	std::list<const char*> yamanoteLine1970 = {
		"Tokyo",
		"Kanda",
		"Akihabara",
		"Okachumachi",
		"Ueno",
		"Uguisudani",
		"Nippori",
		"Tabata",
		"Komagome",
		"Sugamo",
		"Otsuka",
		"Ikebukuro",
		"Mejiro",
		"Takadanobaba",
		"Shin-Okubo",
		"Shinjuku",
		"Yoyogi",
		"Harajuku",
		"Shibuya",
		"Ebisu",
		"Meguro",
		"Gotanda",
		"Osaki",
		"Shinagawa",
		"Tamachi",
		"Hamamatsucho",
		"Shimbashi",
		"Yurakucho",
	};


	//1970年の駅を表示
	std::cout << "YamanoteLine1970" << std::endl;
	for (std::list<const char*>::iterator itr = yamanoteLine1970.begin(); itr != yamanoteLine1970.end(); ++itr) {
		std::cout << *itr << std::endl;
	}


	//2001年の駅を表示
	std::cout << "\nYamanoteLine2001" << std::endl;
	for (std::list<const char*>::iterator itr = yamanoteLine1970.begin(); itr != yamanoteLine1970.end(); ++itr) {
		if (*itr == "Tabata") {
			itr = yamanoteLine1970.insert(itr, "Nishi-Nippori");
			std::cout << *itr << std::endl;
			itr++;
		}
		std::cout << *itr << std::endl;
	}


	//2022年の駅を表示
	std::cout << "\nYamanoteLine2022" << std::endl;
	for (std::list<const char*>::iterator itr = yamanoteLine1970.begin(); itr != yamanoteLine1970.end(); ++itr) {
		if (*itr == "Tamachi") {
			itr = yamanoteLine1970.insert(itr, "Takanawa-Gateway");
			std::cout << *itr << std::endl;
			++itr;
		}
		std::cout << *itr << std::endl;
	}

	return 0;
}