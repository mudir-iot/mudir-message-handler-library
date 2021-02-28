#include <CUnit/CUnit.h>
#include <stdio.h>
#include <limits.h>
#include <mcheck.h>
#include "common.h"
#include "common_test.h"
#include "msghandlerdrv.h"
#include "msghandlerdrvtest.h"
#include "msghandlerdrv_pvt.h"
#include "msghandlerdrvcomqry.test.h"

int msghandlerdrvcomqry_test_init()
{
  CU_pSuite pSuite = NULL;
  
  MUDIR_TEST_ADD_SUITE(pSuite, "Driver Command/Query Message Structure Getters and Setters", NULL, NULL);
  
  /* Add the tests to the suite */
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_init: NULL check", mudir_drvmsg_comqry_init_test_null_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_clean: NULL check", mudir_drvmsg_comqry_clean_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_clean: NULL message check", mudir_drvmsg_comqry_clean_test_null_msg_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_driver_name_set: NULL check", mudir_drvmsg_comqry_driver_name_set_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_driver_name_set: NULL parameter check", mudir_drvmsg_comqry_driver_name_set_test_null_param_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_driver_name_set: Message type check", mudir_drvmsg_comqry_driver_name_set_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_driver_name_set: NULL message structure check", mudir_drvmsg_comqry_driver_name_set_test_null_ackmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_driver_name_set: Normal operation", mudir_drvmsg_comqry_driver_name_set_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_driver_name_get: NULL check", mudir_drvmsg_comqry_driver_name_get_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_driver_name_get: Message type check", mudir_drvmsg_comqry_driver_name_get_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_driver_name_get: NULL message structure check", mudir_drvmsg_comqry_driver_name_get_test_null_ackmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_driver_name_get: Normal operation - Empty string", mudir_drvmsg_comqry_driver_name_get_test_base_empty_string_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_driver_name_get: Normal operation", mudir_drvmsg_comqry_driver_name_get_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_device_name_set: NULL check", mudir_drvmsg_comqry_device_name_set_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_device_name_set: NULL parameter check", mudir_drvmsg_comqry_device_name_set_test_null_param_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_device_name_set: Message type check", mudir_drvmsg_comqry_device_name_set_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_device_name_set: NULL message structure check", mudir_drvmsg_comqry_device_name_set_test_null_ackmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_device_name_set: Normal operation", mudir_drvmsg_comqry_device_name_set_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_device_name_get: NULL check", mudir_drvmsg_comqry_device_name_get_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_device_name_get: Message type check", mudir_drvmsg_comqry_device_name_get_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_device_name_get: NULL message structure check", mudir_drvmsg_comqry_device_name_get_test_null_ackmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_device_name_get: Normal operation - Empty string", mudir_drvmsg_comqry_device_name_get_test_base_empty_string_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_device_name_get: Normal operation", mudir_drvmsg_comqry_device_name_get_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_count_set: NULL check", mudir_drvmsg_comqry_opts_count_set_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_count_set: Zero count check", mudir_drvmsg_comqry_opts_count_set_test_zero_count_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_count_set: Negative count check", mudir_drvmsg_comqry_opts_count_set_test_negative_count_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_count_set: Message type check", mudir_drvmsg_comqry_opts_count_set_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_count_set: NULL message structure test", mudir_drvmsg_comqry_opts_count_set_test_null_comqrymessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_count_set: Normal operation", mudir_drvmsg_comqry_opts_count_set_test_base);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_count_set: Reallocation check increase", mudir_drvmsg_comqry_opts_count_set_test_base_realloc_check_increase);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_count_set: Reallocation check decrease", mudir_drvmsg_comqry_opts_count_set_test_base_realloc_check_decrease);
  
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_count_get: NULL check", mudir_drvmsg_comqry_opts_count_get_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_count_get: Message type check", mudir_drvmsg_comqry_opts_count_get_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_count_get: NULL message structure test", mudir_drvmsg_comqry_opts_count_get_test_null_comqrymessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_count_get: Normal operation - Empty message", mudir_drvmsg_comqry_opts_count_get_test_base_empty_message);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_count_get: Normal operation", mudir_drvmsg_comqry_opts_count_get_test_base);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_key_set: NULL check", mudir_drvmsg_comqry_opts_key_set_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_key_set: NULL parameter check", mudir_drvmsg_comqry_opts_key_set_test_null_param_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_key_set: Message type check", mudir_drvmsg_comqry_opts_key_set_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_key_set: NULL message structure check", mudir_drvmsg_comqry_opts_key_set_test_null_comqrymessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_key_set: Index check - Lower bound", mudir_drvmsg_comqry_opts_key_set_test_index_lowerbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_key_set: Index check - Upper bound", mudir_drvmsg_comqry_opts_key_set_test_index_upperbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_key_set: NULL capabilities structure check", mudir_drvmsg_comqry_opts_key_set_test_null_comqryoptsmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_key_set: Normal operation", mudir_drvmsg_comqry_opts_key_set_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_key_get: NULL check", mudir_drvmsg_comqry_opts_key_get_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_key_get: Message type check", mudir_drvmsg_comqry_opts_key_get_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_key_get: NULL message structure check", mudir_drvmsg_comqry_opts_key_get_test_null_comqrymessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_key_get: Index check - Lower bound", mudir_drvmsg_comqry_opts_key_get_test_index_lowerbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_key_get: Index check - Upper bound", mudir_drvmsg_comqry_opts_key_get_test_index_upperbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_key_get: NULL capabilities structure check", mudir_drvmsg_comqry_opts_key_get_test_null_comqryoptsmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_key_get: Normal operation - Empty name", mudir_drvmsg_comqry_opts_key_get_test_base_empty_string);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_key_get: Normal operation", mudir_drvmsg_comqry_opts_key_get_test_base);

  // MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_valuetype_get: NULL check", mudir_drvmsg_comqry_opts_valuetype_get_test_null_check);
  // MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_valuetype_get: Message type check", mudir_drvmsg_comqry_opts_valuetype_get_test_message_type_check);
  // MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_valuetype_get: NULL message structure check", mudir_drvmsg_comqry_opts_valuetype_get_test_null_regmessage_check);
  // MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_valuetype_get: Index check - Lower bound", mudir_drvmsg_comqry_opts_valuetype_get_test_index_lowerbound_check);
  // MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_valuetype_get: Index check - Upper bound", mudir_drvmsg_comqry_opts_valuetype_get_test_index_upperbound_check);
  // MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_valuetype_get: NULL capabilities structure check", mudir_drvmsg_comqry_opts_valuetype_get_test_null_regcapmessage_check);
  // MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_valuetype_get: Normal operation - Empty description", mudir_drvmsg_comqry_opts_valuetype_get_test_base_empty_message);
  // MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_comqry_opts_valuetype_get: Normal operation", mudir_drvmsg_comqry_opts_valuetype_get_test_base);



  return MUDIR_SUCCESS;
}

void mudir_drvmsg_comqry_init_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_init(NULL), MUDIR_ERROR);
}

void mudir_drvmsg_comqry_clean_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_clean(NULL), MUDIR_ERROR);
}

void mudir_drvmsg_comqry_clean_test_null_msg_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_clean(message), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_clean_test_null_msg_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_driver_name_set_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_driver_name_set(NULL, NULL), MUDIR_ERROR);
}

void mudir_drvmsg_comqry_driver_name_set_test_null_param_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_driver_name_set(message, NULL), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_driver_name_set_test_null_param_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_driver_name_set_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_driver_name_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_driver_name_set_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_driver_name_set_test_null_ackmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND;
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_driver_name_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_driver_name_set_test_null_ackmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_driver_name_set_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_driver_name_set(message, testName), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strncmp(((struct mudir_driver_message_devcomqry *)(message->message))->driver_name_, testName, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_driver_name_set_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_driver_name_get_test_null_check()
{
  CU_ASSERT_PTR_NULL(mudir_drvmsg_comqry_driver_name_get(NULL));
}

void mudir_drvmsg_comqry_driver_name_get_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_comqry_driver_name_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_driver_name_get_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_driver_name_get_test_null_ackmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND;
  CU_ASSERT_PTR_NULL(mudir_drvmsg_comqry_driver_name_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_driver_name_get_test_null_ackmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_driver_name_get_test_base_empty_string_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strnlen(mudir_drvmsg_comqry_driver_name_get(message), MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_driver_name_get_test_base_empty_string_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_driver_name_get_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_driver_name_set(message, testName), MUDIR_SUCCESS); 
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_comqry_driver_name_get(message), testName, MUDIR_MAX_NAME_LEN), 0); 
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_driver_name_get_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_device_name_set_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_device_name_set(NULL, NULL), MUDIR_ERROR);
}

void mudir_drvmsg_comqry_device_name_set_test_null_param_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_device_name_set(message, NULL), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_device_name_set_test_null_param_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_device_name_set_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_device_name_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_device_name_set_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_device_name_set_test_null_ackmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND;
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_device_name_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_device_name_set_test_null_ackmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_device_name_set_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_device_name_set(message, testName), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strncmp(((struct mudir_driver_message_devcomqry *)(message->message))->device_name_, testName, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_device_name_set_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_device_name_get_test_null_check()
{
  CU_ASSERT_PTR_NULL(mudir_drvmsg_comqry_device_name_get(NULL));
}

void mudir_drvmsg_comqry_device_name_get_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_comqry_device_name_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_device_name_get_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_device_name_get_test_null_ackmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND;
  CU_ASSERT_PTR_NULL(mudir_drvmsg_comqry_device_name_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_device_name_get_test_null_ackmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_device_name_get_test_base_empty_string_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strnlen(mudir_drvmsg_comqry_device_name_get(message), MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_device_name_get_test_base_empty_string_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_device_name_get_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_device_name_set(message, testName), MUDIR_SUCCESS); 
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_comqry_device_name_get(message), testName, MUDIR_MAX_NAME_LEN), 0); 
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_device_name_get_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_count_set_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_count_set(NULL, 1), MUDIR_ERROR);
}

void mudir_drvmsg_comqry_opts_count_set_test_zero_count_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_count_set(message, 0), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_count_set_test_zero_count_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_count_set_test_negative_count_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_count_set(message, -1), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_count_set_test_negative_count_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_count_set_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_count_set(message, 1), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_count_set_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_count_set_test_null_comqrymessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DEVICE_QUERY;
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_count_set(message, 1), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_count_set_test_null_comqrymessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_count_set_test_base()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_devcomqry* comqrymessage;
  struct mudir_driver_message_devopts *comqrydevopts;
  MUDIR_BYTE  buff[MUDIR_MAX_BUFFER_SIZE];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  memset(buff, 0, MUDIR_MAX_BUFFER_SIZE);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_QUERY), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_count_set(message, 1), MUDIR_SUCCESS);
  comqrymessage = (struct mudir_driver_message_devcomqry*)(message->message);
  CU_ASSERT_PTR_NOT_NULL_FATAL(comqrymessage);
  comqrydevopts = (struct mudir_driver_message_devopts *) comqrymessage->options_;
  CU_ASSERT_PTR_NOT_NULL_FATAL(comqrydevopts);
  CU_ASSERT_EQUAL(strnlen(comqrydevopts[0].key_, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL(comqrydevopts[0].type_, MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN);
  CU_ASSERT_EQUAL(memcmp(comqrydevopts[0].value_, buff, MUDIR_MAX_BUFFER_SIZE), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_count_set_test_base"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_count_set_test_base_realloc_check_increase()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_devcomqry* comqrymessage;
  struct mudir_driver_message_devopts *comqrydevopts;
  MUDIR_BYTE  buff[MUDIR_MAX_BUFFER_SIZE];
  MUDIR_BYTE  buff2[MUDIR_MAX_BUFFER_SIZE];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;
  memset(buff, 0, MUDIR_MAX_BUFFER_SIZE);
  memset(buff2, 0, MUDIR_MAX_BUFFER_SIZE);
  buff[0] = 0xab;
  buff[1] = 0xac;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_count_set(message, 1), MUDIR_SUCCESS);
  comqrymessage = (struct mudir_driver_message_devcomqry *)(message->message);
  CU_ASSERT_PTR_NOT_NULL_FATAL(comqrymessage);
  comqrydevopts = (struct mudir_driver_message_devopts *) comqrymessage->options_;
  CU_ASSERT_PTR_NOT_NULL_FATAL(comqrydevopts);
  strncpy(comqrydevopts[0].key_, "ABCD", MUDIR_MAX_NAME_LEN);
  comqrydevopts[0].type_ = MUDIR_DRIVERMSG_RETURN_TYPE_STRING;
  memcpy(comqrydevopts[0].value_, buff, MUDIR_MAX_BUFFER_SIZE);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_count_set(message, 2), MUDIR_SUCCESS);
  comqrydevopts = (struct mudir_driver_message_devopts *) comqrymessage->options_;
  CU_ASSERT_EQUAL(comqrydevopts[0].type_, MUDIR_DRIVERMSG_RETURN_TYPE_STRING);
  CU_ASSERT_EQUAL(strnlen(comqrydevopts[0].key_, MUDIR_MAX_NAME_LEN), 4);
  CU_ASSERT_EQUAL(strncmp(comqrydevopts[0].key_, "ABCD", MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL(memcmp(comqrydevopts[0].value_, buff, MUDIR_MAX_BUFFER_SIZE), 0);
  CU_ASSERT_EQUAL(comqrydevopts[1].type_, MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN);
  CU_ASSERT_EQUAL(strnlen(comqrydevopts[1].key_, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL(memcmp(comqrydevopts[1].value_, buff2, MUDIR_MAX_BUFFER_SIZE), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS); 
  CU_ASSERT_PTR_NULL_FATAL(message); 

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_count_set_test_base_realloc_check_increase"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_count_set_test_base_realloc_check_decrease()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_devcomqry* comqrymessage;
  struct mudir_driver_message_devopts *comqrydevopts;
  MUDIR_BYTE  buff[MUDIR_MAX_BUFFER_SIZE];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;
  memset(buff, 0, MUDIR_MAX_BUFFER_SIZE);
  buff[0] = 0xab;
  buff[1] = 0xac;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_count_set(message, 2), MUDIR_SUCCESS);
  comqrymessage = (struct mudir_driver_message_devcomqry *)(message->message);
  CU_ASSERT_PTR_NOT_NULL_FATAL(comqrymessage);
  comqrydevopts = (struct mudir_driver_message_devopts *) comqrymessage->options_;
  CU_ASSERT_PTR_NOT_NULL_FATAL(comqrydevopts);
  strncpy(comqrydevopts[0].key_, "ABCD", MUDIR_MAX_NAME_LEN);
  comqrydevopts[0].type_ = MUDIR_DRIVERMSG_RETURN_TYPE_STRING;
  memcpy(comqrydevopts[0].value_, buff, MUDIR_MAX_BUFFER_SIZE);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_count_set(message, 1), MUDIR_SUCCESS);
  comqrydevopts = (struct mudir_driver_message_devopts *) comqrymessage->options_;
  CU_ASSERT_EQUAL(comqrydevopts[0].type_, MUDIR_DRIVERMSG_RETURN_TYPE_STRING);
  CU_ASSERT_EQUAL(strnlen(comqrydevopts[0].key_, MUDIR_MAX_NAME_LEN), 4);
  CU_ASSERT_EQUAL(strncmp(comqrydevopts[0].key_, "ABCD", MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL(memcmp(comqrydevopts[0].value_, buff, MUDIR_MAX_BUFFER_SIZE), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS); 
  CU_ASSERT_PTR_NULL_FATAL(message); 

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_count_set_test_base_realloc_check_decrease"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_count_get_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_count_get(NULL), -1);
}

void mudir_drvmsg_comqry_opts_count_get_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_count_get(message), -1);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_count_get_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_count_get_test_null_comqrymessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND;
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_count_get(message), -1);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_count_get_test_null_comqrymessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_count_get_test_base_empty_message()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_count_get(message), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_count_get_test_base_empty_message"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_count_get_test_base()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_comqry_opts_count_set(message, 2), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_count_get(message), 2);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_count_get_test_base"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_key_set_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_key_set(NULL, 1, "NULL"), MUDIR_ERROR);
}

void mudir_drvmsg_comqry_opts_key_set_test_null_param_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_key_set(message, 0, NULL), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_key_set_test_null_param_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_key_set_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_key_set(message, 1, "NULL"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_key_set_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_key_set_test_null_comqrymessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND;
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_key_set(message, 1, "NULL"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_key_set_test_null_regmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_key_set_test_index_lowerbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_key_set(message, -1, "NULL"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_key_set_test_index_lowerbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_key_set_test_index_upperbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_key_set(message, 1, "NULL"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_key_set_test_index_upperbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_key_set_test_null_comqryoptsmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_devcomqry *comqrymessage;

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND), MUDIR_SUCCESS);
  comqrymessage = (struct mudir_driver_message_devcomqry*)(message->message);
  comqrymessage->num_opts_ = 1;
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_key_set(message, 0, "NULL"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_key_set_test_null_comqrymessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_key_set_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_devcomqry *comqrymessage;
  struct mudir_driver_message_devopts *comqryoptsmsg;

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_comqry_opts_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_comqry_opts_key_set(message, 0, "ABCD"), MUDIR_SUCCESS);
  comqrymessage = (struct mudir_driver_message_devcomqry *)(message->message);
  CU_ASSERT_PTR_NOT_NULL_FATAL(comqrymessage);
  comqryoptsmsg = (struct mudir_driver_message_devopts *) comqrymessage->options_;
  CU_ASSERT_PTR_NOT_NULL_FATAL(comqryoptsmsg);
  CU_ASSERT_EQUAL(strncmp(comqryoptsmsg[0].key_, "ABCD", MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_key_set_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_key_get_test_null_check()
{
  CU_ASSERT_PTR_NULL(mudir_drvmsg_comqry_opts_key_get(NULL, 0));
}

void mudir_drvmsg_comqry_opts_key_get_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_comqry_opts_key_get(message, 0));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_key_get_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_key_get_test_null_comqrymessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND;
  CU_ASSERT_PTR_NULL(mudir_drvmsg_comqry_opts_key_get(message, 0));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_key_get_test_null_comqrymessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_key_get_test_index_lowerbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_comqry_opts_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_comqry_opts_key_get(message, -1));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_key_get_test_index_lowerbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_key_get_test_index_upperbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_comqry_opts_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_comqry_opts_key_get(message, 1));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_key_get_test_index_upperbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_key_get_test_null_comqryoptsmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_devcomqry *comqrymessage;

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND), MUDIR_SUCCESS);
  comqrymessage = (struct mudir_driver_message_devcomqry *)(message->message);
  comqrymessage->num_opts_ = 1;
  CU_ASSERT_PTR_NULL(mudir_drvmsg_comqry_opts_key_get(message, 0));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_key_get_test_null_comqryoptsmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_key_get_test_base_empty_string()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_comqry_opts_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strnlen(mudir_drvmsg_comqry_opts_key_get(message, 0), MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_key_get_test_base_empty_string"), MUDIR_SUCCESS);
}

void mudir_drvmsg_comqry_opts_key_get_test_base()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_comqry_opts_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_comqry_opts_key_set(message, 0, "ABCD"), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_comqry_opts_key_get(message, 0), "ABCD", MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_comqry_opts_key_get_test_base"), MUDIR_SUCCESS);
}
