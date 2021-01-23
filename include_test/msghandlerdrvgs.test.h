
#ifndef   __MSGHANDLERDRVGS_TEST_H__
#define   __MSGHANDLERDRVGS_TEST_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Test Suite Initializer */ 
int msghandlerdrvgs_test_init();

void mudir_drvmsg_version_get_test_nullcheck();
void mudir_drvmsg_version_get_test_normal();

void mudir_drvmsg_errorcode_set_test_nullcheck();
void mudir_drvmsg_errorcode_set_test_lowerlimit();
void mudir_drvmsg_errorcode_set_test_upperlimit();
void mudir_drvmsg_errorcode_set_test_normal();

void mudir_drvmsg_errorcode_get_test_nullcheck();
void mudir_drvmsg_errorcode_get_test_normal();

void mudir_drvmsg_errordesc_set_test_nullcheck();
void mudir_drvmsg_errordesc_set_test_nullmessagecheck();
void mudir_drvmsg_errordesc_set_test_standarderrorcheck();
void mudir_drvmsg_errordesc_set_test_normal();
void mudir_drvmsg_errordesc_set_test_longerrdesccheck();

void mudir_drvmsg_errordesc_get_test_nullcheck();
void mudir_drvmsg_errordesc_get_test_lowerlimitcheck();
void mudir_drvmsg_errordesc_get_test_upperlimitcheck();
void mudir_drvmsg_errordesc_get_test_normal_noerror();
void mudir_drvmsg_errordesc_get_test_normal_nomessage();
void mudir_drvmsg_errordesc_get_test_normal_invaliddata();
void mudir_drvmsg_errordesc_get_test_normal_devunavail();
void mudir_drvmsg_errordesc_get_test_normal_deverror();
void mudir_drvmsg_errordesc_get_test_normal_others_emptydesc();
void mudir_drvmsg_errordesc_get_test_normal_others();

/*
 * These unit tests just checks that the sub-message structures
 * are allocated in memory and does not check the contents of
 * the sub-messages just after initialization. These will be
 * checked in the respective message type checks.
 */
void mudir_drvmsg_messagetype_set_test_nullcheck();
void mudir_drvmsg_messagetype_set_test_lowerlimitcheck();
void mudir_drvmsg_messagetype_set_test_unassignedcheck();
void mudir_drvmsg_messagetype_set_test_upperlimitcheck();
void mudir_drvmsg_messagetype_set_test_drvregister();
void mudir_drvmsg_messagetype_set_test_drvregack();
void mudir_drvmsg_messagetype_set_test_devqry();
void mudir_drvmsg_messagetype_set_test_devcom();
void mudir_drvmsg_messagetype_set_test_devreply();

void mudir_drvmsg_messagetype_get_test_nullcheck();
void mudir_drvmsg_messagetype_get_test_emptymessagecheck();
void mudir_drvmsg_messagetype_get_test_normal();

/*
 * Important note on mudir_drvmsg_clean() Unit Test cases
 * ===================================================
 * 
 * There is no separate unit test for mudir_drvmsg_clean() function
 * as this function heavily depends upon the sub-message cleanup
 * functions and CUnit does not allow mocking them. This function
 * will be automatically tested as part of clean-up testing for 
 * the individual sub-message test cases.
 */

#ifdef __cplusplus
}
#endif

#endif /* __MSGHANDLERDRVGS_TEST_H__ */