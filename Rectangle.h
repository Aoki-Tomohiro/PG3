#pragma once
#include "IShape.h"

class Rectangle : public IShape {
public:
	Rectangle(float width, float height);
	~Rectangle();
	void size() override;
	void draw() override;
private:
	float width_ = 1.0f;
	float height_ = 1.0f;
	float area_ = 0.0f;
};

