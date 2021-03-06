#ifndef   __MSGHANDLERDRVREP_TEST_H__
#define   __MSGHANDLERDRVREP_TEST_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Test Suite Initializer */ 
int msghandlerdrvrep_test_init();

void mudir_drvmsg_rep_init_test_null_check();

void mudir_drvmsg_rep_clean_test_null_check();
void mudir_drvmsg_rep_clean_test_null_msg_check();

void mudir_drvmsg_reply_driver_name_set_test_null_check();
void mudir_drvmsg_reply_driver_name_set_test_null_param_check();
void mudir_drvmsg_reply_driver_name_set_test_message_type_check();
void mudir_drvmsg_reply_driver_name_set_test_null_ackmessage_check();
void mudir_drvmsg_reply_driver_name_set_test_base_check();

void mudir_drvmsg_reply_driver_name_get_test_null_check();
void mudir_drvmsg_reply_driver_name_get_test_message_type_check();
void mudir_drvmsg_reply_driver_name_get_test_null_ackmessage_check();
void mudir_drvmsg_reply_driver_name_get_test_base_empty_string_check();
void mudir_drvmsg_reply_driver_name_get_test_base_check();

void mudir_drvmsg_reply_device_name_set_test_null_check();
void mudir_drvmsg_reply_device_name_set_test_null_param_check();
void mudir_drvmsg_reply_device_name_set_test_message_type_check();
void mudir_drvmsg_reply_device_name_set_test_null_ackmessage_check();
void mudir_drvmsg_reply_device_name_set_test_base_check();

void mudir_drvmsg_reply_device_name_get_test_null_check();
void mudir_drvmsg_reply_device_name_get_test_message_type_check();
void mudir_drvmsg_reply_device_name_get_test_null_ackmessage_check();
void mudir_drvmsg_reply_device_name_get_test_base_empty_string_check();
void mudir_drvmsg_reply_device_name_get_test_base_check();

void mudir_drvmsg_reply_value_set_test_null_check();
void mudir_drvmsg_reply_value_set_test_null_param_check();
void mudir_drvmsg_reply_value_set_test_message_type_check();
void mudir_drvmsg_reply_value_set_test_null_ackmessage_check();
void mudir_drvmsg_reply_value_set_test_base_check();

void mudir_drvmsg_reply_value_get_test_null_check();
void mudir_drvmsg_reply_value_get_test_message_type_check();
void mudir_drvmsg_reply_value_get_test_null_ackmessage_check();
void mudir_drvmsg_reply_value_get_test_base_empty_string_check();
void mudir_drvmsg_reply_value_get_test_base_check();

void mudir_drvmsg_reply_unit_set_test_null_check();
void mudir_drvmsg_reply_unit_set_test_null_param_check();
void mudir_drvmsg_reply_unit_set_test_message_type_check();
void mudir_drvmsg_reply_unit_set_test_null_ackmessage_check();
void mudir_drvmsg_reply_unit_set_test_base_check();

void mudir_drvmsg_reply_unit_get_test_null_check();
void mudir_drvmsg_reply_unit_get_test_message_type_check();
void mudir_drvmsg_reply_unit_get_test_null_ackmessage_check();
void mudir_drvmsg_reply_unit_get_test_base_empty_string_check();
void mudir_drvmsg_reply_unit_get_test_base_check();

#ifdef __cplusplus
}
#endif

#endif /* __MSGHANDLERDRVREP_TEST_H__ */