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
	return txn.exec(query);
}

/**
 * {@see: http://stackoverflow.com/questions/23132621/create-a-json-array-in-c}
 * Como retornar un valor json de un vector en C++
 *
std::vector<json::value> Database::fetchResult(pqxx::result result)
{
	std::vector<res::json::value> arrayResult;
	
	for (
      pqxx::result::const_iterator row = result.begin();
      row != result.end();
      ++row)
    {
		res::json::value user;
		
		user["user_id"] = row["user_id"];
		user["email"] = row["email"];
		
        Users.push_back(user);
    }
	
	return result;
}*/
