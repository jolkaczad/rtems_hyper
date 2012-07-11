#ifndef _POK_CONSOLE_P_H_
#define _POK_CONSOLE_P_H_

int pok_console_open(
		rtems_device_major_number major,
	 	rtems_device_minor_number minor,
	 	void *arg
);

int pok_console_close(
		rtems_device_major_number major,
	 	rtems_device_minor_number minor,
	 	void *arg
);

int pok_console_read(
		rtems_device_minor_number minor
);

void pok_console_init(
		rtems_device_minor_number minor
);

void pok_console_write_polled(
		rtems_device_minor_number minor,
	 	char cChar
);

#endif /* _POK_CONSOLE_P_H_ */
