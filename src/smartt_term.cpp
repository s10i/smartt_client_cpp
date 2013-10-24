#include "smartt_term.h"

int SmarttTerm::nextIdentifier = 1;

SmarttTerm::SmarttTerm(std::string name) :
    identifier_(nextIdentifier),
    name_(name)
{
    nextIdentifier++;
}

bool SmarttTerm::operator==(const SmarttTerm &rhs) const
{
    return identifier_ == rhs.identifier_;
}

bool SmarttTerm::operator!=(const SmarttTerm &rhs) const
{
    return identifier_ != rhs.identifier_;
}

std::string SmarttTerm::getName() const
{
    return name_;
}

SmarttTerm::operator std::string() const
{
    return name_;
}

namespace smartt {
const SmarttTerm BMF("BMF");
const SmarttTerm BOVESPA("Bovespa");
const SmarttTerm F("F");
const SmarttTerm M("M");
const SmarttTerm ABSOLUTE_BROKERAGE_TAX("absolute_brokerage_tax");
const SmarttTerm ABSOLUTE_BROKERAGE_TAX_COST("absolute_brokerage_tax_cost");
const SmarttTerm ABSOLUTE_INITIAL_DRAWDOWN("absolute_initial_drawdown");
const SmarttTerm ABSOLUTE_LARGEST_LOSS_ELIMINATION("absolute_largest_loss_elimination");
const SmarttTerm ABSOLUTE_LARGEST_PROFIT_ELIMINATION("absolute_largest_profit_elimination");
const SmarttTerm ABSOLUTE_MAXIMUM_DRAWDOWN("absolute_maximum_drawdown");
const SmarttTerm ABSOLUTE_NUMBER_OF_ELIMINATIONS_OF_LONG_POSITIONS("absolute_number_of_eliminations_of_long_positions");
const SmarttTerm ABSOLUTE_NUMBER_OF_ELIMINATIONS_OF_SHORT_POSITIONS("absolute_number_of_eliminations_of_short_positions");
const SmarttTerm ABSOLUTE_NUMBER_OF_LOSS_ELIMINATIONS("absolute_number_of_loss_eliminations");
const SmarttTerm ABSOLUTE_NUMBER_OF_LOSS_ELIMINATIONS_OF_LONG_POSITIONS("absolute_number_of_loss_eliminations_of_long_positions");
const SmarttTerm ABSOLUTE_NUMBER_OF_LOSS_ELIMINATIONS_OF_SHORT_POSITIONS("absolute_number_of_loss_eliminations_of_short_positions");
const SmarttTerm ABSOLUTE_NUMBER_OF_PROFIT_ELIMINATIONS("absolute_number_of_profit_eliminations");
const SmarttTerm ABSOLUTE_NUMBER_OF_PROFIT_ELIMINATIONS_OF_LONG_POSITIONS("absolute_number_of_profit_eliminations_of_long_positions");
const SmarttTerm ABSOLUTE_NUMBER_OF_PROFIT_ELIMINATIONS_OF_SHORT_POSITIONS("absolute_number_of_profit_eliminations_of_short_positions");
const SmarttTerm ADDRESS("address");
const SmarttTerm AUTO("auto");
const SmarttTerm AUTOMATIC_CONTRIBUTION("automatic_contribution");
const SmarttTerm AVERAGE_LOSS_IN_LOSS_ELIMINATIONS("average_loss_in_loss_eliminations");
const SmarttTerm AVERAGE_NOMINAL_PRICE("average_nominal_price");
const SmarttTerm AVERAGE_PRICE("average_price");
const SmarttTerm AVERAGE_PROFIT_IN_PROFIT_ELIMINATIONS("average_profit_in_profit_eliminations");
const SmarttTerm BALANCE("balance");
const SmarttTerm BIRTHDAY("birthday");
const SmarttTerm BROKERAGE_DIGITAL_SIGNATURE("brokerage_digital_signature");
const SmarttTerm BROKERAGE_ID("brokerage_id");
const SmarttTerm BROKERAGE_LOGIN("brokerage_login");
const SmarttTerm BROKERAGE_PASSWORD("brokerage_password");
const SmarttTerm CANCELED("canceled");
const SmarttTerm CANCELED_BY_CLIENT("canceled_by_client");
const SmarttTerm CANCELED_EXPIRED_OPTION("canceled_expired_option");
const SmarttTerm CANCELED_NOT_ALLOWED_MARKET("canceled_not_allowed_market");
const SmarttTerm CANCELED_NOT_ENOUGH_BALANCE("canceled_not_enough_balance");
const SmarttTerm CANCELED_NOT_POSITIONED("canceled_not_positioned");
const SmarttTerm CANCELED_ORDER_LIMIT_EXCEEDED("canceled_order_limit_exceeded");
const SmarttTerm CITY("city");
const SmarttTerm CODE("code");
const SmarttTerm CODE_UNDERLYING_STOCK("code_underlying_stock");
const SmarttTerm COMPANY("company");
const SmarttTerm COMPANY_NAME("company_name");
const SmarttTerm COMPLEMENT("complement");
const SmarttTerm CONTRIBUTION_OR_WITHDRAWAL("contribution_or_withdrawal");
const SmarttTerm COUNTRY("country");
const SmarttTerm CUSTODY_TAX("custody_tax");
const SmarttTerm DAILY_CUMULATIVE_PERFORMANCE("daily_cumulative_performance");
const SmarttTerm DAILY_DRAWDOWN("daily_drawdown");
const SmarttTerm DATETIME("datetime");
const SmarttTerm DAY_TRADE_INCOME_TAX("day_trade_income_tax");
const SmarttTerm DAY_TRADE_LIQUIDATION_TAX("day_trade_liquidation_tax");
const SmarttTerm DAY_TRADE_OTHER_TAXES("day_trade_other_taxes");
const SmarttTerm DAY_TRADE_REGISTER_TAX("day_trade_register_tax");
const SmarttTerm DAY_TRADE_REGITER_TAX("day_trade_regiter_tax");
const SmarttTerm DAY_TRADE_TRADING_TAX("day_trade_trading_tax");
const SmarttTerm DAY_TRADE_WITHHOLDING_INCOME_TAX("day_trade_withholding_income_tax");
const SmarttTerm DESCRIPTION("description");
const SmarttTerm DIRECT_DEBIT("direct_debit");
const SmarttTerm DOCUMENT("document");
const SmarttTerm EMAIL("email");
const SmarttTerm EQUITY("equity");
const SmarttTerm EVENT_TYPE("event_type");
const SmarttTerm EXECUTED("executed");
const SmarttTerm EXERCISE_PRICE("exercise_price");
const SmarttTerm EXPECTED_PAYOFF("expected_payoff");
const SmarttTerm EXPIRATION_DATE("expiration_date");
const SmarttTerm EXPIRED("expired");
const SmarttTerm FINAL_DATETIME("final_datetime");
const SmarttTerm FINANCIAL_TRANSACTION_ID("financial_transaction_id");
const SmarttTerm FINANCIAL_VOLUME("financial_volume");
const SmarttTerm GENDER("gender");
const SmarttTerm GROSS_ANNUALIZED_RETURN("gross_annualized_return");
const SmarttTerm GROSS_DAILY_RETURN("gross_daily_return");
const SmarttTerm GROSS_LOSS("gross_loss");
const SmarttTerm GROSS_PROFIT("gross_profit");
const SmarttTerm GROSS_RETURN("gross_return");
const SmarttTerm HUNG("hung");
const SmarttTerm HUNG_CANCELLABLE("hung_cancellable");
const SmarttTerm HUNG_PENDING("hung_pending");
const SmarttTerm IGNORE("ignore");
const SmarttTerm INCOME_TAX_COST("income_tax_cost");
const SmarttTerm INCOME_TAX_PAYMENT("income_tax_payment");
const SmarttTerm INITIAL_CAPITAL("initial_capital");
const SmarttTerm INITIAL_DATETIME("initial_datetime");
const SmarttTerm INVESTMENT_CODE("investment_code");
const SmarttTerm IS_REAL("is_real");
const SmarttTerm ISIN_CODE("isin_code");
const SmarttTerm ISS_TAX("iss_tax");
const SmarttTerm ISS_TAX_COST("iss_tax_cost");
const SmarttTerm KIND_OF_QUOTATION("kind_of_quotation");
const SmarttTerm KIND_OF_STOCK("kind_of_stock");
const SmarttTerm LEASE_TAX("lease_tax");
const SmarttTerm LIMIT_PRICE("limit_price");
const SmarttTerm LIQUIDATION_TAX_COST("liquidation_tax_cost");
const SmarttTerm LOGIN("login");
const SmarttTerm MAIN_PHONE("main_phone");
const SmarttTerm MARGIN("margin");
const SmarttTerm MARKET_NAME("market_name");
const SmarttTerm MAXIMUM_CONSECUTIVE_LOSS_ELIMINATIONS("maximum_consecutive_loss_eliminations");
const SmarttTerm MAXIMUM_CONSECUTIVE_PROFIT_ELIMINATIONS("maximum_consecutive_profit_eliminations");
const SmarttTerm MESSAGE("message");
const SmarttTerm NAME("name");
const SmarttTerm NAME_OR_CORPORATE_NAME("name_or_corporate_name");
const SmarttTerm NATURAL_PERSON_OR_LEGAL_PERSON("natural_person_or_legal_person");
const SmarttTerm NEIGHBORHOOD("neighborhood");
const SmarttTerm NET_ANNUALIZED_RETURN("net_annualized_return");
const SmarttTerm NET_DAILY_RETURN("net_daily_return");
const SmarttTerm NET_LOSS("net_loss");
const SmarttTerm NET_PROFIT("net_profit");
const SmarttTerm NET_RETURN("net_return");
const SmarttTerm NEW_BROKERAGE_ID("new_brokerage_id");
const SmarttTerm NEW_CODE("new_code");
const SmarttTerm NEW_LIMIT_PRICE("new_limit_price");
const SmarttTerm NEW_NUMBER_OF_STOCKS("new_number_of_stocks");
const SmarttTerm NEW_PRICE("new_price");
const SmarttTerm NEW_S10I_PASSWORD("new_s10i_password");
const SmarttTerm NEW_STOP_PRICE("new_stop_price");
const SmarttTerm NOMINAL_PRICE("nominal_price");
const SmarttTerm NUMBER("number");
const SmarttTerm NUMBER_OF_DAYS("number_of_days");
const SmarttTerm NUMBER_OF_ELIMINATIONS("number_of_eliminations");
const SmarttTerm NUMBER_OF_EVENTS("number_of_events");
const SmarttTerm NUMBER_OF_STOCKS("number_of_stocks");
const SmarttTerm NUMBER_OF_TRADED_STOCKS("number_of_traded_stocks");
const SmarttTerm OPERATIONAL_TAX_COST("operational_tax_cost");
const SmarttTerm OPTION("option");
const SmarttTerm ORDER_CANCELED("order_canceled");
const SmarttTerm ORDER_CHANGED("order_changed");
const SmarttTerm ORDER_EXECUTED("order_executed");
const SmarttTerm ORDER_EXPIRED("order_expired");
const SmarttTerm ORDER_ID("order_id");
const SmarttTerm ORDER_ID_IN_BROKERAGE("order_id_in_brokerage");
const SmarttTerm ORDER_SENT("order_sent");
const SmarttTerm ORDER_TYPE("order_type");
const SmarttTerm OTHER("other");
const SmarttTerm OTHER_TAXES_COST("other_taxes_cost");
const SmarttTerm PAPER("paper");
const SmarttTerm PARTIALLY_CANCELED("partially_canceled");
const SmarttTerm PARTIALLY_EXECUTED("partially_executed");
const SmarttTerm PARTIALLY_EXECUTED_CANCELLABLE("partially_executed_cancellable");
const SmarttTerm PASSWORD("password");
const SmarttTerm PERCENTUAL_BROKERAGE_TAX("percentual_brokerage_tax");
const SmarttTerm PERCENTUAL_BROKERAGE_TAX_COST("percentual_brokerage_tax_cost");
const SmarttTerm PERCENTUAL_INITIAL_DRAWDOWN("percentual_initial_drawdown");
const SmarttTerm PERCENTUAL_LARGEST__LOSS_ELIMINATION("percentual_largest__loss_elimination");
const SmarttTerm PERCENTUAL_LARGEST__PROFIT_ELIMINATION("percentual_largest__profit_elimination");
const SmarttTerm PERCENTUAL_LARGEST_PROFIT_ELIMINATION("percentual_largest_profit_elimination");
const SmarttTerm PERCENTUAL_MAXIMUM_DRAWDOWN("percentual_maximum_drawdown");
const SmarttTerm PERCENTUAL_NUMBER_OF_ELIMINATIONS_OF_LONG_POSITIONS("percentual_number_of_eliminations_of_long_positions");
const SmarttTerm PERCENTUAL_NUMBER_OF_ELIMINATIONS_OF_SHORT_POSITIONS("percentual_number_of_eliminations_of_short_positions");
const SmarttTerm PERCENTUAL_NUMBER_OF_LOSS_ELIMINATIONS("percentual_number_of_loss_eliminations");
const SmarttTerm PERCENTUAL_NUMBER_OF_LOSS_ELIMINATIONS_OF_LONG_POSITIONS("percentual_number_of_loss_eliminations_of_long_positions");
const SmarttTerm PERCENTUAL_NUMBER_OF_LOSS_ELIMINATIONS_OF_SHORT_POSITIONS("percentual_number_of_loss_eliminations_of_short_positions");
const SmarttTerm PERCENTUAL_NUMBER_OF_PROFIT_ELIMINATIONS("percentual_number_of_profit_eliminations");
const SmarttTerm PERCENTUAL_NUMBER_OF_PROFIT_ELIMINATIONS_OF_LONG_POSITIONS("percentual_number_of_profit_eliminations_of_long_positions");
const SmarttTerm PERCENTUAL_NUMBER_OF_PROFIT_ELIMINATIONS_OF_SHORT_POSITIONS("percentual_number_of_profit_eliminations_of_short_positions");
const SmarttTerm POSITION_INCOME_TAX("position_income_tax");
const SmarttTerm POSITION_LIQUIDATION_TAX("position_liquidation_tax");
const SmarttTerm POSITION_OTHER_TAXES("position_other_taxes");
const SmarttTerm POSITION_REGISTER_TAX("position_register_tax");
const SmarttTerm POSITION_TRADING_TAX("position_trading_tax");
const SmarttTerm POSITION_TYPE("position_type");
const SmarttTerm POSITION_WITHHOLDING_INCOME_TAX("position_withholding_income_tax");
const SmarttTerm POSTAL_CODE("postal_code");
const SmarttTerm PRICE("price");
const SmarttTerm PROFIT_FACTOR("profit_factor");
const SmarttTerm REGISTER_TAX_COST("register_tax_cost");
const SmarttTerm REJECTED("rejected");
const SmarttTerm RETURN_ATTRIBUTES("return_attributes");
const SmarttTerm S10I_LOGIN("s10i_login");
const SmarttTerm S10I_PASSWORD("s10i_password");
const SmarttTerm SECONDARY_PHONE("secondary_phone");
const SmarttTerm SENT("sent");
const SmarttTerm SENT_ORDER_ID("sent_order_id");
const SmarttTerm SETUP_CODE("setup_code");
const SmarttTerm SLIPPAGE("slippage");
const SmarttTerm SPECIFIC_DATE("specific_date");
const SmarttTerm SPOT("spot");
const SmarttTerm STATE("state");
const SmarttTerm STATUS("status");
const SmarttTerm STOCK_CODE("stock_code");
const SmarttTerm STOP_ORDER_CANCELED("stop_order_canceled");
const SmarttTerm STOP_ORDER_EXPIRED("stop_order_expired");
const SmarttTerm STOP_ORDER_ID("stop_order_id");
const SmarttTerm STOP_ORDER_ID_IN_BROKERAGE("stop_order_id_in_brokerage");
const SmarttTerm STOP_ORDER_SENT("stop_order_sent");
const SmarttTerm STOP_ORDER_TRIGGERED("stop_order_triggered");
const SmarttTerm STOP_ORDER_TYPE("stop_order_type");
const SmarttTerm STOP_PRICE("stop_price");
const SmarttTerm TAXES_AND_OPERATIONAL_COSTS("taxes_and_operational_costs");
const SmarttTerm TODAY("today");
const SmarttTerm TOTAL_CONTRIBUTIONS("total_contributions");
const SmarttTerm TOTAL_GROSS_PROFIT("total_gross_profit");
const SmarttTerm TOTAL_LOSS_IN_MAXIMUM_CONSECUTIVE_LOSS_ELIMINATIONS("total_loss_in_maximum_consecutive_loss_eliminations");
const SmarttTerm TOTAL_NET_PROFIT("total_net_profit");
const SmarttTerm TOTAL_PROFIT_IN_MAXIMUM_CONSECUTIVE_PROFIT_ELIMINATONS("total_profit_in_maximum_consecutive_profit_eliminatons");
const SmarttTerm TOTAL_WITHDRAWS("total_withdraws");
const SmarttTerm TRADE_ID_IN_BROKERAGE("trade_id_in_brokerage");
const SmarttTerm TRADE_TYPE("trade_type");
const SmarttTerm TRADING_LOT_SIZE("trading_lot_size");
const SmarttTerm TRADING_TAX_COST("trading_tax_cost");
const SmarttTerm TYPE("type");
const SmarttTerm UNTIL_CANCEL("until_cancel");
const SmarttTerm VALIDITY("validity");
const SmarttTerm VALIDITY_TYPE("validity_type");
const SmarttTerm VALUE("value");
const SmarttTerm WITHHOLDING_INCOME_TAX_COST("withholding_income_tax_cost");
}