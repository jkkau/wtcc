#include "scan.h"
#include "defs.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

char *tokenStr[] = {"T_PLUS", "T_MINUS", "T_STAR", "T_SLASH", "T_INT", "T_EOF"};

FILE *g_file = NULL;
int putback = 0;

// get next non whilespace character
static int next() {
    if (putback && putback != ' ') {
        int c = putback;
        putback = 0;
        return c;
    }

    int c = fgetc(g_file);
    while (c == ' ') {
        c = fgetc(g_file);
    }
    return c;
}


static int parseint(int firstc) {
    int value = (firstc-0x30);
    while (true) {
        int c = fgetc(g_file);
        if (!isdigit(c)) {
            putback = c;
            break;
        }
        value = (value*10)+(c-0x30);
    }
    return value;
}

static bool scan(token *t) {
    int c = next();
    if (c == EOF) {
        t->token = T_EOF;
        return false;
    }

    switch (c)
    {
    case '+':
        t->token = T_PLUS;
        break;
    case '-':
        t->token = T_MINUS;
        break;
    case '*':
        t->token = T_STAR;
        break;
    case '/':
        t->token = T_SLASH;
        break;
    default:
        if (isdigit(c)) {
            t->token = T_INT;
            t->intvalue = parseint(c);
        }
    }
    return true;
}


void scanfile(FILE *file) {
    g_file = file;
    token t;

    while (scan(&t)) {
        printf("token: %s", tokenStr[t.token]);
        if (t.token == T_INT) {
            printf(", int value: %d", t.intvalue);
        }
        printf("\n");
    }
}

