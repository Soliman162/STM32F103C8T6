#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include "..\..\LIB\STM32F103C8.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"

static void (*DMA1_ISR[7][3])(void) = {NULL};

ERROR_enumSTATE DMA_u8SetConfigration(const DMA_CHANNEL_DEF_t * Channel_strConfig )
{
	ERROR_enumSTATE LOC_enumError_State = STD_TYPES_OK;
	if( Channel_strConfig != NULL )
	{
		u8 LOC_u8Channel_num = Channel_strConfig->Channel_num;
		u8 LOC_u8Circular_Mode = Channel_strConfig->Circular_Mode;
		u8 LOC_u8MEMORY_TO_MEMORY = Channel_strConfig->MEMORY_TO_MEMORY;
		u8 LOC_u8SOURCE_Increment_Mode = Channel_strConfig->SOURCE_Increment_Mode;
		u8 LOC_u8Destination_Increment_Mode = Channel_strConfig->Destination_Increment_Mode;
		u8 LOC_u8TRANSFER_DIRECTION = Channel_strConfig->TRANSFER_DIRECTION;

		u8 LOC_u8Priorty  = Channel_strConfig->Priorty ;
		u8 LOC_u8Peripheral_Bit_num = Channel_strConfig->Peripheral_Bit_num;
		u8 LOC_u8Memory_Bit_num = Channel_strConfig->Memory_Bit_num;

		DMA1->CHANNEL[LOC_u8Channel_num].CCR &=0;

		DMA1->CHANNEL[ LOC_u8Channel_num ].CCR |= (LOC_u8Circular_Mode << Circular_BIT);
		DMA1->CHANNEL[ LOC_u8Channel_num ].CCR |= (LOC_u8MEMORY_TO_MEMORY << Memory_to_Memory_BIT);
		DMA1->CHANNEL[ LOC_u8Channel_num ].CCR |= (LOC_u8SOURCE_Increment_Mode << SOURCE_Increment_BIT);
		DMA1->CHANNEL[ LOC_u8Channel_num ].CCR |= (LOC_u8Destination_Increment_Mode << Destination_Increment_BIT);
		DMA1->CHANNEL[ LOC_u8Channel_num ].CCR |= (LOC_u8TRANSFER_DIRECTION << DATA_TRANSFER_BIT);

		DMA1->CHANNEL[ LOC_u8Channel_num ].CCR |= ( LOC_u8Priorty << PRIORITY_BITS );
		DMA1->CHANNEL[ LOC_u8Channel_num ].CCR |= ( LOC_u8Peripheral_Bit_num << SOURCE_BITS  );
		DMA1->CHANNEL[ LOC_u8Channel_num ].CCR |= ( LOC_u8Memory_Bit_num << DESTINATION_BITS );

	}else
	{
		LOC_enumError_State =STD_TYPES_NOK;
	}
	return LOC_enumError_State;
}

ERROR_enumSTATE DMA_enumChannel_Enable(const DMA_CHANNEL_DEF_t * Channel_strConfig )
{
	ERROR_enumSTATE LOC_enumError_State = STD_TYPES_OK;
	if( Channel_strConfig != NULL )
	{
		SET_BIT( DMA1->CHANNEL[ Channel_strConfig->Channel_num ].CCR , CHANNEL_EN_DIS_BIT );
	}
	else
	{
		LOC_enumError_State = STD_TYPES_NOK;
	}

	return LOC_enumError_State;
}
ERROR_enumSTATE DMA_enumChannel_Disable(const DMA_CHANNEL_DEF_t * Channel_strConfig)
{
	ERROR_enumSTATE LOC_enumError_State = STD_TYPES_OK;
	if( Channel_strConfig != NULL )
	{
		CLR_BIT( DMA1->CHANNEL[ Channel_strConfig->Channel_num ].CCR , CHANNEL_EN_DIS_BIT );
	}
	else
	{
		LOC_enumError_State = STD_TYPES_NOK;
	}

	return LOC_enumError_State;
}

ERROR_enumSTATE DMA_enumInterrupt_Enable( const DMA_CHANNEL_DEF_t * Channel_strConfig, INTERRUPT_t Interrupt_enumType, void (*Call_BACK_func)(void) )
{
	ERROR_enumSTATE LOC_enumError_State = STD_TYPES_OK;
	if( Channel_strConfig != NULL )
	{
		if( Interrupt_enumType >= TRANSFER_COMPLETE_INTERRUPT && Interrupt_enumType <= TRANSFER_ERROR_INTERRUPT )
		{
			SET_BIT( DMA1->CHANNEL[ Channel_strConfig->Channel_num ].CCR , Interrupt_enumType );
			DMA1_ISR[ Channel_strConfig->Channel_num ][ Interrupt_enumType-1 ] = Call_BACK_func;
		}else
		{
			LOC_enumError_State = STD_TYPES_NOK;
		}

	}else
	{
		LOC_enumError_State = STD_TYPES_NOK;
	}

	return LOC_enumError_State;
}
ERROR_enumSTATE DMA_enumSetAddress(const DMA_CHANNEL_DEF_t * Channel_strConfig ,u32 * Source_Add,u32 * Destin_Add, u16 Blocksize )
{
	ERROR_enumSTATE LOC_enumError_State = STD_TYPES_OK;
	if( (Channel_strConfig != NULL) && (Source_Add != NULL) && (Destin_Add !=NULL) )
	{
		CLR_BIT( DMA1->CHANNEL[ Channel_strConfig->Channel_num ].CCR , CHANNEL_EN_DIS_BIT );
		DMA1->CHANNEL[Channel_strConfig->Channel_num].CNDTR = Blocksize  ;
		DMA1->CHANNEL[Channel_strConfig->Channel_num].CPAR  = Source_Add ;
		DMA1->CHANNEL[Channel_strConfig->Channel_num].CMAR  = Destin_Add ;

	}else
	{
		LOC_enumError_State = STD_TYPES_NOK;
	}
	return LOC_enumError_State;
}

ERROR_enumSTATE DMA_enumClearFlag(const DMA_CHANNEL_DEF_t * Channel_strConfig ,INTERRUPT_t Flag_ID )
{
	ERROR_enumSTATE LOC_enumError_State = STD_TYPES_OK;
	if( Channel_strConfig != NULL )
	{
		u8 Flag_u8BIT = (Channel_strConfig->Channel_num*4) + Flag_ID ;
		SET_BIT( DMA1->IFCR, Flag_u8BIT );
	}else
	{
		LOC_enumError_State = STD_TYPES_NOK;
	}
	return LOC_enumError_State;
}    
ERROR_enumSTATE DMA_enumGETFlag(const DMA_CHANNEL_DEF_t * Channel_strConfig, INTERRUPT_t Flag_ID, u8 * Flag_state)
{
	ERROR_enumSTATE LOC_enumError_State = STD_TYPES_OK;
	if( Channel_strConfig != NULL )
	{
		u8 Flag_u8BIT = (Channel_strConfig->Channel_num*4) + Flag_ID ;
		*Flag_state = GET_BIT( DMA1->ISR , Flag_u8BIT );

	}else
	{
		LOC_enumError_State = STD_TYPES_NOK;
	}
	return LOC_enumError_State;
}


/*TRANSFER_ERROR_INTERRUPT=3,
HALF_TRNSFER_INTERRUPT=2,
TRANSFER_COMPLETE_INTERRUPT=1,*/

void DMA1_Channel1_IRQHandler(void)
{
	if( DMA1_ISR[CHANNEL_1] != NULL )
	{

		if( GET_BIT( DMA1->ISR ,TEIF_1_BIT) == 1 )
		{
			DMA1_ISR[CHANNEL_1][TRANSFER_ERROR_INTERRUPT-1]();
		}
		else if( GET_BIT( DMA1->ISR ,HTIF_1_BIT) )
		{
			DMA1_ISR[CHANNEL_1][HALF_TRNSFER_INTERRUPT-1]();
		}
		else if( GET_BIT( DMA1->ISR ,TCIF_1_BIT) == 1 )
		{
			DMA1_ISR[CHANNEL_1][TRANSFER_COMPLETE_INTERRUPT-1]();
		}
	}
}
void DMA1_Channel2_IRQHandler(void)
{
	if( GET_BIT( DMA1->ISR ,TEIF_2_BIT) )
	{
		DMA1_ISR[CHANNEL_2][TRANSFER_ERROR_INTERRUPT-1]();
	}
	else if( GET_BIT( DMA1->ISR ,HTIF_2_BIT) )
	{
		DMA1_ISR[CHANNEL_2][HALF_TRNSFER_INTERRUPT-1]();
	}
	else if( GET_BIT( DMA1->ISR ,TCIF_2_BIT) )
	{
		DMA1_ISR[CHANNEL_2][TRANSFER_COMPLETE_INTERRUPT-1]();
	}
}
void DMA1_Channel3_IRQHandler(void)
{
	if( GET_BIT( DMA1->ISR ,TEIF_3_BIT) )
	{
		DMA1_ISR[CHANNEL_3][TRANSFER_ERROR_INTERRUPT-1]();
	}
	else if( GET_BIT( DMA1->ISR ,HTIF_3_BIT) )
	{
		DMA1_ISR[CHANNEL_3][HALF_TRNSFER_INTERRUPT-1]();
	}
	else if( GET_BIT( DMA1->ISR ,TCIF_3_BIT) )
	{
		DMA1_ISR[CHANNEL_3][TRANSFER_COMPLETE_INTERRUPT-1]();
	}
}
void DMA1_Channel4_IRQHandler(void)
{
	if( GET_BIT( DMA1->ISR ,TEIF_4_BIT) )
	{
		DMA1_ISR[CHANNEL_4][TRANSFER_ERROR_INTERRUPT-1]();
	}
	else if( GET_BIT( DMA1->ISR ,HTIF_4_BIT) )
	{
		DMA1_ISR[CHANNEL_4][HALF_TRNSFER_INTERRUPT-1]();
	}
	else if( GET_BIT( DMA1->ISR ,TCIF_4_BIT) )
	{
		DMA1_ISR[CHANNEL_4][TRANSFER_COMPLETE_INTERRUPT-1]();
	}
}
void DMA1_Channel5_IRQHandler(void)
{
	if( GET_BIT( DMA1->ISR ,TEIF_5_BIT) )
	{
		DMA1_ISR[CHANNEL_5][TRANSFER_ERROR_INTERRUPT-1]();
	}
	else if( GET_BIT( DMA1->ISR ,HTIF_5_BIT) )
	{
		DMA1_ISR[CHANNEL_5][HALF_TRNSFER_INTERRUPT-1]();
	}
	else if( GET_BIT( DMA1->ISR ,TCIF_5_BIT) )
	{
		DMA1_ISR[CHANNEL_5][TRANSFER_COMPLETE_INTERRUPT-1]();
	}
}
void DMA1_Channel6_IRQHandler(void)
{
	if( GET_BIT( DMA1->ISR ,TEIF_6_BIT) )
	{
		DMA1_ISR[CHANNEL_6][TRANSFER_ERROR_INTERRUPT-1]();
	}
	else if( GET_BIT( DMA1->ISR ,HTIF_6_BIT) )
	{
		DMA1_ISR[CHANNEL_6][HALF_TRNSFER_INTERRUPT-1]();
	}
	else if( GET_BIT( DMA1->ISR ,TCIF_6_BIT) )
	{
		DMA1_ISR[CHANNEL_6][TRANSFER_COMPLETE_INTERRUPT-1]();
	}
}
void DMA1_Channel7_IRQHandler(void)
{
	if( GET_BIT( DMA1->ISR ,TEIF_7_BIT) )
	{
		DMA1_ISR[CHANNEL_7][TRANSFER_ERROR_INTERRUPT-1]();
	}
	else if( GET_BIT( DMA1->ISR ,HTIF_7_BIT) )
	{
		DMA1_ISR[CHANNEL_7][HALF_TRNSFER_INTERRUPT-1]();
	}
	else if( GET_BIT( DMA1->ISR ,TCIF_7_BIT) )
	{
		DMA1_ISR[CHANNEL_7][TRANSFER_COMPLETE_INTERRUPT-1]();
	}
}
