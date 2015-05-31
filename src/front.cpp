#include <string>

#include "../include/http/request.h"
#include "../include/http/response.h"
#include "../include/front.h"

using namespace Core;

Front::Front(
    Http::Request request, 
    Http::Response response)
{
    this->_request  = &request;
    this->_response = &response;

    this->_init();
}

void Front::_init()
{
    this->setController( 
        this->_request->getResource()
    );
    this->setAction( 
        this->_request->getActionResource() 
    );
    this->setArgs( 
        this->_request->getArgs() 
    );
}

std::string Front::exec()
{
    std::string e("Esto es el output");
    

    return e;
/*
    return exec(
        new {getController()},
        {getAction()},
        getArgs(),
    )
*/
}

void Front::setController(char controller)
{
    this->_controller = controller;
}

void Front::setAction(char action)
{
    this->_action = action;
}

void Front::setArgs(char args)
{
    this->_args = args;
}

char Front::getController()
{
    return _controller;
}

char Front::getAction()
{
    return _action;
}

char Front::getArgs()
{
    return _args;
}
