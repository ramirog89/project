#include <iostream>
#include <string>

#include "../include/http/request.h"
#include "../include/http/response.h"
#include "../include/http/handler.h"

using namespace Core;

Http::Handler::Handler(std::string httpmessage)
{
    this->_request  = new Http::Request(httpmessage);
    this->_response = new Http::Response();
}

Http::Request* Http::Handler::getRequest()
{
    return _request;
}

Http::Response* Http::Handler::getResponse()
{
    return _response;
}

std::string Http::Handler::sendHeaders()
{
    this->_headers = "HTTP/1.1 200 OK\n"
                     "Content-Type: application/json\n"
                     "Content-Length: 92\n";
    return this->_headers;
}

std::string Http::Handler::send()
{
    // de aca se agarran todos los datos del object response..
    //std::string body = this->_response->getBody();

    std::string r("HTTP/1.1 200 OK\n"
                  "Content-Type: application/json\n"
                  "Content-Length: 92\n"
                  "\r\n"
                  "{ 'users' : [{ 'email' : 'ramirog89@gmail.com', 'password' : 'peperoni', 'user_id' : '1' }] }");

    std::cout << r << std::endl;

    //std::string r("{ 'users' : [{ 'email' : 'ramirog89@gmail.com', 'password' : 'peperoni', 'user_id' : '1' }] }");

    // Content-Length: body.length()
    // como joraca se concatenta?
    // para mi esta bien el insert el tema es que en el body
    // no vino nada.

    //std::cout << body << std::endl;

    //r.insert(r.length(), body.str());

//    r = r + (std::string)body.length() + "\n";

    //std::cout << r << std::endl;

    return r;
}
