#ifndef CTROLLER_H
#define CTROLLER_H

#include <stddef.h>

#include "hid.h"

#define _STRINGIFY(a) #a
#define STRINGIFY(a) _STRINGIFY(a)

#define MAKEBCDVER(major, minor, patch)                                        \
    ((major & 0xf) << 8 | (minor & 0xf) << 4 | (patch & 0xf))

#define CTROLLER_VERSION_STRING                                                \
    STRINGIFY(VERSION_MAJOR)                                                   \
    "." STRINGIFY(VERSION_MINOR) "." STRINGIFY(VERSION_PATCH)

#define CTROLLER_VERSION MAKEBCDVER(VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH)

#define PACKET_MAGIC 0x3d5c
#define PACKET_SIZE (2 * sizeof(uint16_t) + sizeof(struct hidinfo))

#define UINPUT_DEFAULT_DEVICE "/dev/uinput"
#define PORT_DEFAULT "15708"

typedef unsigned char packet_hid_t[PACKET_SIZE];

int ctroller_init(const char *uinput_device, const char *port);
int ctroller_listener_init(const char *port);
int ctroller_uinput_init(const char *uinput_device);

void ctroller_exit(void);

int ctroller_recv(void *buf, size_t len);

int ctroller_poll_hid_info(struct hidinfo *);
int ctroller_unpack_hid_info(unsigned char *sendbuf, struct hidinfo *hid);
int ctroller_write_hid_info(struct hidinfo *hid);

#endif /* ----- #ifndef CTROLLER_H  ----- */
