#ifndef   __MSGHANDLERDRVACK_TEST_H__
#define   __MSGHANDLERDRVACK_TEST_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Test Suite Initializer */ 
int msghandlerdrvack_test_init();

void mudir_drvmsg_ack_init_test_null_check();

void mudir_drvmsg_ack_clean_test_null_check();
void mudir_drvmsg_ack_clean_test_null_msg_check();

void mudir_drvmsg_ack_name_set_test_null_check();
void mudir_drvmsg_ack_name_set_test_null_param_check();
void mudir_drvmsg_ack_name_set_test_message_type_check();
void mudir_drvmsg_ack_name_set_test_null_ackmessage_check();
void mudir_drvmsg_ack_name_set_test_base_check();

void mudir_drvmsg_ack_name_get_test_null_check();
void mudir_drvmsg_ack_name_get_test_message_type_check();
void mudir_drvmsg_ack_name_get_test_null_ackmessage_check();
void mudir_drvmsg_ack_name_get_test_base_empty_string_check();
void mudir_drvmsg_ack_name_get_test_base_check();

void mudir_drvmsg_ack_inaddr_set_test_null_check();
void mudir_drvmsg_ack_inaddr_set_test_null_param_check();
void mudir_drvmsg_ack_inaddr_set_test_message_type_check();
void mudir_drvmsg_ack_inaddr_set_test_null_ackmessage_check();
void mudir_drvmsg_ack_inaddr_set_test_base_check();

void mudir_drvmsg_ack_inaddr_get_test_null_check();
void mudir_drvmsg_ack_inaddr_get_test_message_type_check();
void mudir_drvmsg_ack_inaddr_get_test_null_ackmessage_check();
void mudir_drvmsg_ack_inaddr_get_test_base_empty_string_check();
void mudir_drvmsg_ack_inaddr_get_test_base_check();

void mudir_drvmsg_ack_outaddr_set_test_null_check();
void mudir_drvmsg_ack_outaddr_set_test_null_param_check();
void mudir_drvmsg_ack_outaddr_set_test_message_type_check();
void mudir_drvmsg_ack_outaddr_set_test_null_ackmessage_check();
void mudir_drvmsg_ack_outaddr_set_test_base_check();

void mudir_drvmsg_ack_outaddr_get_test_null_check();
void mudir_drvmsg_ack_outaddr_get_test_message_type_check();
void mudir_drvmsg_ack_outaddr_get_test_null_ackmessage_check();
void mudir_drvmsg_ack_outaddr_get_test_base_empty_string_check();
void mudir_drvmsg_ack_outaddr_get_test_base_check();

void mudir_drvmsg_ack_mode_set_test_null_check();
void mudir_drvmsg_ack_mode_set_test_invalid_param_lbound_check();
void mudir_drvmsg_ack_mode_set_test_invalid_param_ubound_check();
void mudir_drvmsg_ack_mode_set_test_message_type_check();
void mudir_drvmsg_ack_mode_set_test_null_ackmessage_check();
void mudir_drvmsg_ack_mode_set_test_base_check();

void mudir_drvmsg_ack_mode_get_test_null_check();
void mudir_drvmsg_ack_mode_get_test_message_type_check();
void mudir_drvmsg_ack_mode_get_test_null_ackmessage_check();
void mudir_drvmsg_ack_mode_get_test_base_empty_message();
void mudir_drvmsg_ack_mode_get_test_base();

#ifdef __cplusplus
}
#endif

#endif /* __MSGHANDLERDRVACK_TEST_H__ */