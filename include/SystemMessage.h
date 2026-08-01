#ifndef SYSTEM_EVENT_H
#define SYSTEM_EVENT_H
#endif

enum SystemEvent {
    MESSAGE_START       = 'O',
    START_SYSTEM_HOURS  = 'S',
    START_MARKET_HOURS  = 'Q',
    END_MARKET_HOURS    = 'M',
    END_SYSTEM_HOURS    = 'E',
    MESSAGE_END         = 'C',
};
