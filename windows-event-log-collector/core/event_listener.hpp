#pragma once

#include <vector>
#include <string>
#include <condition_variable>

namespace collector
{
	class EventListener
	{
	private:

	public:
		EventListener() ;
		~EventListener();

		void evt_subscription();
		void get_log(EVT_HANDLE h_event);
	};
}
