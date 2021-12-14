/*********************************************************************************/
/******************* Name : Ahmed Elsayed   **************************************/
/******************* Date : 6/8/2021        **************************************/
/******************* Version : 1.0v         **************************************/ 
/******************* SWC : NVIC_interface.c **************************************/ 
/*********************************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H



typedef enum{


    WWDG_IR=0,
    PVD_IR,
    TAMPER_IR,
    RTC_IR,
    FLASH_IR,
    RCC_IR,
    EXTI0_IR,
    EXTI1_IR,
    EXTI2_IR,
    EXTI3_IR,
    EXTI4_IR,
    DMA1_Channel1_IR,
    DMA1_Channel2_IR,
    DMA1_Channel3_IR,
    DMA1_Channel4_IR,
    DMA1_Channel5_IR,
    DMA1_Channel6_IR,
    DMA1_Channel7_IR,
    ADC1_2_IR,
    USB_HP_CAN_TX_IR,
    USB_LP_CAN_RX0_IR,
    CAN_RX1_IR,
    CAN_SCE_IR,
    EXTI9_5_IR,
    TIM1_BRK_IR,
    TIM1_UP_IR,
    TIM1_TRG_COM_IR,
    TIM1_CC_IR,
    TIM2_IR,
    TIM3_IR,
    TIM4_IR,
    I2C1_EV_IR,
    I2C1_ER_IR,
    I2C2_EV_IR,
    I2C2_ER_IR,
    SPI1_IR,
    SPI2_IR,
    USART1_IR,
    USART2_IR,
    USART3_IR,
    EXTI15_10_IR,
    RTCAlarm_IR,
    USBWakeup_IR,
    TIM8_BRK_IR,
    TIM8_UP_IR,
    TIM8_TRG_COM_IR,
    TIM8_CC_IR,
    ADC3_IR,
    FSMC_IR,
    SDIO_IR,
    TIM5_IR,
    SPI3_IR,
    UART4_IR,
    UART5_IR,
    TIM6_IR,
    TIM7_IR,
    DMA2_Channel1_IR,
    DMA2_Channel2_IR,
    DMA2_Channel3_IR,
    DMA2_Channel4_5_IR

}IRQ_Type;

typedef enum{

    Group_u8Priority_0=0b00,
    Group_u8Priority_1=0b01,
    Group_u8Priority_2=0b10,
    Group_u8Priority_3=0b11

}Group_priority_t;


typedef enum{

    SUB_u8Priority_0=0b00,
    SUB_u8Priority_1=0b01,
    SUB_u8Priority_2=0b10,
    SUB_u8Priority_3=0b11

}SUB_Priority_t;



ERROR_enumSTATE NVIC_voidEnableIRQ(IRQ_Type IRQn);
ERROR_enumSTATE NVIC_voidDisableIRQ(IRQ_Type IRQn);

ERROR_enumSTATE NVIC_voidSetPendingIRQ(IRQ_Type IRQn);
ERROR_enumSTATE NVIC_voidClearPendingIRQ(IRQ_Type IRQn);

ERROR_enumSTATE NVIC_u8GetPendingIRQ(IRQ_Type IRQn,u8 *COPY_ptru8DATA);

ERROR_enumSTATE NVIC_u8GetActiveIRQ( IRQ_Type IRQn ,u8 *COPY_ptru8DATA);

ERROR_enumSTATE NVIC_SetPriority(IRQ_Type IRQn, Group_priority_t GROUP_u8priority, SUB_Priority_t SUB_u8priority);
ERROR_enumSTATE NVIC_GetPriority(IRQ_Type IRQn,u8 *COPY_ptru8DATA);

void Init_priority_field(void);


#endif
