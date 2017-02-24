#ifndef SPATCH_HPP
#define SPATCH_HPP

#include "ServerFactory.hpp"
#include "Cmd.hpp"

#include <libssh/libssh.h>
#include <libssh/server.h>
#include <libssh/callbacks.h>
#include <libssh/sftp.h>

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

  bool isUserInFile(std::string);
  int execSpatch();
  std::string getPassword(std::string);
  void onceConnected(User*);
  int addUserInFile(std::string, std::string);
  void sshStuff();
  int connection();
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
