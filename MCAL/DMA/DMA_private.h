#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

#define CHANNEL_EN_DIS_BIT  	 0

#define PRIORITY_BITS            13   
#define DESTINATION_BITS         11
#define SOURCE_BITS              9

#define     Memory_to_Memory_BIT	  14
#define     Circular_BIT			  5
#define     SOURCE_Increment_BIT	  6
#define     Destination_Increment_BIT 7
#define     DATA_TRANSFER_BIT			  4

#define TEIF_1_BIT      3
#define TEIF_2_BIT      7
#define TEIF_3_BIT      11
#define TEIF_4_BIT      15
#define TEIF_5_BIT      19
#define TEIF_6_BIT      23
#define TEIF_7_BIT      27


#define HTIF_1_BIT      2
#define HTIF_2_BIT      6
#define HTIF_3_BIT      10
#define HTIF_4_BIT      14
#define HTIF_5_BIT      18
#define HTIF_6_BIT      22
#define HTIF_7_BIT      26

#define TCIF_1_BIT      1
#define TCIF_2_BIT      5
#define TCIF_3_BIT      9
#define TCIF_4_BIT      13
#define TCIF_5_BIT      17
#define TCIF_6_BIT      21
#define TCIF_7_BIT      25


#endif
