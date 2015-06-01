#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

#include "../src/server.cpp"
#include "../src/handler.cpp"
#include "../src/front.cpp"

using namespace std;
using namespace Core;

#define DEFAULT_PORT 51517;

int main(int argc, char *argv[])
{
    Server * server;
    Http::Handler * http;
    Front * front;
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

        // Quedaria mas proligo si aca se pone el while?...     
        // y el listen sock queda solo como void?..

        if (!response.empty()) { 
            // inicializamos el HTTP Handler Lee HTTP y responde HTTP
            http = new Core::Http::Handler( response ); // probablemente sea un singleton


            // Se instancia el front si el http request fue valido ...
            front = new Front(
                *http->getRequest(), 
                *http->getResponse()     
            );

            /**
             * Aca se sobre carga al objeto REsponse... 
             * si encontro el recurso, si tuvo resultado todo en el json
             */
            front->exec(); // ACA VA EL JSON

            server->writesock( // ESTO ESCRIBE EL BUFFER EN EL SOCKET 
                server->getNewSocket(), // SOCKET DEL CLIENTE
                http->send() // ACA VA EL HTTP CON EL BODY DEL RESPONSE [JSON]
            );
        }
    }

    return 0;
}
