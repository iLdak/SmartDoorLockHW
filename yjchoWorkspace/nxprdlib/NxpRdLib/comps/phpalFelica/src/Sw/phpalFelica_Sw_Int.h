/*
*         Copyright (c), NXP Semiconductors Gratkorn / Austria
*
*                     (C)NXP Semiconductors
*       All rights are reserved. Reproduction in whole or in part is
*      prohibited without the written consent of the copyright owner.
*  NXP reserves the right to make changes without notice at any time.
* NXP makes no warranty, expressed, implied or statutory, including but
* not limited to any implied warranty of merchantability or fitness for any
*particular purpose, or that the use will not infringe any third party patent,
* copyright or trademark. NXP must not be liable for any loss or damage
*                          arising from its use.
*/

/** \file
* Internal definitions for Software palFelica Component of Reader Library Framework.
* $Author: jenkins_ cm (nxp92197) $
* $Revision: 4258 $ (NFCRDLIB_V4.010.03.001609 : 4184 $ (NFCRDLIB_V4.010.01.001603 : 3719 ))
* $Date: 2016-03-01 16:44:26 +0530 (Tue, 01 Mar 2016) $
*
* History:
*  RSn: Generated 28. January 2010
*
*/

#ifndef PHPALFELICA_SW_INT_H
#define PHPALFELICA_SW_INT_H

#include <ph_Status.h>

/** \addtogroup ph_Private
* @{
*/

/** \name Felica Command Codes
*/
/*@{*/
#define PHPAL_FELICA_SW_CMD_REQC            0x00U   /**< RequestC. */
#define PHPAL_FELICA_SW_CMD_REQ_RESP        0x04U   /**< Request Response. */
#define PHPAL_FELICA_SW_CMD_REQ_SERVICE     0x02U   /**< Request Service. */
#define PHPAL_FELICA_SW_CMD_READ            0x06U   /**< Read. */
#define PHPAL_FELICA_SW_CMD_WRITE           0x08U   /**< Write. */
#define PHPAL_FELICA_SW_CMD_AUTH1           0x10U   /**< Authentication1. */
#define PHPAL_FELICA_SW_CMD_AUTH2           0x12U   /**< Authentication2. */
#define PHPAL_FELICA_SW_CMD_READ_SECF       0x14U   /**< Read from secure file. */
#define PHPAL_FELICA_SW_CMD_WRITE_SECF      0x16U   /**< Write to secure file. */
#define PHPAL_FELICA_SW_RSP_REQC            0x01U   /**< Response to RequestC. */
#define PHPAL_FELICA_SW_LEN_BYTE_SIZE       0x01U   /**< Size of Length byte in RequestC response. */
#define PHPAL_FELICA_SW_RESP_REQC_SIZE      0x01U   /**< Length of Response byte in RequestC response. */
/*@}*/

/** \name Flags
*/
/*@{*/
/** Error Flag. */
#define PHPAL_FELICA_SW_FLAG_ERROR      0x01U
/** Addressed Flag. */
#define PHPAL_FELICA_SW_FLAG_ADDRESSED  0x20U
/** Selected Flag. */
#define PHPAL_FELICA_SW_FLAG_SELECTED   0x10U
/*@}*/

/** \name Values
*/
/*@{*/
/** Stored UID is valid. */
#define PHPAL_FELICA_SW_IDMPMM_VALID    0x01U
/** Stored UID is not valid. */
#define PHPAL_FELICA_SW_IDMPMM_INVALID  0x00U
/** Size of one Felica Response Frame. */
#define PHPAL_FELICA_SW_RESP_FRAME_SIZE 32U
/*@}*/

/** \name Timing constants
*/
/*@{*/
#define PHPAL_FELICA_SW_TIME_T_US           302U
#define PHPAL_FELICA_SW_EXT_TIME_US         500U    /**< Time extension in microseconds for all commands.  */
#define PHPAL_FELICA_SW_RESP_TIME_A_US      (2672U + PHPAL_FELICA_SW_EXT_TIME_US)
#define PHPAL_FELICA_SW_RESP_TIME_B_US      1208U
/*@}*/

/** @}
* end of ph_Private
*/

#endif /* PHPALFELICA_SW_INT_H */
