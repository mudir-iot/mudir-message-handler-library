#ifndef   __MSGHANDLERDRVREG_TEST_H__
#define   __MSGHANDLERDRVREG_TEST_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Test Suite Initializer */ 
int msghandlerdrvreg_test_init();

void mudir_drvmsg_reg_init_test_null_check();

void mudir_drvmsg_reg_clean_test_null_check();
void mudir_drvmsg_reg_clean_test_null_msg_check();

void mudir_drvmsg_reg_name_set_test_null_check();
void mudir_drvmsg_reg_name_set_test_null_param_check();
void mudir_drvmsg_reg_name_set_test_message_type_check();
void mudir_drvmsg_reg_name_set_test_null_regmessage_check();
void mudir_drvmsg_reg_name_set_test_base_check();

void mudir_drvmsg_reg_name_get_test_null_check();
void mudir_drvmsg_reg_name_get_test_message_type_check();
void mudir_drvmsg_reg_name_get_test_null_regmessage_check();
void mudir_drvmsg_reg_name_get_test_base_empty_string();
void mudir_drvmsg_reg_name_get_test_base();

void mudir_drvmsg_reg_snapname_set_test_null_check();
void mudir_drvmsg_reg_snapname_set_test_null_param_check();
void mudir_drvmsg_reg_snapname_set_test_message_type_check();
void mudir_drvmsg_reg_snapname_set_test_null_regmessage_check();
void mudir_drvmsg_reg_snapname_set_test_base_check();

void mudir_drvmsg_reg_snapname_get_test_null_check();
void mudir_drvmsg_reg_snapname_get_test_message_type_check();
void mudir_drvmsg_reg_snapname_get_test_null_regmessage_check();
void mudir_drvmsg_reg_snapname_get_test_base_empty_string();
void mudir_drvmsg_reg_snapname_get_test_base();

void mudir_drvmsg_reg_snapversion_set_test_null_check();
void mudir_drvmsg_reg_snapversion_set_test_null_param_check();
void mudir_drvmsg_reg_snapversion_set_test_message_type_check();
void mudir_drvmsg_reg_snapversion_set_test_null_regmessage_check();
void mudir_drvmsg_reg_snapversion_set_test_base_check();

void mudir_drvmsg_reg_snapversion_get_test_null_check();
void mudir_drvmsg_reg_snapversion_get_test_message_type_check();
void mudir_drvmsg_reg_snapversion_get_test_null_regmessage_check();
void mudir_drvmsg_reg_snapversion_get_test_base_empty_string();
void mudir_drvmsg_reg_snapversion_get_test_base();

void mudir_drvmsg_reg_cap_count_set_test_null_check();
void mudir_drvmsg_reg_cap_count_set_test_zero_count_check();
void mudir_drvmsg_reg_cap_count_set_test_negative_count_check();
void mudir_drvmsg_reg_cap_count_set_test_message_type_check();
void mudir_drvmsg_reg_cap_count_set_test_null_regmessage_check();
void mudir_drvmsg_reg_cap_count_set_test_base();
void mudir_drvmsg_reg_cap_count_set_test_base_realloc_check_increase();
void mudir_drvmsg_reg_cap_count_set_test_base_realloc_check_decrease();

void mudir_drvmsg_reg_cap_count_get_test_null_check();
void mudir_drvmsg_reg_cap_count_get_test_message_type_check();
void mudir_drvmsg_reg_cap_count_get_test_null_regmessage_check();
void mudir_drvmsg_reg_cap_count_get_test_base_empty_message();
void mudir_drvmsg_reg_cap_count_get_test_base();

void mudir_drvmsg_reg_cap_name_set_test_null_check();
void mudir_drvmsg_reg_cap_name_set_test_null_param_check();
void mudir_drvmsg_reg_cap_name_set_test_message_type_check();
void mudir_drvmsg_reg_cap_name_set_test_null_regmessage_check();
void mudir_drvmsg_reg_cap_name_set_test_index_lowerbound_check();
void mudir_drvmsg_reg_cap_name_set_test_index_upperbound_check();
void mudir_drvmsg_reg_cap_name_set_test_null_regcapmessage_check();
void mudir_drvmsg_reg_cap_name_set_test_base_check();

void mudir_drvmsg_reg_cap_name_get_test_null_check();
void mudir_drvmsg_reg_cap_name_get_test_message_type_check();
void mudir_drvmsg_reg_cap_name_get_test_null_regmessage_check();
void mudir_drvmsg_reg_cap_name_get_test_index_lowerbound_check();
void mudir_drvmsg_reg_cap_name_get_test_index_upperbound_check();
void mudir_drvmsg_reg_cap_name_get_test_null_regcapmessage_check();
void mudir_drvmsg_reg_cap_name_get_test_base_empty_string();
void mudir_drvmsg_reg_cap_name_get_test_base();

void mudir_drvmsg_reg_cap_desc_set_test_null_check();
void mudir_drvmsg_reg_cap_desc_set_test_null_param_check();
void mudir_drvmsg_reg_cap_desc_set_test_message_type_check();
void mudir_drvmsg_reg_cap_desc_set_test_null_regmessage_check();
void mudir_drvmsg_reg_cap_desc_set_test_index_lowerbound_check();
void mudir_drvmsg_reg_cap_desc_set_test_index_upperbound_check();
void mudir_drvmsg_reg_cap_desc_set_test_null_regcapmessage_check();
void mudir_drvmsg_reg_cap_desc_set_test_base_check();

void mudir_drvmsg_reg_cap_desc_get_test_null_check();
void mudir_drvmsg_reg_cap_desc_get_test_message_type_check();
void mudir_drvmsg_reg_cap_desc_get_test_null_regmessage_check();
void mudir_drvmsg_reg_cap_desc_get_test_index_lowerbound_check();
void mudir_drvmsg_reg_cap_desc_get_test_index_upperbound_check();
void mudir_drvmsg_reg_cap_desc_get_test_null_regcapmessage_check();
void mudir_drvmsg_reg_cap_desc_get_test_base_empty_string();
void mudir_drvmsg_reg_cap_desc_get_test_base();

void mudir_drvmsg_reg_cap_drvtype_set_test_null_check();
void mudir_drvmsg_reg_cap_drvtype_set_test_invalid_param_lbound_check();
void mudir_drvmsg_reg_cap_drvtype_set_test_invalid_param_ubound_check();
void mudir_drvmsg_reg_cap_drvtype_set_test_message_type_check();
void mudir_drvmsg_reg_cap_drvtype_set_test_null_regmessage_check();
void mudir_drvmsg_reg_cap_drvtype_set_test_index_lowerbound_check();
void mudir_drvmsg_reg_cap_drvtype_set_test_index_upperbound_check();
void mudir_drvmsg_reg_cap_drvtype_set_test_null_regcapmessage_check();
void mudir_drvmsg_reg_cap_drvtype_set_test_base_check();

void mudir_drvmsg_reg_cap_drvtype_get_test_null_check();
void mudir_drvmsg_reg_cap_drvtype_get_test_message_type_check();
void mudir_drvmsg_reg_cap_drvtype_get_test_null_regmessage_check();
void mudir_drvmsg_reg_cap_drvtype_get_test_index_lowerbound_check();
void mudir_drvmsg_reg_cap_drvtype_get_test_index_upperbound_check();
void mudir_drvmsg_reg_cap_drvtype_get_test_null_regcapmessage_check();
void mudir_drvmsg_reg_cap_drvtype_get_test_base_empty_message();
void mudir_drvmsg_reg_cap_drvtype_get_test_base();

void mudir_drvmsg_reg_cap_returntype_set_test_null_check();
void mudir_drvmsg_reg_cap_returntype_set_test_invalid_param_lbound_check();
void mudir_drvmsg_reg_cap_returntype_set_test_invalid_param_ubound_check();
void mudir_drvmsg_reg_cap_returntype_set_test_message_type_check();
void mudir_drvmsg_reg_cap_returntype_set_test_null_regmessage_check();
void mudir_drvmsg_reg_cap_returntype_set_test_index_lowerbound_check();
void mudir_drvmsg_reg_cap_returntype_set_test_index_upperbound_check();
void mudir_drvmsg_reg_cap_returntype_set_test_null_regcapmessage_check();
void mudir_drvmsg_reg_cap_returntype_set_test_base_check();

void mudir_drvmsg_reg_cap_returntype_get_test_null_check();
void mudir_drvmsg_reg_cap_returntype_get_test_message_type_check();
void mudir_drvmsg_reg_cap_returntype_get_test_null_regmessage_check();
void mudir_drvmsg_reg_cap_returntype_get_test_index_lowerbound_check();
void mudir_drvmsg_reg_cap_returntype_get_test_index_upperbound_check();
void mudir_drvmsg_reg_cap_returntype_get_test_null_regcapmessage_check();
void mudir_drvmsg_reg_cap_returntype_get_test_base_empty_message();
void mudir_drvmsg_reg_cap_returntype_get_test_base();

#ifdef __cplusplus
}
#endif

#endif /* __MSGHANDLERDRVREG_TEST_H__ */