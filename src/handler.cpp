#include <iostream>

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

std::string Http::Handler::send(std::string json)
{
    return this->_response->send( json );
}
