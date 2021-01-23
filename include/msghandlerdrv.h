
#ifndef __MSGHANDLERDRV_H__
#define __MSGHANDLERDRV_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

/**
 * @file msghandlerdrv.h
 * @brief Mudir Driver Message Communication Functions Declarations
 * @author Biswajit Dhar
 * @copyright MIT  
 * 
 * This document lists the objects used for handling the messages between
 * base and driver. This file is mainly for use of the drivers which want
 * to communicate with the base. There is a separate library for for 
 * controllers to communicate with base.
 * 
 * <p>This library lists the different operations that are meant to be 
 * used by the driver modules. This library MUST be used in conjunction
 * with common.h.
 */

/* #region __driver_message_types__ */

/**
 * @defgroup __driver_message_types__ The driver message types
 * @{
 * 
 * This section lists the driver message type and its associated enumerators
 */

struct mudir_driver_message;

/**
 * @brief The basic type of the driver message
 */
typedef struct mudir_driver_message * mudir_driver_message;

/**
 * @brief The message types for communicating with Mudir base
 */
typedef enum 
{
  MUDIR_DRIVERMSG_TYPE_DRIVER_UNASSIGNED   = 0,
  /**< No message type assigned */
  MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER     = 1,
  /**< Driver registration message to Mudir base */
  MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK = 2,
  /**< Driver registration acknowledgment message from Mudir base */
  MUDIR_DRIVERMSG_TYPE_DEVICE_QUERY        = 3,
  /**< Message to driver to query a sensor */
  MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND      = 4,
  /**< Message to driver to command a controller */
  MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY        = 5
  /**< Message from driver for the query or command message */
} mudir_drivermsg_message_type;

/**
 * @brief The error types between the driver and base.
 */
typedef enum
{
  MUDIR_DRIVERMSG_ERROR_NO_ERROR = 0,
  /**< There are no errors */
  MUDIR_DRIVERMSG_ERROR_NO_MESSAGE,
  /**< There is no message object */ 
  MUDIR_DRIVERMSG_ERROR_INVALID_DATA,
  /**< Invalid data has been sent/received */
  MUDIR_DRIVERMSG_ERROR_DEVICE_UNAVAILABLE,
  /**< The device is unavailable */
  MUDIR_DRIVERMSG_ERROR_DEVICE_ERROR,
  /**< The device has returned an error */
  MUDIR_DRIVERMSG_ERROR_OTHER
  /**< An unknown error */
} mudir_drivermsg_message_error;

/**
 * @brief Driver Type as described in the specification.
 */
typedef enum
{
  MUDIR_DRIVER_TYPE_UNKNOWN          = 0,
  /**< The driver type is unknown or uninitialized by the driver */
  MUDIR_DRIVER_TYPE_SENSOR           = 1,
  /**< The driver is a sensor */
  MUDIR_DRIVER_TYPE_DISPLAY          = 2,
  /**< The driver is a display */
  MUDIR_DRIVER_TYPE_CONTROLLER       = 3
  /**< The driver is a controller/relay */
} mudir_driver_type;

/**
 * @brief Driver result return type as described in the specification.
 */
typedef enum
{
  MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN   = 0,
  /**< The driver return type is unknown */
  MUDIR_DRIVERMSG_RETURN_TYPE_STRING    = 1,
  /**< The driver returns a string */
  MUDIR_DRIVERMSG_RETURN_TYPE_BOOL      = 2,
  /**< The driver returns a boolean value, i.e. bool (stdbool.h) 1 byte */
  MUDIR_DRIVERMSG_RETURN_TYPE_INTEGER   = 3,
  /**< The driver returns an integer value i.e. long 4 bytes */
  MUDIR_DRIVERMSG_RETURN_TYPE_FLOAT     = 4,
  /**< The driver returns a float value i.e. double */
  MUDIR_DRIVERMSG_RETURN_TYPE_JSON      = 5
  /**< The driver returns a compound value in JSON format */
} mudir_drivermsg_data_type;

/**
 * @brief Driver acknowledgement connection mode.
 */
typedef enum
{
  MUDIR_DRIVERMSG_ACK_MODE_UNASSIGNED   = 0,
  /**< The driver connection mode is unassigned */
  MUDIR_DRIVERMSG_ACK_MODE_IPC          = 1
  /**< The driver needs to connect using IPC methods */
} mudir_drivermsg_ack_mode_type;

/**
 * @brief Driver message versions
 */
typedef enum
{
  MUDIR_DRIVERMSG_VERSION_UNASSIGNED    = 0,
  /**< Driver Message Version not set */
  MUDIR_DRIVERMSG_VERSION_1_0           = 1
  /**< Driver Message Version is 1.0 */
} mudir_drivermsg_version_type;

/**
 * @}
 */

/* #endregion */

/* #region __driver_library_functions__ */

/**
 * @defgroup __driver_library_functions__ The driver library functions
 * @{
 * 
 * This section lists the driver message library functions which provide the
 * library version details.
 */

/**
 * @brief Returns the full printable version string for the library
 * 
 * This function returns the full printable version string of the library. This
 * is intended for printing to logs/screen as is. The vString parameter MUST
 * be a character array having size of MUDIR_MAX_STRING_LEN size.
 * 
 * @param[out] The string buffer to hold full printable version string
 * @return int The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR.
 */
int mudir_drvmsg_lib_fullversionstring_get(
        char *vString
        ) MUDIR_API;

/**
 * @brief Returns the version portion of the version string
 * 
 * This function returns the version portion of the version string. For example
 * "0.1".
 * 
 * @return const char* The version portion of the version string
 */
const char *
    mudir_drvmsg_lib_buildversion_get() MUDIR_API;

/**
 * @brief Returns the full version string including build number. For example
 * "0.1-9-g533c022", which states 9 commits after 0.1 version.
 * 
 * @return const char* The full version string
 */
const char *
    mudir_drvmsg_lib_buildnumber_get() MUDIR_API;

/**
 * @brief Returns the build date in ANSI format with "-" delimiter
 * 
 * This function returns the build date in ANSI format with "-" the delimiter.
 * For example, "2020-05-22" for 22nd of May 2020.
 * 
 * @return const char* The build date in ANSI format with "-" delimiter
 */
const char *
    mudir_drvmsg_lib_builddate_get() MUDIR_API;

/**
 * @}
 */

/* #endregion */

/* #region __driver_message_handler_functions__ */

/**
 * @defgroup __driver_message_handler_functions__ The driver message handlers
 * @{
 * 
 * The functions to handle messages.
 */

/**
 * @brief Message initializer
 * 
 * This function allocates memory and initializes the internal message 
 * structure. Message once initialized must be destroyed by invoking 
 * mudir_drvmsg_free().
 * 
 * @param[out] message The message to be initialized
 * @param[out] version The version of the driver message. Must be #MUDIR_DRIVERMSG_VERSION_1_0.
 * @return int The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR.
 * @see mudir_drvmsg_free()
 * @see ::mudir_driver_message
 */
int mudir_drvmsg_initialize(
        mudir_driver_message            *message,
        mudir_drivermsg_version_type    version
        ) MUDIR_API;

/**
 * @brief Message Destroyer
 * 
 * This function destroys the initialized message. This function must be
 * called after working with the message to free up system resources.
 * 
 * @param[in] message The message to be destroyed.
 * @return int The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR.
 * @see mudir_drvmsg_initialize()
 * @see ::mudir_driver_message
 */
int mudir_drvmsg_free(
        mudir_driver_message            *message
        ) MUDIR_API;

/**
 * @brief Message Serializer
 * 
 * This function serializes the message into a byte array so that it can be 
 * transferred over through the communication mechanism.
 * 
 * @param[in] message The message to be serialized
 * @param[out] buffer The array of bytes which is serialized. Memory is allocated here
 * @param[out] size The total size of the buffer returned by the function
 * @return int The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR.
 * @see mudir_drvmsg_deserialize()
 * @see ::mudir_driver_message
 * @see #MUDIR_BYTE
 */
int mudir_drvmsg_serialize(
        mudir_driver_message            message,
        MUDIR_BYTE                      **buffer,
        size_t                          *size
        ) MUDIR_API;

/**
 * @brief Message Deserializer
 * 
 * This function deserializes the message from the byte array so that it can
 * be utilized for further processing.
 * 
 * @param[out] message The parsed message. The message must be initialized.
 * @param[in] buffer The byte array to parse and convert
 * @param[in] size  The size of the byte array
 * @return int The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR.
 * @see mudir_drvmsg_serialize()
 * @see ::mudir_driver_message
 * @see #MUDIR_BYTE
 */
int mudir_drvmsg_deseralize(
        mudir_driver_message            *message,
        MUDIR_BYTE                      *buffer,
        size_t                          size
        ) MUDIR_API;

/**
 * @}
 */

/* #endregion */

/* #region __driver_message_getters_setters__ */

/**
 * @defgroup __driver_message_getters_setters__ The driver message getters and setters
 * @{
 * 
 * The functions used to handle getting setting attributes.
 */

/**
 * @brief Gets the version of the driver message
 * 
 * This function gets the version of the driver message. There are no set method
 * for the version. Version for a message MUST be set during initialization and
 * cannot be changed during its lifetime.
 * 
 * @param[in] message The message from which to extract the version
 * @return mudir_drivermsg_version_type The message version
 * @see mudir_drvmsg_initialize()
 */
mudir_drivermsg_version_type 
    mudir_drvmsg_version_get(
        mudir_driver_message           message
        ) MUDIR_API;

/**
 * @brief Sets the message type of the message
 * 
 * Use this function to set the message type. Message type must be set
 * before accessing the other contents of the message.
 * 
 * @param[in] message The message for which to set the message type
 * @param[in] message_type The message type to set
 * @return int The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR.
 * @see mudir_drvmsg_messagetype_get()
 */
int mudir_drvmsg_messagetype_set(
        mudir_driver_message            message,
        mudir_drivermsg_message_type    message_type
        ) MUDIR_API;

/**
 * @brief Gets the message type of the message
 * 
 * This function to retrieves the message type.
 * 
 * @param[in] message The message from where to get the message type
 * @return mudir_driver_message_type The message type
 * @see mudir_drvmsg_messagetype_set()
 */
mudir_drivermsg_message_type
    mudir_drvmsg_messagetype_get(
        mudir_driver_message            message
        ) MUDIR_API;

/**
 * @brief Sets the error code of the message
 * 
 * This function sets the error code.
 * 
 * @param[in] message The message for which to set the error code
 * @param[in] error_code The error code to set
 * @return int The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR.
 * @see mudir_drvmsg_errorcode_get()
 */
int mudir_drvmsg_errorcode_set(
        mudir_driver_message            message,
        mudir_drivermsg_message_error   error_code
        ) MUDIR_API;

/**
 * @brief Gets the error code of the message
 * 
 * This function to retrieves the message type.
 * 
 * @param[in] message The message from where to get the error code
 * @return mudir_driver_message_error The error code
 * @see mudir_drvmsg_errorcode_set()
 */
mudir_drivermsg_message_error
    mudir_drvmsg_errorcode_get(
        mudir_driver_message            message
        ) MUDIR_API;

/**
 * @brief Sets the error description of the message
 * 
 * This function sets the error description of the message. This property 
 * is provided to allow custom error messages not covered by error codes.
 * Set the error code to #MUDIR_DRIVERMSG_OTHER in order to set this 
 * property.
 * 
 * @param[in] message The message for which to set the error description
 * @param[in] errordesc The error description
 * @return int The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR.
 * @see mudir_drvmsg_errordesc_get()
 */
int mudir_drvmsg_errordesc_set(
        mudir_driver_message            message,
        const char *                    errordesc
        ) MUDIR_API;

/**
 * @brief Gets the error description of the message
 * 
 * This function gets the error description of the message. This property
 * must be checked for custom error messages when the error code has been
 * set to #MUDIR_DRIVERMSG_OTHER.
 * 
 * @param[in] message The message from where to extract the error description
 * @return const char* The error description
 * @see mudir_drvmsg_errordesc_set()
 */
const char *
    mudir_drvmsg_errordesc_get(
        mudir_driver_message            message
        ) MUDIR_API;
/**
 * @}
 */

/* #endregion */

/* #region __driver_reg_message_getters_setters__ */

/**
 * @defgroup __driver_reg_message_getters_setters__ The driver registration message getters and setters
 * @{
 * 
 * The functions used to handle getting setting driver registration message 
 * attributes.
 */

/**
 * @brief Sets the name attribute of the driver registration message
 * 
 * This attribute is the name of the driver which is communicating with base or
 * vice versa. This function sets the name in the message data structure.
 * 
 * @param[in] message The message for which to set the driver name
 * @param[in] name The name of the driver
 * @return int The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR.
 * @see mudir_drvmsg_reg_name_get()
 */
int mudir_drvmsg_reg_name_set(
        mudir_driver_message            message,
        const char *                    name
        ) MUDIR_API;

/**
 * @brief Gets the name attribute of the driver registration message
 * 
 * This function retrieves the driver name attribute from the driver
 * registration message.
 * 
 * @param[in] message The message from where to extract the driver name
 * @return const char* The name of the driver
 * @see mudir_drvmsg_reg_name_set()
 */
const char *
    mudir_drvmsg_reg_name_get(
        mudir_driver_message            message
        ) MUDIR_API;

/**
 * @brief Sets the snap name attribute of the driver registration message
 * 
 * This function sets the driver snap name attribute of the message
 * structure.
 * 
 * @param[in] message The message for which to set the driver snap name
 * @param[in] snapname The name of the snap
 * @return int The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR.
 * @see mudir_drvmsg_reg_snapname_get()
 */
int mudir_drvmsg_reg_snapname_set(
        mudir_driver_message            message,
        const char *                    snapname
        ) MUDIR_API;

/**
 * @brief Gets the snap name attribute from the driver registration message
 * 
 * This function extracts the snap name attribute from the driver registration
 * message.
 * 
 * @param[in] message The message from where to extract the driver snap name
 * @return const char* The name of the driver snap name
 * @see mudir_drvmsg_reg_snapname_set()
 */
const char *
    mudir_drvmsg_reg_snapname_get(
        mudir_driver_message            message
        ) MUDIR_API;

/**
 * @brief Sets the snap version attribute of the driver registration message
 * 
 * This function sets the snap version attribute of the driver registration 
 * message.
 * 
 * @param[in] message The message for which to set the snap version
 * @param[in] snapversion The version of the driver snap
 * @return int The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR
 * @see mudir_drvmsg_reg_snapversion_get()
 */
int mudir_drvmsg_reg_snapversion_set(
        mudir_driver_message            message,
        const char *                    snapversion
        ) MUDIR_API;

/**
 * @brief Gets the snap version attribute from the driver registration message
 * 
 * This function extracts the snap version attribute from the driver 
 * registration message.
 * 
 * @param[in] message The message from which to get the snap version
 * @return const char * The version of the driver snap
 * @see mudir_drvmsg_reg_snapversion_set()
 */
const char *
    mudir_drvmsg_reg_snapversion_get(
        mudir_driver_message            message
        ) MUDIR_API;

/**
 * @brief Sets the number of capabilities present in the driver registration message
 * 
 * This function sets the number of capabilities attribute to be provisioned 
 * in the driver registration message. Set this prior to setting the capabilities.
 * 
 * @param[in] message The message for which to set the capabilities count
 * @param[in] count The number of capabilities to be provisioned
 * @return int The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR
 * @see mudir_drvmsg_reg_cap_count_get()
 */
int mudir_drvmsg_reg_cap_count_set(
        mudir_driver_message            message,
        const int                       count
        ) MUDIR_API;

/**
 * @brief Gets the number of capabilities present in the driver registration message
 * 
 * This function gets the number of capabilities attribute from the driver 
 * registration message. Inquire this before iterating with the capabilities.
 * 
 * @param[in] message The message from which to get the capabilities count
 * @return int The number of capabilities present. -1 in case of error.
 * @see mudir_drvmsg_reg_cap_count_set()
 */
const int
    mudir_drvmsg_reg_cap_count_get(
        mudir_driver_message            message
        ) MUDIR_API;

/**
 * @brief Sets the driver type attribute in a capability
 * 
 * This function sets the driver type attribute in the driver registration 
 * capability section of the message.
 * 
 * @param[in] message The message for which to set the driver type
 * @param[in] index The index of the capability in the driver registration message
 * @param[in] driver_type The type of driver
 * @return int The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR
 * @see mudir_drvmsg_reg_cap_drvtype_get()
 */
int mudir_drvmsg_reg_cap_drvtype_set(
        mudir_driver_message            message,
        const int                       index,
        const mudir_driver_type         driver_type
        ) MUDIR_API;

/**
 * @brief Gets the driver type attribute in a capability
 * 
 * This function gets the driver type attribute in the driver registration
 * capability section of the message.
 * 
 * @param[in] message The message from where to extract the driver type
 * @param[in] index The index of the capability in the driver registration message
 * @return mudir_driver_type The driver type enum
 * @see mudir_drvmsg_reg_cap_drvtype_set()
 */
const mudir_driver_type
    mudir_drvmsg_reg_cap_drvtype_get(
        mudir_driver_message            message,
        const int                       index
        ) MUDIR_API;

/**
 * @brief Sets the capability name attribute in a capability
 * 
 * This function sets the capability name attribute in a driver registration
 * capability section of the message.
 * 
 * @param[in] message The message for which to set the capability name
 * @param[in] index The index of the capability in the driver registration message
 * @param[in] name The capability name to set
 * @return int The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR
 * @see mudir_drvmsg_reg_cap_name_get()
 */
int mudir_drvmsg_reg_cap_name_set(
        mudir_driver_message            message,
        const int                       index,
        const char *                    name
        ) MUDIR_API;

/**
 * @brief Gets the capability name attribute in a capability
 * 
 * This function gets the capability name attribute from a driver registration
 * capability section of the message.
 * 
 * @param[in] message The message from which to extract the capability name
 * @param[in] index The index of the capability in the driver registration message
 * @return const char* The capability name
 * @see mudir_drvmsg_reg_cap_name_set()
 */
const char *
    mudir_drvmsg_reg_cap_name_get(
        mudir_driver_message            message,
        const int                       index
        ) MUDIR_API;

/**
 * @brief Sets the capability description attribute in a capability
 * 
 * This function sets the capability description attribute of a driver
 * registration capability section of the message.
 * 
 * @param[in] message The message for which to set the capability description
 * @param[in] index The index of the capability in the driver registration message
 * @param[in] description The capability description to set
 * @return int The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR
 * @see mudir_drvmsg_reg_cap_desc_get()
 */
int mudir_drvmsg_reg_cap_desc_set(
        mudir_driver_message            message,
        const int                       index,
        const char *                    description
        ) MUDIR_API;

/**
 * @brief Gets the capability description attribute in a capability
 * 
 * This function gets the capability description attribute of a driver
 * registration capability section of the message.
 * 
 * @param[in] message The message from which to get the capability description
 * @param[in] index The index of the capability in the driver registration message
 * @return const char* The capability description
 * @see mudir_drvmsg_reg_cap_desc_set()
 */
const char *
    mudir_drvmsg_reg_cap_desc_get(
        mudir_driver_message            message,
        const int                       index
        ) MUDIR_API;

/**
 * @brief Sets the return type attribute in a capability
 * 
 * This function sets the return type attribute of a driver registration 
 * capability section of the message
 * 
 * @param[in] message The message for which to set the return type
 * @param[in] index The index of the capability in the driver registration message
 * @param[in] return_type The return type of the capability
 * @return int The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR
 * @see mudir_drvmsg_reg_cap_returntype_get()
 */
int mudir_drvmsg_reg_cap_returntype_set(
        mudir_driver_message            message,
        const int                       index,
        const mudir_drivermsg_data_type return_type
        ) MUDIR_API;

/**
 * @brief Gets the return type attribute in a capability
 * 
 * This function gets the return type attribute of a driver registration 
 * capability section of the message
 * 
 * @param[in] message The message from which to get the return type
 * @param[in] index The index of the capability in the driver registration message
 * @return mudir_driver_return_type The return type enum
 * @see mudir_drvmsg_reg_cap_returntype_set()
 */
const mudir_drivermsg_data_type
    mudir_drvmsg_reg_cap_returntype_get(
        mudir_driver_message            message,
        const int                       index
        ) MUDIR_API;

/**
 * @}
 */

/* #endregion */

/* #region __driver_reg_ack_message_getters_setters__ */

/**
 * @defgroup __driver_reg_ack_message_getters_setters__ The driver registration 
 * acknowledgement message getters and setters
 * @{
 * 
 * The functions used to handle getting setting driver registration  
 * acknowledgement message attributes.
 * 
 */

/**
 * @brief Sets the system-wide unique name of the driver
 * 
 * This function sets the driver name attribute of a driver acknowledgement 
 * section of the message. Mudir base assigns a system-wide unique name for
 * the driver for its routing purposes.
 * 
 * @param[in] message The message for which to set the driver name
 * @param[in] name The assigned name of the driver
 * @return int The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR
 * @see mudir_drvmsg_ack_name_get()
 */
int mudir_drvmsg_ack_name_set(
        mudir_driver_message            message,
        const char                      *name
        ) MUDIR_API;

/**
 * @brief Gets the system-wide unique name of the driver
 * 
 * This function gets the name attribute from a driver registration
 * acknowledgement section of the message.
 * 
 * @param[in] message The message from which to get the driver name
 * @return const char* The driver name
 * @see mudir_drvmsg_ack_name_set()
 */
const char * 
    mudir_drvmsg_ack_name_get(
        mudir_driver_message            message
        ) MUDIR_API;

/**
 * @brief Sets the mode of connection between driver and base
 * 
 * This function sets the mode of connectivity attribute of a driver 
 * acknowledgement section of the message. As of now, only IPC is 
 * supported between base and driver.
 * 
 * @param[in] message The message for which to set the connection mode
 * @param[in] mode    The connection mode enumerator
 * @return int        The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR
 * @see mudir_drvmsg_ack_mode_get()
 */
int mudir_drvmsg_ack_mode_set(
        mudir_driver_message            message,
        mudir_drivermsg_ack_mode_type   mode
        ) MUDIR_API;

/**
 * @brief Gets the mode of connection between driver and base
 * 
 * This function gets the mode of connectivity attribute of a driver
 * acknowledgement section of the message.
 * 
 * @param[in] message The message from which to get the connection mode
 * @return const mudir_driver_ack_mode_type The connectivity mode
 * @see mudir_drvmsg_ack_mode_set()
 */
const mudir_drivermsg_ack_mode_type 
    mudir_drvmsg_ack_mode_get(
        mudir_driver_message            message
        ) MUDIR_API;

/**
 * @brief Sets the inward (i.e. from driver to base) location 
 * 
 * This function sets the inward (i.e. driver to base) connection address
 * or path (in case of IPC) attribute for the driver module to connect to in 
 * the driver acknowledgement section of the message.
 * 
 * @param[in] message The message for which to set the inward connection address/path
 * @param[in] inaddr  The inward connection address/path
 * @return int        The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR
 * @see mudir_drvmsg_ack_inaddr_get()
 */
int mudir_drvmsg_ack_inaddr_set(
        mudir_driver_message            message,
        const char                      *inaddr
        ) MUDIR_API;

/**
 * @brief Gets the inward (i.e. from driver to base) location
 * 
 * This function gets the inward connection address or path attribute from the
 * driver acknowledgement section of the message.
 * 
 * @param[in] message The message from which to get the inward address/path
 * @return const char* The inward connection address/path
 * @see mudir_drvmsg_ack_inaddr_set()
 */
const char * 
    mudir_drvmsg_ack_inaddr_get(
        mudir_driver_message            message
        ) MUDIR_API;

/**
 * @brief Sets the outward (i.e. from base to driver) location
 * 
 * This function sets the outward (i.e. base to driver) connection address
 * or path (in case of IPC) attribute for the driver module to connect to in 
 * the driver acknowledgement section of the message.
 *
 * @param[in] message The message for which to set the outward connection address/path
 * @param[in] outaddr The outward connection address/path
 * @return int        The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR
 * @see mudir_drvmsg_ack_outaddr_get()
 */
int mudir_drvmsg_ack_outaddr_set(
        mudir_driver_message            message,
        const char                      *outaddr
        ) MUDIR_API;

/**
 * @brief Gets the outward (i.e. from base to driver) location
 * 
 * This function gets the outward connection address or path attribute from the
 * driver acknowledgement section of the message.
 * 
 * @param[in] message The message from which to get the outward address/path
 * @return const char* The outward connection address/path
 * @see mudir_drvmsg_ack_outaddr_set()
 */
const char * 
    mudir_drvmsg_ack_outaddr_get(
        mudir_driver_message            message
        ) MUDIR_API;

/**
 * @}
 */

/* #endregion */

/* #region __device_command_query_message_getters_setters__ */

/**
 * @defgroup __device_command_query_message_getters_setters__ The device 
 * command and query message getters and setters
 * @{
 * 
 * The functions used to handle getting setting device command and query  
 * message attributes.
 */

/**
 * @brief Sets the name of the driver for whom this message is intended
 * 
 * This function sets the name of the driver attribute for the driver command/ 
 * query section of the message. This name signifies the intended recepient of  
 * the message.
 * 
 * @param[in] message     The message for which to set the driver name
 * @param[in] driver_name The name of the driver
 * @return int            The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR
 * @see                   mudir_drvmsg_comqry_driver_name_get()
 */
int mudir_drvmsg_comqry_driver_name_set(
        mudir_driver_message            message,
        const char                      *driver_name
        ) MUDIR_API;

/**
 * @brief Gets the name of the driver for whom this message is intended
 * 
 * This function gets the name of the driver attribute from the driver command/ 
 * query section of the message.
 * 
 * @param[in] message      The message from which to get the driver name
 * @return const char*     The name of the driver
 * @see                    mudir_drvmsg_comqry_driver_name_set()
 */
const char * 
    mudir_drvmsg_comqry_driver_name_get(
        mudir_driver_message            message
        ) MUDIR_API;

/**
 * @brief Sets the name of the device within the driver for whom this message is intended
 * 
 * This function sets the name of the device within the driver attribute for  
 * the driver command/query section of the message. This name signifies the  
 * intended recepient of the message.
 * 
 * @param[in] message      The message for which to set the device name
 * @param[in] device_name  The name of the device
 * @return int             The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR
 * @see                    mudir_drvmsg_comqry_device_name_get()
 */
int mudir_drvmsg_comqry_device_name_set(
        mudir_driver_message            message,
        const char                      *device_name
        ) MUDIR_API;

/**
 * @brief Gets the name of the device within the driver for whom this message is intended
 * 
 * This function gets the name of the device attribute from the driver command/
 * query section of the message.
 * 
 * @param[in] message      The message from which to get the device name
 * @return const char*     The name of the device
 * @see                    mudir_drvmsg_comqry_device_name_set()
 */
const char * 
    mudir_drvmsg_comqry_device_name_get(
        mudir_driver_message            message
        ) MUDIR_API;

/**
 * @brief Sets the number of options with the device command/query section of the message
 * 
 * This function sets the number of options that are required to be sent to 
 * the device. This function allocates memory space and readies the option
 * elements.
 * 
 * @param[in] message      The message for which to set the options count
 * @param[in] count        The number of options
 * @return int             The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR
 * @see                    mudir_drvmsg_comqry_opts_count_get()
 */
int mudir_drvmsg_comqry_opts_count_set(
        mudir_driver_message            message,
        const int                       count
        ) MUDIR_API;

/**
 * @brief Gets the number of options with the device command/query section of the message
 * 
 * This function gets the number of options that are required to be sent to 
 * the device.
 * 
 * @param[in] message      The message from which to get the options count
 * @return int             The number of options
 * @see                    mudir_drvmsg_comqry_opts_count_set()
 */
int mudir_drvmsg_comqry_opts_count_get(
        mudir_driver_message            message
        ) MUDIR_API;

/**
 * @brief Sets the key name of an option for the given index
 * 
 * This function sets the key name of an option for a given index of the 
 * device command/query section of the message
 * 
 * @param[in] message      The message for which to set the key of the option
 * @param[in] index        The index of the option
 * @param[in] key          The name of the key
 * @return int             The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR
 * @see                    mudir_drvmsg_comqry_opts_key_get()
 */
int mudir_drvmsg_comqry_opts_key_set(
        mudir_driver_message            message,
        const int                       index,
        const char                      *key
        ) MUDIR_API;

/**
 * @brief Gets the key name of an option for the given index
 * 
 * This function gets the key name of an option for a given index from the 
 * device command/query section of the message
 * 
 * @param[in] message      The message from which to get the key of the option
 * @param[in] index        The index of the option
 * @return const char*     The key name
 * @see                    mudir_drvmsg_comqry_opts_key_set()
 */
const char * 
    mudir_drvmsg_comqry_opts_key_get(
        mudir_driver_message            message,
        const int                       index
        ) MUDIR_API;

/**
 * @brief Sets the key value of an option for the given index
 * 
 * This function sets the key value of an option for a given index of the 
 * device command/query section of the message
 * 
 * @param[in] message      The message for which to set the value of the option
 * @param[in] index        The index of the option
 * @param[in] type         The data type of the value of the option 
 * @param[in] value        The value to set
 * @return int             The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR
 * @see                    mudir_drvmsg_comqry_opts_value_get()
 * @see                    mudir_drvmsg_comqry_opts_valuetype_get()
 */
int mudir_drvmsg_comqry_opts_value_set(
        mudir_driver_message            message,
        const int                       index,
        const mudir_drivermsg_data_type type,
        const void                      *value
        ) MUDIR_API;

/**
 * @brief Gets the key value of an option for the given index
 * 
 * This function gets the key value of an option for a given index from the 
 * device command/query section of the message. This function can also make
 * data type conversion between compatible data types.
 * 
 * @param[in] message      The message from which to get the value of the option
 * @param[in] index        The index of the option
 * @param[in] type         The expected data type to return
 * @param[out] value       The key value
 * @return int             The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR
 * @see                    mudir_drvmsg_comqry_opts_value_set()
 * @see                    mudir_drvmsg_comqry_opts_valuetype_get()
 */
int mudir_drvmsg_comqry_opts_value_get(
        mudir_driver_message            message,
        const int                       index,
        const mudir_drivermsg_data_type type,
        void                            *value
        ) MUDIR_API;

/**
 * @brief Gets the key value data type of an option for the given index
 * 
 * This function returns the enumerator containing the data type of the value
 * set in the key-value pair of the options.
 * 
 * @param[in] message             The message from which to get the data type of the value of the option
 * @param[in] index               The index of the option
 * @return mudir_driver_data_type The data type of the key value
 * @see                           mudir_drvmsg_comqry_opts_value_set()
 * @see                           mudir_drvmsg_comqry_opts_value_get()
 */
mudir_drivermsg_data_type
    mudir_drvmsg_comqry_opts_valuetype_get(
        mudir_driver_message            message,
        const int                       index
        ) MUDIR_API;

/**
 * @}
 */

/* #endregion */

/* #region __device_reply_message_getters_setters__ */

/**
 * @defgroup __device_reply_message_getters_setters__ The device reply message
 * getters and setters
 * @{
 * 
 * The functions used to handle getting and setting device reply message  
 * attributes.
 */

/**
 * @brief Sets the name of the driver from whom this message has originated
 * 
 * This function sets the name of the driver attribute for the driver reply 
 * section of the message. This name signifies the sender of the message. 
 * 
 * @param[in] message     The message for which to set the driver name
 * @param[in] driver_name The name of the driver
 * @return int            The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR
 * @see                   mudir_drvmsg_reply_driver_name_get()
 */
int mudir_drvmsg_reply_driver_name_set(
        mudir_driver_message            message,
        const char                      *driver_name
        ) MUDIR_API;

/**
 * @brief Gets the name of the driver from whom this message originated
 * 
 * This function gets the name of the driver attribute from the driver reply 
 * section of the message.
 * 
 * @param[in] message      The message from which to get the driver name
 * @return const char*     The name of the driver
 * @see                    mudir_drvmsg_reply_driver_name_set()
 */
const char * 
    mudir_drvmsg_reply_driver_name_get(
        mudir_driver_message            message
        ) MUDIR_API;

/**
 * @brief Sets the name of the device within the driver from whom this message originated
 * 
 * This function sets the name of the device within the driver attribute for  
 * the driver reply section of the message. This name signifies the sender of the 
 * message.
 * 
 * @param[in] message      The message for which to set the device name
 * @param[in] device_name  The name of the device
 * @return int             The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR
 * @see                    mudir_drvmsg_reply_device_name_get()
 */
int mudir_drvmsg_reply_device_name_set(
        mudir_driver_message            message,
        const char                      *device_name
        ) MUDIR_API;

/**
 * @brief Gets the name of the device within the driver from whom this message originated
 * 
 * This function gets the name of the device attribute from the driver reply 
 * section of the message.
 * 
 * @param[in] message      The message from which to get the device name
 * @return const char*     The name of the device
 * @see                    mudir_drvmsg_reply_device_name_set()
 */
const char * 
    mudir_drvmsg_reply_device_name_get(
        mudir_driver_message            message
        ) MUDIR_API;

/**
 * @brief Sets the value attribute of the reply message
 * 
 * This function sets the value attribute for the driver reply section 
 * of the message. This name signifies the sender of the message.
 * 
 * @param[in] message      The message for which to set the value
 * @param[in] value        The value to set
 * @return int             The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR
 * @see                    mudir_drvmsg_reply_value_get()
 */
int mudir_drvmsg_reply_value_set(
        mudir_driver_message            message,
        const char                      *value
        ) MUDIR_API;

/**
 * @brief Gets the value attribute from the reply message
 * 
 * This function gets the value attribute from the driver reply section of the 
 * message.
 * 
 * @param[in] message      The message from which to get the value
 * @return const char*     The value
 * @see                    mudir_drvmsg_reply_value_set()
 */
const char * 
    mudir_drvmsg_reply_value_get(
        mudir_driver_message            message
        ) MUDIR_API;

/**
 * @brief Sets the unit attribute of the reply message
 * 
 * This function sets the unit attribute for the driver reply section 
 * of the message. This name signifies the sender of the message.
 * 
 * @param[in] message      The message for which to set the unit
 * @param[in] unit         The unit of the value
 * @return int             The success or failure status. Returns #MUDIR_SUCCESS or #MUDIR_ERROR
 * @see                    mudir_drvmsg_reply_unit_get()
 */
int mudir_drvmsg_reply_unit_set(
        mudir_driver_message            message,
        const char                      *unit
        ) MUDIR_API;

/**
 * @brief Gets the unit attribute from the reply message
 * 
 * This function gets the unit attribute from the driver reply section of the 
 * message.
 * 
 * @param[in] message      The message from which to get the unit
 * @return const char*     The unit of the value
 * @see                    mudir_drvmsg_reply_unit_set()
 */
const char * 
    mudir_drvmsg_reply_unit_get(
        mudir_driver_message            message
        ) MUDIR_API;

/**
 * @}
 */

/* #endregion */

#ifdef __cplusplus
}
#endif

#endif //__MSGHANDLERDRV_H__