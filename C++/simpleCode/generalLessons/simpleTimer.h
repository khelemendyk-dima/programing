#ifndef SIMPLE_TIMER_H
#define SIMPLE_TIMER_H

#include <iostream>
#include <chrono>

class SimpleTimer {
    public:
	SimpleTimer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~SimpleTimer()
	{
		end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = end - start;
		std::cout << "Duration " << duration.count() << " s" << std::endl;
	}

    private:
	std::chrono::time_point<std::chrono::_V2::system_clock> start, end;
};

#endif