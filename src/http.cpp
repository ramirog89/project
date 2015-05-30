#include "../include/http/request.h"
#include "../include/http/response.h"
#include "../include/http/handler.h"

using namespace Core;

Http::Handler::Handler(std::string httpmessage)
{
    if (httpmessage.length() > 0)
    {
        this-> http_response = httpmessage;
        //this->_request  = new Http::Request::Request(httpmessage);
        //this->_response = new Http::Response();
    }
}

/*
Http::Request Http::Handler::getRequest()
{
    return _request;
}

Http::Response Http::Handler::getResponse()
{
    return _response;
}
*/


/** Aca se genera el mensaje HTTP **/
std::string Http::Handler::send()
{
    return http_response;
}
