#include <stdio.h>
#include <iostream>
#include "Num.h"

int main() {

	Num<int, int> a(1, 2);
	std::cout << a.Min() << std::endl;

	Num<int, float> b(3, 4.0f);
	std::cout << b.Min() << std::endl;

	Num<int, double> c(5, 6.0f);
	std::cout << c.Min() << std::endl;

	Num<float, float> d(7.0f, 8.0f);
	std::cout << d.Min() << std::endl;

	Num<float, double> e(9.0f, 10.0f);
	std::cout << e.Min() << std::endl;

	Num<double, double> f(11.0f, 12.0f);
	std::cout << f.Min() << std::endl;

	return 0;
}