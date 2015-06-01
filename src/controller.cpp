#include "../include/controller.h"

using namespace Core;

Core::Controller()
{
    this->_database = Database::getInstance();
}
