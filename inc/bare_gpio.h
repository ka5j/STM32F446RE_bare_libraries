#ifndef GPIO_H_
#define GPIO_H_

#include "device_registers.h"
#include <stdint.h>

#define GPIO_PORTA 0x00
#define GPIO_PORTB 0x01
#define GPIO_PORTC 0x02
#define GPIO_PORTD 0x04
#define GPIO_PORTE 0x05
#define GPIO_PORTF 0x06
#define GPIO_PORTG 0x07
#define GPIO_PORTH 0x08

#define GPIO_MODE_INPUT 0x00
#define GPIO_MODE_OUTPUT 0x01
#define GPIO_MODE_AF 0x02
#define GPIO_MODE_ANALOG 0x03

#define GPIO_PIN_HIGH 0x01
#define GPIO_PIN_LOW 0x00

#define GPIO_PUSH_PULL 0x00
#define GPIO_OPEN_DRAIN 0x01

#define GPIO_LOW_SPEED 0x00
#define GPIO_MEDIUM_SPEED 0x01
#define GPIO_FAST_SPEED 0x02
#define GPIO_HIGH_SPEED 0x03

#define GPIO_FLOATING 0x00
#define GPIO_PULL_UP 0x01
#define GPIO_PULL_DOWN 0x02



#endif /* GPIO_H_ */