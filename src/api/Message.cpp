#include "prototype/Message.h"

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
User::get()
{
	pqxx::result r = this->_database->query($sql);
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