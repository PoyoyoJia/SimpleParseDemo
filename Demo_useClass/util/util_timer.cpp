#include "util_timer.h"

util_timer::util_timer(const char* user)
{
	this->user = user;
	startTime = std::chrono::system_clock::now();
}

util_timer::~util_timer()
{
	endTime = std::chrono::system_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration<double>(endTime - startTime);

	std::cout << "util_timer  " << this->user << " used " << duration.count() << std::endl;
}
