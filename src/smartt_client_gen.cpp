const std::vector<std::string> login_attributes = {
    "message"
};

std::string SmarttClient::login(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("login");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> logout_attributes = {
    "message"
};

std::string SmarttClient::logout(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("logout");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> logged_attributes = {
    "message"
};

std::string SmarttClient::logged(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("logged");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> login_api_key_attributes = {
    "message"
};

std::string SmarttClient::loginApiKey(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("login_api_key");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> check_password_attributes = {
    "message"
};

std::string SmarttClient::checkPassword(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("check_password");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

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
    "company",
    "ip_used_to_sign_up",
    "registration_datetime",
    "plan",
    "has_customized_strategies",
    "is_active",
    "plan_expiration_date",
    "number_of_robots_limit",
    "bovespa_financial_volume_limit",
    "bmef_contracts_limit",
    "bmef_mini_contracts_limit"
};

Json::Value SmarttClient::getClient(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_client");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    Json::Value returnValue = formatMapResponseAsJson(response, findParameter(parameterList, "return_attributes"), get_client_attributes);
    return returnValue;

}


const std::vector<std::string> update_client_attributes = {
    "message"
};

std::string SmarttClient::updateClient(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("update_client");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> get_api_keys_attributes = {
    "api_key"
};

std::string SmarttClient::getApiKeys(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_api_keys");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> insert_api_key_attributes = {
    "message"
};

std::string SmarttClient::insertApiKey(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("insert_api_key");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> delete_api_key_attributes = {
    "message"
};

std::string SmarttClient::deleteApiKey(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("delete_api_key");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> get_client_numbers_attributes = {
    "number_of_orders_executed_on_bovespa",
    "number_of_minis_traded_on_bmf",
    "number_of_contracts_traded_on_bmf"
};

Json::Value SmarttClient::getClientNumbers(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_client_numbers");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    Json::Value returnValue = formatMapResponseAsJson(response, findParameter(parameterList, "return_attributes"), get_client_numbers_attributes);
    return returnValue;

}


const std::vector<std::string> get_activated_brokerages_attributes = {
    "id",
    "name",
    "corporate_name"
};

Json::Value SmarttClient::getActivatedBrokerages(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_activated_brokerages");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    Json::Value returnValue = formatListOfMapsResponseAsJson(response, 0, response.size() - 0, findParameter(parameterList, "return_attributes"), get_activated_brokerages_attributes);
    return returnValue;

}


const std::vector<std::string> get_brokerage_offices_attributes = {
    "brokerage_office_id",
    "brokerage_id",
    "corporate_name",
    "autonomous_agent_name",
    "email",
    "city",
    "state",
    "main_phone",
    "secondary_phone",
    "insertion_datetime",
    "is_already_known",
    "is_already_using"
};

Json::Value SmarttClient::getBrokerageOffices(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_brokerage_offices");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    Json::Value returnValue = formatListOfMapsResponseAsJson(response, 0, response.size() - 0, findParameter(parameterList, "return_attributes"), get_brokerage_offices_attributes);
    return returnValue;

}


const std::vector<std::string> insert_brokerage_office_attributes = {
    "message"
};

std::string SmarttClient::insertBrokerageOffice(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("insert_brokerage_office");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> get_client_brokerages_attributes = {
    "brokerage_id",
    "brokerage_office_id",
    "cblc_bovespa_code",
    "cblc_bmf_code",
    "insertion_datetime",
    "status",
    "approval_datetime"
};

Json::Value SmarttClient::getClientBrokerages(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_client_brokerages");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    Json::Value returnValue = formatListOfMapsResponseAsJson(response, 0, response.size() - 0, findParameter(parameterList, "return_attributes"), get_client_brokerages_attributes);
    return returnValue;

}


const std::vector<std::string> insert_client_brokerage_attributes = {
    "message"
};

std::string SmarttClient::insertClientBrokerage(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("insert_client_brokerage");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> update_client_brokerage_attributes = {
    "message"
};

std::string SmarttClient::updateClientBrokerage(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("update_client_brokerage");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> delete_client_brokerages_attributes = {
    "message"
};

std::string SmarttClient::deleteClientBrokerages(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("delete_client_brokerages");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> get_trading_systems_attributes = {
    "code",
    "description"
};

Json::Value SmarttClient::getTradingSystems(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_trading_systems");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    Json::Value returnValue = formatListOfMapsResponseAsJson(response, 0, response.size() - 0, findParameter(parameterList, "return_attributes"), get_trading_systems_attributes);
    return returnValue;

}


const std::vector<std::string> insert_trading_system_attributes = {
    "message"
};

std::string SmarttClient::insertTradingSystem(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("insert_trading_system");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> update_trading_system_attributes = {
    "message"
};

std::string SmarttClient::updateTradingSystem(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("update_trading_system");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> get_setups_attributes = {
    "code",
    "description",
    "operational_limit",
    "spot_absolute_brokerage_tax",
    "spot_percentual_brokerage_tax",
    "option_absolute_brokerage_tax",
    "option_percentual_brokerage_tax",
    "ibov_contract_day_trade_brokerage_tax",
    "ibov_mini_day_trade_brokerage_tax",
    "dollar_contract_day_trade_brokerage_tax",
    "dollar_mini_day_trade_brokerage_tax",
    "other_absolute_brokerage_tax",
    "other_percentual_brokerage_tax",
    "position_trading_tax",
    "position_liquidation_tax",
    "position_register_tax",
    "position_other_taxes",
    "day_trade_trading_tax",
    "day_trade_liquidation_tax",
    "day_trade_register_tax",
    "day_trade_other_taxes",
    "iss_tax",
    "custody_tax"
};

Json::Value SmarttClient::getSetups(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_setups");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    Json::Value returnValue = formatListOfMapsResponseAsJson(response, 0, response.size() - 0, findParameter(parameterList, "return_attributes"), get_setups_attributes);
    return returnValue;

}


const std::vector<std::string> insert_setup_attributes = {
    "message"
};

std::string SmarttClient::insertSetup(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("insert_setup");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> update_setup_attributes = {
    "message"
};

std::string SmarttClient::updateSetup(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("update_setup");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> get_investments_attributes = {
    "code",
    "description",
    "brokerage_id",
    "trading_system_code",
    "setup_code",
    "is_real",
    "initial_capital",
    "initial_datetime",
    "final_datetime",
    "is_playable"
};

Json::Value SmarttClient::getInvestments(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_investments");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    Json::Value returnValue = formatListOfMapsResponseAsJson(response, 0, response.size() - 0, findParameter(parameterList, "return_attributes"), get_investments_attributes);
    return returnValue;

}


const std::vector<std::string> insert_investment_attributes = {
    "message"
};

std::string SmarttClient::insertInvestment(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("insert_investment");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> update_investment_attributes = {
    "message"
};

std::string SmarttClient::updateInvestment(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("update_investment");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> send_order_attributes = {
    "order_id"
};

int SmarttClient::sendOrder(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("send_order");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    int returnValue = lexical_cast<int>(response[1]);
    return returnValue;

}


const std::vector<std::string> cancel_order_attributes = {
    "order_id"
};

int SmarttClient::cancelOrder(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("cancel_order");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    int returnValue = lexical_cast<int>(response[1]);
    return returnValue;

}


const std::vector<std::string> change_order_attributes = {
    "order_id"
};

int SmarttClient::changeOrder(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("change_order");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    int returnValue = lexical_cast<int>(response[1]);
    return returnValue;

}


const std::vector<std::string> get_orders_attributes = {
    "order_id",
    "order_id_in_brokerage",
    "brokerage_id",
    "investment_code",
    "is_real",
    "order_type",
    "market_name",
    "stock_code",
    "datetime",
    "number_of_stocks",
    "nominal_price",
    "financial_volume",
    "validity_type",
    "validity",
    "number_of_traded_stocks",
    "average_nominal_price",
    "status",
    "is_pending",
    "brokerage_tax_cost",
    "iss_tax_cost",
    "entry_exit_or_reversal",
    "triggered_stop_order_id",
    "absolute_average_simple_profit",
    "percentual_average_simple_profit",
    "gross_profit"
};

Json::Value SmarttClient::getOrders(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_orders");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    Json::Value returnValue = formatListOfMapsResponseAsJson(response, 0, response.size() - 0, findParameter(parameterList, "return_attributes"), get_orders_attributes);
    return returnValue;

}


const std::vector<std::string> get_number_of_orders_attributes = {
    "number_of_orders"
};

unsigned SmarttClient::getNumberOfOrders(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_number_of_orders");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    unsigned returnValue = lexical_cast<unsigned>(response[0]);
    return returnValue;

}


const std::vector<std::string> get_orders_events_attributes = {
    "order_id",
    "brokerage_id",
    "investment_code",
    "number_of_events",
    "datetime",
    "event_type",
    "description",
    "reason"
};

Json::Value SmarttClient::getOrdersEvents(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_orders_events");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    Json::Value returnValue = formatListOfMapsResponseAsJson(response, 0, response.size() - 0, findParameter(parameterList, "return_attributes"), get_orders_events_attributes);
    return returnValue;

}


const std::vector<std::string> get_number_of_orders_events_attributes = {
    "number_of_orders_events"
};

unsigned SmarttClient::getNumberOfOrdersEvents(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_number_of_orders_events");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    unsigned returnValue = lexical_cast<unsigned>(response[0]);
    return returnValue;

}


const std::vector<std::string> get_order_id_attributes = {
    "order_id"
};

int SmarttClient::getOrderId(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_order_id");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    int returnValue = lexical_cast<int>(response[0]);
    return returnValue;

}


const std::vector<std::string> insert_external_order_attributes = {
    "order_id"
};

int SmarttClient::insertExternalOrder(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("insert_external_order");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    int returnValue = lexical_cast<int>(response[1]);
    return returnValue;

}


const std::vector<std::string> update_external_order_attributes = {
    "order_id"
};

int SmarttClient::updateExternalOrder(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("update_external_order");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    int returnValue = lexical_cast<int>(response[1]);
    return returnValue;

}


const std::vector<std::string> delete_external_orders_attributes = {
    "message"
};

std::string SmarttClient::deleteExternalOrders(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("delete_external_orders");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> insert_backtesting_orders_attributes = {
    "order_id"
};

int SmarttClient::insertBacktestingOrders(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("insert_backtesting_orders");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    int returnValue = lexical_cast<int>(response[1]);
    return returnValue;

}


const std::vector<std::string> send_stop_order_attributes = {
    "stop_order_id"
};

int SmarttClient::sendStopOrder(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("send_stop_order");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    int returnValue = lexical_cast<int>(response[1]);
    return returnValue;

}


const std::vector<std::string> cancel_stop_order_attributes = {
    "stop_order_id"
};

int SmarttClient::cancelStopOrder(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("cancel_stop_order");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    int returnValue = lexical_cast<int>(response[1]);
    return returnValue;

}


const std::vector<std::string> change_stop_order_attributes = {
    "stop_order_id"
};

int SmarttClient::changeStopOrder(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("change_stop_order");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    int returnValue = lexical_cast<int>(response[1]);
    return returnValue;

}


const std::vector<std::string> get_stop_orders_attributes = {
    "stop_order_id",
    "stop_order_id_in_brokerage",
    "brokerage_id",
    "investment_code",
    "is_real",
    "order_type",
    "stop_order_type",
    "market_name",
    "stock_code",
    "datetime",
    "number_of_stocks",
    "stop_price",
    "limit_price",
    "validity",
    "status",
    "is_pending",
    "entry_exit_or_reversal",
    "sent_order_id"
};

Json::Value SmarttClient::getStopOrders(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_stop_orders");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    Json::Value returnValue = formatListOfMapsResponseAsJson(response, 0, response.size() - 0, findParameter(parameterList, "return_attributes"), get_stop_orders_attributes);
    return returnValue;

}


const std::vector<std::string> get_number_of_stop_orders_attributes = {
    "number_of_stop_orders"
};

unsigned SmarttClient::getNumberOfStopOrders(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_number_of_stop_orders");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    unsigned returnValue = lexical_cast<unsigned>(response[0]);
    return returnValue;

}


const std::vector<std::string> get_stop_orders_events_attributes = {
    "stop_order_id",
    "brokerage_id",
    "investment_code",
    "number_of_events",
    "datetime",
    "event_type",
    "description",
    "reason"
};

Json::Value SmarttClient::getStopOrdersEvents(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_stop_orders_events");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    Json::Value returnValue = formatListOfMapsResponseAsJson(response, 0, response.size() - 0, findParameter(parameterList, "return_attributes"), get_stop_orders_events_attributes);
    return returnValue;

}


const std::vector<std::string> get_number_of_stop_orders_events_attributes = {
    "number_of_stop_orders_events"
};

unsigned SmarttClient::getNumberOfStopOrdersEvents(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_number_of_stop_orders_events");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    unsigned returnValue = lexical_cast<unsigned>(response[0]);
    return returnValue;

}


const std::vector<std::string> get_stop_order_id_attributes = {
    "stop_order_id"
};

int SmarttClient::getStopOrderId(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_stop_order_id");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    int returnValue = lexical_cast<int>(response[0]);
    return returnValue;

}


const std::vector<std::string> get_trades_attributes = {
    "trade_id",
    "trade_id_in_brokerage",
    "order_id",
    "brokerage_id",
    "investment_code",
    "is_real",
    "trade_type",
    "market_name",
    "stock_code",
    "datetime",
    "number_of_stocks",
    "nominal_price",
    "financial_volume",
    "trading_tax_cost",
    "liquidation_tax_cost",
    "register_tax_cost",
    "income_tax_cost",
    "withholding_income_tax_cost",
    "other_taxes_cost"
};

Json::Value SmarttClient::getTrades(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_trades");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    Json::Value returnValue = formatListOfMapsResponseAsJson(response, 0, response.size() - 0, findParameter(parameterList, "return_attributes"), get_trades_attributes);
    return returnValue;

}


const std::vector<std::string> get_number_of_trades_attributes = {
    "number_of_trades"
};

unsigned SmarttClient::getNumberOfTrades(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_number_of_trades");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    unsigned returnValue = lexical_cast<unsigned>(response[0]);
    return returnValue;

}


const std::vector<std::string> get_report_attributes = {
    "brokerage_id",
    "investment_code",
    "setup_code",
    "initial_datetime",
    "final_datetime",
    "number_of_days",
    "total_contributions",
    "total_withdraws",
    "initial_capital",
    "operational_limit",
    "balance",
    "equity",
    "taxes_and_operational_costs",
    "today_gross_result",
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
    "percentual_largest_profit_elimination",
    "average_profit_in_profit_eliminations",
    "maximum_consecutive_profit_eliminations",
    "total_profit_in_maximum_consecutive_profit_eliminations",
    "absolute_number_of_loss_eliminations",
    "percentual_number_of_loss_eliminations",
    "absolute_largest_loss_elimination",
    "percentual_largest_loss_elimination",
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

Json::Value SmarttClient::getReport(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_report");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    Json::Value returnValue = formatMapResponseAsJson(response, findParameter(parameterList, "return_attributes"), get_report_attributes);
    return returnValue;

}


const std::vector<std::string> get_daily_cumulative_performance_attributes = {
    "brokerage_id",
    "investment_code",
    "daily_cumulative_performance"
};

Json::Value SmarttClient::getDailyCumulativePerformance(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_daily_cumulative_performance");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    Json::Value returnValue = formatMapResponseAsJson(response, get_daily_cumulative_performance_attributes, get_daily_cumulative_performance_attributes);
    return returnValue;

}


const std::vector<std::string> get_daily_drawdown_attributes = {
    "brokerage_id",
    "investment_code",
    "daily_drawdown"
};

Json::Value SmarttClient::getDailyDrawdown(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_daily_drawdown");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    Json::Value returnValue = formatMapResponseAsJson(response, get_daily_drawdown_attributes, get_daily_drawdown_attributes);
    return returnValue;

}


const std::vector<std::string> get_portfolio_attributes = {
    "market_name",
    "stock_code",
    "position_type",
    "number_of_stocks",
    "average_price",
    "financial_volume",
    "variation",
    "result",
    "is_market_open",
    "has_pending_reset_orders"
};

Json::Value SmarttClient::getPortfolio(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_portfolio");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    Json::Value returnValue = formatListOfMapsResponseAsJson(response, 2, response.size() - 2, findParameter(parameterList, "return_attributes"), get_portfolio_attributes);
    Json::Value responseObject;
    responseObject["brokerage_id"] = response[0];
    responseObject["investment_code"] = response[1];
    responseObject["objects"] = returnValue;
    return responseObject;

}


const std::vector<std::string> cancel_all_pending_orders_attributes = {
    "order_ids"
};

int SmarttClient::cancelAllPendingOrders(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("cancel_all_pending_orders");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    int returnValue = lexical_cast<int>(response[0]);
    return returnValue;

}


const std::vector<std::string> cancel_all_pending_stop_orders_attributes = {
    "stop_order_ids"
};

int SmarttClient::cancelAllPendingStopOrders(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("cancel_all_pending_stop_orders");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    int returnValue = lexical_cast<int>(response[0]);
    return returnValue;

}


const std::vector<std::string> reset_portfolio_attributes = {
    "order_ids"
};

int SmarttClient::resetPortfolio(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("reset_portfolio");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    int returnValue = lexical_cast<int>(response[0]);
    return returnValue;

}


const std::vector<std::string> get_available_limits_attributes = {
    "spot",
    "option",
    "margin"
};

Json::Value SmarttClient::getAvailableLimits(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_available_limits");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    Json::Value returnValue = formatListOfMapsResponseAsJson(response, 0, response.size() - 0, findParameter(parameterList, "return_attributes"), get_available_limits_attributes);
    return returnValue;

}


const std::vector<std::string> get_financial_transactions_attributes = {
    "financial_transaction_id",
    "brokerage_id",
    "investment_code",
    "datetime",
    "contribution_or_withdrawal",
    "value",
    "operational_tax_cost",
    "description"
};

Json::Value SmarttClient::getFinancialTransactions(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_financial_transactions");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    Json::Value returnValue = formatListOfMapsResponseAsJson(response, 0, response.size() - 0, findParameter(parameterList, "return_attributes"), get_financial_transactions_attributes);
    return returnValue;

}


const std::vector<std::string> get_number_of_financial_transactions_attributes = {
    "number_of_financial_transactions"
};

unsigned SmarttClient::getNumberOfFinancialTransactions(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_number_of_financial_transactions");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    unsigned returnValue = lexical_cast<unsigned>(response[0]);
    return returnValue;

}


const std::vector<std::string> insert_financial_transaction_attributes = {
    "message"
};

std::string SmarttClient::insertFinancialTransaction(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("insert_financial_transaction");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> update_financial_transaction_attributes = {
    "message"
};

std::string SmarttClient::updateFinancialTransaction(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("update_financial_transaction");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> delete_financial_transactions_attributes = {
    "message"
};

std::string SmarttClient::deleteFinancialTransactions(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("delete_financial_transactions");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


const std::vector<std::string> get_indicators_attributes = {
    "code",
    "description",
    "market_name",
    "stock_code",
    "market_name2",
    "stock_code2",
    "market_name3",
    "stock_code3",
    "datetime",
    "datetime2",
    "datetime3",
    "value",
    "value2",
    "value3",
    "value4",
    "value5"
};

Json::Value SmarttClient::getIndicators(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("get_indicators");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    Json::Value returnValue = formatListOfMapsResponseAsJson(response, 0, response.size() - 0, findParameter(parameterList, "return_attributes"), get_indicators_attributes);
    return returnValue;

}


const std::vector<std::string> insert_indicator_attributes = {
    "message"
};

std::string SmarttClient::insertIndicator(const ParameterList& parameterList)
{
    vector<string> message;
    message.push_back("insert_indicator");
    appendParameterList(message, parameterList);
    vector<string> response = smarttFunction(message);
    std::string returnValue = lexical_cast<std::string>(response[0]);
    return returnValue;

}


