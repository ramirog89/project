#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

#include "../src/server.cpp"
#include "../src/handler.cpp"
//#include "../include/front.h"

using namespace std;
using namespace Core;

#define DEFAULT_PORT 51517;

int main(int argc, char *argv[])
{
    Server * server;
    Http::Handler * http;
    int status;

    // Definimos al Servidor con el puerto que querramos
    server = new Core::Server( 51517 );

    cout << "Iniciando server" << endl;

    // Iniciamos el servidor
    status = server->start();

    // Si estuvo todo bien
    if (status) {
        // Ponemos a escuchar al servidor
        std::string response(server->listensock()); // constructor de char* a string..

        if (response.length() > 0) { 
            // inicializamos el HTTP Handler Lee HTTP y responde HTTP
            http = new Core::Http::Handler( response ); // probablemente sea un singleton

            // aca iria el front... ?..
            // algo asi como..
            // front = new Front( http->getRequest(), http->getResponse() );
            // rta_recurso_pedido  = front->exec();
            // server_response = http->send( rta_recurso_pedido ); -> pero asi se puede validar.. almeno ¿? nose alpedo igual
            // o... http->send( front->exec() );

            // el servidor escribe al cliente
            server->writesock(
                server->getNewSocket(),
                http->send() // aca va el HTTP + el body JSON
            );
        }
    }

    return 0;
    
}
