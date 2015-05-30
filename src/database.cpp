#include <iostream>
#include <pqxx/pqxx>
//#include "../include/database.h"

int main()
{
    pqxx::connection c("dbname=prueba user=ramiro password=c4c4fr1t489");
    pqxx::work txn(c);

    pqxx::result r = txn.exec("select user_id, email from users");
//        "WHERE name =" + txn.quote(argv[1]));

   // We'll be printing these fields:
    std::cout
      << "ID" << "\t"
      << "Email" << std::endl;

// Iterate over the rows in our result set.  Results objects
    // are containers similar to std::vector and such.
    for (
      pqxx::result::const_iterator row = r.begin();
      row != r.end();
      ++row)
    {
        // Fields within a row can be accessed by column name.
        // You can also iterate the fields in a row, or index the row
        // by column number just like an array.
        // Values are stored internally as plain strings.  You access
        // them by converting each to the desired C++ type using the
        // "as()" function template.
        std::cout
            << row["user_id"].as<int>() << "\t"
            << row["email"].as<std::string>() << "\t"
            << std::endl;
    }

/*
    if (r.size() != 1)
    {
    std::cerr
      << "Hubo más de un resultado , "
      << "but found " << r.size() << std::endl;
    return 1;
    }
*/


//    int employee_id = r[0][0].as<int>();
//    std::cout << "Updating employee #" << employee_id << std::endl;

/*
    txn.exec(
        "UPDATE EMPLOYEE "
        "SET salary = salary + 1 "
        "WHERE id = " + txn.quote(employee_id));

    txn.commit();
*/
} 
