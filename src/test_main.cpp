/*
    Smartt C++ Client
    Copyright 2013 S10I (s10i.com.br)

    Author: Felipe Menezes Machado (felipe@s10i.com.br)
*/

#include "smartt_client.h"

#include <iostream>

using namespace std;

string LOGIN = "YOUR_LOGIN";
string PASSWORD = "YOUR_PASSWORD";

void printMapResponse(const map<string,string> &response) {
    for (std::map<string,string>::const_iterator it = response.begin(); it != response.end(); ++it)
    {
        cout << it->first << ": " << it->second << endl;
    }
}

void printListOfMapsResponse(const vector< map<string,string> > &response) {
    for (unsigned int i = 0; i < response.size(); ++i)
    {
        printMapResponse(response[i]);
        cout << endl;
    }
}

int main() {
    try {
        cout << "Creating client... " << flush;

        SmarttClient client(DEFAULT_SMARTT_CLIENT_HOST, DEFAULT_SMARTT_CLIENT_PORT, false);

        cout << "Client created!" << endl;

        cout << "###########################################################" << endl;

        string response = client.login(LOGIN, PASSWORD);
        cout << response << endl;

        cout << "###########################################################" << endl;

        string response2 = client.logged();
        cout << response2 << endl;

        cout << "###########################################################" << endl;

        map<string,string> response3 = client.getClient();
        printMapResponse(response3);

        cout << "###########################################################" << endl;

//        string response4 = client.getTime();
//        cout << response4 << endl;

        cout << "###########################################################" << endl;

        map<string,string> response5 = client.getStock("PETR3F");
        printMapResponse(response5);

        cout << "###########################################################" << endl;

        vector< map<string,string> > response6 = client.getOrders();
        printListOfMapsResponse(response6);

        cout << "###########################################################" << endl;

        vector< map<string,string> > response7 = client.getOrdersEvents();
        printListOfMapsResponse(response7);

        cout << "###########################################################" << endl;

        vector< map<string,string> > response8 = client.getStopOrders();
        printListOfMapsResponse(response8);

        cout << "###########################################################" << endl;

        vector< map<string,string> > response9 = client.getStopOrdersEvents();
        printListOfMapsResponse(response9);

        cout << "###########################################################" << endl;

        vector< map<string,string> > response10 = client.getTrades(0, "paper", 1000);
        printListOfMapsResponse(response10);

        cout << "###########################################################" << endl;

        vector< map<string,string> > response11 = client.getPortfolio("paper");
        printListOfMapsResponse(response11);

        cout << "###########################################################" << endl;

        vector< map<string,string> > response12 = client.getAvailableLimits("paper", 1000);
        printListOfMapsResponse(response12);

        cout << "###########################################################" << endl;

        int response13 = client.sendOrder("paper", 0, 1, "PETR4F", "", 1, 5.00);
        cout << "ORDER ID: " << response13 << endl;

        cout << "###########################################################" << endl;

        vector< map<string,string> > response14 = client.getOrders(response13);
        printListOfMapsResponse(response14);

        cout << "###########################################################" << endl;

        bool response15 = client.cancelOrder(response13);
        cout << "ORDER ID: " << response13 << " canceled: " << response15 << endl;

        cout << "###########################################################" << endl;

//        vector< map<string,string> > response16 = client.getOrders("672385");
//        printListOfMapsResponse(response16);

        cout << "###########################################################" << endl;

//        bool response17 = client.changeOrder("672385", 2, 4.50);
//        cout << "ORDER ID: " << "672385" << " changed: " << response17 << endl;

        cout << "###########################################################" << endl;

//        vector< map<string,string> > response18 = client.getOrders("672385");
//        printListOfMapsResponse(response18);

        cout << "###########################################################" << endl;

        int response19 = client.sendStopOrder("paper", 1000, 0, 0, "PETR4F", "", 10, 5.00, 4.50, "2013-08-21");
        cout << "STOP ORDER ID: " << response19 << endl;

        cout << "###########################################################" << endl;

        vector< map<string,string> > response20 = client.getStopOrders(response19);
        printListOfMapsResponse(response20);

        cout << "###########################################################" << endl;

        bool response21 = client.cancelStopOrder(response19);
        cout << "ORDER ID: " << response19 << " canceled: " << response21 << endl;

        cout << "###########################################################" << endl;

        vector< map<string,string> > response22 = client.getStopOrders(response19);
        printListOfMapsResponse(response22);

        cout << "###########################################################" << endl;

        string response_logout = client.logout();
        cout << response_logout << endl;

    } catch (SmarttClientException &e) {
        cout << e.what() << endl;
    }

    return 0;
}
