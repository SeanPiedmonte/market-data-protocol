#ifndef STOCK_TYPE_H
#define STOCK_TYPE_H
#endif

enum MessageType {
    STOCK_DIRECTORY_MESSAGE                            = 'R',
    SYSTEM_EVENT_MESSAG                                = 'S',
    STOCK_TRADING_ACTION_MESSAGE                       = 'H',
    REG_SHO_SHORT_SALE_PRICE_TEST_RESTRICTED_INDICATOR = 'Y',
    MARKET_PARTICIPANT_POSITION_MESSAGE                = 'L',
    MARKET_WIDE_CIRCUIT_BREAKER_DECLINE_LEVEL_MESSAGE  = 'V',
    MARKET_WIDE_CIRCUIT_BREAKER_STATUS_MESSAGE         = 'W',
    QUOTING_PERIOD_UPDATE                              = 'K',
    LULD_AUCTION_COLLAR                                = 'J',
    OPERATIONAL_HALT                                   = 'h',
    ADD_ORDER_NO_MPID_ATTRIBUTION_MESSAGE              = 'A',
    ADD_ORDER_MPID_ATTRIBUTION_MESSAGE                 = 'F',
    ADD_ORDER_ORDER_EXECUTED_MESSAGE                   = 'E',
    ADD_ORDER_ORDER_EXECUTED_WITH_PRICE_MESSAGE        = 'C',
    ORDER_CANCEL_MESSAGE                               = 'X',
    ORDER_DELETE_MESSAGE                               = 'D',
    ORDER_REPLACE_MESSAGE                              = 'U',
    TRADE_MESSAGE                                      = 'P',
    CROSS_TRADE_MESSAGE                                = 'Q',
    BROKEN_TRADE_MESSAGE                               = 'B',
    NOII_MESSAGE                                       = 'I',
    RETAIL_INTEREST_MESSAGE                            = 'N',
    DIRECT_LISTING_WITH_CAPITAL_RAISE_MESSAGE          = 'O',
};

enum MarketCategory {
    NASDAQ_GLOBAL_SELECT_MARKET = 'Q',
    NASDAQ_GLOBAL_MARKET        = 'G',
    NASDAQ_CAPITAL_MARKET       = 'S',
    NYSE                        = 'N',
    NYSE_AMERICAN               = 'A',
    NYSE_ACRA                   = 'P',
    BATS_Z_EXCHANGE             = 'Z',
    INVESTORS_EXCHANGE_LLC      = 'V',
};

enum FinancialStatusIndicator {
    DEFICIENT                                               = 'D',
    DELINQUINT                                              = 'E',
    BANKRUPT                                                = 'Q',
    SUSPENDED                                               = 'S',
    DEFICIENT_AND_BANKRUPT                                  = 'G',
    DEFICIENT_AND_DELINQUIENT                               = 'H',
    DELINQUINT_AND_BANKRUPT                                 = 'J',
    DEFICIENT_AND_DELINQUIENT_AND_BANKRUPT                  = 'K',
    CREATIONS_AND_OR_REDEMPTIONS_SUS_FOR_EXCH_TRADE_PRODUCT = 'C',
    NORMAL                                                  = 'N',
};

enum TradingState {
    HALT      = 'H',
    PAUSE     = 'P',
    QUOTATION = 'Q',
    TRADING   = 'T',
};

enum REG_SHO_ACTION {
    NO_PRICE             = '0',
    INTRA_DAY_PRICE_DROP = '1',
    TEST_RESTRICTION     = '2'
};

enum MarketMaker {
    NORM          = 'N',
    PASSIVE       = 'P',
    SYNDICATE     = 'S',
    PRE_SYNDICATE = 'R',
    PENALTY       = 'L'
};

enum MarketParticipant {
    ACTIVE    = 'A',
    EXCUSED   = 'E',
    WITHDRAWN = 'W',
    SUS       = 'S',
    DELETED   = 'D',
};
