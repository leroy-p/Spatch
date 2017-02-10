//
// Created by fab_a on 03/02/2017.
//

#ifndef SPATCH_SERVER_H
#define SPATCH_SERVER_H
#include <iostream>
#include <string>
class Server {

private:

    Server(std::string, int);

    std::string name;
    std::string port;

    void setName(std::string);
    void setPort(std::string);

public:
    std::string getName();
    std::string getPort();



};


#endif //SPATCH_SERVER_H
