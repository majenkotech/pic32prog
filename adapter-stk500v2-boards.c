#include <config.h>

#include "adapter-stk500v2-boards.h"

#define     vendUnknown         0xFFFF
#define     vendUnassigned      0x0000
#define     vendDigilent        0x0001
#define     vendMicrochip       0x0002
#define     vendFubarino        0x0003
#define     vendSchmalzHausLLC  0x0004
#define     vendOlimex          0x0005
#define     vendElement14       0x0006
#define     vendPontech         0x0007
#define     vend4DSystems       0x0008
#define     vendMajenko         0x0009
#define     vendMikroe          0x000A
#define     vendExperimental    0x8000

const stk500v2_board_t stk500v2_boards[] = {

    // Unassigned
    { vendUnassigned, 0x0000, "Unassigned", },

    // Digilent
    { vendDigilent, 0x0101, "chipKIT Uno32", },
    { vendDigilent, 0x0102, "chipKIT Max32", },
    { vendDigilent, 0x0103, "chipKIT uC32", },
    { vendDigilent, 0x0104, "chipKIT WF32", },
    { vendDigilent, 0x0105, "chipKIT FG32", },
    { vendDigilent, 0x0201, "Cerebot32 MX4", },
    { vendDigilent, 0x0202, "Cerebot32 MX7", },
    { vendDigilent, 0x0203, "Cerebot32 MX3cK 128", },
    { vendDigilent, 0x0204, "Cerebot32 MX4cK", },
    { vendDigilent, 0x0205, "Cerebot32 MX7cK", },
    { vendDigilent, 0x0206, "Cerebot32 MX3cK 512", },
    { vendDigilent, 0x0301, "Cmod CK1", },
    { vendDigilent, 0x0401, "chipKIT DP32", },
    { vendDigilent, 0x0501, "chipKIT UDP32PIM", },
    { vendDigilent, 0x0601, "chipKIT WiFire", },
    { vendDigilent, 0x0602, "chipKIT zUno", },

    // Fubarino

    { vendFubarino, 0x0001, "Fubarino SD", },
    { vendFubarino, 0x0002, "Fubarino Mini", },
    { vendFubarino, 0x0003, "Fubarino SD 512K", },
    { vendFubarino, 0x0004, "Fubarino Mini 48MHz", },
    { vendFubarino, 0x0005, "Fubarino Mini 50MHz", },
    { vendFubarino, 0x0006, "Fubarino SDZ", },

    // Schmalz Haus

    { vendSchmalzHausLLC, 0x0001, "EEBv3", },
    { vendSchmalzHausLLC, 0x0002, "UBW32 MX460", },
    { vendSchmalzHausLLC, 0x0003, "UBW32 MX795", },

    // Olimex

    { vendOlimex, 0x0001, "PIC32 Pinguino", },
    { vendOlimex, 0x0002, "Duinomite", },

    // Element 14

    { vendElement14, 0x0001, "chipKIT Pi", },

    // Pontech

    { vendPontech, 0x0001, "Quick240", },
    { vendPontech, 0x0002, "UAV100", },

    // 4D Systems

    { vend4DSystems, 0x0001, "Picadillo-35T", },

    // Majenko Technologies

    { vendMajenko, 0x0001, "Majenko Technologies SDXL", },
    { vendMajenko, 0x0002, "Majenko Technologies SDAU", },
    { vendMajenko, 0x0003, "Majenko Technologies SDZL", },
    { vendMajenko, 0x0004, "Majenko Technologies UltraNano", },
    { vendMajenko, 0x0005, "Majenko Technologies SDZLEFH", },

    // MikroE

    { vendMikroe, 0x0001, "PIC32MX Clicker", },

    { 0, 0, 0 }
};
