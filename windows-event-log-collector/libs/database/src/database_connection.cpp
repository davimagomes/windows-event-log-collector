#include <sqlite3.h>

#include "database_connection.hpp"

static void get_sql3_conn(std::string db_name, sqlite3*& sql_conn)
{
	sqlite3_open_v2(
		db_name.c_str(),
		&sql_conn,
		SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
		NULL
	);
}

database::DatabaseConnection::DatabaseConnection()
{
	std::string db_name = "sqlite.db";

	get_sql3_conn(db_name, sql_conn);
}

database::DatabaseConnection::~DatabaseConnection()
{
	if (sql_conn)
	{
		sqlite3_close(sql_conn);
	}
}

sqlite3* database::DatabaseConnection::get_sqlite3() const
{
	return sql_conn;
}