#include "../includes/Spatch.hpp"

Spatch::Spatch() {
  this->serversList = new ServerFactory();
  this->usersList = new UserFactory();
  this->cmd = new Cmd();
  std::cout << "Welcome to Spatch." << std::endl;
  this->execSpatch();
}

Spatch::~Spatch() {
  std::cout << "You have left Spatch." << std::endl;
}

int Spatch::execSpatch() {
  Server *s1 = new Server("111.11.11.1");
  Server *s2 = new Server("222.22.22.2");
  Server *s3 = new Server("333.33.33.3");
  User *u1 = new User("127.0.0.1", "toto");
  User *u2 = new User("127.0.0.2", "titi");
  User *u3 = new User("127.0.0.3", "tutu");
  int check = 2;
  User *u;
  std::string name;
  char buf[4096];

  this->addServer(s1);
  this->addServer(s2);
  this->addServer(s3);
  this->connectUser(u1);
  this->connectUser(u2);
  this->connectUser(u3);
  
  while (check > 0) {
    if (check == 2)
      std::cout << std::endl << "Pease enter your username." << std::endl;
    else if (check == 1)
      std::cout << "Please enter another username." << std::endl;
    std::cin >> name;
    u = new User("127.0.0.4", name, true);
    check = this->connectUser(u);
    if (check == 1)
      delete u;
  }
  check = 1;
  while (1) {
    std::cin.getline(buf, sizeof(buf));
    if (strcmp(buf, "exit") == 0)
      return 0;
    else if (strcmp(buf, "") != 0) {
      this->getCmd()->setCmd(buf);
      this->getCmd()->execCmd(this->getUsersList(), this->getServersList(), u);
    }
  }
  return 1;
}

ServerFactory *Spatch::getServersList() const {
  return this->serversList;
}

UserFactory *Spatch::getUsersList() const {
  return this->usersList;
}

Cmd *Spatch::getCmd() const {
  return this->cmd;
}

int Spatch::connectUser(User *user) {
  if (this->usersList->addUser(user) == 0) {
    std::cout << user->getName() << " has connected to Spatch." << std::endl;
    return 0;
  }
  std::cout << user->getName() << " is already connected to Spatch." << std::endl;
  return 1;
}

int Spatch::disconnectUser(User *user) {
  if (this->usersList->deleteUser(user) == 0) {
    std::cout << user->getName() << " has disconnected to Spatch." << std::endl;
    return 0;
  }
  std::cout << user->getName() << " is already disconnected to Spatch." << std::endl;
  return 1;
}

int Spatch::addServer(Server *server) {
  if (this->serversList->addServer(server) == 0) {
    std::cout << server->getIp() << " has been added to Spatch." << std::endl;
    return 0;
  }
  std::cout << server->getIp() << " is already in Spatch." << std::endl;
  return 1;
}

int Spatch::removeServer(Server *server) {
  if (this->serversList->deleteServer(server) == 0) {
    std::cout << server->getIp() << " is removed to Spatch." << std::endl;
    return 0;
  }
  std::cout << server->getIp() << " was already removed to Spatch." << std::endl;
  return 1;
}
