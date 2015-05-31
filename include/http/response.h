#ifndef HTTP_RESPONSE_H 
#define HTTP_RESPONSE_H

namespace Core {
    namespace Http {

class Response
{
    private:
        char _headers[];
        std::string _response;
    public:
        void setResponse();
        char getResponse();
        void setHeaders(char*);
        char* getHeaders();
        void setHeader(char);
        char getHeader(int);
        std::string send(std::string);
};

    } //namespace Http
} //namespace Core

#endif
