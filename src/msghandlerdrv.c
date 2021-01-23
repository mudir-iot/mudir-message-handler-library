
#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "msghandlerdrv.h"
#include "msghandlerdrv_pvt.h"

int mudir_drvmsg_lib_fullversionstring_get(
        char *vString
        )
{
  int res;

  if (vString == NULL)
    return MUDIR_ERROR;
    
  res =  snprintf(vString, 
                  MUDIR_MAX_STRING_LEN, 
                  "libmudirmsghandlerdrv Build Version: %s Build Date: %s", 
                  __BUILDNUMBER__, 
                  __BUILDDATE__);
  
  if (res <= 0 || res > MUDIR_MAX_STRING_LEN)
    return MUDIR_ERROR;
  
  return MUDIR_SUCCESS;
}

const char *
    mudir_drvmsg_lib_buildversion_get()
{
  return __BUILDVERSION__;
}

const char *
    mudir_drvmsg_lib_buildnumber_get()
{
  return __BUILDNUMBER__;
}

const char *
    mudir_drvmsg_lib_builddate_get()
{
  return __BUILDDATE__;
}

int mudir_drvmsg_initialize(
        mudir_driver_message            *message,
        mudir_drivermsg_version_type    version
        )
{
  if (message == NULL)
    return MUDIR_ERROR;
  
  if (version <= MUDIR_DRIVERMSG_VERSION_UNASSIGNED ||
      version >  MUDIR_DRIVERMSG_VERSION_1_0)
    return MUDIR_ERROR;

  *message = (mudir_driver_message) 
            malloc(sizeof(struct mudir_driver_message));
  
  if (*message == NULL)
    return MUDIR_ERROR;

  (*message)->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_UNASSIGNED;
  (*message)->message = NULL;
  (*message)->error_desc_ = NULL;
  (*message)->error_ = MUDIR_DRIVERMSG_ERROR_NO_ERROR;
  (*message)->version_ = version;

  return MUDIR_SUCCESS;
}

int mudir_drvmsg_free(
        mudir_driver_message            *message
        )
{
  if (NULL == message)
    return MUDIR_ERROR;
  
  if (NULL == *message)
    return MUDIR_ERROR;

  if (MUDIR_ERROR == mudir_drvmsg_clean(*message))
    return MUDIR_ERROR;
  
  if (NULL != (*message)->error_desc_)
    free((*message)->error_desc_);

  free(*message);
  *message = NULL;

  return MUDIR_SUCCESS;
}

int mudir_drvmsg_serialize(
        mudir_driver_message            message,
        MUDIR_BYTE                      **buffer,
        size_t                          *size
        )
{
  /* Message structure is unallocated */
  if (message == NULL)
  {
    *buffer = NULL;
    *size = 0;
    return MUDIR_ERROR;
  }

  /* Message type is unassigned or unknown */
  if ((MUDIR_DRIVERMSG_TYPE_DRIVER_UNASSIGNED == message->message_type_) || 
      (MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY < message->message_type_))
  {
    *buffer = NULL;
    *size = 0;
    return MUDIR_ERROR;
  }
  
  MUDIR_BYTE *tbuf = NULL;

  tbuf = (MUDIR_BYTE *) calloc(MUDIR_MAX_BUFFER_SIZE, sizeof(MUDIR_BYTE));

  size_t i = 0;
  size_t len = 0;

  memcpy(&tbuf[i], &message->message_type_, sizeof message->message_type_);
  i += sizeof(message->message_type_);

  memcpy(&tbuf[i], &message->error_, sizeof message->error_);
  i += sizeof(message->error_);
  
  len = strnlen(message->error_desc_, MUDIR_MAX_STRING_LEN);
  memcpy(&tbuf[i], &len, sizeof(size_t));
  i += sizeof(size_t);

  memcpy(&tbuf[i], message->error_desc_, len);
  i += len;

  switch(message->message_type_)
  {
    case MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER:
            if(mudir_drvmsg_reg_serialize(
                  message, &tbuf[i], &i
                  ) != MUDIR_SUCCESS)
            {
              free(tbuf);
              *buffer = NULL;
              *size = 0;
              return MUDIR_ERROR;
            }
            break;

    case MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK:
            if(mudir_drvmsg_ack_serialize(
                  message, &tbuf[i], &i
                  ) != MUDIR_SUCCESS)
            {
              free(tbuf);
              *buffer = NULL;
              *size = 0;
              return MUDIR_ERROR;
            }
            break;

    case MUDIR_DRIVERMSG_TYPE_DEVICE_QUERY:
    case MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND:
            if(mudir_drvmsg_comqry_serialize(
                  message, &tbuf[i], &i
                  ) != MUDIR_SUCCESS)
            {
              free(tbuf);
              *buffer = NULL;
              *size = 0;
              return MUDIR_ERROR;
            }
            break;

    case MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY:
            if(mudir_drvmsg_rep_serialize(
                  message, &tbuf[i], &i
                  ) != MUDIR_SUCCESS)
            {
              free(tbuf);
              *buffer = NULL;
              *size = 0;
              return MUDIR_ERROR;
            }
            break;

    default:
            free(tbuf);
            *buffer = NULL;
            *size = 0;
            return MUDIR_ERROR;
  }

  *buffer = tbuf;
  *size = i;
  return MUDIR_SUCCESS;
}

int mudir_drvmsg_deseralize(
        mudir_driver_message            *message,
        MUDIR_BYTE                      *buffer,
        size_t                          size
        )
{
  if (message == NULL)
  {
    return MUDIR_ERROR;
  }

  if (buffer == NULL)
  {
    *message = NULL;
    return MUDIR_ERROR;
  }

  if (size <= 0)
  {
    *message = NULL;
    return MUDIR_ERROR;
  }

  /* TODO: Serialize and deserialize Message Version */
  if (MUDIR_ERROR == mudir_drvmsg_initialize(message, MUDIR_DRIVERMSG_VERSION_1_0))
  {
    *message = NULL;
    return MUDIR_ERROR;
  }

  size_t i = 0;
  size_t len = 0;
  mudir_drivermsg_message_type  message_type;
  mudir_drivermsg_message_error error_code;
  char                          tempstring[MUDIR_MAX_STRING_LEN];

  memcpy(&message_type, &buffer[i], sizeof(mudir_drivermsg_message_type));
  if (MUDIR_SUCCESS != mudir_drvmsg_messagetype_set(*message, message_type))
  {
    mudir_drvmsg_free(message);
    return MUDIR_ERROR;
  }
  i += sizeof(mudir_drivermsg_message_type);

  memcpy(&error_code, &buffer[i], sizeof(mudir_drivermsg_message_error));
  if (MUDIR_SUCCESS !=  mudir_drvmsg_errorcode_set(*message, error_code))
  {
    mudir_drvmsg_free(message);
    return MUDIR_ERROR;
  }
  i += sizeof(mudir_drivermsg_message_error);

  memcpy(&len, &buffer[i], sizeof(size_t));
  i += sizeof(size_t);

  if (MUDIR_DRIVERMSG_ERROR_OTHER == mudir_drvmsg_errorcode_get(*message))
  {
    memcpy(tempstring, &buffer[i], MIN(len, MUDIR_MAX_STRING_LEN));
    if (MUDIR_SUCCESS != mudir_drvmsg_errordesc_set(*message, tempstring))
    {
      mudir_drvmsg_free(message);
      return MUDIR_ERROR;
    }
  }
  i += len;

  switch((*message)->message_type_)
  {
    case MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER:
            if(mudir_drvmsg_reg_deserialize(
                  *message, &buffer[i], (size - i)
                  ) != MUDIR_SUCCESS)
            {
              mudir_drvmsg_free(message);
              return MUDIR_ERROR;
            }
            break;

    case MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK:
            if(mudir_drvmsg_ack_deserialize(
                  *message, &buffer[i], (size - i)
                  ) != MUDIR_SUCCESS)
            {
              mudir_drvmsg_free(message);
              return MUDIR_ERROR;
            }
            break;

    case MUDIR_DRIVERMSG_TYPE_DEVICE_QUERY:
    case MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND:
            if(mudir_drvmsg_comqry_deserialize(
                  *message, &buffer[i], (size - i)
                  ) != MUDIR_SUCCESS)
            {
              mudir_drvmsg_free(message);
              return MUDIR_ERROR;
            }
            break;

    case MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY:
            if(mudir_drvmsg_rep_deserialize(
                  *message, &buffer[i], (size - i)
                  ) != MUDIR_SUCCESS)
            {
              mudir_drvmsg_free(message);
              return MUDIR_ERROR;
            }
            break;

    default:
            mudir_drvmsg_free(message);
            return MUDIR_ERROR;
  }

  return MUDIR_SUCCESS;
}
