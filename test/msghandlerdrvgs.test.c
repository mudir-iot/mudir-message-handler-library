#include <CUnit/CUnit.h>
#include <stdio.h>
#include <limits.h>
#include <mcheck.h>
#include "common.h"
#include "common_test.h"
#include "msghandlerdrv.h"
#include "msghandlerdrvtest.h"
#include "msghandlerdrv_pvt.h"
#include "msghandlerdrvgs.test.h"

int msghandlerdrvgs_test_init()
{
  CU_pSuite pSuite = NULL;
  
  MUDIR_TEST_ADD_SUITE(pSuite, "Driver Message Handler Base Structure Getters and Setters", NULL, NULL);
  
  /* Add the tests to the suite */
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_version_get: NULL check",                 mudir_drvmsg_version_get_test_nullcheck);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_version_get: Normal operation",           mudir_drvmsg_version_get_test_normal);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errorcode_set: NULL check",               mudir_drvmsg_errorcode_set_test_nullcheck);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errorcode_set: Error code lower limit",   mudir_drvmsg_errorcode_set_test_lowerlimit);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errorcode_set: Error code upper limit",   mudir_drvmsg_errorcode_set_test_upperlimit);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errorcode_set: Normal Operation",         mudir_drvmsg_errorcode_set_test_normal);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errorcode_get: NULL check",               mudir_drvmsg_errorcode_get_test_nullcheck);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errorcode_get: Normal Operation",         mudir_drvmsg_errorcode_get_test_normal);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errordesc_set: NULL message check",       mudir_drvmsg_errordesc_set_test_nullcheck);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errordesc_set: NULL error desc. check",   mudir_drvmsg_errordesc_set_test_nullmessagecheck);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errordesc_set: Standard error check",     mudir_drvmsg_errordesc_set_test_standarderrorcheck);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errordesc_set: Normal operation",         mudir_drvmsg_errordesc_set_test_normal);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errordesc_set: Long error desc. check",   mudir_drvmsg_errordesc_set_test_longerrdesccheck);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errordesc_get: NULL check",               mudir_drvmsg_errordesc_get_test_nullcheck);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errordesc_get: Error code lower limit",   mudir_drvmsg_errordesc_get_test_lowerlimitcheck);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errordesc_get: Error code upper limit",   mudir_drvmsg_errordesc_get_test_upperlimitcheck);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errordesc_get: No error check",           mudir_drvmsg_errordesc_get_test_normal_noerror);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errordesc_get: No message check",         mudir_drvmsg_errordesc_get_test_normal_nomessage);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errordesc_get: Invalid data check",       mudir_drvmsg_errordesc_get_test_normal_invaliddata);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errordesc_get: Device unavailable check", mudir_drvmsg_errordesc_get_test_normal_devunavail);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errordesc_get: Device error check",       mudir_drvmsg_errordesc_get_test_normal_deverror);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errordesc_get: Other error with desc.",   mudir_drvmsg_errordesc_get_test_normal_others_emptydesc);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_errordesc_get: Other error without desc", mudir_drvmsg_errordesc_get_test_normal_others);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_messagetype_set: NULL check",             mudir_drvmsg_messagetype_set_test_nullcheck);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_messagetype_set: Mess. Type lower limit", mudir_drvmsg_messagetype_set_test_lowerlimitcheck);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_messagetype_set: Unassigned check",       mudir_drvmsg_messagetype_set_test_unassignedcheck);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_messagetype_set: Mess. Type upper limit", mudir_drvmsg_messagetype_set_test_upperlimitcheck);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_messagetype_set: Driver Register set",    mudir_drvmsg_messagetype_set_test_drvregister);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_messagetype_set: Driver Ack. set",        mudir_drvmsg_messagetype_set_test_drvregack);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_messagetype_set: Device Query set",       mudir_drvmsg_messagetype_set_test_devqry);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_messagetype_set: Device Command set",     mudir_drvmsg_messagetype_set_test_devcom);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_messagetype_set: Device Reply set",       mudir_drvmsg_messagetype_set_test_devreply);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_messagetype_get: NULL check",             mudir_drvmsg_messagetype_get_test_nullcheck);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_messagetype_get: Empty message check",    mudir_drvmsg_messagetype_get_test_emptymessagecheck);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_messagetype_get: Normal check",           mudir_drvmsg_messagetype_get_test_normal);

  return MUDIR_SUCCESS;
}

void mudir_drvmsg_version_get_test_nullcheck()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_version_get(NULL), MUDIR_DRIVERMSG_VERSION_UNASSIGNED);
}

void mudir_drvmsg_version_get_test_normal()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_version_get(message), MUDIR_DRIVERMSG_VERSION_1_0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_errorcode_set_test_normal"), MUDIR_SUCCESS);
}

void mudir_drvmsg_errorcode_set_test_nullcheck()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_errorcode_set(NULL, MUDIR_DRIVERMSG_ERROR_NO_ERROR), MUDIR_ERROR);
}

void mudir_drvmsg_errorcode_set_test_lowerlimit()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_errorcode_set(message, (MUDIR_DRIVERMSG_ERROR_NO_ERROR - 1)), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_errorcode_set_test_lowerlimit"), MUDIR_SUCCESS);
}

void mudir_drvmsg_errorcode_set_test_upperlimit()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_errorcode_set(message, (MUDIR_DRIVERMSG_ERROR_OTHER + 1)), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_errorcode_set_test_upperlimit"), MUDIR_SUCCESS);
}

void mudir_drvmsg_errorcode_set_test_normal()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_errorcode_set(message, MUDIR_DRIVERMSG_ERROR_INVALID_DATA), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(message->error_, MUDIR_DRIVERMSG_ERROR_INVALID_DATA);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_errorcode_set_test_normal"), MUDIR_SUCCESS);
}

void mudir_drvmsg_errorcode_get_test_nullcheck()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_errorcode_get(NULL), MUDIR_DRIVERMSG_ERROR_NO_MESSAGE);
}

void mudir_drvmsg_errorcode_get_test_normal()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_errorcode_set(message, (MUDIR_DRIVERMSG_ERROR_INVALID_DATA)), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_errorcode_get(message), MUDIR_DRIVERMSG_ERROR_INVALID_DATA);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_errorcode_get_test_normal"), MUDIR_SUCCESS);
}

void mudir_drvmsg_errordesc_set_test_nullcheck()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_errordesc_set(NULL, NULL), MUDIR_ERROR);
}

void mudir_drvmsg_errordesc_set_test_nullmessagecheck()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_errordesc_set(message, NULL), MUDIR_ERROR);
  CU_ASSERT_PTR_NULL(message->error_desc_);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_errordesc_set_test_nullmessagecheck"), MUDIR_SUCCESS);
}

void mudir_drvmsg_errordesc_set_test_standarderrorcheck()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char errMsg[] = "This is a test error message";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_errorcode_set(message, MUDIR_DRIVERMSG_ERROR_INVALID_DATA), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_errordesc_set(message, errMsg), MUDIR_ERROR);
  CU_ASSERT_PTR_NULL(message->error_desc_);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_errordesc_set_test_standarderrorcheck"), MUDIR_SUCCESS);
}

void mudir_drvmsg_errordesc_set_test_normal()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char errMsg[] = "This is a test error message";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_errorcode_set(message, MUDIR_DRIVERMSG_ERROR_OTHER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_errordesc_set(message, errMsg), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL(message->error_desc_);
  CU_ASSERT_EQUAL(strncmp(message->error_desc_, errMsg, MUDIR_MAX_STRING_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_errordesc_set_test_normal"), MUDIR_SUCCESS);
}

void mudir_drvmsg_errordesc_set_test_longerrdesccheck()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char errMsg[] = "12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
  const char errTruncMsg[] = "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_errorcode_set(message, MUDIR_DRIVERMSG_ERROR_OTHER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_errordesc_set(message, errMsg), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL(message->error_desc_);
  CU_ASSERT_EQUAL(strncmp(message->error_desc_, errTruncMsg, MUDIR_MAX_STRING_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_errordesc_set_test_longerrdesccheck"), MUDIR_SUCCESS);
}

void mudir_drvmsg_errordesc_get_test_nullcheck()
{
  CU_ASSERT_PTR_NULL(mudir_drvmsg_errordesc_get(NULL));
}

void mudir_drvmsg_errordesc_get_test_lowerlimitcheck()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->error_ = (MUDIR_DRIVERMSG_ERROR_NO_ERROR - 1);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_errordesc_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_errordesc_get_test_lowerlimitcheck"), MUDIR_SUCCESS);
}

void mudir_drvmsg_errordesc_get_test_upperlimitcheck()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->error_ = (MUDIR_DRIVERMSG_ERROR_OTHER + 1);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_errordesc_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_errordesc_get_test_upperlimitcheck"), MUDIR_SUCCESS);
}

void mudir_drvmsg_errordesc_get_test_normal_noerror()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char errMsg[] = "No errors";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_errorcode_set(message, MUDIR_DRIVERMSG_ERROR_NO_ERROR), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL(mudir_drvmsg_errordesc_get(message));
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_errordesc_get(message), errMsg, MUDIR_MAX_STRING_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_errordesc_get_test_normal_noerror"), MUDIR_SUCCESS);
}

void mudir_drvmsg_errordesc_get_test_normal_nomessage()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char errMsg[] = "No message object";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_errorcode_set(message, MUDIR_DRIVERMSG_ERROR_NO_MESSAGE), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL(mudir_drvmsg_errordesc_get(message));
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_errordesc_get(message), errMsg, MUDIR_MAX_STRING_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_errordesc_get_test_normal_nomessage"), MUDIR_SUCCESS);
}

void mudir_drvmsg_errordesc_get_test_normal_invaliddata()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char errMsg[] = "Invalid data has been sent/received";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_errorcode_set(message, MUDIR_DRIVERMSG_ERROR_INVALID_DATA), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL(mudir_drvmsg_errordesc_get(message));
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_errordesc_get(message), errMsg, MUDIR_MAX_STRING_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_errordesc_get_test_normal_invaliddata"), MUDIR_SUCCESS);
}

void mudir_drvmsg_errordesc_get_test_normal_devunavail()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char errMsg[] = "The device is unavailable";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_errorcode_set(message, MUDIR_DRIVERMSG_ERROR_DEVICE_UNAVAILABLE), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL(mudir_drvmsg_errordesc_get(message));
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_errordesc_get(message), errMsg, MUDIR_MAX_STRING_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_errordesc_get_test_normal_devunavail"), MUDIR_SUCCESS);
}

void mudir_drvmsg_errordesc_get_test_normal_deverror()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char errMsg[] = "The device has returned an error";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_errorcode_set(message, MUDIR_DRIVERMSG_ERROR_DEVICE_ERROR), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL(mudir_drvmsg_errordesc_get(message));
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_errordesc_get(message), errMsg, MUDIR_MAX_STRING_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_errordesc_get_test_normal_deverror"), MUDIR_SUCCESS);
}

void mudir_drvmsg_errordesc_get_test_normal_others_emptydesc()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char errMsg[] = "An unknown error";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_errorcode_set(message, MUDIR_DRIVERMSG_ERROR_OTHER), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL(mudir_drvmsg_errordesc_get(message));
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_errordesc_get(message), errMsg, MUDIR_MAX_STRING_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_errordesc_get_test_normal_others_emptydesc"), MUDIR_SUCCESS);
}

void mudir_drvmsg_errordesc_get_test_normal_others()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char errMsg[] = "A test error";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_errorcode_set(message, MUDIR_DRIVERMSG_ERROR_OTHER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_errordesc_set(message, errMsg), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL(mudir_drvmsg_errordesc_get(message));
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_errordesc_get(message), errMsg, MUDIR_MAX_STRING_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_errordesc_get_test_normal_others"), MUDIR_SUCCESS);
}

void mudir_drvmsg_messagetype_set_test_nullcheck()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_messagetype_set(NULL, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK), MUDIR_ERROR);
}

void mudir_drvmsg_messagetype_set_test_lowerlimitcheck()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_messagetype_set(message, (MUDIR_DRIVERMSG_TYPE_DRIVER_UNASSIGNED - 1)), MUDIR_ERROR);
  CU_ASSERT_EQUAL(message->message_type_, MUDIR_DRIVERMSG_TYPE_DRIVER_UNASSIGNED);
  CU_ASSERT_PTR_NULL(message->message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_messagetype_set_test_lowerlimitcheck"), MUDIR_SUCCESS);
}

void mudir_drvmsg_messagetype_set_test_unassignedcheck()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_UNASSIGNED), MUDIR_ERROR);
  CU_ASSERT_EQUAL(message->message_type_, MUDIR_DRIVERMSG_TYPE_DRIVER_UNASSIGNED);
  CU_ASSERT_PTR_NULL(message->message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_messagetype_set_test_unassignedcheck"), MUDIR_SUCCESS);
}

void mudir_drvmsg_messagetype_set_test_upperlimitcheck()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_messagetype_set(message, (MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY + 1)), MUDIR_ERROR);
  CU_ASSERT_EQUAL(message->message_type_, MUDIR_DRIVERMSG_TYPE_DRIVER_UNASSIGNED);
  CU_ASSERT_PTR_NULL(message->message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_messagetype_set_test_upperlimitcheck"), MUDIR_SUCCESS);
}

void mudir_drvmsg_messagetype_set_test_drvregister()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(message->message_type_, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER);
  CU_ASSERT_EQUAL(strnlen(((struct mudir_driver_message_reg *) message->message)->name_, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL(strnlen(((struct mudir_driver_message_reg *) message->message)->snap_name_, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL(strnlen(((struct mudir_driver_message_reg *) message->message)->snap_version_, MUDIR_MAX_VER_LEN), 0);
  CU_ASSERT_EQUAL(((struct mudir_driver_message_reg *) message->message)->num_capabilities_, 0);
  CU_ASSERT_PTR_NULL(((struct mudir_driver_message_reg *) message->message)->capabilities_);
  CU_ASSERT_PTR_NOT_NULL(message->message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_messagetype_set_test_drvregister"), MUDIR_SUCCESS);
}

void mudir_drvmsg_messagetype_set_test_drvregack()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(message->message_type_, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK);
  CU_ASSERT_EQUAL(strnlen(((struct mudir_driver_message_ack *) message->message)->name_, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL(strnlen(((struct mudir_driver_message_ack *) message->message)->inbound_, MUDIR_MAX_STRING_LEN), 0);
  CU_ASSERT_EQUAL(strnlen(((struct mudir_driver_message_ack *) message->message)->outbound_, MUDIR_MAX_STRING_LEN), 0);
  CU_ASSERT_EQUAL(((struct mudir_driver_message_ack *) message->message)->mode_, MUDIR_DRIVERMSG_ACK_MODE_UNASSIGNED);
  CU_ASSERT_PTR_NOT_NULL(message->message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_messagetype_set_test_drvregack"), MUDIR_SUCCESS);
}

void mudir_drvmsg_messagetype_set_test_devqry()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_QUERY), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(message->message_type_, MUDIR_DRIVERMSG_TYPE_DEVICE_QUERY);
  CU_ASSERT_PTR_NOT_NULL(message->message);
  CU_ASSERT_EQUAL(strnlen(((struct mudir_driver_message_devcomqry *) message->message)->driver_name_, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL(strnlen(((struct mudir_driver_message_devcomqry *) message->message)->device_name_, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL(((struct mudir_driver_message_devcomqry *) message->message)->num_opts_, 0);
  CU_ASSERT_PTR_NULL(((struct mudir_driver_message_devcomqry *) message->message)->options_);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_messagetype_set_test_devqry"), MUDIR_SUCCESS);
}

void mudir_drvmsg_messagetype_set_test_devcom()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(message->message_type_, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND);
  CU_ASSERT_PTR_NOT_NULL(message->message);
  CU_ASSERT_EQUAL(strnlen(((struct mudir_driver_message_devcomqry *) message->message)->driver_name_, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL(strnlen(((struct mudir_driver_message_devcomqry *) message->message)->device_name_, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL(((struct mudir_driver_message_devcomqry *) message->message)->num_opts_, 0);
  CU_ASSERT_PTR_NULL(((struct mudir_driver_message_devcomqry *) message->message)->options_);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_messagetype_set_test_devcom"), MUDIR_SUCCESS);
}

void mudir_drvmsg_messagetype_set_test_devreply()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(message->message_type_, MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY);
  CU_ASSERT_EQUAL(strnlen(((struct mudir_driver_message_devreply *) message->message)->driver_name_, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL(strnlen(((struct mudir_driver_message_devreply *) message->message)->device_name_, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL(strnlen(((struct mudir_driver_message_devreply *) message->message)->value_, MUDIR_MAX_STRING_LEN), 0);
  CU_ASSERT_EQUAL(strnlen(((struct mudir_driver_message_devreply *) message->message)->unit_, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_PTR_NOT_NULL(message->message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_messagetype_set_test_devreply"), MUDIR_SUCCESS);
}

void mudir_drvmsg_messagetype_get_test_nullcheck()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_messagetype_get(NULL), MUDIR_DRIVERMSG_TYPE_DRIVER_UNASSIGNED);
}

void mudir_drvmsg_messagetype_get_test_emptymessagecheck()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_messagetype_get(message), MUDIR_DRIVERMSG_TYPE_DRIVER_UNASSIGNED);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_messagetype_get_test_emptymessagecheck"), MUDIR_SUCCESS);
}

void mudir_drvmsg_messagetype_get_test_normal()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_messagetype_get(message), MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_messagetype_get_test_normal"), MUDIR_SUCCESS);
}
