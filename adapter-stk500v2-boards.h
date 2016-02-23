#ifndef _ADAPTER_STK500V2_BOARDS_H
#define _ADAPTER_STK500V2_BOARDS_H

typedef struct {
    unsigned vendor_id;
    unsigned product_id;
    const char *name;
} stk500v2_board_t;

extern const stk500v2_board_t stk500v2_boards[];

#endif // _ADAPTER_STK500V2_BOARDS_H
