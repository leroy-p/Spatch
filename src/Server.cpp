#include "../includes/Server.hpp"

Server::Server(std::string ip) {
  this->ip = ip;
  this->isPublic = true;
  this->connectedUsers = new UserFactory();
  this->accessList = new UserFactory();
  this->banList = new UserFactory();
  std::cout << "New server created : " << ip << std::endl;
}

Server::~Server() {
  std::cout << "New server deleted : " << this->getIp() << std::endl;
}

std::string Server::getIp() const {
  return this->ip;
}

bool Server::getIsPublic() const {
  return this->isPublic;
}

void Server::setIsPublic(bool isPublic) {
  this->isPublic = isPublic;
  if (isPublic == true)
    std::cout << "Server " << this->getIp() << " is now public" << std::endl;
  else
    std::cout << "Server " << this->getIp() << " is now private" << std::endl;
}

UserFactory *Server::getConnectedUsers() const {
  return this->connectedUsers;
}

UserFactory *Server::getAccessList() const {
  return this->accessList;
}

UserFactory *Server::getBanList() const {
  return this->banList;
}

int Server::connectUser(User *user) {
  if ((this->isPublic == true && this->isInBanList(user) == false) ||
      (this->isPublic == false && this->isInAccessList(user) == true && this->isInBanList(user) == false)) {
    if (this->connectedUsers->addUser(user) == 0) {
      std::cout << user->getName() << " has connected to the server " << this->getIp() << std::endl;
      return 0;
    }
    std::cout << user->getName() << " is already connected to the server " << this->getIp() << std::endl;
    return 1;
  }
  std::cout << user->getName() << " does not have access to the server " << this->getIp() << std::endl;
  return 1;
}

int Server::disconnectUser(User *user) {
  if (this->connectedUsers->deleteUser(user) == 0) {
    std::cout << user->getName() << " has disconnected to the server " << this->getIp() << std::endl;
    return 0;
  }
  std::cout << user->getName() << " is already disconnected to the server " << this->getIp() << std::endl;
  return 1;
}

int Server::allowUser(User *user) {
  if (this->accessList->addUser(user) == 0) {
    std::cout << user->getName() << " now has access to the server " << this->getIp() << std::endl;
    return 0;
  }
  std::cout << user->getName() << " already has access to the server " << this->getIp() << std::endl;
  return 1;
}

int Server::unallowUser(User *user) {
  if (this->accessList->deleteUser(user) == 0) {
    std::cout << user->getName() << " no longer has access to the server " << this->getIp() << std::endl;
    return 0;
  }
  std::cout << user->getName() << " had no access to the server " << this->getIp() << std::endl;
  return 1;
}

int Server::banUser(User *user) {
  if (this->banList->addUser(user) == 0) {
    std::cout << user->getName() << " is now banned to the server " << this->getIp() << std::endl;
    return 0;
  }
  std::cout << user->getName() << " is already banned to the server " << this->getIp() << std::endl;
  return 1;
}

int Server::unbanUser(User *user) {
  if (this->banList->deleteUser(user) == 0) {
    std::cout << user->getName() << " is no longer banned to the server " << this->getIp() << std::endl;
    return 0;
  }
  std::cout << user->getName() << " was not banned to the server " << this->getIp() << std::endl;
  return 1;
}

bool Server::isInAccessList(User *user) {
  return this->accessList->isInList(user->getName());
}

bool Server::isInBanList(User *user) {
  return this->banList->isInList(user->getName());
}
