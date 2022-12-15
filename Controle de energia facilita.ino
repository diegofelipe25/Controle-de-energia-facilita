#include <Arduino.h>
//@autor diego felipe
const int portas[40] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41}; //define todos os pinos que serao usados
const char LIGAR = 'l';
const char DESLIGAR = 'd';

void setup(){
  Serial.begin(9600); //inicia a serial
  for(int i=0; i<sizeof(portas); i++){
    pinMode(portas[i], OUTPUT); //define todos os canais como saida
    digitalWrite(portas[i], HIGH); //desliga todos as portas ao iniciar
  }
}

void interruptor(char comando,int portaEscolhida){
    bool portaCorreta = false;
    for(int i=0; i< sizeof(portas); i++){ // inicia o contador de portas 
      if (portaEscolhida == portas[i]){ //verifica se a porta digitada esta dentro do vetor de portas      
        portaCorreta = true;
      }
    }
  if (portaCorreta){  
     if(comando == DESLIGAR){ // se for digitado 'd' de desligado
         digitalWrite(portaEscolhida, HIGH); //aciona o rele para abrir 'desligar'
         Serial.print("Porta desligada: ");
         Serial.println(portaEscolhida);
     }else if(comando == LIGAR){ // se for digitado 'l' de ligado
         digitalWrite(portaEscolhida, LOW); //aciona o rele para fechar 'ligar'
         Serial.print("Porta ligada: ");
         Serial.println(portaEscolhida);
     }else{
     Serial.print("Comando invÃ¡lido!");
     }
  }else{
    Serial.print("Porta invÃ¡lida!");
  }
}  
            
void loop() {
  
  //Esta etapa so ler a porta
  int portaEscolhida;
  char comando;
  Serial.println("Digite a porta: ");
  delay(3000); //espera 3 segundos
  do{
    if(Serial.available()){
      portaEscolhida = Serial.parseInt(); 
      Serial.read(); //aqui Ã© nessesario para que o arduino nao passe o ASCI do enter na proxima variavel
      break;
    }
  }while(true);
  if(portaEscolhida > 1 and portaEscolhida < 42){ //so pede o comando caso a porta seja maior que 1 e menor que 42, pois a primeira porta do arduino obrigatoriamente Ã© a 2
      Serial.println("Digite o comando: ");
      delay(3000); //espera 3 segundos
      do{
        //Esta etapa so ler o comando
        if(Serial.available()){
          comando = Serial.read();  
          Serial.read(); //aqui Ã© necessario para que o arduino nao passe o ASCI do enter na proxima variavel
          break;
       }
      }while(true);
  }
  interruptor(comando, portaEscolhida);
  
  Serial.println("\n\n\n\n\n"); //gambiarra pra limpar a tela

}
