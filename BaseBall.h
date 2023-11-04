#pragma once
#include "Sports.h"

class BaseBall : public Sports {
public:
	BaseBall();
	~BaseBall() override;
	void Play() override;

private:

};