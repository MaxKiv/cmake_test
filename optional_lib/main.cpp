#include <iostream>

#ifdef USE_LIBTIMON
#	include "libtimon.h"
#endif

void bigBoi(const int&);

int main(int argc, char* argv[]) {
	std::cout << "entry of main" << std::endl;
	bigBoi(12309);
    return 0;
}