#pragma once

#include <iostream>
#include <chrono>

struct util_timer
{
public:
	util_timer(const char* user)
	{
		this->user = user;
		startTime = std::chrono::system_clock::now();
	}

	~util_timer()
	{
		endTime = std::chrono::system_clock::now();
		std::chrono::duration<double> duration = std::chrono::duration<double>(endTime - startTime);

		std::cout << "util_timer  " << this->user << " used " << duration.count() << std::endl;
	}

public:
	const char* user;
	int index = 0;
	std::chrono::system_clock::time_point startTime;
	std::chrono::system_clock::time_point endTime;
};
