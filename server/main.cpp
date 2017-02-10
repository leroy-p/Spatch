//
// Created by fab_a on 03/02/2017.
//

#include "Server.h"
#include <list>

int handleFlags(int pString, char **pString1);

// Usage : ./server -n [NbServs]
int main(int argc, char **argv) {
    // Here we handle different flags
    // we create a file that would have the summary of all server(s) config

    int nbServs = handleFlags(argc, argv);

    std::list<Server> servers;

    return 0;
}

int handleFlags(int count, char **values) {

    int res = count;


    return 0;
}

