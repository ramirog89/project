namespace Core\Http;

class Request
{
    private:
        char resource;
        char actionResource;
        char args;
    public:
        Request::Request();
        Request::setRequest();
        Request::getRequest();
        Request::getResource();
        Request::getActionResource();
        Request::getArgs();
};
