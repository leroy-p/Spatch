//
// Created by fab_a on 03/02/2017.
//

#include "Server.h"

std::string Server::getName() {
    return std::string();
}

std::string Server::getPort() {
    return std::string();
}

std::string Server::getIp() {
    return std::string();
}

void Server::setIp(std::string ip) {
    this->ip = ip;
}

void Server::setName(std::string name) {
    this->name =  name;
}

void Server::setPort(std::string port) {
    this->port = port;
}

Server::Server()
{
    // Here we create the server
}
