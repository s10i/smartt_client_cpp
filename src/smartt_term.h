#ifndef SMARTT_PARAMETER_H
#define SMARTT_PARAMETER_H

#include <string>
#include <iostream>


/// Represents a Smartt Term, that is, a parameter's name, a return attribute's name or an enumeration value.
class SmarttTerm {
    public:
        SmarttTerm(std::string name);

        /// Tests the equality between this term and another one.
        /// \return true if the two parameters compare equal, and false otherwise
        bool operator==(const SmarttTerm &rhs) const;

        /// Tests the difference between this term and another one.
        /// \return true if the two parameters compare different, and false otherwise
        bool operator!=(const SmarttTerm &rhs) const;

        /// \return A string containing the name of the attribute or value as Smartt knows it
        std::string getName() const;

        /// SmarttTerm to std::string cast.
        /// This is used to provide automatic coesion for use with ParameterList.
        /// \return Same as getName()
        /// \see @ParameterList
        operator std::string() const;

    private:
        //integer used to assign successive identifiers to objects
        static int nextIdentifier;

        const int identifier_;
        const std::string name_;
};


// All Smartt Terms
namespace smartt {
extern const SmarttTerm BMF;
extern const SmarttTerm BOVESPA;
extern const SmarttTerm F;
extern const SmarttTerm M;
extern const SmarttTerm ABSOLUTE_BROKERAGE_TAX;
extern const SmarttTerm ABSOLUTE_BROKERAGE_TAX_COST;
extern const SmarttTerm ABSOLUTE_INITIAL_DRAWDOWN;
extern const SmarttTerm ABSOLUTE_LARGEST_LOSS_ELIMINATION;
extern const SmarttTerm ABSOLUTE_LARGEST_PROFIT_ELIMINATION;
extern const SmarttTerm ABSOLUTE_MAXIMUM_DRAWDOWN;
extern const SmarttTerm ABSOLUTE_NUMBER_OF_ELIMINATIONS_OF_LONG_POSITIONS;
extern const SmarttTerm ABSOLUTE_NUMBER_OF_ELIMINATIONS_OF_SHORT_POSITIONS;
extern const SmarttTerm ABSOLUTE_NUMBER_OF_LOSS_ELIMINATIONS;
extern const SmarttTerm ABSOLUTE_NUMBER_OF_LOSS_ELIMINATIONS_OF_LONG_POSITIONS;
extern const SmarttTerm ABSOLUTE_NUMBER_OF_LOSS_ELIMINATIONS_OF_SHORT_POSITIONS;
extern const SmarttTerm ABSOLUTE_NUMBER_OF_PROFIT_ELIMINATIONS;
extern const SmarttTerm ABSOLUTE_NUMBER_OF_PROFIT_ELIMINATIONS_OF_LONG_POSITIONS;
extern const SmarttTerm ABSOLUTE_NUMBER_OF_PROFIT_ELIMINATIONS_OF_SHORT_POSITIONS;
extern const SmarttTerm ADDRESS;
extern const SmarttTerm AUTO;
extern const SmarttTerm AUTOMATIC_CONTRIBUTION;
extern const SmarttTerm AVERAGE_LOSS_IN_LOSS_ELIMINATIONS;
extern const SmarttTerm AVERAGE_NOMINAL_PRICE;
extern const SmarttTerm AVERAGE_PRICE;
extern const SmarttTerm AVERAGE_PROFIT_IN_PROFIT_ELIMINATIONS;
extern const SmarttTerm BALANCE;
extern const SmarttTerm BIRTHDAY;
extern const SmarttTerm BROKERAGE_DIGITAL_SIGNATURE;
extern const SmarttTerm BROKERAGE_ID;
extern const SmarttTerm BROKERAGE_LOGIN;
extern const SmarttTerm BROKERAGE_PASSWORD;
extern const SmarttTerm CANCELED;
extern const SmarttTerm CANCELED_BY_CLIENT;
extern const SmarttTerm CANCELED_EXPIRED_OPTION;
extern const SmarttTerm CANCELED_NOT_ALLOWED_MARKET;
extern const SmarttTerm CANCELED_NOT_ENOUGH_BALANCE;
extern const SmarttTerm CANCELED_NOT_POSITIONED;
extern const SmarttTerm CANCELED_ORDER_LIMIT_EXCEEDED;
extern const SmarttTerm CITY;
extern const SmarttTerm CODE;
extern const SmarttTerm CODE_UNDERLYING_STOCK;
extern const SmarttTerm COMPANY;
extern const SmarttTerm COMPANY_NAME;
extern const SmarttTerm COMPLEMENT;
extern const SmarttTerm CONTRIBUTION_OR_WITHDRAWAL;
extern const SmarttTerm COUNTRY;
extern const SmarttTerm CUSTODY_TAX;
extern const SmarttTerm DAILY_CUMULATIVE_PERFORMANCE;
extern const SmarttTerm DAILY_DRAWDOWN;
extern const SmarttTerm DATETIME;
extern const SmarttTerm DAY_TRADE_INCOME_TAX;
extern const SmarttTerm DAY_TRADE_LIQUIDATION_TAX;
extern const SmarttTerm DAY_TRADE_OTHER_TAXES;
extern const SmarttTerm DAY_TRADE_REGISTER_TAX;
extern const SmarttTerm DAY_TRADE_REGITER_TAX;
extern const SmarttTerm DAY_TRADE_TRADING_TAX;
extern const SmarttTerm DAY_TRADE_WITHHOLDING_INCOME_TAX;
extern const SmarttTerm DESCRIPTION;
extern const SmarttTerm DIRECT_DEBIT;
extern const SmarttTerm DOCUMENT;
extern const SmarttTerm EMAIL;
extern const SmarttTerm EQUITY;
extern const SmarttTerm EVENT_TYPE;
extern const SmarttTerm EXECUTED;
extern const SmarttTerm EXERCISE_PRICE;
extern const SmarttTerm EXPECTED_PAYOFF;
extern const SmarttTerm EXPIRATION_DATE;
extern const SmarttTerm EXPIRED;
extern const SmarttTerm FINAL_DATETIME;
extern const SmarttTerm FINANCIAL_TRANSACTION_ID;
extern const SmarttTerm FINANCIAL_VOLUME;
extern const SmarttTerm GENDER;
extern const SmarttTerm GROSS_ANNUALIZED_RETURN;
extern const SmarttTerm GROSS_DAILY_RETURN;
extern const SmarttTerm GROSS_LOSS;
extern const SmarttTerm GROSS_PROFIT;
extern const SmarttTerm GROSS_RETURN;
extern const SmarttTerm HUNG;
extern const SmarttTerm HUNG_CANCELLABLE;
extern const SmarttTerm HUNG_PENDING;
extern const SmarttTerm IGNORE;
extern const SmarttTerm INCOME_TAX_COST;
extern const SmarttTerm INCOME_TAX_PAYMENT;
extern const SmarttTerm INITIAL_CAPITAL;
extern const SmarttTerm INITIAL_DATETIME;
extern const SmarttTerm INVESTMENT_CODE;
extern const SmarttTerm IS_REAL;
extern const SmarttTerm ISIN_CODE;
extern const SmarttTerm ISS_TAX;
extern const SmarttTerm ISS_TAX_COST;
extern const SmarttTerm KIND_OF_QUOTATION;
extern const SmarttTerm KIND_OF_STOCK;
extern const SmarttTerm LEASE_TAX;
extern const SmarttTerm LIMIT_PRICE;
extern const SmarttTerm LIQUIDATION_TAX_COST;
extern const SmarttTerm LOGIN;
extern const SmarttTerm MAIN_PHONE;
extern const SmarttTerm MARGIN;
extern const SmarttTerm MARKET_NAME;
extern const SmarttTerm MAXIMUM_CONSECUTIVE_LOSS_ELIMINATIONS;
extern const SmarttTerm MAXIMUM_CONSECUTIVE_PROFIT_ELIMINATIONS;
extern const SmarttTerm MESSAGE;
extern const SmarttTerm NAME;
extern const SmarttTerm NAME_OR_CORPORATE_NAME;
extern const SmarttTerm NATURAL_PERSON_OR_LEGAL_PERSON;
extern const SmarttTerm NEIGHBORHOOD;
extern const SmarttTerm NET_ANNUALIZED_RETURN;
extern const SmarttTerm NET_DAILY_RETURN;
extern const SmarttTerm NET_LOSS;
extern const SmarttTerm NET_PROFIT;
extern const SmarttTerm NET_RETURN;
extern const SmarttTerm NEW_BROKERAGE_ID;
extern const SmarttTerm NEW_CODE;
extern const SmarttTerm NEW_LIMIT_PRICE;
extern const SmarttTerm NEW_NUMBER_OF_STOCKS;
extern const SmarttTerm NEW_PRICE;
extern const SmarttTerm NEW_S10I_PASSWORD;
extern const SmarttTerm NEW_STOP_PRICE;
extern const SmarttTerm NOMINAL_PRICE;
extern const SmarttTerm NUMBER;
extern const SmarttTerm NUMBER_OF_DAYS;
extern const SmarttTerm NUMBER_OF_ELIMINATIONS;
extern const SmarttTerm NUMBER_OF_EVENTS;
extern const SmarttTerm NUMBER_OF_STOCKS;
extern const SmarttTerm NUMBER_OF_TRADED_STOCKS;
extern const SmarttTerm OPERATIONAL_TAX_COST;
extern const SmarttTerm OPTION;
extern const SmarttTerm ORDER_CANCELED;
extern const SmarttTerm ORDER_CHANGED;
extern const SmarttTerm ORDER_EXECUTED;
extern const SmarttTerm ORDER_EXPIRED;
extern const SmarttTerm ORDER_ID;
extern const SmarttTerm ORDER_ID_IN_BROKERAGE;
extern const SmarttTerm ORDER_SENT;
extern const SmarttTerm ORDER_TYPE;
extern const SmarttTerm OTHER;
extern const SmarttTerm OTHER_TAXES_COST;
extern const SmarttTerm PAPER;
extern const SmarttTerm PARTIALLY_CANCELED;
extern const SmarttTerm PARTIALLY_EXECUTED;
extern const SmarttTerm PARTIALLY_EXECUTED_CANCELLABLE;
extern const SmarttTerm PASSWORD;
extern const SmarttTerm PERCENTUAL_BROKERAGE_TAX;
extern const SmarttTerm PERCENTUAL_BROKERAGE_TAX_COST;
extern const SmarttTerm PERCENTUAL_INITIAL_DRAWDOWN;
extern const SmarttTerm PERCENTUAL_LARGEST__LOSS_ELIMINATION;
extern const SmarttTerm PERCENTUAL_LARGEST__PROFIT_ELIMINATION;
extern const SmarttTerm PERCENTUAL_LARGEST_PROFIT_ELIMINATION;
extern const SmarttTerm PERCENTUAL_MAXIMUM_DRAWDOWN;
extern const SmarttTerm PERCENTUAL_NUMBER_OF_ELIMINATIONS_OF_LONG_POSITIONS;
extern const SmarttTerm PERCENTUAL_NUMBER_OF_ELIMINATIONS_OF_SHORT_POSITIONS;
extern const SmarttTerm PERCENTUAL_NUMBER_OF_LOSS_ELIMINATIONS;
extern const SmarttTerm PERCENTUAL_NUMBER_OF_LOSS_ELIMINATIONS_OF_LONG_POSITIONS;
extern const SmarttTerm PERCENTUAL_NUMBER_OF_LOSS_ELIMINATIONS_OF_SHORT_POSITIONS;
extern const SmarttTerm PERCENTUAL_NUMBER_OF_PROFIT_ELIMINATIONS;
extern const SmarttTerm PERCENTUAL_NUMBER_OF_PROFIT_ELIMINATIONS_OF_LONG_POSITIONS;
extern const SmarttTerm PERCENTUAL_NUMBER_OF_PROFIT_ELIMINATIONS_OF_SHORT_POSITIONS;
extern const SmarttTerm POSITION_INCOME_TAX;
extern const SmarttTerm POSITION_LIQUIDATION_TAX;
extern const SmarttTerm POSITION_OTHER_TAXES;
extern const SmarttTerm POSITION_REGISTER_TAX;
extern const SmarttTerm POSITION_TRADING_TAX;
extern const SmarttTerm POSITION_TYPE;
extern const SmarttTerm POSITION_WITHHOLDING_INCOME_TAX;
extern const SmarttTerm POSTAL_CODE;
extern const SmarttTerm PRICE;
extern const SmarttTerm PROFIT_FACTOR;
extern const SmarttTerm REGISTER_TAX_COST;
extern const SmarttTerm REJECTED;
extern const SmarttTerm RETURN_ATTRIBUTES;
extern const SmarttTerm S10I_LOGIN;
extern const SmarttTerm S10I_PASSWORD;
extern const SmarttTerm SECONDARY_PHONE;
extern const SmarttTerm SENT;
extern const SmarttTerm SENT_ORDER_ID;
extern const SmarttTerm SETUP_CODE;
extern const SmarttTerm SLIPPAGE;
extern const SmarttTerm SPECIFIC_DATE;
extern const SmarttTerm SPOT;
extern const SmarttTerm STATE;
extern const SmarttTerm STATUS;
extern const SmarttTerm STOCK_CODE;
extern const SmarttTerm STOP_ORDER_CANCELED;
extern const SmarttTerm STOP_ORDER_EXPIRED;
extern const SmarttTerm STOP_ORDER_ID;
extern const SmarttTerm STOP_ORDER_ID_IN_BROKERAGE;
extern const SmarttTerm STOP_ORDER_SENT;
extern const SmarttTerm STOP_ORDER_TRIGGERED;
extern const SmarttTerm STOP_ORDER_TYPE;
extern const SmarttTerm STOP_PRICE;
extern const SmarttTerm TAXES_AND_OPERATIONAL_COSTS;
extern const SmarttTerm TODAY;
extern const SmarttTerm TOTAL_CONTRIBUTIONS;
extern const SmarttTerm TOTAL_GROSS_PROFIT;
extern const SmarttTerm TOTAL_LOSS_IN_MAXIMUM_CONSECUTIVE_LOSS_ELIMINATIONS;
extern const SmarttTerm TOTAL_NET_PROFIT;
extern const SmarttTerm TOTAL_PROFIT_IN_MAXIMUM_CONSECUTIVE_PROFIT_ELIMINATONS;
extern const SmarttTerm TOTAL_WITHDRAWS;
extern const SmarttTerm TRADE_ID_IN_BROKERAGE;
extern const SmarttTerm TRADE_TYPE;
extern const SmarttTerm TRADING_LOT_SIZE;
extern const SmarttTerm TRADING_TAX_COST;
extern const SmarttTerm TYPE;
extern const SmarttTerm UNTIL_CANCEL;
extern const SmarttTerm VALIDITY;
extern const SmarttTerm VALIDITY_TYPE;
extern const SmarttTerm VALUE;
extern const SmarttTerm WITHHOLDING_INCOME_TAX_COST;
}

#endif