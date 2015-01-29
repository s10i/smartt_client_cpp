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
const SmarttTerm BOVESPA("BOVESPA");
const SmarttTerm F("F");
const SmarttTerm M("M");
const SmarttTerm ABSOLUTE_AVERAGE_SIMPLE_PROFIT("absolute_average_simple_profit");
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
const SmarttTerm API_KEY("api_key");
const SmarttTerm AUTO("auto");
const SmarttTerm AVERAGE_LOSS_IN_LOSS_ELIMINATIONS("average_loss_in_loss_eliminations");
const SmarttTerm AVERAGE_NOMINAL_PRICE("average_nominal_price");
const SmarttTerm AVERAGE_PRICE("average_price");
const SmarttTerm AVERAGE_PROFIT_IN_PROFIT_ELIMINATIONS("average_profit_in_profit_eliminations");
const SmarttTerm BALANCE("balance");
const SmarttTerm BIRTHDAY("birthday");
const SmarttTerm BROKERAGE_ID("brokerage_id");
const SmarttTerm BROKERAGE_TAX_COST("brokerage_tax_cost");
const SmarttTerm CANCELED("canceled");
const SmarttTerm CBLC_BMF_CODE("cblc_bmf_code");
const SmarttTerm CBLC_BOVESPA_CODE("cblc_bovespa_code");
const SmarttTerm CHANGED("changed");
const SmarttTerm CITY("city");
const SmarttTerm CODE("code");
const SmarttTerm COMPANY("company");
const SmarttTerm COMPLEMENT("complement");
const SmarttTerm CONTRIBUTION_OR_WITHDRAWAL("contribution_or_withdrawal");
const SmarttTerm CORPORATE_NAME("corporate_name");
const SmarttTerm COUNTRY("country");
const SmarttTerm CUSTODY_TAX("custody_tax");
const SmarttTerm DAILY_CUMULATIVE_PERFORMANCE("daily_cumulative_performance");
const SmarttTerm DAILY_DRAWDOWN("daily_drawdown");
const SmarttTerm DATE("date");
const SmarttTerm DATETIME("datetime");
const SmarttTerm DAY_TRADE_LIQUIDATION_TAX("day_trade_liquidation_tax");
const SmarttTerm DAY_TRADE_OTHER_TAXES("day_trade_other_taxes");
const SmarttTerm DAY_TRADE_REGISTER_TAX("day_trade_register_tax");
const SmarttTerm DAY_TRADE_TRADING_TAX("day_trade_trading_tax");
const SmarttTerm DESCRIPTION("description");
const SmarttTerm DOCUMENT("document");
const SmarttTerm DOLLAR_CONTRACT_DAY_TRADE_BROKERAGE_TAX("dollar_contract_day_trade_brokerage_tax");
const SmarttTerm DOLLAR_MINI_DAY_TRADE_BROKERAGE_TAX("dollar_mini_day_trade_brokerage_tax");
const SmarttTerm EMAIL("email");
const SmarttTerm ENTRY("entry");
const SmarttTerm ENTRY_EXIT_OR_REVERSAL("entry_exit_or_reversal");
const SmarttTerm EQUITY("equity");
const SmarttTerm EVENT_TYPE("event_type");
const SmarttTerm EXECUTED("executed");
const SmarttTerm EXIT("exit");
const SmarttTerm EXPECTED_PAYOFF("expected_payoff");
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
const SmarttTerm HAS_CUSTOMIZED_STRATEGIES("has_customized_strategies");
const SmarttTerm HUNG("hung");
const SmarttTerm IBOV_CONTRACT_DAY_TRADE_BROKERAGE_TAX("ibov_contract_day_trade_brokerage_tax");
const SmarttTerm IBOV_MINI_DAY_TRADE_BROKERAGE_TAX("ibov_mini_day_trade_brokerage_tax");
const SmarttTerm ID("id");
const SmarttTerm INCOME_TAX_COST("income_tax_cost");
const SmarttTerm INITIAL_CAPITAL("initial_capital");
const SmarttTerm INITIAL_DATETIME("initial_datetime");
const SmarttTerm INVESTMENT_CODE("investment_code");
const SmarttTerm IP_CLIENT_PARAMS_SAVED("ip_client_params_saved");
const SmarttTerm IP_CLIENT_STRATEGY_START("ip_client_strategy_start");
const SmarttTerm IP_USED_TO_SIGN_UP("ip_used_to_sign_up");
const SmarttTerm IS_ACTIVE("is_active");
const SmarttTerm IS_MARKET_ORDER("is_market_order");
const SmarttTerm IS_REAL("is_real");
const SmarttTerm ISS_TAX("iss_tax");
const SmarttTerm ISS_TAX_COST("iss_tax_cost");
const SmarttTerm LIMIT("limit");
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
const SmarttTerm NUMBER_OF_FINANCIAL_TRANSACTIONS("number_of_financial_transactions");
const SmarttTerm NUMBER_OF_ORDERS("number_of_orders");
const SmarttTerm NUMBER_OF_ORDERS_EVENTS("number_of_orders_events");
const SmarttTerm NUMBER_OF_STOCKS("number_of_stocks");
const SmarttTerm NUMBER_OF_STOP_ORDERS("number_of_stop_orders");
const SmarttTerm NUMBER_OF_STOP_ORDERS_EVENTS("number_of_stop_orders_events");
const SmarttTerm NUMBER_OF_TRADED_STOCKS("number_of_traded_stocks");
const SmarttTerm NUMBER_OF_TRADES("number_of_trades");
const SmarttTerm OFFSET("offset");
const SmarttTerm OPERATIONAL_LIMIT("operational_limit");
const SmarttTerm OPERATIONAL_TAX_COST("operational_tax_cost");
const SmarttTerm OPTION("option");
const SmarttTerm OPTION_ABSOLUTE_BROKERAGE_TAX("option_absolute_brokerage_tax");
const SmarttTerm OPTION_PERCENTUAL_BROKERAGE_TAX("option_percentual_brokerage_tax");
const SmarttTerm ORDER_CANCEL_REJECTED("order_cancel_rejected");
const SmarttTerm ORDER_CANCELED("order_canceled");
const SmarttTerm ORDER_CHANGE_REJECTED("order_change_rejected");
const SmarttTerm ORDER_CHANGED("order_changed");
const SmarttTerm ORDER_EXECUTED("order_executed");
const SmarttTerm ORDER_EXPIRED("order_expired");
const SmarttTerm ORDER_ID("order_id");
const SmarttTerm ORDER_ID_IN_BROKERAGE("order_id_in_brokerage");
const SmarttTerm ORDER_RECEIVED("order_received");
const SmarttTerm ORDER_REJECTED("order_rejected");
const SmarttTerm ORDER_SENT("order_sent");
const SmarttTerm ORDER_SET_TO_PREVIOUS_FINAL_STATE("order_set_to_previous_final_state");
const SmarttTerm ORDER_SUSPENDED("order_suspended");
const SmarttTerm ORDER_TYPE("order_type");
const SmarttTerm OTHER_ABSOLUTE_BROKERAGE_TAX("other_absolute_brokerage_tax");
const SmarttTerm OTHER_PERCENTUAL_BROKERAGE_TAX("other_percentual_brokerage_tax");
const SmarttTerm OTHER_TAXES_COST("other_taxes_cost");
const SmarttTerm PAPER("paper");
const SmarttTerm PARTIALLY_EXECUTED("partially_executed");
const SmarttTerm PASSWORD("password");
const SmarttTerm PENDING_CANCEL("pending_cancel");
const SmarttTerm PENDING_CHANGE("pending_change");
const SmarttTerm PENDING_HUNG("pending_hung");
const SmarttTerm PERCENTUAL_AVERAGE_SIMPLE_PROFIT("percentual_average_simple_profit");
const SmarttTerm PERCENTUAL_INITIAL_DRAWDOWN("percentual_initial_drawdown");
const SmarttTerm PERCENTUAL_LARGEST_LOSS_ELIMINATION("percentual_largest_loss_elimination");
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
const SmarttTerm PLAN("plan");
const SmarttTerm PLAN_EXPIRATION_DATE("plan_expiration_date");
const SmarttTerm POSITION_LIQUIDATION_TAX("position_liquidation_tax");
const SmarttTerm POSITION_OTHER_TAXES("position_other_taxes");
const SmarttTerm POSITION_REGISTER_TAX("position_register_tax");
const SmarttTerm POSITION_TRADING_TAX("position_trading_tax");
const SmarttTerm POSITION_TYPE("position_type");
const SmarttTerm POSTAL_CODE("postal_code");
const SmarttTerm PREVIOUS_FINAL_STATE("previous_final_state");
const SmarttTerm PRICE("price");
const SmarttTerm PROFIT_FACTOR("profit_factor");
const SmarttTerm REASON("reason");
const SmarttTerm RECEIVED("received");
const SmarttTerm REGISTER_TAX_COST("register_tax_cost");
const SmarttTerm REGISTRATION_DATETIME("registration_datetime");
const SmarttTerm REJECTED("rejected");
const SmarttTerm RETURN_ATTRIBUTES("return_attributes");
const SmarttTerm REVERSAL("reversal");
const SmarttTerm S10I_LOGIN("s10i_login");
const SmarttTerm S10I_PASSWORD("s10i_password");
const SmarttTerm SECONDARY_PHONE("secondary_phone");
const SmarttTerm SENT_ORDER_ID("sent_order_id");
const SmarttTerm SETUP_CODE("setup_code");
const SmarttTerm SPECIFIC_DATE("specific_date");
const SmarttTerm SPOT("spot");
const SmarttTerm SPOT_ABSOLUTE_BROKERAGE_TAX("spot_absolute_brokerage_tax");
const SmarttTerm SPOT_PERCENTUAL_BROKERAGE_TAX("spot_percentual_brokerage_tax");
const SmarttTerm STATE("state");
const SmarttTerm STATUS("status");
const SmarttTerm STOCK_CODE("stock_code");
const SmarttTerm STOP_ORDER_CANCEL_REJECTED("stop_order_cancel_rejected");
const SmarttTerm STOP_ORDER_CANCELED("stop_order_canceled");
const SmarttTerm STOP_ORDER_CHANGE_REJECTED("stop_order_change_rejected");
const SmarttTerm STOP_ORDER_CHANGED("stop_order_changed");
const SmarttTerm STOP_ORDER_EXPIRED("stop_order_expired");
const SmarttTerm STOP_ORDER_ID("stop_order_id");
const SmarttTerm STOP_ORDER_ID_IN_BROKERAGE("stop_order_id_in_brokerage");
const SmarttTerm STOP_ORDER_RECEIVED("stop_order_received");
const SmarttTerm STOP_ORDER_REJECTED("stop_order_rejected");
const SmarttTerm STOP_ORDER_SENT("stop_order_sent");
const SmarttTerm STOP_ORDER_SET_TO_PREVIOUS_FINAL_STATE("stop_order_set_to_previous_final_state");
const SmarttTerm STOP_ORDER_SUSPENDED("stop_order_suspended");
const SmarttTerm STOP_ORDER_TRIGGERED("stop_order_triggered");
const SmarttTerm STOP_ORDER_TYPE("stop_order_type");
const SmarttTerm STOP_PRICE("stop_price");
const SmarttTerm STRATEGY_ID("strategy_id");
const SmarttTerm SUSPENDED("suspended");
const SmarttTerm TAXES_AND_OPERATIONAL_COSTS("taxes_and_operational_costs");
const SmarttTerm TODAY("today");
const SmarttTerm TOTAL_CONTRIBUTIONS("total_contributions");
const SmarttTerm TOTAL_GROSS_PROFIT("total_gross_profit");
const SmarttTerm TOTAL_LOSS_IN_MAXIMUM_CONSECUTIVE_LOSS_ELIMINATIONS("total_loss_in_maximum_consecutive_loss_eliminations");
const SmarttTerm TOTAL_NET_PROFIT("total_net_profit");
const SmarttTerm TOTAL_PROFIT_IN_MAXIMUM_CONSECUTIVE_PROFIT_ELIMINATIONS("total_profit_in_maximum_consecutive_profit_eliminations");
const SmarttTerm TOTAL_WITHDRAWS("total_withdraws");
const SmarttTerm TRADE_ID_IN_BROKERAGE("trade_id_in_brokerage");
const SmarttTerm TRADE_TYPE("trade_type");
const SmarttTerm TRADING_SYSTEM_CODE("trading_system_code");
const SmarttTerm TRADING_TAX_COST("trading_tax_cost");
const SmarttTerm TRIGGERED("triggered");
const SmarttTerm TRIGGERED_STOP_ORDER_ID("triggered_stop_order_id");
const SmarttTerm UNTIL_CANCEL("until_cancel");
const SmarttTerm VALIDITY("validity");
const SmarttTerm VALIDITY_TYPE("validity_type");
const SmarttTerm VALUE("value");
const SmarttTerm WITHHOLDING_INCOME_TAX_COST("withholding_income_tax_cost");
}