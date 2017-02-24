#include "../includes/Spatch.hpp"

Spatch::Spatch(int port) {
  this->port = port;
  this->serversList = new ServerFactory();
  this->usersList = new UserFactory();
  this->cmd = new Cmd();
  std::cout << "Welcome to Spatch." << std::endl;
  this->execSpatch();
}

Spatch::Spatch() {
  this->port = 4577;
  this->serversList = new ServerFactory();
  this->usersList = new UserFactory();
  this->cmd = new Cmd();
  std::cout << "Welcome to Spatch." << std::endl;
  this->execSpatch();
}

Spatch::~Spatch() {
  std::cout << "You have left Spatch." << std::endl;
}

void Spatch::sshStuff(){
	ssh_message message;
	int 				auth=0;
	char 				buf[2048];
	int 				i;
	int 				sftp=0;
	int 				r;
	ssh_channel chan=0;
  User *u;

	do {
			message=ssh_message_get(this->session);
			if(!message)
					break;
			switch(ssh_message_type(message)){
					case SSH_REQUEST_AUTH:
							switch(ssh_message_subtype(message)){
									case SSH_AUTH_METHOD_PASSWORD:
											printf("User %s wants to auth with pass %s\n",
														 ssh_message_auth_user(message),
														 ssh_message_auth_password(message));
														 if(strncmp(ssh_message_auth_password(message), "test", strlen("test")) == 0) {
																//if(isFirstConnection(ssh_message_auth_user(message)) ||strncmp(ssh_message_auth_password(message), getUserPassword(ssh_message_auth_user(message)), strlen("test")) == 0) {
                                u = new User(ssh_message_auth_user(message), true);
                                std::string response = "Welcome to spatch.";
                                ssh_channel_write(chan, response.c_str(), response.length());
                                this->connectUser(u);
                                auth=1;
                                ssh_message_auth_reply_success(message,0);
																			 onceConnected(u);
																			 break;
																	 }
											// not authenticated, send default message
									case SSH_AUTH_METHOD_NONE:
									default:
											ssh_message_auth_set_methods(message,SSH_AUTH_METHOD_PASSWORD);
											ssh_message_reply_default(message);
											break;
							}
							break;
					default:
							ssh_message_reply_default(message);
			}
			ssh_message_free(message);
	} while (!auth);
	if(!auth){
			printf("auth error: %s\n",ssh_get_error(this->session));
	}
}

void Spatch::onceConnected(User *u){
	ssh_message message;
	int 				auth=0;
	char 				buf[2048];
	int 				i;
	int 				sftp=0;
	int 				r;
	ssh_channel chan=0;

	do {
			message=ssh_message_get(this->session);
			if(message){
					switch(ssh_message_type(message)){
							case SSH_REQUEST_CHANNEL_OPEN:
									if(ssh_message_subtype(message)==SSH_CHANNEL_SESSION){
											chan=ssh_message_channel_request_open_reply_accept(message);
											break;
									}
							default:
							ssh_message_reply_default(message);
					}
					ssh_message_free(message);
			}
	} while(message && !chan);
	if(!chan){
			printf("error : %s\n",ssh_get_error(this->session));
			ssh_finalize();
	//		return 1;
	}
	do {
			message=ssh_message_get(this->session);
			if(message && ssh_message_type(message)==SSH_REQUEST_CHANNEL &&
				 ssh_message_subtype(message)==SSH_CHANNEL_REQUEST_SHELL){
							sftp=1;
							ssh_message_channel_request_reply_success(message);
							break;
				 }
			if(!sftp){
					ssh_message_reply_default(message);
			}
			ssh_message_free(message);
	} while (message && !sftp);
	if(!sftp){
			printf("error : %s\n",ssh_get_error(this->session));
	}
	printf("it works !\n");
	do{
			i=ssh_channel_read(chan,buf, 2048, 0);
		 if(i>0) {
					if (write(1,buf,i) < 0) {
							printf("error writing to buffer\n");
					} else {
            char *cmd = parse_buf(buf);
            std::cout<<cmd<<std::endl;
            this->getCmd()->setCmd(cmd);
            this->getCmd()->execCmd(this->getUsersList(), this->getServersList(), u);
            std::string response = this->getCmd()->getResponse();
            ssh_channel_write(chan, response.c_str(), response.length());
            free(cmd);
          }
			}
	} while (i>0);

}

char *Spatch::parse_buf(char *buf) {
 char *res;
 int i;

 if ((res = (char*)malloc(strlen(buf) * sizeof(char)))== NULL) {
     std::cerr << "Error: malloc failed." << std::endl;
     return NULL;
 }
 i = 0;
 while (buf[i] && buf[i] != '\n') {
   res[i] = buf[i];
   i++;
 }
 res[i] = '\0';
 return res;
}

int Spatch::initSsh(){
    ssh_bind sshbind;
    int verbosity = SSH_LOG_PROTOCOL;
		int 				r;

    sshbind = ssh_bind_new();
    this->session = ssh_new();

    ssh_bind_options_set(sshbind, SSH_BIND_OPTIONS_DSAKEY, KEYS_FOLDER "ssh_host_dsa_key");
    ssh_bind_options_set(sshbind, SSH_BIND_OPTIONS_RSAKEY, KEYS_FOLDER "ssh_host_rsa_key");

    ssh_bind_options_set(sshbind, SSH_BIND_OPTIONS_BINDPORT, &(this->port));
    ssh_bind_options_set(sshbind, SSH_BIND_OPTIONS_LOG_VERBOSITY, &verbosity);
   // ssh_bind_options_set(sshbind, SSH_OPTIONS_HOST, "0.0.0.0");
    if(ssh_bind_listen(sshbind)<0){
        printf("Error listening to socket: %s\n",ssh_get_error(sshbind));
        return 1;
    }
    r=ssh_bind_accept(sshbind,this->session);
    if(r==SSH_ERROR){
      printf("error accepting a connection : %s\n",ssh_get_error(sshbind));
      return 1;
    }
    if (ssh_handle_key_exchange(this->session)) {
        printf("ssh_handle_key_exchange: %s\n", ssh_get_error(this->session));
        return 1;
    }
		sshStuff();
    ssh_disconnect(this->session);
    ssh_bind_free(sshbind);
    ssh_finalize();
    return 0;
}


int Spatch::execSpatch() {
  initSsh();
/*  Server *s1 = new Server("111.11.11.1");
  Server *s2 = new Server("222.22.22.2");
  Server *s3 = new Server("333.33.33.3");
  User *u1 = new User("toto");
  User *u2 = new User("titi");
  User *u3 = new User("tutu");
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
    u = new User(name, true);
    check = this->connectUser(u);
    if (check == 1)
      delete u;
  }
  std::cout << "Welcome, " << name << ". You are now connected to Spatch. Type 'help' to get all the available commands. Type 'exit' to disconnect." << std::endl;
  check = 1;
  while (1) {
    std::cin.getline(buf, sizeof(buf));
    if (strcmp(buf, "exit") == 0)
      return 0;
    else if (strcmp(buf, "") != 0 && strcmp(buf, "\n") != 0) {
      this->getCmd()->setCmd(buf);
      this->getCmd()->execCmd(this->getUsersList(), this->getServersList(), u);
    }
  }
  return 1;*/
  return 0;
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
