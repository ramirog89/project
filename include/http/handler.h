#ifndef HTTP_HANLDER_H
#define HTTP_HANDLER_H

namespace Core {
    namespace Http {

class Handler
{
    private: 
        int version;
        int headers;
        char body;
        char method;
        char user_agent;
        char host;
        void _setBody(){};
        bool _valid_http_request(char);
        std::string http_response;
//        Core::Http::Request _request;
//        Core::Http::Request _response;

    public:
        Handler(std::string); // se inicializan request y response aca new response, new reuqest
        void setHeaders();
        void setContent();
        void setAgent();
        void buildResponse();
        Http::Request getRequest();
        Http::Response getResponse();
        std::string send();
};

    } // namespace Http
} //namespace Core

#endif
