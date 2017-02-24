#ifndef SERVERFACTORY_HPP
#define SERVERFACTORY_HPP

#include "Server.hpp"

class ServerFactory {
private:
  std::list<Server *> serversList;

public:
  ServerFactory();
  ~ServerFactory();
  std::list<Server *> getServersList() const;
  int addServer(Server *);
  int deleteServer(Server *);
  Server *getServerByIp(std::string);
  std::string printFactory();
  bool isInList(std::string);
};

#endif
