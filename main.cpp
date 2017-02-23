#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

bool isUserInFile(std::string name) {
  std::ifstream infile("users.conf");
  std::string line;

  while (std::getline(infile, line)) {
    int i = line.find_first_of(":", 0);
    if (line.substr(0, i).compare(name) == 0)
	return true;
  }
  return false;
}

std::string getPassword(std::string name) {
  std::ifstream infile("users.conf");
  std::string line;

  while (std::getline(infile, line)) {
    int i = line.find_first_of(":", 0);
    if (line.substr(0, i).compare(name) == 0)
      return line.substr(name.length() + 1, line.length() - name.length() - 3);
  }
  return "";  
}

bool isAdmin(std::string name) {
  std::ifstream infile("users.conf");
  std::string line;

  while (std::getline(infile, line)) {
    int i = line.find_first_of(":", 0);
    if (line.substr(0, i).compare(name) == 0) {
      if (line.substr(line.length() - 1, 1).compare("1") == 0)
	return true;
      else
	return false;
    }
  }
  return false;  
}

int main(int ac, char **av) {
  if (isUserInFile(av[1]))
    std::cout << av[1] << " exists." << std::endl;
  else
    std::cout << av[1] << " does not exist." << std::endl;

  std::string password = getPassword(av[1]);
  if (!password.empty())
    std::cout << "password : " << password << std::endl;
  if (isAdmin(av[1]) == true)
    std::cout << av[1] << " is admin. " << std::endl;
  else
    std::cout << av[1] << " is not admin. "<< std::endl;
  return 0;
}
