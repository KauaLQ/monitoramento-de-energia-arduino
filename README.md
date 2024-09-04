<img width=100% src="https://capsule-render.vercel.app/api?type=waving&color=00979C&height=120&section=header"/>

# monitoramento-de-energia-arduino <img width='70' heigth='70' src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/arduino/arduino-original-wordmark.svg" />
#### Olá, leitor. Neste repositório, você encontrará o firmware do meu protótipo de um sistema de monitoramento de energia de baixo custo, desenvolvido em um projeto de pesquisa em parceria com o _IFCE campus Pecém_. Este sistema, controlado por uma placa _Arduino_, utiliza um transformador e um diodo retificador de meia-onda para analisar a tensão, além de um _módulo ACS712_ para medir a corrente elétrica. As leituras são exibidas em um _display LCD_, permitindo ao usuário monitorar o consumo elétrico de cada aparelho.
#### A seguir eu escrevi um resumo básico de cada parte do sistema;
### _Leitura de tensão:_
Para medir a tensão, optou-se por utilizar um sinal retificado de meia-onda, obtido a partir de um divisor resistivo seguido por um diodo, conectado ao secundário de um transformador 220V/9V. Essa abordagem assegura o isolamento do circuito eletrônico do protótipo em relação à rede de alimentação. O sinal retificado é proporcional ao valor de entrada, e o divisor resistivo foi cuidadosamente projetado para garantir que a tensão não ultrapasse 4,96V, mantendo-se dentro do limite aceitável pelo Arduino.

---

### _Leitura de corrente:_
Para a medição de corrente elétrica, foi utilizado o sensor ACS712 que funciona com base no efeito Hall. Esse sensor gera um sinal de tensão linear e proporcional à corrente que flui entre seus terminais de carga que, para o modelo de 5A utilizado no projeto, corresponde a 185mV/A. O ACS712 não gera tensões negativas, e sua tensão de referência é igual à metade da tensão de alimentação, determinando o sentido da corrente elétrica no circuito: valores acima da referência indicam corrente positiva, enquanto valores abaixo indicam corrente negativa.

---

### _Apresentação dos dados:_
O Arduino realiza todo o processamento dos dados, aplicando cálculos de proporcionalidade, e exibe os resultados em um display LCD 16x2. Essa abordagem foi desenvolvida para garantir que o sistema seja simples e fácil de usar, mesmo para consumidores finais.

---

### O protótipo ainda está em fase inicial e apresenta alguns erros de medição em torno de 5%. No entanto, há planos futuros para aprimorar tanto o _hardware_ quanto o _firmware_, visando reduzir esses erros. Sua contribuição também é muito bem-vinda! Se tiver alguma melhoria em mente, faça um _fork_, realize as alterações necessárias e envie um _pull request_; ficarei muito grato pela sua colaboração. Caso tenha dúvidas, sinta-se à vontade para criar uma _issue_ ou me contatar através de: &nbsp;&nbsp;[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/kaualimaq/) &nbsp;&nbsp;[![Gmail](https://img.shields.io/badge/Gmail-333333?style=for-the-badge&logo=gmail&logoColor=red)](mailto:limakaua610@gmail.com)
