#include <stdlib.h>
#include <string>
#include "../include/http/request.h"

using namespace Core;

Http::Request::Request(std::string mensaje)
{
    // string::regex o algoasi.. nose
    // aca tengo que hacer la magia de explodear al get..
    // y traer al resource, action y args.. y whiala..

    this->_http_message = mensaje;
    this->_resource = 'a';
    this->_actionResource = 'b';
    this->_args = 'c';
}

char Http::Request::getResource()
{
    return this->_resource;
}

char Http::Request::getActionResource()
{
    return this->_actionResource;
}

char Http::Request::getArgs()
{
    return this->_args;
}
