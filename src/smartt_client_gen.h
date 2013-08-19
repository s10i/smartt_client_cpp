std::string login(std::string s10iLogin = "", std::string s10iPassword = "");

std::string logout();

std::string logged();

std::map<std::string, std::string> getClient(std::vector<std::string> returnAttributes = std::vector<std::string>());

std::string updateClient(std::string s10iPassword = "", bool naturalPersonOrLegalPerson = false, std::string nameOrCorporateName = "", char gender = '\0', int document = 0, std::string email = "", std::string s10iLogin = "", std::string newS10iPassword = "", std::string address = "", std::string number = "", std::string complement = "", std::string neighborhood = "", std::string postalCode = "", std::string city = "", std::string state = "", std::string country = "", std::string birthday = "", std::string mainPhone = "", std::string secondaryPhone = "", std::string company = "");

std::map<std::string, std::string> getClientBrokerages(int brokerageId = 0, std::string brokerageLogin = "", std::vector<std::string> returnAttributes = std::vector<std::string>());

std::string insertClientBrokerage(int brokerageId = 0, std::string brokerageLogin = "", std::string brokeragePassword = "", std::string brokerageDigitalSignature = "");

std::string updateClientBrokerage(int brokerageId = 0, int newBrokerageId = 0, std::string brokerageLogin = "", std::string brokeragePassword = "", std::string brokerageDigiralSignature = "");

std::string deleteClientBrokerages(int brokerageId = 0, std::string brokerageLogin = "");

std::map<std::string, std::string> getStock(std::string stockCode = "", std::string marketName = "", std::vector<std::string> returnAttributes = std::vector<std::string>());

int sendOrder(std::string investmentCode = "", int brokerageId = 0, bool orderType = false, std::string stockCode = "", std::string marketName = "", int numberOfStocks = 0, double price = 0.0, std::string validityType = "", std::string validity = "");

int cancelOrder(int orderId = 0);

int changeOrder(int orderId = 0, int newNumberOfStocks = 0, double newPrice = 0.0);

std::vector<std::map<std::string, std::string> > getOrders(int orderId = 0, std::string investmentCode = "", int brokerageId = 0, std::string initialDatetime = "", std::string finalDatetime = "", std::string status = "", std::vector<std::string> returnAttributes = std::vector<std::string>());

std::vector<std::map<std::string, std::string> > getOrdersEvents(int orderId = 0, std::string investmentCode = "", int brokerageId = 0, std::string initialDatetime = "", std::string finalDatetime = "", std::string eventType = "", std::vector<std::string> returnAttributes = std::vector<std::string>());

int getOrderId(std::string orderIdInBrokerage = "", int brokerageId = 0);

int sendStopOrder(std::string investmentCode = "", int brokerageId = 0, bool orderType = false, bool stopOrderType = false, std::string stockCode = "", std::string marketName = "", int numberOfStocks = 0, double stopPrice = 0.0, double limitPrice = 0.0, std::string validity = "", bool validAfterMarket = false);

int cancelStopOrder(int stopOrderId = 0);

std::vector<std::map<std::string, std::string> > getStopOrders(int stopOrderId = 0, std::string investmentCode = "", int brokerageId = 0, std::string initialDatetime = "", std::string finalDatetime = "", std::string status = "", std::vector<std::string> returnAttributes = std::vector<std::string>());

std::vector<std::map<std::string, std::string> > getStopOrdersEvents(int stopOrderId = 0, std::string investmentCode = "", int brokerageId = 0, std::string initialDatetime = "", std::string finalDatetime = "", std::string eventType = "", std::vector<std::string> returnAttributes = std::vector<std::string>());

int getStopOrderId(std::string stopOrderIdInBrokerage = "", int brokerageId = 0);

std::vector<std::map<std::string, std::string> > getTrades(int orderId = 0, std::string investmentCode = "", int brokerageId = 0, std::string initialDatetime = "", std::string finalDatetime = "", std::vector<std::string> returnAttributes = std::vector<std::string>());

std::map<std::string, std::string> getInvestments(std::string investmentCode = "", int brokerageId = 0, std::vector<std::string> returnAttributes = std::vector<std::string>());

std::map<std::string, std::string> getReport(std::string investmentCode = "", int brokerageId = 0, std::vector<std::string> returnAttributes = std::vector<std::string>());

std::map<std::string, std::string> getDailyCumulativePerformance(std::string investmentCode = "", int brokerageId = 0);

std::map<std::string, std::string> getDailyDrawdown(std::string investmentCode = "", int brokerageId = 0);

std::vector<std::map<std::string, std::string> > getPortfolio(std::string investmentCode = "", int brokerageId = 0, std::vector<std::string> returnAttributes = std::vector<std::string>());

std::vector<std::map<std::string, std::string> > getAvailableLimits(std::string investmentCode = "", int brokerageId = 0, std::vector<std::string> returnAttributes = std::vector<std::string>());

std::map<std::string, std::string> getSetups(std::string code = "", std::vector<std::string> returnAttributes = std::vector<std::string>());

std::string updateSetup(std::string code = "", std::string name = "", std::string newCode = "", std::string initialCapital = "", double slippage = 0.0, double absoluteBrokerageTax = 0.0, double percentualBrokerageTax = 0.0, double positionTradingTax = 0.0, double positionLiquidationTax = 0.0, double positionRegisterTax = 0.0, double positionIncomeTax = 0.0, double positionWithholdingIncomeTax = 0.0, double positionOtherTaxes = 0.0, double dayTradeTradingTax = 0.0, double dayTradeLiquidationTax = 0.0, double dayTradeRegiterTax = 0.0, double dayTradeIncomeTax = 0.0, double dayTradeWithholdingIncomeTax = 0.0, double dayTradeOtherTaxes = 0.0, double issTax = 0.0, double custodyTax = 0.0, double leaseTax = 0.0, std::string incomeTaxPayment = "");

std::map<std::string, std::string> getFinancialTransactions(std::string financialTransactionId = "", std::string investmentCode = "", int brokerageId = 0, std::vector<std::string> returnAttributes = std::vector<std::string>());

std::string insertFinancialTransaction(std::string investmentCode = "", int brokerageId = 0, std::string datetime = "", bool contributionOrWithdrawal = false, double value = 0.0, double operationalTaxCost = 0.0, std::string description = "");

std::string updateFinancialTransaction(std::string financialTransactionId = "", std::string investmentCode = "", int brokerageId = 0, std::string datetime = "", bool contributionOrWithdrawal = false, double value = 0.0, double operationalTaxCost = 0.0, std::string description = "");

std::string deleteFinancialTransactions(std::string financialTransactionId = "", std::string investmentCode = "", int brokerageId = 0);

