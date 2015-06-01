#ifndef HTTP_RESPONSE_H 
#define HTTP_RESPONSE_H

namespace Core {
    namespace Http {

class Response
{
    private:
        char _headers[];
		int  _status;
        std::string _body;
    public:
        void setHeader(char);
        char getHeader(int);
        void setBody(std::string);
        std::string getBody();
		void setStatus(int);
        int  getStatus();
};

    } //namespace Http
} //namespace Core

#endif
