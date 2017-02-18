#ifndef SERVER_HPP
#define SERVER_HPP

#include "UserFactory.hpp"

class Server {
private:
  std::string ip;
  bool isPublic;
  UserFactory *connectedUsers;
  UserFactory *accessList;
  UserFactory *banList;

public:
  Server(std::string ip);
  ~Server();
  std::string getIp() const;
  bool getIsPublic() const;
  void setIsPublic(bool);
  UserFactory *getConnectedUsers() const;
  UserFactory *getAccessList() const;
  UserFactory *getBanList() const;
  int connectUser(User *);
  int disconnectUser(User *);
  int allowUser(User *);
  int unallowUser(User *);
  int banUser(User *);
  int unbanUser(User *);
  bool isInAccessList(User *);
  bool isInBanList(User *);
};

#endif
