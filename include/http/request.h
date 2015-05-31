#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

namespace Core {
    namespace Http {

class Request
{
    private:
        char _resource;
        char _actionResource;
        char _args;
        std::string _http_message;
    public:
        Request(std::string);
        char getResource();
        char getActionResource();
        char getArgs();
};

    } //namespace Http
} //namespace Core

#endif
