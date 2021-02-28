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
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <arpa/inet.h>
#include "msghandlerdrv.h"
#include "msghandlerdrv_pvt.h"

int mudir_drvmsg_comqry_init(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return MUDIR_ERROR;
  
  message->message = malloc(sizeof(struct mudir_driver_message_reg));
  if (message->message == NULL)
    return MUDIR_ERROR;
  
  ((struct mudir_driver_message_devcomqry *) message->message)->driver_name_[0] = '\0';
  ((struct mudir_driver_message_devcomqry *) message->message)->device_name_[0] = '\0';
  ((struct mudir_driver_message_devcomqry *) message->message)->num_opts_ = 0;
  ((struct mudir_driver_message_devcomqry *) message->message)->options_ = NULL;

  return MUDIR_SUCCESS;
}

int mudir_drvmsg_comqry_clean(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;
  
  if (((struct mudir_driver_message_devcomqry *) message->message)->options_ != NULL)
    free(((struct mudir_driver_message_devcomqry *) message->message)->options_);

  free(message->message);
  message->message = NULL;
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_UNASSIGNED;

  return MUDIR_SUCCESS;
}

int mudir_drvmsg_comqry_serialize(
        mudir_driver_message            message,
        MUDIR_BYTE                      *buffer,
        size_t                          *index
        )
{
  /* TODO: Implement mudir_drvmsg_comqry_serialize() */
  return MUDIR_SUCCESS;
}

int mudir_drvmsg_comqry_deserialize(
        mudir_driver_message            message,
        MUDIR_BYTE                      *buffer,
        size_t                          size
        )
{
  /* TODO: Implement mudir_drvmsg_comqry_deserialize() */
  return MUDIR_SUCCESS;
}

int mudir_drvmsg_comqry_driver_name_set(
        mudir_driver_message            message,
        const char                      *driver_name
        )
{
  struct mudir_driver_message_devcomqry *comqrymessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (NULL == driver_name)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DEVICE_QUERY != message->message_type_ && 
      MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  comqrymessage = (struct mudir_driver_message_devcomqry*)(message->message);
  strncpy(comqrymessage->driver_name_, driver_name, MUDIR_MAX_NAME_LEN);

  return MUDIR_SUCCESS;
}

const char * 
    mudir_drvmsg_comqry_driver_name_get(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return NULL;
  
  if (MUDIR_DRIVERMSG_TYPE_DEVICE_QUERY != message->message_type_ && 
      MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND != message->message_type_)
    return NULL;

  if (NULL == message->message)
    return NULL;

  return ((struct mudir_driver_message_devcomqry*)(message->message))->driver_name_;
}

int mudir_drvmsg_comqry_device_name_set(
        mudir_driver_message            message,
        const char                      *device_name
        )
{
  struct mudir_driver_message_devcomqry *comqrymessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (NULL == device_name)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DEVICE_QUERY != message->message_type_ && 
      MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  comqrymessage = (struct mudir_driver_message_devcomqry*)(message->message);
  strncpy(comqrymessage->device_name_, device_name, MUDIR_MAX_NAME_LEN);

  return MUDIR_SUCCESS;
}

const char * 
    mudir_drvmsg_comqry_device_name_get(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return NULL;
  
  if (MUDIR_DRIVERMSG_TYPE_DEVICE_QUERY != message->message_type_ && 
      MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND != message->message_type_)
    return NULL;

  if (NULL == message->message)
    return NULL;

  return ((struct mudir_driver_message_devcomqry*)(message->message))->device_name_;
}

int mudir_drvmsg_comqry_opts_count_set(
        mudir_driver_message            message,
        const int                       count
        )
{
  struct mudir_driver_message_devcomqry *comqrymessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (0 >= count)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DEVICE_QUERY != message->message_type_ && 
      MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  comqrymessage = (struct mudir_driver_message_devcomqry*)(message->message);

struct mudir_driver_message_devopts *optsComQrymsg;

  /*
   * Deliberately using realloc for shallow copy as the structure
   * is simple. May need to be modified for deep copy if the 
   * structure gets "complicated".
   */

  optsComQrymsg = (struct mudir_driver_message_devopts *) realloc(comqrymessage->options_, count * sizeof(struct mudir_driver_message_devopts));
  if (NULL == optsComQrymsg)
    return MUDIR_ERROR;
  
  /*
   * Simple initialize the additional capabilities.
   */
  for (int i = comqrymessage->num_opts_; i < count; i++)
  {
    optsComQrymsg[i].key_[0] = '\0';
    memset(optsComQrymsg[i].value_, 0, MUDIR_MAX_BUFFER_SIZE);
    optsComQrymsg[i].type_ = MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN;
  }

  comqrymessage->options_ = optsComQrymsg;
  comqrymessage->num_opts_ = count;

  return MUDIR_SUCCESS;
}

int mudir_drvmsg_comqry_opts_count_get(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return -1;
  
  if (MUDIR_DRIVERMSG_TYPE_DEVICE_QUERY != message->message_type_ && 
      MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND != message->message_type_)
    return -1;

  if (NULL == message->message)
    return -1;
  
  return ((struct mudir_driver_message_devcomqry*)(message->message))->num_opts_;
}

int mudir_drvmsg_comqry_opts_key_set(
        mudir_driver_message            message,
        const int                       index,
        const char                      *key
        )
{
  struct mudir_driver_message_devcomqry *comqrymessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (NULL == key)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DEVICE_QUERY != message->message_type_ && 
      MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  comqrymessage = (struct mudir_driver_message_devcomqry*)(message->message);

  if (0 > index || comqrymessage->num_opts_ <= index)
    return MUDIR_ERROR;
  
  if (NULL == comqrymessage->options_)
    return MUDIR_ERROR;
  
  strncpy(comqrymessage->options_[index].key_, key, MUDIR_MAX_NAME_LEN);

  return MUDIR_SUCCESS;
}

const char * 
    mudir_drvmsg_comqry_opts_key_get(
        mudir_driver_message            message,
        const int                       index
        )
{
  struct mudir_driver_message_devcomqry *comqrymessage;

  if (NULL == message)
    return NULL;
  
  if (MUDIR_DRIVERMSG_TYPE_DEVICE_QUERY != message->message_type_ && 
      MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND != message->message_type_)
    return NULL;

  if (NULL == message->message)
    return NULL;

  comqrymessage = (struct mudir_driver_message_devcomqry*)(message->message);

  if (0 > index || comqrymessage->num_opts_ <= index)
    return NULL;
  
  if (NULL == comqrymessage->options_)
    return NULL;
  
  return comqrymessage->options_[index].key_;
}

int mudir_drvmsg_comqry_opts_value_set(
        mudir_driver_message            message,
        const int                       index,
        const mudir_drivermsg_data_type type,
        const void                      *value
        )
{
  struct mudir_driver_message_devcomqry *comqrymessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (NULL == value)
    return MUDIR_ERROR;

  if (MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN > type ||
      MUDIR_DRIVERMSG_RETURN_TYPE_JSON    <  type)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DEVICE_QUERY != message->message_type_ && 
      MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  comqrymessage = (struct mudir_driver_message_devcomqry*)(message->message);

  if (0 > index || comqrymessage->num_opts_ <= index)
    return MUDIR_ERROR;
  
  if (NULL == comqrymessage->options_)
    return MUDIR_ERROR;
  
  switch(type)
  {
    case MUDIR_DRIVERMSG_RETURN_TYPE_BOOL:
      memset(comqrymessage->options_[index].value_, 0, MUDIR_MAX_BUFFER_SIZE);
      if (*((bool *) value) == true)
        comqrymessage->options_[index].value_[0] = 1;
      
      comqrymessage->options_[index].type_ = MUDIR_DRIVERMSG_RETURN_TYPE_BOOL;
      break;

    case MUDIR_DRIVERMSG_RETURN_TYPE_INTEGER:
      memset(comqrymessage->options_[index].value_, 0, MUDIR_MAX_BUFFER_SIZE);

      long correctedValue = htonl(*((long *) value));
      comqrymessage->options_[index].value_[0] = (correctedValue >> 24) & 0xFF;
      comqrymessage->options_[index].value_[1] = (correctedValue >> 16) & 0xFF;
      comqrymessage->options_[index].value_[2] = (correctedValue >> 8)  & 0xFF;
      comqrymessage->options_[index].value_[3] = (correctedValue >> 0)  & 0xFF;

      comqrymessage->options_[index].type_ = MUDIR_DRIVERMSG_RETURN_TYPE_INTEGER;
      break;

    case MUDIR_DRIVERMSG_RETURN_TYPE_FLOAT:
      memset(comqrymessage->options_[index].value_, 0, MUDIR_MAX_BUFFER_SIZE);

      long mant = 0;
      int exp = 0;

      mant = (long) (LONG_MAX * frexp((*((double *) value)), &exp));
      mant = htonl(mant);
      exp = (int) htons((unsigned int) exp);

      comqrymessage->options_[index].value_[0] = (mant >> 24) & 0xFF;
      comqrymessage->options_[index].value_[1] = (mant >> 16) & 0xFF;
      comqrymessage->options_[index].value_[2] = (mant >> 8)  & 0xFF;
      comqrymessage->options_[index].value_[3] = (mant >> 0)  & 0xFF;
      comqrymessage->options_[index].value_[4] = (exp  >> 8)  & 0xFF;
      comqrymessage->options_[index].value_[5] = (exp  >> 0)  & 0xFF;

      comqrymessage->options_[index].type_ = MUDIR_DRIVERMSG_RETURN_TYPE_FLOAT;
      break;

    case MUDIR_DRIVERMSG_RETURN_TYPE_STRING:
    case MUDIR_DRIVERMSG_RETURN_TYPE_JSON:
      memset(comqrymessage->options_[index].value_, 0, MUDIR_MAX_BUFFER_SIZE);
      strncpy((char *) comqrymessage->options_[index].value_, (const char *) value, MUDIR_MAX_BUFFER_SIZE);

      comqrymessage->options_[index].type_ = type;
      break;

    default:
      return MUDIR_ERROR;
  }

  return MUDIR_SUCCESS;
}

int mudir_drvmsg_comqry_opts_value_get(
        mudir_driver_message            message,
        const int                       index,
        const mudir_drivermsg_data_type type,
        void                            *value
        )
{
  struct mudir_driver_message_devcomqry *comqrymessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (NULL == value)
    return MUDIR_ERROR;

  if (MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN > type ||
      MUDIR_DRIVERMSG_RETURN_TYPE_JSON    <  type)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DEVICE_QUERY != message->message_type_ && 
      MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  comqrymessage = (struct mudir_driver_message_devcomqry*)(message->message);

  if (0 > index || comqrymessage->num_opts_ <= index)
    return MUDIR_ERROR;
  
  if (NULL == comqrymessage->options_)
    return MUDIR_ERROR;
  
  if (type != comqrymessage->options_[index].type_)
    return MUDIR_ERROR;
  
  bool *tbool;
  long tlong;
  int  tint;

  switch(type)
  {
    case MUDIR_DRIVERMSG_RETURN_TYPE_BOOL:
      tbool = value;
      if (comqrymessage->options_[index].value_[0] == 0)
        *tbool = false;
      else
        *tbool = true;
      
      break;
    
    case MUDIR_DRIVERMSG_RETURN_TYPE_INTEGER:
      tlong = 0;
      tlong = tlong | comqrymessage->options_[index].value_[0];
      tlong *= 0xFF;
      tlong = tlong | comqrymessage->options_[index].value_[1];
      tlong *= 0xFF;
      tlong = tlong | comqrymessage->options_[index].value_[2];
      tlong *= 0xFF;
      tlong = tlong | comqrymessage->options_[index].value_[3];

      *((long *) value) = ntohl(tlong);
      break;

    case MUDIR_DRIVERMSG_RETURN_TYPE_FLOAT:
      tlong = 0;
      tlong = tlong | comqrymessage->options_[index].value_[0];
      tlong *= 0xFF;
      tlong = tlong | comqrymessage->options_[index].value_[1];
      tlong *= 0xFF;
      tlong = tlong | comqrymessage->options_[index].value_[2];
      tlong *= 0xFF;
      tlong = tlong | comqrymessage->options_[index].value_[3];

      tint = 0;
      tint = tint | comqrymessage->options_[index].value_[4];
      tint *= 0xFF;
      tint = tint | comqrymessage->options_[index].value_[5];

      tlong = ntohl(tlong);
      tint  = ntohs(tint);

      *((double *) value) = ldexp((((double) tlong)/((double) LONG_MAX)), tint);
      break;

    case MUDIR_DRIVERMSG_RETURN_TYPE_STRING:
    case MUDIR_DRIVERMSG_RETURN_TYPE_JSON:
      memset(value, 0, MUDIR_MAX_NAME_LEN);
      strncpy((char *) value, (const char *) comqrymessage->options_[index].value_, MUDIR_MAX_NAME_LEN);
      break;
    
    default:
      return MUDIR_ERROR;
  }

  return MUDIR_SUCCESS;
}

mudir_drivermsg_data_type
    mudir_drvmsg_comqry_opts_valuetype_get(
        mudir_driver_message            message,
        const int                       index
        )
{
  struct mudir_driver_message_devcomqry *comqrymessage;

  if (NULL == message)
    return MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN;
  
  if (MUDIR_DRIVERMSG_TYPE_DEVICE_QUERY != message->message_type_ && 
      MUDIR_DRIVERMSG_TYPE_DEVICE_COMMAND != message->message_type_)
    return MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN;

  if (NULL == message->message)
    return MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN;

  comqrymessage = (struct mudir_driver_message_devcomqry*)(message->message);

  if (0 > index || comqrymessage->num_opts_ <= index)
    return MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN;
  
  if (NULL == comqrymessage->options_)
    return MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN;
  
  return comqrymessage->options_[index].type_;
}