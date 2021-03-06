/* SPDX-License-Identifier: GPL-2.0-or-later */

#include <arch/cache.h>
#include <arch/io.h>
#include <cf9_reset.h>
#include <console/console.h>
#include <drivers/spi/tpm/tpm.h>
#include <ec/google/chromeec/ec.h>
#include <halt.h>
#include <intelblocks/cse.h>
#include <security/tpm/tss.h>

void cse_board_reset(void)
{
	struct cr50_firmware_version version;

	/* Initialize TPM and get the cr50 firmware version. */
	tlcl_lib_init();
	cr50_get_firmware_version(&version);
	/*
	 * Cr50 firmware versions 0.[3|4].20 or newer support strap config 0xe where PLTRST from
	 * AP is connected to cr50's PLTRST# signal. So return immediately and trigger a
	 * global reset.
	 */
	if (version.epoch != 0 || version.major > 4 ||
			(version.major >= 3 && version.minor >= 20))
		return;

	printk(BIOS_INFO, "Initiating request to EC to trigger cold reset\n");
	/*
	 * Clean the data cache and set the full reset bit, so that when EC toggles
	 * SYS_RESET# pin, AP makes a trip to S5 and then to S0.
	 */
	dcache_clean_all();
	outb(FULL_RST, RST_CNT);
	if (!google_chromeec_ap_reset())
		halt();
}
