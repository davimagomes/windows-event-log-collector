#pragma once

#include <vector>
#include <Windows.h>

struct LogPayload
{
	DWORD buffer_used;
	std::vector<wchar_t> raw_xml;
};