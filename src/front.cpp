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

void Front::_init()
{
	/** 
	 * Obtengo la URI del request y defino
	 * el recurso/controller
	 * el action
	 * los argumentos del mismo
	 */
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
     * {@see: http://www.cs.sjsu.edu/~pearce/modules/lectures/oop/types/reflection/prototype.htm}
     * Quizas sea bueno crear un prototipo para los controladores ¿?.. salvo que el uso de using Namespace ::object::method funcione de pelos ¿?
     * {@see: http://stackoverflow.com/questions/4189682/calling-an-external-function-from-a-class-method}
	 * Me parece que ésto es lo que más sentido tiene:
	 * {@see: {@see: http://karthikpresumes.blogspot.com/2011/10/prototype-pattern-in-c-dynamic.html}}
	 * {@link: http://www.cs.sjsu.edu/~pearce/modules/lectures/oop/types/reflection/prototype.htm}
	 * Armar un Prototype Pattern de Controller para instanciarlo Dinamicamente.
	 * Y un Factory method para construir el objeto desde la protoTable.
	 * Entonces quedaria algo asi como:

	 Controller* controller;
   	 controller = Controller::makeController(this->_getController());
	 
	 *Reflection : {@see: http://www.garret.ru/cppreflection/docs/reflect.html}
		Es la capacidad de obtener la informacion de un objeto en tiempo de ejecucion.
		Ver su tipo, sus metodos de invocacion, sus campos, esto es requerido cuando se quiere
		implementar codigo generico el cual pueda trabajar con tipos no conocidos de los objetos
		en el momento que se instancian.
		Hay muchas tareas en las que la refleccion puede ser usada: 
			- Invocar metodos remotos
			- Serializacion
			- Dump de un objeto
			- Interfaz de una base de datos
		Como funciona? : Dado un objeto, se pregunta su tipo,
			Como resultado, obtenemos un "descriptor de clase" que provee la informacino acerca de sus metodos y campos.
		
	 Nota : C++ no permite "Reflection"
		esto significa que no puedo hacer controller->*this->_getAction() 
		asi como si nada.. vamos a tener que implementarlo
		ver: {@link: http://stackoverflow.com/questions/10668363/how-to-pass-method-name-in-variable}
		
		Aca en caso de no tener el recurso, puedo poner
		Metodo no implementado, nose.. tengo que ver bien eso si tiene que ver
		con el httpmetod o el recurso implementado mio. (que es lo standard?)
		
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
	/*
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
