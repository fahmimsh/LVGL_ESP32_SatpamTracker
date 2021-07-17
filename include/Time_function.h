#ifndef __TIME_FUNCTION_H__
#define __TIME_FUNCTION_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>

const char* getTime();
bool initTime();
void getTime_tm(struct tm* var);

#ifdef __cplusplus
}

#endif
#endif