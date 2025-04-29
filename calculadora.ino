#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>
#include <Keypad.h>
#define MAX 100
int velocidade = 20;

LiquidCrystal_I2C lcd(0x27, 16, 2);

const uint8_t ROWS = 4;
const uint8_t COLS = 4;
char keys[ROWS][COLS] = {
  { '1', '2', '3', '+' },
  { '4', '5', '6', '-' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', '=' }
};

uint8_t colPins[COLS] = { 5, 4, 3, 2 }; // Pinos conectados a C1, C2, C3, C4
uint8_t rowPins[ROWS] = { 9, 8, 7, 6 }; // Pinos conectados a R1, R2, R3, R4

Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

char alert[][80] = {{"Calculadora"},{"A = +   B = -   * = x   D = ="}};
uint8_t customChars[][8]  = {{0x00},{0x10}};
int ans = 0;


void setup() {
  setupChars();
  lcd.init();        // inicializa o LCD
  lcd.backlight();   // ativa a luz de fundo
  for(int i = 0; i < 2; i++)mensagem(i,1000);
  kpd.setDebounceTime(10);	
}

void loop() {
  
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(ans);
  lcd.setCursor(0, 0);

  char buffer[80] = {0};  // Inicializa com zeros
  short int cliques = 0;
  char key = NO_KEY;

  while (true) {

    key = kpd.getKey();
    if (key != NO_KEY) {
      if (key == 'C' || key == '='){
        if(key == 'C'){
          ans = 0;
        }
        break;
      }; // encerra se for C ou D
      if (cliques < 80) {
        buffer[cliques] = key;
        lcd.setCursor(cliques, 0);
        lcd.print(key);
        cliques++;
      }
    }
  }  
   
  short int contNum = 0, contOp = 0, idx = 0;
  long int numeros[MAX];
  char chNumeros[MAX];
  char operadores[MAX];
  
  for(int i = 0; i < strlen(buffer); i++){
    if(buffer[i] == '+'||buffer[i] == '-'){
      chNumeros[idx] = '\0';
      numeros[contNum++] = atoi(chNumeros);
      operadores[contOp++] = buffer[i];
      idx = 0;
      
    }else{
      chNumeros[idx++] = buffer[i];
   }
  }

  chNumeros[idx] = '\0';
  numeros[contNum++] = atoi(chNumeros);
  

  ans += numeros[0];

  
  for(int i = 0; i<contOp;i++){
    if(operadores[i] == '+'){
      ans += numeros[i + 1];
    }else if (operadores[i] == '-'){
      ans -= numeros[i + 1];
    }
  }
}

//Output animado de mensagens guardadas na matriz alert
void Alert(short int mensagem){
    lcd.clear();
    short int linha = 0;
    for(int coluna = 0; coluna < strlen(alert[mensagem]); coluna++ ){
      if(coluna > 15){
        linha = 1;
        lcd.setCursor(coluna-15,linha);
      }else{
        lcd.setCursor(coluna,linha);
      }
      lcd.print(alert[mensagem][coluna]);
      delay(velocidade);
  }
}

void barra(int cursor){
  lcd.write(byte(0));
  delay(velocidade);
  for(int i = 0; i<5; i++){
    lcd.createChar(1,customChars[1]);
    lcd.setCursor(cursor,0);
    lcd.write(byte(1));
    lcd.setCursor(cursor,1);
    lcd.write(byte(1));
    for(int j = 0; j<8; j++)customChars[1][j] = customChars[1][j] >> 1;
    delay(velocidade);
  }
  for(int j = 0; j<8; j++)customChars[1][j] = B10000;
}

/*função que junta e justifica a animação de transição de abas, repete a 
função barra por toda a tela*/
void transicao(void){
   for(int i = 0; i<16; i++){
    lcd.setCursor(i-1,0);
    lcd.write(byte(0));
    lcd.setCursor(i-1,1);
    lcd.write(byte(0));
    barra(i);
  }
  lcd.clear();
}

void setupChars(void){
  for(int i = 0; i < 8; i++)customChars[0][i] = 0x00;
  for(int i = 0; i < 8; i++)customChars[1][i] = 0x10;
}

void mensagem(int alert, int d){
  Alert(alert);
  delay(d);
  transicao();
}