/* 
 * File:   main.c
 * Author: mkmek
 *
 * Created on July 16, 2025, 2:19 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "gpio.h"
#include "define.h"
#define _XTAL_FREQ 4000000UL

/*
 * 
 */
void delayMS(int M){
    int i, j;
    for (i = 0; i<M ; i++){
        for (j = 0; j<80; j++){

        }
    }
}

void main(void){
    setPinDir(PIN1, EPORTB, OUT);
    setPinDir(PIN2, EPORTB, IN);
    while(1){
        setPinLevel(PIN1, EPORTB, LOW);
        if (getBit(PIN2, EPORTB) == 1){ // button pressed
            setPinLevel(PIN1, EPORTB, HIGH);
        }
         delayMS(2000);
    }
}
