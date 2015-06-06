#include <string>
#include <vector>
#include <time.h>
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

void Http::Response::setStatus(int status)
{
	this->_status = status;
}

int Http::Response::getStatus()
{
	return this->_status;
}

/**
 * {@see: http://www.cplusplus.com/reference/ctime/tm/}
 * {@see: http://www.cplusplus.com/reference/ctime/ctime/}
 */
std::string Http::Response::getTime()
{
    time( &this->_response_time );

	return ctime( &this->_response_time );
}

// No se puede definir un array estatico en el prototipo de una clase ni en un header file
const std::string Http::Response::_statusMessages[][2] = {
    {"200", "OK"},
    {"302", "Temprary redirect"},
    {"403", "Forbidden"},
    {"404", "Not Found"},
    {"405", "Method Not Allowed"},
    {"500", "Internal Server Error"},
    {"501", "Not Implemented"},
    {"505", "HTTP Version not supported"}
};
