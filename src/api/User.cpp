#include "prototype/User.h"

/** 
 * Agrega el Objeto a la tabla de prototipos para estar disponible y ser
 * consumido dinamicamente
 */
MAKE_PROTOTYPE(User);

/**
 * Aca en teoria, tienen que venir todos los recursos
 * por ejemplo la uri:
 * 		/users/:id/marks
 * 		/users/:id/notifications
 * 		/users
 * y esto tiene que resolver segun los recursos
 * puedo explotar al string por / y quedarme
 * con lo que no sea int.. ??
 * para crear la query, almenos por ahora seria asi
 */
// Esto deberia recibir un array del tipo
// keynameattr => value
std::vector<char> User::get()
{
	std::string sqlStatement = 
		"SELECT *"
		"FROM users";
				   
	return this->_database->query(sqlStatement);
}

User::head()
{}

int User::put()
{}

/** INSERT USER **/
int User::post()
{}

/** DELETE USER **/
int User::delete(int id)
{}