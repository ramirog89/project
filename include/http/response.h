#ifndef HTTP_RESPONSE_H 
#define HTTP_RESPONSE_H

namespace Core {
    namespace Http {

class Response
{
    private:
        char _headers[];
        std::string _body;
    public:
        void setResponse();
        char getResponse();
        void setHeaders(char*);
        char* getHeaders();
        void setHeader(char);
        char getHeader(int);
        void setBody(std::string);
        std::string getBody();
};

    } //namespace Http
} //namespace Core

#endif
