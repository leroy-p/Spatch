#include "../includes/User.hpp"

User::User(std::string name) {
  std::cout << "User " << name << " has been created." << std::endl;
  this->name = name;
  this->admin = false;
}

User::User(std::string name, bool admin) {
  std::cout << "User " << name << " has been created." << std::endl;
  this->name = name;
  this->admin = admin;
}

User::~User() {
  std::cout << "User " << *this << " has been deleted." << std::endl;
}

std::string User::getName() const {
  return this->name;
}

bool User::isAdmin() const {
  return this->admin;
}

std::ostream& operator<<(std::ostream& out, const User& user) {
  return out << user.getName();
}
