#pragma once

#include_next "mcuconf.h"

// #undef RP_ADC_USE_ADC1
// #define RP_ADC_USE_ADC1 TRUE


#undef RP_SPI_USE_SPI0
#define RP_SPI_USE_SPI0 TRUE

#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 TRUE

#undef RP_PWM_USE_PWM1
#define RP_PWM_USE_PWM1 TRUE
