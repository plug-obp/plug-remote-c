//
// Created by fourniem on 16/10/19.
//

#ifndef PLUG_REMOTE_C_MURMUR3_H
#define PLUG_REMOTE_C_MURMUR3_H

#include "string.h"
#define uint32_t unsigned int
#define uint8_t char

uint32_t murmur3_32(const uint8_t* key, size_t len, uint32_t seed);


#endif //PLUG_REMOTE_C_MURMUR3_H
