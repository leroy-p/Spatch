#ifndef USER_HPP
#define USER_HPP

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
  bool admin;

public:
  User(std::string, std::string);
  User(std::string, std::string, bool);
  ~User();
  std::string getIp() const;
  std::string getName() const;
  bool isAdmin() const;
  int createIpAccess();
  bool isAutorized(std::string);
};

std::ostream& operator<<(std::ostream&, const User&);

#endif
