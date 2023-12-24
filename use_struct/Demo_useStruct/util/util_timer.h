#pragma once

#include <iostream>
#include <chrono>

struct util_timer
{
public:
    util_timer(const char* user);
    ~util_timer();

public:
    const char* user;
	int index = 0;
    std::chrono::system_clock::time_point startTime;
    std::chrono::system_clock::time_point endTime;
};

