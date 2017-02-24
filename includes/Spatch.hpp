#ifndef SPATCH_HPP
#define SPATCH_HPP

#include "ServerFactory.hpp"
#include "Cmd.hpp"

#include <libssh/libssh.h>
#include <libssh/server.h>

#include <stdlib.h>
#include <string>
#include <string.h>
#include <stdio.h>

#define KEYS_FOLDER "/etc/ssh/"

class Spatch {
private:
  ServerFactory *serversList;
  UserFactory *usersList;
  Cmd *cmd;
  ssh_session session;
  int port;

public:
  Spatch();
  Spatch(int port);
  ~Spatch();
  int execSpatch();
  void onceConnected(User *u);
  void sshStuff();
  int initSsh();
  ServerFactory *getServersList() const;
  UserFactory *getUsersList() const;
  Cmd *getCmd() const;
  char* parse_buf(char *buf);
  int connectUser(User *);
  int disconnectUser(User *);
  int addServer(Server *);
  int removeServer(Server *);
};

#endif
