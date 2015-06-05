#include <string>
#include <vector>
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

/** 
 * @Description: Obtengo la URI del request y defino el recurso/controller 
 *               el action y los argumentos del mismo
 */
void Front::_init()
{
	std::string original_uri = this->_request->getRequestUri();
    
	this->setController( 
        original_uri.find(0, 'primeraparte')
    );
    this->setAction( 
        original_uri.find(10, 'action')
    );
    this->setArgs( 
        original_uri.find(30, 'lodemas')
    );
}

void Front::exec()
{
	//local front output buffer
	std::string output;
	
    /**
	 * {@see: {@see: http://karthikpresumes.blogspot.com/2011/10/prototype-pattern-in-c-dynamic.html}}
	 * {@link: http://www.cs.sjsu.edu/~pearce/modules/lectures/oop/types/reflection/prototype.htm}

	 Controller* controller;
   	 controller = Controller::makeController(this->_getController());
		
	 switch(this->_request->getMethod()) // esto no esta nada mal tampoco
	 {
		case 'POST':
			output = (*controller)->post(this->_getArgs());
		break;
		case 'PUT':
			output = (*controller)->put(this->_getArgs());
		break;
		case 'DELETE':
			output = (*controller)->delete(this->_getArgs());
		break;
		case 'HEAD':
			output = (*controller)->head(this->_getArgs());
		break;
		default:
			output = (*controller)->get(this->_getArgs());
		break;
	 }
    */
	
    output = "{ 'users' : [{ 'email' : 'ramirog89@gmail.com', 'password' : 'peperoni', 'user_id' : '1' }] }";

    this->_response->setBody(output);
}

void Front::setController(std::string controller)
{
    this->_controller = controller;
}

void Front::setAction(std::string action)
{
    this->_action = action;
}

void Front::setArgs(int arrayArgs)
{
	// array iterator... push in _args
	// Adentro puede tener un struct keyValuePar { std::string key, std::string value } ??
	/* {@see: http://www.cplusplus.com/reference/array/array/begin/}
	for ( auto it = arrayArgs.begin(); it != arrayArgs.end(); ++it )
		this->_args.push_back(*it);
	
	arrayArgs::begin;
		this->_args.push_back(arg[i])
	arrayArgs::end;*/
    this->_args = arrayArgs;
}

std::string Front::getController()
{
    return this->_controller;
}

std::string Front::getAction()
{
    return this->_action;
}

std::vector<std::pair<std::string,std::string> > Front::getArgs()
{
    return this->_args;
}
