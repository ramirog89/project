Server::Server (int port, (char *) sock) 
{
    _init(port, sock);
}

Server::start(){}
Server::stop(){}
Server::restart(){}

Server::getStatus(){}
Server::setStatus(){}

Server::_init() 
{ 
    _port = port;
    _socket = sock;
    _connect();
};

Server::_connect(){}

