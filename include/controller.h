#ifndef CORE_CONTROLLER_H
#define CORE_CONTROLLER_H

namespace Core {

class Controller 
{
    protected:
        Database* _database;
    public:
        Controller();
        virtual int post();
        virtual int put();
        virtual int delete();
        virtual char* get(); //esto podria ser un vector
        virtual char* head();//esto podria ser un vector
}

} //namespace Core

#endif
