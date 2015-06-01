#include <string>
#include <time>
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
	return ctime(time(&this->_response_time));
}
