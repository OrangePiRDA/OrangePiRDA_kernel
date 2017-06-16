#ifndef _SP0718_CFG_H_
#define _SP0718_CFG_H_

#include "rda_sensor.h"
#include <linux/delay.h>

#ifdef BIT
#undef BIT
#endif
#define BIT	8

static struct sensor_reg exp_sp0718[][3] =
{
	{{0xfd,0x01,BIT,0},{0xdb,0xd0,BIT,0},{0xfd,0x00,BIT,0}},
	{{0xfd,0x01,BIT,0},{0xdb,0xe0,BIT,0},{0xfd,0x00,BIT,0}},
	{{0xfd,0x01,BIT,0},{0xdb,0xf0,BIT,0},{0xfd,0x00,BIT,0}},
	{{0xfd,0x01,BIT,0},{0xdb,0x00,BIT,0},{0xfd,0x00,BIT,0}},
	{{0xfd,0x01,BIT,0},{0xdb,0x10,BIT,0},{0xfd,0x00,BIT,0}},
	{{0xfd,0x01,BIT,0},{0xdb,0x20,BIT,0},{0xfd,0x00,BIT,0}},
	{{0xfd,0x01,BIT,0},{0xdb,0x30,BIT,0},{0xfd,0x00,BIT,0}},
};

static struct sensor_reg awb_sp0718[][6] =
{
	{{0xfd,0x02,BIT,0},{0xfd,0x00,BIT,0},{0xfd,0x00,BIT,0},{0xfd,0x00,BIT,0},{0xfd,0x00,BIT,0},{0xfd,0x00,BIT,0}},//OFF
	{{0xfd,0x02,BIT,0},{0x26,0xc8,BIT,0},{0x27,0xb6,BIT,0},{0xfd,0x01,BIT,0},{0x32,0x15,BIT,0},{0xfd,0x00,BIT,0}},//AUTO
	{{0xfd,0x01,BIT,0},{0x32,0x05,BIT,0},{0xfd,0x02,BIT,0},{0x26,0xaa,BIT,0},{0x27,0xce,BIT,0},{0xfd,0x00,BIT,0}},//INCANDESCENT
	{{0xfd,0x01,BIT,0},{0x32,0x05,BIT,0},{0xfd,0x02,BIT,0},{0x26,0x91,BIT,0},{0x27,0xc8,BIT,0},{0xfd,0x00,BIT,0}},//FLUORESCENT
	{{0xfd,0x01,BIT,0},{0x32,0x05,BIT,0},{0xfd,0x02,BIT,0},{0x26,0x75,BIT,0},{0x27,0xe2,BIT,0},{0xfd,0x00,BIT,0}},//TUNGSTEN
	{{0xfd,0x01,BIT,0},{0x32,0x05,BIT,0},{0xfd,0x02,BIT,0},{0x26,0xc8,BIT,0},{0x27,0x89,BIT,0},{0xfd,0x00,BIT,0}},//DAYLIGHT
	{{0xfd,0x01,BIT,0},{0x32,0x05,BIT,0},{0xfd,0x02,BIT,0},{0x26,0xdc,BIT,0},{0x27,0x75,BIT,0},{0xfd,0x00,BIT,0}},//CLOUD
};

// use this for 640x480 (VGA) capture
static struct sensor_reg vga_sp0718[] =
{
	//add
	{0xfd,0x01,BIT,0},
	{0x4a,0x00,BIT,0},
	{0x4b,0x01,BIT,0},
	{0x4c,0xe0,BIT,0},
	{0x4d,0x00,BIT,0},
	{0x4e,0x02,BIT,0},
	{0x4f,0x80,BIT,0},

	{0xfd,0x02,BIT,0},
	{0x0f,0x00,BIT,0},
	{0x30,0x00,BIT,0},
	{0xfd,0x00,BIT,0},
};

// use this for 320x240 (QVGA) capture
static struct sensor_reg qvga_sp0718[] =
{
	//add
	#if 1//subsample
	{0xfd,0x01,BIT,0},
	{0x4a,0x00,BIT,0},
	{0x4b,0x01,BIT,0},
	{0x4c,0xe0,BIT,0},
	{0x4d,0x00,BIT,0},
	{0x4e,0x02,BIT,0},
	{0x4f,0x80,BIT,0},

	{0xfd,0x02,BIT,0},
	{0x0f,0x01,BIT,0},
	{0x30,0x10,BIT,0},
	{0xfd,0x00,BIT,0},
#else//windows
	{0xfd,0x01,BIT,0},
	{0x4a,0x78,BIT,0},
	{0x4b,0x00,BIT,0},
	{0x4c,0xc0,BIT,0},
	{0x4d,0xa0,BIT,0},
	{0x4e,0x01,BIT,0},
	{0x4f,0x40,BIT,0},
	{0xfd,0x00,BIT,0},

#endif
};

// use this for 160x120 (QQVGA) capture
static struct sensor_reg qqvga_sp0718[] =
{
	//add
		#if 1//subsample
	{0xfd,0x01,BIT,0},
	{0x4a,0x00,BIT,0},
	{0x4b,0x01,BIT,0},
	{0x4c,0xe0,BIT,0},
	{0x4d,0x00,BIT,0},
	{0x4e,0x02,BIT,0},
	{0x4f,0x80,BIT,0},

	{0xfd,0x02,BIT,0},
	{0x0f,0x02,BIT,0},
	{0x30,0x20,BIT,0},
	{0xfd,0x00,BIT,0},
#else//windows
	{0xfd,0x01,BIT,0},
	{0x4a,0xb4,BIT,0},
	{0x4b,0x00,BIT,0},
	{0x4c,0x78,BIT,0},
	{0x4d,0xf0,BIT,0},
	{0x4e,0x00,BIT,0},
	{0x4f,0xa0,BIT,0},
	{0xfd,0x00,BIT,0},
#endif
};

// use this for 176x144 (QCIF) capture
static struct sensor_reg qcif_sp0718[] =
{
//add
		#if 0//subsample
	{0xfd,0x00,BIT,0},

#else//windows
	{0xfd,0x01,BIT,0},
	{0x4a,0xa8,BIT,0},
	{0x4b,0x00,BIT,0},
	{0x4c,0x90,BIT,0},
	{0x4d,0xe8,BIT,0},
	{0x4e,0x00,BIT,0},
	{0x4f,0xb0,BIT,0},
	{0xfd,0x00,BIT,0},
#endif

};

// use this for init sensor
static struct sensor_reg init_sp0718[] =
{
	{0xfd,0x00,BIT,0},
	{0x1C,0x00,BIT,0},
	{0x31,0x10,BIT,0},
	{0x27,0xb3,BIT,0},//2x gain
	{0x1b,0x17,BIT,0},
	{0x26,0xaa,BIT,0},
	{0x37,0x02,BIT,0},
	{0x28,0x8f,BIT,0},
	{0x1a,0x73,BIT,0},
	{0x1e,0x1b,BIT,0},
	{0x21,0x06,BIT,0},//blackout voltage
	{0x22,0x2a,BIT,0},//colbias
	{0x0f,0x3f,BIT,0},
	{0x10,0x3e,BIT,0},
	{0x11,0x00,BIT,0},
	{0x12,0x01,BIT,0},
	{0x13,0x3f,BIT,0},
	{0x14,0x04,BIT,0},
	{0x15,0x30,BIT,0},
	{0x16,0x31,BIT,0},
	{0x17,0x01,BIT,0},
	{0x69,0x31,BIT,0},
	{0x6a,0x2a,BIT,0},
	{0x6b,0x33,BIT,0},
	{0x6c,0x1a,BIT,0},
	{0x6d,0x32,BIT,0},
	{0x6e,0x28,BIT,0},
	{0x6f,0x29,BIT,0},
	{0x70,0x34,BIT,0},
	{0x71,0x18,BIT,0},
	{0x36,0x00,BIT,0},//02 delete badframe
	{0xfd,0x01,BIT,0},
	{0x5d,0x51,BIT,0},//position
	{0xf2,0x19,BIT,0},

	//Blacklevel
	{0x1f,0x10,BIT,0},
	{0x20,0x1f,BIT,0},
	 //pregain
	{0xfd,0x02,BIT,0},
	{0x00,0x88,BIT,0},
	{0x01,0x88,BIT,0},

	//ae setting 26M 50HZ 8-17fps
	{0xfd,0x00,BIT,0},
	{0x03,0x02,BIT,0},
	{0x04,0x0a,BIT,0},
	{0x06,0x00,BIT,0},
	{0x09,0x02,BIT,0},
	{0x0a,0x84,BIT,0},
	{0xfd,0x01,BIT,0},
	{0xef,0x57,BIT,0},
	{0xf0,0x00,BIT,0},
	{0x02,0x0c,BIT,0},
	{0x03,0x01,BIT,0},
	{0x06,0x51,BIT,0},
	{0x07,0x00,BIT,0},
	{0x08,0x01,BIT,0},
	{0x09,0x00,BIT,0},
	//Status
	{0xfd,0x02,BIT,0},
	{0xbe,0x14,BIT,0},
	{0xbf,0x04,BIT,0},
	{0xd0,0x14,BIT,0},
	{0xd1,0x04,BIT,0},
	{0xfd,0x01,BIT,0},
	{0x5b,0x04,BIT,0},
	{0x5c,0x14,BIT,0},

	//rpc
	{0xfd,0x01,BIT,0},
	{0xe0,0x40,BIT,0},//rpc_1base_max
	{0xe1,0x30,BIT,0},//rpc_2base_max
	{0xe2,0x2e,BIT,0},//rpc_3base_max
	{0xe3,0x2a,BIT,0},//rpc_4base_max
	{0xe4,0x2a,BIT,0},//rpc_5base_max
	{0xe5,0x28,BIT,0},//rpc_6base_max
	{0xe6,0x28,BIT,0},//rpc_7base_max
	{0xe7,0x26,BIT,0},//1e//rpc_8base_max
	{0xe8,0x26,BIT,0},//1e//rpc_9base_max
	{0xe9,0x26,BIT,0},//1e//rpc_10base_max
	{0xea,0x26,BIT,0},//1d//rpc_11base_max
	{0xf3,0x26,BIT,0},//1d//rpc_12base_max
	{0xf4,0x26,BIT,0},//1d//rpc_13base_max
	//ae gain &status
	{0xfd,0x01,BIT,0},
	{0x04,0xe0,BIT,0},//rpc_max_indr
	{0x05,0x26,BIT,0},//1e//rpc_min_indr
	{0x0a,0xa0,BIT,0},//rpc_max_outdr
	{0x0b,0x26,BIT,0},//rpc_min_outdr
	{0x5a,0x40,BIT,0},//dp rpc
	{0xfd,0x02,BIT,0},
	{0xbc,0xa0,BIT,0},//rpc_heq_low
	{0xbd,0x80,BIT,0},//rpc_heq_dummy
	{0xb8,0x80,BIT,0},//mean_normal_dummy
	{0xb9,0x90,BIT,0},//mean_dummy_normal

	//ae target
	{0xfd,0x01,BIT,0},
	{0xeb,0x78,BIT,0},
	{0xec,0x6c,BIT,0},
	{0xed,0x0a,BIT,0},
	{0xee,0x10,BIT,0},

	//lsc
	{0xfd,0x01,BIT,0},
	{0x26,0x30,BIT,0},
	{0x27,0x2c,BIT,0},
	{0x28,0x07,BIT,0},
	{0x29,0x08,BIT,0},
	{0x2a,0x40,BIT,0},
	{0x2b,0x03,BIT,0},
	{0x2c,0x00,BIT,0},
	{0x2d,0x00,BIT,0},

	{0xa1,0x24,BIT,0},
	{0xa2,0x27,BIT,0},
	{0xa3,0x27,BIT,0},
	{0xa4,0x2b,BIT,0},
	{0xa5,0x1c,BIT,0},
	{0xa6,0x1a,BIT,0},
	{0xa7,0x1a,BIT,0},
	{0xa8,0x1a,BIT,0},
	{0xa9,0x18,BIT,0},
	{0xaa,0x1c,BIT,0},
	{0xab,0x17,BIT,0},
	{0xac,0x17,BIT,0},
	{0xad,0x08,BIT,0},
	{0xae,0x08,BIT,0},
	{0xaf,0x08,BIT,0},
	{0xb0,0x00,BIT,0},
	{0xb1,0x00,BIT,0},
	{0xb2,0x00,BIT,0},
	{0xb3,0x00,BIT,0},
	{0xb4,0x00,BIT,0},
	{0xb5,0x02,BIT,0},
	{0xb6,0x06,BIT,0},
	{0xb7,0x00,BIT,0},
	{0xb8,0x00,BIT,0},


	//DP
	{0xfd,0x01,BIT,0},
	{0x48,0x09,BIT,0},
	{0x49,0x99,BIT,0},

	//awb
	{0xfd,0x01,BIT,0},
	{0x32,0x05,BIT,0},
	{0xfd,0x00,BIT,0},
	{0xe7,0x03,BIT,0},
	{0xfd,0x02,BIT,0},
	{0x26,0xc8,BIT,0},
	{0x27,0xb6,BIT,0},
	{0xfd,0x00,BIT,0},
	{0xe7,0x00,BIT,0},
	{0xfd,0x02,BIT,0},
	{0x1b,0x80,BIT,0},
	{0x1a,0x80,BIT,0},
	{0x18,0x26,BIT,0},
	{0x19,0x28,BIT,0},
	{0xfd,0x02,BIT,0},
	{0x2a,0x00,BIT,0},
	{0x2b,0x08,BIT,0},
	{0x28,0xef,BIT,0},
	{0x29,0x20,BIT,0},

	//d65
	{0x66,0x42,BIT,0},
	{0x67,0x62,BIT,0},
	{0x68,0xee,BIT,0},
	{0x69,0x18,BIT,0},
	{0x6a,0xa6,BIT,0},
	//indoor 91
	{0x7c,0x3b,BIT,0},
	{0x7d,0x5b,BIT,0},
	{0x7e,0x15,BIT,0},
	{0x7f,0x39,BIT,0},
	{0x80,0xaa,BIT,0},
	//cwf   92
	{0x70,0x3e,BIT,0},
	{0x71,0x59,BIT,0},
	{0x72,0x31,BIT,0},
	{0x73,0x4f,BIT,0},
	{0x74,0xaa,BIT,0},
	//tl84  93
	{0x6b,0x1b,BIT,0},
	{0x6c,0x3a,BIT,0},
	{0x6d,0x3e,BIT,0},
	{0x6e,0x59,BIT,0},
	{0x6f,0xaa,BIT,0},
	//f    94
	{0x61,0xea,BIT,0},
	{0x62,0x03,BIT,0},
	{0x63,0x6a,BIT,0},
	{0x64,0x8a,BIT,0},
	{0x65,0x6a,BIT,0},

	{0x75,0x80,BIT,0},
	{0x76,0x20,BIT,0},
	{0x77,0x00,BIT,0},
	{0x24,0x25,BIT,0},

	 //������ڵ�ƫ�����������ʹ��//���������ƫ
	{0x20,0xd8,BIT,0},
	{0x21,0xa3,BIT,0},//ƫ���նȻ��е�ƫ
	{0x22,0xd0,BIT,0},
	{0x23,0x86,BIT,0},

	//outdoor r\b range
	{0x78,0xc3,BIT,0},
	{0x79,0xba,BIT,0},
	{0x7a,0xa6,BIT,0},
	{0x7b,0x99,BIT,0},


	//skin
	{0x08,0x15,BIT,0},
	{0x09,0x04,BIT,0},
	{0x0a,0x20,BIT,0},
	{0x0b,0x12,BIT,0},
	{0x0c,0x27,BIT,0},
	{0x0d,0x06,BIT,0},
	{0x0e,0x63,BIT,0},

	 //wt th
	{0x3b,0x10,BIT,0},
	//gw
	{0x31,0x60,BIT,0},
	{0x32,0x60,BIT,0},
	{0x33,0xc0,BIT,0},
	{0x35,0x6f,BIT,0},

	// sharp
	{0xfd,0x02,BIT,0},
	{0xde,0x0f,BIT,0},
	{0xd2,0x02,BIT,0},//���ƺڰױߣ�0-�ߴ֣�f-��ϸ
	{0xd3,0x06,BIT,0},
	{0xd4,0x06,BIT,0},
	{0xd5,0x06,BIT,0},
	{0xd7,0x20,BIT,0},//2x���������ж�������ֵ
	{0xd8,0x30,BIT,0},//24//1A//4x
	{0xd9,0x38,BIT,0},//28//8x
	{0xda,0x38,BIT,0},//16x
	{0xdb,0x08,BIT,0},//
	{0xe8,0x58,BIT,0},//����ǿ��
	{0xe9,0x48,BIT,0},
	{0xea,0x30,BIT,0},
	{0xeb,0x20,BIT,0},
	{0xec,0x48,BIT,0},
	{0xed,0x48,BIT,0},
	{0xee,0x30,BIT,0},
	{0xef,0x20,BIT,0},
	//ƽ̹����������
	{0xf3,0x50,BIT,0},
	{0xf4,0x10,BIT,0},
	{0xf5,0x10,BIT,0},
	{0xf6,0x10,BIT,0},
	//dns
	{0xfd,0x01,BIT,0},
	{0x64,0x44,BIT,0},//�ط����Եƽ������  //0-��ǿ��8-����
	{0x65,0x22,BIT,0},
	{0x6d,0x04,BIT,0},//8//ǿƽ����ƽ̹������ƽ����ֵ
	{0x6e,0x06,BIT,0},//8
	{0x6f,0x10,BIT,0},
	{0x70,0x10,BIT,0},
	{0x71,0x08,BIT,0},//0d//��ƽ������ƽ̹������ƽ����ֵ
	{0x72,0x12,BIT,0},//1b
	{0x73,0x1c,BIT,0},//20
	{0x74,0x24,BIT,0},
	{0x75,0x44,BIT,0},//[7:4]ƽ̹����ǿ�ȣ�[3:0]��ƽ̹����ǿ�ȣ�0-��ǿ��8-������
	{0x76,0x02,BIT,0},//46
	{0x77,0x02,BIT,0},//33
	{0x78,0x02,BIT,0},
	{0x81,0x10,BIT,0},//18//2x//���������ж�������ֵ�����������ǿƽ���������������ƽ����
	{0x82,0x20,BIT,0},//30//4x
	{0x83,0x30,BIT,0},//40//8x
	{0x84,0x48,BIT,0},//50//16x
	{0x85,0x0c,BIT,0},//12/8+reg0x81 �ڶ���ֵ����ƽ̹�ͷ�ƽ̹����������
	{0xfd,0x02,BIT,0},
	{0xdc,0x0f,BIT,0},

	//gamma
	{0xfd,0x01,BIT,0},
	{0x8b,0x00,BIT,0},
	{0x8c,0x0a,BIT,0},
	{0x8d,0x16,BIT,0},
	{0x8e,0x1f,BIT,0},
	{0x8f,0x2a,BIT,0},
	{0x90,0x3c,BIT,0},
	{0x91,0x4e,BIT,0},
	{0x92,0x5f,BIT,0},
	{0x93,0x6c,BIT,0},
	{0x94,0x82,BIT,0},
	{0x95,0x94,BIT,0},
	{0x96,0xa6,BIT,0},
	{0x97,0xb2,BIT,0},
	{0x98,0xbf,BIT,0},
	{0x99,0xc9,BIT,0},
	{0x9a,0xd1,BIT,0},
	{0x9b,0xd8,BIT,0},
	{0x9c,0xe0,BIT,0},
	{0x9d,0xe8,BIT,0},
	{0x9e,0xef,BIT,0},
	{0x9f,0xf8,BIT,0},
	{0xa0,0xff,BIT,0},
	//CCM
	{0xfd,0x02,BIT,0},
	{0x15,0xd0,BIT,0},//b>th
	{0x16,0x95,BIT,0},//r<th
	//gc��ͷ������ƫ��
	//!F
	{0xa0,0x80,BIT,0},
	{0xa1,0x00,BIT,0},
	{0xa2,0x00,BIT,0},
	{0xa3,0x00,BIT,0},
	{0xa4,0x8c,BIT,0},
	{0xa5,0xf4,BIT,0},
	{0xa6,0x0c,BIT,0},
	{0xa7,0xf4,BIT,0},
	{0xa8,0x80,BIT,0},
	{0xa9,0x00,BIT,0},
	{0xaa,0x30,BIT,0},
	{0xab,0x0c,BIT,0},
	 //F
	{0xac,0x8c,BIT,0},
	{0xad,0xf4,BIT,0},
	{0xae,0x00,BIT,0},
	{0xaf,0xed,BIT,0},
	{0xb0,0x8c,BIT,0},
	{0xb1,0x06,BIT,0},
	{0xb2,0xf4,BIT,0},
	{0xb3,0xf4,BIT,0},
	{0xb4,0x99,BIT,0},
	{0xb5,0x0c,BIT,0},
	{0xb6,0x03,BIT,0},
	{0xb7,0x0f,BIT,0},

	//sat u
	{0xfd,0x01,BIT,0},
	{0xd3,0x9c,BIT,0},
	{0xd4,0x98,BIT,0},
	{0xd5,0x8c,BIT,0},
	{0xd6,0x84,BIT,0},
	//sat v
	{0xd7,0x9c,BIT,0},
	{0xd8,0x98,BIT,0},
	{0xd9,0x8c,BIT,0},
	{0xda,0x84,BIT,0},
	//auto_sat
	{0xdd,0x30,BIT,0},
	{0xde,0x10,BIT,0},
	{0xd2,0x01,BIT,0},//autosa_en
	{0xdf,0xff,BIT,0},//y_mean_th

	//uv_th
	{0xfd,0x01,BIT,0},
	{0xc2,0xaa,BIT,0},
	{0xc3,0xaa,BIT,0},
	{0xc4,0x66,BIT,0},
	{0xc5,0x66,BIT,0},

	//heq
	{0xfd,0x01,BIT,0},
	{0x0f,0xff,BIT,0},
	{0x10,0x00,BIT,0},
	{0x11,0x00,BIT,0},
	{0x12,0x00,BIT,0},
	{0x13,0x00,BIT,0},
	{0x14,0x20,BIT,0},
	{0x15,0x18,BIT,0},
	{0x16,0x10,BIT,0},
	{0x17,0x00,BIT,0},

	{0xfd,0x01,BIT,0},
	{0xcd,0x20,BIT,0},
	{0xce,0x1f,BIT,0},
	{0xcf,0x20,BIT,0},
	{0xd0,0x55,BIT,0},

	 //auto
	{0xfd,0x01,BIT,0},
	{0xfb,0x33,BIT,0},
	{0x32,0x15,BIT,0},
	{0x33,0xff,BIT,0},
	{0x34,0xe7,BIT,0},
	{0x35,0x42,BIT,0},//output YUYV
  {0xfd,0x00,BIT,0},

	{0xfd,0x02,BIT,0},
	{0x0f,0x00,BIT,0},
	{0x30,0x00,BIT,0},
	{0xfd,0x00,BIT,0},
};

static struct sensor_reg_list sp0718_init = {
	.size = ARRAY_ROW(init_sp0718),
	.val = init_sp0718
};

static struct sensor_reg_list sp0718_vga = {
	.size = ARRAY_ROW(vga_sp0718),
	.val = vga_sp0718
};
static struct sensor_reg_list sp0718_qvga = {
	.size = ARRAY_ROW(qvga_sp0718),
	.val = qvga_sp0718
};
static struct sensor_reg_list sp0718_qcif = {
	.size = ARRAY_ROW(qcif_sp0718),
	.val = qcif_sp0718
};
static struct sensor_reg_list sp0718_qqvga = {
	.size = ARRAY_ROW(qqvga_sp0718),
	.val = qqvga_sp0718
};
static struct sensor_win_size sp0718_win_size[] = {
	WIN_SIZE("VGA", W_VGA, H_VGA, &sp0718_vga),
	WIN_SIZE("QVGA", W_QVGA, H_QVGA, &sp0718_qvga),
	WIN_SIZE("QCIF", W_QCIF, H_QCIF, &sp0718_qcif),
	WIN_SIZE("QQVGA", W_QQVGA, H_QQVGA, &sp0718_qqvga),
};

static struct sensor_win_cfg sp0718_win_cfg = {
	.num = ARRAY_ROW(sp0718_win_size),
	.win_size = sp0718_win_size
};

static struct sensor_csi_cfg sp0718_csi_cfg = {
	.csi_en = false,
	.d_term_en = 0,
	.c_term_en = 0,
	.dhs_settle = 0,
	.chs_settle = 0,
};

static struct sensor_info sp0718_info = {
	.name		= "sp0718",
	.chip_id	= 0x71,
	.mclk		= 26,
	.i2c_addr	= 0x21,
	.exp_def	= 0,
	.awb_def	= 1,
	.rst_act_h	= false,
	.pdn_act_h	= true,
	.init		= &sp0718_init,
	.win_cfg	= &sp0718_win_cfg,
	.csi_cfg	= &sp0718_csi_cfg
};

extern void sensor_power_down(bool high, bool acth, int id);
extern void sensor_reset(bool rst, bool acth);
extern void sensor_clock(bool out, int mclk);
extern void sensor_read(const u16 addr, u8 *data, u8 bits);
extern void sensor_write(const u16 addr, const u8 data, u8 bits);
extern void sensor_write_group(struct sensor_reg* reg, u32 size);

static u32 sp0718_power(int id, int mclk, bool rst_h, bool pdn_h)
{
	/* set state to power off */
	sensor_power_down(true, pdn_h, 0);
	mdelay(10);
	sensor_power_down(true, pdn_h, 1);
	mdelay(20);
	sensor_reset(true, rst_h);
	mdelay(10);
	sensor_clock(false, mclk);
	mdelay(5);

	/* power on sequence */
	sensor_clock(true, mclk);
	mdelay(10);
	sensor_power_down(false, pdn_h, id);
	mdelay(10);
	sensor_reset(false, rst_h);
	mdelay(10);

	return 0;
}

static u32 sp0718_get_chipid(void)
{
	u32 chip_id = 0;

	sensor_write(0xfd, 0x00, BIT);
	mdelay(10);
	sensor_read(0x02, &chip_id, BIT);
	rda_dbg_camera("%s: chip_id = %x\n", __func__,chip_id);

	return chip_id;
}

static u32 sp0718_get_lum(void)
{
	u8 val = 0;
	u32 ret = 0;

	sensor_write(0xfd, 0x01, BIT);
	sensor_read(0xf1, &val, BIT);
	sensor_write(0xfd, 0x00, BIT);

	if (val < 0x70)
		ret = 1;

	return ret;
}



#define SP0718_FLIP_BASE	0x31
#define SP0718_H_FLIP_BIT	0
#define SP0718_V_FLIP_BIT		1
static void sp0718_set_flip(int hv, int flip)
{
	u8 tmp = 0;

	sensor_read(SP0718_FLIP_BASE, &tmp, BIT);

	if (hv) {
		if (flip)
			tmp |= (0x1 << SP0718_V_FLIP_BIT);
		else
			tmp &= ~(0x1 << SP0718_V_FLIP_BIT);
	}
	else {
		if (flip)
			tmp |= (0x1 << SP0718_H_FLIP_BIT);
		else
			tmp &= ~(0x1 << SP0718_H_FLIP_BIT);
	}

	sensor_write(SP0718_FLIP_BASE, tmp, BIT);
}

#define SP0718_EXP_ROW		ARRAY_ROW(exp_sp0718)
#define SP0718_EXP_COL		ARRAY_COL(exp_sp0718)
static void sp0718_set_exp(int exp)
{
	int key = exp + (SP0718_EXP_ROW / 2);
	if ((key < 0) || (key > (SP0718_EXP_ROW - 1)))
		return;

	sensor_write_group(exp_sp0718[key], SP0718_EXP_COL);
}

#define SP0718_AWB_ROW		ARRAY_ROW(awb_sp0718)
#define SP0718_AWB_COL		ARRAY_COL(awb_sp0718)
static void sp0718_set_awb(int awb)
{
	if ((awb < 0) || (awb > (SP0718_AWB_ROW - 1)))
		return;

	sensor_write_group(awb_sp0718[awb], SP0718_AWB_COL);
}

static struct sensor_ops sp0718_ops = {
	.power		= sp0718_power,
	.get_chipid	= sp0718_get_chipid,
	.get_lum	= sp0718_get_lum,
	.set_flip	= sp0718_set_flip,
	.set_exp	= sp0718_set_exp,
	.set_awb	= sp0718_set_awb,
	.start		= NULL,
	.stop		= NULL
};

struct sensor_dev sp0718_dev = {
	.info	= &sp0718_info,
	.ops	= &sp0718_ops,
};

#undef BIT
#endif