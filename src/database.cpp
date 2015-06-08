#include <iostream>
#include <pqxx/pqxx>
#include "../include/database.h"

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
   try
   {
     pqxx::result r = this->_txn.exec(query);
     this->_txn.commit();
	 
     return r;
   }
   catch (const std::exception &e)
   {
     std::cerr << e.what() << std::endl;
     return 1;
   }
}
