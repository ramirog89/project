namespace Core;

class Front
{
    private:
        Http _http;
        int _controller;
        int _action;
        int _args;
        void _init(){};

    public:
        Front::Front(){};
        Front::setController(){};
        Front::getController(){};
        Front::setAction(){};
        Front::getAction(){};
        Front::setArgs(){};
        Front::getArgs(){};
        Front::execute(){};
};
