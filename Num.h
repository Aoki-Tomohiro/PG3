#pragma once

template <typename Type1, typename Type2>
class Num {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	Num(Type1 a, Type2 b) :a(a), b(b) {};

	/// <summary>
	/// 比較関数
	/// </summary>
	/// <returns></returns>
	Type1 Min() {
		if (a < b) {
			return a;
		}
		return static_cast<Type2>(b);
	}

private:
	Type1 a;
	Type2 b;

};