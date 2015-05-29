#include "request.h"
#include "response.h"

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
        bool _valid_http_request(char http_request){ return (true) ? true : false; };
        char http_response;
        Request request;
        Response response;

    public:
        Handler(){}; // se inicializan request y response aca new response, new reuqest
        void setHeaders(){};
        void setContent(){};
        void setAgent(){};
        void buildResponse(){};
        char send(){ return http_response; };
};

    } // namespace Http
} //namespace Core
