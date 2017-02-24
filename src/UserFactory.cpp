#include "../includes/UserFactory.hpp"

UserFactory::UserFactory() {
  std::list<User *> usersList;
  
  this->usersList = usersList;
  std::cout << "New user factory created." << std::endl;
}

UserFactory::~UserFactory() {
  std::cout << "User factory deleted." << std::endl;
}

std::list<User *> UserFactory::getUsersList() const {
  return this->getUsersList();
}

int UserFactory::addUser(User *user) {
  int check = 0;
  std::list<User *>::iterator it;

  for (it = this->usersList.begin(); it != this->usersList.end(); ++it) {
    if ((*it)->getName().compare(user->getName()) == 0) {
      check = 1;
      break;
    }
  }
  if (check == 0) {
    this->usersList.push_back(user);
    std::cout << "User " << user->getName() << " has been added to the user factory." << std::endl;
    return 0;
  }
  std::cout << "User " << user->getName() << " has not been added to the user factory : username already taken." << std::endl;
  return 1;
}

int UserFactory::deleteUser(User *user) {
  std::list<User *>::iterator it;

  for (it = this->usersList.begin(); it != this->usersList.end(); ++it) {
    if ((*it)->getName().compare(user->getName()) == 0) {
      this->usersList.erase(it);
      std::cout << "User " << user->getName() << " has been deleted." << std::endl;
      return 0;
    }
  }
  return 1;
}

User *UserFactory::getUserByName(std::string name) {
  std::list<User *>::iterator it;

  for (it = this->usersList.begin(); it != this->usersList.end(); ++it) {
    if ((*it)->getName().compare(name) == 0) {
      return *it;
      break;
    }
  }
  std::cout << "User " << name << " not found." << std::endl;
  return NULL;
}

std::string UserFactory::printFactory() {
  std::list<User *>::iterator it;
  std::string res;

  res = "=============USERS=============\n";
  for (it = this->usersList.begin(); it != this->usersList.end(); ++it) {
    res += (*it)->getName();
    res += "\n";
  }
  res += "===============================\n";
  return res;
}

bool UserFactory::isInList(std::string name) {
  std::list<User *>::iterator it;

  for (it = this->usersList.begin(); it != this->usersList.end(); ++it) {
    if ((*it)->getName().compare(name) == 0)
      return true;
  }
  return false;
}
