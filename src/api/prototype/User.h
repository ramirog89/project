#ifndef API_CONTROLLER_USER_H
#define API_CONTROLLER_USER_H

using namespace Core;

class User : public Core::Controller
{
    public:
		// Macro definido en el CoreController
		IMPLEMENT_CLONE(User);
		// Controller* clone() const { return new User(*this); } < visto desde el preprocesador
		// Devuelve una clonacion del objeto
		
        int post();
        int put();
        int delete();
        int get();
        int head();
}

#endif