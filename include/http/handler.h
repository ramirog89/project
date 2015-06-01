#ifndef HTTP_HANLDER_H
#define HTTP_HANDLER_H

namespace Core {
    namespace Http {

class Handler
{
    private: 
        int version;
        std::string _headers;
        char method;
        char user_agent;
        char host;
        bool _valid_http_request(char);
        Request* _request;
        Response* _response;

    public:
        Handler(std::string); // se inicializan request y response aca new response, new reuqest
        void setHeaders();
        void setContent();
        void setAgent();
        void buildResponse();
        Request* getRequest();
        Response* getResponse();
        std::string sendHeaders();
        std::string send();
};

    } // namespace Http
} //namespace Core

#endif
