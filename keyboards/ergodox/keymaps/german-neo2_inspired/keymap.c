#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "keymap_extras/keymap_german.h"

#define BASE 0 // default layer
#define PROG 1 // programming
#define UML  2 // german umlaut
#define FUN  3 // some macros

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ^    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   X  |   V  |   L  |   C  |   W  |  L1  |           |  L1  |   K  |   H  |   G  |   F  |   Q  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Hyper/ESC|  U  |   I  |   A  |   E  |   O  |------|           |------|   S  |   N  |   R  |   T  |   D  |   '    |
 * |--------+------+------+------+------+------|  L2  |           |  L2  |------+------+------+------+------+--------|
 * | LShift |   @  |   ~  |   Y  |   P  |   Z  |      |           |      |   B  |   M  |   ,  |   .  |   J  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  L3  | GUI  | DEL  |  ALT | CTRL |                                       | Left | Down |  Up  | Right|  L3  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |Bckspc| Space|------|       |------| RShift |Enter |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,         DE_1,      DE_2,      DE_3,       DE_4,       DE_5,       KC_LEFT,
        KC_TAB,         DE_X,      DE_V,      DE_L,       DE_C,       DE_W,       OSL(PROG),
        ALL_T(KC_ESC),  DE_U,      DE_I,      DE_A,       DE_E,       DE_O,
        KC_LSFT,        DE_AT,     DE_TILD,   DE_Y,       DE_P,       DE_Z,       OSL(UML),
        OSL(FUN),       KC_LGUI,   KC_DEL,    KC_LALT,    KC_LCTL,
                                                       KC_NO, KC_NO,
                                                              KC_HOME,
                                               KC_BSPC,KC_SPC,KC_END,
        // right hand
        KC_RGHT,        DE_6,      DE_7,      DE_8,       DE_9,       DE_0,       DE_MINS,

        KC_FN0,         DE_K,      DE_H,      DE_G,       DE_F,       DE_Q,       DE_BSLS,
                        DE_S,      DE_N,      DE_R,       DE_T,       DE_D,       DE_QUOT,
        OSL(UML),       DE_B,      DE_M,      DE_COMM,    DE_DOT,     DE_J,       KC_RSFT,
                                   KC_LEFT,   KC_DOWN,    KC_UP,      KC_RGHT,    OSL(FUN),
        TG(UML),KC_NO,
        KC_PGUP,
        KC_PGDN,KC_RSFT,KC_ENT
),
/* Keymap 1: programming layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |  (   |   )  |      |      |           |      |      |   7  |   8  |   9  |   -  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  <   |  >   |  {   |   }  |      |------|           |------|      |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |  [   |   ]  |      |      |           |      |      |   1  |   2  |   3  |   *  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   =  |   0  |   .  |   /  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[PROG] = KEYMAP( // layer 1 : programming
       // left hand
       KC_TRNS,   KC_F1,    KC_F2,    KC_F3,     KC_F4,      KC_F5,    KC_TRNS,
       KC_TRNS,   KC_TRNS,  KC_TRNS,  DE_LPRN,   DE_RPRN,    KC_TRNS,  KC_TRNS,
       KC_TRNS,   DE_LESS,  DE_MORE,  DE_LCBR,   DE_RCBR,    KC_TRNS,
       KC_TRNS,   KC_TRNS,  KC_TRNS,  DE_LBRC,   DE_RBRC,    KC_TRNS,  KC_TRNS,
       KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F12,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_TRNS,
       KC_TRNS,   KC_TRNS,  DE_7,     DE_8,     DE_9,     DE_MINS,  KC_TRNS,
                  KC_TRNS,  DE_4,     DE_5,     DE_6,     DE_PLUS,  KC_TRNS,
       KC_TRNS,   KC_TRNS,  DE_1,     DE_2,     DE_3,     DE_ASTR,  KC_TRNS,
                            DE_EQL,   DE_0,     DE_DOT,   DE_SLSH,  KC_TRNS,
       KC_TRNS,   KC_TRNS,
       KC_TRNS,
       KC_TRNS,   KC_TRNS, KC_TRNS
),
/* Keymap 2: german umlaut
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  Ü   |      |  Ä   |      |  Ö   |------|           |------|  ß   |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[UML] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, DE_UE,   KC_TRNS, DE_AE,   KC_TRNS, DE_OE,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 DE_SS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: macro layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           | F12  |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |  M2  |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|  M1  |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FUN] = KEYMAP(
       // left hand
       KC_TRNS,   KC_F1,    KC_F2,    KC_F3,      KC_F4,    KC_F5,          KC_F11,
       KC_TRNS,   KC_TRNS,  KC_TRNS,  M(2),       KC_TRNS,  KC_TRNS,        KC_TRNS,
       KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,
       KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,        KC_TRNS,
       KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F12,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_TRNS,
       KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                M(1),     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    ACTION_LAYER_TAP_TOGGLE(PROG) // FN0
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch(id) {
        // send "SELECT * FROM"
        case 1:
            if (record->event.pressed) {
                return MACRO(I(10), D(LSFT), T(S), T(E), T(L), T(E), T(C), T(T), T(SPACE), T(RBRC), T(ENT), T(F), T(R), T(O), T(M), T(SPACE), U(LSFT), END);
            }
            break;
        // send "LEFT JOIN
        //         ON
        case 2:
            if (record->event.pressed) {
                return MACRO(I(10), D(LSFT), T(L), T(E), T(F), T(T), T(SPACE), T(J), T(O), T(I), T(N), T(SPACE), T(ENT), T(SPACE), T(SPACE), T(O), T(N), U(LSFT), T(LEFT), T(LEFT), T(LEFT), T(LEFT), T(LEFT), END);
            }
            break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
