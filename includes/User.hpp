#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <fstream>
#include <list>
#include <cstring>
#include <cstdlib>

class User {
private:
  std::string name;
  bool admin;

public:
  User(std::string);
  User(std::string, bool);
  ~User();
  std::string getIp() const;
  std::string getName() const;
  bool isAdmin() const;
};

std::ostream& operator<<(std::ostream&, const User&);

#endif
