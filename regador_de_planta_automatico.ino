/* Regador automático para planta. 20º projeto.linguagem utilizada c++
 <<Projeto de robótica do ditão 2023>>
 1º campeonato "Ditão robótica"

 criado por: Leonardo de Oliveira Prado.
 Instagram: arduino2.0tecnologico

 Data de inicio do projeto 03/09/2023
 Data de término do projeto 05/05/2024  

************************************************************************************************************************************
*/
#define vermelho 2
#define amarelo 3
#define verde 4
#define bombadagua 5
#define SensorDeUmidade A0

void setup() {
  pinMode(SensorDeUmidade, INPUT);  // sensor de umidade da terra

  pinMode(vermelho, OUTPUT);  //pin vermelho 2
  pinMode(amarelo, OUTPUT);   //pin vermelho 3
  pinMode(verde, OUTPUT);     //pin vermelho 4

  pinMode(bombadagua, OUTPUT);  //pin boba d'água 5
  //Serial.begin(9600);
}

void loop() {
  //Serial.println(analogRead(A1));
  //delay(50);
  if (analogRead(SensorDeUmidade) <= 1023 && analogRead(SensorDeUmidade) >= 601) {  // ligar a bomba d'água //umidade da terra ruim
    delay(2000);
    digitalWrite(amarelo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(vermelho, HIGH);

    digitalWrite(bombadagua, HIGH);
    delay(2000);
  }

  else if (analogRead(SensorDeUmidade) <= 600 && analogRead(SensorDeUmidade) >= 501) {  // desligar a bomba d'água //umidade da terra média
    delay(2000);
    digitalWrite(vermelho, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(amarelo, HIGH);

    digitalWrite(bombadagua, LOW);
    delay(2000);

  } else if (analogRead(SensorDeUmidade) <= 500) {  // desligar a bomba d'água //umidade da terra boa
    delay(2000);
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, LOW);
    digitalWrite(verde, HIGH);

    digitalWrite(bombadagua, LOW);
    delay(2000);
  }
}
