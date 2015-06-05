#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

namespace Core {
    namespace Http {

/**
 * {@see: http://www.w3.org/Protocols/rfc2616/rfc2616-sec5.html}
 */
class Request
{
    private:
        float _version;
        const char* _method;
        const char* _user_agent;
        const char* _host;
		std::string _request_uri;
        
    public:
        Request(std::string);
		
		void setVersion(float);
		void setUserAgent(const char*);
		void setMethod(const char*);
		void setHost(const char*);
		void setRequestUri(std::string);
		
		float getVersion();
		const char* getUserAgent();
		const char* getMethod();
		const char* getHost();
		std::string getRequestUri();
};

    } //namespace Http
} //namespace Core

#endif
