# MCU name
MCU = STM32F411
BOOTLOADER = tinyuf2

SERIAL_DRIVER ?= usart
WS2812_DRIVER ?= bitbang

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
ENCODER_ENABLE = no

# Either do RGBLIGHT_ENABLE or RGB_MATRIX_ENABLE and RGB_MATRIX_DRIVER
RGBLIGHT_ENABLE ?= no
RGB_MATRIX_ENABLE ?= yes
RGB_MATRIX_DRIVER = ws2812

MIDI_ENABLE = no            # MIDI support
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
ENCODER_ENABLE = no
OLED_ENABLE = no            # this can be yes or no depending on if you have an OLED
EXTRAFLAGS     += -flto     # macros disabled, as a lot of barobord features require more space, can move this line into all the individual rules.mk, only where needed
                            # for instance, if you build "no_features", it's very unlikely you'll need to disable macros
MOUSEKEY_ENABLE = no

AUDIO_ENABLE ?= yes
# AUDIO_DRIVER = pwm_hardware
AUDIO_DRIVER = pwm_software
CIRQUE_ENABLE ?= no

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
   RGB_MATRIX_CUSTOM_KB = yes
   OPT_DEFS += -DRGB_MATRIX_CUSTOM_KB
endif

ifeq ($(strip $(CIRQUE_ENABLE)), yes)
   MOUSEKEY_ENABLE := yes  # not required, but enabling for mouse button keys
   POINTING_DEVICE_ENABLE := yes
   POINTING_DEVICE_DRIVER := cirque_pinnacle_i2c
   OPT_DEFS += -DCIRQUE_ENABLE
endif

include keyboards/fingerpunch/src/rules.mk
