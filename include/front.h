#ifndef CORE_FRONT_H
#define CORE_FRONT_H

namespace Core {

class Front
{
    private:
        Http::Request* _request;
        Http::Response* _response;
		
        char _controller;
        char _action;
        char _args;
		
        void _init();
		
        std::string _output;

    public:
        Front(Http::Request, Http::Response);
        void setController(char);
        char getController();
        void setAction(char);
        char getAction();
        void setArgs(char);
        char getArgs();
        void exec();
};

} //namespace Core

#endif
