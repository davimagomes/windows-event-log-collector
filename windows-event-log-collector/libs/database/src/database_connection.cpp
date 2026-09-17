#include "database_connection.hpp"

DatabaseConnection::~DatabaseConnection()
{
	if (sql_conn)
	{
		sqlite3_close(sql_conn);
	}
}

void DatabaseConnection::GetDatabaseConn()
{
	sqlite3_open_v2(
		db_name.c_str(),
		&sql_conn,
		SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
		NULL
	);
}