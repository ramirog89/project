#ifndef HTTP_RESPONSE_H 
#define HTTP_RESPONSE_H

namespace Core {
    namespace Http {

/**
 * {@see: http://www.w3.org/Protocols/rfc2616/rfc2616-sec6.html}
 */
class Response
{
    private:
        char _statusMessages[];
        char _headers[];
		int  _status;
        std::string _body;
		time_t _response_time;
    public:
        void setHeader(char);
        char getHeader(int);
        void setBody(std::string);
        std::string getBody();
		void setStatus(int);
        int  getStatus();
		
		std::string getTime();
};

    } //namespace Http
} //namespace Core

#endif
