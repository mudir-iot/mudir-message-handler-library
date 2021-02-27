#include <CUnit/CUnit.h>
#include <stdio.h>
#include <limits.h>
#include <mcheck.h>
#include "common.h"
#include "common_test.h"
#include "msghandlerdrv.h"
#include "msghandlerdrvtest.h"
#include "msghandlerdrv_pvt.h"
#include "msghandlerdrvrep.test.h"

int msghandlerdrvrep_test_init()
{
  CU_pSuite pSuite = NULL;
  
  MUDIR_TEST_ADD_SUITE(pSuite, "Driver Command/Query Reply Message Structure Getters and Setters", NULL, NULL);
  
  /* Add the tests to the suite */
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_rep_init: NULL check", mudir_drvmsg_rep_init_test_null_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_rep_clean: NULL check", mudir_drvmsg_rep_clean_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_rep_clean: NULL message check", mudir_drvmsg_rep_clean_test_null_msg_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_driver_name_set: NULL check", mudir_drvmsg_reply_driver_name_set_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_driver_name_set: NULL parameter check", mudir_drvmsg_reply_driver_name_set_test_null_param_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_driver_name_set: Message type check", mudir_drvmsg_reply_driver_name_set_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_driver_name_set: NULL message structure check", mudir_drvmsg_reply_driver_name_set_test_null_ackmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_driver_name_set: Normal operation", mudir_drvmsg_reply_driver_name_set_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_driver_name_get: NULL check", mudir_drvmsg_reply_driver_name_get_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_driver_name_get: Message type check", mudir_drvmsg_reply_driver_name_get_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_driver_name_get: NULL message structure check", mudir_drvmsg_reply_driver_name_get_test_null_ackmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_driver_name_get: Normal operation - Empty string", mudir_drvmsg_reply_driver_name_get_test_base_empty_string_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_driver_name_get: Normal operation", mudir_drvmsg_reply_driver_name_get_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_device_name_set: NULL check", mudir_drvmsg_reply_device_name_set_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_device_name_set: NULL parameter check", mudir_drvmsg_reply_device_name_set_test_null_param_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_device_name_set: Message type check", mudir_drvmsg_reply_device_name_set_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_device_name_set: NULL message structure check", mudir_drvmsg_reply_device_name_set_test_null_ackmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_device_name_set: Normal operation", mudir_drvmsg_reply_device_name_set_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_device_name_get: NULL check", mudir_drvmsg_reply_device_name_get_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_device_name_get: Message type check", mudir_drvmsg_reply_device_name_get_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_device_name_get: NULL message structure check", mudir_drvmsg_reply_device_name_get_test_null_ackmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_device_name_get: Normal operation - Empty string", mudir_drvmsg_reply_device_name_get_test_base_empty_string_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_device_name_get: Normal operation", mudir_drvmsg_reply_device_name_get_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_value_set: NULL check", mudir_drvmsg_reply_value_set_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_value_set: NULL parameter check", mudir_drvmsg_reply_value_set_test_null_param_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_value_set: Message type check", mudir_drvmsg_reply_value_set_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_value_set: NULL message structure check", mudir_drvmsg_reply_value_set_test_null_ackmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_value_set: Normal operation", mudir_drvmsg_reply_value_set_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_value_get: NULL check", mudir_drvmsg_reply_value_get_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_value_get: Message type check", mudir_drvmsg_reply_value_get_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_value_get: NULL message structure check", mudir_drvmsg_reply_value_get_test_null_ackmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_value_get: Normal operation - Empty string", mudir_drvmsg_reply_value_get_test_base_empty_string_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_value_get: Normal operation", mudir_drvmsg_reply_value_get_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_unit_set: NULL check", mudir_drvmsg_reply_unit_set_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_unit_set: NULL parameter check", mudir_drvmsg_reply_unit_set_test_null_param_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_unit_set: Message type check", mudir_drvmsg_reply_unit_set_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_unit_set: NULL message structure check", mudir_drvmsg_reply_unit_set_test_null_ackmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_unit_set: Normal operation", mudir_drvmsg_reply_unit_set_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_unit_get: NULL check", mudir_drvmsg_reply_unit_get_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_unit_get: Message type check", mudir_drvmsg_reply_unit_get_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_unit_get: NULL message structure check", mudir_drvmsg_reply_unit_get_test_null_ackmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_unit_get: Normal operation - Empty string", mudir_drvmsg_reply_unit_get_test_base_empty_string_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reply_unit_get: Normal operation", mudir_drvmsg_reply_unit_get_test_base_check);

  return MUDIR_SUCCESS;
}

void mudir_drvmsg_rep_init_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_rep_init(NULL), MUDIR_ERROR);
}

void mudir_drvmsg_rep_clean_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_rep_clean(NULL), MUDIR_ERROR);
}

void mudir_drvmsg_rep_clean_test_null_msg_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_rep_clean(message), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_rep_clean_test_null_msg_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_driver_name_set_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_driver_name_set(NULL, NULL), MUDIR_ERROR);
}

void mudir_drvmsg_reply_driver_name_set_test_null_param_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_driver_name_set(message, NULL), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_driver_name_set_test_null_param_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_driver_name_set_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_driver_name_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_driver_name_set_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_driver_name_set_test_null_ackmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY;
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_driver_name_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_driver_name_set_test_null_ackmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_driver_name_set_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_driver_name_set(message, testName), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strncmp(((struct mudir_driver_message_devreply *)(message->message))->driver_name_, testName, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_driver_name_set_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_driver_name_get_test_null_check()
{
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reply_driver_name_get(NULL));
}

void mudir_drvmsg_reply_driver_name_get_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reply_driver_name_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_driver_name_get_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_driver_name_get_test_null_ackmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY;
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reply_driver_name_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_driver_name_get_test_null_ackmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_driver_name_get_test_base_empty_string_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strnlen(mudir_drvmsg_reply_driver_name_get(message), MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_driver_name_get_test_base_empty_string_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_driver_name_get_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_driver_name_set(message, testName), MUDIR_SUCCESS); 
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_reply_driver_name_get(message), testName, MUDIR_MAX_NAME_LEN), 0); 
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_driver_name_get_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_device_name_set_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_device_name_set(NULL, NULL), MUDIR_ERROR);
}

void mudir_drvmsg_reply_device_name_set_test_null_param_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_device_name_set(message, NULL), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_device_name_set_test_null_param_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_device_name_set_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_device_name_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_device_name_set_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_device_name_set_test_null_ackmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY;
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_device_name_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_device_name_set_test_null_ackmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_device_name_set_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_device_name_set(message, testName), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strncmp(((struct mudir_driver_message_devreply *)(message->message))->device_name_, testName, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_device_name_set_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_device_name_get_test_null_check()
{
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reply_device_name_get(NULL));
}

void mudir_drvmsg_reply_device_name_get_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reply_device_name_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_device_name_get_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_device_name_get_test_null_ackmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY;
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reply_device_name_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_device_name_get_test_null_ackmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_device_name_get_test_base_empty_string_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strnlen(mudir_drvmsg_reply_device_name_get(message), MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_device_name_get_test_base_empty_string_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_device_name_get_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_device_name_set(message, testName), MUDIR_SUCCESS); 
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_reply_device_name_get(message), testName, MUDIR_MAX_NAME_LEN), 0); 
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_device_name_get_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_value_set_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_value_set(NULL, NULL), MUDIR_ERROR);
}

void mudir_drvmsg_reply_value_set_test_null_param_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_value_set(message, NULL), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_value_set_test_null_param_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_value_set_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_value_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_value_set_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_value_set_test_null_ackmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY;
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_value_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_value_set_test_null_ackmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_value_set_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_value_set(message, testName), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strncmp(((struct mudir_driver_message_devreply *)(message->message))->value_, testName, MUDIR_MAX_STRING_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_value_set_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_value_get_test_null_check()
{
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reply_value_get(NULL));
}

void mudir_drvmsg_reply_value_get_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reply_value_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_value_get_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_value_get_test_null_ackmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY;
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reply_value_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_value_get_test_null_ackmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_value_get_test_base_empty_string_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strnlen(mudir_drvmsg_reply_value_get(message), MUDIR_MAX_STRING_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_value_get_test_base_empty_string_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_value_get_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_value_set(message, testName), MUDIR_SUCCESS); 
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_reply_value_get(message), testName, MUDIR_MAX_STRING_LEN), 0); 
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_value_get_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_unit_set_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_unit_set(NULL, NULL), MUDIR_ERROR);
}

void mudir_drvmsg_reply_unit_set_test_null_param_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_unit_set(message, NULL), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_unit_set_test_null_param_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_unit_set_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_unit_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_unit_set_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_unit_set_test_null_ackmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY;
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_unit_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_unit_set_test_null_ackmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_unit_set_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_unit_set(message, testName), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strncmp(((struct mudir_driver_message_devreply *)(message->message))->unit_, testName, MUDIR_MAX_STRING_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_unit_set_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_unit_get_test_null_check()
{
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reply_unit_get(NULL));
}

void mudir_drvmsg_reply_unit_get_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reply_unit_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_unit_get_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_unit_get_test_null_ackmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY;
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reply_unit_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_unit_get_test_null_ackmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_unit_get_test_base_empty_string_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strnlen(mudir_drvmsg_reply_unit_get(message), MUDIR_MAX_STRING_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_unit_get_test_base_empty_string_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reply_unit_get_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reply_unit_set(message, testName), MUDIR_SUCCESS); 
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_reply_unit_get(message), testName, MUDIR_MAX_STRING_LEN), 0); 
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reply_unit_get_test_base_check"), MUDIR_SUCCESS);
}
