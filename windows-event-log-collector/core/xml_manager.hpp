#pragma once

#include <iostream>
#include <functional>

#include <pugixml.hpp>

#include "log_types.hpp"

namespace Core
{
	using DataCallback = std::function<void(LogData)>;

	class XmlManager
	{
	private:
		DataCallback data_callback;

	public:
		XmlManager();

		void XmlParser(LogPayload&& log_payload);
	};
}
