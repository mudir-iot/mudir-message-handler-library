
#ifndef   __MSGHANDLERDRVTEST_H__
#define   __MSGHANDLERDRVTEST_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

/*
 * Include all the header files for test fixtures, test cases and
 * associated libraries files here.
 */
#include "msghandlerdrv.test.h"

int addSuites();
int generateTempTraceFileName(char *buffer);
int confirmNoMemoryLeakage(const char *mTraceFName, const char *TestName);

#ifdef __cplusplus
}
#endif

#endif /* __MSGHANDLERDRVTEST_H__ */