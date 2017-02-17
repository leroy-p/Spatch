//
// Created by BEDIDI Fawzi on 03/02/2017.
//

#include "spatch.h"

int init_spatch() {
    ssh_session my_ssh_session;
    int verbosity = SSH_LOG_PROTOCOL;
    int port = 22;
    int rc;

    if (my_ssh_session == NULL)
        exit(-1);

    my_ssh_session = ssh_new();
    ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, "localhost");
    ssh_options_set(my_ssh_session, SSH_OPTIONS_LOG_VERBOSITY, &verbosity);
    ssh_options_set(my_ssh_session, SSH_OPTIONS_PORT, &port);
    rc = ssh_connect(my_ssh_session);
    if (rc != SSH_OK) {
        fprintf(stderr, "Error connecting to localhost: %s\n",
                ssh_get_error(my_ssh_session));
        exit(-1);
    }
    ssh_disconnect(my_ssh_session);
    ssh_free(my_ssh_session);
    return 0;
}
