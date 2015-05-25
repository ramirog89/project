Front::Front(Http http)
{
    _http = http;
    _init( http->getRequest() );
}

Front::_init()
{
    request = _http->getRequest();
    setController( request.getResource() );
    setAction( request.getActionResource() );
    setArgs( request.getArgs() );
}

Front::execute()
{
    return exec(
        new {getController()},
        {getAction()},
        getArgs(),
    )
}

Front::setController(char controller)
{
    _controller = controller;
}

Front::setAction(char action)
{
    _action = action;
}

Front::setArgs(char args)
{
    _args = args;
}

Front::getController()
{
    return _controller;
}

Front::getAction()
{
    return _action;
}

Front::getArgs()
{
    return _args;
}
