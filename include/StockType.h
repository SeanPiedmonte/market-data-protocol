#ifndef STOCK_TYPE_H
#define STOCK_TYPE_H
#include "SystemMessage.h"
#endif

#include "Protocol.h"
#include "TradeMessage.h"

enum MessageType {
    SYSTEM_EVENT_MESSAG                                = 'S',
    STOCK_DIRECTORY_MESSAGE                            = 'R',
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

enum BreachedLevel {
    LEVEL1 = '1',
    LEVEL2 = '2',
    LEVEL3 = '3',
};

enum MarketCode {
    NASDAQ = 'Q',
    BX     = 'B',
    PSX    = 'X',
};

enum YesNoFlag {
    YES  = 'Y',
    NO   = 'N',
    NONE = ' ',
};

struct StockDirectory {
    u64 Stock;
    MarketCategory MarkCat;
    FinancialStatusIndicator FSI;
    u32 RoundLotSize;
    bool RoundLotsOnly;
    u8 IssueClassification;
    u16 IssueSubType;
    u8 Authenticity;
    YesNoFlag ShortSaleThresIndicator;
    YesNoFlag IPOFlag;
    u8 LULDReferencePriceTier;
    YesNoFlag ETPFlag;
    u32 ETPLeverageFactor;
    bool InverseIndicator;
};

struct StockTradingAction {
    u64 Stock;
    TradingState TS;
    u8 Reserved;
    u32 Reason;
};

struct ShortSalePriceTestRI {
    u64 Stock;
    REG_SHO_ACTION RSA;
};

struct MarketParticipantPosition {
    u32 MPID;
    u64 Stock;
    bool PrimaryMarketMaker;
    MarketMaker MarketMakerMode;
    MarketParticipant MarketParticipantState;
};

struct MWCBDeclineLevelMessage {
    u64 Level1;
    u64 Level2;
    u64 Level3;
};

struct IPOQuotingPeriodUpdate {
    u64 Stock;
    u32 IPOQuotationReleaseTime;
    u8  IPOQuotationReleaseQualifier;
    u32 IPOPrice;
};

struct LULDAuctionCollar {
    u64 Stock;
    u32 AuctionCollarReferencePrice;
    u32 UpperAuctionCollarPrice;
    u32 LowerAuctionCollarPrice;
    u32 AuctionCollarExtension;
};

struct OperationalHalt {
    u64 Stock;
    MarketCode MarketCode;
    u8 OperationalHaltAction;
};

struct AddOrder {
    u64 OrderReferenceNumber;
    u8  BuySellIndicator;
    u32 Shares;
    u64 Stock;
    u32 Price;
    u32 Attribution; // This field is possible to not be present
};

struct OrderExecutedWithPrice {
    u32 ExecutedShares;
    u64 MatchNumber;
    bool Printable;
    u32  ExecutionPrice;
};

struct OrderExecuted {
    u32 ExecutedShares;
    u64 MatchNumber;
};

struct OrderReplaceMessage {
    u64 NewOrderReferenceNumber;
    u32 Shares;
    u32 Price;
};

struct ModifyOrderMessages {
    MessageType Type;
    u64 OrderReferenceNumber;
    union {
        OrderExecuted OrderExecute;
        OrderExecutedWithPrice OrderExecuteWithPrice;
        u32 CancelledShares; // For a cancel msg
        struct {} Delete; // for a delete msg
        OrderReplaceMessage Replace;
    };
};

struct TradeMessageNonCross {
    u64 OrderReferenceNumber;
    u8  BuySellIndicator;
    u32 Shares;
    u64 Stock;
    u32 Price;
    u64 MatchNumber;
};

struct CrossTradeMessage {
    u64 Shares;
    u64 Stock;
    u32 CrossPrice;
    u64 MatchNumber;
    CrossType CrossType; 
};

struct Message {
    MessageType Type;
    u16         StockLocate;
    u16         TrackingNumber;
    u64         Timestamp;
    union {
        SystemEvent EventCode;
        StockDirectory Directory;
        StockTradingAction STA;
        ShortSalePriceTestRI SSPTRI;
        MarketParticipantPosition MPP;
        MWCBDeclineLevelMessage MWCBDecLevMsg;
        BreachedLevel BL;
        IPOQuotingPeriodUpdate IPO;
        LULDAuctionCollar LULDAucCol;
        OperationalHalt Halt;
        AddOrder AddOrder;
        ModifyOrderMessages ModifyOrder;
        TradeMessageNonCross TradeMessageNC;
        CrossTradeMessage CrossTradeMsg;
        u64 MatchNumber;
    };
};

