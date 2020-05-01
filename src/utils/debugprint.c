#include <stdio.h>

#include "datastorage.h"
#include "debugprint.h"
#include "utils.h"

static void print_ap_entry(ap *entry) {
    char mac_buf_ap[MACSTRLEN];

    sprintf(mac_buf_ap, MACSTR, MAC2STR(entry->bssid_addr));
    printf("ssid: %s, bssid_addr: %s, freq: %d, ht: %d, vht: %d, chan_utilz: %d, col_d: %d, bandwidth: %d, col_count: %d neighbor_report: %s\n",
           entry->ssid, mac_buf_ap, entry->freq, entry->ht_support, entry->vht_support,
           entry->channel_utilization, entry->collision_domain, entry->bandwidth,
           ap_get_collision_count(entry->collision_domain), entry->neighbor_report
    );
}

void print_probe_entry(probe_entry *entry) {
    char mac_buf_ap[MACSTRLEN];
    char mac_buf_client[MACSTRLEN];
    char mac_buf_target[MACSTRLEN];

    sprintf(mac_buf_ap, MACSTR, MAC2STR(entry->bssid_addr));
    sprintf(mac_buf_client, MACSTR, MAC2STR(entry->client_addr));
    sprintf(mac_buf_target, MACSTR, MAC2STR(entry->target_addr));

    printf(
            "bssid_addr: %s, client_addr: %s, signal: %d, freq: "
            "%d, counter: %d, vht: %d, min_rate: %d, max_rate: %d\n",
            mac_buf_ap, mac_buf_client, entry->signal, entry->freq,
            entry->counter, entry->vht_capabilities,
            entry->min_supp_datarate, entry->max_supp_datarate);
}

void print_auth_entry(auth_entry *entry) {
    char mac_buf_ap[MACSTRLEN];
    char mac_buf_client[MACSTRLEN];
    char mac_buf_target[MACSTRLEN];

    sprintf(mac_buf_ap, MACSTR, MAC2STR(entry->bssid_addr));
    sprintf(mac_buf_client, MACSTR, MAC2STR(entry->client_addr));
    sprintf(mac_buf_target, MACSTR, MAC2STR(entry->target_addr));

    printf(
            "bssid_addr: %s, client_addr: %s, signal: %d, freq: "
            "%d\n",
            mac_buf_ap, mac_buf_client, entry->signal, entry->freq);
}

void print_client_entry(client *entry) {
    char mac_buf_ap[MACSTRLEN];
    char mac_buf_client[MACSTRLEN];

    sprintf(mac_buf_ap, MACSTR, MAC2STR(entry->bssid_addr));
    sprintf(mac_buf_client, MACSTR, MAC2STR(entry->client_addr));

    printf("bssid_addr: %s, client_addr: %s, freq: %d, ht_supported: %d, vht_supported: %d, ht: %d, vht: %d, kick: %d\n",
           mac_buf_ap, mac_buf_client, entry->freq, entry->ht_supported, entry->vht_supported, entry->ht, entry->vht,
           entry->kick_count);
}

void print_client_array(client *client_array, int client_index_last) {
    printf("--------Clients------\n");
    printf("Client Entry Last: %d\n", client_index_last);
    for (int i = 0; i <= client_index_last; i++) {
        print_client_entry(&client_array[i]);
    }
    printf("------------------\n");
}

void print_ap_array(ap *ap_array, int ap_index_last) {
    printf("--------APs------\n");
    for (int i = 0; i <= ap_index_last; i++) {
        print_ap_entry(&ap_array[i]);
    }
    printf("------------------\n");
}

void print_probe_array(probe_entry *probe_array, int probe_array_last) {
    printf("------------------\n");
    printf("Probe Entry Last: %d\n", probe_array_last);
    for (int i = 0; i <= probe_array_last; i++) {
        print_probe_entry(&probe_array[i]);
    }
    printf("------------------\n");
}