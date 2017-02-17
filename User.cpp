#include "User.hpp"

User::User(std::string ip, std::string name) {
  std::cout << "Bienvenue " << name << ", votre adresse IP est : " << ip << std::endl;
  this->ip = ip;
  this->name = name;
  createIpAccess();
}

User::~User() {
}

std::string User::getIp() const {
  return this->ip;
}

std::string User::getName() const {
  return this->name;
}

int User::createIpAccess() {
  std::ifstream infile("config.txt");
  std::string line;
  char **sep;
  char *tmp;
  int i = 0;
  
  if ((sep = (char **)malloc(3 * sizeof(char *))) == NULL) {
    std::cerr << "Error: malloc failed" << std::endl;
    return 1;
  }
  while (std::getline(infile, line)) {
    if (strncmp(this->ip.c_str(), line.c_str(), this->ip.length()) == 0) {
      tmp = strtok((char *)line.c_str(), "|;");
      while (tmp != NULL) {
	sep[i++] = tmp;
	tmp = strtok(NULL, "|;");
      }
      i = 1;
      while (sep[i])
	this->ipAccess.push_back(sep[i++]);
    }
  }
  return 0;
}

bool User::isAutorized(std::string ip) {
  std::list<std::string>::iterator it;
  
  for (it = this->ipAccess.begin(); it != this->ipAccess.end(); ++it) {
    if (ip.compare(*it) == 0)
      return true;
  }
  return false;
}
