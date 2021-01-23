

/*
 * Important Note:
 * ===============
 * 
 * Test cases for mudir_drvmsg_serialize() and mudir_drvmsg_deseralize()
 * are handled as separate test stuie after executing the test cases 
 * for individual message types.
 */

#ifndef   __MSGHANDLERDRV_TEST_H__
#define   __MSGHANDLERDRV_TEST_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Test Suite Initializer */ 
int msghandlerdrv_test_init();

/* Test cases for mudir_drvmsg_lib_fullversionstring_get() */
void mudir_drvmsg_lib_fullversionstring_get_test_nullchk();
void mudir_drvmsg_lib_fullversionstring_get_test_base();

void mudir_drvmsg_lib_buildversion_get_test_base();

void mudir_drvmsg_lib_buildnumber_get_test_base();

void mudir_drvmsg_lib_builddate_get_test_base();

/* Test cases for mudir_drvmsg_initialize() */
void mudir_drvmsg_initialize_test_nullchk();
void mudir_drvmsg_initialize_test_versionlowerlimit();
void mudir_drvmsg_initialize_test_versionupperlimit();
void mudir_drvmsg_initialize_test_versionunassigned();
void mudir_drvmsg_initialize_test_base();

/* Test cases for mudir_drvmsg_free() */
void mudir_drvmsg_free_test_nullvarchk();
void mudir_drvmsg_free_test_nullchk();
void mudir_drvmsg_free_test_empty_message();
void mudir_drvmsg_free_test_err_desc();

#ifdef __cplusplus
}
#endif

#endif /* __MSGHANDLERDRV_TEST_H__ */