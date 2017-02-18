#ifndef SPATCH_HPP
#define SPATCH_HPP

#include "ServerFactory.hpp"
#include "Cmd.hpp"

class Spatch {
private:
  ServerFactory *serversList;
  UserFactory *usersList;
  Cmd *cmd;

public:
  Spatch();
  ~Spatch();
  int execSpatch();
  ServerFactory *getServersList() const;
  UserFactory *getUsersList() const;
  Cmd *getCmd() const;
  int connectUser(User *);
  int disconnectUser(User *);
  int addServer(Server *);
  int removeServer(Server *);
};

#endif
