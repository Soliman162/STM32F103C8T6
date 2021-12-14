#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

typedef enum{

    CHANNEL_1=0,  
    CHANNEL_2,   
    CHANNEL_3,   
    CHANNEL_4,   
    CHANNEL_5,   
    CHANNEL_6,   
    CHANNEL_7   

}CHANNEL_t;

typedef enum{

    Memory_to_Prephiral=0,
    Memory_to_Memory=1

}ME_2_ME_MODE;

typedef enum{

    Circular_Mode_Disabled=0,
    Circular_Mode_Enabled=1

}CIRC_MODE;


typedef enum{

    SOURCE_Increment_Mode_Disabled=0,
    SOURCE_Increment_Mode_Enabled=1

}SRCI_MODE;

typedef enum{

    Destination_Increment_Mode_Disabled=0,
    Destination_Increment_Mode_Enabled=1

}DESI_MODE;

typedef enum{

    LOW=0b00,
    MEDIUM=0b01,
    HIGH=0B10,
    VERY_HIGH=0B11

}CHANNEL_PRIORTY;

typedef enum{

    MEMORY_8_bit=0b00,
    MEMORY_16_bit=0b01,
    MEMORY_32_bit=0b10

}MEMORY_SIZE;

typedef enum{

  PERIPHERAL_8_bit=0b00,
  PERIPHERAL_16_bit=0b01,
  PERIPHERAL_32_bit=0b10

}PERIPHERAL_SIZE;

typedef enum{

    TRANSFER_ERROR_INTERRUPT=3,
    HALF_TRNSFER_INTERRUPT=2,
    TRANSFER_COMPLETE_INTERRUPT=1,
    GLOBAL_INTERRUPT=0

}INTERRUPT_t;

typedef enum{

    Read_from_Source=0,
    Read_from_Destination=1

}DATA_TRANSFER_DIRECTION;

typedef struct{

    CHANNEL_t               Channel_num;
    ME_2_ME_MODE            MEMORY_TO_MEMORY;
    CIRC_MODE               Circular_Mode;
    SRCI_MODE               SOURCE_Increment_Mode;
    DESI_MODE               Destination_Increment_Mode;
    CHANNEL_PRIORTY         Priorty;
    MEMORY_SIZE             Memory_Bit_num; 
    PERIPHERAL_SIZE         Peripheral_Bit_num;
    DATA_TRANSFER_DIRECTION TRANSFER_DIRECTION;

}DMA_CHANNEL_DEF_t;

ERROR_enumSTATE DMA_u8SetConfigration( const DMA_CHANNEL_DEF_t * Channel_strConfig );

ERROR_enumSTATE DMA_enumChannel_Enable(const  DMA_CHANNEL_DEF_t * Channel_strConfig);
ERROR_enumSTATE DMA_enumChannel_Disable( const DMA_CHANNEL_DEF_t * Channel_strConfig);

ERROR_enumSTATE DMA_enumInterrupt_Enable( const DMA_CHANNEL_DEF_t * Channel_strConfig,INTERRUPT_t Interrupt_enumType,void (*Call_BACK_func)(void) );
ERROR_enumSTATE DMA_enumSetAddress(const DMA_CHANNEL_DEF_t * Channel_strConfig ,u32 * Source_Add,u32 * Destin_Add, u16 Blocksize );

ERROR_enumSTATE DMA_enumClearFlag( const DMA_CHANNEL_DEF_t * Channel_strConfig ,INTERRUPT_t Flag_ID);
ERROR_enumSTATE DMA_enumGETFlag( const DMA_CHANNEL_DEF_t * Channel_strConfig, INTERRUPT_t Flag_ID, u8 * Flag_state);

#endif
