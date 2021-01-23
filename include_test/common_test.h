
#ifndef   __COMMON_TEST_H__
#define   __COMMON_TEST_H__

#ifdef __cplusplus
extern "C" {
#endif

#define MUDIR_TEST_ADD_SUITE(pSuite, strName, pInit, pClean) \
          do { \
            pSuite = CU_add_suite(strName, pInit, pClean); \
            if (NULL == pSuite) { \
              printf("FATAL ERROR: msghandlerdrv_test_init Suite addition failed: %s", CU_get_error_msg()); \
              return MUDIR_ERROR; \
            } \
          } while(0)

#define MUDIR_TEST_ADD_TEST(pSuite, strName, pTestFunc) \
          do { \
            if (CU_add_test(pSuite, strName, pTestFunc) == NULL) { \
              printf("FATAL ERROR: %s_test addition failed: %s", strName, CU_get_error_msg()); \
              return MUDIR_ERROR; \
            } \
          } while(0)

#ifdef __cplusplus
}
#endif

#endif /* __COMMON_TEST_H__ */
