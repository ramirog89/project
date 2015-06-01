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

void Front::exec()
{

    /**
     * {@see: http://www.cs.sjsu.edu/~pearce/modules/lectures/oop/types/reflection/prototype.htm}
     * Quizas sea bueno crear un prototipo para los controladores ¿?.. salvo que el uso de using Namespace ::object::method funcione de pelos ¿?
     * {@see: http://stackoverflow.com/questions/4189682/calling-an-external-function-from-a-class-method}
    */
    this->_output = "{ 'users' : [{ 'email' : 'ramirog89@gmail.com', 'password' : 'peperoni', 'user_id' : '1' }] }";

    this->_response->setBody(this->_output);
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
