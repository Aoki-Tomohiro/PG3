#include <stdio.h>
#include "BasketBall.h"
#include "Soccer.h"
#include "BaseBall.h"

int main() {

	//�o�X�P
	Sports* basketBall = new BasketBall();
	basketBall->Play();

	//�T�b�J�[
	Sports* soccer = new Soccer();
	soccer->Play();

	//�싅
	Sports* baseBall = new BaseBall();
	baseBall->Play();


	delete basketBall;
	delete soccer;
	delete baseBall;

	return 0;
}