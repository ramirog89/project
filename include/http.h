#include <request.h>
#include <response.h>

namespace Core;

abstract class Http
{
    private version;

    private headers;

    private body;

    private method;

    private user_agent;

    private host;

    public function Http
    (
        http_message
    )
    {
    // @TODO : VALIDAR EL HTTP MESSAGE::
        if (this->_is_http_valid(http_message)) {
            this->request = new Request(http_message);
            this->response = new Response;
        }
    }

    public function setResponse(Response)
    {
        // Genera el JSON del resultado del recurso..
        this->_setBody( Response );
    }

    public function getResponse()
    {
    }

    public function sendHttpResponse()
    {
        /**
         * DESCRIPTION: Genera el mensaje
         * HTTP/1.1
         * BODY
         */
    }

}

