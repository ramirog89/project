#ifndef CORE_SERVER_H
#define CORE_SERVER_H

#include <string>

namespace Core {

/**
* Aca se definen los prototipos, por eso no se abren las llaves {}.
* Es para que el compilador sepa cuanto va a ocupar en memoria el objeto (o algo asi)
* {@see: http://stackoverflow.com/questions/2133250/does-not-name-a-type-error-in-c} 
*/
class Server
{
    private:
        int _port;
        int _socket; //file descriptor, contiene el socket del lado del server
        int _newsock; //file descriptor, contiene el socket abierto por el cliente al servidor
        int _status; 
        int _pid; // process identifier
        char _buffer[512];
        struct sockaddr_in serv_addr, cli_addr;
        socklen_t clilen;

    public:
        Server(int);
        int start(); // sock este mismo crea el socket..
        int stop();
        void restart();//aca va stop y start.. guardando en memoria algo?.. ponele

        char* listensock();
        int readsock(int);
        void writesock(int, std::string);
        int getNewSocket();

        int getStatus();
        void setStatus(int); // this->_status = status
};

} //namespace Core

#endif
