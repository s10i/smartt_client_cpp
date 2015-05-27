/*
    Smartt C++ Client
    Copyright 2013 S10I (s10i.com.br)

    Author: Felipe Menezes Machado (felipe@s10i.com.br)
*/

#include "smartt_client.h"

#include <getopt.h>
#include <iostream>
#include <string>

using namespace std;

string waitForCommand() {
    cout << ">> ";
    string command_line;
    getline( cin, command_line );
    return command_line;
}

void shell(SmarttClient &client) {
    bool loop = true;
    while(loop) {
        string command = waitForCommand();

        if (command.size() > 0)
        {
            if (command.find("$") == string::npos)
            {
                command += "$";
            }

            string response = client.sendRawMessage(command);
            cout << response << endl;
        }

        if (cin.eof())
        {
            loop = false;
        }
    }
}

int main( int argc, char *argv[] )
{
    string smartt_server_host = "localhost";
    int    smartt_server_port = 5060;
    bool   smartt_server_ssl  = true;
    int    c                  = 0;
    int    index;

    const struct option longopts[] =
    {
        {"host",  required_argument,  0, 'h'},
        {"port",  required_argument,  0, 'p'},
        {"nossl", no_argument,        0, 'n'},
        {0,       0,                  0,  0},
    };

    while( c != -1 )
    {
        c = getopt_long( argc, argv, "sp:h:", longopts, &index );

        switch ( c )
        {
            case 0:
                printf("option %s", longopts[index].name);
                if (optarg) printf(" with arg %s\n", optarg);
                break;

            case 'h':
                smartt_server_host = optarg;
                break;

            case 'p':
                smartt_server_port = atoi( optarg );
                break;

            case 'n':
                smartt_server_ssl = false;
                break;
        }
    }

    SmarttClient client(smartt_server_host, smartt_server_port, smartt_server_ssl);

    shell(client);

    return 0;
}
