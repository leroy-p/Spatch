//
// Created by BEDIDI Fawzi on 17/02/2017.
//

#ifndef SPATCH_LIBSSH_H
#define SPATCH_LIBSSH_H

#if __x86_64__

#include "libssh_OSX/libssh.h"

#else
#include "./libssh/include/libssh.h"
#endif
#endif //SPATCH_LIBSSH_H
