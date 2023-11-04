#include <stdio.h>
#include "BasketBall.h"
#include "Soccer.h"
#include "BaseBall.h"

int main() {

	//バスケ
	Sports* basketBall = new BasketBall();
	basketBall->Play();

	//サッカー
	Sports* soccer = new Soccer();
	soccer->Play();

	//野球
	Sports* baseBall = new BaseBall();
	baseBall->Play();


	delete basketBall;
	delete soccer;
	delete baseBall;

	return 0;
}