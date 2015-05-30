#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

#include "../src/server.cpp"
#include "../include/http/handler.h"
#include "../include/front.h"

using namespace std;
using namespace Core;

#define DEFAULT_PORT 51517;

int main(int argc, char *argv[])
{
    Server * server;
    int status;

    // asi llamo al construct.. cuack ok.. esta bien
    server = new Core::Server( 51517 );

    cout << "Iniciando server" << endl;

    status = server->start();


    if (status) {
        std::string response(server->listensock()); // constructor de char* a string..

        server->writesock(server->getNewSocket(), response);
/*

    switch (status) {
        case server::trunon:
            do {

                if (server_http_msg != false) {
                    // Creo un HTTP object con el resultado de la escucha del socket
                    http    = new Http(
                        server_http_msg
                    ); // probablemente sea un singleton

                    // Le paso el HTTP al front para que pueda generar el recurso apartir de la solicitud
                    front   = new Front(http);

                    // Genero el recurso en JSON y lo envio como respuesta HTTP
                    r = http->sendHttpRespone(
                        font->execute()
                    );

                    // LO ENVIO AL SOCKET...
                    server->send(r);
                }


            } while(server_http_msg = server->listen();
        break;
        case server::status_fail:
            return server->getError();
        break;
*/
    }

    return 0;
    
}
