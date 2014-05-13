std::string login(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

std::string logout(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

std::string logged(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

Json::Value getClient(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

std::string updateClient(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

Json::Value getClientBrokerages(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

std::string insertClientBrokerage(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

int sendOrder(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

int cancelOrder(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

int changeOrder(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

Json::Value getOrders(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

unsigned getNumberOfOrders(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

Json::Value getOrdersEvents(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

unsigned getNumberOfOrdersEvents(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

int getOrderId(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

int sendStopOrder(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

int cancelStopOrder(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

int changeStopOrder(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

Json::Value getStopOrders(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

unsigned getNumberOfStopOrders(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

Json::Value getStopOrdersEvents(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

unsigned getNumberOfStopOrdersEvents(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

int getStopOrderId(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

Json::Value getTrades(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

unsigned getNumberOfTrades(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

Json::Value getInvestments(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

Json::Value getReport(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

Json::Value getDailyCumulativePerformance(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

Json::Value getDailyDrawdown(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

Json::Value getPortfolio(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

Json::Value getAvailableLimits(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

Json::Value getSetups(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

std::string updateSetup(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

Json::Value getFinancialTransactions(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

unsigned getNumberOfFinancialTransactions(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

std::string insertFinancialTransaction(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

std::string updateFinancialTransaction(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

std::string deleteFinancialTransactions(const ParameterList& parameterList = ParameterList::EMPTY_LIST);

