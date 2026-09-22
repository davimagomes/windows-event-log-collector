#pragma once

#include <iostream>
#include <string_view>
#include <vector>
#include <array>

// Forward Declaration
struct sqlite3_stmt;

using StringViewArray = std::array<std::string_view, 2>;

namespace database
{
	class SqliteManager
	{

	private:
		sqlite3* sql_conn;
		std::vector<sqlite3_stmt*> stmt_list;

		void init_table();
		StringViewArray push_str();
		void prep_stmts(StringViewArray& stmt_str_list);

	public:
		SqliteManager(sqlite3* sql_conn);
		~SqliteManager();

		void insert_data(std::string value, int index);
	};
}