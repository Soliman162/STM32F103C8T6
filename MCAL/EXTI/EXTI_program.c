#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include "..\..\LIB\STM32F103C8.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (*EXTI_addISR[16])(void) = {NULL};

ERROR_enumSTATE EXTI_enumInit_Interrupt(const EXTI_Def_t * Copy_ptrstrEXTI_Data )
{
    ERROR_enumSTATE LOC_enumError_State = STD_TYPES_OK;
    if( Copy_ptrstrEXTI_Data != NULL )
    {
        u8 LOC_u8Port_ID = Copy_ptrstrEXTI_Data->PORT_ID;
        u8 LOC_u8PIN_NUM = Copy_ptrstrEXTI_Data->EXTI_PIN_NUM;
        u8 LOC_u8Trigger_Level = Copy_ptrstrEXTI_Data->Trigger_Level;

        if( (LOC_u8PIN_NUM <= EXTI_PIN_15) )
        {
            if( (LOC_u8Port_ID<=EXTI_PORTG) )
            {
                u8 LOC_u8EXTI_REG_NUM =  LOC_u8PIN_NUM   / 4 ;
                u8 LOC_u8Shift_Value  =  LOC_u8PIN_NUM   % 4 ;

                AFIO->EXTICR[LOC_u8EXTI_REG_NUM] &= (~(0b1111<< (LOC_u8Shift_Value*4) ) );
                AFIO->EXTICR[LOC_u8EXTI_REG_NUM] |= ( Copy_ptrstrEXTI_Data->PORT_ID<<(LOC_u8Shift_Value*4) );

                switch (LOC_u8Trigger_Level)
                {
                    case RISING_TRIGGER:
                        CLR_BIT(EXTI->FTSR ,Copy_ptrstrEXTI_Data->EXTI_PIN_NUM);
                        SET_BIT(EXTI->RTSR ,Copy_ptrstrEXTI_Data->EXTI_PIN_NUM);
                        break;
                    case FALLING_TRIGGER:
                        CLR_BIT(EXTI->RTSR ,Copy_ptrstrEXTI_Data->EXTI_PIN_NUM);
                        SET_BIT(EXTI->FTSR ,Copy_ptrstrEXTI_Data->EXTI_PIN_NUM);
                        break;
                    default:
                        LOC_enumError_State = STD_TYPES_NOK; 
                }

                EXTI_addISR[LOC_u8PIN_NUM] = Copy_ptrstrEXTI_Data->pfunc;
            }
        }else{ LOC_enumError_State = STD_TYPES_NOK; }

    }else{ LOC_enumError_State = STD_TYPES_NOK; }

    return LOC_enumError_State;

}

ERROR_enumSTATE EXTI_enumEnable_Interrupt( const EXTI_Def_t * Copy_ptrstrEXTI_Data )
{
    ERROR_enumSTATE LOC_enumError_State = STD_TYPES_OK;
    if( Copy_ptrstrEXTI_Data !=NULL )
    {
        if(  (Copy_ptrstrEXTI_Data->EXTI_PIN_NUM <= EXTI_PIN_15) )
        {
            SET_BIT(EXTI->IMR ,Copy_ptrstrEXTI_Data->EXTI_PIN_NUM);

        }else{ LOC_enumError_State =STD_TYPES_NOK; }
    }else{ LOC_enumError_State =STD_TYPES_NOK; }
   
    return LOC_enumError_State;
}

ERROR_enumSTATE EXTI_enumDisable_Interrupt( const EXTI_Def_t * Copy_ptrstrEXTI_Data )
{
    ERROR_enumSTATE LOC_enumError_State = STD_TYPES_OK;
    if( Copy_ptrstrEXTI_Data !=NULL )
    {
        if( (Copy_ptrstrEXTI_Data->EXTI_PIN_NUM <= EXTI_PIN_15) )
        {
            CLR_BIT(EXTI->IMR ,Copy_ptrstrEXTI_Data->EXTI_PIN_NUM);

        }else{ LOC_enumError_State =STD_TYPES_NOK; }
    }else{ LOC_enumError_State =STD_TYPES_NOK; }
   
    return LOC_enumError_State;
}

void EXTI0_IRQHandler(void)
{
    if( EXTI_addISR[0] != NULL )
    {
        EXTI_addISR[0]();
    }
    SET_BIT(EXTI->PR ,0);
}
void EXTI1_IRQHandler(void)
{
    if( EXTI_addISR[1] != NULL)
    {
        EXTI_addISR[1]();
    }
    SET_BIT(EXTI->PR ,1);
}
void EXTI2_IRQHandler(void)
{
    if( EXTI_addISR[2] != NULL)
    {
        EXTI_addISR[2]();
    }
    SET_BIT(EXTI->PR ,2);
}
void EXTI3_IRQHandler(void)
{
    if( EXTI_addISR[3] != NULL)
    {
        EXTI_addISR[3]();
    }
    SET_BIT(EXTI->PR ,3);
}
void EXTI4_IRQHandler(void)
{
    if( EXTI_addISR[4] != NULL)
    {
        EXTI_addISR[4]();
    }
    SET_BIT(EXTI->PR ,4);
}
