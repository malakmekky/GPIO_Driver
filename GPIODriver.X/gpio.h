/* 
 * File:   gpio.h
 * Author: mkmek
 *
 * Created on July 16, 2025, 2:20 PM
 */

#ifndef GPIO_H
#define	GPIO_H

#ifdef	__cplusplus
extern "C" {
#endif
typedef enum {
    OUT = 0, IN = 1
}pinDir;
typedef enum {
    PIN=0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7
}pinNum;
typedef enum {
    LOW = 0, HIGH = 1
}pinLevel;
typedef enum {
    EPORTA, EPORTB, EPORTC, EPORTD, EPORTE
}portNum;
 
void setPinDir(pinNum pin, portNum port, pinDir dir);
void setPinLevel(pinNum pin, portNum port, pinLevel level);
int getBit(pinNum pin, portNum port);
void clearAllBits(portNum port);
void clearBit(pinNum pin, portNum port);

#ifdef	__cplusplus
}
#endif

#endif	/* GPIO_H */

