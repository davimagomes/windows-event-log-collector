#include "xml_manager.hpp"

void Core::XmlManager::XmlParser(LogPayload&& log_payload)
{
	LogData log_data;
	pugi::xml_document xml_doc;
	
	pugi::xml_parse_result result = xml_doc.load_buffer(
		log_payload.raw_xml.data(),
		log_payload.buffer_used,
		pugi::parse_default,
		pugi::encoding_wchar
	);

	{
		pugi::xml_node xml_system_node = xml_doc.child("Event").child("System");

		log_data.event_id = xml_system_node.child_value("EventID");
		log_data.time_created = xml_system_node.child("TimeCreated").attribute("SystemTime").value();
	}
	{
		pugi::xml_node xml_userdata_node = xml_doc.child("Event").child("UserData").child("DocumentPrinted");

		log_data.user_name = xml_userdata_node.child_value("Param3");
		log_data.computer_name = xml_userdata_node.child_value("Param4");
		log_data.printer_name = xml_userdata_node.child_value("Param5");
	}

	data_callback(std::move(log_data));
}