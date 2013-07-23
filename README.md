
# Smartt C++ Client

Bibliotecas e aplicações cliente para o Smartt na linguagem C++.

O código dessa biblioteca é aberto, distribuído sob a licença BSD de duas
cláusulas (ver arquivo LICENSE).


## Compilação

Para compilar a biblioteca e a aplicação cliente, basta utilizar o arquivo
makefile incluído e executar o comando make:

	make


## Dependências

A única dependência além da *STL* é a biblioteca *OpenSSL*, utilizada para
comunicação segura com o servidor através do protocolo *SSL*.

A versão utilizada durante o desenvolvimento e testes é a **1.0.1e, Revision 1**.


## Exemplo

	#include "smartt_client.h"
	SmarttClient client();

	string login_response = client.login("LOGIN", "PASSWORD");

	map<string,string> stock_info = client.getStock("PETR3F");

	// Envia uma ordem de compra de uma ação da Petrobrás a R$5,00
	string order_id = client.sendOrder("auto", -1, 0, "PETR3F", "", 1, 5.00);
