#include <sqlite3.h>

#include "sqlite_manager.hpp"

database::SqliteManager::SqliteManager(sqlite3* sql_conn) : sql_conn(sql_conn)
{
	StringViewArray stmt_str_list = push_str();

	init_table();
	prep_stmts(stmt_str_list);
}

database::SqliteManager::~SqliteManager()
{
	for (sqlite3_stmt* stmt : stmt_list)
	{
		if (stmt != nullptr)
		{
			sqlite3_finalize(stmt);
		}
	}
}

void database::SqliteManager::init_table()
{
	sqlite3_stmt* init_stmt = nullptr;

	std::string_view init_stmt_str = "CREATE TABLE IF NOT EXISTS printer_log (id INTEGER PRIMARY KEY AUTOINCREMENT, time_created TEXT NOT NULL, event_id TEXT NOT NULL, computer_name TEXT NOT NULL, user_name TEXT NOT NULL, printer_name TEXT NOT NULL)";

	int table_stmt_success = sqlite3_prepare_v2(
		sql_conn,
		init_stmt_str.data(),
		static_cast<int>(init_stmt_str.size()),
		&init_stmt,
		nullptr
	);

	if (table_stmt_success == SQLITE_OK)
	{
		sqlite3_step(init_stmt);
	}
	else {
		std::cout << sqlite3_errmsg(sql_conn);
	}
}

StringViewArray database::SqliteManager::push_str()
{
	StringViewArray stmt_str_list;

	stmt_str_list[0] = "INSERT INTO printer_log (time_created, event_id, computer_name, user_name, printer_name) VALUES (?, ?, ?, ?, ?)";

	return stmt_str_list;
}

void database::SqliteManager::prep_stmts(StringViewArray& stmt_str_list)
{
	for (std::string_view& stmt_str : stmt_str_list)
	{
		sqlite3_stmt* stmt_temp = nullptr;

		int stmt_success = sqlite3_prepare_v2(
			sql_conn,
			stmt_str.data(),
			static_cast<int>(stmt_str.size()),
			&stmt_temp,
			nullptr
		);

		if (stmt_success == SQLITE_OK)
		{
			stmt_list.push_back(stmt_temp);
		}
		else {
			std::cout << sqlite3_errmsg(sql_conn) << "\n";
		}
	}
}

void database::SqliteManager::insert_data(std::string value, int index)
{
	int bind_success = sqlite3_bind_text(
		stmt_list[0],
		index,
		value.data(),
		static_cast<int>(value.size()),
		nullptr
	);

	if (bind_success != SQLITE_OK)
	{
		std::cout << sqlite3_errmsg(sql_conn);
	}

	int step_success = sqlite3_step(stmt_list[0]);

	if (step_success != SQLITE_OK)
	{
		std::cout << sqlite3_errmsg(sql_conn);
	}
}