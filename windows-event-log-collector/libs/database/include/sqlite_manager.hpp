#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <sqlite3.h>

class SqliteManager
{

private:
	sqlite3* db = nullptr;

	sqlite3_stmt* p_insert_stmt = nullptr;

	void TableStmt();
	void InsertStmt();

public:
	explicit SqliteManager(sqlite3& db);
	~SqliteManager();

	void InsertData(std::string value, int index);
};