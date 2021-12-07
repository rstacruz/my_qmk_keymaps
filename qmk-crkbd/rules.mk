MCU = atmega32u4
OLED_DRIVER_ENABLE = no
BOOTLOADER = atmel-dfu
COMBO_ENABLE = yes
EXTRAKEY_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes

DEBOUNCE_TYPE = asym_eager_defer_pk
# DEBOUNCE_TYPE = sym_eager_pk

# These make the firmware too big
# RGBLIGHT_ENABLE = yes
# TAP_DANCE_ENABLE = yes
