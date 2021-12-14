#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include "..\..\LIB\STM32F103C8.h"

#include "SPI1_interface.h"
#include "SPI1_private.h"
#include "SPI1_config.h"

u8 * SPI_string;

void SPI1_voidInit(void)
{
	u16 CR1_config[12] = {BIDIRECTIONAL_DATA_MODE,OUTPUT_BIDIERCTIONAL_MODE,CRC_CALCULATION,CRC_TRANSFER_NEXT
	                        ,DATA_FRAME,RXONLY,SOFTWARE_SLAVE_MANAGEMENT,LSBFIRST,BUAD_RATE_CONTROL,MASTR_CONFIGRATION,CPOL,CPHA};
    SPI1->CR1 &= 0;
    for(u8 i=0;i<12;i++)
    {
        SPI1->CR1 |= CR1_config[i];
    }
    SET_BIT(SPI1->CR1,6);
}

ERROR_enumSTATE SPI1_voidTransmite_Recieve(u8 Copy_u8TransimitedData,u8 *Copy_u8RecievedData)
{
    ERROR_enumSTATE LOC_enumError_State = STD_TYPES_OK;
    if( Copy_u8RecievedData != NULL)
    {
        SPI1->DR = Copy_u8TransimitedData;
        while( GET_BIT(SPI1->SR,1) == 1 );

        //while( GET_BIT(SPI1->SR,0) == 0 );
        *Copy_u8RecievedData = SPI1->DR;
    }else
    {
        LOC_enumError_State = STD_TYPES_NOK;
    }
    return LOC_enumError_State;
}

ERROR_enumSTATE SPI1_voidTransmite_Recieve_string( u8 *Copy_u8TransimitedData){

    ERROR_enumSTATE LOC_enumError_State = STD_TYPES_OK;
    u8 i = 0;

	if(Copy_u8TransimitedData!=NULL){

		while( Copy_u8TransimitedData[i] != '\0' ){

			SPI1_voidTransmite_Recieve(Copy_u8TransimitedData[i],&SPI_string[i]);
			i++;
		}

	}else{

        LOC_enumError_State = STD_TYPES_NOK;

	}
    return LOC_enumError_State;
}

