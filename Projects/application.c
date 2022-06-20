/*
 * File   : application.c
 * Author : Amr Mohamed Samy
 * Created on June 14,2022
 */
#define _XTAL_FREQ  4000000
#include "Application.h"

pin_config_t led_1 = 
{
    .port       = PORTC_INDEX,
    .pin        = GPIO_PIN7,
    .direction  = GPIO_DIRECTION_OUTPUT,
    .logic      = GPIO_LOW
};

pin_config_t led_2 = 
{
    .port       = PORTC_INDEX,
    .pin        = GPIO_PIN1,
    .direction  = GPIO_DIRECTION_OUTPUT,
    .logic      = GPIO_LOW
};

pin_config_t led_3 = 
{
    .port       = PORTC_INDEX,
    .pin        = GPIO_PIN2,
    .direction  = GPIO_DIRECTION_OUTPUT,
    .logic      = GPIO_LOW
};

pin_config_t btn_1 = 
{
    .port       = PORTD_INDEX,
    .pin        = GPIO_PIN0,
    .direction  = GPIO_DIRECTION_INPUT,
    .logic      = GPIO_LOW
};

Std_ReturnType ret = E_NOK;
direction_t led_1_st;
logic_t btn1_st;

int main()
{    
    gpio_port_direction_intialize(PORTC_INDEX, 0x00);
    gpio_port_write_logic(PORTC_INDEX, 0x55);
  
    while(1)
    {
        gpio_port_toggle_logic(PORTC_INDEX);
        //gpio_port_write_logic(PORTC_INDEX, 0x55);
        __delay_ms(250);
        //gpio_port_write_logic(PORTC_INDEX, 0xAA);
        //__delay_ms(250);
        //gpio_port_write_logic(PORTC_INDEX, 0x0F);
        //__delay_ms(250);
        //gpio_port_write_logic(PORTC_INDEX, 0xF0);
        //__delay_ms(250);
    }
    return (EXIT_SUCCESS);
}

void application_initialize()
{
    ret = gpio_pin_intialize(&led_1);
}