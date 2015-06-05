#ifndef HTTP_RESPONSE_H 
#define HTTP_RESPONSE_H

namespace Core {
    namespace Http {

struct statusMessage {
	int status;
	const char* message;
}
	
/**
 * {@see: http://www.w3.org/Protocols/rfc2616/rfc2616-sec6.html}
 */
class Response
{
    private:
        char _statusMessages[7] = {
			{200, "OK"},
			{302, "Temprary redirect"},
			{403, "Forbidden"},
			{404, "Not Found"},
			{405, "Method Not Allowed"},
			{500, "Internal Server Error"},
			{501, "Not Implemented"},
			{505, "HTTP Version not supported"}
		};
		
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
