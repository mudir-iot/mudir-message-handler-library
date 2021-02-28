/*
 *  Mudir IoT Driver Message Handler Library
 *  Copyright (C) 2021  Biswajit Dhar
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file
 * @brief Do not use, mudir internal, may be changed or removed at any time.
 */

#ifndef __MSGHANDLERDRV_PVT_H__
#define __MSGHANDLERDRV_PVT_H__

#ifdef __cplusplus
extern "C" {
#endif

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#define MUDIR_MAX_BUFFER_SIZE           10000
#define MUDIR_MAX_STRING_LEN            100
#define MUDIR_MAX_NAME_LEN              20
#define MUDIR_MAX_DESC_LEN              30
#define MUDIR_MAX_VER_LEN               10

/* #region __driver_message_types__ */

struct mudir_driver_message
{
  mudir_drivermsg_version_type          version_;
  mudir_drivermsg_message_type          message_type_;
  mudir_drivermsg_message_error         error_;
  char *                                error_desc_;
  void *                                message;            /* Dangerous but efficient */
};

struct mudir_driver_message_reg
{
  char                                  name_[MUDIR_MAX_NAME_LEN];
  char                                  snap_name_[MUDIR_MAX_NAME_LEN];
  char                                  snap_version_[MUDIR_MAX_VER_LEN];
  int                                   num_capabilities_;
  struct mudir_driver_message_reg_cap * capabilities_;
};

struct mudir_driver_message_reg_cap
{
  mudir_driver_type                     driver_type_;
  char                                  name_[MUDIR_MAX_NAME_LEN];
  char                                  desc_[MUDIR_MAX_DESC_LEN];
  mudir_drivermsg_data_type             return_type_;
};

struct mudir_driver_message_ack
{
  char                                  name_[MUDIR_MAX_NAME_LEN];
  mudir_drivermsg_ack_mode_type         mode_;
  char                                  inbound_[MUDIR_MAX_STRING_LEN];
  char                                  outbound_[MUDIR_MAX_STRING_LEN];
};

struct mudir_driver_message_devopts
{
  char                                  key_[MUDIR_MAX_NAME_LEN];
  MUDIR_BYTE                            value_[MUDIR_MAX_BUFFER_SIZE];
  mudir_drivermsg_data_type             type_;
};

struct mudir_driver_message_devcomqry
{
  char                                  driver_name_[MUDIR_MAX_NAME_LEN];
  char                                  device_name_[MUDIR_MAX_NAME_LEN];
  int                                   num_opts_;
  struct mudir_driver_message_devopts   *options_;
};

struct mudir_driver_message_devreply
{
  char                                  driver_name_[MUDIR_MAX_NAME_LEN];
  char                                  device_name_[MUDIR_MAX_NAME_LEN];
  char                                  value_[MUDIR_MAX_STRING_LEN];
  char                                  unit_[MUDIR_MAX_NAME_LEN];
};

/* #endregion */

/* #region __driver_message_methods__ */

/*
 * Cleans child message structures.
 */
int mudir_drvmsg_clean(
        mudir_driver_message            message
        ) MUDIR_PRIVATE;

/* #endregion */

/* #region __driver_registration_message_methods__ */

/*
 * Initializes Register Driver structure.
 */
int mudir_drvmsg_reg_init(
        mudir_driver_message            message
        ) MUDIR_PRIVATE;

/*
 * Cleans the driver registration message structure.
 */
int mudir_drvmsg_reg_clean(
        mudir_driver_message            message
        ) MUDIR_PRIVATE;

/*
 * Private method to serialize registration portion of the message.
 */
int mudir_drvmsg_reg_serialize(
        mudir_driver_message            message,
        MUDIR_BYTE                      *buffer,
        size_t                          *index
        ) MUDIR_PRIVATE;

/*
 * Private method to deseralize registration portion of the message.
 */
int mudir_drvmsg_reg_deserialize(
        mudir_driver_message            message,
        MUDIR_BYTE                      *buffer,
        size_t                          size
        ) MUDIR_PRIVATE;

/* #endregion */

/* #region __driver_acknowledgement_message_methods__ */

/*
 * Initializes Driver Registration Acknowledgement structure.
 */
int mudir_drvmsg_ack_init(
        mudir_driver_message            message
        ) MUDIR_PRIVATE;

/*
 * Cleans the driver registration acknowledge message structure.
 */
int mudir_drvmsg_ack_clean(
        mudir_driver_message            message
        ) MUDIR_PRIVATE;

/*
 * Private method to serialize registration acknowledgement portion of the message.
 */
int mudir_drvmsg_ack_serialize(
        mudir_driver_message            message,
        MUDIR_BYTE                      *buffer,
        size_t                          *index
        ) MUDIR_PRIVATE;

/*
 * Private method to deserialize registration acknowledgement portion of the message.
 */
int mudir_drvmsg_ack_deserialize(
        mudir_driver_message            message,
        MUDIR_BYTE                      *buffer,
        size_t                          size
        ) MUDIR_PRIVATE;

/* #endregion */

/* #region __device_command_query_message_methods__ */

/*
 * Initializes Device Query structure.
 */
int mudir_drvmsg_comqry_init(
        mudir_driver_message            message
        ) MUDIR_PRIVATE;

/*
 * Cleans the device query message structure.
 */
int mudir_drvmsg_comqry_clean(
        mudir_driver_message            message
        ) MUDIR_PRIVATE;

/*
 * Private method to serialize device query portion of the message.
 */
int mudir_drvmsg_comqry_serialize(
        mudir_driver_message            message,
        MUDIR_BYTE                      *buffer,
        size_t                          *index
        ) MUDIR_PRIVATE;

/*
 * Private method to deserialize device query portion of the message.
 */
int mudir_drvmsg_comqry_deserialize(
        mudir_driver_message            message,
        MUDIR_BYTE                      *buffer,
        size_t                          size
        ) MUDIR_PRIVATE;

/* #endregion */

/* #region __device_reply_message_types__ */

/*
 * Initializes device reply message structure.
 */
int mudir_drvmsg_rep_init(
        mudir_driver_message            message
        ) MUDIR_PRIVATE;

/*
 * Cleans the device reply message structure.
 */
int mudir_drvmsg_rep_clean(
        mudir_driver_message            message
        ) MUDIR_PRIVATE;

/*
 * Private method to serialize device reply portion of the
 * message.
 */
int mudir_drvmsg_rep_serialize(
        mudir_driver_message            message,
        MUDIR_BYTE                      *buffer,
        size_t                          *index
        ) MUDIR_PRIVATE;

/*
 * Private method to deserialize device reply portion of the
 * message.
 */
int mudir_drvmsg_rep_deserialize(
        mudir_driver_message            message,
        MUDIR_BYTE                      *buffer,
        size_t                          size
        ) MUDIR_PRIVATE;

/* #endregion */

#ifdef __cplusplus
}
#endif

#endif //__MSGHANDLERDRV_PVT_H__