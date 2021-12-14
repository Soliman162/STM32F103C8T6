#ifndef SPI1_INTERFACE_H
#define SPI1_INTERFACE_H

void SPI1_voidInit(void);
ERROR_enumSTATE SPI1_voidTransmite_Recieve(u8 Copy_u8TransimitedData,u8 *Copy_u8RecievedData);
ERROR_enumSTATE SPI1_voidTransmite_Recieve_string( u8 *Copy_u8TransimitedData);

#endif
