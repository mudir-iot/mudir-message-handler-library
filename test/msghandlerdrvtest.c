#include <CUnit/Automated.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <libgen.h>
#include "msghandlerdrvtest.h"
#include "msghandlerdrv.test.h"
#include "msghandlerdrvgs.test.h"
#include "msghandlerdrvreg.test.h"
#include "msghandlerdrvack.test.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

struct allocations
{
  char          flocation[PATH_MAX];
  unsigned long addr;
  unsigned long size;
  unsigned int  count;
};

/* Removed 14 characters for file name */
static char path[PATH_MAX - 14];
static char filename[PATH_MAX];
static int counter = 0;

int addSuites()
{
  /* Add individual test suites' addition methods here. */
  if (MUDIR_ERROR == msghandlerdrv_test_init()) { return MUDIR_ERROR; }
  if (MUDIR_ERROR == msghandlerdrvgs_test_init()) { return MUDIR_ERROR; }
  if (MUDIR_ERROR == msghandlerdrvreg_test_init()) { return MUDIR_ERROR; }
  if (MUDIR_ERROR == msghandlerdrvack_test_init()) { return MUDIR_ERROR; }

  return MUDIR_SUCCESS;
}

int main() 
{
  char exePath[PATH_MAX];
  char *pathc;
  char *basec;

  readlink("/proc/self/exe", exePath, PATH_MAX);
  pathc = strndup(exePath, PATH_MAX);
  basec = strndup(exePath, PATH_MAX);
  
  strncpy(path, dirname(pathc), (PATH_MAX - 14));
  strncpy(filename, basename(basec), PATH_MAX);
  free(pathc);
  free(basec);

  printf("Starting unit tests...\n");

  // Initialize the CUnit test registry
  if (CUE_SUCCESS != CU_initialize_registry())
  {
    printf("FATAL ERROR: Registry Initialization failed: %s\nExiting.\n", CU_get_error_msg());
    return MUDIR_ERROR;
  }

  CU_set_output_filename("libmudirmsghandlerdrvTest");
  
  if (MUDIR_ERROR == addSuites()) 
  {
    printf("FATAL ERROR: Suite addition failed\nExiting.\n");
    CU_cleanup_registry();
    return MUDIR_ERROR;
  }

  //List tests to file
  if (CUE_SUCCESS != CU_list_tests_to_file())
  {
    printf("FATAL ERROR: Unable to list tests! Exiting.\n");
    CU_cleanup_registry();
    return MUDIR_ERROR;
  }

  // Run the tests and show the run summary
  CU_automated_run_tests();

  int failedTests = (int) CU_get_number_of_tests_failed();
  printf("No. of failed tests: %d\n", failedTests);

  CU_cleanup_registry();
  printf("Unit test completed without CUnit errors.\n");
  
  return failedTests;
}

int generateTempTraceFileName(char *buffer)
{
  snprintf(buffer, PATH_MAX, "%s/mtrc%04d.trc", path, counter++);
  setenv("MALLOC_TRACE", buffer, 1);
  return MUDIR_SUCCESS;
}

int confirmNoMemoryLeakage(const char *mTraceFName, const char *TestName)
{
  FILE *fd;
  char line[100];
  struct allocations alloc[100];

  char lType;
  char mOperType;
  char flocation[PATH_MAX];
  unsigned long location;
  unsigned long size;
  int nCnt, i;

  fd = fopen(mTraceFName, "r");
  if (fd == NULL)
  {
    printf(ANSI_COLOR_RED "Unable to open trace file: %s\n" ANSI_COLOR_RESET, mTraceFName);
    return MUDIR_ERROR;
  }

  nCnt = 0;
  while (!feof(fd))
  {
    fgets(line, 100, fd);
    sscanf(line, "%c %s %c %lx %lx", &lType, flocation, &mOperType, &location, &size);
    if ('@' == lType)
    {
      if (strncmp("testoutput/mudirmsghandlerdrv.test", flocation, 33) == 0)
      {
        /* Search */
        for (i = 0; i < nCnt; i++)
        {
          if (alloc[i].addr == location)
          {
            /* Found! */
            if ('+' == mOperType || '>' == mOperType)
              alloc[i].count++;
            else
              alloc[i].count--;
            
            break;
          }
        }

        if (i >= nCnt)
        {
          /* Not found... add record */
          alloc[nCnt].addr = location;
          alloc[nCnt].size = size;
          strncpy(alloc[nCnt].flocation, flocation, PATH_MAX);
          if ('+' == mOperType || '>' == mOperType)
            alloc[nCnt].count = 1;
          else
            alloc[nCnt].count = -1;
          
          nCnt++;
        }
      }
    }
  }

  fclose(fd);

  /* Loop through records and find mismatch */
  lType = 't';    /* Repurpose as flag */
  for (i = 0; i < nCnt; i++)
  {
    if (alloc[i].count != 0 && strstr(alloc[i].flocation, filename) != NULL)
    {
      printf(ANSI_COLOR_RED "%s:" ANSI_COLOR_RESET " Leakage noted at address: %lx Size: %lu Count:%u\n", 
              TestName, alloc[i].addr, alloc[i].size, alloc[i].count);
      lType = 'f';
    }
  }

  if ('f' == lType)
    return MUDIR_ERROR;

  printf(ANSI_COLOR_GREEN "%s:" ANSI_COLOR_RESET " No leakage found.\n", TestName);
  return MUDIR_SUCCESS;
}
