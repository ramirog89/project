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
        void _init();

    public:
        Server(int port, (char *) sock);
        int start(){};
        int stop(){};
        int restart(){}
        int getStatus(){};
        void setStatus(){};
};
