#include <iostream>
#include <fstream>
#include <list>
#include <cstring>
#include <cstdlib>

class User {
private:
  std::string ip;
  std::string name;
  std::list<std::string> ipAccess;

public:
  User(std::string, std::string);
  ~User();
  std::string getIp() const;
  std::string getName() const;
  int createIpAccess();
  bool isAutorized(std::string);
};
 
