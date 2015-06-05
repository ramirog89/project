#ifndef CORE_CONTROLLER_H
#define CORE_CONTROLLER_H

// Defino la macro para implementar un Controlador desde la tabla protoTable
#define IMPLEMENT_CLONE(TYPE) \
	Controller* clone() const { return new TYPE(*this); }
// Recibe el tipo del controlador y devuelve una puntero de instancia del objeto pedido
	
// Defino la macro para agregar un controllerChild en la prototable antes de que el Main se ejecute
// y poder consumir de la tabla dinamicamente
#define MAKE_PROTOTYPE(TYPE) \
	Controller* TYPE ## _myProtoype = \
	Controller::addPrototype(#TYPE, new TYPE());

namespace Core {

class Controller 
{
    protected:
        Database* _database;
    public:
        Controller();
		
		virtual ~Controller() {} // Destructor
		virtual Controller* clone() const = 0; // Allow clone
		
		//Factory Pattern
		static Controller* makeController(std::string type); // Factory
		
		//Prototype Pattern | Dynamic instantiation
		static Controller* addPrototype(std::string type, Controller* c);
		static std::map<std::string, Controller*> protoTable;
		
        virtual int post();
        virtual int put();
        virtual int delete();
        virtual char* get(); //esto podria ser un vector
        virtual char* head();//esto podria ser un vector
}

} //namespace Core

#endif
