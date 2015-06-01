#include <stdlib.h>
#include <string>
#include "../include/http/request.h"

using namespace Core;

Http::Request::Request(std::string uri)
{
	/**
	 * Aca estaria bueno ya parsear y tener todo..
	 * del http Request... el metodo para vaalidar si escorrecto
	 * el user agent... el host que lo pidio..
	 * y validar si es correcto el request?...
	 * en caso de ser valido.. paso solamente el URL
	 * a el Request, que va a explotar todo de ahi
	 * para obtener el recurso/action/params
	 *
	 * Hay que parsear al httpmessage con las funciones de 
	 * string... string.sub, string.find, string.match
	 * y obtener los datos que quiero
	 */


    // string::regex o algoasi.. nose
    // aca tengo que hacer la magia de explodear al get..
    // y traer al resource, action y args.. y whiala..

    // {@see: http://www.freeinfosociety.com/pdfs/computers/12strings.pdf?phpMyAdmin=af0f6b4465fe3f904426eaeb3dc0e3fa&phpMyAdmin=Kb2XHnhmhTctZwPmOqks7zD3-sc}
    // todos los ejemplos de el string.compare, string.substr
    // string.find.. etc con esas funciones.. saco todo ñaca ñaca

    this->_uri = uri; // el original.. solo para mantenerlo
    this->_resource = 'a'; // recurso del uri
    this->_actionResource = 'b'; // action del uri
    this->_args = 'c'; // params del uri
}

std::string Http::Request::getRequestUri()
{
    return this->_request_uri;
}

