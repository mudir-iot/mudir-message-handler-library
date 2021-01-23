/**
 * @file common.h
 * @brief Mudir Common Declarations
 * @author Biswajit Dhar
 * @copyright Biswajit Dhar (2020)
 * 
 * This file contains the common declarations and macros which are used
 * throughout Mudir and are used by all the modules in the application
 * and libraries.
 */

#ifndef __COMMON_H__
#define __COMMON_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

/**
 * @defgroup __common_macros__ Common Macros for use by library functions
 * @{
 * 
 * Commonly used macros for compiler directives.
 */

/**
 * @brief Marks the function visible outside module
 */
#define MUDIR_API             __attribute__((visibility("default")))

/**
 * @brief Marks the function as deprecated
 */
#define MUDIR_API_DEPRECATED  __attribute__((deprecated))

/**
 * @brief Marks the function as hidden with the shared object
 */
#define MUDIR_PRIVATE         __attribute__((visibility("hidden")))
/**
 * @}
 */

/**
 * @defgroup __common_return_types__ Common return types of all Mudir functions
 * @{
 * Common return types of all Mudir functions
 */

/**
 * @brief The function returned successful
 */
#define  MUDIR_SUCCESS    EXIT_SUCCESS

/**
 * @brief The function returned error
 */
#define  MUDIR_ERROR      EXIT_FAILURE

/**
 * @brief The type for a byte
 */
#define  MUDIR_BYTE       unsigned char

/**
 * @}
 */

/* Macro for printing standard error. */
#define handle_error_en(en, msg) \
        do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

/* Macro for printing system error */
#define handle_error(msg) \
        do { perror(msg); exit(EXIT_FAILURE); } while (0)

typedef struct
{
  char *reg_sock_location;
} mudirbase_type_config_t;

#ifdef __cplusplus
}
#endif

#endif //__COMMON_H__
