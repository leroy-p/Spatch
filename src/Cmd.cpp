#include "../includes/Cmd.hpp"

Cmd::Cmd() {
  this->cmd = "";
  this->response = "";
  createCmds();
  createFcts();
}

Cmd::~Cmd() {
}

std::string Cmd::getCmd() const {
  return this->cmd;
}

void Cmd::setCmd(std::string cmd) {
  this->cmd = cmd;
}

void Cmd::execConnect(char **cmds, UserFactory *uf, ServerFactory *sf, User *user) {
  if (cmds[1] == NULL || cmds[2] != NULL) {
    std::cout << "Syntax error. The command must be 'connect [ip server]'." << std::endl;
    this->response = "Syntax error. The command must be 'connect [ip server]'.";
  }
  else if (strcmp(cmds[0], "connect") == 0) {
    if (sf->isInList(cmds[1]) == true)
      sf->getServerByIp(cmds[1])->connectUser(user);
    else {
      std::cout << "Error: cannot find server " << cmds[1] << " in Spatch." << std::endl;
      this->response = "Error: cannot find server " + cmds[1] + " in Spatch.";
    }
  }
  else {
    std::cout << "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect." << std::endl;
    this->response = "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect.";
  }
}

void Cmd::execShow(char **cmds, UserFactory *uf, ServerFactory *sf, User *user) {
  if (strcmp(cmds[0], "show") != 0) {
    std::cout << "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect." << std::endl;
    this->response = "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect.";
  }
  if (cmds[1] == NULL || cmds[2] != NULL || (strcmp(cmds[1], "users") != 0 && strcmp(cmds[1], "servers") != 0)) {
    std::cout << "Syntax error. The command must be 'show users' or 'show servers'." << std::endl;
    this->response = "Syntax error. The command must be 'show users' or 'show servers'.";
  }
  else if (strcmp(cmds[0], "show") == 0 && strcmp(cmds[1], "servers") == 0)
    sf->printFactory();
  else if (strcmp(cmds[0], "show") == 0 && strcmp(cmds[1], "users") == 0)
    uf->printFactory();
  else {
    std::cout << "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect." << std::endl;
    this->response = "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect.";
  }
}

void Cmd::execKick(char **cmds, UserFactory *uf, ServerFactory *sf, User *user) {
  if (cmds[1] == NULL || cmds[2] == NULL || cmds[3] != NULL) {
    std::cout << "Syntax error. The command must be 'kick [username] [ip server]'." << std::endl;
    this->response = "Syntax error. The command must be 'kick [username] [ip server]'.";
  }
  else if (strcmp(cmds[0], "kick") == 0 && user->isAdmin() == true) {
    if (uf->isInList(cmds[1]) == false) {
      std::cout << "Error: cannot find user " << cmds[1] << " in Spatch." << std::endl;
      this->response = "Error: cannot find user " + cmds[1] + " in Spatch.";
    }
    else if (sf->isInList(cmds[2]) == false) {
      std::cout << "Error: cannot find server " << cmds[2] << " in Spatch." << std::endl;
      this->response = "Error: cannot find server " + cmds[2] + " in Spatch."
    }
    else
      sf->getServerByIp(cmds[2])->disconnectUser(uf->getUserByName(cmds[1]));
  }
  else {
    std::cout << "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect." << std::endl;
    this->response = "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect.";
  }
}

void Cmd::execBan(char **cmds, UserFactory *uf, ServerFactory *sf, User *user) {
  if (cmds[1] == NULL || cmds[2] == NULL || cmds[3] != NULL) {
    std::cout << "Syntax error. The command must be 'ban [username] [ip server]'." << std::endl;
    this->response = "Syntax error. The command must be 'ban [username] [ip server]'.";
  }
  else if (strcmp(cmds[0], "ban") == 0 && user->isAdmin() == true) {
    if (uf->isInList(cmds[1]) == false) {
      std::cout << "Error: cannot find user " << cmds[1] << " in Spatch." << std::endl;
      this->response = "Error: cannot find user " + cmds[1] + " in Spatch.";
    }
    else if (sf->isInList(cmds[2]) == false) {
      std::cout << "Error: cannot find server " << cmds[2] << " in Spatch." << std::endl;
      this->response = "Error: cannot find server " + cmds[2] + " in Spatch."
    }
    else
      sf->getServerByIp(cmds[2])->banUser(uf->getUserByName(cmds[1]));
  }
  else {
    std::cout << "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect." << std::endl;
    this->response = "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect.";
  }
}

void Cmd::execUnban(char **cmds, UserFactory *uf, ServerFactory *sf, User *user) {
  if (cmds[1] == NULL || cmds[2] == NULL) {
    std::cout << "Syntax error. The command must be 'unban [username] [ip server]'." << std::endl;
    this->response = "Syntax error. The command must be 'unban [username] [ip server]'.";
  }
  else if (strcmp(cmds[0], "unban") == 0 && user->isAdmin() == true) {
    if (uf->isInList(cmds[1]) == false) {
      std::cout << "Error: cannot find user " << cmds[1] << " in Spatch." << std::endl;
      this->response = "Error: cannot find user " + cmds[1] + " in Spatch.";
    }
    else if (sf->isInList(cmds[2]) == false) {
      std::cout << "Error: cannot find server " << cmds[2] << " in Spatch." << std::endl;
      this->response = "Error: cannot find server " + cmds[2] + " in Spatch."
    }
    else
      sf->getServerByIp(cmds[2])->unbanUser(uf->getUserByName(cmds[1]));
  }
  else {
    std::cout << "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect." << std::endl;
    this->response = "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect.";
  }
}

void Cmd::execAllow(char **cmds, UserFactory *uf, ServerFactory *sf, User *user) {
  if (cmds[1] == NULL || cmds[2] == NULL || cmds[3] != NULL) {
    std::cout << "Syntax error. The command must be 'allow [username] [ip server]'." << std::endl;
    this->response = "Syntax error. The command must be 'allow [username] [ip server]'.";
  }
  else if (strcmp(cmds[0], "allow") == 0 && user->isAdmin() == true) {
    if (uf->isInList(cmds[1]) == false) {
      std::cout << "Error: cannot find user " << cmds[1] << " in Spatch." << std::endl;
      this->response = "Error: cannot find user " + cmds[1] + " in Spatch.";
    }
    else if (sf->isInList(cmds[2]) == false) {
      std::cout << "Error: cannot find server " << cmds[2] << " in Spatch." << std::endl;
      this->response = "Error: cannot find server " + cmds[2] + " in Spatch."
    }
    else
      sf->getServerByIp(cmds[2])->allowUser(uf->getUserByName(cmds[1]));
  }
  else {
    std::cout << "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect." << std::endl;
    this->response = "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect.";
  }
}

void Cmd::execUnallow(char **cmds, UserFactory *uf, ServerFactory *sf, User *user) {
  if (cmds[1] == NULL || cmds[2] == NULL || cmds[3] != NULL) {
    std::cout << "Syntax error. The command must be 'unallow [username] [ip server]'." << std::endl;
    this->response = "Syntax error. The command must be 'unallow [username] [ip server]'.";
  }
  else if (strcmp(cmds[0], "unallow") == 0 && user->isAdmin() == true) {
    if (uf->isInList(cmds[1]) == false) {
      std::cout << "Error: cannot find user " << cmds[1] << " in Spatch." << std::endl;
      this->response = "Error: cannot find user " + cmds[1] + " in Spatch.";
    }
    else if (sf->isInList(cmds[2]) == false) {
      std::cout << "Error: cannot find server " << cmds[2] << " in Spatch." << std::endl;
      this->response = "Error: cannot find server " + cmds[2] + " in Spatch."
    }
    else
      sf->getServerByIp(cmds[2])->unallowUser(uf->getUserByName(cmds[1]));
  }
  else {
    std::cout << "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect." << std::endl;
    this->response = "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect.";
  }
}

void Cmd::execPublic(char **cmds, UserFactory *uf, ServerFactory *sf, User *user) {
  if (cmds[1] == NULL || cmds[2] != NULL) {
    std::cout << "Syntax error. The command must be 'public [ip server]'." << std::endl;
    this->response = "Syntax error. The command must be 'public [ip server]'.";
  }
  else if (strcmp(cmds[0], "public") == 0 && user->isAdmin() == true) {
    if (sf->isInList(cmds[1]) == true)
      sf->getServerByIp(cmds[1])->setIsPublic(true);
    else {
      std::cout << "Error: cannot find server " << cmds[1] << " in Spatch." << std::endl;
      this->response = "Error: cannot find server " + cmds[2] + " in Spatch."
    }
  }
  else {
    std::cout << "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect." << std::endl;
    this->response = "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect.";
  }
}

void Cmd::execPrivate(char **cmds, UserFactory *uf, ServerFactory *sf, User *user) {
  if (cmds[1] == NULL || cmds[2] != NULL) {
    std::cout << "Syntax error. The command must be 'private [ip server]'." << std::endl;
    this->response = "Syntax error. The command must be 'private [ip server]'.";
  }
  else if (strcmp(cmds[0], "private") == 0 && user->isAdmin() == true) {
    if (sf->isInList(cmds[1]) == true)
      sf->getServerByIp(cmds[1])->setIsPublic(false);
    else {
      std::cout << "Error: cannot find server " << cmds[1] << " in Spatch." << std::endl;
      this->response = "Error: cannot find server " + cmds[2] + " in Spatch."
    }
  }
  else {
    std::cout << "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect." << std::endl;
    this->response = "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect.";
  }
}

void Cmd::execHelp(char **cmds, UserFactory *uf, ServerFactory *sf, User *user) {
  if (strcmp(cmds[0], "help") != 0 || cmds[1] != NULL) {
    std::cout << "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect." << std::endl;
    this->response = "Command not found. Type 'help' to see all available commands. Type 'exit' to disconnect.";
  }
  std::cout << "===========COMMANDS============" << std::endl;
  std::cout << "connect [ip server]" << std::endl << "show users" << std::endl << "show servers" << std::endl;
  if (user->isAdmin() == true) {
    std::cout << "kick [username] [ip server]" << std::endl
	      << "ban [username] [ip server]" << std::endl
	      << "unban [username] [ip server]" << std::endl
	      << "allow [username] [ip server]" << std::endl
	      << "unallow [username] [ip server]" << std::endl
	      << "public [ip server]" << std::endl
	      << "private [ip server]" << std::endl;
  }
  std::cout << "help" << std::endl << "exit" << std::endl;
  std::cout << "===============================" << std::endl;
  this->response = "===========COMMANDS============\n" +
    "connect [ip server]\n" +
    "show users\n" +
    "show servers\n" +
    "kick [username] [ip server]\n" +
    "ban [username] [ip server]\n" +
    "unban [username] [ip server]\n" +
    "allow [username] [ip server]\n" +
    "unallow [username] [ip server]\n" +
    "public [ip server]\n" +
    "private [ip server]\n" +
    "help\n" +
    "exit\n" +
    "===============================";
}

void Cmd::createCmds() {
  this->cmds[0] = "connect";
  this->cmds[1] = "show";
  this->cmds[2] = "kick";
  this->cmds[3] = "ban";
  this->cmds[4] = "unban";
  this->cmds[5] = "allow";
  this->cmds[6] = "unallow";
  this->cmds[7] = "public";
  this->cmds[8] = "private";
  this->cmds[9] = "help";
}

void Cmd::createFcts() {
  this->fcts[0] = &Cmd::execConnect;
  this->fcts[1] = &Cmd::execShow;
  this->fcts[2] = &Cmd::execKick;
  this->fcts[3] = &Cmd::execBan;
  this->fcts[4] = &Cmd::execUnban;
  this->fcts[5] = &Cmd::execAllow;
  this->fcts[6] = &Cmd::execUnallow;
  this->fcts[7] = &Cmd::execPublic;
  this->fcts[8] = &Cmd::execPrivate;
  this->fcts[9] = &Cmd::execHelp;
}

int Cmd::execCmd(UserFactory *uf, ServerFactory *sf, User *user) {
  char **cmds;
  char *tmp;
  int i = 0;

  if ((cmds = (char **)malloc(32 * sizeof(char *))) == NULL) {
    std::cerr << "Error: malloc failed" << std::endl;
    return 1;
  }
  tmp = strtok((char *)this->cmd.c_str(), " \t");
  while (tmp != NULL) {
    cmds[i] = tmp;
    tmp = strtok(NULL, " \t");
    ++i;
  }
  for (int k = 0; k < 10; ++k) {
    if (strcmp(this->cmds[k].c_str(), cmds[0]) == 0) {
      (this->*fcts[k])(cmds, uf, sf, user);
      return 0;
    }
  }
  std::cout << "Command not found." << std::endl;
  return 1;
}
