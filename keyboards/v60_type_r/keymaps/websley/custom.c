#include QMK_KEYBOARD_H
#include "keymap.h"

enum my_layers {
    BASE_LAYER,
    MAC_BASE_LAYER,
    OVERLAY_LAYER,
    MAC_OVERLAY_LAYER,
    MIDI_LAYER
};

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
        case QK_MIDI_START:
            if (record->event.pressed) {
                layer_on(MIDI_LAYER);
            }
            return false;
        case QK_MIDI_STOP:
            if (record->event.pressed) {
                layer_off(MIDI_LAYER);
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
