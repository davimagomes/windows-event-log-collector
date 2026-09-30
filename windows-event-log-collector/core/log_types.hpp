#pragma once

#include <vector>
#include <Windows.h>

struct LogPayload
{
	DWORD buffer_used;
	std::vector<wchar_t> raw_xml;
};

struct LogData
{
	std::string event_id;
	std::string time_created;
	std::string user_name;
	std::string computer_name;
	std::string printer_name;
};