#include <string>
#include <iostream>
#include <pqxx/pqxx>
#include "../include/database.h"

/*Database& Database::getInstance()
{
	if (!instance)   // Only allow one instance of class to be generated.
		instance = new Database;
	return instance;
}*/

Database::Database()
{
	this->_connect();
}

void Database::connect()
{
	pqxx::connection c("dbname=prueba user=ramiro password=c4c4fr1t489");	
    pqxx::work txn(c);
}

pqxx::result Database::query(std::string query)
{
	pqxx::result r = txn.exec("select user_id, email from users");
	return r;
}
