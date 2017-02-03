//
// Created by fab_a on 03/02/2017.
//

#ifndef SPATCH_SERVER_H
#define SPATCH_SERVER_H
#include <iostream>
#include <string>
class Server {

private:
    Server();

    std::string name;
    std::string port;
    std::string ip;
    void setName(std::string);
    void setPort(std::string);
    void setIp(std::string);
public:
    std::string getName();
    std::string getPort();
    std::string getIp();



};


#endif //SPATCH_SERVER_H
