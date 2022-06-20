/* 
 * File:   hal_gpio.h
 * Author: Amr Samy
 *
 * Created on June 14, 2022, 6:02 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* Section: Includes */
#include "../MCAL_std_types.h"
#include "../proc/pic18f4620.h"
#include "../device_config.h"
#include "hal_gpio_cfg.h"

/* Section: Macro Declarations */
#define BIT_MASK                (uint8)1
#define PORT_PIN_MAX_NUMBER     8
#define PORT_MAX_NUMBER         5

#define GPIO_PORT_INPUT_DIRECTION       0x00
#define GPIO_PORT_OUTPUT_DIRECTION      0xFF

#define GPIO_PORT_LOW                   0x00
#define GPIO_PORT_HIGH                  0xFF

#define PORTx_MASK                      0xFF

#define GPIO_PORT_PIN_CONFIGURATIONS    CONFIG_ENABLE
#define GPIO_PORT_CONFIGURATIONS        CONFIG_ENABLE

/* Section: Macro Functions Declarations */
#define HWREG8(_X)      (*((volatile uint8 *)(_X)))

#define SET_BIT(REG, BIT_POSN)          (REG |= (BIT_MASK << BIT_POSN))
#define CLEAR_BIT(REG, BIT_POSN)        (REG &= ~(BIT_MASK << BIT_POSN))
#define TOGGLE_BIT(REG, BIT_POSN)       (REG ^= (BIT_MASK << BIT_POSN))
#define READ_BIT(REG, BIT_POSN)         ((REG >> BIT_POSN) & BIT_MASK)

/* Section: Data Type Declarations */

//Enum for Logic Value
typedef enum
{
    GPIO_LOW = 0,
    GPIO_HIGH       
}logic_t;

/* Enum for Direction Value */
typedef enum
{
    GPIO_DIRECTION_OUTPUT = 0,
    GPIO_DIRECTION_INPUT
}direction_t;

//Enum for Pin Index
typedef enum
{
    GPIO_PIN0 = 0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7,
}pin_index_t;

//Enum for Port Index
typedef enum
{
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX,
}port_index_t;

//Structure to Encapsulate the characteristics for every PIN
typedef struct
{
    uint8 port :3;        /* @ref  port_index_t */
    uint8 pin : 3;        /* @ref  pin_index_t  */
    uint8 direction : 1;  /* @ref  direction_t  */
    uint8 logic : 1;      /* @ref  logic_t      */
}pin_config_t;

/* Section: Function Declarations */
Std_ReturnType gpio_pin_direction_intialize (const pin_config_t *_pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *dic_status);
Std_ReturnType gpio_pin_write_logic         (const pin_config_t *_pin_config, logic_t logic);
Std_ReturnType gpio_pin_read_logic          (const pin_config_t *_pin_config, logic_t *logic);
Std_ReturnType gpio_pin_toggle_logic        (const pin_config_t *_pin_config);
Std_ReturnType gpio_pin_intialize           (const pin_config_t *_pin_config);

Std_ReturnType gpio_port_direction_intialize    (port_index_t port, direction_t direction);
Std_ReturnType gpio_port_get_direction_status   (port_index_t port, direction_t *direction_status);
Std_ReturnType gpio_port_write_logic            (port_index_t port, logic_t logic);
Std_ReturnType gpio_port_read_logic             (port_index_t port, logic_t *logic);
Std_ReturnType gpio_port_toggle_logic           (port_index_t port);

#endif	/* HAL_GPIO_H */

