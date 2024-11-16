#include <stdio.h>
#include "utils.h"
#include "scan.h"

int main(int argc, char*argv[]) {
    if (argc < 2) {
        printf("usage: ./cc inputfile\n");
        return 0;
    }
    FILE *file = fopen(argv[1], "r");
    MUST_NOT_NULL(file, "open input file failed");   

    scanfile(file);
    return 0;
}