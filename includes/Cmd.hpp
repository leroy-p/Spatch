#ifndef CMD_HPP
#define CMD_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <map>
#include "UserFactory.hpp"
#include "ServerFactory.hpp"

class Cmd {
public:
  typedef void (Cmd::*pf)(char **, UserFactory *, ServerFactory *, User *);
  
private:
  std::string cmd;
  std::string cmds[10];
  pf fcts[10];
  std::string response;

public:
  Cmd();
  ~Cmd();
  std::string getCmd() const;
  int execCmd(UserFactory *, ServerFactory *, User *);
  void setCmd(std::string);
  void execConnect(char **, UserFactory *, ServerFactory *, User *);
  void execShow(char **, UserFactory *, ServerFactory *, User *);
  void execKick(char **, UserFactory *, ServerFactory *, User *);
  void execBan(char **, UserFactory *, ServerFactory *, User *);
  void execUnban(char **, UserFactory *, ServerFactory *, User *);
  void execAllow(char **, UserFactory *, ServerFactory *, User *);
  void execUnallow(char **, UserFactory *, ServerFactory *, User *);
  void execPublic(char **, UserFactory *, ServerFactory *, User *);
  void execPrivate(char **, UserFactory *, ServerFactory *, User *);
  void execHelp(char **, UserFactory *, ServerFactory *, User *);
  void createCmds();
  void createFcts();
};

#endif
