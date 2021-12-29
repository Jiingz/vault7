#pragma once
#include <mutex>
struct hooked_mouse
{
	int x;
	int y;
	bool enabled;
	std::mutex mutex;
} static Mouse;