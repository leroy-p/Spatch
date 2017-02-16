#include "Cmd.hpp"

int main() {
  char buf[4096];
  std::cin.getline(buf, sizeof(buf));
  Cmd *cmd = new Cmd(buf);
  return cmd->execCmd();
}
