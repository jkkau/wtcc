#ifndef _WTCC_UTILS_H
#define _WTCC_UTILS_H

#include <stdio.h>
#include <stdlib.h>

#define MUST_NOT_NULL(ptr, promotion) if (ptr == NULL) {puts(promotion);exit(1);}


#endif