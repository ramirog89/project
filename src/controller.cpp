#include "../include/controller.h"
#include "../include/database.h"

using namespace Core;

Controller::Controller()
{
    this->_database = Database::getInstance();
}
