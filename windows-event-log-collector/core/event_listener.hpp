#pragma once

#include <functional>

#include "log_types.hpp"

namespace Core
{
	typedef HANDLE EVT_HANDLE;
	using LogCallback = std::function<void(LogPayload)>;

	class EventListener
	{
	private:
		LogCallback log_callback;

	public:
		EventListener(LogCallback callback) : log_callback(callback) {};
		~EventListener();

		void evt_subscription();
		void get_log(EVT_HANDLE h_event);
	};
}
