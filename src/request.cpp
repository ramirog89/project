#include <stdlib.h>
#include <string>
#include "../include/http/request.h"

using namespace Core;

Http::Request::Request(std::string mensaje)
{
    // string::regex o algoasi.. nose
    // aca tengo que hacer la magia de explodear al get..
    // y traer al resource, action y args.. y whiala..

    // {@see: http://www.freeinfosociety.com/pdfs/computers/12strings.pdf?phpMyAdmin=af0f6b4465fe3f904426eaeb3dc0e3fa&phpMyAdmin=Kb2XHnhmhTctZwPmOqks7zD3-sc}
    // todos los ejemplos de el string.compare, string.substr
    // string.find.. etc con esas funciones.. saco todo ñaca ñaca

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
