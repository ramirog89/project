#include <iostream>
#include <string>

#include "../include/http/request.h"
#include "../include/http/response.h"
#include "../include/http/handler.h"

using namespace Core;

Http::Handler::Handler(std::string httpmessage)
{
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
	// Todo esto deberia venir de los headers?
	// Headers: O->RESPONSE->getHeaders()?
	/******** OUTPUT STRING *********
	 * RESPUESTA DEL API
	 * HTTP/1.1 (O->RESPONSE->getStatus()) statusMessage[status]
	 * Server: MiServer.. joajoas! A donde te conectaste wili
	 * Date: (O->RESPONSE->getTime())
     * Content-Type: application/json (por lo pronto esta hardcodeado)
	 * Content-Length: O->RESPONSE->getBody().length()
	 * Allow: GET, PUT, DELETE, POST, HEAD
	 * \n\r
	 * O->RESPONSE->getBody()
	 *******************************/
      	 
    std::string output(
	"HTTP/1.1 200 OK\n" // el
	"Content-Type: application/json\n"
	"Content-Length: 92\n" // aca va el body.length()
	"\r\n"
	"{ 'users' : [{ 'email' : 'ramirog89@gmail.com', 'password' : 'peperoni', 'user_id' : '1' }] }"
	); // aca deberia ir el this->_toJson(body.str())

    std::cout << output << std::endl;

    //output.insert(output.length(), this->_response->getBody());

    return output;
}

json::value Http::Handler::_toJson(pqxx::result result)
{
	std::vector<res::json::value> arrayResult;
	
	for (
      pqxx::result::const_iterator row = result.begin();
      row != result.end();
      ++row)
    {
		res::json::value r;
		
		// ver como iterar campo y valor, also asi como un foreach o [0] y [1]
		r["user_id"] = row["user_id"];
		r["email"] = row["email"];
		
        arrayResult.push_back(r);
    }
	
	res::json::value jsonBodyResponse;
	
	jsonBodyResponse["response"] = res::json::value::array(arrayResult);
	
	return jsonBodyResponse;
}
