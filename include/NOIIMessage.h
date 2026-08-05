#ifndef NOII_MESSAGE_H
#define NOII_MESSAGE_H
#endif

enum ImbalanceDirection {
    BUY          = 'B',
    SELL         = 'S',
    NO_IMBALANCE = 'N',
    INSUFFICIENT = 'O',
    PAUSED       = 'P',
};

enum PriceVariation {
    LESS_ONE       = 'L',
    ONE            = '1',
    TWO            = '2',
    THREE          = '3',
    FOUR           = '4',
    FIVE           = '5',
    SIX            = '6',
    SEVEN          = '7',
    EIGHT          = '8',
    NINE           = '9',
    TENS           = 'A',
    TWENTIES       = 'B',
    THIRTY_GREATER = 'C',
    NO_CALC        = ' ',
};
