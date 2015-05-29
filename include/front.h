namespace Core {

using namespace Http;

class Front
{
    private:
        Http::Handler* _httpHandler;
        int _controller;
        int _action;
        int _args;
        void _init(){};
        int _status; // modificado por el exec, el status de la ejecucion

    public:
        Front(){};
        void setController(char controller){};
        char getController(){ return this->_controller; };
        void setAction(char action){};
        char getAction(){ return this->_action; };
        void setArgs(char args[]){};
        char getArgs(){ return this->_args; };
        int  exec(){ return _httpHandler->send(); };
};

} //namespace Core
