#include "../includes/Spatch.hpp"

int main(int argc, char **av) {
  if (av[1] == NULL)
    Spatch *s = new Spatch();
  else
    Spatch *s = new Spatch(atoi(av[1]));
  return 0;
}
