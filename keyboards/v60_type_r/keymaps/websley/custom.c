#include QMK_KEYBOARD_H
#include "keymap.h"

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
        case MEDIA_PLAY:
            if (record->event.pressed) {
                host_consumer_send(0xB0);
            } else {
                host_consumer_send(0);
            }
            return false;
        case MEDIA_PAUSE:
            if (record->event.pressed) {
                host_consumer_send(0xB1);
            } else {
                host_consumer_send(0);
            }
            return false;
    }
    return true;
}
