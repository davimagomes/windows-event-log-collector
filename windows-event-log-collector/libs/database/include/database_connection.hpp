#pragma once

#include <iostream>
#include <vector>

#include <sqlite3.h>

class DatabaseConnection
{

private:
	sqlite3* sql_conn = nullptr;

	std::string db_name = "sqlite.db";

public:
	~DatabaseConnection();
	void GetDatabaseConn();
};