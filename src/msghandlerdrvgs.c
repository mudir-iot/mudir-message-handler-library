/*
 *  Mudir IoT Driver Message Handler Library
 *  Copyright (C) 2021  Biswajit Dhar
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>
#include "msghandlerdrv.h"
#include "msghandlerdrv_pvt.h"

mudir_drivermsg_version_type 
    mudir_drvmsg_version_get(
        mudir_driver_message           message
        )
{
  if (NULL == message)
  {
    return MUDIR_DRIVERMSG_VERSION_UNASSIGNED;
  }

  return message->version_;
}

int mudir_drvmsg_messagetype_set(
        mudir_driver_message            message,
        mudir_drivermsg_message_type    message_type
        )
{
  if (NULL == message)
    return MUDIR_ERROR;

  if ((MUDIR_DRIVERMSG_TYPE_DRIVER_UNASSIGNED >= message_type) || 
      (MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY      <  message_type))
    return MUDIR_ERROR;
  
  if (MUDIR_ERROR == mudir_drvmsg_clean(message))
    return MUDIR_ERROR;
  
  switch(message_type)
  {
    case MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER:
      if (MUDIR_ERROR == mudir_drvmsg_reg_init(message))
        return MUDIR_ERROR;

      break;

    case MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK:
      if (MUDIR_ERROR == mudir_drvmsg_ack_init(message))
        return MUDIR_ERROR;

      break;

    case MUDIR_DRIVERMSG_TYPE_DEVICE_QUERY:
    case MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND:
      if (MUDIR_ERROR == mudir_drvmsg_comqry_init(message))
        return MUDIR_ERROR;

      break;

    case MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY:
      if (MUDIR_ERROR == mudir_drvmsg_rep_init(message))
        return MUDIR_ERROR;

      break;

    default:
      return MUDIR_ERROR;
  }
      
  message->message_type_ = message_type;

  return MUDIR_SUCCESS;
}

mudir_drivermsg_message_type
    mudir_drvmsg_messagetype_get(
        mudir_driver_message            message
        )
{
  if (NULL == message)
  {
    return MUDIR_DRIVERMSG_TYPE_DRIVER_UNASSIGNED;
  }

  return message->message_type_;
}

int mudir_drvmsg_errorcode_set(
        mudir_driver_message            message,
        mudir_drivermsg_message_error   error_code
        )
{
  if (NULL == message)
    return MUDIR_ERROR;

  if ((MUDIR_DRIVERMSG_ERROR_NO_ERROR > error_code) ||
      (MUDIR_DRIVERMSG_ERROR_OTHER < error_code))
    return MUDIR_ERROR;
  
  message->error_ = error_code;
  return MUDIR_SUCCESS;
}

mudir_drivermsg_message_error
    mudir_drvmsg_errorcode_get(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return MUDIR_DRIVERMSG_ERROR_NO_MESSAGE;
  
  return message->error_;
}

int mudir_drvmsg_errordesc_set(
        mudir_driver_message            message,
        const char *                    errordesc
        )
{
  if (NULL == message)
    return MUDIR_ERROR;
  
  if (NULL == errordesc)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_ERROR_OTHER != message->error_)
    return MUDIR_ERROR;
  
  if (NULL == message->error_desc_)
    message->error_desc_ = (char *) calloc(MUDIR_MAX_STRING_LEN, sizeof(char));
  
  strncpy(message->error_desc_, errordesc, MUDIR_MAX_STRING_LEN);

  return MUDIR_SUCCESS;
}

const char *
    mudir_drvmsg_errordesc_get(
        mudir_driver_message            message
        )
{
  const char * mudir_error_description[] =
  {
          "No errors",
          "No message object",
          "Invalid data has been sent/received",
          "The device is unavailable",
          "The device has returned an error",
          "An unknown error"
  };

  if (NULL == message)
    return NULL;
  
  if ((MUDIR_DRIVERMSG_ERROR_NO_ERROR > message->error_) ||
      (MUDIR_DRIVERMSG_ERROR_OTHER < message->error_))
    return NULL;
    
  if ((MUDIR_DRIVERMSG_ERROR_OTHER == message->error_) &&
      (NULL != message->error_desc_) &&
      (0 < strnlen(message->error_desc_, MUDIR_MAX_STRING_LEN)))
    return message->error_desc_;
  
  return mudir_error_description[message->error_];
}

int mudir_drvmsg_clean(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return MUDIR_ERROR;
  
  if (NULL != message->message)
    switch (message->message_type_)
    {
      case MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER:
        if (mudir_drvmsg_reg_clean(message) != MUDIR_SUCCESS)
          return MUDIR_ERROR;
        
        break;

      case MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK:
        if (mudir_drvmsg_ack_clean(message) != MUDIR_SUCCESS)
          return MUDIR_ERROR;
        
        break;

      case MUDIR_DRIVERMSG_TYPE_DEVICE_QUERY:
      case MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND:
        if (mudir_drvmsg_comqry_clean(message) != MUDIR_SUCCESS)
          return MUDIR_ERROR;
        
        break;
        
      case MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY:
        if (mudir_drvmsg_rep_clean(message) != MUDIR_SUCCESS)
          return MUDIR_ERROR;
        
        break;
    
      default:            /* Inconsistency. May not be properly cleaned up */
        free(message->message);
        message->message = NULL;
        break;
    }
  
  return MUDIR_SUCCESS;
}