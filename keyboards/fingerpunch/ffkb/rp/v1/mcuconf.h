#pragma once

#include_next <mcuconf.h>

#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 TRUE

#undef RP_PWM_USE_PWM1
#define RP_PWM_USE_PWM1 TRUE

#undef RP_SPI_USE_SPI0
#define RP_SPI_USE_SPI0 TRUE

// #undef RP_PWM_USE_PWM0
// #define RP_PWM_USE_PWM0 TRUE

// #undef RP_SIO_USE_UART0
// #define RP_SIO_USE_UART0 TRUE
