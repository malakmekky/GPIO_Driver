#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "gpio.h"

void setPinDir(pinNum pin, portNum port, pinDir dir){
    if (dir == IN){ 
        TRIS_REG(port) |= (1<< pin);
    }
    else if(dir == OUT){
        TRIS_REG(port) &= ~(1<<pin);
    }
}
void setPinLevel(pinNum pin, portNum port, pinLevel level){
    if (level == HIGH){ //high
        PORT_REG(port) |= (1<<pin);
    }
    else if (level == LOW){
        PORT_REG(port) &= ~(1<<pin);
    }
}
int getBit(pinNum pin, portNum port){
    //return PORT_REG port &(1<<pin); //
    (PORT_REG(port)>>pin);
    return PORT_REG(port)&1;
    
};
void clearAllBits(portNum port){
    PORT_REG(port) &= 0b00000000;
};
void clearBit(pinNum pin, portNum port){
    PORT_REG(port) &= ~(1 << pin);
};
