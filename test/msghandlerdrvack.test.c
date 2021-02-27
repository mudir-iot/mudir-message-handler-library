#include <CUnit/CUnit.h>
#include <stdio.h>
#include <limits.h>
#include <mcheck.h>
#include "common.h"
#include "common_test.h"
#include "msghandlerdrv.h"
#include "msghandlerdrvtest.h"
#include "msghandlerdrv_pvt.h"
#include "msghandlerdrvack.test.h"

int msghandlerdrvack_test_init()
{
  CU_pSuite pSuite = NULL;
  
  MUDIR_TEST_ADD_SUITE(pSuite, "Driver Acknowledgement Message Structure Getters and Setters", NULL, NULL);
  
  /* Add the tests to the suite */
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_init: NULL check", mudir_drvmsg_ack_init_test_null_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_clean: NULL check", mudir_drvmsg_ack_clean_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_clean: NULL message check", mudir_drvmsg_ack_clean_test_null_msg_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_name_set: NULL check", mudir_drvmsg_ack_name_set_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_name_set: NULL parameter check", mudir_drvmsg_ack_name_set_test_null_param_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_name_set: Message type check", mudir_drvmsg_ack_name_set_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_name_set: NULL message structure check", mudir_drvmsg_ack_name_set_test_null_ackmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_name_set: Normal operation", mudir_drvmsg_ack_name_set_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_name_get: NULL check", mudir_drvmsg_ack_name_get_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_name_get: Message type check", mudir_drvmsg_ack_name_get_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_name_get: NULL message structure check", mudir_drvmsg_ack_name_get_test_null_ackmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_name_get: Normal operation - Empty string", mudir_drvmsg_ack_name_get_test_base_empty_string_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_name_get: Normal operation", mudir_drvmsg_ack_name_get_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_inaddr_set: NULL check", mudir_drvmsg_ack_inaddr_set_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_inaddr_set: NULL parameter check", mudir_drvmsg_ack_inaddr_set_test_null_param_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_inaddr_set: Message type check", mudir_drvmsg_ack_inaddr_set_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_inaddr_set: NULL message structure check", mudir_drvmsg_ack_inaddr_set_test_null_ackmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_inaddr_set: Normal operation", mudir_drvmsg_ack_inaddr_set_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_inaddr_get: NULL check", mudir_drvmsg_ack_inaddr_get_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_inaddr_get: Message type check", mudir_drvmsg_ack_inaddr_get_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_inaddr_get: NULL message structure check", mudir_drvmsg_ack_inaddr_get_test_null_ackmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_inaddr_get: Normal operation - Empty string", mudir_drvmsg_ack_inaddr_get_test_base_empty_string_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_inaddr_get: Normal operation", mudir_drvmsg_ack_inaddr_get_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_outaddr_set: NULL check", mudir_drvmsg_ack_outaddr_set_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_outaddr_set: NULL parameter check", mudir_drvmsg_ack_outaddr_set_test_null_param_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_outaddr_set: Message type check", mudir_drvmsg_ack_outaddr_set_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_outaddr_set: NULL message structure check", mudir_drvmsg_ack_outaddr_set_test_null_ackmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_outaddr_set: Normal operation", mudir_drvmsg_ack_outaddr_set_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_outaddr_get: NULL check", mudir_drvmsg_ack_outaddr_get_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_outaddr_get: Message type check", mudir_drvmsg_ack_outaddr_get_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_outaddr_get: NULL message structure check", mudir_drvmsg_ack_outaddr_get_test_null_ackmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_outaddr_get: Normal operation - Empty string", mudir_drvmsg_ack_outaddr_get_test_base_empty_string_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_outaddr_get: Normal operation", mudir_drvmsg_ack_outaddr_get_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_mode_set: NULL check", mudir_drvmsg_ack_mode_set_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_mode_set: Invalid parameter lower bound check", mudir_drvmsg_ack_mode_set_test_invalid_param_lbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_mode_set: Invalid parameter upper bound check", mudir_drvmsg_ack_mode_set_test_invalid_param_ubound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_mode_set: Message type check", mudir_drvmsg_ack_mode_set_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_mode_set: NULL message structure check", mudir_drvmsg_ack_mode_set_test_null_ackmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_mode_set: Normal operation", mudir_drvmsg_ack_mode_set_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_mode_get: NULL check", mudir_drvmsg_ack_mode_get_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_mode_get: Message type check", mudir_drvmsg_ack_mode_get_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_mode_get: NULL message structure check", mudir_drvmsg_ack_mode_get_test_null_ackmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_mode_get: Normal operation - Empty description", mudir_drvmsg_ack_mode_get_test_base_empty_message);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_ack_mode_get: Normal operation", mudir_drvmsg_ack_mode_get_test_base);

  return MUDIR_SUCCESS;
}

void mudir_drvmsg_ack_init_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_init(NULL), MUDIR_ERROR);
}

void mudir_drvmsg_ack_clean_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_clean(NULL), MUDIR_ERROR);
}

void mudir_drvmsg_ack_clean_test_null_msg_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_clean(message), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_clean_test_null_msg_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_name_set_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_name_set(NULL, NULL), MUDIR_ERROR);
}

void mudir_drvmsg_ack_name_set_test_null_param_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_name_set(message, NULL), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_name_set_test_null_param_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_name_set_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_name_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_name_set_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_name_set_test_null_ackmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK;
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_name_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_name_set_test_null_ackmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_name_set_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_name_set(message, testName), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strncmp(((struct mudir_driver_message_ack *)(message->message))->name_, testName, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_name_set_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_name_get_test_null_check()
{
  CU_ASSERT_PTR_NULL(mudir_drvmsg_ack_name_get(NULL));
}

void mudir_drvmsg_ack_name_get_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_ack_name_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_name_get_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_name_get_test_null_ackmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK;
  CU_ASSERT_PTR_NULL(mudir_drvmsg_ack_name_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_name_get_test_null_ackmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_name_get_test_base_empty_string_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strnlen(mudir_drvmsg_ack_name_get(message), MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_name_get_test_base_empty_string_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_name_get_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_name_set(message, testName), MUDIR_SUCCESS); 
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_ack_name_get(message), testName, MUDIR_MAX_NAME_LEN), 0); 
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_name_get_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_inaddr_set_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_inaddr_set(NULL, NULL), MUDIR_ERROR);
}

void mudir_drvmsg_ack_inaddr_set_test_null_param_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_inaddr_set(message, NULL), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_inaddr_set_test_null_param_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_inaddr_set_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_inaddr_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_inaddr_set_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_inaddr_set_test_null_ackmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK;
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_inaddr_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_inaddr_set_test_null_ackmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_inaddr_set_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_inaddr_set(message, testName), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strncmp(((struct mudir_driver_message_ack *)(message->message))->inbound_, testName, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_inaddr_set_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_inaddr_get_test_null_check()
{
  CU_ASSERT_PTR_NULL(mudir_drvmsg_ack_inaddr_get(NULL));
}

void mudir_drvmsg_ack_inaddr_get_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_ack_inaddr_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_inaddr_get_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_inaddr_get_test_null_ackmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK;
  CU_ASSERT_PTR_NULL(mudir_drvmsg_ack_inaddr_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_inaddr_get_test_null_ackmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_inaddr_get_test_base_empty_string_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strnlen(mudir_drvmsg_ack_inaddr_get(message), MUDIR_MAX_STRING_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_inaddr_get_test_base_empty_string_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_inaddr_get_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testAddress[] = "testAddress";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_inaddr_set(message, testAddress), MUDIR_SUCCESS); 
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_ack_inaddr_get(message), testAddress, MUDIR_MAX_STRING_LEN), 0); 
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_inaddr_get_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_outaddr_set_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_outaddr_set(NULL, NULL), MUDIR_ERROR);
}

void mudir_drvmsg_ack_outaddr_set_test_null_param_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_outaddr_set(message, NULL), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_outaddr_set_test_null_param_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_outaddr_set_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_outaddr_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_outaddr_set_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_outaddr_set_test_null_ackmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK;
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_outaddr_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_outaddr_set_test_null_ackmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_outaddr_set_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testAddress[] = "testAddress";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_outaddr_set(message, testAddress), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strncmp(((struct mudir_driver_message_ack *)(message->message))->outbound_, testAddress, MUDIR_MAX_STRING_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_outaddr_set_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_outaddr_get_test_null_check()
{
  CU_ASSERT_PTR_NULL(mudir_drvmsg_ack_outaddr_get(NULL));
}

void mudir_drvmsg_ack_outaddr_get_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_ack_outaddr_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_outaddr_get_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_outaddr_get_test_null_ackmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK;
  CU_ASSERT_PTR_NULL(mudir_drvmsg_ack_outaddr_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_outaddr_get_test_null_ackmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_outaddr_get_test_base_empty_string_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strnlen(mudir_drvmsg_ack_outaddr_get(message), MUDIR_MAX_STRING_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_outaddr_get_test_base_empty_string_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_outaddr_get_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testAddress[] = "testAddress";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_outaddr_set(message, testAddress), MUDIR_SUCCESS); 
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_ack_outaddr_get(message), testAddress, MUDIR_MAX_STRING_LEN), 0); 
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_outaddr_get_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_mode_set_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_mode_set(NULL, MUDIR_DRIVERMSG_ACK_MODE_UNASSIGNED), MUDIR_ERROR);
}

void mudir_drvmsg_ack_mode_set_test_invalid_param_lbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_mode_set(message, -1), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_mode_set_test_invalid_param_lbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_mode_set_test_invalid_param_ubound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_mode_set(message, 4), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_mode_set_test_invalid_param_ubound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_mode_set_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_mode_set(message, MUDIR_DRIVERMSG_ACK_MODE_UNASSIGNED), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_mode_set_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_mode_set_test_null_ackmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK;
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_mode_set(message, MUDIR_DRIVERMSG_ACK_MODE_UNASSIGNED), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_mode_set_test_null_ackmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_mode_set_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_ack* ackmessage;

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_mode_set(message, MUDIR_DRIVERMSG_ACK_MODE_IPC), MUDIR_SUCCESS);
  ackmessage = (struct mudir_driver_message_ack *)(message->message);
  CU_ASSERT_EQUAL(ackmessage->mode_, MUDIR_DRIVER_TYPE_SENSOR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_mode_set_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_mode_get_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_mode_get(NULL), MUDIR_DRIVERMSG_ACK_MODE_UNASSIGNED);
}

void mudir_drvmsg_ack_mode_get_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_mode_get(message), MUDIR_DRIVERMSG_ACK_MODE_UNASSIGNED);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_mode_get_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_mode_get_test_null_ackmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK;
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_mode_get(message), MUDIR_DRIVERMSG_ACK_MODE_UNASSIGNED);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_mode_get_test_null_ackmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_mode_get_test_base_empty_message()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_mode_get(message), MUDIR_DRIVERMSG_ACK_MODE_UNASSIGNED);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_mode_get_test_base_empty_message"), MUDIR_SUCCESS);
}

void mudir_drvmsg_ack_mode_get_test_base()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_ack_mode_set(message, MUDIR_DRIVERMSG_ACK_MODE_IPC), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_ack_mode_get(message), MUDIR_DRIVERMSG_ACK_MODE_IPC);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_ack_mode_get_test_base"), MUDIR_SUCCESS);
}
