#ifndef CHECK_H
#define CHECK_H
#include <stdbool.h>

//MACROS

#define IS_INTEGER(var) _Generic((var),\
    int: true, \
    unsigned int: true, \
    long: true, \
    unsigned long: true, \
    long long: true, \
    unsigned long long: true, \
    default: false \
)

#define IS_CHAR(var) _Generic((var),\
    char: true, \
    default: false \
)

#define IS_FLOAT(var) _Generic((var), \
    float: true, \
    double: true, \
    default: false \
)
#endif