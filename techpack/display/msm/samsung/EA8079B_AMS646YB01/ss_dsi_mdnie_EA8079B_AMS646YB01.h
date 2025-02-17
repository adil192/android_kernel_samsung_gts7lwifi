/*
 * =================================================================
 *
 *
 *	Description:  samsung display common file
 *
 *	Author: cj1225.jang
 *	Company:  Samsung Electronics
 *
 * ================================================================
 */
/*
<one line to give the program's name and a brief idea of what it does.>
Copyright (C) 2020, Samsung Electronics. All rights reserved.

*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
*/
#ifndef _SAMSUNG_DSI_MDNIE_EA8079B_AMS646YB01_
#define _SAMSUNG_DSI_MDNIE_EA8079B_AMS646YB01_

#include "ss_dsi_mdnie_lite_common.h"

#define MDNIE_COLOR_BLINDE_CMD_OFFSET 2

#define ADDRESS_SCR_WHITE_RED   0x14
#define ADDRESS_SCR_WHITE_GREEN 0x15
#define ADDRESS_SCR_WHITE_BLUE  0x16

#define MDNIE_RGB_SENSOR_INDEX	1

#define MDNIE_STEP1_INDEX 4
#define MDNIE_STEP2_INDEX 5
#define MDNIE_STEP3_INDEX 6

#define MDNIE_TRANS_DIMMING_DATA_INDEX	0

static char level_1_key_on[] = {
	0xF0,
	0x5A, 0x5A
};

static char level_1_key_off[] = {
	0xF0,
	0xA5, 0xA5
};

static char adjust_ldu_data_1[] = {
	0xff, 0xff, 0xff,
	0xfd, 0xfd, 0xff,
	0xfb, 0xfb, 0xff,
	0xf9, 0xf8, 0xff,
	0xf6, 0xf6, 0xff,
	0xf4, 0xf4, 0xff,
};

static char adjust_ldu_data_2[] = {
	0xff, 0xfc, 0xf6,
	0xfd, 0xfa, 0xf6,
	0xfb, 0xf7, 0xf6,
	0xf9, 0xf5, 0xf6,
	0xf4, 0xf0, 0xf6,
	0xf2, 0xee, 0xf6,
};

static char *adjust_ldu_data[MAX_MODE] = {
	adjust_ldu_data_2,
	adjust_ldu_data_2,
	adjust_ldu_data_2,
	adjust_ldu_data_1,
	adjust_ldu_data_1,
};

static char night_mode_data[] = {
	0xff, 0x00, 0x00, 0x00, 0xf9, 0x00, 0x00, 0x00, 0xee, 0x00, 0xf9, 0xee, 0xff, 0x00, 0xee, 0xff, 0xf9, 0x00, 0xff, 0xf9, 0xee, 0xff, 0x00, 0x00, /* 6500K */
	0xff, 0x00, 0x00, 0x00, 0xf7, 0x00, 0x00, 0x00, 0xe6, 0x00, 0xf7, 0xe6, 0xff, 0x00, 0xe6, 0xff, 0xf7, 0x00, 0xff, 0xf7, 0xe6, 0xff, 0x00, 0x00, /* 6300K */
	0xff, 0x00, 0x00, 0x00, 0xf3, 0x00, 0x00, 0x00, 0xde, 0x00, 0xf3, 0xde, 0xff, 0x00, 0xde, 0xff, 0xf3, 0x00, 0xff, 0xf3, 0xde, 0xff, 0x00, 0x00, /* 6100K */
	0xff, 0x00, 0x00, 0x00, 0xef, 0x00, 0x00, 0x00, 0xd6, 0x00, 0xef, 0xd6, 0xff, 0x00, 0xd6, 0xff, 0xef, 0x00, 0xff, 0xef, 0xd6, 0xff, 0x00, 0x00, /* 5900K */
	0xff, 0x00, 0x00, 0x00, 0xec, 0x00, 0x00, 0x00, 0xcd, 0x00, 0xec, 0xcd, 0xff, 0x00, 0xcd, 0xff, 0xec, 0x00, 0xff, 0xec, 0xcd, 0xff, 0x00, 0x00, /* 5700K */
	0xff, 0x00, 0x00, 0x00, 0xe8, 0x00, 0x00, 0x00, 0xc5, 0x00, 0xe8, 0xc5, 0xff, 0x00, 0xc5, 0xff, 0xe8, 0x00, 0xff, 0xe8, 0xc5, 0xff, 0x00, 0x00, /* 5500K */
	0xff, 0x00, 0x00, 0x00, 0xdd, 0x00, 0x00, 0x00, 0xaa, 0x00, 0xdd, 0xaa, 0xff, 0x00, 0xaa, 0xff, 0xdd, 0x00, 0xff, 0xdd, 0xaa, 0xff, 0x00, 0x00, /* 4900K */
	0xff, 0x00, 0x00, 0x00, 0xcd, 0x00, 0x00, 0x00, 0x87, 0x00, 0xcd, 0x87, 0xff, 0x00, 0x87, 0xff, 0xcd, 0x00, 0xff, 0xcd, 0x87, 0xff, 0x00, 0x00, /* 4300K */
	0xff, 0x00, 0x00, 0x00, 0xb9, 0x00, 0x00, 0x00, 0x62, 0x00, 0xb9, 0x62, 0xff, 0x00, 0x62, 0xff, 0xb9, 0x00, 0xff, 0xb9, 0x62, 0xff, 0x00, 0x00, /* 3700K */
	0xff, 0x00, 0x00, 0x00, 0xa4, 0x00, 0x00, 0x00, 0x42, 0x00, 0xa4, 0x42, 0xff, 0x00, 0x42, 0xff, 0xa4, 0x00, 0xff, 0xa4, 0x42, 0xff, 0x00, 0x00, /* 3100K */
	0xff, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x78, 0x1a, 0xff, 0x00, 0x1a, 0xff, 0x78, 0x00, 0xff, 0x78, 0x1a, 0xff, 0x00, 0x00, /* 2300K */
	0xac, 0x02, 0x04, 0x28, 0xf8, 0x11, 0x05, 0x06, 0xb3, 0x4a, 0xe4, 0xcf, 0xc1, 0x07, 0xbd, 0xe7, 0xd8, 0x18, 0xff, 0xf9, 0xee, 0xff, 0x00, 0x00, /* 6500K */
	0xac, 0x02, 0x04, 0x28, 0xf6, 0x10, 0x05, 0x06, 0xad, 0x4a, 0xe3, 0xc8, 0xc1, 0x07, 0xb7, 0xe7, 0xd6, 0x17, 0xff, 0xf7, 0xe6, 0xff, 0x00, 0x00, /* 6300K */
	0xac, 0x02, 0x03, 0x28, 0xf2, 0x10, 0x05, 0x06, 0xa7, 0x4a, 0xdf, 0xc1, 0xc1, 0x07, 0xb1, 0xe7, 0xd3, 0x17, 0xff, 0xf3, 0xde, 0xff, 0x00, 0x00, /* 6100K */
	0xac, 0x02, 0x03, 0x28, 0xee, 0x0f, 0x05, 0x06, 0xa1, 0x4a, 0xdb, 0xba, 0xc1, 0x07, 0xaa, 0xe7, 0xcf, 0x16, 0xff, 0xef, 0xd6, 0xff, 0x00, 0x00, /* 5900K */
	0xac, 0x02, 0x03, 0x28, 0xeb, 0x0e, 0x05, 0x06, 0x9a, 0x4a, 0xd9, 0xb2, 0xc1, 0x06, 0xa3, 0xe7, 0xcd, 0x15, 0xff, 0xec, 0xcd, 0xff, 0x00, 0x00, /* 5700K */
	0xac, 0x02, 0x03, 0x28, 0xe7, 0x0e, 0x05, 0x05, 0x94, 0x4a, 0xd5, 0xac, 0xc1, 0x06, 0x9d, 0xe7, 0xc9, 0x14, 0xff, 0xe8, 0xc5, 0xff, 0x00, 0x00, /* 5500K */
	0xac, 0x02, 0x03, 0x28, 0xdc, 0x0c, 0x05, 0x05, 0x80, 0x4a, 0xcb, 0x94, 0xc1, 0x06, 0x87, 0xe7, 0xc0, 0x11, 0xff, 0xdd, 0xaa, 0xff, 0x00, 0x00, /* 4900K */
	0xac, 0x02, 0x02, 0x28, 0xcc, 0x0a, 0x05, 0x05, 0x66, 0x4a, 0xbc, 0x76, 0xc1, 0x06, 0x6b, 0xe7, 0xb2, 0x0e, 0xff, 0xcd, 0x87, 0xff, 0x00, 0x00, /* 4300K */
	0xac, 0x01, 0x02, 0x28, 0xb8, 0x07, 0x05, 0x04, 0x4a, 0x4a, 0xaa, 0x55, 0xc1, 0x05, 0x4e, 0xe7, 0xa0, 0x0a, 0xff, 0xb9, 0x62, 0xff, 0x00, 0x00, /* 3700K */
	0xac, 0x01, 0x01, 0x28, 0xa3, 0x05, 0x05, 0x04, 0x32, 0x4a, 0x96, 0x39, 0xc1, 0x05, 0x35, 0xe7, 0x8e, 0x07, 0xff, 0xa4, 0x42, 0xff, 0x00, 0x00, /* 3100K */
	0xac, 0x01, 0x00, 0x28, 0x78, 0x02, 0x05, 0x03, 0x14, 0x4a, 0x6e, 0x17, 0xc1, 0x03, 0x15, 0xe7, 0x68, 0x03, 0xff, 0x78, 0x1a, 0xff, 0x00, 0x00, /* 2300K */
};

static char color_lens_data[] = {
	//Blue
	0xcc, 0x00, 0x33, 0x00, 0xcc, 0x33, 0x00, 0x00, 0xff, 0x00, 0xcc, 0xff, 0xcc, 0x00, 0xff, 0xcc, 0xcc, 0x33, 0xcc, 0xcc, 0xff, 0xff, 0x00, 0x00, /* 20% */
	0xbf, 0x00, 0x40, 0x00, 0xbf, 0x40, 0x00, 0x00, 0xff, 0x00, 0xbf, 0xff, 0xbf, 0x00, 0xff, 0xbf, 0xbf, 0x40, 0xbf, 0xbf, 0xff, 0xff, 0x00, 0x00, /* 25% */
	0xb2, 0x00, 0x4d, 0x00, 0xb2, 0x4d, 0x00, 0x00, 0xff, 0x00, 0xb2, 0xff, 0xb2, 0x00, 0xff, 0xb2, 0xb2, 0x4d, 0xb2, 0xb2, 0xff, 0xff, 0x00, 0x00, /* 30% */
	0xa6, 0x00, 0x59, 0x00, 0xa6, 0x59, 0x00, 0x00, 0xff, 0x00, 0xa6, 0xff, 0xa6, 0x00, 0xff, 0xa6, 0xa6, 0x59, 0xa6, 0xa6, 0xff, 0xff, 0x00, 0x00, /* 35% */
	0x99, 0x00, 0x66, 0x00, 0x99, 0x66, 0x00, 0x00, 0xff, 0x00, 0x99, 0xff, 0x99, 0x00, 0xff, 0x99, 0x99, 0x66, 0x99, 0x99, 0xff, 0xff, 0x00, 0x00, /* 40% */
	0x8c, 0x00, 0x73, 0x00, 0x8c, 0x73, 0x00, 0x00, 0xff, 0x00, 0x8c, 0xff, 0x8c, 0x00, 0xff, 0x8c, 0x8c, 0x73, 0x8c, 0x8c, 0xff, 0xff, 0x00, 0x00, /* 45% */
	0x7f, 0x00, 0x80, 0x00, 0x7f, 0x80, 0x00, 0x00, 0xff, 0x00, 0x7f, 0xff, 0x7f, 0x00, 0xff, 0x7f, 0x7f, 0x80, 0x7f, 0x7f, 0xff, 0xff, 0x00, 0x00, /* 50% */
	0x73, 0x00, 0x8c, 0x00, 0x73, 0x8c, 0x00, 0x00, 0xff, 0x00, 0x73, 0xff, 0x73, 0x00, 0xff, 0x73, 0x73, 0x8c, 0x73, 0x73, 0xff, 0xff, 0x00, 0x00, /* 55% */
	0x66, 0x00, 0x99, 0x00, 0x66, 0x99, 0x00, 0x00, 0xff, 0x00, 0x66, 0xff, 0x66, 0x00, 0xff, 0x66, 0x66, 0x99, 0x66, 0x66, 0xff, 0xff, 0x00, 0x00, /* 60% */

	//Azure
	0xcc, 0x19, 0x33, 0x00, 0xe5, 0x33, 0x00, 0x19, 0xff, 0x00, 0xe5, 0xff, 0xcc, 0x19, 0xff, 0xcc, 0xe5, 0x33, 0xcc, 0xe5, 0xff, 0xff, 0x00, 0x00, /* 20% */
	0xbf, 0x20, 0x40, 0x00, 0xdf, 0x40, 0x00, 0x20, 0xff, 0x00, 0xdf, 0xff, 0xbf, 0x20, 0xff, 0xbf, 0xdf, 0x40, 0xbf, 0xdf, 0xff, 0xff, 0x00, 0x00, /* 25% */
	0xb2, 0x26, 0x4d, 0x00, 0xd8, 0x4d, 0x00, 0x26, 0xff, 0x00, 0xd8, 0xff, 0xb2, 0x26, 0xff, 0xb2, 0xd8, 0x4d, 0xb2, 0xd8, 0xff, 0xff, 0x00, 0x00, /* 30% */
	0xa6, 0x2c, 0x59, 0x00, 0xd2, 0x59, 0x00, 0x2c, 0xff, 0x00, 0xd2, 0xff, 0xa6, 0x2c, 0xff, 0xa6, 0xd2, 0x59, 0xa6, 0xd2, 0xff, 0xff, 0x00, 0x00, /* 35% */
	0x99, 0x33, 0x66, 0x00, 0xcc, 0x66, 0x00, 0x33, 0xff, 0x00, 0xcc, 0xff, 0x99, 0x33, 0xff, 0x99, 0xcc, 0x66, 0x99, 0xcc, 0xff, 0xff, 0x00, 0x00, /* 40% */
	0x8c, 0x39, 0x73, 0x00, 0xc5, 0x73, 0x00, 0x39, 0xff, 0x00, 0xc5, 0xff, 0x8c, 0x39, 0xff, 0x8c, 0xc5, 0x73, 0x8c, 0xc5, 0xff, 0xff, 0x00, 0x00, /* 45% */
	0x7f, 0x40, 0x80, 0x00, 0xbf, 0x80, 0x00, 0x40, 0xff, 0x00, 0xbf, 0xff, 0x7f, 0x40, 0xff, 0x7f, 0xbf, 0x80, 0x7f, 0xbf, 0xff, 0xff, 0x00, 0x00, /* 50% */
	0x73, 0x46, 0x8c, 0x00, 0xb9, 0x8c, 0x00, 0x46, 0xff, 0x00, 0xb9, 0xff, 0x73, 0x46, 0xff, 0x73, 0xb9, 0x8c, 0x73, 0xb9, 0xff, 0xff, 0x00, 0x00, /* 55% */
	0x66, 0x4c, 0x99, 0x00, 0xb2, 0x99, 0x00, 0x4c, 0xff, 0x00, 0xb2, 0xff, 0x66, 0x4c, 0xff, 0x66, 0xb2, 0x99, 0x66, 0xb2, 0xff, 0xff, 0x00, 0x00, /* 60% */

	//Cyan
	0xcc, 0x33, 0x33, 0x00, 0xff, 0x33, 0x00, 0x33, 0xff, 0x00, 0xff, 0xff, 0xcc, 0x33, 0xff, 0xcc, 0xff, 0x33, 0xcc, 0xff, 0xff, 0xff, 0x00, 0x00, /* 20% */
	0xbf, 0x40, 0x40, 0x00, 0xff, 0x40, 0x00, 0x40, 0xff, 0x00, 0xff, 0xff, 0xbf, 0x40, 0xff, 0xbf, 0xff, 0x40, 0xbf, 0xff, 0xff, 0xff, 0x00, 0x00, /* 25% */
	0xb2, 0x4d, 0x4d, 0x00, 0xff, 0x4d, 0x00, 0x4d, 0xff, 0x00, 0xff, 0xff, 0xb2, 0x4d, 0xff, 0xb2, 0xff, 0x4d, 0xb2, 0xff, 0xff, 0xff, 0x00, 0x00, /* 30% */
	0xa6, 0x59, 0x59, 0x00, 0xff, 0x59, 0x00, 0x59, 0xff, 0x00, 0xff, 0xff, 0xa6, 0x59, 0xff, 0xa6, 0xff, 0x59, 0xa6, 0xff, 0xff, 0xff, 0x00, 0x00, /* 35% */
	0x99, 0x66, 0x66, 0x00, 0xff, 0x66, 0x00, 0x66, 0xff, 0x00, 0xff, 0xff, 0x99, 0x66, 0xff, 0x99, 0xff, 0x66, 0x99, 0xff, 0xff, 0xff, 0x00, 0x00, /* 40% */
	0x8c, 0x73, 0x73, 0x00, 0xff, 0x73, 0x00, 0x73, 0xff, 0x00, 0xff, 0xff, 0x8c, 0x73, 0xff, 0x8c, 0xff, 0x73, 0x8c, 0xff, 0xff, 0xff, 0x00, 0x00, /* 45% */
	0x7f, 0x80, 0x80, 0x00, 0xff, 0x80, 0x00, 0x80, 0xff, 0x00, 0xff, 0xff, 0x7f, 0x80, 0xff, 0x7f, 0xff, 0x80, 0x7f, 0xff, 0xff, 0xff, 0x00, 0x00, /* 50% */
	0x73, 0x8c, 0x8c, 0x00, 0xff, 0x8c, 0x00, 0x8c, 0xff, 0x00, 0xff, 0xff, 0x73, 0x8c, 0xff, 0x73, 0xff, 0x8c, 0x73, 0xff, 0xff, 0xff, 0x00, 0x00, /* 55% */
	0x66, 0x99, 0x99, 0x00, 0xff, 0x99, 0x00, 0x99, 0xff, 0x00, 0xff, 0xff, 0x66, 0x99, 0xff, 0x66, 0xff, 0x99, 0x66, 0xff, 0xff, 0xff, 0x00, 0x00, /* 60% */

	//Spring green
	0xcc, 0x33, 0x19, 0x00, 0xff, 0x19, 0x00, 0x33, 0xe5, 0x00, 0xff, 0xe5, 0xcc, 0x33, 0xe5, 0xcc, 0xff, 0x19, 0xcc, 0xff, 0xe5, 0xff, 0x00, 0x00, /* 20% */
	0xbf, 0x40, 0x20, 0x00, 0xff, 0x20, 0x00, 0x40, 0xdf, 0x00, 0xff, 0xdf, 0xbf, 0x40, 0xdf, 0xbf, 0xff, 0x20, 0xbf, 0xff, 0xdf, 0xff, 0x00, 0x00, /* 25% */
	0xb2, 0x4d, 0x26, 0x00, 0xff, 0x26, 0x00, 0x4d, 0xd8, 0x00, 0xff, 0xd8, 0xb2, 0x4d, 0xd8, 0xb2, 0xff, 0x26, 0xb2, 0xff, 0xd8, 0xff, 0x00, 0x00, /* 30% */
	0xa6, 0x59, 0x2c, 0x00, 0xff, 0x2c, 0x00, 0x59, 0xd2, 0x00, 0xff, 0xd2, 0xa6, 0x59, 0xd2, 0xa6, 0xff, 0x2c, 0xa6, 0xff, 0xd2, 0xff, 0x00, 0x00, /* 35% */
	0x99, 0x66, 0x33, 0x00, 0xff, 0x33, 0x00, 0x66, 0xcc, 0x00, 0xff, 0xcc, 0x99, 0x66, 0xcc, 0x99, 0xff, 0x33, 0x99, 0xff, 0xcc, 0xff, 0x00, 0x00, /* 40% */
	0x8c, 0x73, 0x39, 0x00, 0xff, 0x39, 0x00, 0x73, 0xc5, 0x00, 0xff, 0xc5, 0x8c, 0x73, 0xc5, 0x8c, 0xff, 0x39, 0x8c, 0xff, 0xc5, 0xff, 0x00, 0x00, /* 45% */
	0x7f, 0x80, 0x40, 0x00, 0xff, 0x40, 0x00, 0x80, 0xbf, 0x00, 0xff, 0xbf, 0x7f, 0x80, 0xbf, 0x7f, 0xff, 0x40, 0x7f, 0xff, 0xbf, 0xff, 0x00, 0x00, /* 50% */
	0x73, 0x8c, 0x46, 0x00, 0xff, 0x46, 0x00, 0x8c, 0xb9, 0x00, 0xff, 0xb9, 0x73, 0x8c, 0xb9, 0x73, 0xff, 0x46, 0x73, 0xff, 0xb9, 0xff, 0x00, 0x00, /* 55% */
	0x66, 0x99, 0x4c, 0x00, 0xff, 0x4c, 0x00, 0x99, 0xb2, 0x00, 0xff, 0xb2, 0x66, 0x99, 0xb2, 0x66, 0xff, 0x4c, 0x66, 0xff, 0xb2, 0xff, 0x00, 0x00, /* 60% */

	//Green
	0xcc, 0x33, 0x00, 0x00, 0xff, 0x00, 0x00, 0x33, 0xcc, 0x00, 0xff, 0xcc, 0xcc, 0x33, 0xcc, 0xcc, 0xff, 0x00, 0xcc, 0xff, 0xcc, 0xff, 0x00, 0x00, /* 20% */
	0xbf, 0x40, 0x00, 0x00, 0xff, 0x00, 0x00, 0x40, 0xbf, 0x00, 0xff, 0xbf, 0xbf, 0x40, 0xbf, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0xbf, 0xff, 0x00, 0x00, /* 25% */
	0xb2, 0x4d, 0x00, 0x00, 0xff, 0x00, 0x00, 0x4d, 0xb2, 0x00, 0xff, 0xb2, 0xb2, 0x4d, 0xb2, 0xb2, 0xff, 0x00, 0xb2, 0xff, 0xb2, 0xff, 0x00, 0x00, /* 30% */
	0xa6, 0x59, 0x00, 0x00, 0xff, 0x00, 0x00, 0x59, 0xa6, 0x00, 0xff, 0xa6, 0xa6, 0x59, 0xa6, 0xa6, 0xff, 0x00, 0xa6, 0xff, 0xa6, 0xff, 0x00, 0x00, /* 35% */
	0x99, 0x66, 0x00, 0x00, 0xff, 0x00, 0x00, 0x66, 0x99, 0x00, 0xff, 0x99, 0x99, 0x66, 0x99, 0x99, 0xff, 0x00, 0x99, 0xff, 0x99, 0xff, 0x00, 0x00, /* 40% */
	0x8c, 0x73, 0x00, 0x00, 0xff, 0x00, 0x00, 0x73, 0x8c, 0x00, 0xff, 0x8c, 0x8c, 0x73, 0x8c, 0x8c, 0xff, 0x00, 0x8c, 0xff, 0x8c, 0xff, 0x00, 0x00, /* 45% */
	0x7f, 0x80, 0x00, 0x00, 0xff, 0x00, 0x00, 0x80, 0x7f, 0x00, 0xff, 0x7f, 0x7f, 0x80, 0x7f, 0x7f, 0xff, 0x00, 0x7f, 0xff, 0x7f, 0xff, 0x00, 0x00, /* 50% */
	0x73, 0x8c, 0x00, 0x00, 0xff, 0x00, 0x00, 0x8c, 0x73, 0x00, 0xff, 0x73, 0x73, 0x8c, 0x73, 0x73, 0xff, 0x00, 0x73, 0xff, 0x73, 0xff, 0x00, 0x00, /* 55% */
	0x66, 0x99, 0x00, 0x00, 0xff, 0x00, 0x00, 0x99, 0x66, 0x00, 0xff, 0x66, 0x66, 0x99, 0x66, 0x66, 0xff, 0x00, 0x66, 0xff, 0x66, 0xff, 0x00, 0x00, /* 60% */

	//Chartreuse Gre
	0xe5, 0x33, 0x00, 0x19, 0xff, 0x00, 0x19, 0x33, 0xcc, 0x19, 0xff, 0xcc, 0xe5, 0x33, 0xcc, 0xe5, 0xff, 0x00, 0xe5, 0xff, 0xcc, 0xff, 0x00, 0x00, /* 20% */
	0xdf, 0x40, 0x00, 0x20, 0xff, 0x00, 0x20, 0x40, 0xbf, 0x20, 0xff, 0xbf, 0xdf, 0x40, 0xbf, 0xdf, 0xff, 0x00, 0xdf, 0xff, 0xbf, 0xff, 0x00, 0x00, /* 25% */
	0xd8, 0x4d, 0x00, 0x26, 0xff, 0x00, 0x26, 0x4d, 0xb2, 0x26, 0xff, 0xb2, 0xd8, 0x4d, 0xb2, 0xd8, 0xff, 0x00, 0xd8, 0xff, 0xb2, 0xff, 0x00, 0x00, /* 30% */
	0xd2, 0x59, 0x00, 0x2c, 0xff, 0x00, 0x2c, 0x59, 0xa6, 0x2c, 0xff, 0xa6, 0xd2, 0x59, 0xa6, 0xd2, 0xff, 0x00, 0xd2, 0xff, 0xa6, 0xff, 0x00, 0x00, /* 35% */
	0xcc, 0x66, 0x00, 0x33, 0xff, 0x00, 0x33, 0x66, 0x99, 0x33, 0xff, 0x99, 0xcc, 0x66, 0x99, 0xcc, 0xff, 0x00, 0xcc, 0xff, 0x99, 0xff, 0x00, 0x00, /* 40% */
	0xc5, 0x73, 0x00, 0x39, 0xff, 0x00, 0x39, 0x73, 0x8c, 0x39, 0xff, 0x8c, 0xc5, 0x73, 0x8c, 0xc5, 0xff, 0x00, 0xc5, 0xff, 0x8c, 0xff, 0x00, 0x00, /* 45% */
	0xbf, 0x80, 0x00, 0x40, 0xff, 0x00, 0x40, 0x80, 0x7f, 0x40, 0xff, 0x7f, 0xbf, 0x80, 0x7f, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x7f, 0xff, 0x00, 0x00, /* 50% */
	0xb9, 0x8c, 0x00, 0x46, 0xff, 0x00, 0x46, 0x8c, 0x73, 0x46, 0xff, 0x73, 0xb9, 0x8c, 0x73, 0xb9, 0xff, 0x00, 0xb9, 0xff, 0x73, 0xff, 0x00, 0x00, /* 55% */
	0xb2, 0x99, 0x00, 0x4c, 0xff, 0x00, 0x4c, 0x99, 0x66, 0x4c, 0xff, 0x66, 0xb2, 0x99, 0x66, 0xb2, 0xff, 0x00, 0xb2, 0xff, 0x66, 0xff, 0x00, 0x00, /* 60% */

	//Yellow
	0xff, 0x33, 0x00, 0x33, 0xff, 0x00, 0x33, 0x33, 0xcc, 0x33, 0xff, 0xcc, 0xff, 0x33, 0xcc, 0xff, 0xff, 0x00, 0xff, 0xff, 0xcc, 0xff, 0x00, 0x00, /* 20% */
	0xff, 0x40, 0x00, 0x40, 0xff, 0x00, 0x40, 0x40, 0xbf, 0x40, 0xff, 0xbf, 0xff, 0x40, 0xbf, 0xff, 0xff, 0x00, 0xff, 0xff, 0xbf, 0xff, 0x00, 0x00, /* 25% */
	0xff, 0x4d, 0x00, 0x4d, 0xff, 0x00, 0x4d, 0x4d, 0xb2, 0x4d, 0xff, 0xb2, 0xff, 0x4d, 0xb2, 0xff, 0xff, 0x00, 0xff, 0xff, 0xb2, 0xff, 0x00, 0x00, /* 30% */
	0xff, 0x59, 0x00, 0x59, 0xff, 0x00, 0x59, 0x59, 0xa6, 0x59, 0xff, 0xa6, 0xff, 0x59, 0xa6, 0xff, 0xff, 0x00, 0xff, 0xff, 0xa6, 0xff, 0x00, 0x00, /* 35% */
	0xff, 0x66, 0x00, 0x66, 0xff, 0x00, 0x66, 0x66, 0x99, 0x66, 0xff, 0x99, 0xff, 0x66, 0x99, 0xff, 0xff, 0x00, 0xff, 0xff, 0x99, 0xff, 0x00, 0x00, /* 40% */
	0xff, 0x73, 0x00, 0x73, 0xff, 0x00, 0x73, 0x73, 0x8c, 0x73, 0xff, 0x8c, 0xff, 0x73, 0x8c, 0xff, 0xff, 0x00, 0xff, 0xff, 0x8c, 0xff, 0x00, 0x00, /* 45% */
	0xff, 0x80, 0x00, 0x80, 0xff, 0x00, 0x80, 0x80, 0x7f, 0x80, 0xff, 0x7f, 0xff, 0x80, 0x7f, 0xff, 0xff, 0x00, 0xff, 0xff, 0x7f, 0xff, 0x00, 0x00, /* 50% */
	0xff, 0x8c, 0x00, 0x8c, 0xff, 0x00, 0x8c, 0x8c, 0x73, 0x8c, 0xff, 0x73, 0xff, 0x8c, 0x73, 0xff, 0xff, 0x00, 0xff, 0xff, 0x73, 0xff, 0x00, 0x00, /* 55% */
	0xff, 0x99, 0x00, 0x99, 0xff, 0x00, 0x99, 0x99, 0x66, 0x99, 0xff, 0x66, 0xff, 0x99, 0x66, 0xff, 0xff, 0x00, 0xff, 0xff, 0x66, 0xff, 0x00, 0x00, /* 60% */

	//Orange
	0xff, 0x19, 0x00, 0x33, 0xe5, 0x00, 0x33, 0x19, 0xcc, 0x33, 0xe5, 0xcc, 0xff, 0x19, 0xcc, 0xff, 0xe5, 0x00, 0xff, 0xe5, 0xcc, 0xff, 0x00, 0x00, /* 20% */
	0xff, 0x20, 0x00, 0x40, 0xdf, 0x00, 0x40, 0x20, 0xbf, 0x40, 0xdf, 0xbf, 0xff, 0x20, 0xbf, 0xff, 0xdf, 0x00, 0xff, 0xdf, 0xbf, 0xff, 0x00, 0x00, /* 25% */
	0xff, 0x26, 0x00, 0x4d, 0xd8, 0x00, 0x4d, 0x26, 0xb2, 0x4d, 0xd8, 0xb2, 0xff, 0x26, 0xb2, 0xff, 0xd8, 0x00, 0xff, 0xd8, 0xb2, 0xff, 0x00, 0x00, /* 30% */
	0xff, 0x2c, 0x00, 0x59, 0xd2, 0x00, 0x59, 0x2c, 0xa6, 0x59, 0xd2, 0xa6, 0xff, 0x2c, 0xa6, 0xff, 0xd2, 0x00, 0xff, 0xd2, 0xa6, 0xff, 0x00, 0x00, /* 35% */
	0xff, 0x33, 0x00, 0x66, 0xcc, 0x00, 0x66, 0x33, 0x99, 0x66, 0xcc, 0x99, 0xff, 0x33, 0x99, 0xff, 0xcc, 0x00, 0xff, 0xcc, 0x99, 0xff, 0x00, 0x00, /* 40% */
	0xff, 0x39, 0x00, 0x73, 0xc5, 0x00, 0x73, 0x39, 0x8c, 0x73, 0xc5, 0x8c, 0xff, 0x39, 0x8c, 0xff, 0xc5, 0x00, 0xff, 0xc5, 0x8c, 0xff, 0x00, 0x00, /* 45% */
	0xff, 0x40, 0x00, 0x80, 0xbf, 0x00, 0x80, 0x40, 0x7f, 0x80, 0xbf, 0x7f, 0xff, 0x40, 0x7f, 0xff, 0xbf, 0x00, 0xff, 0xbf, 0x7f, 0xff, 0x00, 0x00, /* 50% */
	0xff, 0x46, 0x00, 0x8c, 0xb9, 0x00, 0x8c, 0x46, 0x73, 0x8c, 0xb9, 0x73, 0xff, 0x46, 0x73, 0xff, 0xb9, 0x00, 0xff, 0xb9, 0x73, 0xff, 0x00, 0x00, /* 55% */
	0xff, 0x4c, 0x00, 0x99, 0xb2, 0x00, 0x99, 0x4c, 0x66, 0x99, 0xb2, 0x66, 0xff, 0x4c, 0x66, 0xff, 0xb2, 0x00, 0xff, 0xb2, 0x66, 0xff, 0x00, 0x00, /* 60% */

	//Red
	0xff, 0x00, 0x00, 0x33, 0xcc, 0x00, 0x33, 0x00, 0xcc, 0x33, 0xcc, 0xcc, 0xff, 0x00, 0xcc, 0xff, 0xcc, 0x00, 0xff, 0xcc, 0xcc, 0xff, 0x00, 0x00, /* 20% */
	0xff, 0x00, 0x00, 0x40, 0xbf, 0x00, 0x40, 0x00, 0xbf, 0x40, 0xbf, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0xbf, 0x00, 0xff, 0xbf, 0xbf, 0xff, 0x00, 0x00, /* 25% */
	0xff, 0x00, 0x00, 0x4d, 0xb2, 0x00, 0x4d, 0x00, 0xb2, 0x4d, 0xb2, 0xb2, 0xff, 0x00, 0xb2, 0xff, 0xb2, 0x00, 0xff, 0xb2, 0xb2, 0xff, 0x00, 0x00, /* 30% */
	0xff, 0x00, 0x00, 0x59, 0xa6, 0x00, 0x59, 0x00, 0xa6, 0x59, 0xa6, 0xa6, 0xff, 0x00, 0xa6, 0xff, 0xa6, 0x00, 0xff, 0xa6, 0xa6, 0xff, 0x00, 0x00, /* 35% */
	0xff, 0x00, 0x00, 0x66, 0x99, 0x00, 0x66, 0x00, 0x99, 0x66, 0x99, 0x99, 0xff, 0x00, 0x99, 0xff, 0x99, 0x00, 0xff, 0x99, 0x99, 0xff, 0x00, 0x00, /* 40% */
	0xff, 0x00, 0x00, 0x73, 0x8c, 0x00, 0x73, 0x00, 0x8c, 0x73, 0x8c, 0x8c, 0xff, 0x00, 0x8c, 0xff, 0x8c, 0x00, 0xff, 0x8c, 0x8c, 0xff, 0x00, 0x00, /* 45% */
	0xff, 0x00, 0x00, 0x80, 0x7f, 0x00, 0x80, 0x00, 0x7f, 0x80, 0x7f, 0x7f, 0xff, 0x00, 0x7f, 0xff, 0x7f, 0x00, 0xff, 0x7f, 0x7f, 0xff, 0x00, 0x00, /* 50% */
	0xff, 0x00, 0x00, 0x8c, 0x73, 0x00, 0x8c, 0x00, 0x73, 0x8c, 0x73, 0x73, 0xff, 0x00, 0x73, 0xff, 0x73, 0x00, 0xff, 0x73, 0x73, 0xff, 0x00, 0x00, /* 55% */
	0xff, 0x00, 0x00, 0x99, 0x66, 0x00, 0x99, 0x00, 0x66, 0x99, 0x66, 0x66, 0xff, 0x00, 0x66, 0xff, 0x66, 0x00, 0xff, 0x66, 0x66, 0xff, 0x00, 0x00, /* 60% */

	//Rose
	0xff, 0x00, 0x19, 0x33, 0xcc, 0x19, 0x33, 0x00, 0xe5, 0x33, 0xcc, 0xe5, 0xff, 0x00, 0xe5, 0xff, 0xcc, 0x19, 0xff, 0xcc, 0xe5, 0xff, 0x00, 0x00, /* 20% */
	0xff, 0x00, 0x20, 0x40, 0xbf, 0x20, 0x40, 0x00, 0xdf, 0x40, 0xbf, 0xdf, 0xff, 0x00, 0xdf, 0xff, 0xbf, 0x20, 0xff, 0xbf, 0xdf, 0xff, 0x00, 0x00, /* 25% */
	0xff, 0x00, 0x26, 0x4d, 0xb2, 0x26, 0x4d, 0x00, 0xd8, 0x4d, 0xb2, 0xd8, 0xff, 0x00, 0xd8, 0xff, 0xb2, 0x26, 0xff, 0xb2, 0xd8, 0xff, 0x00, 0x00, /* 30% */
	0xff, 0x00, 0x2c, 0x59, 0xa6, 0x2c, 0x59, 0x00, 0xd2, 0x59, 0xa6, 0xd2, 0xff, 0x00, 0xd2, 0xff, 0xa6, 0x2c, 0xff, 0xa6, 0xd2, 0xff, 0x00, 0x00, /* 35% */
	0xff, 0x00, 0x33, 0x66, 0x99, 0x33, 0x66, 0x00, 0xcc, 0x66, 0x99, 0xcc, 0xff, 0x00, 0xcc, 0xff, 0x99, 0x33, 0xff, 0x99, 0xcc, 0xff, 0x00, 0x00, /* 40% */
	0xff, 0x00, 0x39, 0x73, 0x8c, 0x39, 0x73, 0x00, 0xc5, 0x73, 0x8c, 0xc5, 0xff, 0x00, 0xc5, 0xff, 0x8c, 0x39, 0xff, 0x8c, 0xc5, 0xff, 0x00, 0x00, /* 45% */
	0xff, 0x00, 0x40, 0x80, 0x7f, 0x40, 0x80, 0x00, 0xbf, 0x80, 0x7f, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x7f, 0x40, 0xff, 0x7f, 0xbf, 0xff, 0x00, 0x00, /* 50% */
	0xff, 0x00, 0x46, 0x8c, 0x73, 0x46, 0x8c, 0x00, 0xb9, 0x8c, 0x73, 0xb9, 0xff, 0x00, 0xb9, 0xff, 0x73, 0x46, 0xff, 0x73, 0xb9, 0xff, 0x00, 0x00, /* 55% */
	0xff, 0x00, 0x4c, 0x99, 0x66, 0x4c, 0x99, 0x00, 0xb2, 0x99, 0x66, 0xb2, 0xff, 0x00, 0xb2, 0xff, 0x66, 0x4c, 0xff, 0x66, 0xb2, 0xff, 0x00, 0x00, /* 60% */

	//Magenta
	0xff, 0x00, 0x33, 0x33, 0xcc, 0x33, 0x33, 0x00, 0xff, 0x33, 0xcc, 0xff, 0xff, 0x00, 0xff, 0xff, 0xcc, 0x33, 0xff, 0xcc, 0xff, 0xff, 0x00, 0x00, /* 20% */
	0xff, 0x00, 0x40, 0x40, 0xbf, 0x40, 0x40, 0x00, 0xff, 0x40, 0xbf, 0xff, 0xff, 0x00, 0xff, 0xff, 0xbf, 0x40, 0xff, 0xbf, 0xff, 0xff, 0x00, 0x00, /* 25% */
	0xff, 0x00, 0x4d, 0x4d, 0xb2, 0x4d, 0x4d, 0x00, 0xff, 0x4d, 0xb2, 0xff, 0xff, 0x00, 0xff, 0xff, 0xb2, 0x4d, 0xff, 0xb2, 0xff, 0xff, 0x00, 0x00, /* 30% */
	0xff, 0x00, 0x59, 0x59, 0xa6, 0x59, 0x59, 0x00, 0xff, 0x59, 0xa6, 0xff, 0xff, 0x00, 0xff, 0xff, 0xa6, 0x59, 0xff, 0xa6, 0xff, 0xff, 0x00, 0x00, /* 35% */
	0xff, 0x00, 0x66, 0x66, 0x99, 0x66, 0x66, 0x00, 0xff, 0x66, 0x99, 0xff, 0xff, 0x00, 0xff, 0xff, 0x99, 0x66, 0xff, 0x99, 0xff, 0xff, 0x00, 0x00, /* 40% */
	0xff, 0x00, 0x73, 0x73, 0x8c, 0x73, 0x73, 0x00, 0xff, 0x73, 0x8c, 0xff, 0xff, 0x00, 0xff, 0xff, 0x8c, 0x73, 0xff, 0x8c, 0xff, 0xff, 0x00, 0x00, /* 45% */
	0xff, 0x00, 0x80, 0x80, 0x7f, 0x80, 0x80, 0x00, 0xff, 0x80, 0x7f, 0xff, 0xff, 0x00, 0xff, 0xff, 0x7f, 0x80, 0xff, 0x7f, 0xff, 0xff, 0x00, 0x00, /* 50% */
	0xff, 0x00, 0x8c, 0x8c, 0x73, 0x8c, 0x8c, 0x00, 0xff, 0x8c, 0x73, 0xff, 0xff, 0x00, 0xff, 0xff, 0x73, 0x8c, 0xff, 0x73, 0xff, 0xff, 0x00, 0x00, /* 55% */
	0xff, 0x00, 0x99, 0x99, 0x66, 0x99, 0x99, 0x00, 0xff, 0x99, 0x66, 0xff, 0xff, 0x00, 0xff, 0xff, 0x66, 0x99, 0xff, 0x66, 0xff, 0xff, 0x00, 0x00, /* 60% */

	//Violet
	0xe5, 0x00, 0x33, 0x19, 0xcc, 0x33, 0x19, 0x00, 0xff, 0x19, 0xcc, 0xff, 0xe5, 0x00, 0xff, 0xe5, 0xcc, 0x33, 0xe5, 0xcc, 0xff, 0xff, 0x00, 0x00, /* 20% */
	0xdf, 0x00, 0x40, 0x20, 0xbf, 0x40, 0x20, 0x00, 0xff, 0x20, 0xbf, 0xff, 0xdf, 0x00, 0xff, 0xdf, 0xbf, 0x40, 0xdf, 0xbf, 0xff, 0xff, 0x00, 0x00, /* 25% */
	0xd8, 0x00, 0x4d, 0x26, 0xb2, 0x4d, 0x26, 0x00, 0xff, 0x26, 0xb2, 0xff, 0xd8, 0x00, 0xff, 0xd8, 0xb2, 0x4d, 0xd8, 0xb2, 0xff, 0xff, 0x00, 0x00, /* 30% */
	0xd2, 0x00, 0x59, 0x2c, 0xa6, 0x59, 0x2c, 0x00, 0xff, 0x2c, 0xa6, 0xff, 0xd2, 0x00, 0xff, 0xd2, 0xa6, 0x59, 0xd2, 0xa6, 0xff, 0xff, 0x00, 0x00, /* 35% */
	0xcc, 0x00, 0x66, 0x33, 0x99, 0x66, 0x33, 0x00, 0xff, 0x33, 0x99, 0xff, 0xcc, 0x00, 0xff, 0xcc, 0x99, 0x66, 0xcc, 0x99, 0xff, 0xff, 0x00, 0x00, /* 40% */
	0xc5, 0x00, 0x73, 0x39, 0x8c, 0x73, 0x39, 0x00, 0xff, 0x39, 0x8c, 0xff, 0xc5, 0x00, 0xff, 0xc5, 0x8c, 0x73, 0xc5, 0x8c, 0xff, 0xff, 0x00, 0x00, /* 45% */
	0xbf, 0x00, 0x80, 0x40, 0x7f, 0x80, 0x40, 0x00, 0xff, 0x40, 0x7f, 0xff, 0xbf, 0x00, 0xff, 0xbf, 0x7f, 0x80, 0xbf, 0x7f, 0xff, 0xff, 0x00, 0x00, /* 50% */
	0xb9, 0x00, 0x8c, 0x46, 0x73, 0x8c, 0x46, 0x00, 0xff, 0x46, 0x73, 0xff, 0xb9, 0x00, 0xff, 0xb9, 0x73, 0x8c, 0xb9, 0x73, 0xff, 0xff, 0x00, 0x00, /* 55% */
	0xb2, 0x00, 0x99, 0x4c, 0x66, 0x99, 0x4c, 0x00, 0xff, 0x4c, 0x66, 0xff, 0xb2, 0x00, 0xff, 0xb2, 0x66, 0x99, 0xb2, 0x66, 0xff, 0xff, 0x00, 0x00, /* 60% */
};

static char DSI0_BYPASS_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x00, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_BYPASS_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_BYPASS_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_BYPASS_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_BYPASS_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xa2, // crc_lut_mode1_rr
	0x0b, // crc_lut_mode1_rg
	0x04, // crc_lut_mode1_rb
	0x38, // crc_lut_mode1_gr
	0xbf, // crc_lut_mode1_gg
	0x13, // crc_lut_mode1_gb
	0x05, // crc_lut_mode1_br
	0x06, // crc_lut_mode1_bg
	0xaf, // crc_lut_mode1_bb
	0x45, // crc_lut_mode1_cr
	0xe0, // crc_lut_mode1_cg
	0xd2, // crc_lut_mode1_cb
	0xc2, // crc_lut_mode1_mr
	0x12, // crc_lut_mode1_mg
	0xc3, // crc_lut_mode1_mb
	0xe3, // crc_lut_mode1_yr
	0xd9, // crc_lut_mode1_yg
	0x19, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfc, // crc_lut_mode1_wg
	0xf6, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_BYPASS_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static char DSI0_NEGATIVE_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x00, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_NEGATIVE_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_NEGATIVE_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_NEGATIVE_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_NEGATIVE_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xa2, // crc_lut_mode1_rr
	0x0b, // crc_lut_mode1_rg
	0x04, // crc_lut_mode1_rb
	0x38, // crc_lut_mode1_gr
	0xbf, // crc_lut_mode1_gg
	0x13, // crc_lut_mode1_gb
	0x05, // crc_lut_mode1_br
	0x06, // crc_lut_mode1_bg
	0xaf, // crc_lut_mode1_bb
	0x45, // crc_lut_mode1_cr
	0xe0, // crc_lut_mode1_cg
	0xd2, // crc_lut_mode1_cb
	0xc2, // crc_lut_mode1_mr
	0x12, // crc_lut_mode1_mg
	0xc3, // crc_lut_mode1_mb
	0xe3, // crc_lut_mode1_yr
	0xd9, // crc_lut_mode1_yg
	0x19, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfc, // crc_lut_mode1_wg
	0xf6, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_NEGATIVE_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static char DSI0_GRAYSCALE_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x00, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_GRAYSCALE_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_GRAYSCALE_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_GRAYSCALE_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_GRAYSCALE_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xa2, // crc_lut_mode1_rr
	0x0b, // crc_lut_mode1_rg
	0x04, // crc_lut_mode1_rb
	0x38, // crc_lut_mode1_gr
	0xbf, // crc_lut_mode1_gg
	0x13, // crc_lut_mode1_gb
	0x05, // crc_lut_mode1_br
	0x06, // crc_lut_mode1_bg
	0xaf, // crc_lut_mode1_bb
	0x45, // crc_lut_mode1_cr
	0xe0, // crc_lut_mode1_cg
	0xd2, // crc_lut_mode1_cb
	0xc2, // crc_lut_mode1_mr
	0x12, // crc_lut_mode1_mg
	0xc3, // crc_lut_mode1_mb
	0xe3, // crc_lut_mode1_yr
	0xd9, // crc_lut_mode1_yg
	0x19, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfc, // crc_lut_mode1_wg
	0xf6, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_GRAYSCALE_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static char DSI0_GRAYSCALE_NEGATIVE_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x00, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_GRAYSCALE_NEGATIVE_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_GRAYSCALE_NEGATIVE_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_GRAYSCALE_NEGATIVE_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_GRAYSCALE_NEGATIVE_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xa2, // crc_lut_mode1_rr
	0x0b, // crc_lut_mode1_rg
	0x04, // crc_lut_mode1_rb
	0x38, // crc_lut_mode1_gr
	0xbf, // crc_lut_mode1_gg
	0x13, // crc_lut_mode1_gb
	0x05, // crc_lut_mode1_br
	0x06, // crc_lut_mode1_bg
	0xaf, // crc_lut_mode1_bb
	0x45, // crc_lut_mode1_cr
	0xe0, // crc_lut_mode1_cg
	0xd2, // crc_lut_mode1_cb
	0xc2, // crc_lut_mode1_mr
	0x12, // crc_lut_mode1_mg
	0xc3, // crc_lut_mode1_mb
	0xe3, // crc_lut_mode1_yr
	0xd9, // crc_lut_mode1_yg
	0x19, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfc, // crc_lut_mode1_wg
	0xf6, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_GRAYSCALE_NEGATIVE_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static char DSI0_COLOR_BLIND_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x00, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_COLOR_BLIND_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_COLOR_BLIND_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_COLOR_BLIND_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_COLOR_BLIND_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xff, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xff, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xff, // crc_lut_mode1_wg
	0xff, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_COLOR_BLIND_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static char DSI0_NIGHT_MODE_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x90, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_NIGHT_MODE_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_NIGHT_MODE_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_NIGHT_MODE_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_NIGHT_MODE_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xff, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xff, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xff, // crc_lut_mode1_wg
	0xff, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_NIGHT_MODE_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static char DSI0_COLOR_LENS_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x90, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_COLOR_LENS_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_COLOR_LENS_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_COLOR_LENS_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_COLOR_LENS_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xff, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xff, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xff, // crc_lut_mode1_wg
	0xff, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_COLOR_LENS_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static char DSI0_HBM_CE_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x00, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_HBM_CE_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_HBM_CE_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_HBM_CE_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x80, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_HBM_CE_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xf5, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xff, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xff, // crc_lut_mode1_wg
	0xff, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_HBM_CE_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static char DSI0_HBM_CE_D65_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x00, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_HBM_CE_D65_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_HBM_CE_D65_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_HBM_CE_D65_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x80, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_HBM_CE_D65_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xf5, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xff, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xff, // crc_lut_mode1_wg
	0xff, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_HBM_CE_D65_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static char DSI0_RGB_SENSOR_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x00, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_RGB_SENSOR_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_RGB_SENSOR_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_RGB_SENSOR_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_RGB_SENSOR_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xff, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xff, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xff, // crc_lut_mode1_wg
	0xff, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_RGB_SENSOR_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static char DSI0_SCREEN_CURTAIN_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x90, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_SCREEN_CURTAIN_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_SCREEN_CURTAIN_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_SCREEN_CURTAIN_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_SCREEN_CURTAIN_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0x00, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0x00, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0x00, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0x00, // crc_lut_mode1_cg
	0x00, // crc_lut_mode1_cb
	0x00, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0x00, // crc_lut_mode1_mb
	0x00, // crc_lut_mode1_yr
	0x00, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0x00, // crc_lut_mode1_wr
	0x00, // crc_lut_mode1_wg
	0x00, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_SCREEN_CURTAIN_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static char DSI0_LIGHT_NOTIFICATION_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x90, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_LIGHT_NOTIFICATION_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_LIGHT_NOTIFICATION_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_LIGHT_NOTIFICATION_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_LIGHT_NOTIFICATION_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x60, // crc_lut_mode1_rg
	0x13, // crc_lut_mode1_rb
	0x66, // crc_lut_mode1_gr
	0xf9, // crc_lut_mode1_gg
	0x13, // crc_lut_mode1_gb
	0x66, // crc_lut_mode1_br
	0x60, // crc_lut_mode1_bg
	0xac, // crc_lut_mode1_bb
	0x66, // crc_lut_mode1_cr
	0xf9, // crc_lut_mode1_cg
	0xac, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x60, // crc_lut_mode1_mg
	0xac, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xf9, // crc_lut_mode1_yg
	0x13, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xf9, // crc_lut_mode1_wg
	0xac, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_LIGHT_NOTIFICATION_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static unsigned char DSI0_HDR_VIDEO_1_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x00, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static unsigned char DSI0_HDR_VIDEO_1_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static unsigned char DSI0_HDR_VIDEO_1_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static unsigned char DSI0_HDR_VIDEO_1_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static unsigned char DSI0_HDR_VIDEO_1_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xa2, // crc_lut_mode1_rr
	0x0b, // crc_lut_mode1_rg
	0x04, // crc_lut_mode1_rb
	0x38, // crc_lut_mode1_gr
	0xbf, // crc_lut_mode1_gg
	0x13, // crc_lut_mode1_gb
	0x05, // crc_lut_mode1_br
	0x06, // crc_lut_mode1_bg
	0xaf, // crc_lut_mode1_bb
	0x45, // crc_lut_mode1_cr
	0xe0, // crc_lut_mode1_cg
	0xd2, // crc_lut_mode1_cb
	0xc2, // crc_lut_mode1_mr
	0x12, // crc_lut_mode1_mg
	0xc3, // crc_lut_mode1_mb
	0xe3, // crc_lut_mode1_yr
	0xd9, // crc_lut_mode1_yg
	0x19, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfc, // crc_lut_mode1_wg
	0xf6, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static unsigned char DSI0_HDR_VIDEO_1_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static unsigned char DSI0_HDR_VIDEO_2_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x00, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static unsigned char DSI0_HDR_VIDEO_2_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static unsigned char DSI0_HDR_VIDEO_2_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static unsigned char DSI0_HDR_VIDEO_2_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static unsigned char DSI0_HDR_VIDEO_2_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xa2, // crc_lut_mode1_rr
	0x0b, // crc_lut_mode1_rg
	0x04, // crc_lut_mode1_rb
	0x38, // crc_lut_mode1_gr
	0xbf, // crc_lut_mode1_gg
	0x13, // crc_lut_mode1_gb
	0x05, // crc_lut_mode1_br
	0x06, // crc_lut_mode1_bg
	0xaf, // crc_lut_mode1_bb
	0x45, // crc_lut_mode1_cr
	0xe0, // crc_lut_mode1_cg
	0xd2, // crc_lut_mode1_cb
	0xc2, // crc_lut_mode1_mr
	0x12, // crc_lut_mode1_mg
	0xc3, // crc_lut_mode1_mb
	0xe3, // crc_lut_mode1_yr
	0xd9, // crc_lut_mode1_yg
	0x19, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfc, // crc_lut_mode1_wg
	0xf6, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static unsigned char DSI0_HDR_VIDEO_2_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static unsigned char DSI0_HDR_VIDEO_3_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x00, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static unsigned char DSI0_HDR_VIDEO_3_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static unsigned char DSI0_HDR_VIDEO_3_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static unsigned char DSI0_HDR_VIDEO_3_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static unsigned char DSI0_HDR_VIDEO_3_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xa2, // crc_lut_mode1_rr
	0x0b, // crc_lut_mode1_rg
	0x04, // crc_lut_mode1_rb
	0x38, // crc_lut_mode1_gr
	0xbf, // crc_lut_mode1_gg
	0x13, // crc_lut_mode1_gb
	0x05, // crc_lut_mode1_br
	0x06, // crc_lut_mode1_bg
	0xaf, // crc_lut_mode1_bb
	0x45, // crc_lut_mode1_cr
	0xe0, // crc_lut_mode1_cg
	0xd2, // crc_lut_mode1_cb
	0xc2, // crc_lut_mode1_mr
	0x12, // crc_lut_mode1_mg
	0xc3, // crc_lut_mode1_mb
	0xe3, // crc_lut_mode1_yr
	0xd9, // crc_lut_mode1_yg
	0x19, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfc, // crc_lut_mode1_wg
	0xf6, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static unsigned char DSI0_HDR_VIDEO_3_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static unsigned char DSI0_HDR_VIDEO_4_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x00, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static unsigned char DSI0_HDR_VIDEO_4_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static unsigned char DSI0_HDR_VIDEO_4_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static unsigned char DSI0_HDR_VIDEO_4_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static unsigned char DSI0_HDR_VIDEO_4_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xa2, // crc_lut_mode1_rr
	0x0b, // crc_lut_mode1_rg
	0x04, // crc_lut_mode1_rb
	0x38, // crc_lut_mode1_gr
	0xbf, // crc_lut_mode1_gg
	0x13, // crc_lut_mode1_gb
	0x05, // crc_lut_mode1_br
	0x06, // crc_lut_mode1_bg
	0xaf, // crc_lut_mode1_bb
	0x45, // crc_lut_mode1_cr
	0xe0, // crc_lut_mode1_cg
	0xd2, // crc_lut_mode1_cb
	0xc2, // crc_lut_mode1_mr
	0x12, // crc_lut_mode1_mg
	0xc3, // crc_lut_mode1_mb
	0xe3, // crc_lut_mode1_yr
	0xd9, // crc_lut_mode1_yg
	0x19, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfc, // crc_lut_mode1_wg
	0xf6, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static unsigned char DSI0_HDR_VIDEO_4_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static unsigned char DSI0_HDR_VIDEO_5_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x00, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static unsigned char DSI0_HDR_VIDEO_5_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static unsigned char DSI0_HDR_VIDEO_5_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static unsigned char DSI0_HDR_VIDEO_5_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static unsigned char DSI0_HDR_VIDEO_5_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xa2, // crc_lut_mode1_rr
	0x0b, // crc_lut_mode1_rg
	0x04, // crc_lut_mode1_rb
	0x38, // crc_lut_mode1_gr
	0xbf, // crc_lut_mode1_gg
	0x13, // crc_lut_mode1_gb
	0x05, // crc_lut_mode1_br
	0x06, // crc_lut_mode1_bg
	0xaf, // crc_lut_mode1_bb
	0x45, // crc_lut_mode1_cr
	0xe0, // crc_lut_mode1_cg
	0xd2, // crc_lut_mode1_cb
	0xc2, // crc_lut_mode1_mr
	0x12, // crc_lut_mode1_mg
	0xc3, // crc_lut_mode1_mb
	0xe3, // crc_lut_mode1_yr
	0xd9, // crc_lut_mode1_yg
	0x19, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfc, // crc_lut_mode1_wg
	0xf6, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static unsigned char DSI0_HDR_VIDEO_5_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static unsigned char DSI0_VIDEO_ENHANCER_D65_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x00, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static unsigned char DSI0_VIDEO_ENHANCER_D65_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static unsigned char DSI0_VIDEO_ENHANCER_D65_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static unsigned char DSI0_VIDEO_ENHANCER_D65_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static unsigned char DSI0_VIDEO_ENHANCER_D65_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xa2, // crc_lut_mode1_rr
	0x0b, // crc_lut_mode1_rg
	0x04, // crc_lut_mode1_rb
	0x38, // crc_lut_mode1_gr
	0xbf, // crc_lut_mode1_gg
	0x13, // crc_lut_mode1_gb
	0x05, // crc_lut_mode1_br
	0x06, // crc_lut_mode1_bg
	0xaf, // crc_lut_mode1_bb
	0x45, // crc_lut_mode1_cr
	0xe0, // crc_lut_mode1_cg
	0xd2, // crc_lut_mode1_cb
	0xc2, // crc_lut_mode1_mr
	0x12, // crc_lut_mode1_mg
	0xc3, // crc_lut_mode1_mb
	0xe3, // crc_lut_mode1_yr
	0xd9, // crc_lut_mode1_yg
	0x19, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfc, // crc_lut_mode1_wg
	0xf6, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static unsigned char DSI0_VIDEO_ENHANCER_D65_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static unsigned char DSI0_VIDEO_ENHANCER_AUTO_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x00, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static unsigned char DSI0_VIDEO_ENHANCER_AUTO_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static unsigned char DSI0_VIDEO_ENHANCER_AUTO_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static unsigned char DSI0_VIDEO_ENHANCER_AUTO_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static unsigned char DSI0_VIDEO_ENHANCER_AUTO_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xa2, // crc_lut_mode1_rr
	0x0b, // crc_lut_mode1_rg
	0x04, // crc_lut_mode1_rb
	0x38, // crc_lut_mode1_gr
	0xbf, // crc_lut_mode1_gg
	0x13, // crc_lut_mode1_gb
	0x05, // crc_lut_mode1_br
	0x06, // crc_lut_mode1_bg
	0xaf, // crc_lut_mode1_bb
	0x45, // crc_lut_mode1_cr
	0xe0, // crc_lut_mode1_cg
	0xd2, // crc_lut_mode1_cb
	0xc2, // crc_lut_mode1_mr
	0x12, // crc_lut_mode1_mg
	0xc3, // crc_lut_mode1_mb
	0xe3, // crc_lut_mode1_yr
	0xd9, // crc_lut_mode1_yg
	0x19, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfc, // crc_lut_mode1_wg
	0xf6, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static unsigned char DSI0_VIDEO_ENHANCER_AUTO_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static unsigned char DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x00, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static unsigned char DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static unsigned char DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static unsigned char DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static unsigned char DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xa2, // crc_lut_mode1_rr
	0x0b, // crc_lut_mode1_rg
	0x04, // crc_lut_mode1_rb
	0x38, // crc_lut_mode1_gr
	0xbf, // crc_lut_mode1_gg
	0x13, // crc_lut_mode1_gb
	0x05, // crc_lut_mode1_br
	0x06, // crc_lut_mode1_bg
	0xaf, // crc_lut_mode1_bb
	0x45, // crc_lut_mode1_cr
	0xe0, // crc_lut_mode1_cg
	0xd2, // crc_lut_mode1_cb
	0xc2, // crc_lut_mode1_mr
	0x12, // crc_lut_mode1_mg
	0xc3, // crc_lut_mode1_mb
	0xe3, // crc_lut_mode1_yr
	0xd9, // crc_lut_mode1_yg
	0x19, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfc, // crc_lut_mode1_wg
	0xf6, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static unsigned char DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static unsigned char DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x00, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static unsigned char DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static unsigned char DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static unsigned char DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static unsigned char DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xa2, // crc_lut_mode1_rr
	0x0b, // crc_lut_mode1_rg
	0x04, // crc_lut_mode1_rb
	0x38, // crc_lut_mode1_gr
	0xbf, // crc_lut_mode1_gg
	0x13, // crc_lut_mode1_gb
	0x05, // crc_lut_mode1_br
	0x06, // crc_lut_mode1_bg
	0xaf, // crc_lut_mode1_bb
	0x45, // crc_lut_mode1_cr
	0xe0, // crc_lut_mode1_cg
	0xd2, // crc_lut_mode1_cb
	0xc2, // crc_lut_mode1_mr
	0x12, // crc_lut_mode1_mg
	0xc3, // crc_lut_mode1_mb
	0xe3, // crc_lut_mode1_yr
	0xd9, // crc_lut_mode1_yg
	0x19, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfc, // crc_lut_mode1_wg
	0xf6, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static unsigned char DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static char DSI0_UI_DYNAMIC_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x90, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_UI_DYNAMIC_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_UI_DYNAMIC_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_UI_DYNAMIC_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_UI_DYNAMIC_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xc6, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x1f, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x02, // crc_lut_mode1_gb
	0x06, // crc_lut_mode1_br
	0x05, // crc_lut_mode1_bg
	0xca, // crc_lut_mode1_bb
	0x20, // crc_lut_mode1_cr
	0xf0, // crc_lut_mode1_cg
	0xe0, // crc_lut_mode1_cb
	0xda, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xd6, // crc_lut_mode1_mb
	0xda, // crc_lut_mode1_yr
	0xd6, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfa, // crc_lut_mode1_wg
	0xf0, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_UI_DYNAMIC_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static char DSI0_UI_STANDARD_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x90, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_UI_STANDARD_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_UI_STANDARD_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_UI_STANDARD_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_UI_STANDARD_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xe4, // crc_lut_mode1_rr
	0x01, // crc_lut_mode1_rg
	0x06, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x05, // crc_lut_mode1_br
	0x05, // crc_lut_mode1_bg
	0xc8, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xe3, // crc_lut_mode1_cg
	0xda, // crc_lut_mode1_cb
	0xfa, // crc_lut_mode1_mr
	0x09, // crc_lut_mode1_mg
	0xde, // crc_lut_mode1_mb
	0xe6, // crc_lut_mode1_yr
	0xdc, // crc_lut_mode1_yg
	0x0c, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfa, // crc_lut_mode1_wg
	0xf0, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_UI_STANDARD_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static char DSI0_UI_NATURAL_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x90, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_UI_NATURAL_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_UI_NATURAL_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_UI_NATURAL_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_UI_NATURAL_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xac, // crc_lut_mode1_rr
	0x02, // crc_lut_mode1_rg
	0x04, // crc_lut_mode1_rb
	0x28, // crc_lut_mode1_gr
	0xfe, // crc_lut_mode1_gg
	0x12, // crc_lut_mode1_gb
	0x05, // crc_lut_mode1_br
	0x06, // crc_lut_mode1_bg
	0xc0, // crc_lut_mode1_bb
	0x4a, // crc_lut_mode1_cr
	0xea, // crc_lut_mode1_cg
	0xde, // crc_lut_mode1_cb
	0xc1, // crc_lut_mode1_mr
	0x07, // crc_lut_mode1_mg
	0xcb, // crc_lut_mode1_mb
	0xe7, // crc_lut_mode1_yr
	0xdd, // crc_lut_mode1_yg
	0x1a, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xf9, // crc_lut_mode1_wg
	0xee, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_UI_NATURAL_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static char DSI0_UI_AUTO_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x90, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_UI_AUTO_MDNIE_2[] = {
	0x83, // TCS
	0x80, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_UI_AUTO_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_UI_AUTO_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_UI_AUTO_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xff, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xff, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xff, // crc_lut_mode1_wg
	0xff, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_UI_AUTO_MDNIE_6[] = {
	0xB2, // TCS
	0x82, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x7f, // skin_boundary_parameter
	0x00,
	0x00,
	0x03,
	0x40,
	0x00,
	0x00,
	0x02,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x00, // skin_boundary_parameter
	0xff,
	0x00,
	0x80,
	0x28,
	0x7e,
	0x00,
	0xff,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0x04,
	0x93,
	0x7a,
	0x00,
	0x2f,
	0x02,
	0x08,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x20, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x8a, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x80, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x32, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xdc, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x88, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x8a, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0x24, // Brightness Parameter
	0x00,
	0x00,
	0x8a,
	0x80,
	0x80,
	0x01,
	0x86,
	0x00,
	0x00,
	0x00,
	0x00,
	0x82,
	0xfa,
	0x80,
	0x00,
	0x80,
	0x00,
	0x7c,
	0xf4,
	0x80,
	0x00,
	0x80,
	0x00,
};

/* VIDEO */

static char DSI0_CAMERA_AUTO_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x90, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_CAMERA_AUTO_MDNIE_2[] = {
	0x83, // TCS
	0x80, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_CAMERA_AUTO_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_CAMERA_AUTO_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_CAMERA_AUTO_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x14, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xff, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xee, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xff, // crc_lut_mode1_wg
	0xff, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_CAMERA_AUTO_MDNIE_6[] = {
	0xB2, // TCS
	0x82, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x7f, // skin_boundary_parameter
	0x00,
	0x00,
	0x03,
	0x40,
	0x00,
	0x00,
	0x02,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x00, // skin_boundary_parameter
	0xff,
	0x00,
	0x80,
	0x28,
	0x7e,
	0x00,
	0xff,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0x04,
	0x93,
	0x7a,
	0x00,
	0x2f,
	0x02,
	0x08,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x20, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x8a, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x80, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x32, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xdc, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x88, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x8a, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0x24, // Brightness Parameter
	0x00,
	0x00,
	0x8a,
	0x80,
	0x80,
	0x01,
	0x86,
	0x00,
	0x00,
	0x00,
	0x00,
	0x82,
	0xfa,
	0x80,
	0x00,
	0x80,
	0x00,
	0x7c,
	0xf4,
	0x80,
	0x00,
	0x80,
	0x00,
};

static char DSI0_GALLERY_AUTO_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x90, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_GALLERY_AUTO_MDNIE_2[] = {
	0x83, // TCS
	0x80, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_GALLERY_AUTO_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_GALLERY_AUTO_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_GALLERY_AUTO_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x14, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xff, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xee, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xff, // crc_lut_mode1_wg
	0xff, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_GALLERY_AUTO_MDNIE_6[] = {
	0xB2, // TCS
	0x82, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x7f, // skin_boundary_parameter
	0x00,
	0x00,
	0x03,
	0x40,
	0x00,
	0x00,
	0x02,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x00, // skin_boundary_parameter
	0xff,
	0x00,
	0x80,
	0x28,
	0x7e,
	0x00,
	0xff,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0x04,
	0x93,
	0x7a,
	0x00,
	0x2f,
	0x02,
	0x08,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x20, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x8a, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x80, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x32, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xdc, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x88, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x8a, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0x24, // Brightness Parameter
	0x00,
	0x00,
	0x8a,
	0x80,
	0x80,
	0x01,
	0x86,
	0x00,
	0x00,
	0x00,
	0x00,
	0x82,
	0xfa,
	0x80,
	0x00,
	0x80,
	0x00,
	0x7c,
	0xf4,
	0x80,
	0x00,
	0x80,
	0x00,
};

/* BROWSER */

static char DSI0_EBOOK_AUTO_MDNIE_1[] = {
	//start
	0x81, // CRC, BLF
	0x90, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_EBOOK_AUTO_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_EBOOK_AUTO_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_EBOOK_AUTO_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_EBOOK_AUTO_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xff, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xff, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xf3, // crc_lut_mode1_wg
	0xde, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_EBOOK_AUTO_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static char DSI0_EMAIL_AUTO_MDNIE_1[] = {
	0x81, // CRC, BLF
	0x90, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_EMAIL_AUTO_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_EMAIL_AUTO_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_EMAIL_AUTO_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_EMAIL_AUTO_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xff, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xff, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xf4, // crc_lut_mode1_wg
	0xea, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_EMAIL_AUTO_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

/* DMB */

static char DSI0_HMT_COLOR_TEMP_6500K_MDNIE_1[] = {
	0x81, // CRC, BLF
	0x90, // CRC on/off, BLF on/off, CRC on/off 0 0 00 00 00 
};

static char DSI0_HMT_COLOR_TEMP_6500K_MDNIE_2[] = {
	0x83, // TCS
	0x00, // 0x80 : TCS_enable, 0x00 : TCS_disable
};

static char DSI0_HMT_COLOR_TEMP_6500K_MDNIE_3[] = {
	0x85, // ACE
	0x00, // 0x00 : ACE_Disable, 0x9F : ACE_Enable, Default Gain
};

static char DSI0_HMT_COLOR_TEMP_6500K_MDNIE_4[] = {
	0x87, // ORE
	0x00, // 0x00 : ORE_Disable, 0x80 : ORE_Enable
	0x00, // ORE_level, ex) 0xff : ORE_255_Step(max), 0x00 : ORE_0_step (min)
};

static char DSI0_HMT_COLOR_TEMP_6500K_MDNIE_5[] = {
	0xB1, // CRC, BLF
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xf5, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xff, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfa, // crc_lut_mode1_wg
	0xf0, // crc_lut_mode1_wb
	0xf1, // crc_lut_mode2_rr
	0x14, // crc_lut_mode2_rg
	0x07, // crc_lut_mode2_rb
	0x00, // crc_lut_mode2_gr
	0xb4, // crc_lut_mode2_gg
	0x07, // crc_lut_mode2_gb
	0x07, // crc_lut_mode2_br
	0x06, // crc_lut_mode2_bg
	0xc1, // crc_lut_mode2_bb
	0x00, // crc_lut_mode2_cr
	0xd0, // crc_lut_mode2_cg
	0xc9, // crc_lut_mode2_cb
	0xff, // crc_lut_mode2_mr
	0x1b, // crc_lut_mode2_mg
	0xd2, // crc_lut_mode2_mb
	0xe4, // crc_lut_mode2_yr
	0xde, // crc_lut_mode2_yg
	0x0f, // crc_lut_mode2_yb
	0xff, // crc_lut_mode2_wr
	0xff, // crc_lut_mode2_wg
	0xff, // crc_lut_mode2_wb
	0xff, // crc_lut_mode3_rr
	0x00, // crc_lut_mode3_rg
	0x00, // crc_lut_mode3_rb
	0x00, // crc_lut_mode3_gr
	0xff, // crc_lut_mode3_gg
	0x00, // crc_lut_mode3_gb
	0x00, // crc_lut_mode3_br
	0x00, // crc_lut_mode3_bg
	0xff, // crc_lut_mode3_bb
	0x00, // crc_lut_mode3_cr
	0xff, // crc_lut_mode3_cg
	0xff, // crc_lut_mode3_cb
	0xff, // crc_lut_mode3_mr
	0x00, // crc_lut_mode3_mg
	0xff, // crc_lut_mode3_mb
	0xff, // crc_lut_mode3_yr
	0xff, // crc_lut_mode3_yg
	0x00, // crc_lut_mode3_yb
	0xff, // crc_lut_mode3_wr
	0xff, // crc_lut_mode3_wg
	0xff, // crc_lut_mode3_wb
	0x30, // blf_fixed_parameter
	0x00, // blue_light_reduction_level 0 - ff
	0x66,
	0xb2,
	0xff,
	0x14, // Diff LUT #0, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x11, // Diff LUT #0, Green, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x04, // Diff LUT #0, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x14, // Diff LUT #0, Cyan, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x11, // Diff LUT #0, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x41,
	0x04, // Diff LUT #0, Yellow, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x00,
	0x00, // Diff LUT #0, White, [r:8bit, g:8bit, b:8bit]
	0x24,
	0x41,
	0x1f, // Diff LUT #1, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x19, // Diff LUT #1, Green, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x04, // Diff LUT #1, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x1e, // Diff LUT #1, Cyan, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x19, // Diff LUT #1, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x66,
	0x04, // Diff LUT #1, Yellow, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x00,
	0x00, // Diff LUT #1, White, [r:8bit, g:8bit, b:8bit]
	0x35,
	0x66,
	0x1d, // Diff LUT #2, Red, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x00,
	0x1d, // Diff LUT #2, Green, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x01, // Diff LUT #2, Blue, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x1e, // Diff LUT #2, Cyan, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
	0x1d, // Diff LUT #2, Magenta, [r:8bit, g:8bit, b:8bit]
	0x00,
	0x3c,
	0x01, // Diff LUT #2, Yellow, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x00,
	0x00, // Diff LUT #2, White, [r:8bit, g:8bit, b:8bit]
	0x38,
	0x3c,
};

static char DSI0_HMT_COLOR_TEMP_6500K_MDNIE_6[] = {
	0xB2, // TCS
	0x02, // bypass, control switch
	0x0f, // skin_boundary_parameter
	0x05, // grass_boundary_parameter
	0x0f, // sky_boundary_paraneter
	0x0c, // skin_boundary_parameter
	0x0c, // grass_boundary_parameter
	0x0c, // sky_boundary_paraneter
	0x09, // skin_boundary_parameter
	0x9a,
	0x00,
	0x15,
	0x0b,
	0xc0,
	0x00,
	0x1a,
	0x00, // grass_boundary_parameter
	0xf0,
	0x00,
	0x59,
	0x00,
	0xf0,
	0x00,
	0x59,
	0x02, // sky_boundary_paraneter
	0x49,
	0x00,
	0x60,
	0x02,
	0x5a,
	0x00,
	0x63,
	0x03, // skin_boundary_parameter
	0xb4,
	0x00,
	0x8b,
	0x06,
	0xa7,
	0x00,
	0xbc,
	0x00, // grass_boundary_parameter
	0x9f,
	0x00,
	0x33,
	0x00,
	0xf0,
	0x00,
	0x72,
	0x01, // sky_boundary_paraneter
	0xae,
	0x00,
	0x89,
	0x02,
	0x16,
	0x00,
	0xb3,
	0x00, // skin_boundary_parameter
	0xda,
	0x11,
	0xcb,
	0x01,
	0x3b,
	0x07,
	0xe0,
	0x0b, // grass_boundary_parameter
	0x24,
	0x0a,
	0x18,
	0x04,
	0x6a,
	0x06,
	0xcd,
	0x04, // sky_boundary_paraneter
	0x98,
	0x0f,
	0xc1,
	0x06,
	0xe6,
	0x0a,
	0xe1,
	0x64, // skin_boundary_parameter
	0x62, // grass_boundary_parameter
	0x61, // sky_boundary_paraneter
	0x80, // Skin Color Gain (0x00 ~ 0xFF)
	0x80, // grass Color Gain (0x00 ~ 0xFF)
	0x80, // sky Color Gain (0x00 ~ 0xFF)
	0x73, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xae, // Target Sky Color (Cb)
	0x90, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x1e, // Minumum Y of Skin Brightness Control
	0x1e, // Minumum Y of grass Brightness Control
	0x1e, // Minumum Y of Sky Brightness Control
	0xc8, // Maximum Y of Skin Brightness Control
	0xc8, // Maximum Y of grass Brightness Control
	0xc8, // Maximum Y of Sky Brightness Control
	0x78, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x82, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0xb6, // Brightness Parameter
	0x00,
	0x00,
	0xa9,
	0x80,
	0x80,
	0x04,
	0x2b,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8e,
	0x39,
	0x80,
	0x00,
	0x80,
	0x00,
	0x70,
	0x00,
	0x80,
	0x00,
	0x80,
	0x00,
};

static struct dsi_cmd_desc DSI0_BYPASS_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_1), DSI0_BYPASS_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_2), DSI0_BYPASS_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_3), DSI0_BYPASS_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_4), DSI0_BYPASS_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_5), DSI0_BYPASS_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_6), DSI0_BYPASS_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_NEGATIVE_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NEGATIVE_MDNIE_1), DSI0_NEGATIVE_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NEGATIVE_MDNIE_2), DSI0_NEGATIVE_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NEGATIVE_MDNIE_3), DSI0_NEGATIVE_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NEGATIVE_MDNIE_4), DSI0_NEGATIVE_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NEGATIVE_MDNIE_5), DSI0_NEGATIVE_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NEGATIVE_MDNIE_6), DSI0_NEGATIVE_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_GRAYSCALE_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GRAYSCALE_MDNIE_1), DSI0_GRAYSCALE_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GRAYSCALE_MDNIE_2), DSI0_GRAYSCALE_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GRAYSCALE_MDNIE_3), DSI0_GRAYSCALE_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GRAYSCALE_MDNIE_4), DSI0_GRAYSCALE_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GRAYSCALE_MDNIE_5), DSI0_GRAYSCALE_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GRAYSCALE_MDNIE_6), DSI0_GRAYSCALE_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_GRAYSCALE_NEGATIVE_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GRAYSCALE_NEGATIVE_MDNIE_1), DSI0_GRAYSCALE_NEGATIVE_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GRAYSCALE_NEGATIVE_MDNIE_2), DSI0_GRAYSCALE_NEGATIVE_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GRAYSCALE_NEGATIVE_MDNIE_3), DSI0_GRAYSCALE_NEGATIVE_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GRAYSCALE_NEGATIVE_MDNIE_4), DSI0_GRAYSCALE_NEGATIVE_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GRAYSCALE_NEGATIVE_MDNIE_5), DSI0_GRAYSCALE_NEGATIVE_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GRAYSCALE_NEGATIVE_MDNIE_6), DSI0_GRAYSCALE_NEGATIVE_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_COLOR_BLIND_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_BLIND_MDNIE_1), DSI0_COLOR_BLIND_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_BLIND_MDNIE_2), DSI0_COLOR_BLIND_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_BLIND_MDNIE_3), DSI0_COLOR_BLIND_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_BLIND_MDNIE_4), DSI0_COLOR_BLIND_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_BLIND_MDNIE_5), DSI0_COLOR_BLIND_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_BLIND_MDNIE_6), DSI0_COLOR_BLIND_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_NIGHT_MODE_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NIGHT_MODE_MDNIE_1), DSI0_NIGHT_MODE_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NIGHT_MODE_MDNIE_2), DSI0_NIGHT_MODE_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NIGHT_MODE_MDNIE_3), DSI0_NIGHT_MODE_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NIGHT_MODE_MDNIE_4), DSI0_NIGHT_MODE_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NIGHT_MODE_MDNIE_5), DSI0_NIGHT_MODE_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NIGHT_MODE_MDNIE_6), DSI0_NIGHT_MODE_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_COLOR_LENS_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_LENS_MDNIE_1), DSI0_COLOR_LENS_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_LENS_MDNIE_2), DSI0_COLOR_LENS_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_LENS_MDNIE_3), DSI0_COLOR_LENS_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_LENS_MDNIE_4), DSI0_COLOR_LENS_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_LENS_MDNIE_5), DSI0_COLOR_LENS_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_LENS_MDNIE_6), DSI0_COLOR_LENS_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_HBM_CE_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_MDNIE_1), DSI0_HBM_CE_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_MDNIE_2), DSI0_HBM_CE_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_MDNIE_3), DSI0_HBM_CE_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_MDNIE_4), DSI0_HBM_CE_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_MDNIE_5), DSI0_HBM_CE_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_MDNIE_6), DSI0_HBM_CE_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_HBM_CE_D65_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_D65_MDNIE_1), DSI0_HBM_CE_D65_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_D65_MDNIE_2), DSI0_HBM_CE_D65_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_D65_MDNIE_3), DSI0_HBM_CE_D65_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_D65_MDNIE_4), DSI0_HBM_CE_D65_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_D65_MDNIE_5), DSI0_HBM_CE_D65_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_D65_MDNIE_6), DSI0_HBM_CE_D65_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_RGB_SENSOR_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_RGB_SENSOR_MDNIE_1), DSI0_RGB_SENSOR_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_RGB_SENSOR_MDNIE_2), DSI0_RGB_SENSOR_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_RGB_SENSOR_MDNIE_3), DSI0_RGB_SENSOR_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_RGB_SENSOR_MDNIE_4), DSI0_RGB_SENSOR_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_RGB_SENSOR_MDNIE_5), DSI0_RGB_SENSOR_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_RGB_SENSOR_MDNIE_6), DSI0_RGB_SENSOR_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_SCREEN_CURTAIN_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_SCREEN_CURTAIN_MDNIE_1), DSI0_SCREEN_CURTAIN_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_SCREEN_CURTAIN_MDNIE_2), DSI0_SCREEN_CURTAIN_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_SCREEN_CURTAIN_MDNIE_3), DSI0_SCREEN_CURTAIN_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_SCREEN_CURTAIN_MDNIE_4), DSI0_SCREEN_CURTAIN_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_SCREEN_CURTAIN_MDNIE_5), DSI0_SCREEN_CURTAIN_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_SCREEN_CURTAIN_MDNIE_6), DSI0_SCREEN_CURTAIN_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_LIGHT_NOTIFICATION_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_LIGHT_NOTIFICATION_MDNIE_1), DSI0_LIGHT_NOTIFICATION_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_LIGHT_NOTIFICATION_MDNIE_2), DSI0_LIGHT_NOTIFICATION_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_LIGHT_NOTIFICATION_MDNIE_3), DSI0_LIGHT_NOTIFICATION_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_LIGHT_NOTIFICATION_MDNIE_4), DSI0_LIGHT_NOTIFICATION_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_LIGHT_NOTIFICATION_MDNIE_5), DSI0_LIGHT_NOTIFICATION_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_LIGHT_NOTIFICATION_MDNIE_6), DSI0_LIGHT_NOTIFICATION_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_HDR_VIDEO_1_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_1_MDNIE_1), DSI0_HDR_VIDEO_1_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_1_MDNIE_2), DSI0_HDR_VIDEO_1_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_1_MDNIE_3), DSI0_HDR_VIDEO_1_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_1_MDNIE_4), DSI0_HDR_VIDEO_1_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_1_MDNIE_5), DSI0_HDR_VIDEO_1_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_1_MDNIE_6), DSI0_HDR_VIDEO_1_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_HDR_VIDEO_2_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_2_MDNIE_1), DSI0_HDR_VIDEO_2_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_2_MDNIE_2), DSI0_HDR_VIDEO_2_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_2_MDNIE_3), DSI0_HDR_VIDEO_2_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_2_MDNIE_4), DSI0_HDR_VIDEO_2_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_2_MDNIE_5), DSI0_HDR_VIDEO_2_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_2_MDNIE_6), DSI0_HDR_VIDEO_2_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_HDR_VIDEO_3_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_3_MDNIE_1), DSI0_HDR_VIDEO_3_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_3_MDNIE_2), DSI0_HDR_VIDEO_3_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_3_MDNIE_3), DSI0_HDR_VIDEO_3_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_3_MDNIE_4), DSI0_HDR_VIDEO_3_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_3_MDNIE_5), DSI0_HDR_VIDEO_3_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_3_MDNIE_6), DSI0_HDR_VIDEO_3_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_HDR_VIDEO_4_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_4_MDNIE_1), DSI0_HDR_VIDEO_4_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_4_MDNIE_2), DSI0_HDR_VIDEO_4_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_4_MDNIE_3), DSI0_HDR_VIDEO_4_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_4_MDNIE_4), DSI0_HDR_VIDEO_4_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_4_MDNIE_5), DSI0_HDR_VIDEO_4_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_4_MDNIE_6), DSI0_HDR_VIDEO_4_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_HDR_VIDEO_5_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_5_MDNIE_1), DSI0_HDR_VIDEO_5_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_5_MDNIE_2), DSI0_HDR_VIDEO_5_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_5_MDNIE_3), DSI0_HDR_VIDEO_5_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_5_MDNIE_4), DSI0_HDR_VIDEO_5_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_5_MDNIE_5), DSI0_HDR_VIDEO_5_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_5_MDNIE_6), DSI0_HDR_VIDEO_5_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_VIDEO_ENHANCER_D65_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_D65_MDNIE_1), DSI0_VIDEO_ENHANCER_D65_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_D65_MDNIE_2), DSI0_VIDEO_ENHANCER_D65_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_D65_MDNIE_3), DSI0_VIDEO_ENHANCER_D65_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_D65_MDNIE_4), DSI0_VIDEO_ENHANCER_D65_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_D65_MDNIE_5), DSI0_VIDEO_ENHANCER_D65_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_D65_MDNIE_6), DSI0_VIDEO_ENHANCER_D65_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_VIDEO_ENHANCER_AUTO_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_AUTO_MDNIE_1), DSI0_VIDEO_ENHANCER_AUTO_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_AUTO_MDNIE_2), DSI0_VIDEO_ENHANCER_AUTO_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_AUTO_MDNIE_3), DSI0_VIDEO_ENHANCER_AUTO_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_AUTO_MDNIE_4), DSI0_VIDEO_ENHANCER_AUTO_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_AUTO_MDNIE_5), DSI0_VIDEO_ENHANCER_AUTO_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_AUTO_MDNIE_6), DSI0_VIDEO_ENHANCER_AUTO_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_1), DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_2), DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_3), DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_4), DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_5), DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_6), DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_1), DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_2), DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_3), DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_4), DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_5), DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_6), DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

///////////////////////////////////////////////////////////////////////////////////

static struct dsi_cmd_desc DSI0_UI_DYNAMIC_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_DYNAMIC_MDNIE_1), DSI0_UI_DYNAMIC_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_DYNAMIC_MDNIE_2), DSI0_UI_DYNAMIC_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_DYNAMIC_MDNIE_3), DSI0_UI_DYNAMIC_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_DYNAMIC_MDNIE_4), DSI0_UI_DYNAMIC_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_DYNAMIC_MDNIE_5), DSI0_UI_DYNAMIC_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_DYNAMIC_MDNIE_6), DSI0_UI_DYNAMIC_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_UI_STANDARD_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_STANDARD_MDNIE_1), DSI0_UI_STANDARD_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_STANDARD_MDNIE_2), DSI0_UI_STANDARD_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_STANDARD_MDNIE_3), DSI0_UI_STANDARD_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_STANDARD_MDNIE_4), DSI0_UI_STANDARD_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_STANDARD_MDNIE_5), DSI0_UI_STANDARD_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_STANDARD_MDNIE_6), DSI0_UI_STANDARD_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_UI_NATURAL_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_NATURAL_MDNIE_1), DSI0_UI_NATURAL_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_NATURAL_MDNIE_2), DSI0_UI_NATURAL_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_NATURAL_MDNIE_3), DSI0_UI_NATURAL_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_NATURAL_MDNIE_4), DSI0_UI_NATURAL_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_NATURAL_MDNIE_5), DSI0_UI_NATURAL_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_NATURAL_MDNIE_6), DSI0_UI_NATURAL_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_UI_AUTO_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_AUTO_MDNIE_1), DSI0_UI_AUTO_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_AUTO_MDNIE_2), DSI0_UI_AUTO_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_AUTO_MDNIE_3), DSI0_UI_AUTO_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_AUTO_MDNIE_4), DSI0_UI_AUTO_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_AUTO_MDNIE_5), DSI0_UI_AUTO_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_AUTO_MDNIE_6), DSI0_UI_AUTO_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_CAMERA_AUTO_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_CAMERA_AUTO_MDNIE_1), DSI0_CAMERA_AUTO_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_CAMERA_AUTO_MDNIE_2), DSI0_CAMERA_AUTO_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_CAMERA_AUTO_MDNIE_3), DSI0_CAMERA_AUTO_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_CAMERA_AUTO_MDNIE_4), DSI0_CAMERA_AUTO_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_CAMERA_AUTO_MDNIE_5), DSI0_CAMERA_AUTO_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_CAMERA_AUTO_MDNIE_6), DSI0_CAMERA_AUTO_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_GALLERY_AUTO_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_AUTO_MDNIE_1), DSI0_GALLERY_AUTO_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_AUTO_MDNIE_2), DSI0_GALLERY_AUTO_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_AUTO_MDNIE_3), DSI0_GALLERY_AUTO_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_AUTO_MDNIE_4), DSI0_GALLERY_AUTO_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_AUTO_MDNIE_5), DSI0_GALLERY_AUTO_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_AUTO_MDNIE_6), DSI0_GALLERY_AUTO_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_EBOOK_AUTO_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_AUTO_MDNIE_1), DSI0_EBOOK_AUTO_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_AUTO_MDNIE_2), DSI0_EBOOK_AUTO_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_AUTO_MDNIE_3), DSI0_EBOOK_AUTO_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_AUTO_MDNIE_4), DSI0_EBOOK_AUTO_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_AUTO_MDNIE_5), DSI0_EBOOK_AUTO_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_AUTO_MDNIE_6), DSI0_EBOOK_AUTO_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_EMAIL_AUTO_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EMAIL_AUTO_MDNIE_1), DSI0_EMAIL_AUTO_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EMAIL_AUTO_MDNIE_2), DSI0_EMAIL_AUTO_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EMAIL_AUTO_MDNIE_3), DSI0_EMAIL_AUTO_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EMAIL_AUTO_MDNIE_4), DSI0_EMAIL_AUTO_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EMAIL_AUTO_MDNIE_5), DSI0_EMAIL_AUTO_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EMAIL_AUTO_MDNIE_6), DSI0_EMAIL_AUTO_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_GAME_LOW_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_1), DSI0_BYPASS_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_2), DSI0_BYPASS_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_3), DSI0_BYPASS_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_4), DSI0_BYPASS_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_5), DSI0_BYPASS_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_6), DSI0_BYPASS_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_GAME_MID_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_1), DSI0_BYPASS_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_2), DSI0_BYPASS_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_3), DSI0_BYPASS_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_4), DSI0_BYPASS_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_5), DSI0_BYPASS_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_6), DSI0_BYPASS_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc DSI0_GAME_HIGH_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_1), DSI0_BYPASS_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_2), DSI0_BYPASS_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_3), DSI0_BYPASS_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_4), DSI0_BYPASS_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_5), DSI0_BYPASS_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_6), DSI0_BYPASS_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc *mdnie_tune_value_dsi0[MAX_APP_MODE][MAX_MODE][MAX_OUTDOOR_MODE] = {
	/*
		DYNAMIC_MODE
		STANDARD_MODE
		NATURAL_MODE
		MOVIE_MODE
		AUTO_MODE
		READING_MODE
	*/
		/* UI_APP */
	{
		{DSI0_UI_DYNAMIC_MDNIE,	NULL},
		{DSI0_UI_STANDARD_MDNIE,	NULL},
		{DSI0_UI_NATURAL_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_UI_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	/* VIDEO_APP*/
	{
		{DSI0_UI_DYNAMIC_MDNIE,	NULL},
		{DSI0_UI_STANDARD_MDNIE,	NULL},
		{DSI0_UI_NATURAL_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_GALLERY_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE, NULL},
	},
	/* VIDEO_WARM_APP*/
	{
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
	},
	/* VIDEO_COLD_APP*/
	{
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
	},
	/* CAMERA_APP*/
	{
		{DSI0_UI_DYNAMIC_MDNIE,	NULL},
		{DSI0_UI_STANDARD_MDNIE,	NULL},
		{DSI0_UI_NATURAL_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_CAMERA_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	/* NAVI_APP*/
	{
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
	},
	/* GALLERY_APP*/
	{
		{DSI0_UI_DYNAMIC_MDNIE,	NULL},
		{DSI0_UI_STANDARD_MDNIE,	NULL},
		{DSI0_UI_NATURAL_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_GALLERY_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	/* VT_APP*/
	{
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
	},
	/* BROWSER_APP*/
	{
		{DSI0_UI_DYNAMIC_MDNIE,	NULL},
		{DSI0_UI_STANDARD_MDNIE,	NULL},
		{DSI0_UI_NATURAL_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_CAMERA_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	/* eBOOK_APP*/
	{
		{DSI0_UI_DYNAMIC_MDNIE,	NULL},
		{DSI0_UI_STANDARD_MDNIE,	NULL},
		{DSI0_UI_NATURAL_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	// EMAIL_APP
	{
		{DSI0_EMAIL_AUTO_MDNIE,	NULL},
		{DSI0_EMAIL_AUTO_MDNIE,	NULL},
		{DSI0_EMAIL_AUTO_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_EMAIL_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	// GAME_LOW_APP
	{
		{DSI0_GAME_LOW_MDNIE,	NULL},
		{DSI0_GAME_LOW_MDNIE,	NULL},
		{DSI0_GAME_LOW_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_GAME_LOW_MDNIE,	NULL},
		{DSI0_GAME_LOW_MDNIE,	NULL},
	},
	// GAME_MID_APP
	{
		{DSI0_GAME_MID_MDNIE,	NULL},
		{DSI0_GAME_MID_MDNIE,	NULL},
		{DSI0_GAME_MID_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_GAME_MID_MDNIE,	NULL},
		{DSI0_GAME_MID_MDNIE,	NULL},
	},
	// GAME_HIGH_APP
	{
		{DSI0_GAME_HIGH_MDNIE,	NULL},
		{DSI0_GAME_HIGH_MDNIE,	NULL},
		{DSI0_GAME_HIGH_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_GAME_HIGH_MDNIE,	NULL},
		{DSI0_GAME_HIGH_MDNIE,	NULL},
	},
	// VIDEO_ENHANCER_APP
	{
		{DSI0_VIDEO_ENHANCER_D65_MDNIE,	NULL},
		{DSI0_VIDEO_ENHANCER_D65_MDNIE,	NULL},
		{DSI0_VIDEO_ENHANCER_D65_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_VIDEO_ENHANCER_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	// VIDEO_ENHANCER_THIRD_APP
	{
		{DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE,	NULL},
		{DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE,	NULL},
		{DSI0_VIDEO_ENHANCER_THIRD_D65_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_VIDEO_ENHANCER_THIRD_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	/* TDMB_APP*/
	{
		{DSI0_UI_DYNAMIC_MDNIE,	NULL},
		{DSI0_UI_STANDARD_MDNIE,	NULL},
		{DSI0_UI_NATURAL_MDNIE,	NULL},
		{NULL,	NULL},
		{DSI0_GALLERY_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
};

static struct dsi_cmd_desc DSI0_HMT_COLOR_TEMP_6500K_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_6500K_MDNIE_1), DSI0_HMT_COLOR_TEMP_6500K_MDNIE_1, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_6500K_MDNIE_2), DSI0_HMT_COLOR_TEMP_6500K_MDNIE_2, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_6500K_MDNIE_3), DSI0_HMT_COLOR_TEMP_6500K_MDNIE_3, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_6500K_MDNIE_4), DSI0_HMT_COLOR_TEMP_6500K_MDNIE_4, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_6500K_MDNIE_5), DSI0_HMT_COLOR_TEMP_6500K_MDNIE_5, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_6500K_MDNIE_6), DSI0_HMT_COLOR_TEMP_6500K_MDNIE_6, 0, NULL}, false, 0},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0},
};

static struct dsi_cmd_desc *hmt_color_temperature_tune_value_dsi0[HMT_COLOR_TEMP_MAX] = {
	/*
		HMT_COLOR_TEMP_3000K, // 3000K
		HMT_COLOR_TEMP_4000K, // 4000K
		HMT_COLOR_TEMP_5000K, // 5000K
		HMT_COLOR_TEMP_6500K, // 6500K
		HMT_COLOR_TEMP_7500K, // 7500K
	*/
	NULL,
	NULL,
	NULL,
	NULL,
	DSI0_HMT_COLOR_TEMP_6500K_MDNIE,
	NULL,
};

static struct dsi_cmd_desc *light_notification_tune_value_dsi0[LIGHT_NOTIFICATION_MAX] = {
	NULL,
	DSI0_LIGHT_NOTIFICATION_MDNIE,
};

static struct dsi_cmd_desc *hdr_tune_value_dsi0[HDR_MAX] = {
	NULL,
	DSI0_HDR_VIDEO_1_MDNIE,
	DSI0_HDR_VIDEO_2_MDNIE,
	DSI0_HDR_VIDEO_3_MDNIE,
	DSI0_HDR_VIDEO_4_MDNIE,
	DSI0_HDR_VIDEO_5_MDNIE,
};

#define DSI0_RGB_SENSOR_MDNIE_1_SIZE ARRAY_SIZE(DSI0_RGB_SENSOR_MDNIE_1)
#define DSI0_RGB_SENSOR_MDNIE_2_SIZE ARRAY_SIZE(DSI0_RGB_SENSOR_MDNIE_2)
#define DSI0_RGB_SENSOR_MDNIE_3_SIZE ARRAY_SIZE(DSI0_RGB_SENSOR_MDNIE_3)
#define DSI0_RGB_SENSOR_MDNIE_4_SIZE ARRAY_SIZE(DSI0_RGB_SENSOR_MDNIE_4)
#define DSI0_RGB_SENSOR_MDNIE_5_SIZE ARRAY_SIZE(DSI0_RGB_SENSOR_MDNIE_5)
#define DSI0_RGB_SENSOR_MDNIE_6_SIZE ARRAY_SIZE(DSI0_RGB_SENSOR_MDNIE_6)

#endif