#include "../include/controller.h"
#include "../include/database.h"

using namespace Core;

Controller::Controller()
{
    this->_database = Database::getInstance();
}

/**
 * {@see: http://karthikpresumes.blogspot.com/2011/10/prototype-pattern-in-c-dynamic.html}
 */
// Busca el controlador pedido en la tabla de prototipo y devuelve el Clone del objeto instanciado
Controller* Controller::makeController(std::string type)
{
	Controller* proto;
	// {@link: http://www.cplusplus.com/reference/algorithm/find/}
	if (!find(type, proto, Controller::protoTable))
		perror("prototype not found");
	
	return proto->clone();
}

// Agrega un Controlador a la tabla del Prototipo para poder ser consumido dinamicamente
Controller* Controller::addPrototype(std::string type, Controller* c)
{
	std::cout << "adding prototype for " << type << endl;
	Controller::protoTable[type] = c;
	std::cout << "done\n";
	
	return c; // handy
}