#include "Cmd.hpp"
#include "User.hpp"

int main() {
  char buf[4096];
  std::cin.getline(buf, sizeof(buf));
  Cmd *cmd = new Cmd(buf);
  return cmd->execCmd();
}

// int main() {
//   User *user = new User("127.0.0.2", "toto");
//   if (user->isAutorized("134.22.55.6") == true)
//     std::cout << "Vous avez acces au serveur 134.22.55.6" << std::endl;
//   else
//     std::cout << "Vous n'avez pas acces au serveur 134.22.55.6" << std::endl;

//   if (user->isAutorized("123.23.12.1")== true)
//     std::cout << "Vous avez acces au serveur 123.23.12.1" << std::endl;
//   else
//     std::cout << "Vous n'avez pas acces au serveur 123.23.12.1" << std::endl;
//   return 0;
// }
