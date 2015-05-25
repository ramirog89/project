#include <request.h>
#include <response.h>

namespace Core;

class Http
{
    private: 
        int version;
        int headers;
        string body;
        char method;
        char user_agent;
        char host;
        void _setBody(){};
        bool _valid_http_request(){};

    public:
        Request request;
        Response response;
        Http::Http(){};
        Http::setResponse(){};
        Http::getResponse(){};
        Http::setRequest(){};
        Http::getRequest(){};
        Http::send(){};
};

