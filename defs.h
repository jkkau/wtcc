#ifndef WTCC_DEFS_H
#define WTCC_DEFS_H

typedef struct _token {
    int token;
    int intvalue;
}token;

// Token type
enum {
    T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INT, T_EOF
};

#endif