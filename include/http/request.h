namespace Core {
    namespace Http {

class Request
{
    private:
        char resource;
        char actionResource;
        char args;
    public:
        Request();
        void  setRequest();
        void  getRequest();
        char  getResource();
        char  getActionResource();
        char* getArgs(char args[]);
};

    } //namespace Http
} //namespace Core
