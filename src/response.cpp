#include <string>
#include "../include/http/response.h"

using namespace Core;

std::string Http::Response::send(std::string json)
{
    this->_response = json;
    return this->_response;
}
