#include <CUnit/CUnit.h>
#include <stdio.h>
#include <limits.h>
#include <mcheck.h>
#include "common.h"
#include "common_test.h"
#include "msghandlerdrv.h"
#include "msghandlerdrvtest.h"
#include "msghandlerdrv_pvt.h"
#include "msghandlerdrv.test.h"

int msghandlerdrv_test_init()
{
  CU_pSuite pSuite = NULL;
  
  MUDIR_TEST_ADD_SUITE(pSuite, "Driver Message Handler Base Operations", NULL, NULL);
  
  /* Add the tests to the suite */
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_lib_fullversionstring_get: NULL check",     mudir_drvmsg_lib_fullversionstring_get_test_nullchk);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_lib_fullversionstring_get: base operation", mudir_drvmsg_lib_fullversionstring_get_test_base);
  
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_lib_buildversion_get: base operation",      mudir_drvmsg_lib_buildversion_get_test_base);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_lib_buildnumber_get: base operation",       mudir_drvmsg_lib_buildnumber_get_test_base);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_lib_builddate_get: base operation",         mudir_drvmsg_lib_builddate_get_test_base);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_initialize: NULL check",                    mudir_drvmsg_initialize_test_nullchk);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_initialize: Version lower limit",           mudir_drvmsg_initialize_test_versionlowerlimit);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_initialize: Version upper limit",           mudir_drvmsg_initialize_test_versionupperlimit);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_initialize: Version unassigned",            mudir_drvmsg_initialize_test_versionunassigned);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_initialize: base operation",                mudir_drvmsg_initialize_test_base);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_free: NULL variable check",                 mudir_drvmsg_free_test_nullvarchk);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_free: NULL check",                          mudir_drvmsg_free_test_nullchk);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_free: Empty message check",                 mudir_drvmsg_free_test_empty_message);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_free: Empty message with error desc check", mudir_drvmsg_free_test_err_desc);

  return MUDIR_SUCCESS;
}

void mudir_drvmsg_lib_fullversionstring_get_test_nullchk()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_lib_fullversionstring_get(NULL), MUDIR_ERROR);
}

void mudir_drvmsg_lib_fullversionstring_get_test_base()
{
  char vString[MUDIR_MAX_STRING_LEN];
  char vStringTest[MUDIR_MAX_STRING_LEN];
  int  res;

  CU_ASSERT_EQUAL(mudir_drvmsg_lib_fullversionstring_get(vString), MUDIR_SUCCESS);

  res =  snprintf(vStringTest, 
                  MUDIR_MAX_STRING_LEN, 
                  "libmudirmsghandlerdrv Build Version: %s Build Date: %s", 
                  __BUILDNUMBER__, 
                  __BUILDDATE__);
  CU_ASSERT(res);
  CU_ASSERT((res > 0));
  CU_ASSERT((res <= MUDIR_MAX_STRING_LEN));
  CU_ASSERT_STRING_EQUAL(vString, vStringTest);
}

void mudir_drvmsg_lib_buildversion_get_test_base()
{
  if (mudir_drvmsg_lib_buildversion_get() == NULL)
  {
    CU_FAIL("mudir_drvmsg_lib_buildversion_get() returned NULL");
  }
  else
  {
    CU_ASSERT_STRING_EQUAL(mudir_drvmsg_lib_buildversion_get(), __BUILDVERSION__);
  }
}

void mudir_drvmsg_lib_buildnumber_get_test_base()
{
  if (mudir_drvmsg_lib_buildnumber_get() == NULL)
  {
    CU_FAIL("mudir_drvmsg_lib_buildnumber_get() returned NULL");
  }
  else
  {
    CU_ASSERT_STRING_EQUAL(mudir_drvmsg_lib_buildnumber_get(), __BUILDNUMBER__);
  }
}

void mudir_drvmsg_lib_builddate_get_test_base()
{
  if (mudir_drvmsg_lib_builddate_get() == NULL)
  {
    CU_FAIL("mudir_drvmsg_lib_builddate_get() returned NULL");
  }
  else
  {
    CU_ASSERT_STRING_EQUAL(mudir_drvmsg_lib_builddate_get(), __BUILDDATE__);
  }
}

void mudir_drvmsg_initialize_test_nullchk()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_initialize(NULL, MUDIR_DRIVERMSG_VERSION_UNASSIGNED), MUDIR_ERROR);
}

void mudir_drvmsg_initialize_test_versionlowerlimit()
{
  mudir_driver_message message;

  CU_ASSERT_EQUAL(mudir_drvmsg_initialize(&message, (MUDIR_DRIVERMSG_VERSION_UNASSIGNED - 1)), MUDIR_ERROR);
}

void mudir_drvmsg_initialize_test_versionupperlimit()
{
  mudir_driver_message message;

  CU_ASSERT_EQUAL(mudir_drvmsg_initialize(&message, (MUDIR_DRIVERMSG_VERSION_1_0 + 1)), MUDIR_ERROR);
}

void mudir_drvmsg_initialize_test_versionunassigned()
{
  mudir_driver_message message;

  CU_ASSERT_EQUAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_UNASSIGNED), MUDIR_ERROR);
}

void mudir_drvmsg_initialize_test_base()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();

  /* Normal Check */
  message = NULL;
  CU_ASSERT_EQUAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL(message);
  CU_ASSERT_EQUAL(message->message_type_, MUDIR_DRIVERMSG_TYPE_DRIVER_UNASSIGNED);
  CU_ASSERT_PTR_NULL(message->message);
  CU_ASSERT_PTR_NULL(message->error_desc_);
  CU_ASSERT_EQUAL(message->error_, MUDIR_DRIVERMSG_ERROR_NO_ERROR);

  /* Cleanup */
  free(message);
  muntrace();

  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_initialize_test"), MUDIR_SUCCESS);
}

void mudir_drvmsg_free_test_nullvarchk()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_free(NULL), MUDIR_ERROR);
}

void mudir_drvmsg_free_test_nullchk()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();

  message = NULL;
  CU_ASSERT_EQUAL(mudir_drvmsg_free(&message), MUDIR_ERROR);

  /* Confirm there were no memory checks in the entire testing */
  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_free_test_nullchk"), MUDIR_SUCCESS);
}

void mudir_drvmsg_free_test_empty_message()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL(message);

  /* Confirm there were no memory checks in the entire testing */
  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_free_test_empty_message"), MUDIR_SUCCESS);
}

void mudir_drvmsg_free_test_err_desc()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  /* Check with error message by manually allocating memory to error message */
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->error_desc_ = (char *) malloc(11);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message->error_desc_);
  strncpy(message->error_desc_, "Hello Test", 11);
  CU_ASSERT_EQUAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL(message);

  /* Confirm there were no memory checks in the entire testing */
  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_free_test_err_desc"), MUDIR_SUCCESS);
}
