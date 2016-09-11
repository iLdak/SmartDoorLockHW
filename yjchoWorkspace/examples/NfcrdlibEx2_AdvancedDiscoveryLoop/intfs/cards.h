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
* Cards identification.
* $Author: jenkins_cm (nxp92197) $
* $Revision: 2673 $
* $Date: 2015-07-14 15:12:35 +0530 (Tue, 14 Jul 2015) $
*
* History:
*
*
*/

#ifndef CARDS_H
#define CARDS_H

/*
 * SAK codes
 */
#define sak_ul         0x00
#define sak_ulc        0x00
#define sak_mini       0x09
#define sak_mfc_1k     0x08
#define sak_mfc_4k     0x18
#define sak_mfp_2k_sl1 0x08
#define sak_mfp_4k_sl1 0x18
#define sak_mfp_2k_sl2 0x10
#define sak_mfp_4k_sl2 0x11
#define sak_mfp_2k_sl3 0x20
#define sak_mfp_4k_sl3 0x20
#define sak_desfire    0x20
#define sak_jcop       0x28
#define sak_layer4     0x20

/*
 * ATQ codes
 */
#define atqa_ul        0x4400
#define atqa_ulc       0x4400
#define atqa_mfc       0x0200
#define atqa_mfp_s     0x0400
#define atqa_mfp_x     0x4200
#define atqa_desfire   0x4403
#define atqa_jcop      0x0400
#define atqa_mini      0x0400
#define atqa_nPA       0x0800

/*
 * MIFARE cards
 */
#define mifare_ultralight    0x01
#define mifare_ultralight_c  0x02
#define mifare_classic       0x03
#define mifare_classic_1k    0x04
#define mifare_classic_4k    0x05
#define mifare_plus          0x06
#define mifare_plus_2k_sl1   0x07
#define mifare_plus_4k_sl1   0x08
#define mifare_plus_2k_sl2   0x09
#define mifare_plus_4k_sl2   0x0A
#define mifare_plus_2k_sl3   0x0B
#define mifare_plus_4k_sl3   0x0C
#define mifare_desfire       0x0D
#define jcop                 0x0F
#define mifare_mini          0x10
#define nPA                  0x11

/*
 * Exported functions
 */
uint32_t DetectMifare(uint8_t *pAtqa, uint8_t *bSak);

#endif /* CARDS_H */
