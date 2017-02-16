#include <iostream>
#include <cstring>
#include <cstdlib>
#include <map>


class Cmd {
public:
  typedef void (Cmd::*pf)(char **);
  
private:
  std::string cmd;
  std::string cmds[8];
  pf fcts[8];

public:
  Cmd(std::string);
  ~Cmd();
  std::string getCmd() const;
  void setCmd(std::string);
  int execCmd();
  void execConnect(char **);
  void execShow(char **);
  void execKick(char **);
  void execAllow(char **);
  void execBan(char **);
  void execForbid(char **);
  void execPublic(char **);
  void execPrivate(char **);
  void createCmds();
  void createFcts();
};
