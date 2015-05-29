namespace Core {
    namespace Http {

class Response
{
    private:
        char _headers[];
        char _response;
    public:
        void setResponse(){};
        char getResponse(){ return _response; };
        void setHeaders(char header[]){};
        char* getHeaders(){ return _headers; };
        void setHeader(char header){};
        char getHeader(int  header){ return _headers[header]; };
        char send(){ return _response; };
};

    } //namespace Http
} //namespace Core
