#include "sqlite_manager.hpp"

SqliteManager::SqliteManager(sqlite3& db) : db(&db)
{
	TableStmt();
	InsertStmt();
}

SqliteManager::~SqliteManager()
{
	if (p_insert_stmt)
	{
		sqlite3_finalize(p_insert_stmt);
	}
}

void SqliteManager::TableStmt()
{
	std::string stmt_str = R"(
		CREATE TABLE IF NOT EXISTS printer_log (
			id INTEGER PRIMARY KEY AUTOINCREMENT,
			time_created TEXT NOT NULL
			event_id TEXT NOT NULL
			computer_name TEXT NOT NULL
			user_name TEXT NOT NULL
			printer_name TEXT NOT NULL
		);
	)";

	sqlite3_stmt* p_table_stmt = nullptr;

	int stmt_success = sqlite3_prepare_v2(
		db,
		stmt_str.c_str(),
		stmt_str.size(),
		&p_table_stmt,
		nullptr
	);

	sqlite3_finalize(p_table_stmt);
}

void SqliteManager::InsertStmt()
{
	std::string stmt_str = R"(
		INSERT INTO printer_log (
			time_created, 
			event_id, 
			computer_name, 
			user_name, 
			printer_name) VALUES (?, ?, ?, ?, ?)
		)
	)";

	int stmt_success = sqlite3_prepare_v2(
		db,
		stmt_str.c_str(),
		stmt_str.size(),
		&p_insert_stmt,			
		nullptr				
	);
}

void SqliteManager::InsertData(std::string value, int index)
{
	int bind_success = sqlite3_bind_text(
		p_insert_stmt,
		index,
		value.data(),
		NULL,
		nullptr
	);
}