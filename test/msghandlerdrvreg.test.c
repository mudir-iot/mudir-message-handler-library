#include <CUnit/CUnit.h>
#include <stdio.h>
#include <limits.h>
#include <mcheck.h>
#include "common.h"
#include "common_test.h"
#include "msghandlerdrv.h"
#include "msghandlerdrvtest.h"
#include "msghandlerdrv_pvt.h"
#include "msghandlerdrvreg.test.h"

int msghandlerdrvreg_test_init()
{
  CU_pSuite pSuite = NULL;
  
  MUDIR_TEST_ADD_SUITE(pSuite, "Driver Register Message Structure Getters and Setters", NULL, NULL);
  
  /* Add the tests to the suite */
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_init: NULL check", mudir_drvmsg_reg_init_test_null_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_clean: NULL check", mudir_drvmsg_reg_clean_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_clean: NULL message check", mudir_drvmsg_reg_clean_test_null_msg_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_name_set: NULL check", mudir_drvmsg_reg_name_set_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_name_set: NULL parameter check", mudir_drvmsg_reg_name_set_test_null_param_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_name_set: Message type check", mudir_drvmsg_reg_name_set_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_name_set: NULL message structure test", mudir_drvmsg_reg_name_set_test_null_regmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_name_set: Normal operation", mudir_drvmsg_reg_name_set_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_name_get: NULL check", mudir_drvmsg_reg_name_get_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_name_get: Message type check", mudir_drvmsg_reg_name_get_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_name_get: NULL message structure test", mudir_drvmsg_reg_name_get_test_null_regmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_name_get: Normal operation - empty string", mudir_drvmsg_reg_name_get_test_base_empty_string);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_name_get: Normal operation", mudir_drvmsg_reg_name_get_test_base);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_snapname_set: NULL check", mudir_drvmsg_reg_snapname_set_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_snapname_set: NULL parameter check", mudir_drvmsg_reg_snapname_set_test_null_param_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_snapname_set: Message type check", mudir_drvmsg_reg_snapname_set_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_snapname_set: NULL message structure test", mudir_drvmsg_reg_snapname_set_test_null_regmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_snapname_set: Normal operation", mudir_drvmsg_reg_snapname_set_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_snapname_get: NULL check", mudir_drvmsg_reg_snapname_get_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_snapname_get: Message type check", mudir_drvmsg_reg_snapname_get_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_snapname_get: NULL message structure test", mudir_drvmsg_reg_snapname_get_test_null_regmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_snapname_get: Normal operation - empty string", mudir_drvmsg_reg_snapname_get_test_base_empty_string);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_snapname_get: Normal operation", mudir_drvmsg_reg_snapname_get_test_base);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_snapversion_set: NULL check", mudir_drvmsg_reg_snapversion_set_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_snapversion_set: NULL parameter check", mudir_drvmsg_reg_snapversion_set_test_null_param_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_snapversion_set: Message type check", mudir_drvmsg_reg_snapversion_set_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_snapversion_set: NULL message structure test", mudir_drvmsg_reg_snapversion_set_test_null_regmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_snapversion_set: Normal operation", mudir_drvmsg_reg_snapversion_set_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_snapversion_get: NULL check", mudir_drvmsg_reg_snapversion_get_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_snapversion_get: Message type check", mudir_drvmsg_reg_snapversion_get_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_snapversion_get: NULL message structure test", mudir_drvmsg_reg_snapversion_get_test_null_regmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_snapversion_get: Normal operation - empty string", mudir_drvmsg_reg_snapversion_get_test_base_empty_string);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_snapversion_get: Normal operation", mudir_drvmsg_reg_snapversion_get_test_base);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_count_set: NULL check", mudir_drvmsg_reg_cap_count_set_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_count_set: Zero count check", mudir_drvmsg_reg_cap_count_set_test_zero_count_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_count_set: Negative count check", mudir_drvmsg_reg_cap_count_set_test_negative_count_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_count_set: Message type check", mudir_drvmsg_reg_cap_count_set_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_count_set: NULL message structure test", mudir_drvmsg_reg_cap_count_set_test_null_regmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_count_set: Normal operation", mudir_drvmsg_reg_cap_count_set_test_base);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_count_set: Reallocation check increase", mudir_drvmsg_reg_cap_count_set_test_base_realloc_check_increase);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_count_set: Reallocation check decrease", mudir_drvmsg_reg_cap_count_set_test_base_realloc_check_decrease);
  
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_count_get: NULL check", mudir_drvmsg_reg_cap_count_get_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_count_get: Message type check", mudir_drvmsg_reg_cap_count_get_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_count_get: NULL message structure test", mudir_drvmsg_reg_cap_count_get_test_null_regmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_count_get: Normal operation - Empty message", mudir_drvmsg_reg_cap_count_get_test_base_empty_message);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_count_get: Normal operation", mudir_drvmsg_reg_cap_count_get_test_base);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_name_set: NULL check", mudir_drvmsg_reg_cap_name_set_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_name_set: NULL parameter check", mudir_drvmsg_reg_cap_name_set_test_null_param_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_name_set: Message type check", mudir_drvmsg_reg_cap_name_set_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_name_set: NULL message structure check", mudir_drvmsg_reg_cap_name_set_test_null_regmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_name_set: Index check - Lower bound", mudir_drvmsg_reg_cap_name_set_test_index_lowerbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_name_set: Index check - Upper bound", mudir_drvmsg_reg_cap_name_set_test_index_upperbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_name_set: NULL capabilities structure check", mudir_drvmsg_reg_cap_name_set_test_null_regcapmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_name_set: Normal operation", mudir_drvmsg_reg_cap_name_set_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_name_get: NULL check", mudir_drvmsg_reg_cap_name_get_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_name_get: Message type check", mudir_drvmsg_reg_cap_name_get_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_name_get: NULL message structure check", mudir_drvmsg_reg_cap_name_get_test_null_regmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_name_get: Index check - Lower bound", mudir_drvmsg_reg_cap_name_get_test_index_lowerbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_name_get: Index check - Upper bound", mudir_drvmsg_reg_cap_name_get_test_index_upperbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_name_get: NULL capabilities structure check", mudir_drvmsg_reg_cap_name_get_test_null_regcapmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_name_get: Normal operation - Empty name", mudir_drvmsg_reg_cap_name_get_test_base_empty_string);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_name_get: Normal operation", mudir_drvmsg_reg_cap_name_get_test_base);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_desc_set: NULL check", mudir_drvmsg_reg_cap_desc_set_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_desc_set: NULL parameter check", mudir_drvmsg_reg_cap_desc_set_test_null_param_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_desc_set: Message type check", mudir_drvmsg_reg_cap_desc_set_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_desc_set: NULL message structure check", mudir_drvmsg_reg_cap_desc_set_test_null_regmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_desc_set: Index check - Lower bound", mudir_drvmsg_reg_cap_desc_set_test_index_lowerbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_desc_set: Index check - Upper bound", mudir_drvmsg_reg_cap_desc_set_test_index_upperbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_desc_set: NULL capabilities structure check", mudir_drvmsg_reg_cap_desc_set_test_null_regcapmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_desc_set: Normal operation", mudir_drvmsg_reg_cap_desc_set_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_desc_get: NULL check", mudir_drvmsg_reg_cap_desc_get_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_desc_get: Message type check", mudir_drvmsg_reg_cap_desc_get_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_desc_get: NULL message structure check", mudir_drvmsg_reg_cap_desc_get_test_null_regmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_desc_get: Index check - Lower bound", mudir_drvmsg_reg_cap_desc_get_test_index_lowerbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_desc_get: Index check - Upper bound", mudir_drvmsg_reg_cap_desc_get_test_index_upperbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_desc_get: NULL capabilities structure check", mudir_drvmsg_reg_cap_desc_get_test_null_regcapmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_desc_get: Normal operation - Empty description", mudir_drvmsg_reg_cap_desc_get_test_base_empty_string);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_desc_get: Normal operation", mudir_drvmsg_reg_cap_desc_get_test_base);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_drvtype_set: NULL check", mudir_drvmsg_reg_cap_drvtype_set_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_drvtype_set: Invalid parameter lower bound check", mudir_drvmsg_reg_cap_drvtype_set_test_invalid_param_lbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_drvtype_set: Invalid parameter upper bound check", mudir_drvmsg_reg_cap_drvtype_set_test_invalid_param_ubound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_drvtype_set: Message type check", mudir_drvmsg_reg_cap_drvtype_set_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_drvtype_set: NULL message structure check", mudir_drvmsg_reg_cap_drvtype_set_test_null_regmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_drvtype_set: Index check - Lower bound", mudir_drvmsg_reg_cap_drvtype_set_test_index_lowerbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_drvtype_set: Index check - Upper bound", mudir_drvmsg_reg_cap_drvtype_set_test_index_upperbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_drvtype_set: NULL capabilities structure check", mudir_drvmsg_reg_cap_drvtype_set_test_null_regcapmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_drvtype_set: Normal operation", mudir_drvmsg_reg_cap_drvtype_set_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_drvtype_get: NULL check", mudir_drvmsg_reg_cap_drvtype_get_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_drvtype_get: Message type check", mudir_drvmsg_reg_cap_drvtype_get_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_drvtype_get: NULL message structure check", mudir_drvmsg_reg_cap_drvtype_get_test_null_regmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_drvtype_get: Index check - Lower bound", mudir_drvmsg_reg_cap_drvtype_get_test_index_lowerbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_drvtype_get: Index check - Upper bound", mudir_drvmsg_reg_cap_drvtype_get_test_index_upperbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_drvtype_get: NULL capabilities structure check", mudir_drvmsg_reg_cap_drvtype_get_test_null_regcapmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_drvtype_get: Normal operation - Empty description", mudir_drvmsg_reg_cap_drvtype_get_test_base_empty_message);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_drvtype_get: Normal operation", mudir_drvmsg_reg_cap_drvtype_get_test_base);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_returntype_set: NULL check", mudir_drvmsg_reg_cap_returntype_set_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_returntype_set: Invalid parameter lower bound check", mudir_drvmsg_reg_cap_returntype_set_test_invalid_param_lbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_returntype_set: Invalid parameter upper bound check", mudir_drvmsg_reg_cap_returntype_set_test_invalid_param_ubound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_returntype_set: Message type check", mudir_drvmsg_reg_cap_returntype_set_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_returntype_set: NULL message structure check", mudir_drvmsg_reg_cap_returntype_set_test_null_regmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_returntype_set: Index check - Lower bound", mudir_drvmsg_reg_cap_returntype_set_test_index_lowerbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_returntype_set: Index check - Upper bound", mudir_drvmsg_reg_cap_returntype_set_test_index_upperbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_returntype_set: NULL capabilities structure check", mudir_drvmsg_reg_cap_returntype_set_test_null_regcapmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_returntype_set: Normal operation", mudir_drvmsg_reg_cap_returntype_set_test_base_check);

  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_returntype_get: NULL check", mudir_drvmsg_reg_cap_returntype_get_test_null_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_returntype_get: Message type check", mudir_drvmsg_reg_cap_returntype_get_test_message_type_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_returntype_get: NULL message structure check", mudir_drvmsg_reg_cap_returntype_get_test_null_regmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_returntype_get: Index check - Lower bound", mudir_drvmsg_reg_cap_returntype_get_test_index_lowerbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_returntype_get: Index check - Upper bound", mudir_drvmsg_reg_cap_returntype_get_test_index_upperbound_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_returntype_get: NULL capabilities structure check", mudir_drvmsg_reg_cap_returntype_get_test_null_regcapmessage_check);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_returntype_get: Normal operation - Empty description", mudir_drvmsg_reg_cap_returntype_get_test_base_empty_message);
  MUDIR_TEST_ADD_TEST(pSuite, "mudir_drvmsg_reg_cap_returntype_get: Normal operation", mudir_drvmsg_reg_cap_returntype_get_test_base);

  return MUDIR_SUCCESS;
}

void mudir_drvmsg_reg_init_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_init(NULL), MUDIR_ERROR);
}

void mudir_drvmsg_reg_clean_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_clean(NULL), MUDIR_ERROR);
}

void mudir_drvmsg_reg_clean_test_null_msg_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_clean(message), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_clean_test_null_msg_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_name_set_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_name_set(NULL, NULL), MUDIR_ERROR);
}

void mudir_drvmsg_reg_name_set_test_null_param_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_name_set(message, NULL), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_name_set_null_param_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_name_set_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_name_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_name_set_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_name_set_test_null_regmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER;
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_name_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_name_set_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_name_set_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_name_set(message, testName), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strncmp(((struct mudir_driver_message_reg *)(message->message))->name_, testName, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_name_set_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_name_get_test_null_check()
{
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_name_get(NULL));
}

void mudir_drvmsg_reg_name_get_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_name_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_name_get_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_name_get_test_null_regmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER;
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_name_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_name_get_test_null_regmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_name_get_test_base_empty_string()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strnlen(mudir_drvmsg_reg_name_get(message), MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_name_get_test_base_empty_string"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_name_get_test_base()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_name_set(message, testName), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_reg_name_get(message), testName, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_name_get_test_base"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_snapname_set_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_snapname_set(NULL, NULL), MUDIR_ERROR);
}

void mudir_drvmsg_reg_snapname_set_test_null_param_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_snapname_set(message, NULL), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_snapname_set_null_param_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_snapname_set_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_snapname_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_snapname_set_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_snapname_set_test_null_regmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER;
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_snapname_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_snapname_set_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_snapname_set_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_snapname_set(message, testName), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strncmp(((struct mudir_driver_message_reg *)(message->message))->snap_name_, testName, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_snapname_set_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_snapname_get_test_null_check()
{
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_snapname_get(NULL));
}

void mudir_drvmsg_reg_snapname_get_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_snapname_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_snapname_get_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_snapname_get_test_null_regmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER;
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_snapname_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_snapname_get_test_null_regmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_snapname_get_test_base_empty_string()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strnlen(mudir_drvmsg_reg_snapname_get(message), MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_snapname_get_test_base_empty_string"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_snapname_get_test_base()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_snapname_set(message, testName), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_reg_snapname_get(message), testName, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_snapname_get_test_base"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_snapversion_set_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_snapversion_set(NULL, NULL), MUDIR_ERROR);
}

void mudir_drvmsg_reg_snapversion_set_test_null_param_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_snapversion_set(message, NULL), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_snapversion_set_null_param_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_snapversion_set_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_snapversion_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_snapversion_set_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_snapversion_set_test_null_regmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER;
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_snapversion_set(message, "Test Name"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_snapversion_set_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_snapversion_set_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_snapversion_set(message, testName), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strncmp(((struct mudir_driver_message_reg *)(message->message))->snap_version_, testName, MUDIR_MAX_VER_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_snapversion_set_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_snapversion_get_test_null_check()
{
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_snapversion_get(NULL));
}

void mudir_drvmsg_reg_snapversion_get_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_snapversion_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_snapversion_get_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_snapversion_get_test_null_regmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER;
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_snapversion_get(message));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_snapversion_get_test_null_regmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_snapversion_get_test_base_empty_string()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strnlen(mudir_drvmsg_reg_snapversion_get(message), MUDIR_MAX_VER_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_snapversion_get_test_base_empty_string"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_snapversion_get_test_base()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  const char testName[] = "testName";

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_snapversion_set(message, testName), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_reg_snapversion_get(message), testName, MUDIR_MAX_VER_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_snapversion_get_test_base"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_count_set_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_set(NULL, 1), MUDIR_ERROR);
}

void mudir_drvmsg_reg_cap_count_set_test_zero_count_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_set(message, 0), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_count_set_test_zero_count_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_count_set_test_negative_count_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_set(message, -1), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_count_set_test_negative_count_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_count_set_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_count_set_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_count_set_test_null_regmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER;
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_count_set_test_null_regmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_count_set_test_base()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_reg* regmessage;
  struct mudir_driver_message_reg_cap *regcapmsg;

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  regmessage = (struct mudir_driver_message_reg*)(message->message);
  CU_ASSERT_PTR_NOT_NULL_FATAL(regmessage);
  regcapmsg = (struct mudir_driver_message_reg_cap *) regmessage->capabilities_;
  CU_ASSERT_PTR_NOT_NULL_FATAL(regcapmsg);
  CU_ASSERT_EQUAL(regcapmsg[0].driver_type_, MUDIR_DRIVER_TYPE_UNKNOWN);
  CU_ASSERT_EQUAL(regcapmsg[0].return_type_, MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN);
  CU_ASSERT_EQUAL(strnlen(regcapmsg[0].name_, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL(strnlen(regcapmsg[0].desc_, MUDIR_MAX_DESC_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_count_set_test_base"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_count_set_test_base_realloc_check_increase()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_reg* regmessage;
  struct mudir_driver_message_reg_cap *regcapmsg;

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  regmessage = (struct mudir_driver_message_reg*)(message->message);
  CU_ASSERT_PTR_NOT_NULL_FATAL(regmessage);
  regcapmsg = (struct mudir_driver_message_reg_cap *) regmessage->capabilities_;
  CU_ASSERT_PTR_NOT_NULL_FATAL(regcapmsg);
  regcapmsg[0].driver_type_ = MUDIR_DRIVER_TYPE_SENSOR;
  regcapmsg[0].return_type_ = MUDIR_DRIVERMSG_RETURN_TYPE_BOOL;
  strncpy(regcapmsg[0].name_, "ABCD", MUDIR_MAX_NAME_LEN);
  strncpy(regcapmsg[0].desc_, "DESC01", MUDIR_MAX_DESC_LEN);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_set(message, 2), MUDIR_SUCCESS);
  regcapmsg = (struct mudir_driver_message_reg_cap *) regmessage->capabilities_;
  CU_ASSERT_EQUAL(regcapmsg[0].driver_type_, MUDIR_DRIVER_TYPE_SENSOR);
  CU_ASSERT_EQUAL(regcapmsg[0].return_type_, MUDIR_DRIVERMSG_RETURN_TYPE_BOOL);
  CU_ASSERT_EQUAL(strnlen(regcapmsg[0].name_, MUDIR_MAX_NAME_LEN), 4);
  CU_ASSERT_EQUAL(strncmp(regcapmsg[0].name_, "ABCD", MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL(strnlen(regcapmsg[0].desc_, MUDIR_MAX_DESC_LEN), 6);
  CU_ASSERT_EQUAL(strncmp(regcapmsg[0].desc_, "DESC01", MUDIR_MAX_DESC_LEN), 0);
  CU_ASSERT_EQUAL(regcapmsg[1].driver_type_, MUDIR_DRIVER_TYPE_UNKNOWN);
  CU_ASSERT_EQUAL(regcapmsg[1].return_type_, MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN);
  CU_ASSERT_EQUAL(strnlen(regcapmsg[1].name_, MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL(strnlen(regcapmsg[1].desc_, MUDIR_MAX_DESC_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS); 
  CU_ASSERT_PTR_NULL_FATAL(message); 

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_count_set_test_base_realloc_check_increase"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_count_set_test_base_realloc_check_decrease()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_reg* regmessage;
  struct mudir_driver_message_reg_cap *regcapmsg;

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_set(message, 2), MUDIR_SUCCESS);
  regmessage = (struct mudir_driver_message_reg*)(message->message);
  CU_ASSERT_PTR_NOT_NULL_FATAL(regmessage);
  regcapmsg = (struct mudir_driver_message_reg_cap *) regmessage->capabilities_;
  CU_ASSERT_PTR_NOT_NULL_FATAL(regcapmsg);
  regcapmsg[0].driver_type_ = MUDIR_DRIVER_TYPE_SENSOR;
  regcapmsg[0].return_type_ = MUDIR_DRIVERMSG_RETURN_TYPE_BOOL;
  strncpy(regcapmsg[0].name_, "ABCD", MUDIR_MAX_NAME_LEN);
  strncpy(regcapmsg[0].desc_, "DESC01", MUDIR_MAX_DESC_LEN);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  regcapmsg = (struct mudir_driver_message_reg_cap *) regmessage->capabilities_;
  CU_ASSERT_EQUAL(regcapmsg[0].driver_type_, MUDIR_DRIVER_TYPE_SENSOR);
  CU_ASSERT_EQUAL(regcapmsg[0].return_type_, MUDIR_DRIVERMSG_RETURN_TYPE_BOOL);
  CU_ASSERT_EQUAL(strnlen(regcapmsg[0].name_, MUDIR_MAX_NAME_LEN), 4);
  CU_ASSERT_EQUAL(strncmp(regcapmsg[0].name_, "ABCD", MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL(strnlen(regcapmsg[0].desc_, MUDIR_MAX_DESC_LEN), 6);
  CU_ASSERT_EQUAL(strncmp(regcapmsg[0].desc_, "DESC01", MUDIR_MAX_DESC_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_count_set_test_base_realloc_check_decrease"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_count_get_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_get(NULL), -1);
}

void mudir_drvmsg_reg_cap_count_get_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_get(message), -1);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_count_get_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_count_get_test_null_regmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER;
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_get(message), -1);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_count_get_test_null_regmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_count_get_test_base_empty_message()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_get(message), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_count_get_test_base_empty_message"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_count_get_test_base()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 2), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_get(message), 2);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_count_get_test_base"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_name_set_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_name_set(NULL, 1, "NULL"), MUDIR_ERROR);
}

void mudir_drvmsg_reg_cap_name_set_test_null_param_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_name_set(message, 0, NULL), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_name_set_test_null_param_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_name_set_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_name_set(message, 1, "NULL"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_name_set_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_name_set_test_null_regmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER;
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_name_set(message, 1, "NULL"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_name_set_test_null_regmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_name_set_test_index_lowerbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_name_set(message, -1, "NULL"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_name_set_test_index_lowerbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_name_set_test_index_upperbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_name_set(message, 1, "NULL"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_name_set_test_index_upperbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_name_set_test_null_regcapmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_reg *regmessage;

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  regmessage = (struct mudir_driver_message_reg*)(message->message);
  regmessage->num_capabilities_ = 1;
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_name_set(message, 0, "NULL"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_name_set_test_null_regcapmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_name_set_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_reg* regmessage;
  struct mudir_driver_message_reg_cap *regcapmsg;

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_name_set(message, 0, "ABCD"), MUDIR_SUCCESS);
  regmessage = (struct mudir_driver_message_reg*)(message->message);
  CU_ASSERT_PTR_NOT_NULL_FATAL(regmessage);
  regcapmsg = (struct mudir_driver_message_reg_cap *) regmessage->capabilities_;
  CU_ASSERT_PTR_NOT_NULL_FATAL(regcapmsg);
  CU_ASSERT_EQUAL(strncmp(regcapmsg[0].name_, "ABCD", MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_name_set_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_name_get_test_null_check()
{
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_cap_name_get(NULL, 0));
}

void mudir_drvmsg_reg_cap_name_get_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_cap_name_get(message, 0));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_name_get_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_name_get_test_null_regmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER;
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_cap_name_get(message, 0));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_name_get_test_null_regmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_name_get_test_index_lowerbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_cap_name_get(message, -1));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_name_get_test_index_lowerbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_name_get_test_index_upperbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_cap_name_get(message, 1));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_name_get_test_index_upperbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_name_get_test_null_regcapmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_reg *regmessage;

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  regmessage = (struct mudir_driver_message_reg*)(message->message);
  regmessage->num_capabilities_ = 1;
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_cap_name_get(message, 0));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_name_get_test_null_regcapmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_name_get_test_base_empty_string()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strnlen(mudir_drvmsg_reg_cap_name_get(message, 0), MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_name_get_test_base_empty_string"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_name_get_test_base()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_name_set(message, 0, "ABCD"), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_reg_cap_name_get(message, 0), "ABCD", MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_name_get_test_base"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_desc_set_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_desc_set(NULL, 1, "NULL"), MUDIR_ERROR);
}

void mudir_drvmsg_reg_cap_desc_set_test_null_param_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_desc_set(message, 0, NULL), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_desc_set_test_null_param_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_desc_set_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_desc_set(message, 1, "NULL"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_desc_set_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_desc_set_test_null_regmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER;
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_desc_set(message, 1, "NULL"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_desc_set_test_null_regmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_desc_set_test_index_lowerbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_desc_set(message, -1, "NULL"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_desc_set_test_index_lowerbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_desc_set_test_index_upperbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_desc_set(message, 1, "NULL"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_desc_set_test_index_upperbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_desc_set_test_null_regcapmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_reg *regmessage;

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  regmessage = (struct mudir_driver_message_reg*)(message->message);
  regmessage->num_capabilities_ = 1;
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_desc_set(message, 0, "NULL"), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_desc_set_test_null_regcapmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_desc_set_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_reg* regmessage;
  struct mudir_driver_message_reg_cap *regcapmsg;

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_desc_set(message, 0, "ABCD"), MUDIR_SUCCESS);
  regmessage = (struct mudir_driver_message_reg*)(message->message);
  CU_ASSERT_PTR_NOT_NULL_FATAL(regmessage);
  regcapmsg = (struct mudir_driver_message_reg_cap *) regmessage->capabilities_;
  CU_ASSERT_PTR_NOT_NULL_FATAL(regcapmsg);
  CU_ASSERT_EQUAL(strncmp(regcapmsg[0].desc_, "ABCD", MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_desc_set_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_desc_get_test_null_check()
{
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_cap_desc_get(NULL, 0));
}

void mudir_drvmsg_reg_cap_desc_get_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_cap_desc_get(message, 0));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_desc_get_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_desc_get_test_null_regmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER;
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_cap_desc_get(message, 0));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_desc_get_test_null_regmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_desc_get_test_index_lowerbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_cap_desc_get(message, -1));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_desc_get_test_index_lowerbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_desc_get_test_index_upperbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_cap_desc_get(message, 1));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_desc_get_test_index_upperbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_desc_get_test_null_regcapmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_reg *regmessage;

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  regmessage = (struct mudir_driver_message_reg*)(message->message);
  regmessage->num_capabilities_ = 1;
  CU_ASSERT_PTR_NULL(mudir_drvmsg_reg_cap_desc_get(message, 0));
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_desc_get_test_null_regcapmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_desc_get_test_base_empty_string()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strnlen(mudir_drvmsg_reg_cap_desc_get(message, 0), MUDIR_MAX_NAME_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_desc_get_test_base_empty_string"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_desc_get_test_base()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_desc_set(message, 0, "ABCD"), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(strncmp(mudir_drvmsg_reg_cap_desc_get(message, 0), "ABCD", MUDIR_MAX_DESC_LEN), 0);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_desc_get_test_base"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_drvtype_set_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_drvtype_set(NULL, 1, MUDIR_DRIVER_TYPE_UNKNOWN), MUDIR_ERROR);
}

void mudir_drvmsg_reg_cap_drvtype_set_test_invalid_param_lbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_drvtype_set(message, 0, -1), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_drvtype_set_test_invalid_param_lbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_drvtype_set_test_invalid_param_ubound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_drvtype_set(message, 0, 4), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_drvtype_set_test_invalid_param_ubound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_drvtype_set_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_drvtype_set(message, 1, MUDIR_DRIVER_TYPE_UNKNOWN), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_drvtype_set_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_drvtype_set_test_null_regmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER;
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_drvtype_set(message, 1, MUDIR_DRIVER_TYPE_UNKNOWN), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_drvtype_set_test_null_regmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_drvtype_set_test_index_lowerbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_drvtype_set(message, -1, MUDIR_DRIVER_TYPE_UNKNOWN), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_drvtype_set_test_index_lowerbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_drvtype_set_test_index_upperbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_drvtype_set(message, 1, MUDIR_DRIVER_TYPE_UNKNOWN), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_drvtype_set_test_index_upperbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_drvtype_set_test_null_regcapmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_reg *regmessage;

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  regmessage = (struct mudir_driver_message_reg*)(message->message);
  regmessage->num_capabilities_ = 1;
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_drvtype_set(message, 0, MUDIR_DRIVER_TYPE_UNKNOWN), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_drvtype_set_test_null_regcapmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_drvtype_set_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_reg* regmessage;
  struct mudir_driver_message_reg_cap *regcapmsg;

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_drvtype_set(message, 0, MUDIR_DRIVER_TYPE_SENSOR), MUDIR_SUCCESS);
  regmessage = (struct mudir_driver_message_reg*)(message->message);
  CU_ASSERT_PTR_NOT_NULL_FATAL(regmessage);
  regcapmsg = (struct mudir_driver_message_reg_cap *) regmessage->capabilities_;
  CU_ASSERT_PTR_NOT_NULL_FATAL(regcapmsg);
  CU_ASSERT_EQUAL(regcapmsg[0].driver_type_, MUDIR_DRIVER_TYPE_SENSOR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_drvtype_set_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_drvtype_get_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_drvtype_get(NULL, 0), MUDIR_DRIVER_TYPE_UNKNOWN);
}

void mudir_drvmsg_reg_cap_drvtype_get_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_drvtype_get(message, 0), MUDIR_DRIVER_TYPE_UNKNOWN);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_drvtype_get_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_drvtype_get_test_null_regmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER;
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_drvtype_get(message, 0), MUDIR_DRIVER_TYPE_UNKNOWN);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_drvtype_get_test_null_regmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_drvtype_get_test_index_lowerbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_drvtype_get(message, -1), MUDIR_DRIVER_TYPE_UNKNOWN);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_drvtype_get_test_index_lowerbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_drvtype_get_test_index_upperbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_drvtype_get(message, 1), MUDIR_DRIVER_TYPE_UNKNOWN);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_drvtype_get_test_index_upperbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_drvtype_get_test_null_regcapmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_reg *regmessage;

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  regmessage = (struct mudir_driver_message_reg*)(message->message);
  regmessage->num_capabilities_ = 1;
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_drvtype_get(message, 0), MUDIR_DRIVER_TYPE_UNKNOWN);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_drvtype_get_test_null_regcapmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_drvtype_get_test_base_empty_message()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_drvtype_get(message, 0), MUDIR_DRIVER_TYPE_UNKNOWN);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_drvtype_get_test_base_empty_message"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_drvtype_get_test_base()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_drvtype_set(message, 0, MUDIR_DRIVER_TYPE_SENSOR), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_drvtype_get(message, 0), MUDIR_DRIVER_TYPE_SENSOR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_drvtype_get_test_base"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_returntype_set_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_returntype_set(NULL, 1, MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN), MUDIR_ERROR);
}

void mudir_drvmsg_reg_cap_returntype_set_test_invalid_param_lbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_returntype_set(message, 0, -1), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_returntype_set_test_invalid_param_lbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_returntype_set_test_invalid_param_ubound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_returntype_set(message, 0, 6), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_returntype_set_test_invalid_param_ubound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_returntype_set_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_returntype_set(message, 1, MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_returntype_set_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_returntype_set_test_null_regmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER;
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_returntype_set(message, 1, MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_returntype_set_test_null_regmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_returntype_set_test_index_lowerbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_returntype_set(message, -1, MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_returntype_set_test_index_lowerbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_returntype_set_test_index_upperbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_returntype_set(message, 1, MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_returntype_set_test_index_upperbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_returntype_set_test_null_regcapmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_reg *regmessage;

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  regmessage = (struct mudir_driver_message_reg*)(message->message);
  regmessage->num_capabilities_ = 1;
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_returntype_set(message, 0, MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN), MUDIR_ERROR);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_returntype_set_test_null_regcapmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_returntype_set_test_base_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_reg* regmessage;
  struct mudir_driver_message_reg_cap *regcapmsg;

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_returntype_set(message, 0, MUDIR_DRIVERMSG_RETURN_TYPE_BOOL), MUDIR_SUCCESS);
  regmessage = (struct mudir_driver_message_reg*)(message->message);
  CU_ASSERT_PTR_NOT_NULL_FATAL(regmessage);
  regcapmsg = (struct mudir_driver_message_reg_cap *) regmessage->capabilities_;
  CU_ASSERT_PTR_NOT_NULL_FATAL(regcapmsg);
  CU_ASSERT_EQUAL(regcapmsg[0].return_type_, MUDIR_DRIVERMSG_RETURN_TYPE_BOOL);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_returntype_set_test_base_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_returntype_get_test_null_check()
{
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_returntype_get(NULL, 0), MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN);
}

void mudir_drvmsg_reg_cap_returntype_get_test_message_type_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_returntype_get(message, 0), MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_returntype_get_test_message_type_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_returntype_get_test_null_regmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER;
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_returntype_get(message, 0), MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_returntype_get_test_null_regmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_returntype_get_test_index_lowerbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_returntype_get(message, -1), MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_returntype_get_test_index_lowerbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_returntype_get_test_index_upperbound_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_returntype_get(message, 1), MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_returntype_get_test_index_upperbound_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_returntype_get_test_null_regcapmessage_check()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];
  struct mudir_driver_message_reg *regmessage;

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  regmessage = (struct mudir_driver_message_reg*)(message->message);
  regmessage->num_capabilities_ = 1;
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_returntype_get(message, 0), MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_returntype_get_test_null_regcapmessage_check"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_returntype_get_test_base_empty_message()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_returntype_get(message, 0), MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_returntype_get_test_base_empty_message"), MUDIR_SUCCESS);
}

void mudir_drvmsg_reg_cap_returntype_get_test_base()
{
  mudir_driver_message message;
  char mTraceFile[PATH_MAX];

  generateTempTraceFileName(mTraceFile);
  mtrace();
  
  message = NULL;

  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_initialize(&message, MUDIR_DRIVERMSG_VERSION_1_0), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NOT_NULL_FATAL(message);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_messagetype_set(message, MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_count_set(message, 1), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_reg_cap_returntype_set(message, 0, MUDIR_DRIVERMSG_RETURN_TYPE_BOOL), MUDIR_SUCCESS);
  CU_ASSERT_EQUAL(mudir_drvmsg_reg_cap_returntype_get(message, 0), MUDIR_DRIVERMSG_RETURN_TYPE_BOOL);
  CU_ASSERT_EQUAL_FATAL(mudir_drvmsg_free(&message), MUDIR_SUCCESS);
  CU_ASSERT_PTR_NULL_FATAL(message);

  muntrace();
  CU_ASSERT_EQUAL(confirmNoMemoryLeakage(mTraceFile, "mudir_drvmsg_reg_cap_returntype_get_test_base"), MUDIR_SUCCESS);
}
