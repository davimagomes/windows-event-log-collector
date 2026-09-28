#include <Windows.h>
#include <winevt.h>

#include "event_listener.hpp"

#include "log_types.hpp"

static DWORD WINAPI sub_callback_ctx(EVT_SUBSCRIBE_NOTIFY_ACTION action, PVOID context, EVT_HANDLE h_event) 
{
	auto* self = static_cast<collector::EventListener*>(context);

	if (self) 
	{
		self->get_log(h_event);
	}

	return ERROR_SUCCESS;
}

void collector::EventListener::evt_subscription()
{
	LPCWSTR path = L"Microsoft-Windows-PrintService/Operational";
	LPCWSTR query = L"*[System[(EventID=307)]]";

	EVT_HANDLE evtSub = EvtSubscribe(
		NULL,
		NULL,
		path,
		query,
		NULL,
		this,
		sub_callback_ctx,
		EvtSubscribeToFutureEvents
	);
}

void collector::EventListener::get_log(EVT_HANDLE hEvent)
{
	LogPayload log_payload;
	DWORD property_count = 0;

	bool buffer_size_success = EvtRender(
		NULL,
		hEvent,
		EvtRenderEventXml,
		0,
		NULL,
		&log_payload.buffer_used,
		&property_count
	);

	log_payload.raw_xml.resize(log_payload.buffer_used / sizeof(wchar_t) + 1);

	bool xml_log_success = EvtRender(
		NULL,
		hEvent,
		EvtRenderEventXml,
		log_payload.raw_xml.size() * sizeof(wchar_t),
		log_payload.raw_xml.data(),
		&log_payload.buffer_used,
		&property_count
	);

	return;
}