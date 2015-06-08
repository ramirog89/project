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
	// @var uri.ej : /users/1431/marks/132
	std::string original_uri = this->_request->getRequestUri();
	
	std::size_t to = original_uri.find("/");
	original_uri.substr(0, to);
    
	this->setController( 
        original_uri.substr(0, to)
    );
	
	//original_uri.find(10, 'action')
	// por lo pronto es put/del/get/head/post
    this->setAction(
		this->_request->getMethod()
    );
	
	// todo lo demas despues del controller.. o primer "/"
    this->setArgs(
        original_uri.substr(to);
    );
}

void Front::exec()
{
	//local output buffer
	std::string output;
	
    /**
	 * {@see: {@see: http://karthikpresumes.blogspot.com/2011/10/prototype-pattern-in-c-dynamic.html}}
	 * {@link: http://www.cs.sjsu.edu/~pearce/modules/lectures/oop/types/reflection/prototype.htm}
	 *
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
	
	// el body aca va limpio, se hace json en el Handler 
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

void Front::setArgs(std::string stringArgs)
{
	/**
	 * http://stackoverflow.com/questions/890164/how-can-i-split-a-string-by-a-delimiter-into-an-array
	 * Ejemplo de split string to vector
	 * Aun falta hacerlo del tipo std::pair<string,string>
	 * this->_args['marks'] = 1234 | por ejemplo
	 */
	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter))!= std::string::npos) {
		token = s.substr(0, pos);
		s.erase(0, pos + delimiter.length());
		this->_args.push_back(token);
	}
	this->_args.push_back(s);	
	
}

std::string Front::getController()
{
    return this->_controller;
}

std::string Front::getAction()
{
    return this->_action;
}

std::vector<std::string> Front::getArgs()
{
    return this->_args;
}
