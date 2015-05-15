#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

namespace Core;

class Server
{
    private:
        int _port;
        int socket;
        int status; 
        int _connect();

    public:
        Server(int port, (char *) sock);
        int start(){};
        int stop(){};
        int restart(){}
        int getStatus(){};
        void setStatus(){};
        void init();
        

};

Server::Server (int port, (char *) sock) 
{
    _port = port;
    _socket = sock;
}


Server::start(){}
Server::stop(){}
Server::restart(){}

Server::getStatus(){}
Server::setStatus(){}


Server::init() { _connect() };
Server::_connect(){}

