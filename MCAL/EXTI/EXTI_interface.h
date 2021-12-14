#ifndef EXTI_interface_H
#define EXTI_interface_H

/*typedef enum{

    EVENT_0,
    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
    EVENT_6,
    EVENT_7,
    EVENT_8,
    EVENT_9,
    EVENT_10,
    EVENT_11,
    EVENT_12,
    EVENT_13,
    EVENT_14,
    EVENT_15,
    EVENT_16,
    EVENT_17,
    EVENT_18,
    EVENT_19

 }EVENT_DEF_t;*/

typedef enum{

    EXTI_PORTA = 0b0000,    
    EXTI_PORTB = 0b0001,
    EXTI_PORTC = 0b0010,
    EXTI_PORTD = 0b0011,
    EXTI_PORTE = 0b0100,
    EXTI_PORTF = 0b0101,
    EXTI_PORTG = 0b0110

}EXTI_PORT_Config;

typedef enum{

    EXTI_PIN_0=0,
    EXTI_PIN_1,
    EXTI_PIN_2,
    EXTI_PIN_3,
    EXTI_PIN_4,
    EXTI_PIN_5,
    EXTI_PIN_6,
    EXTI_PIN_7,
    EXTI_PIN_8,
    EXTI_PIN_9,
    EXTI_PIN_10,
    EXTI_PIN_11,
    EXTI_PIN_12,
    EXTI_PIN_13,
    EXTI_PIN_14,
    EXTI_PIN_15

}EXTI_PIN_NUM_Config;

typedef enum{

    FALLING_TRIGGER,
    RISING_TRIGGER

}TRIGGER_type;

typedef struct{

    EXTI_PORT_Config        PORT_ID;
    EXTI_PIN_NUM_Config     EXTI_PIN_NUM;
    TRIGGER_type            Trigger_Level;
    void (*pfunc) (void);

}EXTI_Def_t;


ERROR_enumSTATE EXTI_enumInit_Interrupt    ( const EXTI_Def_t *  Copy_ptrstrEXTI_Data );
ERROR_enumSTATE EXTI_enumEnable_Interrupt  ( const EXTI_Def_t *  Copy_ptrstrEXTI_Data );
ERROR_enumSTATE EXTI_enumDisable_Interrupt ( const EXTI_Def_t *  Copy_ptrstrEXTI_Data );



#endif