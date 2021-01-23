#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>
#include "msghandlerdrv.h"
#include "msghandlerdrv_pvt.h"

int mudir_drvmsg_rep_init(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return MUDIR_ERROR;
  
  message->message = malloc(sizeof(struct mudir_driver_message_devreply));
  if (message->message == NULL)
    return MUDIR_ERROR;
  
  ((struct mudir_driver_message_devreply *) message->message)->driver_name_[0] = '\0';
  ((struct mudir_driver_message_devreply *) message->message)->device_name_[0] = '\0';
  ((struct mudir_driver_message_devreply *) message->message)->value_[0] = '\0';
  ((struct mudir_driver_message_devreply *) message->message)->unit_[0] = '\0';

  return MUDIR_SUCCESS;
}

int mudir_drvmsg_rep_clean(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;
  
  free(message->message);
  message->message = NULL;
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_UNASSIGNED;

  return MUDIR_SUCCESS;
}

int mudir_drvmsg_rep_serialize(
        mudir_driver_message            message,
        MUDIR_BYTE                      *buffer,
        size_t                          *index
        )
{
  /* TODO: Implement mudir_drvmsg_rep_serialize() */
  return MUDIR_SUCCESS;
}

int mudir_drvmsg_rep_deserialize(
        mudir_driver_message            message,
        MUDIR_BYTE                      *buffer,
        size_t                          size
        )
{
  /* TODO: Implement mudir_drvmsg_rep_deserialize() */
  return MUDIR_SUCCESS;
}

int mudir_drvmsg_reply_driver_name_set(
        mudir_driver_message            message,
        const char                      *driver_name
        )
{
  struct mudir_driver_message_devreply *replymessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (NULL == driver_name)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  replymessage = (struct mudir_driver_message_devreply*)(message->message);
  strncpy(replymessage->driver_name_, driver_name, MUDIR_MAX_NAME_LEN);

  return MUDIR_SUCCESS;
}

const char * 
    mudir_drvmsg_reply_driver_name_get(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return NULL;
  
  if (MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY != message->message_type_)
    return NULL;

  if (NULL == message->message)
    return NULL;

  return ((struct mudir_driver_message_devreply*)(message->message))->driver_name_;
}

int mudir_drvmsg_reply_device_name_set(
        mudir_driver_message            message,
        const char                      *device_name
        )
{
  struct mudir_driver_message_devreply *replymessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (NULL == device_name)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  replymessage = (struct mudir_driver_message_devreply*)(message->message);
  strncpy(replymessage->device_name_, device_name, MUDIR_MAX_NAME_LEN);

  return MUDIR_SUCCESS;
}

const char * 
    mudir_drvmsg_reply_device_name_get(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return NULL;
  
  if (MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY != message->message_type_)
    return NULL;

  if (NULL == message->message)
    return NULL;

  return ((struct mudir_driver_message_devreply*)(message->message))->device_name_;
}

int mudir_drvmsg_reply_value_set(
        mudir_driver_message            message,
        const char                      *value
        )
{
  struct mudir_driver_message_devreply *replymessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (NULL == value)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  replymessage = (struct mudir_driver_message_devreply*)(message->message);
  strncpy(replymessage->value_, value, MUDIR_MAX_STRING_LEN);

  return MUDIR_SUCCESS;
}

const char * 
    mudir_drvmsg_reply_value_get(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return NULL;
  
  if (MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY != message->message_type_)
    return NULL;

  if (NULL == message->message)
    return NULL;

  return ((struct mudir_driver_message_devreply*)(message->message))->value_;
}

int mudir_drvmsg_reply_unit_set(
        mudir_driver_message            message,
        const char                      *unit
        )
{
  struct mudir_driver_message_devreply *replymessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (NULL == unit)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  replymessage = (struct mudir_driver_message_devreply*)(message->message);
  strncpy(replymessage->unit_, unit, MUDIR_MAX_NAME_LEN);

  return MUDIR_SUCCESS;
}

const char * 
    mudir_drvmsg_reply_unit_get(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return NULL;
  
  if (MUDIR_DRIVERMSG_TYPE_DEVICE_REPLY != message->message_type_)
    return NULL;

  if (NULL == message->message)
    return NULL;

  return ((struct mudir_driver_message_devreply*)(message->message))->unit_;
}