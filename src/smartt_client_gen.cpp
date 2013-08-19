const std::vector<std::string> login_attributes = {
    "message"
};

std::string SmarttClient::login(std::string s10iLogin, std::string s10iPassword)
{
    std::vector<string> message;
    message.push_back("login");
    appendStringParameter(message, "s10i_login", s10iLogin, false);
    appendStringParameter(message, "s10i_password", s10iPassword, false);
    std::vector<std::string> response = smarttFunction(message);
    return lexical_cast<std::string>(response[0]);
}


const std::vector<std::string> logout_attributes = {
    "message"
};

std::string SmarttClient::logout()
{
    std::vector<string> message;
    message.push_back("logout");
    std::vector<std::string> response = smarttFunction(message);
    return lexical_cast<std::string>(response[0]);
}


const std::vector<std::string> logged_attributes = {
    "message"
};

std::string SmarttClient::logged()
{
    std::vector<string> message;
    message.push_back("logged");
    std::vector<std::string> response = smarttFunction(message);
    return lexical_cast<std::string>(response[0]);
}


const std::vector<std::string> get_client_attributes = {
    "natural_person_or_legal_person",
    "name_or_corporate_name",
    "gender",
    "document",
    "email",
    "s10i_login",
    "address",
    "number",
    "complement",
    "neighborhood",
    "postal_code",
    "city",
    "state",
    "country",
    "birthday",
    "main_phone",
    "secondary_phone",
    "company"
};

std::map<std::string, std::string> SmarttClient::getClient(std::vector<std::string> returnAttributes)
{
    std::vector<string> message;
    message.push_back("get_client");
    appendAttributes(message, returnAttributes, get_client_attributes);
    std::vector<std::string> response = smarttFunction(message);
    return formatMapResponse(response, returnAttributes, get_client_attributes);
}


const std::vector<std::string> update_client_attributes = {
    "message"
};

std::string SmarttClient::updateClient(std::string s10iPassword, bool naturalPersonOrLegalPerson, std::string nameOrCorporateName, char gender, int document, std::string email, std::string s10iLogin, std::string newS10iPassword, std::string address, std::string number, std::string complement, std::string neighborhood, std::string postalCode, std::string city, std::string state, std::string country, std::string birthday, std::string mainPhone, std::string secondaryPhone, std::string company)
{
    std::vector<string> message;
    message.push_back("update_client");
    appendStringParameter(message, "s10i_password", s10iPassword, true);
    appendBooleanParameter(message, "natural_person_or_legal_person", naturalPersonOrLegalPerson);
    appendStringParameter(message, "name_or_corporate_name", nameOrCorporateName, true);
    appendCharParameter(message, "gender", gender, true);
    appendUnsignedIntegerParameter(message, "document", document, false);
    appendStringParameter(message, "email", email, false);
    appendStringParameter(message, "s10i_login", s10iLogin, false);
    appendStringParameter(message, "new_s10i_password", newS10iPassword, true);
    appendStringParameter(message, "address", address, true);
    appendStringParameter(message, "number", number, true);
    appendStringParameter(message, "complement", complement, true);
    appendStringParameter(message, "neighborhood", neighborhood, true);
    appendStringParameter(message, "postal_code", postalCode, true);
    appendStringParameter(message, "city", city, true);
    appendStringParameter(message, "state", state, true);
    appendStringParameter(message, "country", country, true);
    appendDateParameter(message, "birthday", birthday, true);
    appendStringParameter(message, "main_phone", mainPhone, true);
    appendStringParameter(message, "secondary_phone", secondaryPhone, true);
    appendStringParameter(message, "company", company, true);
    std::vector<std::string> response = smarttFunction(message);
    return lexical_cast<std::string>(response[0]);
}


const std::vector<std::string> get_client_brokerages_attributes = {
    "brokerage_id",
    "brokerage_login"
};

std::map<std::string, std::string> SmarttClient::getClientBrokerages(int brokerageId, std::string brokerageLogin, std::vector<std::string> returnAttributes)
{
    std::vector<string> message;
    message.push_back("get_client_brokerages");
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, true);
    appendStringParameter(message, "brokerage_login", brokerageLogin, true);
    appendAttributes(message, returnAttributes, get_client_brokerages_attributes);
    std::vector<std::string> response = smarttFunction(message);
    return formatMapResponse(response, returnAttributes, get_client_brokerages_attributes);
}


const std::vector<std::string> insert_client_brokerage_attributes = {
    "message"
};

std::string SmarttClient::insertClientBrokerage(int brokerageId, std::string brokerageLogin, std::string brokeragePassword, std::string brokerageDigitalSignature)
{
    std::vector<string> message;
    message.push_back("insert_client_brokerage");
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, false);
    appendStringParameter(message, "brokerage_login", brokerageLogin, false);
    appendStringParameter(message, "brokerage_password", brokeragePassword, false);
    appendStringParameter(message, "brokerage_digital_signature", brokerageDigitalSignature, false);
    std::vector<std::string> response = smarttFunction(message);
    return lexical_cast<std::string>(response[0]);
}


const std::vector<std::string> update_client_brokerage_attributes = {
    "message"
};

std::string SmarttClient::updateClientBrokerage(int brokerageId, int newBrokerageId, std::string brokerageLogin, std::string brokeragePassword, std::string brokerageDigiralSignature)
{
    std::vector<string> message;
    message.push_back("update_client_brokerage");
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, false);
    appendUnsignedIntegerParameter(message, "new_brokerage_id", newBrokerageId, true);
    appendStringParameter(message, "brokerage_login", brokerageLogin, true);
    appendStringParameter(message, "brokerage_password", brokeragePassword, true);
    appendStringParameter(message, "brokerage_digiral_signature", brokerageDigiralSignature, true);
    std::vector<std::string> response = smarttFunction(message);
    return lexical_cast<std::string>(response[0]);
}


const std::vector<std::string> delete_client_brokerages_attributes = {
    "message"
};

std::string SmarttClient::deleteClientBrokerages(int brokerageId, std::string brokerageLogin)
{
    std::vector<string> message;
    message.push_back("delete_client_brokerages");
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, true);
    appendStringParameter(message, "brokerage_login", brokerageLogin, true);
    std::vector<std::string> response = smarttFunction(message);
    return lexical_cast<std::string>(response[0]);
}


const std::vector<std::string> get_stock_attributes = {
    "stock_code",
    "market_name",
    "company_name",
    "kind_of_stock",
    "isin_code",
    "trading_lot_size",
    "kind_of_quotation",
    "type",
    "code_underlying_stock",
    "exercise_price",
    "expiration_date"
};

std::map<std::string, std::string> SmarttClient::getStock(std::string stockCode, std::string marketName, std::vector<std::string> returnAttributes)
{
    std::vector<string> message;
    message.push_back("get_stock");
    appendStringParameter(message, "stock_code", stockCode, false);
    appendStringParameter(message, "market_name", marketName, true);
    appendAttributes(message, returnAttributes, get_stock_attributes);
    std::vector<std::string> response = smarttFunction(message);
    return formatMapResponse(response, returnAttributes, get_stock_attributes);
}


const std::vector<std::string> send_order_attributes = {
    "order_id"
};

int SmarttClient::sendOrder(std::string investmentCode, int brokerageId, bool orderType, std::string stockCode, std::string marketName, int numberOfStocks, double price, std::string validityType, std::string validity)
{
    std::vector<string> message;
    message.push_back("send_order");
    appendStringParameter(message, "investment_code", investmentCode, false);
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, true);
    appendBooleanParameter(message, "order_type", orderType);
    appendStringParameter(message, "stock_code", stockCode, false);
    appendStringParameter(message, "market_name", marketName, true);
    appendUnsignedIntegerParameter(message, "number_of_stocks", numberOfStocks, false);
    appendFloatParameter(message, "price", price, false);
    appendStringParameter(message, "validity_type", validityType, true);
    appendDateParameter(message, "validity", validity, true);
    std::vector<std::string> response = smarttFunction(message);
    return lexical_cast<int>(response[1]);
}


const std::vector<std::string> cancel_order_attributes = {
    "order_id"
};

int SmarttClient::cancelOrder(int orderId)
{
    std::vector<string> message;
    message.push_back("cancel_order");
    appendUnsignedIntegerParameter(message, "order_id", orderId, false);
    std::vector<std::string> response = smarttFunction(message);
    return lexical_cast<int>(response[1]);
}


const std::vector<std::string> change_order_attributes = {
    "order_id"
};

int SmarttClient::changeOrder(int orderId, int newNumberOfStocks, double newPrice)
{
    std::vector<string> message;
    message.push_back("change_order");
    appendUnsignedIntegerParameter(message, "order_id", orderId, false);
    appendUnsignedIntegerParameter(message, "new_number_of_stocks", newNumberOfStocks, true);
    appendFloatParameter(message, "new_price", newPrice, true);
    std::vector<std::string> response = smarttFunction(message);
    return lexical_cast<int>(response[1]);
}


const std::vector<std::string> get_orders_attributes = {
    "order_id",
    "order_id_in_brokerage",
    "investment_code",
    "brokerage_id",
    "is_real",
    "order_type",
    "stock_code",
    "market_name",
    "datetime",
    "number_of_stocks",
    "price",
    "financial_volume",
    "validity_type",
    "validity",
    "number_of_traded_stocks",
    "average_nominal_price",
    "status",
    "absolute_brokerage_tax_cost",
    "percentual_brokerage_tax_cost",
    "iss_tax_cost"
};

std::vector<std::map<std::string, std::string> > SmarttClient::getOrders(int orderId, std::string investmentCode, int brokerageId, std::string initialDatetime, std::string finalDatetime, std::string status, std::vector<std::string> returnAttributes)
{
    std::vector<string> message;
    message.push_back("get_orders");
    appendUnsignedIntegerParameter(message, "order_id", orderId, true);
    appendStringParameter(message, "investment_code", investmentCode, true);
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, true);
    appendDatetimeParameter(message, "initial_datetime", initialDatetime, true);
    appendDatetimeParameter(message, "final_datetime", finalDatetime, true);
    appendStringParameter(message, "status", status, true);
    appendAttributes(message, returnAttributes, get_orders_attributes);
    std::vector<std::string> response = smarttFunction(message);
    return formatListOfMapsResponse(response, 0, response.size() - 0, returnAttributes, get_orders_attributes);
}


const std::vector<std::string> get_orders_events_attributes = {
    "order_id",
    "investment_code",
    "brokerage_id",
    "number_of_events",
    "datetime",
    "event_type",
    "description"
};

std::vector<std::map<std::string, std::string> > SmarttClient::getOrdersEvents(int orderId, std::string investmentCode, int brokerageId, std::string initialDatetime, std::string finalDatetime, std::string eventType, std::vector<std::string> returnAttributes)
{
    std::vector<string> message;
    message.push_back("get_orders_events");
    appendUnsignedIntegerParameter(message, "order_id", orderId, true);
    appendStringParameter(message, "investment_code", investmentCode, true);
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, true);
    appendDatetimeParameter(message, "initial_datetime", initialDatetime, true);
    appendDatetimeParameter(message, "final_datetime", finalDatetime, true);
    appendStringParameter(message, "event_type", eventType, true);
    appendAttributes(message, returnAttributes, get_orders_events_attributes);
    std::vector<std::string> response = smarttFunction(message);
    return formatListOfMapsResponse(response, 0, response.size() - 0, returnAttributes, get_orders_events_attributes);
}


const std::vector<std::string> get_order_id_attributes = {
    "order_id"
};

int SmarttClient::getOrderId(std::string orderIdInBrokerage, int brokerageId)
{
    std::vector<string> message;
    message.push_back("get_order_id");
    appendStringParameter(message, "order_id_in_brokerage", orderIdInBrokerage, false);
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, false);
    std::vector<std::string> response = smarttFunction(message);
    return lexical_cast<int>(response[0]);
}


const std::vector<std::string> send_stop_order_attributes = {
    "stop_order_id"
};

int SmarttClient::sendStopOrder(std::string investmentCode, int brokerageId, bool orderType, bool stopOrderType, std::string stockCode, std::string marketName, int numberOfStocks, double stopPrice, double limitPrice, std::string validity, bool validAfterMarket)
{
    std::vector<string> message;
    message.push_back("send_stop_order");
    appendStringParameter(message, "investment_code", investmentCode, false);
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, true);
    appendBooleanParameter(message, "order_type", orderType);
    appendBooleanParameter(message, "stop_order_type", stopOrderType);
    appendStringParameter(message, "stock_code", stockCode, false);
    appendStringParameter(message, "market_name", marketName, true);
    appendUnsignedIntegerParameter(message, "number_of_stocks", numberOfStocks, false);
    appendFloatParameter(message, "stop_price", stopPrice, false);
    appendFloatParameter(message, "limit_price", limitPrice, false);
    appendDateParameter(message, "validity", validity, false);
    appendBooleanParameter(message, "valid_after_market", validAfterMarket);
    std::vector<std::string> response = smarttFunction(message);
    return lexical_cast<int>(response[1]);
}


const std::vector<std::string> cancel_stop_order_attributes = {
    "stop_order_id"
};

int SmarttClient::cancelStopOrder(int stopOrderId)
{
    std::vector<string> message;
    message.push_back("cancel_stop_order");
    appendUnsignedIntegerParameter(message, "stop_order_id", stopOrderId, false);
    std::vector<std::string> response = smarttFunction(message);
    return lexical_cast<int>(response[1]);
}


const std::vector<std::string> get_stop_orders_attributes = {
    "stop_order_id",
    "order_id_in_brokerage",
    "investment_code",
    "brokerage_id",
    "is_real",
    "order_type",
    "stop_order_type",
    "stock_code",
    "market_name",
    "datetime",
    "number_of_stocks",
    "stop_price",
    "limit_price",
    "validity",
    "valid_after_market",
    "status",
    "sent_order_id"
};

std::vector<std::map<std::string, std::string> > SmarttClient::getStopOrders(int stopOrderId, std::string investmentCode, int brokerageId, std::string initialDatetime, std::string finalDatetime, std::string status, std::vector<std::string> returnAttributes)
{
    std::vector<string> message;
    message.push_back("get_stop_orders");
    appendUnsignedIntegerParameter(message, "stop_order_id", stopOrderId, true);
    appendStringParameter(message, "investment_code", investmentCode, true);
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, true);
    appendDatetimeParameter(message, "initial_datetime", initialDatetime, true);
    appendDatetimeParameter(message, "final_datetime", finalDatetime, true);
    appendStringParameter(message, "status", status, true);
    appendAttributes(message, returnAttributes, get_stop_orders_attributes);
    std::vector<std::string> response = smarttFunction(message);
    return formatListOfMapsResponse(response, 0, response.size() - 0, returnAttributes, get_stop_orders_attributes);
}


const std::vector<std::string> get_stop_orders_events_attributes = {
    "stop_order_id",
    "investment_code",
    "brokerage_id",
    "number_of_events",
    "datetime",
    "event_type",
    "description"
};

std::vector<std::map<std::string, std::string> > SmarttClient::getStopOrdersEvents(int stopOrderId, std::string investmentCode, int brokerageId, std::string initialDatetime, std::string finalDatetime, std::string eventType, std::vector<std::string> returnAttributes)
{
    std::vector<string> message;
    message.push_back("get_stop_orders_events");
    appendUnsignedIntegerParameter(message, "stop_order_id", stopOrderId, true);
    appendStringParameter(message, "investment_code", investmentCode, true);
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, true);
    appendDatetimeParameter(message, "initial_datetime", initialDatetime, true);
    appendDatetimeParameter(message, "final_datetime", finalDatetime, true);
    appendStringParameter(message, "event_type", eventType, true);
    appendAttributes(message, returnAttributes, get_stop_orders_events_attributes);
    std::vector<std::string> response = smarttFunction(message);
    return formatListOfMapsResponse(response, 0, response.size() - 0, returnAttributes, get_stop_orders_events_attributes);
}


const std::vector<std::string> get_stop_order_id_attributes = {
    "stop_order_id"
};

int SmarttClient::getStopOrderId(std::string stopOrderIdInBrokerage, int brokerageId)
{
    std::vector<string> message;
    message.push_back("get_stop_order_id");
    appendStringParameter(message, "stop_order_id_in_brokerage", stopOrderIdInBrokerage, false);
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, false);
    std::vector<std::string> response = smarttFunction(message);
    return lexical_cast<int>(response[0]);
}


const std::vector<std::string> get_trades_attributes = {
    "order_id",
    "trade_id_in_brokerage",
    "investment_code",
    "brokerage_id",
    "is_real",
    "trade_type",
    "stock_code",
    "market_name",
    "datetime",
    "number_of_stocks",
    "price",
    "financial_volume",
    "trading_tax_cost",
    "liquidation_tax_cost",
    "register_tax_cost",
    "income_tax_cost",
    "withholding_income_tax_cost",
    "other_taxes_cost"
};

std::vector<std::map<std::string, std::string> > SmarttClient::getTrades(int orderId, std::string investmentCode, int brokerageId, std::string initialDatetime, std::string finalDatetime, std::vector<std::string> returnAttributes)
{
    std::vector<string> message;
    message.push_back("get_trades");
    appendUnsignedIntegerParameter(message, "order_id", orderId, true);
    appendStringParameter(message, "investment_code", investmentCode, true);
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, false);
    appendDatetimeParameter(message, "initial_datetime", initialDatetime, true);
    appendDatetimeParameter(message, "final_datetime", finalDatetime, true);
    appendAttributes(message, returnAttributes, get_trades_attributes);
    std::vector<std::string> response = smarttFunction(message);
    return formatListOfMapsResponse(response, 0, response.size() - 0, returnAttributes, get_trades_attributes);
}


const std::vector<std::string> get_investments_attributes = {
    "name",
    "code",
    "brokerage_id",
    "setup_code",
    "is_real",
    "initial_datetime",
    "final_datetime"
};

std::map<std::string, std::string> SmarttClient::getInvestments(std::string investmentCode, int brokerageId, std::vector<std::string> returnAttributes)
{
    std::vector<string> message;
    message.push_back("get_investments");
    appendStringParameter(message, "investment_code", investmentCode, true);
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, false);
    appendAttributes(message, returnAttributes, get_investments_attributes);
    std::vector<std::string> response = smarttFunction(message);
    return formatMapResponse(response, returnAttributes, get_investments_attributes);
}


const std::vector<std::string> get_report_attributes = {
    "investment_code",
    "brokerage_id",
    "setup_code",
    "initial_datetime",
    "final_datetime",
    "number_of_days",
    "total_contributions",
    "total_withdraws",
    "initial_capital",
    "balance",
    "equity",
    "taxes_and_operational_costs",
    "gross_return",
    "gross_daily_return",
    "gross_annualized_return",
    "net_return",
    "net_daily_return",
    "net_annualized_return",
    "absolute_initial_drawdown",
    "percentual_initial_drawdown",
    "absolute_maximum_drawdown",
    "percentual_maximum_drawdown",
    "gross_profit",
    "gross_loss",
    "total_gross_profit",
    "net_profit",
    "net_loss",
    "total_net_profit",
    "profit_factor",
    "number_of_eliminations",
    "expected_payoff",
    "absolute_number_of_profit_eliminations",
    "percentual_number_of_profit_eliminations",
    "absolute_largest_profit_elimination",
    "percentual_largest__profit_elimination",
    "average_profit_in_profit_eliminations",
    "maximum_consecutive_profit_eliminations",
    "total_profit_in_maximum_consecutive_profit_eliminatons",
    "absolute_number_of_loss_eliminations",
    "percentual_number_of_loss_eliminations",
    "absolute_largest_loss_elimination",
    "percentual_largest__loss_elimination",
    "average_loss_in_loss_eliminations",
    "maximum_consecutive_loss_eliminations",
    "total_loss_in_maximum_consecutive_loss_eliminations",
    "absolute_number_of_eliminations_of_long_positions",
    "percentual_number_of_eliminations_of_long_positions",
    "absolute_number_of_profit_eliminations_of_long_positions",
    "percentual_number_of_profit_eliminations_of_long_positions",
    "absolute_number_of_loss_eliminations_of_long_positions",
    "percentual_number_of_loss_eliminations_of_long_positions",
    "absolute_number_of_eliminations_of_short_positions",
    "percentual_number_of_eliminations_of_short_positions",
    "absolute_number_of_profit_eliminations_of_short_positions",
    "percentual_number_of_profit_eliminations_of_short_positions",
    "absolute_number_of_loss_eliminations_of_short_positions",
    "percentual_number_of_loss_eliminations_of_short_positions"
};

std::map<std::string, std::string> SmarttClient::getReport(std::string investmentCode, int brokerageId, std::vector<std::string> returnAttributes)
{
    std::vector<string> message;
    message.push_back("get_report");
    appendStringParameter(message, "investment_code", investmentCode, false);
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, true);
    appendAttributes(message, returnAttributes, get_report_attributes);
    std::vector<std::string> response = smarttFunction(message);
    return formatMapResponse(response, returnAttributes, get_report_attributes);
}


const std::vector<std::string> get_daily_cumulative_performance_attributes = {
    "investment_code",
    "brokerage_id",
    "daily_cumulative_performance"
};

std::map<std::string, std::string> SmarttClient::getDailyCumulativePerformance(std::string investmentCode, int brokerageId)
{
    std::vector<string> message;
    message.push_back("get_daily_cumulative_performance");
    appendStringParameter(message, "investment_code", investmentCode, false);
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, true);
    std::vector<std::string> response = smarttFunction(message);
    return formatMapResponse(response, get_daily_cumulative_performance_attributes, get_daily_cumulative_performance_attributes);
}


const std::vector<std::string> get_daily_drawdown_attributes = {
    "investment_code",
    "brokerage_id",
    "daily_drawdown"
};

std::map<std::string, std::string> SmarttClient::getDailyDrawdown(std::string investmentCode, int brokerageId)
{
    std::vector<string> message;
    message.push_back("get_daily_drawdown");
    appendStringParameter(message, "investment_code", investmentCode, false);
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, true);
    std::vector<std::string> response = smarttFunction(message);
    return formatMapResponse(response, get_daily_drawdown_attributes, get_daily_drawdown_attributes);
}


const std::vector<std::string> get_portfolio_attributes = {
    "investment_code",
    "brokerage_id",
    "stock_code",
    "position_type",
    "number_of_stocks",
    "average_price",
    "financial_volume"
};

std::vector<std::map<std::string, std::string> > SmarttClient::getPortfolio(std::string investmentCode, int brokerageId, std::vector<std::string> returnAttributes)
{
    std::vector<string> message;
    message.push_back("get_portfolio");
    appendStringParameter(message, "investment_code", investmentCode, false);
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, true);
    appendAttributes(message, returnAttributes, get_portfolio_attributes);
    std::vector<std::string> response = smarttFunction(message);
    return formatListOfMapsResponse(response, 2, response.size() - 2, returnAttributes, get_portfolio_attributes);
}


const std::vector<std::string> get_available_limits_attributes = {
    "spot",
    "option",
    "margin"
};

std::vector<std::map<std::string, std::string> > SmarttClient::getAvailableLimits(std::string investmentCode, int brokerageId, std::vector<std::string> returnAttributes)
{
    std::vector<string> message;
    message.push_back("get_available_limits");
    appendStringParameter(message, "investment_code", investmentCode, true);
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, true);
    appendAttributes(message, returnAttributes, get_available_limits_attributes);
    std::vector<std::string> response = smarttFunction(message);
    return formatListOfMapsResponse(response, 0, response.size() - 0, returnAttributes, get_available_limits_attributes);
}


const std::vector<std::string> get_setups_attributes = {
    "name",
    "code",
    "initial_capital",
    "slippage",
    "absolute_brokerage_tax",
    "percentual_brokerage_tax",
    "position_trading_tax",
    "position_liquidation_tax",
    "position_register_tax",
    "position_income_tax",
    "position_withholding_income_tax",
    "position_other_taxes",
    "day_trade_trading_tax",
    "day_trade_liquidation_tax",
    "day_trade_regiter_tax",
    "day_trade_income_tax",
    "day_trade_withholding_income_tax",
    "day_trade_other_taxes",
    "iss_tax",
    "custody_tax",
    "lease_tax",
    "income_tax_payment"
};

std::map<std::string, std::string> SmarttClient::getSetups(std::string code, std::vector<std::string> returnAttributes)
{
    std::vector<string> message;
    message.push_back("get_setups");
    appendStringParameter(message, "code", code, true);
    appendAttributes(message, returnAttributes, get_setups_attributes);
    std::vector<std::string> response = smarttFunction(message);
    return formatMapResponse(response, returnAttributes, get_setups_attributes);
}


const std::vector<std::string> update_setup_attributes = {
    "message"
};

std::string SmarttClient::updateSetup(std::string code, std::string name, std::string newCode, std::string initialCapital, double slippage, double absoluteBrokerageTax, double percentualBrokerageTax, double positionTradingTax, double positionLiquidationTax, double positionRegisterTax, double positionIncomeTax, double positionWithholdingIncomeTax, double positionOtherTaxes, double dayTradeTradingTax, double dayTradeLiquidationTax, double dayTradeRegiterTax, double dayTradeIncomeTax, double dayTradeWithholdingIncomeTax, double dayTradeOtherTaxes, double issTax, double custodyTax, double leaseTax, std::string incomeTaxPayment)
{
    std::vector<string> message;
    message.push_back("update_setup");
    appendStringParameter(message, "code", code, false);
    appendStringParameter(message, "name", name, true);
    appendStringParameter(message, "new_code", newCode, true);
    appendStringParameter(message, "initial_capital", initialCapital, true);
    appendFloatParameter(message, "slippage", slippage, true);
    appendFloatParameter(message, "absolute_brokerage_tax", absoluteBrokerageTax, true);
    appendFloatParameter(message, "percentual_brokerage_tax", percentualBrokerageTax, true);
    appendFloatParameter(message, "position_trading_tax", positionTradingTax, true);
    appendFloatParameter(message, "position_liquidation_tax", positionLiquidationTax, true);
    appendFloatParameter(message, "position_register_tax", positionRegisterTax, true);
    appendFloatParameter(message, "position_income_tax", positionIncomeTax, true);
    appendFloatParameter(message, "position_withholding_income_tax", positionWithholdingIncomeTax, true);
    appendFloatParameter(message, "position_other_taxes", positionOtherTaxes, true);
    appendFloatParameter(message, "day_trade_trading_tax", dayTradeTradingTax, true);
    appendFloatParameter(message, "day_trade_liquidation_tax", dayTradeLiquidationTax, true);
    appendFloatParameter(message, "day_trade_regiter_tax", dayTradeRegiterTax, true);
    appendFloatParameter(message, "day_trade_income_tax", dayTradeIncomeTax, true);
    appendFloatParameter(message, "day_trade_withholding_income_tax", dayTradeWithholdingIncomeTax, true);
    appendFloatParameter(message, "day_trade_other_taxes", dayTradeOtherTaxes, true);
    appendFloatParameter(message, "iss_tax", issTax, true);
    appendFloatParameter(message, "custody_tax", custodyTax, true);
    appendFloatParameter(message, "lease_tax", leaseTax, true);
    appendStringParameter(message, "income_tax_payment", incomeTaxPayment, true);
    std::vector<std::string> response = smarttFunction(message);
    return lexical_cast<std::string>(response[0]);
}


const std::vector<std::string> get_financial_transactions_attributes = {
    "financial_transaction_id",
    "investment_code",
    "brokerage_id",
    "datetime",
    "contribution_or_withdrawal",
    "value",
    "operational_tax_cost",
    "description"
};

std::map<std::string, std::string> SmarttClient::getFinancialTransactions(std::string financialTransactionId, std::string investmentCode, int brokerageId, std::vector<std::string> returnAttributes)
{
    std::vector<string> message;
    message.push_back("get_financial_transactions");
    appendStringParameter(message, "financial_transaction_id", financialTransactionId, true);
    appendStringParameter(message, "investment_code", investmentCode, true);
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, true);
    appendAttributes(message, returnAttributes, get_financial_transactions_attributes);
    std::vector<std::string> response = smarttFunction(message);
    return formatMapResponse(response, returnAttributes, get_financial_transactions_attributes);
}


const std::vector<std::string> insert_financial_transaction_attributes = {
    "message"
};

std::string SmarttClient::insertFinancialTransaction(std::string investmentCode, int brokerageId, std::string datetime, bool contributionOrWithdrawal, double value, double operationalTaxCost, std::string description)
{
    std::vector<string> message;
    message.push_back("insert_financial_transaction");
    appendStringParameter(message, "investment_code", investmentCode, false);
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, true);
    appendDatetimeParameter(message, "datetime", datetime, false);
    appendBooleanParameter(message, "contribution_or_withdrawal", contributionOrWithdrawal);
    appendFloatParameter(message, "value", value, false);
    appendFloatParameter(message, "operational_tax_cost", operationalTaxCost, false);
    appendStringParameter(message, "description", description, true);
    std::vector<std::string> response = smarttFunction(message);
    return lexical_cast<std::string>(response[0]);
}


const std::vector<std::string> update_financial_transaction_attributes = {
    "message"
};

std::string SmarttClient::updateFinancialTransaction(std::string financialTransactionId, std::string investmentCode, int brokerageId, std::string datetime, bool contributionOrWithdrawal, double value, double operationalTaxCost, std::string description)
{
    std::vector<string> message;
    message.push_back("update_financial_transaction");
    appendStringParameter(message, "financial_transaction_id", financialTransactionId, false);
    appendStringParameter(message, "investment_code", investmentCode, true);
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, true);
    appendDatetimeParameter(message, "datetime", datetime, true);
    appendBooleanParameter(message, "contribution_or_withdrawal", contributionOrWithdrawal);
    appendFloatParameter(message, "value", value, true);
    appendFloatParameter(message, "operational_tax_cost", operationalTaxCost, true);
    appendStringParameter(message, "description", description, true);
    std::vector<std::string> response = smarttFunction(message);
    return lexical_cast<std::string>(response[0]);
}


const std::vector<std::string> delete_financial_transactions_attributes = {
    "message"
};

std::string SmarttClient::deleteFinancialTransactions(std::string financialTransactionId, std::string investmentCode, int brokerageId)
{
    std::vector<string> message;
    message.push_back("delete_financial_transactions");
    appendStringParameter(message, "financial_transaction_id", financialTransactionId, true);
    appendStringParameter(message, "investment_code", investmentCode, true);
    appendUnsignedIntegerParameter(message, "brokerage_id", brokerageId, true);
    std::vector<std::string> response = smarttFunction(message);
    return lexical_cast<std::string>(response[0]);
}


