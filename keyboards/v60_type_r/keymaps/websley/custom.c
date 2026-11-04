#include QMK_KEYBOARD_H

#define MAC_ALT_LAYER QK_USER_0
#define LAYER_A 2
#define LAYER_B 3

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MAC_ALT_LAYER:
            if (record->event.pressed) {
                layer_on(LAYER_A);
                layer_on(LAYER_B);
            } else {
                layer_off(LAYER_A);
                layer_off(LAYER_B);
            }
            return false;
    }
    return true;
}
