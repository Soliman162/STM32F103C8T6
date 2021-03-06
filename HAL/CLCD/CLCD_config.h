#ifndef CLCD_CONFIG_H
#define CLCD_CONFIG_H


u8 Arr_u8ExtraChar []={

		0x00,0x00,0x01,0x01,0x07,0x00,0x00,0x00,  //char4
		0x00,0x00,0x00,0x00,0x1F,0x0A,0x0E,0x00,  //char3
		0x00,0x04,0x0A,0x01,0x1F,0x00,0x00,0x00,  //char2
		0x07,0x04,0x1F,0x00,0x04,0x04,0x04,0x04,  //char1
		0x00,0x00,0x00, 0x00,0x00,0x00,0x00,0x00  //char0
};


#define CLCD_DATA_PORT         GPIOA_PORT
#define CLCD_CONTROL_PORT      GPIOC_PORT

#define CLCD_CONTROL_PIN_RS	    PIN_13
#define CLCD_CONTROL_PIN_RW     PIN_14
#define CLCD_CONTROL_PIN_EN	    PIN_15

#endif