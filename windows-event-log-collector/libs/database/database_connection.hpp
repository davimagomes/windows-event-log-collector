#pragma once

#include <string>

// Forward Declaration
struct sqlite3;

namespace database
{
	class DatabaseConnection
	{
	private:
		sqlite3* sql_conn = nullptr;

	public:
		~DatabaseConnection();
		DatabaseConnection();

		sqlite3* get_sqlite3() const;
	};
}
