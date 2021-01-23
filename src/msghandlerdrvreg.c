
#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>
#include "msghandlerdrv.h"
#include "msghandlerdrv_pvt.h"

int mudir_drvmsg_reg_init(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return MUDIR_ERROR;
  
  message->message = malloc(sizeof(struct mudir_driver_message_reg));
  if (message->message == NULL)
    return MUDIR_ERROR;
  
  ((struct mudir_driver_message_reg *) message->message)->name_[0] = '\0';
  ((struct mudir_driver_message_reg *) message->message)->snap_name_[0] = '\0';
  ((struct mudir_driver_message_reg *) message->message)->snap_version_[0] = '\0';
  ((struct mudir_driver_message_reg *) message->message)->num_capabilities_ = 0;
  ((struct mudir_driver_message_reg *) message->message)->capabilities_ = NULL;

  return MUDIR_SUCCESS;
}

int mudir_drvmsg_reg_clean(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;
  
  if (((struct mudir_driver_message_reg *) message->message)->capabilities_ != NULL)
    free(((struct mudir_driver_message_reg *) message->message)->capabilities_);

  free(message->message);
  message->message = NULL;
  message->message_type_ = MUDIR_DRIVERMSG_TYPE_DRIVER_UNASSIGNED;

  return MUDIR_SUCCESS;
}

int mudir_drvmsg_reg_serialize(
        mudir_driver_message            message,
        MUDIR_BYTE                      *buffer,
        size_t                          *index
        )
{
  size_t len = 0;
  size_t i = *index;

  struct mudir_driver_message_reg *reg_msg = 
        (struct mudir_driver_message_reg *) message->message;

  len = strnlen(reg_msg->name_, MUDIR_MAX_NAME_LEN);
  memcpy(&buffer[i], &len, sizeof(size_t));
  i += sizeof(size_t);

  memcpy(&buffer[i], reg_msg->name_, len);
  i += len;

  len = strnlen(reg_msg->snap_name_, MUDIR_MAX_NAME_LEN);
  memcpy(&buffer[i], &len, sizeof(size_t));
  i += sizeof(size_t);

  memcpy(&buffer[i], reg_msg->snap_name_, len);
  i += len;

  len = strnlen(reg_msg->snap_version_, MUDIR_MAX_VER_LEN);
  memcpy(&buffer[i], &len, sizeof(size_t));
  i += sizeof(size_t);

  memcpy(&buffer[i], reg_msg->snap_version_, len);
  i += len;

  memcpy(&buffer[i], &reg_msg->num_capabilities_, sizeof(reg_msg->num_capabilities_));
  i += sizeof(reg_msg->num_capabilities_);

  int j;
  struct mudir_driver_message_reg_cap *cap_msg;

  for(j = 0; j < reg_msg->num_capabilities_; j++)
  {
    cap_msg = &reg_msg->capabilities_[j];

    memcpy(&buffer[i], &cap_msg->driver_type_, sizeof(cap_msg->driver_type_));
    i += sizeof(cap_msg->driver_type_);

    len = strnlen(cap_msg->name_, MUDIR_MAX_NAME_LEN);
    memcpy(&buffer[i], &len, sizeof(size_t));
    i += sizeof(size_t);

    memcpy(&buffer[i], cap_msg->name_, len);
    i += len;

    len = strnlen(cap_msg->desc_, MUDIR_MAX_DESC_LEN);
    memcpy(&buffer[i], &len, sizeof(size_t));
    i += sizeof(size_t);

    memcpy(&buffer[i], cap_msg->desc_, len);
    i += len;

    memcpy(&buffer[i], &cap_msg->return_type_, sizeof(cap_msg->return_type_));
    i += sizeof(cap_msg->return_type_);

  }

  *index = i;

  return MUDIR_SUCCESS;
}

int mudir_drvmsg_reg_deserialize(
        mudir_driver_message            message,
        MUDIR_BYTE                      *buffer,
        size_t                          size
        )
{
  /* TODO: Implement mudir_drvmsg_reg_deserialize() */
  return MUDIR_SUCCESS;
}

int mudir_drvmsg_reg_name_set(
        mudir_driver_message            message,
        const char *                    name
        )
{
  struct mudir_driver_message_reg *regmessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (NULL == name)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  regmessage = (struct mudir_driver_message_reg*)(message->message);
  strncpy(regmessage->name_, name, MUDIR_MAX_NAME_LEN);

  return MUDIR_SUCCESS;
}

const char *
    mudir_drvmsg_reg_name_get(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return NULL;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER != message->message_type_)
    return NULL;

  if (NULL == message->message)
    return NULL;

  return ((struct mudir_driver_message_reg*)(message->message))->name_;
}

int mudir_drvmsg_reg_snapname_set(
        mudir_driver_message            message,
        const char *                    snapname
        )
{
  struct mudir_driver_message_reg *regmessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (NULL == snapname)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  regmessage = (struct mudir_driver_message_reg*)(message->message);
  strncpy(regmessage->snap_name_, snapname, MUDIR_MAX_NAME_LEN);

  return MUDIR_SUCCESS;
}

const char *
    mudir_drvmsg_reg_snapname_get(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return NULL;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER != message->message_type_)
    return NULL;

  if (NULL == message->message)
    return NULL;

  return ((struct mudir_driver_message_reg*)(message->message))->snap_name_;
}

int mudir_drvmsg_reg_snapversion_set(
        mudir_driver_message            message,
        const char *                    snapversion
        )
{
  struct mudir_driver_message_reg *regmessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (NULL == snapversion)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  regmessage = (struct mudir_driver_message_reg*)(message->message);
  strncpy(regmessage->snap_version_, snapversion, MUDIR_MAX_VER_LEN);

  return MUDIR_SUCCESS;
}

const char *
    mudir_drvmsg_reg_snapversion_get(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return NULL;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER != message->message_type_)
    return NULL;

  if (NULL == message->message)
    return NULL;

  return ((struct mudir_driver_message_reg*)(message->message))->snap_version_;
}

int mudir_drvmsg_reg_cap_count_set(
        mudir_driver_message            message,
        const int                       count
        )
{
  struct mudir_driver_message_reg *regmessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (0 >= count)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  struct mudir_driver_message_reg_cap *regcapmsg;
  struct mudir_driver_message_reg_cap *oldregcapmsg;

  regmessage = (struct mudir_driver_message_reg *) message->message;
  oldregcapmsg = regmessage->capabilities_;
  regcapmsg = (struct mudir_driver_message_reg_cap *) malloc(count * sizeof(struct mudir_driver_message_reg_cap));

  if (NULL == regcapmsg)
    return MUDIR_ERROR;
  
  for (int i = 0; i < count; i++)
  {
    if (i < regmessage->num_capabilities_)
    {
      strncpy(regcapmsg[i].name_, oldregcapmsg[i].name_, MUDIR_MAX_NAME_LEN);
      strncpy(regcapmsg[i].desc_, oldregcapmsg[i].desc_, MUDIR_MAX_DESC_LEN);
      regcapmsg[i].driver_type_ = oldregcapmsg[i].driver_type_;
      regcapmsg[i].return_type_ = oldregcapmsg[i].return_type_;
    }
    else
    {
      regcapmsg[i].name_[0] = '\0';
      regcapmsg[i].desc_[0] = '\0';
      regcapmsg[i].driver_type_ = MUDIR_DRIVER_TYPE_UNKNOWN;
      regcapmsg[i].return_type_ = MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN;
    }
    
  }

  regmessage->capabilities_ = regcapmsg;
  regmessage->num_capabilities_ = count;
  free(oldregcapmsg);

  return MUDIR_SUCCESS;
}

const int
    mudir_drvmsg_reg_cap_count_get(
        mudir_driver_message            message
        )
{
  if (NULL == message)
    return -1;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER != message->message_type_)
    return -1;

  if (NULL == message->message)
    return -1;
  
  return ((struct mudir_driver_message_reg*)(message->message))->num_capabilities_;
}

int mudir_drvmsg_reg_cap_drvtype_set(
        mudir_driver_message            message,
        const int                       index,
        const mudir_driver_type         driver_type
        )
{
  struct mudir_driver_message_reg *regmessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVER_TYPE_UNKNOWN > driver_type || MUDIR_DRIVER_TYPE_CONTROLLER < driver_type)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  regmessage = (struct mudir_driver_message_reg*)(message->message);

  if (0 > index || regmessage->num_capabilities_ <= index)
    return MUDIR_ERROR;
  
  if (NULL == regmessage->capabilities_)
    return MUDIR_ERROR;
  
  regmessage->capabilities_[index].driver_type_ = driver_type;

  return MUDIR_SUCCESS;
}

const mudir_driver_type
    mudir_drvmsg_reg_cap_drvtype_get(
        mudir_driver_message            message,
        const int                       index
        )
{
  struct mudir_driver_message_reg *regmessage;

  if (NULL == message)
    return MUDIR_DRIVER_TYPE_UNKNOWN;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER != message->message_type_)
    return MUDIR_DRIVER_TYPE_UNKNOWN;

  if (NULL == message->message)
    return MUDIR_DRIVER_TYPE_UNKNOWN;

  regmessage = (struct mudir_driver_message_reg*)(message->message);

  if (0 > index || regmessage->num_capabilities_ <= index)
    return MUDIR_DRIVER_TYPE_UNKNOWN;
  
  if (NULL == regmessage->capabilities_)
    return MUDIR_DRIVER_TYPE_UNKNOWN;
  
  return regmessage->capabilities_[index].driver_type_;
}

int mudir_drvmsg_reg_cap_name_set(
        mudir_driver_message            message,
        const int                       index,
        const char *                    name
        )
{
  struct mudir_driver_message_reg *regmessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (NULL == name)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  regmessage = (struct mudir_driver_message_reg*)(message->message);

  if (0 > index || regmessage->num_capabilities_ <= index)
    return MUDIR_ERROR;
  
  if (NULL == regmessage->capabilities_)
    return MUDIR_ERROR;
  
  strncpy(regmessage->capabilities_[index].name_, name, MUDIR_MAX_NAME_LEN);

  return MUDIR_SUCCESS;
}

const char *
    mudir_drvmsg_reg_cap_name_get(
        mudir_driver_message            message,
        const int                       index
        )
{
  struct mudir_driver_message_reg *regmessage;

  if (NULL == message)
    return NULL;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER != message->message_type_)
    return NULL;

  if (NULL == message->message)
    return NULL;

  regmessage = (struct mudir_driver_message_reg*)(message->message);

  if (0 > index || regmessage->num_capabilities_ <= index)
    return NULL;
  
  if (NULL == regmessage->capabilities_)
    return NULL;
  
  return regmessage->capabilities_[index].name_;
}

int mudir_drvmsg_reg_cap_desc_set(
        mudir_driver_message            message,
        const int                       index,
        const char *                    description
        )
{
  struct mudir_driver_message_reg *regmessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (NULL == description)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  regmessage = (struct mudir_driver_message_reg*)(message->message);

  if (0 > index || regmessage->num_capabilities_ <= index)
    return MUDIR_ERROR;
  
  if (NULL == regmessage->capabilities_)
    return MUDIR_ERROR;
  
  strncpy(regmessage->capabilities_[index].desc_, description, MUDIR_MAX_DESC_LEN);

  return MUDIR_SUCCESS;
}

const char *
    mudir_drvmsg_reg_cap_desc_get(
        mudir_driver_message            message,
        const int                       index
        )
{
  struct mudir_driver_message_reg *regmessage;

  if (NULL == message)
    return NULL;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER != message->message_type_)
    return NULL;

  if (NULL == message->message)
    return NULL;

  regmessage = (struct mudir_driver_message_reg*)(message->message);

  if (0 > index || regmessage->num_capabilities_ <= index)
    return NULL;
  
  if (NULL == regmessage->capabilities_)
    return NULL;
  
  return regmessage->capabilities_[index].desc_;
}

int mudir_drvmsg_reg_cap_returntype_set(
        mudir_driver_message            message,
        const int                       index,
        const mudir_drivermsg_data_type return_type
        )
{
  struct mudir_driver_message_reg *regmessage;

  if (NULL == message)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN > return_type || MUDIR_DRIVERMSG_RETURN_TYPE_JSON < return_type)
    return MUDIR_ERROR;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER != message->message_type_)
    return MUDIR_ERROR;

  if (NULL == message->message)
    return MUDIR_ERROR;

  regmessage = (struct mudir_driver_message_reg*)(message->message);

  if (0 > index || regmessage->num_capabilities_ <= index)
    return MUDIR_ERROR;
  
  if (NULL == regmessage->capabilities_)
    return MUDIR_ERROR;
  
  regmessage->capabilities_[index].return_type_ = return_type;

  return MUDIR_SUCCESS;
}

const mudir_drivermsg_data_type
    mudir_drvmsg_reg_cap_returntype_get(
        mudir_driver_message            message,
        const int                       index
        )
{
  struct mudir_driver_message_reg *regmessage;

  if (NULL == message)
    return MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN;
  
  if (MUDIR_DRIVERMSG_TYPE_DRIVER_REGISTER != message->message_type_)
    return MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN;

  if (NULL == message->message)
    return MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN;

  regmessage = (struct mudir_driver_message_reg*)(message->message);

  if (0 > index || regmessage->num_capabilities_ <= index)
    return MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN;
  
  if (NULL == regmessage->capabilities_)
    return MUDIR_DRIVERMSG_RETURN_TYPE_UNKNOWN;
  
  return regmessage->capabilities_[index].return_type_;
}
