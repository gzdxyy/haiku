/*
 * Copyright 2018, Haiku, Inc. All rights reserved.
 * Distributed under the terms of the MIT License.
 */


#include <sys/bus.h>


extern driver_t* DRIVER_MODULE_NAME(em, pci);
extern driver_t* DRIVER_MODULE_NAME(lem, pci);
extern driver_t* DRIVER_MODULE_NAME(igb, pci);

HAIKU_FBSD_DRIVERS_GLUE(ipro1000);
HAIKU_DRIVER_REQUIREMENTS(FBSD_TASKQUEUES | FBSD_FAST_TASKQUEUE);
NO_HAIKU_FBSD_MII_DRIVER();
NO_HAIKU_REENABLE_INTERRUPTS();


status_t
__haiku_handle_fbsd_drivers_list(status_t (*handler)(driver_t *[]))
{
	driver_t *drivers[] = {
		DRIVER_MODULE_NAME(em, pci),
		DRIVER_MODULE_NAME(lem, pci),
		NULL
	};
	return (*handler)(drivers);
}


int
HAIKU_CHECK_DISABLE_INTERRUPTS(device_t dev)
{
	// only MSI interrupts, legacy uses fast intr
	return 1;
}