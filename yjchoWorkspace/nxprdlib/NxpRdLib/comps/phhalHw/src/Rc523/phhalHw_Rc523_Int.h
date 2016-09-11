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
* Internal definitions for Rc523 specific HAL-Component of Reader Library Framework.
* $Author: jenkins_ cm (nxp92197) $
* $Revision: 4258 $ (NFCRDLIB_V4.010.03.001609 : 4240 $ (NFCRDLIB_V4.010.01.001603 : 4000 ))
* $Date: 2016-03-01 16:44:26 +0530 (Tue, 01 Mar 2016) $
*
* History:
*  CHu: Generated 19. May 2009
*
*/

#ifndef PHHALHW_RC523_INT_H
#define PHHALHW_RC523_INT_H

#include <ph_Status.h>

/** \defgroup phhalHw_Rc523_Int Internal
* \brief Internal definitions.
* @{
*/

#define PHHAL_HW_RC523_TIMER_FREQ               13.56f      /**< RC internal timer frequency. */
#define PHHAL_HW_RC523_TIMER_MAX_VALUE_US       39586813    /**< RC maximum timer value in microseconds. */
#define PHHAL_HW_RC523_TIMER_SHIFT              4.8f        /**< Shift of the internal RC timer in ETUs. */
#define PHHAL_HW_RC523_ETU_106                  9.44f       /**< Duration of one ETU at 106 kBit/s in [us]. */
#define PHHAL_HW_RC523_ETU_212                  4.7f        /**< Duration of one ETU at 212 kBit/s in [us]. */
#define PHHAL_HW_RC523_ETU_424                  2.4f        /**< Duration of one ETU at 424 kBit/s in [us]. */
#define PHHAL_HW_RC523_ETU_848                  1.2f        /**< Duration of one ETU at 848 kBit/s in [us]. */
#define PHHAL_HW_RC523_REQC_MIN_LEN              19U        /**< Minimum length of valid ReqC response when multiple reception is enable. */

/** \name Timing related constants
*/
/*@{*/
#define PHHAL_HW_RC523_FELICA_ADD_DELAY_US      240U        /**< Additional digital timeout delay for Felica. */
/*@}*/

/** \name RS232 speed settings
*/
/*@{*/
#define PHHAL_HW_RC523_SERIALSPEED_7200     0xFAU       /**< 7.200 kBit/s. */
#define PHHAL_HW_RC523_SERIALSPEED_9600     0xEBU       /**< 9.600 kBit/s. */
#define PHHAL_HW_RC523_SERIALSPEED_14400    0xDAU       /**< 14.400 kBit/s. */
#define PHHAL_HW_RC523_SERIALSPEED_19200    0xCBU       /**< 19.200 kBit/s. */
#define PHHAL_HW_RC523_SERIALSPEED_38400    0xABU       /**< 38.400 kBit/s. */
#define PHHAL_HW_RC523_SERIALSPEED_57600    0x9AU       /**< 57.500 kBit/s. */
#define PHHAL_HW_RC523_SERIALSPEED_115200   0x7AU       /**< 115.200 kBit/s. */
#define PHHAL_HW_RC523_SERIALSPEED_128000   0x74U       /**< 128.000 kBit/s. */
#define PHHAL_HW_RC523_SERIALSPEED_230400   0x5AU       /**< 230.400 kBit/s. */
#define PHHAL_HW_RC523_SERIALSPEED_460800   0x3AU       /**< 460.800 kBit/s. */
#define PHHAL_HW_RC523_SERIALSPEED_921600   0x1CU       /**< 921.600 kBit/s. */
#define PHHAL_HW_RC523_SERIALSPEED_1228800  0x15U       /**< 1.228.800 kBit/s. */
/*@}*/

#define PHHAL_HW_RC523_MFC_AUTHA_CMD          0x60U     /**< MIFARE(R) Classic AUTHA command code. */
#define PHHAL_HW_RC523_MFC_AUTHB_CMD          0x61U     /**< MIFARE(R) Classic AUTHB command code. */

/** \name EMD noise detection settings
*/
/*@{*/
#define PHHAL_HWRC523_EMD_NOISE_ERROR             (PHHAL_HW_RC523_BIT_COLLERR | PHHAL_HW_RC523_BIT_CRCERR | PHHAL_HW_RC523_BIT_PARITYERR | PHHAL_HW_RC523_BIT_PROTERR)
#define PHHAL_HWRC523_EMD_NOISE_CHECK(dwReg)        \
    (                                               \
    (((dwReg) & PHHAL_HWRC523_EMD_NOISE_ERROR) != 0)\
    ? 1 : 0                                         \
    )

/* Noise length. 2 CRC bytes are not
 * included since they are removed by the h/w
 * */
#define PHHAL_HW_RC523_EMV_NOISE_MAXLEN 2U
#define PHHAL_HW_RC523_ISO_NOISE_MAXLEN 1U

/*@}*/

/**
* \brief Write Data to Fifo buffer.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and under-laying component.
*/
phStatus_t phhalHw_Rc523_WriteFifo(
                                   phhalHw_Rc523_DataParams_t * pDataParams,    /**< [In] Pointer to this layer's parameter structure. */
                                   uint8_t * pData,                             /**< [In] input data */
                                   uint16_t wLength,                            /**< [In] length of input data */
                                   uint16_t * pBytesWritten                     /**< [Out] Number of written bytes */
                                   );

/**
* \brief Read Data from Fifo buffer.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and under-laying component.
*/
phStatus_t phhalHw_Rc523_ReadFifo(
                                  phhalHw_Rc523_DataParams_t * pDataParams, /**< [In] Pointer to this layer's parameter structure. */
                                  uint16_t wBufSize,                        /**< [In] size of output buffer */
                                  uint8_t * pData,                          /**< [Out] output data */
                                  uint16_t * pLength                        /**< [Out] number of output data bytes */
                                  );

/**
* \brief Clear Fifo buffer.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and under-laying component.
*/
phStatus_t phhalHw_Rc523_FlushFifo(
                                   phhalHw_Rc523_DataParams_t * pDataParams /**< [In] Pointer to this layer's parameter structure. */
                                   );

/**
* \brief Write multiple values to a single register address.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and under-laying component.
*/
phStatus_t phhalHw_Rc523_WriteData(
                                   phhalHw_Rc523_DataParams_t * pDataParams,    /**< [In] Pointer to this layer's parameter structure. */
                                   uint8_t bAddress,                            /**< [In] Start-Register Address */
                                   uint8_t * pData,                             /**< [In] Register Values; uint8_t[wLength] */
                                   uint16_t wLength                             /**< [In] Number of Values */
                                   );

/**
* \brief Read multiple values from single register address.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and under-laying component.
*/
phStatus_t phhalHw_Rc523_ReadData(
                                  phhalHw_Rc523_DataParams_t * pDataParams, /**< [In] Pointer to this layer's parameter structure. */
                                  uint8_t bAddress,                         /**< [In] Register Address */
                                  uint16_t wLength,                         /**< [In] Number of Values */
                                  uint8_t * pData                           /**< [Out] Register Values; uint8_t[wLength] */
                                  );

/**
* \brief Transmit part of Exchange command.
*
* \see phhalHw_Exchange
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and under-laying component.
*/
phStatus_t phhalHw_Rc523_ExchangeTransmit(
    phhalHw_Rc523_DataParams_t * pDataParams,   /**< [In] Pointer to this layer's parameter structure. */
    uint8_t bCmdCode,                           /**< [In] Command-Code of command. */
    uint8_t * pTxBuffer,                        /**< [In] Data to transmit. */
    uint16_t wTxLength                          /**< [In] Length of data to transmit. */
    );

/**
* \brief Receive part of Exchange command.
*
* \see phhalHw_Exchange
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and under-laying component.
*/
phStatus_t phhalHw_Rc523_ExchangeReceive(
    phhalHw_Rc523_DataParams_t * pDataParams,   /**< [In] Pointer to this layer's parameter structure. */
    uint8_t ** ppRxBuffer,                      /**< [Out] Pointer to received data. */
    uint16_t * pRxLength                        /**< [Out] Number of received data bytes. */
    );

/**
* \brief This function will calculate and store Timer Pre-scaler and Timer ReLoad values (Lower and Higher bytes).
*  For function \ref phhalHw_Wait, this function will directly set register with calculated values.
*  This function will calculate and store value for #PHHAL_HW_CONFIG_TXWAIT_US or #PHHAL_HW_CONFIG_TXWAIT_MS or #PHHAL_HW_CONFIG_TIMEOUT_VALUE_US or #PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS.\n
*
* \b wConfig can be one of:\n
* \li #PHHAL_HW_TIME_MICROSECONDS       : Calculate values in microseconds.
* \li #PHHAL_HW_TIME_MILLISECONDS       : Calculate values in milliseconds.
* \li #PHHAL_HW_CONFIG_TXWAIT_US        : Calculate values for TxWait in microseconds.
* \li #PHHAL_HW_CONFIG_TXWAIT_MS        : Calculate values for TxWait in milliseconds.
* \li #PHHAL_HW_CONFIG_TIMEOUT_VALUE_US : Calculate values for FDT in microseconds.
* \li #PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS : Calculate values for FDT in milliseconds.
*
* \b Note: Frame Delay Time (FDT) is defined between the last transmitted bit and the first received bit.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and under-laying component.
*/
phStatus_t phhalHw_Rc523_SetFdt(
                                phhalHw_Rc523_DataParams_t * pDataParams,   /**< [In] Pointer to this layer's parameter structure. */
                                uint16_t wConfig,                           /**< [In] Configuration Identifier. */
                                uint16_t wTimeout                           /**< [In] Time-out value. */
                                );

/**
* \brief Retrieves the Frame Delay Time of the last command.
*
* \b Note: Frame Delay Time is defined between the last transmitted bit and the first received bit.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and under-laying component.
*/
phStatus_t phhalHw_Rc523_GetFdt(
                                phhalHw_Rc523_DataParams_t * pDataParams,   /**< [In] Pointer to this layer's parameter structure. */
                                phStatus_t wExchangeStatus,                 /**< [In] Status code returned by exchange function. */
                                uint32_t * pTime                            /**< [Out] Calculated time in microseconds from timer contents. */
                                );

/**
* \brief Returns the TxBuffer pointer, length and size.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
phStatus_t phhalHw_Rc523_GetTxBuffer(
                                     phhalHw_Rc523_DataParams_t * pDataParams,  /**< [In] Pointer to this layer's parameter structure. */
                                     uint8_t bIsExchange,                       /**< [In] Whether this is for Exchange (#PH_ON) or not (#PH_OFF). */
                                     uint8_t ** pTxBuffer,                      /**< [Out] Pointer to the TxBuffer. */
                                     uint16_t * pTxBufferLen,                   /**< [Out] Number of bytes already in the TxBuffer. */
                                     uint16_t * pTxBufferSize                   /**< [Out] Size of the TxBuffer. */
                                     );

/**
* \brief Returns the RxBuffer pointer, length and size.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
phStatus_t phhalHw_Rc523_GetRxBuffer(
                                     phhalHw_Rc523_DataParams_t * pDataParams,  /**< [In] Pointer to this layer's parameter structure. */
                                     uint8_t bIsExchange,                       /**< [In] Whether this is for Exchange (#PH_ON) or not (#PH_OFF). */
                                     uint8_t ** pRxBuffer,                      /**< [Out] Pointer to the RxBuffer. */
                                     uint16_t * pRxBufferLen,                   /**< [Out] Number of bytes already in the RxBuffer. */
                                     uint16_t * pRxBufferSize                   /**< [Out] Size of the RxBuffer. */
                                     );

/**
* \brief Wait until one of the given interrupts occurs.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and under-laying component.
*/
phStatus_t phhalHw_Rc523_WaitIrq(
                                 phhalHw_Rc523_DataParams_t * pDataParams,  /**< [In] Pointer to this layer's parameter structure. */
                                 uint8_t bIrq0WaitFor,                      /**< [In] Bitmask of interrupts in CommIrq register to wait for. */
                                 uint8_t bIrq1WaitFor,                      /**< [In] Bitmask of interrupts in DivIrq register to wait for. */
                                 uint8_t * pIrq0Reg,                        /**< [Out] Contents of CommIrq register. */
                                 uint8_t * pIrq1Reg                         /**< [Out] Contents of DivIrq register. */
                                 );

/**
* \brief Configure registers for Frame Delay Time (Timeout) values. Registers value are calculated and stored by function \ref phhalHw_Rc523_SetFdt.
*
* \b Note: Frame Delay Time is defined between the last transmitted bit and the first received bit.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and under-laying component.
*/
phStatus_t phhalHw_Rc523_LoadTimeout(
                                     phhalHw_Rc523_DataParams_t * pDataParams   /**< [In] Pointer to this layer's parameter structure. */
                                     );

/**
* \brief Configure registers for TxWait and start timer. Registers value are calculated and stored by function \ref phhalHw_Rc523_SetFdt.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and under-laying component.
*/
phStatus_t phhalHw_Rc523_StartTxWaitTimer(
                                          phhalHw_Rc523_DataParams_t * pDataParams   /**< [In] Pointer to this layer's parameter structure. */
                                          );

/**
* \brief This function will  return the answer to ReqC in 32 byte multi slot frame format.
* Size of output frame is #PHHAL_HW_RESP_FRAME_SIZE byte.
*
* \b Note: This function is only valid when multiple reception #PHHAL_HW_CONFIG_RXMULTIPLE is enabled.
*/
void phhalHw_Rc523_CreateRespFrame(
                                   uint8_t* bInBuff,  /**< [In]  Pointer to Rx buffer. */
                                   uint8_t bDataPos,  /**< [In]  position of card response in Rxbuffer. */
                                   uint8_t * bOutBuff /**< [Out] Pointer to buffer which store frame of #PHHAL_HW_RESP_FRAME_SIZE size.  */
                                   );

/**
* \brief Frame packet which contains a series of ReqC responses(if multiple response received) in multi-slot response format and update Hal Rx buffer.
* This function will use function \ref phhalHw_Rc523_CreateRespFrame to frame each card responses multi-slot frame format.
*
* \b Note: This function is only valid when multiple reception #PHHAL_HW_CONFIG_RXMULTIPLE is enabled.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and under-laying component.
*/
phStatus_t phhalHw_Rc523_FrameRxMultiplePkt(
                                            phhalHw_Rc523_DataParams_t * pDataParams   /**< [In] Pointer to this layer's parameter structure. */
                                            );

/**
* \brief EMD error handling function on PN512.
* \retval Other Depending on implementation and under-laying component.
*/
phStatus_t phhalHw_Rc523_CheckForEmdError(
                                      phhalHw_Rc523_DataParams_t * pDataParams, /**< [In] Pointer to this layer's parameter structure. */
                                      uint8_t bIrq0WaitFor,                     /**< [In] Bitmask of interrupts in Irq0 register to wait for. */
                                      uint8_t bIrq1WaitFor,                     /**< [In] Bitmask of interrupts in Irq1 register to wait for. */
                                      uint8_t * pIrq0Reg,                       /**< [Out] Contains  Register Read Value. */
                                      uint8_t * pIrq1Reg                        /**< [Out] Contains  Register Read Value. */
                                      );

/**
* \brief Restart Receiver function on PN512.
* \retval Other Depending on implementation and under-laying component.
*/
phStatus_t phhalHw_Rc523_ReStartRx(
                                   phhalHw_Rc523_DataParams_t * pDataParams  /**< [In] Pointer to this layer's parameter structure. */
                                   );

/**
* \brief Get MultiReg function on PN512.
* \retval Other Depending on implementation and under-laying component.
*/
phStatus_t phhalHw_Rc523_GetMultiReg(
                                    phhalHw_Rc523_DataParams_t * pDataParams, /**< [In] Pointer to this layer's parameter structure. */
                                    uint8_t * pData                           /**< [Out] Pointer to buffer which store register values.  */
                                    );

/**
* \brief Get error from ErrorReg of PN512.
* \retval .
*/
phStatus_t phhalHw_Rc523_GetError(
                                  phhalHw_Rc523_DataParams_t * pDataParams    /**< [In] Pointer to this layer's parameter structure. */
                                  );

/** @}
* end of phhalHw_Rc523_Internal group
*/

#endif /* PHHALHW_RC523_INT_H */
