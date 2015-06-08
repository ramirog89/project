#include <iostream>
#include <string>
#include <pqxx/pqxx>
#include "../include/http/request.h"
#include "../include/http/response.h"
#include "../include/http/handler.h"

using namespace Core;

Http::Handler::Handler(std::string httpmessage)
{
	// if (this->_valid_http_request()) 
	this->_request  = new Http::Request(httpmessage);
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

/******** OUTPUT STRING *********
 *								*
 * 		RESPUESTA DEL API		*
 *								*
 ********************************
 *
 * HTTP/1.1 (O->RESPONSE->getStatus()) O->RESPONSE->statusMessage[status]
 * Server: MyServerApiRest
 * Date: (O->RESPONSE->getTime())
 * Content-Type: application/json
 * Content-Length: O->RESPONSE->getBody().length()
 * Allow: GET, PUT, DELETE, POST, HEAD
 * \n\r
 * this->_toJson( O->RESPONSE->getBody() )
 *
 *******************************/
std::string Http::Handler::send()
{
    /*	 
    std::string output(
	"HTTP/1.1 200 OK\n" // el
	"Content-Type: application/json\n"
	"Content-Length: 92\n" // aca va el body.length()
	"\r\n"
	"{ 'users' : [{ 'email' : 'ramirog89@gmail.com', 'password' : 'peperoni', 'user_id' : '1' }] }"
	);
	*/
	
	std::string content(this->_response->getBody());
	
	std::string output(
	"HTTP/1.1 200 OK\n" // el
	"Content-Type: application/json\n"
	"Content-Length: 92\n" // aca va el body.length()
	"\r\n"
	+ content // append content
	);
	
    std::cout << output << std::endl;

    return output;
}


/**
* {@see: https://github.com/Loki-Astari/ThorsSerializer/tree/master/src/Serialize}
* {@see: https://github.com/Mizuchi/acml}
*/
std::string Http::Handler::_toJson(pqxx::result result)
{

}
