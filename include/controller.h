#ifndef CORE_CONTROLLER_H
#define CORE_CONTROLLER_H

namespace Core {

class Controller 
{
    private:
        Database* _database;
    public:
        Controller;
        virtual int post();
        virtual int put();
        virtual int delete();
        virtual int get();
        virtual int head();
}

} //namespace Core

#endif
