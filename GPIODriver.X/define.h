/* 
 * File:   define.h
 * Author: mkmek
 *
 * Created on July 16, 2025, 10:28 AM
 */

#ifndef DEFINE_H
#define	DEFINE_H

#ifdef	__cplusplus
extern "C" {
#endif


#define PORTA *((char*)0x05)
#define PORTB *((char*)0x06)
#define PORTC *((char*)0x07)
#define PORTD *((char*)0x08)
#define PORTE *((char*)0x09)
#define TRISA *((char*)0x85)
#define TRISB *((char*)0x86)
#define TRISC *((char*)0x87)
#define TRISD *((char*)0x88)
#define TRISE *((char*)0x89)

#define PORT_REG(port) (*(&PORTA + (port))) //gets address of port
#define TRIS_REG(port) (*(&TRISA + (port)))



#ifdef	__cplusplus
}
#endif

#endif	/* DEFINE_H */

