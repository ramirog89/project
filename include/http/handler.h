#ifndef HTTP_HANLDER_H
#define HTTP_HANDLER_H

namespace Core {
    namespace Http {

class Handler
{
    private: 
        bool _valid_http_request(); // aca iria un string.compare?.. va esto?

        Request* _request;
        Response* _response;
		
		void _toJson(pqxx::result); // esto no deberia recibir el result igual

    public:
        Handler(std::string); // init request y response.
		
        Request* getRequest();
        Response* getResponse();
		
        std::string send(); // envia el http response..
};

    } // namespace Http
} //namespace Core

#endif
