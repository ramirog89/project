#ifndef CORE_FRONT_H
#define CORE_FRONT_H

namespace Core {

class Front
{
    private:
        Http::Request* _request;
        Http::Response* _response;
		
        std::string _controller;
        std::string _action;
        std::vector<std::pair<std::string,std::string> > _args;
		
        void _init();
    public:
        Front(Http::Request, Http::Response);
        void setController(std::string);
        std::string getController();
        void setAction(std::string);
        std::string getAction();
        void setArgs(int);
        std::vector<std::pair<std::string,std::string> > getArgs();
        void exec();
};

} //namespace Core

#endif
