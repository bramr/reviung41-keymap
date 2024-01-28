 #include QMK_KEYBOARD_H

 enum layer_names {
     _BASE,
     _SYMBOL,
     _MOVE,
     _FUNC
 };


// Shortcut to make keymap more readable
#define KC_OSX_EJECT 0x66
#define LOCK_OSX LSFT(LCTL(KC_OSX_EJECT))
#define SLEEP_OSX LALT(LGUI(KC_OSX_EJECT))

// Macos Emoji
#define KC_MAC_EM   LCTL(LGUI(KC_SPACE))


 // tap dance declarations
 enum {
     _TD_CTRL_ESC = 0,
     _TD_TAB_ESC,
     _TD_BSPC_WDEL,
     _TD_SFT_CAPS,
     _TD_SPC_ENT,
     _TD_CTRL_LANG,
 };

 #define TD_CTRL_ESC TD(_TD_CTRL_ESC)
 #define TD_TAB_ESC TD(_TD_TAB_ESC)
 #define TD_BSPC_WDEL TD(_TD_BSPC_WDEL)
 #define TD_SFT_CAPS TD(_TD_SFT_CAPS)
 #define TD_SPC_ENT TD(_TD_SPC_ENT)
 #define TD_CTRL_LANG TD(_TD_CTRL_LANG)

 // Tap Dance Definitions
 tap_dance_action_t tap_dance_actions[] = {
     [_TD_CTRL_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_ESC),
     [_TD_BSPC_WDEL] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, LALT(KC_BSPC)),
     [_TD_SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
     [_TD_SPC_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
     [_TD_CTRL_LANG] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, LCTL(LSFT(KC_SPACE))),
 };

// Combos
const uint16_t PROGMEM c_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM c_bsp[] = {KC_O, KC_P, COMBO_END};

combo_t key_combos[] = {
    COMBO(c_esc, KC_ESC),
    COMBO(c_bsp, KC_BSPC),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /**
    * QWERTY / BASE
    * +-----------------------------------------+         +-----------------------------------------+
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |         |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+------+         +------+------+------+------+------+------|
    * |CtlEsc|   A  |   S  |   D  |   F  |   G  |         |   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------+         +------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |         |   N  |   M  |   ,  |   .  |   /  |SftEnt|
    * +------+------+------+------+------+------+---------+------+------+------+------+------+------+
    *                             | GUI  |SYMBOL|  Space  | MOVE | Alt  |
    *                             +-------------+---------+-------------+
    */
	[_BASE] = LAYOUT(
            KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y,
                KC_U, KC_I, KC_O, KC_P, KC_BSPC,
            LCTL_T(KC_ESC), LSFT_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LCTL_T(KC_F), LCA_T(KC_G),
                ALL_T(KC_H), RCTL_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RSFT_T(KC_SCLN), KC_QUOT,
            KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,
                KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_ENT),
            KC_LGUI, MO(1), KC_SPC, LT(2, KC_BSPC), KC_LALT),
   /**
    * QWERTY / SYMBOL
    * +-----------------------------------------+         +-----------------------------------------+
    * |      |   !  |   @  |   #  |   $  |   %  |         |   ^  |   &  |   *  |   (  |   )  |      |
    * |------+------+------+------+------+------+         +------+------+------+------+------+------|
    * |      |   1  |   2  |   3  |   4  |   5  |         |   6  |   7  |   8  |   9  |   0  |      |
    * |------+------+------+------+------+------+         +------+------+------+------+------+------|
    * |      |   [  |   ]  |   {  |   }  |   -  |         |   _  |   =  |   +  |   '  |   "  |      |
    * +------+------+------+------+------+------+---------+------+------+------+------+------+------+
    *                             | GUI  |      |  Enter  | FUNC | Alt  |
    *                             +-------------+---------+-------------+
    */
	[_SYMBOL] = LAYOUT(
            KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,
                KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
            KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5,
                KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
            KC_TRNS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_MINS,
                KC_UNDS, KC_EQL, KC_PLUS, KC_QUOT, KC_DQUO, KC_TRNS,
            KC_TRNS, KC_NO, KC_ENT, MO(3), KC_TRNS),
   /**
    * QWERTY / MOVE
    * +-----------------------------------------+         +-----------------------------------------+
    * |      |   ~  |   `  |   |  |   \  |      |         | G-{  | G-}  | G-W  | G-`  | TAB  |      |
    * |------+------+------+------+------+------+         +------+------+------+------+------+------|
    * |      |      |      | GSTab| GTab |      |         | LEFT | DOWN | UP   | RIGHT|  \   |      |
    * |------+------+------+------+------+------+         +------+------+------+------+------+------|
    * |      |      |      |      |      |      |         | C-1  | C-2  | C-3  | C-4  | C-5  |      |
    * +------+------+------+------+------+------+---------+------+------+------+------+------+------+
    *                             | GUI  | FUNC |  Enter  |      | Alt  |
    *                             +-------------+---------+-------------+
    */
	[_MOVE] = LAYOUT(
            KC_TRNS, KC_TILD, KC_GRV, KC_PIPE, KC_BSLS, KC_NO,
                LGUI(KC_LCBR), LGUI(KC_RCBR), LGUI(KC_W), LGUI(KC_GRV), KC_TAB, KC_NO,
            KC_NO, KC_NO, KC_NO, SGUI(KC_TAB), LGUI(KC_TAB), KC_NO,
                KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BSLS, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5),KC_TRNS,
            KC_TRNS, MO(3), KC_ENT, KC_NO, KC_TRNS),
   /**
    * QWERTY / FUNC
    * +-----------------------------------------+         +-----------------------------------------+
    * |      | BOOT | PScr | Home | End  | PgUp |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |
    * |------+------+------+------+------+------+         +------+------+------+------+------+------|
    * |      |      |      |      |      | PgDn |         |  F6  |  F7  |  F8  |  F9  |  F10 |      |
    * |------+------+------+------+------+------+         +------+------+------+------+------+------|
    * |      |      |      |      | BrDn | BrUp |         | VoDn | VoUp | Play |  F11 |  F12 |      |
    * +------+------+------+------+------+------+---------+------+------+------+------+------+------+
    *                             | GUI  |      |  Enter  | FUNC | Alt  |
    *                             +-------------+---------+-------------+
    */
	[_FUNC] = LAYOUT(
            KC_TRNS, QK_BOOT, KC_PSCR, KC_HOME, KC_END, KC_PGUP,
                KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,
            KC_TRNS, OSM(MOD_LSFT), OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LCTL), KC_NO,
                KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
            KC_TRNS, KC_INS, KC_DEL, KC_NO, KC_BRID, KC_BRIU,
                KC_VOLD, KC_VOLU, KC_MPLY, KC_F11, KC_F12, KC_TRNS,
            KC_TRNS, KC_NO, KC_ENT, KC_NO, KC_TRNS)
};

