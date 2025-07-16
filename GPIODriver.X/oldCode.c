/* 
 * File:   main.c
 * Author: mkmek
 *
 * Created on July 15, 2025, 3:12 PM
 */

#include <stdio.h>
#include <stdlib.h>

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define SET_BIT(X, BTT_NUM) X = X | (1 << BTT_NUM)
#define RESET_BIT(X, BTT_NUM) X = X & ~(1 << BTT_NUM)
#define GET_BIT(X,BIT_NUM)((X>>BIT_NUM)&0x01)

#define _XTAL_FREQ 4000000UL


#define PORTC *((char*)0x07)
#define TRISC *((char*)0x87)
#define TRISB *((char*)0x86)
#define PORTB *((char*)0x06)
#define LED_PORT PORTC
#define LED1_PIN 3
#define LED2_PIN 2
#define LED3_PIN 1
#define BUTTON_PORT PORTB
#define BUTTON_PIN 5

void delayMS(int M){
    int i, j;
    for (i = 0; i<M ; i++){
        for (j = 0; j<80; j++){

        }
    }
}



void main(void) {

    RESET_BIT(TRISC, LED1_PIN);
    RESET_BIT(TRISC, LED2_PIN);
    RESET_BIT(TRISC, LED3_PIN);
    SET_BIT(TRISB, BUTTON_PIN);  
    int modeNum=1;


    while(1)
    {
        if(GET_BIT(BUTTON_PORT, BUTTON_PIN)==0) //if the button is pressed
        {   
            while (modeNum ==1){
                RESET_BIT(TRISC, LED1_PIN);
                RESET_BIT(TRISC, LED2_PIN);
                RESET_BIT(TRISC, LED3_PIN);
                delayMS(250);
                if(GET_BIT(BUTTON_PORT, BUTTON_PIN)==0){
                      modeNum++;
                      break;
                  }
            }
            while(modeNum==2)
            {
                 delayMS(250);
                 SET_BIT(LED_PORT, LED1_PIN);
                 SET_BIT(LED_PORT, LED2_PIN);
                 SET_BIT(LED_PORT, LED3_PIN);
                 delayMS(250);
                  //currentLED1Stat,currentLED2Stat, currentLED3Stat=0; 
                 RESET_BIT(LED_PORT, LED1_PIN);
                 RESET_BIT(LED_PORT, LED2_PIN);
                 RESET_BIT(LED_PORT, LED3_PIN);
                 if(GET_BIT(BUTTON_PORT, BUTTON_PIN)==0){
                      modeNum++;
                      break;
                  }



            }
            delayMS(250);
            while(modeNum==3)
            {
             SET_BIT(LED_PORT, LED1_PIN);
             delayMS(250);
             SET_BIT(LED_PORT, LED2_PIN);
             delayMS(250);
             SET_BIT(LED_PORT, LED3_PIN);
             delayMS(250);
               RESET_BIT(LED_PORT, LED1_PIN);
                  RESET_BIT(LED_PORT, LED2_PIN);
                  RESET_BIT(LED_PORT, LED3_PIN);
             delayMS(250);
            if(GET_BIT(BUTTON_PORT, BUTTON_PIN)==0){
                      modeNum++;
                      break;
            }
            }
             while(modeNum==4)
             {
              SET_BIT(LED_PORT, LED1_PIN);
             delayMS(250);
            RESET_BIT(LED_PORT, LED1_PIN);
             delayMS(250);
            SET_BIT(LED_PORT, LED2_PIN);
              delayMS(250);
              RESET_BIT(LED_PORT, LED2_PIN);
              delayMS(250);
             SET_BIT(LED_PORT, LED3_PIN);
              delayMS(250);
              RESET_BIT(LED_PORT, LED3_PIN);
               delayMS(250);
              if(GET_BIT(BUTTON_PORT, BUTTON_PIN)==0){
                      modeNum++;
                      break;
            }
             }
            while(modeNum==5)
            {
             SET_BIT(LED_PORT, LED1_PIN);
              SET_BIT(LED_PORT, LED3_PIN);
               delayMS(250);
            RESET_BIT(LED_PORT, LED1_PIN);
             RESET_BIT(LED_PORT, LED3_PIN);
             SET_BIT(LED_PORT, LED2_PIN);
             delayMS(250);
               RESET_BIT(LED_PORT, LED2_PIN);
                 delayMS(250);
                 if(GET_BIT(BUTTON_PORT, BUTTON_PIN)==0){
                      modeNum++;
                      break;

            }
            }
            while (modeNum == 6){
                //0
                RESET_BIT(LED_PORT, LED1_PIN);
                RESET_BIT(LED_PORT, LED2_PIN);
                RESET_BIT(LED_PORT, LED3_PIN);
                delayMS(500);
                //1
                SET_BIT(LED_PORT, LED1_PIN);
                RESET_BIT(LED_PORT, LED2_PIN);
                RESET_BIT(LED_PORT, LED3_PIN);
                delayMS(500);
                //2
                RESET_BIT(LED_PORT, LED1_PIN);
                SET_BIT(LED_PORT, LED2_PIN);
                RESET_BIT(LED_PORT, LED3_PIN);
                delayMS(500);
                //3
                SET_BIT(LED_PORT, LED1_PIN);
                SET_BIT(LED_PORT, LED2_PIN);
                RESET_BIT(LED_PORT, LED3_PIN);
                delayMS(500);
                //4
                RESET_BIT(LED_PORT, LED1_PIN);
                RESET_BIT(LED_PORT, LED2_PIN);
                SET_BIT(LED_PORT, LED3_PIN);
                delayMS(500);
                //5
                SET_BIT(LED_PORT, LED1_PIN);
                RESET_BIT(LED_PORT, LED2_PIN);
                SET_BIT(LED_PORT, LED3_PIN);
                delayMS(500);
                //6
                RESET_BIT(LED_PORT, LED1_PIN);
                SET_BIT(LED_PORT, LED2_PIN);
                SET_BIT(LED_PORT, LED3_PIN);
                delayMS(500);
                //7
                SET_BIT(LED_PORT, LED1_PIN);
                SET_BIT(LED_PORT, LED2_PIN);
                SET_BIT(LED_PORT, LED3_PIN);
                delayMS(500);

                if(GET_BIT(BUTTON_PORT, BUTTON_PIN)==0){
                      modeNum=1;
                      break;
                }
            }


//set GPIO dir 
//read if its input which bit is stored
//if its output, store a specific bit in the register --> fn to enable you to change the bit
// 
            }

        }
        }



