#include <stdlib.h>
#include <string>
#include "../include/http/request.h"

using namespace Core;

Http::Request::Request(std::string httpmessage)
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

    // {@see: http://www.freeinfosociety.com/pdfs/computers/12strings.pdf?phpMyAdmin=af0f6b4465fe3f904426eaeb3dc0e3fa&phpMyAdmin=Kb2XHnhmhTctZwPmOqks7zD3-sc}
    // todos los ejemplos de el string.compare, string.substr
    // string.find.. etc con esas funciones.. saco todo ñaca ñaca

	// {@see: http://www.cplusplus.com/reference/string/string/substr/}
	std::size_t uri_pos = httpmessage.find("uri");
    this->_request_uri = httpmessage.substr(uri_pos); // el original.. solo para mantenerlo
}

std::string Http::Request::getRequestUri()
{
    return this->_request_uri;
}

