#pragma once
#include <functional>
#include <Windows.h>
#include <vector>
typedef std::function<void()> callback;
struct action
{
	callback func;
	float    time;
	bool     executed;
	action(callback f, float t)
	{
		func = f;
		time = GetTickCount64() + t;
		executed = false;
	}
};
class Humanizer
{
protected:
	std::vector<action> actionList;
public:
	void Add(action a)
	{
		actionList.push_back(a);
	}
	void Clear()
	{
		actionList.clear();
	}
	size_t GetSize()
	{
		return actionList.size();
	}
	bool IsReady()
	{
		for (auto& a : actionList) {
			if (!a.executed) {
				return false;
			}
		}
		return true;
	}
	void Update(float time)
	{
		for (auto iter = actionList.begin(); iter != actionList.end(); ) {
			if ((*iter).executed == false && (*iter).time <= time) {
				(*iter).func();
				(*iter).executed = true;
				iter = actionList.erase(iter);
			}
			else ++iter;
		}
	}
};
inline Humanizer DelayedAction;