#include <Wire.h>  //Biblioteca para Comunicação I2C
#include <LiquidCrystal_I2C.h>  //Biblioteca com as funções do display

LiquidCrystal_I2C lcd(0x27, 16, 2);// Inicializa o display no endereco 0x27

float tensaoAC; //Defina aqui a tensão AC da rede
float correnteRms; //A variável que vai armazenar a corrente medida pelo sensor

//Defina a variável 'sensibilidade' a partir da corrente medida pelo seu sensor:
//- Para 30A, sensibilidade = 0.066; 
//- Para 20A, sensibilidade = 0.100; 
//- Para 5A,  sensibilidade = 0.185;
float sensibilidade = 0.185; 
float relacaoDivisiva = 0.5;//Ajuste conforme o divisor resistivo
float relacaoTrafo = 24.4;//Ajuste conforme a relação de transformação do trafo

void setup() {
  lcd.init();
  lcd.init();
  lcd.backlight();  // Ativa a luz de fundo do display
}

void loop() {
  correnteRms = calculaCorrente(filtroDaMedia()); //Calcula a corrente
  tensaoAC = relacaoTrafo*(calculaTensao(filtroDaMediaTensao())); //Calcula a tensão
  lcd.clear(); //Apaga todos os caracteres do display
  lcd.setCursor(0,0); //Coloca o cursor do display na primeira linha e primeira coluna
  //Digita o valor de Tensão na linha 1
  lcd.print("Vrms=");
  lcd.print(tensaoAC);
  
  //Digita o valor de Corrente na linha 2
  lcd.setCursor(0,1);    
  lcd.print("Irms=");
  lcd.print(correnteRms,3);
}

// A função "calculaCorrente" vai converter o sinal amostrado pelo arduino em A0 num valor de corrente.
float calculaCorrente(int sinalSensor) {
  return (float)(sinalSensor)*(5.000)/(1023.000*sensibilidade);
}

// A função "filtroDaMedia", como o nome já diz, é um Filtro da Média. Esse é um filtro digital que serve para retirar o ruído do sinal do sensor.
// Nessa função, nós amostramos o sinal do sensor mil vezes, somamos essas amostras e dividimos por 1000. Obtemos assim a média aritmética de 1000 amostras.
int filtroDaMedia(){
  long somaDasCorrentes=0, mediaDasCorrentes;
  for(int i=0; i<1000; i++){
    somaDasCorrentes+=pow((analogRead(A0)-509),2); //Soma o valor das correntes elevadas ao quadrado para calcular o valor RMS
    delay(1);
  }
  mediaDasCorrentes=sqrt(somaDasCorrentes/1000); //Calcula a média quadrática da corrente
  if(mediaDasCorrentes==1) //esse if é para remover o ruído de 7mA quando I=0. possui uma desvantagem, pois só permite que o sensor meça correntes a partir de (2*5)/(1023*sensibilidade)
  return 0;
  return mediaDasCorrentes;
}

float calculaTensao(int sinalMeiaOnda) {
  return (float)(sinalMeiaOnda)*(5.000)/(1023.000*relacaoDivisiva);
}

int filtroDaMediaTensao() {
  long somaDasTensoes = 0, mediaDasTensoes;
  for(int i = 0; i < 1000; i++) {
    somaDasTensoes += pow(analogRead(A1), 2); // Soma o valor das tensões elevadas ao quadrado para calcular o valor RMS
    delay(1);
  }
  mediaDasTensoes = sqrt((somaDasTensoes) / 1000); // Calcula a média quadrática da tensão

  return mediaDasTensoes;
}
