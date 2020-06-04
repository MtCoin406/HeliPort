//
//  Api.h
//  ClientKit
//
//  Created by 钟先耀 on 2020/4/7.
//  Copyright © 2020 lhy. All rights reserved.
//

/*
 * This program and the accompanying materials are licensed and made available
 * under the terms and conditions of the The 3-Clause BSD License
 * which accompanies this distribution. The full text of the license may be found at
 * https://opensource.org/licenses/BSD-3-Clause
 */

#ifndef Api_h
#define Api_h

#include <IOKit/IOKitLib.h>
#include <IOKit/IOTypes.h>
#include "Common.h"
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORK_LIST_LENGTH 50
#define MAX_SSID_LENGTH 32

enum network_auth_security_mode {
    NETWORK_AUTH_SECURITY_NONE,
    NETWORK_AUTH_SECURITY_WEP,
    NETWORK_AUTH_SECURITY_MIXED_WPA_WP2_PERSONAL,
    NETWORK_AUTH_SECURITY_WPA2_PERSONAL,
    NETWORK_AUTH_SECURITY_DYNAMIC_WEP,
    NETWORK_AUTH_SECURITY_MIXED_WPA_WP2_ENTERPRISE,
    NETWORK_AUTH_SECURITY_WPA2_ENTERPRISE,
    NETWORK_AUTH_SECURITY_WPA3_ENTERPRISE,
};

typedef struct {
    char device_info_str[32];
    char driver_info_str[32];
} platform_info_t;

typedef struct {
    uint8_t security;
    uint64_t option;
    uint8_t *identity;
    uint32_t identity_length;
    char *username;
    char *password;
} network_auth_t;

typedef struct {
    char SSID[MAX_SSID_LENGTH + 1];
    bool is_connected;
    bool is_encrypted;
    int RSSI;
    network_auth_t auth;
} network_info_t;

typedef struct {
    int count;
    network_info_t networks[MAX_NETWORK_LIST_LENGTH];
} network_info_list_t;

bool connect_driver(void);

void disconnect_driver(void);

bool open_adapter(void *con);

bool ioctl_get(int ctl, void *data);

bool ioctl_set(int ctl, void *data);

bool get_platform_info(platform_info_t *result);

bool get_network_list(network_info_list_t *list);

bool connect_network(network_info_t *info);

#endif /* Api_h */