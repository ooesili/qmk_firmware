#include QMK_KEYBOARD_H
#include "keymap.h"

#define BASE_LAYER 0
#define MAC_BASE_LAYER 1
#define OVERLAY_LAYER 2
#define MAC_OVERLAY_LAYER 3

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_MAC_OVERLAY:
            if (record->event.pressed) {
                layer_on(OVERLAY_LAYER);
                layer_on(MAC_OVERLAY_LAYER);
            } else {
                layer_off(OVERLAY_LAYER);
                layer_off(MAC_OVERLAY_LAYER);
            }
            return false;
    }
    return true;
}

bool process_detected_host_os_user(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_MACOS:
            layer_on(MAC_BASE_LAYER);
            break;
        default:
            break;
    }

    return true;
}
