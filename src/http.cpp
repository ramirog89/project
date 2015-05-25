Http::Http()
{
    if (_is_http_valid(httpMsg))
    {
        _request  = new Request();
        _response = new Response();
    }
}

Http::getRequest()
{
    return _request;
}

Http::getResponse()
{
    return _response;
}

Http::send()
{
    /** Aca se genera el mensaje HTTP **/
}
