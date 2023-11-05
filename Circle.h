#pragma once
#include "IShape.h"

class Circle : public IShape {
public:
	Circle(float radius);
	~Circle();
	void size() override;
	void draw() override;
private:
	float radius_ = 1.0f;
	float area_ = 0.0f;
};

