#include <stdio.h>
#include <iostream>

template<typename Type>
Type Min(Type a, Type b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

template <>
char Min<char>(char a, char b) {
	printf("数字以外は代入できません\n");
	return '\n';
}

int main() {

	printf("%d\n", Min<int>(5, 10));
	printf("%f\n", Min<float>(5.0f, 10.0f));
	printf("%lf\n", Min<double>(5.0f, 10.0f));
	Min<char>('a', 'b');

	return 0;
}