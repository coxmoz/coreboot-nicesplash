/* SPDX-License-Identifier: GPL-2.0-or-later */

#include <device/azalia_device.h>

const u32 cim_verb_data[] = {
	0x14f15069,	/* Codec Vendor / Device ID: Conexant CX20585 */
	0x17aa214c,	/* Subsystem ID */
	11,		/* Number of 4 dword sets */
	AZALIA_SUBVENDOR(0, 0x17aa214c),
	AZALIA_PIN_CFG(0, 0x19, 0x042110f0),
	AZALIA_PIN_CFG(0, 0x1a, 0x61a190f0),
	AZALIA_PIN_CFG(0, 0x1b, 0x04a110f0),
	AZALIA_PIN_CFG(0, 0x1c, 0x612140f0),
	AZALIA_PIN_CFG(0, 0x1d, 0x40f001f0),
	AZALIA_PIN_CFG(0, 0x1e, 0x40f001f0),
	AZALIA_PIN_CFG(0, 0x1f, 0x901701f0),
	AZALIA_PIN_CFG(0, 0x20, 0x40f001f0),
	AZALIA_PIN_CFG(0, 0x22, 0x40f001f0),
	AZALIA_PIN_CFG(0, 0x23, 0x90a601f0),

	0x80862804,	/* Codec Vendor / Device ID: Intel Ibexpeak HDMI. */
	0x17aa21b5,	/* Subsystem ID */
	4,		/* Number of 4 dword sets */
	AZALIA_SUBVENDOR(3, 0x17aa21b5),
	AZALIA_PIN_CFG(3, 0x04, 0x18560010),
	AZALIA_PIN_CFG(3, 0x05, 0x18560020),
	AZALIA_PIN_CFG(3, 0x06, 0x18560030),
};

const u32 pc_beep_verbs[0] = {};

AZALIA_ARRAY_SIZES;
