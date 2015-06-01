#ifndef HTTP_HANLDER_H
#define HTTP_HANDLER_H

namespace Core {
    namespace Http {

class Handler
{
    private: 
        float version = 1.1;
        const char* method;
        const char* user_agent;
        const char* host;
		
        bool _valid_http_request();

        Request* _request;
        Response* _response;

    public:
        Handler(std::string); // se inicializan request y response aca new response, new reuqest
        
		void setVersion(float);
		void setUserAgent(const char*);
		void setMethod(const char*);
		void setHost(const char*);
		
        Request* getRequest();
        Response* getResponse();
		
        std::string send(); // envia el http response..
};

    } // namespace Http
} //namespace Core

#endif
