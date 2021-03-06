#ifndef USERFACTORY_HPP
#define USERFACTORY_HPP

#include "User.hpp"

class UserFactory {
private:
  std::list<User *> usersList;

public:
  UserFactory();
  ~UserFactory();
  std::list<User *> getUsersList() const;
  int addUser(User *);
  int deleteUser(User *);
  User *getUserByName(std::string);
  bool isInList(std::string);
  std::string printFactory();
};

#endif
