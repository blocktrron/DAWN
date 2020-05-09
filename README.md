![DAWN PICTURE](https://image.ibb.co/nbmNfJ/dawn_bla.png)

# DAWN
Decentralized WiFi Controller

## Installation

**You need full wpad installation and not wpad-basic**.

See [installation](INSTALL.md).

## LuCI App
There is an luci app called [luci-app-dawn](https://github.com/openwrt/luci/tree/master/applications/luci-app-dawn).

## Setting up Routers

You can find a good guide to configure your router is [here](https://gist.github.com/braian87b/bba9da3a7ac23c35b7f1eecafecdd47d).
I setup the OpenWRT Router as dumb APs.

## Configuration


|Option             |Standard | Meaning |
|-------------------|---------|---------|
|ht_support         |  '10'   |If AP and station support high throughput.|
|vht_support        |  '100'  |If AP and station support very high throughput.|
|no_ht_support      |  '0'    |If AP and station not supporting high throughput.|
|no_vht_support     |  '0'    |If AP and station not supporting very high throughput.
|rssi               |  '10'   |If RSSI is greater equal rssi_val.|
|low_rssi           |  '-500' |If RSSI is less than low_rssi_val.|
|freq               |  '100'  |If connection is 5Ghz.|
|chan_util          |  '0'    |If channel utilization is lower chan_util_val.|
|max_chan_util      |  '-500' |If channel utilization is greater max_chan_util_val.|
|rssi_val           |  '-60'  |Threshold for an good RSSI.|
|low_rssi_val       |  '-80'  |Threshold for an bad RSSI.|
|chan_util_val      |  '140'  |Threshold for an good channel utilization.|
|max_chan_util_val  |  '170'  |Threshold for a bad channel utilization.|
|min_probe_count    |  '2'    |Minimum number of probe requests aftrer calculating if AP is best and sending a probe response.|
|bandwidth_threshold |  '6'    |Threshold for the receiving bit rate indicating if a client is in an active transmission.|
|use_station_count  | '1'    |Use station count as metric.|
|max_station_diff   | '1'    |Maximal station difference that is allowed.|
|eval_probe_req     | '1'    |Evaluate the incoming probe requests.|
|eval_auth_req      | '1'    |Evaluate the incomning authentication reqeuests.|
|eval_assoc_req     | '1'    |Evaluate the incoming association requests.|
|deny_auth_reason   | '1'    |Status code for denying authentications.|
|deny_assoc_reason  | '17'   |Status code for denying associations.|
|use_driver_recog   | '1'    |Allow drivers to connect after a certain time.|
| min_number_to_kick | '3' | How often a clients needs to be evaluated as bad before kicking. |
| chan_util_avg_period | '3' | Channel Utilization Averaging |
| set_hostapd_nr       | '1' | Feed Hostapd With NR-Reports |
| op_class             | '0' | 802.11k beacon request parameters |
| duration             | '0' | 802.11k beacon request parameters |
| mode                 | '0' | 802.11k beacon request parameters |
| scan_channel         | '0' | 802.11k beacon request parameters |


## ubus interface


##  OpenWrt in a Nutshell

![OpenWrtInANuthshell](https://raw.githubusercontent.com/PolynomialDivision/upload_stuff/master/dawn_pictures/openwrt_in_a_nutshell_dawn.png)


