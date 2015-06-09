#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h> // socket|listen|accept 
#include <netinet/in.h> // estructura de los address_SOCKS
#include "../include/server.h"

using namespace Core;

Server::Server(int port) 
{
    this->_port = port;
}

int Server::start(){
    std::cout << "inicializando el servidor \n";

     // Open Socket
    this->_socket = socket(
        AF_INET, // *nix/ domain address 
        SOCK_STREAM, // type socket TCP/STREAM
        0
    );

    if (this->_socket < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

     // SERVER ADDRESS CONFIG
    this->serv_addr.sin_family = AF_INET; // Family address
    this->serv_addr.sin_addr.s_addr = INADDR_ANY;  // IP HOST
    this->serv_addr.sin_port = htons(this->_port); // PORT NUMBER converted to network byte order with htons()
    if (bind(this->_socket, (struct sockaddr *) &this->serv_addr,
        sizeof(this->serv_addr)) < 0) 
    {
        perror("ERROR on binding");
        exit(1);
    }

    return 1;
}

int Server::stop()
{
    close(this->_socket); 
    return 1; //status
}

char* Server::listensock()
{
    std::cout << "Comienza la lectura el socket\n";

    listen(this->_socket, 5);
    this->clilen = sizeof(this->cli_addr); 

    while(1)
    {
        this->_newsock = accept(this->_socket,
        (struct sockaddr *) &this->cli_addr,
        &this->clilen);
        if (this->_newsock < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        this->_pid = fork();
        if (this->_pid < 0) {
            perror("ERROR on fork");
            exit(1);
        }

        if (this->_pid == 0) { 
            close(this->_socket); 

            if (this->readsock(this->_newsock) < 0) {
                perror("Error reading socket");
                exit(1);
            }

            return this->_buffer;

            exit(0);
        } 
        else close(this->_newsock);
    }
}

void Server::restart()
{   
    this->stop();
    this->start();
}

void Server::setStatus(int status)
{
    this->_status = status;
}

int Server::getNewSocket()
{
    return this->_newsock;
}

int Server::readsock(int sock)
{
    int n;

    n = read(sock, this->_buffer, sizeof(this->_buffer));

    return n;
}

void Server::writesock(int sock, std::string buffer)
{
    // std::string.c_str() devuelve la cadena del string
    // sizeof(char)* es el cast del std::string.size()
    write(sock, buffer.c_str(), sizeof(char)*buffer.size());
}

int Server::getStatus()
{
    return this->_status;
}

