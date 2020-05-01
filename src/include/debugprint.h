#ifndef __DAWN_DEBUGPRINT_H
#define __DAWN_DEBUGPRINT_H

#include "datastorage.h"

void print_probe_entry(probe_entry *entry);

void print_auth_entry(auth_entry *entry);

void print_client_entry(client *entry);

void print_client_array(client *client_array, int client_index_last);

void print_ap_array(ap *ap_array, int ap_index_last);

void print_probe_array(probe_entry *probe_array, int probe_array_last);

#endif