#include <string>
#include "../include/http/response.h"

using namespace Core;

void Http::Response::setBody(std::string body)
{
    this->_body = body;
}

std::string Http::Response::getBody()
{
    return this->_body;
}

