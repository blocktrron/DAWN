#ifndef DAWN_RSSI_H
#define DAWN_RSSI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int get_rssi_iwinfo(__uint8_t *client_addr);

#endif //DAWN_RSSI_H
