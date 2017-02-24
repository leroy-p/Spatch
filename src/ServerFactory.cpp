#include "../includes/ServerFactory.hpp"

ServerFactory::ServerFactory() {
  std::list<Server *> serversList;
  
  this->serversList = serversList;
  std::cout << "New server factory created." << std::endl;
}

ServerFactory::~ServerFactory() {
  std::cout << "Server factory deleted." << std::endl;
}

std::list<Server *> ServerFactory::getServersList() const {
  return this->getServersList();
}

int ServerFactory::addServer(Server *server) {
  int check = 0;
  std::list<Server *>::iterator it;

  for (it = this->serversList.begin(); it != this->serversList.end(); ++it) {
    if ((*it)->getIp().compare(server->getIp()) == 0) {
      check = 1;
      break;
    }
  }
  if (check == 0) {
    this->serversList.push_back(server);
    std::cout << "Server " << server->getIp() << " has been added to the server factory." << std::endl;
    return 0;
  }
  std::cout << "Server " << server->getIp() << " has not been added to the server factory : servername already taken." << std::endl;
  return 1;
}

int ServerFactory::deleteServer(Server *server) {
  std::list<Server *>::iterator it;

  for (it = this->serversList.begin(); it != this->serversList.end(); ++it) {
    if ((*it)->getIp().compare(server->getIp()) == 0) {
      this->serversList.erase(it);
      std::cout << "Server " << server->getIp() << " has been deleted." << std::endl;
      return 0;
    }
  }
  return 1;
}

Server *ServerFactory::getServerByIp(std::string ip) {
  std::list<Server *>::iterator it;

  for (it = this->serversList.begin(); it != this->serversList.end(); ++it) {
    if ((*it)->getIp().compare(ip) == 0) {
      return *it;
      break;
    }
  }
  std::cout << "Server with IP " << ip << " not found." << std::endl;
  return NULL;
}

std::string ServerFactory::printFactory() {
  std::list<Server *>::iterator it;
  std::string res;

  res = "============SERVERS============\n";
  for (it = this->serversList.begin(); it != this->serversList.end(); ++it) {
    res += (*it)->getIp();
    res += "\n";
  }
  res += "===============================\n";
  return res;
}

bool ServerFactory::isInList(std::string ip) {
  std::list<Server *>::iterator it;

  for (it = this->serversList.begin(); it != this->serversList.end(); ++it) {
    if ((*it)->getIp().compare(ip) == 0)
      return true;
  }
  return false;
}
