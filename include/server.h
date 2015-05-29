#ifndef SERVER_H
#define SERVER_H

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
        struct sockaddr_in serv_addr, cli_addr;
        socklen_t clilen;

    public:
        Server(int);
        int start(); // sock este mismo crea el socket..
        int stop();
        char listensock();
        void restart();//aca va stop y start.. guardando en memoria algo?.. ponele
        int getStatus();
        void setStatus(int); // this->_status = status
};

} //namespace Core

#endif
