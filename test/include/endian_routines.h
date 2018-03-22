
#ifndef _ENDIAN_ROUTINES_H
#define _ENDIAN_ROUTINES_H

#define ntohll(x) (((_int64)(ntohl((int)((x << 32) >> 32))) << 32) | (unsigned int)ntohl(((int)(x >> 32))))
#define htonll(x) ntohll(x)

#endif //_ENDIAN_ROUTINES_H
