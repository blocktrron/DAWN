#include "datastorage.h"

#include <limits.h>

#include "utils.h"
#include "ieee80211_utils.h"

#define REALLOC_STEPS	10

struct denied_list list;

void clean_denied_probe_requests(time_t threshold);

void add_denied_probe_request(auth_entry *entry);

static auth_entry* denied_req_array_resize(struct denied_list *dl, size_t new_size) {
	if (new_size <= dl->size)
		return 0;

	new_size = dl->size + REALLOC_STEPS;
	dl->ptr = realloc(dl->ptr, new_size * sizeof(auth_entry));
	dl->size = new_size;

	return dl->ptr;
}

static auth_entry* denied_req_array_get(struct denied_list *dl, uint8_t *bssid, uint8_t *client) {
	auth_entry *entry;

	for (int i = 0; i < dl->len; i++) {
		entry = &dl->ptr[i];
		if (   mac_is_equal(entry->bssid_addr, bssid)
		    && mac_is_equal(entry->client_addr, client))
		    return entry;
	}

	return 0;
}

static auth_entry* denied_req_array_create_entry(struct denied_list *dl, uint8_t *bssid, uint8_t *client) {
	size_t new_len;
	auth_entry *entry;

	new_len = dl->len + 1;

	/* Extend Array if needed & blank memory */
	denied_req_array_resize(dl, new_len);
	memset(&dl->ptr[dl->len], 0, sizeof(auth_entry));
	entry = &dl->ptr[new_len];
	dl->len = new_len;

	/* Create array element */
	memcpy(entry->bssid_addr, bssid, ETH_ALEN * sizeof(uint8_t));
	memcpy(entry->client_addr, client, ETH_ALEN * sizeof(uint8_t));
	
	return entry;
}

static void denied_req_array_delete_idx(struct denied_list *dl, int idx) {
	int last_idx;

	last_idx = dl->len - 1;
	if (dl->len > 1 && idx != last_idx)
		memcpy(&dl->ptr[idx], &dl->ptr[last_idx], sizeof(auth_entry));

	memset(&dl->ptr[last_idx], 0, sizeof(auth_entry));
	dl->len = dl->len - 1;
}

void add_denied_probe_request(auth_entry *entry) {
	auth_entry *from_list;
	pthread_mutex_lock(&list.array_mutex);

	from_list = denied_req_array_get(&list,
					 entry->bssid_addr,
					 entry->client_addr);

	if (!from_list)
		from_list = denied_req_array_create_entry(&list,
						    entry->bssid_addr,
						    entry->client_addr);

	from_list->time = time(0);
	from_list->counter++;

	pthread_mutex_unlock(&denied_array_mutex);
}

void clean_denied_probe_requests(time_t threshold) {
	time_t current_time = time(0);
	pthread_mutex_lock(&list.array_mutex);
	
	for (int i = 0; i <= list.len; i++) {
		if (list.ptr[i].time < current_time - threshold) {
			denied_req_array_delete_idx(&list, i);
		}
	}

	pthread_mutex_unlock(&denied_array_mutex);
}