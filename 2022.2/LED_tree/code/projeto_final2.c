/*
###########################################################
#                                                         #
#                   Projeto - LED Tree                    #
#                                                         #
# Autoras: J�lia Perassolli De L�zari    - Ra:200298      #
#          Wesna Simone Bulla de Araujo  - Ra:225843      #
#                                                         #
###########################################################

/*
   Esse projeto tem por finalidade desenvolver um enfeite natalino (pequena
   �vore de natal no formato de um quadrinho) que tem seus leds controlados por
   um bot�o que est� relacionado a uma interrup��o. Foram desenvolvidas quatro
   rotinas de padr�es para acender os leds:
   
   - rotina_ordem: acende os leds em sequ�ncia;
   - rotina_fileira: acende os leds alternando entre as fileiras da arvore;
   - rotina_cores: acende os leds da mesma cor em sequ�ncia;
   - rotina_aleat�ria: acende os leds aleat�riamente.
   
   Al�m disso, a rotina padr�o foi definida como a rotina_ordem e os leds
   presentes na estrela da �rvore ficam acessos o tempo todo.
*/


//Declara��o das portas do microcontrolador

sbit I0          at RC5_bit;               //porta 1 do charlieplexing
sbit I1          at RC4_bit;               //porta 2 do charlieplexing
sbit I2          at RC7_bit;               //porta 3 do charlieplexing
sbit I3          at RC6_bit;               //porta 4 do charlieplexing
sbit estrela     at RB4_bit;               //porta da estrela
sbit botao       at RA2_bit;               //entrada bot�o

#define TIME 400                           //tempo de delay dos leds
int count = 0;                             //contador da interrup��o

//Fun��es para acender cada LED do charlieplexing

//Acende LED 1
void LED1(){
    //I0 e I1 como saida e I2 e I3 como entrada
    TRISC = 0b11000111;
    //acende o LED 1
    I0 = 1;
    I1 = 0;
    Delay_ms(TIME);
}

//Acende LED 2
void LED2(){
    //I0 e I1 como saida e I2 e I3 como entrada
    TRISC = 0b11000111;
    //acende LED 2
    I0 = 0;
    I1 = 1;
    Delay_ms(TIME);
}

//Acende LED 3
void LED3(){
      //I0 e I2 como saida e I1 e I3 como entrada
      TRISC = 0b01010111;
      //acende o LED 3
      I0 = 1;
      I2 = 0;
      Delay_ms(TIME);
}

//Acende LED 4
void LED4(){
      //I0 e I2 como saida e I1 e I3 como entrada
      TRISC = 0b01010111;
      //estrela = 1;
      //acende o LED 4
      I0 = 0;
      I2 = 1;
      Delay_ms(TIME);
}

//Acende LED 5
void LED5(){
      //I0 e I3 como saida e I1 e I2 como entrada
      TRISC = 0b10010111;
      //estrela = 1;
      //acende o LED 5
      I0 = 1;
      I3 = 0;
      Delay_ms(TIME);
}

//Acende LED 6
void LED6(){
      //I0 e I3 como saida e I1 e I2 como entrada
      TRISC = 0b10010111;
      //estrela = 1;
      //acende o LED 6
      I0 = 0;
      I3 = 1;
      Delay_ms(TIME);
}

//Acende LED 7
void LED7(){
      //I1 e I2 como saida e I0 e I3 como entrada
      TRISC = 0b01100111;
      //estrela = 1;
      //acende o LED 7
      I1 = 1;
      I2 = 0;
      Delay_ms(TIME);
}

//Acende LED 8
void LED8(){
      //I1 e I2 como saida e I0 e I3 como entrada
      TRISC = 0b01100111;
      //estrela = 1;
      //acende o LED 8
      I1 = 0;
      I2 = 1;
      Delay_ms(TIME);
}

//Acende LED 9
void LED9(){
      //I1 e I3 como saida e I0 e I2 como entrada
      TRISC = 0b10100111;
      //estrela = 1;
      //acende o LED 9
      I1 = 1;
      I3 = 0;
      Delay_ms(TIME);
}

//Acende LED 10
void LED10(){
      //I1 e I3 como saida e I0 e I2 como entrada
      TRISC = 0b10100111;
      //estrela = 1;
      //acende o LED 10
      I1 = 0;
      I3 = 1;
      Delay_ms(TIME);
}

//Acende LED 11
void LED11(){
     //I2 e I3 como saida e I0 e I1 como entrada
      TRISC = 0b00110111;
      //estrela = 1;
      //acende o LED 11
      I2 = 1;
      I3 = 0;
      Delay_ms(TIME);
}

//Acende LED 12
void LED12(){
      //I2 e I3 como saida e I0 e I1 como entrada
      TRISC = 0b00110111;
      //estrela = 1;
      //acende o LED 12
      I2 = 0;
      I3 = 1;
      Delay_ms(TIME);
}

//Rotinas com os padr�es para acender os Leds

//Rotina 1
void rotina_fileira(){
        LED12();
        LED8();
        LED7();
        LED3();
        LED2();
        LED1();
        LED6();
        LED5();
        LED4();
        LED11();
        LED10();
        LED9();
}

//Rotina 2
 void rotina_cores(){
      LED12();
      LED11();
      LED9();
      LED8();
      LED7();
      LED2();
      LED10();
      LED4();
      LED6();
      LED5();
      LED3();
      LED1();
 }

//Rotina 3
 void rotina_aleatoria(){
      LED11();
      LED3();
      LED12();
      LED5();
      LED9();
      LED1();
      LED6();
      LED7();
      LED9();
      LED2();
      LED8();
      LED4();
 }

 //Rotina 4
 void rotina_ordem(){
        LED3();
        LED2();
        LED1();
        LED6();
        LED5();
        LED4();
        LED8();
        LED7();
        LED9();
        LED10();
        LED11();
        LED12();
        LED11();
        LED10();
        LED9();
        LED7();
        LED8();
        LED4();
        LED5();
        LED6();
        LED1();
        LED2();
        LED3();
 }
 
 //Rotina de interrup��o
 void interrupt()
{
    //se o bot�o foi pressionado uma vez
    //chama a rotina 1
    if (count == 0){
       rotina_fileira();
       rotina_fileira();
    }
    
    //se o bot�o foi pressionado duas vezes
    //chama a rotina 2
    if (count == 1){
       rotina_cores();
       rotina_cores();
    }
    
    //se o bot�o foi pressionado tr�s vezes
    //chama a rotina 3 e reseta o contador para que na pr�xima vez que o bot�o
    //for apertado retorne a rotina 1
    if (count == 2){
       rotina_aleatoria();
       rotina_aleatoria();
       count = 0;
    }
    
    count +=1;                    //incrementa contador
    INTCON.INTF = 0b00000000;     //reseta a flag de interrup��o externa

}

void main() {

     //configura��es de registradores
     
     ANSEL = 0;                   //registradores associados com a defini��o de porta digital. 0 indica porta digital
     ANSELH = 0x00;               //
     TRISA = 0b11111111;          //seta a porta A como entrada
     TRISC = 0;                   //seta a porta C como sa�da
     TRISB = 0;                   //seta a porta B como sa�da
     ADCON0 = 0;                  //desliga os conversores
     INTCON.GIE = 0x01;           //habilita a interrup��o global
     INTCON.INTE = 0x01;          //habilita a interrup��o externa
     INTCON.PEIE = 0x00;          //n�o habilita interrup��o por perif�ricos
     OPTION_REG.INTEDG = 0x01;    //interrup��o externa por borda de subida
       
     //n�vel l�gico nas portas
     
      estrela = 1;                //acende led associado a estrela da �rvore
      I0 = 0;                    //inicia com a sa�da 1 do charlieplexing zerada
      I1 = 0;                    //inicia com a sa�da 2 do charlieplexing zerada
      I2 = 0;                    //inicia com a sa�da 3 do charlieplexing zerada
      I3 = 0;                    //inicia com a sa�da 4 do charlieplexing zerada
       
  while (1)
   {
       rotina_ordem();          //quando n�o houver interrup��o executa essa rotina
   }
}