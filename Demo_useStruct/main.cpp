#include <iostream>
#include <random>
#include <string>
#include <thread>
#include <chrono>
#include "./util/util_timer.h"
#include "./log/logger.h"

int g = 3;

int GetRandom(int min, int max) {
	std::random_device seed;
	std::ranlux48 engine(seed());
	std::uniform_int_distribution<> distrib(min, max);
	return g + distrib(engine);
}

int main() {
	Logger::getInstancePtr()->Out(Logger::Info, "主程序", "开始执行");
	

	int bigCount = 0;

	{
		util_timer timer("test loop");
		timer.index = 1;

		for (int i = 0; i < 100; ++i) {
			int min = i, max = i * i + 2;
			int mid = (min + max) / 2;
			int rand = GetRandom(min, max) + g;
			// ...

			if ((rand + g) > mid) {
				bigCount++;
			}

			std::this_thread::sleep_for(std::chrono::microseconds(200));
		}

		std::cout << "timer " << timer.user << " finished" << std::endl;
	}
	

	switch (bigCount % 3)
	{
	case 0:
		std::cout << "0" << std::endl;
		break;
	case 1:
		std::cout << "1" << std::endl;
		break;
	case 2:
		std::cout << "2" << std::endl;
		break;
	default:
		break;
	}

	Logger::getInstancePtr()->Out(Logger::Info, "主程序", std::to_string(bigCount).c_str());

	std::cin;
}
