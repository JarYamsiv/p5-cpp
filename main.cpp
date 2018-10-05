#include <iostream>
#include "headers/SDLM.h"

void p(void)
{
	printf("p-fun\n");
}

int main()
{
	sdlm::pFun=p;
	sdlm::rFun=p;
	sdlm::LOOP();
	return 0;
}