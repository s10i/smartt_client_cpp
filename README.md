
# Smartt C++ Client

Bibliotecas e aplicações cliente para o S10I Smartt na linguagem C++.

O código dessa biblioteca é aberto, distribuído sob a licença BSD de duas
cláusulas (ver arquivo LICENSE).


## Compilação

Para compilar a biblioteca e a aplicação cliente, basta utilizar o arquivo
makefile incluído e executar o comando make:

$ make

Um método mais portável de compilação é utilizar o CMake. Para tal, você
pode criar um diretório temporário para os arquivos de compilação, e usar
o arquivo CMakeLists.txt deste repositório. Em um sistema GNU/Linux,
considerando que o CMake está instalado, você poderia fazer (estando
na pasta deste README):

$ mkdir build
$ cd build
$ cmake ..
$ make

A execução do CMake poderá informar algum erro, por exemplo sobre 
dependências faltando. A seção seguinte pode ajudar neste caso.

## Dependências

As únicas dependências além da *STL* são as bibliotecas *OpenSSL*, 
utilizada para comunicação segura com o servidor através do protocolo 
*SSL*, e *jsoncpp* (http://jsoncpp.sourceforge.net), usada para 
representar os valores de retorno do Smartt.

A versão da *OpenSSL* utilizada durante o desenvolvimento e testes é a 
**1.0.1e, Revision 1**.

As duas bibliotecas podem ser encontradas nos repositórios das 
distribuições Linux mais populares. Por exemplo, no Debian ou Ubuntu,
elas podem ser instaladas com o comando:

$ sudo apt-get install libjsoncpp-dev libssl-dev

Ou no Fedora:

$ sudo yum install jsoncpp-devel openssl-devel

## Usando a Biblioteca

Para usar este cliente em suas estratégias automatizadas, basta incluir o
 header `"smartt_client.h"`. Ele contém uma classe `SmarttClient`, que 
deverá ser instanciada.

Tendo um objeto `SmarttClient`, você já terá acesso a todas as funções do
Smartt disponíveis na API. O primeiro passo é realizar login:

```cpp
    SmarttClient client;
    using namespace smartt;
    std::string mensagem = client.login(ParameterList()
                                        (S10I_LOGIN, "seu login")
                                        (S10I_PASSWORD, "sua senha"));
```

Observe que a forma de passar parâmetros para as funções do Smartt não é
posicional, como é comum na linguagem C++. Ao invés disso, passamos apenas
um objeto do tipo `ParameterList`, que contém seus parâmetros. Assim, você
pode passar qualquer subconjunto dos parâmetros aceitos, e em qualquer ordem.
Assim, basta usar a sintaxe exemplificada:

    ParameterList()(nome_parametro_1, valor_parametro_1)
                   (nome_parametro_2, valor_parametro_2)
                   ...
                   (nome_parametro_n, valor_parametro_n)

Nas funções do Smartt que não pedem parâmetros, você não deve passar 
argumentos. Por exemplo:

    // Exibe uma mensagem informando se você está logado no Smartt
    std::cout << client.logged() << std::endl; 

Você pode informar o nome dos parâmetros como string, usando o nome descrito
no manual. Porém, o cliente contém constantes que podem ser usadas por 
conveniência para nomes de parâmetros, como `S10I_LOGIN` e `S10I_PASSWORD`.
Além disto, há constantes para valores enumerados do Smartt, como `BOVESPA`,
`BMF` (para o parâmetro `market_name` de algumas funções), ou `CANCELED` 
(estado da ordem retornado pela função `getOrders()`). Estas constantes
estão no `namespace smartt`.

Note que o nome dos métodos no cliente segue o padrão *lower cammel case*.
Ou seja, a função `get_available_limits` do Smartt, no cliente, se chama
`getAvailableLimits`. Os demais nomes (parâmetros, valores enumerados e 
atributos de retorno) seguem o mesmo nome do manual.

As respostas do Smartt são representadas em um tipo apropriado da linguagem
C++, quando é apenas um valor (exemplo: `logged()`, que retorna apenas uma
mensagem, retorna std::string), ou com um objeto  do tipo Json::Value quando
o valor de retorno é mais complexo.

Esta classe vem da biblioteca jsoncpp (http://jsoncpp.sourceforge.net).
Os valores podem ser acessados de maneira muito natural. Se a função do
Smartt retorna uma lista, por exemplo, podemos fazer:

```cpp
    Json::Value myOrders = client.getOrders(ParameterList()
                                            (INVESTMENT_CODE, PAPER));

    for (unsigned i = 0; i < myOrders.size(); i++) {
        // exibe o identificador da corretora de cada ordem
        std::cout << myOrders[i][BROKERAGE_ID] << std::endl;
    }
```

Neste exemplo, `myOrders[i]` contém uma ordem retornada, e seus atributos
podem ser acessados com o operador []. No caso, o atributo `"brokerage_id"`
pode ser obtido por `myOrders[i]["brokerage_id"]` ou, usando a constante
do cliente, `myOrders[i][BROKERAGE_ID]`.

Para maiores informações sobre a API do Smartt, acesse o site
http://smartt.s10i.com.br, aonde você encontrará, dentre vários outros
recursos, a documentação completa da API.

## Exemplo

```cpp
    // Um exemplo completo pode ser encontrado no arquivo src/test_main.cpp
	#include "smartt_client.h"
    #include <jsoncpp/json/json.h>
    #include <string>
    #include <iostream>

    SmarttClient client;
    using namespace smartt;

    std::string mensagem = client.login(ParameterList()
                                        (S10I_LOGIN, "seu login")
                                        (S10I_PASSWORD, "sua senha"));

	Json::Value stockInfo = client.getStock("PETR3F");

    std::cout << stockInfo << std::endl;

	// Envia uma ordem de compra de uma ação da Petrobrás a R$5,00
    // orderId guardará o identificador da ordem feita
	int orderId = client.sendOrder(ParameterList()
                                   (INVESTMENT_CODE, AUTO)
                                   (BROKERAGE_ID, 1000)
                                   (STOCK_CODE, "PETR3F")
                                   (NUMBER_OF_STOCKS, 1)
                                   (PRICE, 5.00));

    // Cancela a ordem feita
    client.cancelOrder(ParameterList()(ORDER_ID, orderId));
```
