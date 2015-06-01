#include <iostream>
#include <string>

#include "../include/http/request.h"
#include "../include/http/response.h"
#include "../include/http/handler.h"

using namespace Core;

Http::Handler::Handler(std::string httpmessage)
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
	 
	//this->setMethod()
	//this->setUserAgent()
	//this->setHost()
	//this->setVersion()
	
	// if (this->_valid_http_request()) 
	this->_request  = new Http::Request(httpmessage); //aca va solo la uri
    this->_response = new Http::Response();
	// endif
}

Http::Request* Http::Handler::getRequest()
{
    return _request;
}

Http::Response* Http::Handler::getResponse()
{
    return _response;
}

std::string Http::Handler::send()
{
	/**
	 * RESPUESTA DEL API
	 * HTTP/1.1 (O->RESPONSE->getStatus()) statusMessage[status]
	 * Headers: O->RESPONSE->getHeaders()
     * Content-Type: application/json (por lo pronto esta hardcodeado)
	 * Content-Length: O->RESPONSE->getBody().length()
	 * \n\r
	 * O->RESPONSE->getBody()
	 */
      	 
    std::string r(
	"HTTP/1.1 200 OK\n" // el
	"Content-Type: application/json\n"
	"Content-Length: 92\n" // aca va el body.length()
	"\r\n"
	"{ 'users' : [{ 'email' : 'ramirog89@gmail.com', 'password' : 'peperoni', 'user_id' : '1' }] }"
	); // aca deberia ir el body.str()

    std::cout << r << std::endl;

    //std::cout << body << std::endl;

    //r.insert(r.length(), body.str());

    return r;
}
