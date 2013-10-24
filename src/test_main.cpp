/*
    Smartt C++ Client
    Copyright 2013 S10I (s10i.com.br)

    Author: Felipe Menezes Machado (felipe@s10i.com.br)
*/

#include "smartt_client.h"
#include "jsoncpp/json/json.h"

#include <iostream>

using namespace std;
using namespace smartt;

string MY_LOGIN = "YOUR_LOGIN";
string MY_PASSWORD = "YOUR_PASSWORD";

int main() {
    try {
        cout << "Creating client... " << flush;

        SmarttClient client(DEFAULT_SMARTT_CLIENT_HOST, DEFAULT_SMARTT_CLIENT_PORT, false);

        cout << "Client created!" << endl;

        cout << "###########################################################" << endl;

        string loginMessage = client.login(ParameterList()
                                           (S10I_LOGIN, MY_LOGIN)
                                           (S10I_PASSWORD, MY_PASSWORD));
        cout << loginMessage << endl;

        cout << "###########################################################" << endl;

        string loggedMessage = client.logged();
        cout << loggedMessage << endl;

        cout << "###########################################################" << endl;

        Json::Value portfolios = client.getPortfolio(ParameterList()
                                                     (INVESTMENT_CODE, PAPER)
                                                     (BROKERAGE_ID, 1000));

        cout << "Portfolios:\n" << portfolios << endl;

        cout << "###########################################################" << endl;

        Json::Value s10iClient = client.getClient();
        cout << "Client information:\n" << s10iClient << endl;

        cout << "###########################################################" << endl;

        Json::Value stock = client.getStock(ParameterList()
                                            (STOCK_CODE, "PETR4"));
        cout << "Stock information for PETR4:\n" << stock << endl;

        cout << "###########################################################" << endl;

        Json::Value orders = client.getOrders();

        cout << "Got " << orders.size() << " orders.\n";

        if (orders.size() > 3)
            cout << "Showing first 3 orders...\n";

        for (unsigned i = 0; i < min(3U, orders.size()); i++)
            cout << orders[i] << endl;

        cout << "###########################################################" << endl;

        Json::Value trades = client.getTrades(ParameterList()(INVESTMENT_CODE, PAPER));

        cout << "Got " << trades.size() << " trades.\n";

        if (trades.size() > 3)
            cout << "Showing first 3 trades...\n";

        for (unsigned i = 0; i < min(3U, trades.size()); i++)
            cout << trades[i] << endl;

        cout << "###########################################################" << endl;

        int orderId = client.sendOrder(ParameterList()
                                       (INVESTMENT_CODE, PAPER)
                                       (ORDER_TYPE, 0)
                                       (STOCK_CODE, "PETR4")
                                       (NUMBER_OF_STOCKS, 200)
                                       (VALIDITY_TYPE, "HJ")
                                       (PRICE, 2.00));

        cout << "Sent buy order for PETR4. Id: " << orderId << endl;

        cout << "###########################################################" << endl;

        cout << "Getting that specific order:\n";

        cout << client.getOrders(ParameterList()(ORDER_ID, orderId));

        cout << endl;
        cout << "###########################################################" << endl;

        cout << "Cancelling that order... ";

        client.cancelOrder(ParameterList()(ORDER_ID, orderId));

        cout << "cancel request sent." << endl;

        cout << "###########################################################" << endl;

        cout << "Getting that order again. Its status changed:\n";

        cout << client.getOrders(ParameterList()(ORDER_ID, orderId)) << endl;

        cout << "###########################################################" << endl;

        string response_logout = client.logout();
        cout << response_logout << endl;

    } catch (SmarttClientException &e) {
        cout << e.what() << endl;
    }

    return 0;
}
