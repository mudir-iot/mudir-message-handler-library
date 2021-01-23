#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>
#include "msghandlerdrv.h"
#include "msghandlerdrv_pvt.h"

int mudir_drvmsg_ack_init(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return MUDIR_ERROR;
  
  message->message = malloc(sizeof(struct mudir_driver_message_ack));
  if (message->message == NULL)
    return MUDIR_ERROR;
  
  ((struct mudir_driver_message_ack *) message->message)->name_[0] = '\0';
  ((struct mudir_driver_message_ack *) message->message)->inbound_[0] = '\0';
  ((struct mudir_driver_message_ack *) message->message)->outbound_[0] = '\0';
  ((struct mudir_driver_message_ack *) message->message)->mode_ = MUDIR_DRIVERMSG_ACK_MODE_UNASSIGNED;

  return MUDIR_SUCCESS;
}

int mudir_drvmsg_ack_clean(
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

int mudir_drvmsg_ack_serialize(
        mudir_driver_message            message,
        MUDIR_BYTE                      *buffer,
        size_t                          *index
        )
{
  /* TODO: Implement mudir_drvmsg_ack_serialize() */
  return MUDIR_SUCCESS;
}

int mudir_drvmsg_ack_deserialize(
        mudir_driver_message            message,
        MUDIR_BYTE                      *buffer,
        size_t                          size
        )
{
  /* TODO: Implement mudir_drvmsg_ack_deserialize() */
  return MUDIR_SUCCESS;
}

int mudir_drvmsg_ack_name_set(
        mudir_driver_message            message,
        const char                      *name
        )
{
  struct mudir_driver_message_ack *ackmessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (NULL == name)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  ackmessage = (struct mudir_driver_message_ack*)(message->message);
  strncpy(ackmessage->name_, name, MUDIR_MAX_NAME_LEN);

  return MUDIR_SUCCESS;
}

const char * 
    mudir_drvmsg_ack_name_get(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return NULL;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK != message->message_type_)
    return NULL;

  if (NULL == message->message)
    return NULL;

  return ((struct mudir_driver_message_ack*)(message->message))->name_;
}

int mudir_drvmsg_ack_mode_set(
        mudir_driver_message            message,
        mudir_drivermsg_ack_mode_type   mode
        )
{
  struct mudir_driver_message_ack *ackmessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_ACK_MODE_UNASSIGNED > mode || MUDIR_DRIVERMSG_ACK_MODE_IPC < mode)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  ackmessage = (struct mudir_driver_message_ack*)(message->message);
  ackmessage->mode_ = mode;

  return MUDIR_SUCCESS;
}

const mudir_drivermsg_ack_mode_type 
    mudir_drvmsg_ack_mode_get(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return MUDIR_DRIVERMSG_ACK_MODE_UNASSIGNED;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK != message->message_type_)
    return MUDIR_DRIVERMSG_ACK_MODE_UNASSIGNED;

  if (NULL == message->message)
    return MUDIR_DRIVERMSG_ACK_MODE_UNASSIGNED;

  return ((struct mudir_driver_message_ack*)(message->message))->mode_;
}

int mudir_drvmsg_ack_inaddr_set(
        mudir_driver_message            message,
        const char                      *inaddr
        )
{
  struct mudir_driver_message_ack *ackmessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (NULL == inaddr)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  ackmessage = (struct mudir_driver_message_ack*)(message->message);
  strncpy(ackmessage->inbound_, inaddr, MUDIR_MAX_STRING_LEN);

  return MUDIR_SUCCESS;
}

const char * 
    mudir_drvmsg_ack_inaddr_get(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return NULL;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK != message->message_type_)
    return NULL;

  if (NULL == message->message)
    return NULL;

  return ((struct mudir_driver_message_ack*)(message->message))->inbound_;
}

int mudir_drvmsg_ack_outaddr_set(
        mudir_driver_message            message,
        const char                      *outaddr
        )
{
  struct mudir_driver_message_ack *ackmessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (NULL == outaddr)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  ackmessage = (struct mudir_driver_message_ack*)(message->message);
  strncpy(ackmessage->outbound_, outaddr, MUDIR_MAX_STRING_LEN);

  return MUDIR_SUCCESS;
}

const char * 
    mudir_drvmsg_ack_outaddr_get(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return NULL;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER_ACK != message->message_type_)
    return NULL;

  if (NULL == message->message)
    return NULL;

  return ((struct mudir_driver_message_ack*)(message->message))->outbound_;
}
