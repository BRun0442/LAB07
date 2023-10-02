#include "config.h"
#include "pic18f4520.h"
#include "ssd.h"
#include "keypad.h"

void main(void) {
    char i = 0;
    unsigned char tecla;
    unsigned char teclaData = 0;
    unsigned char teclaState;
    unsigned char quantidadeTeclasPressionadas = 185;

    ssdInit();
    kpInit();

    for (;;) {
        ssdUpdate();
        kpDebounce();

        tecla = kpRead();

        /*for (i = 0; i < 8; i++) {
            //Ex1
            /*if(BitTst(tecla, i))
            {
                ssdDigit(i, 0);
            }*/

            //Ex3
            /*switch(tecla)
            {
                case 1:
                    ssdDigit(10, 0);
                    break;
                    
                case 2:
                    ssdDigit(11, 0);
                    break;
                    
                case 4:
                    ssdDigit(3, 0);
                    break;
                    
                case 8:
                    ssdDigit(6, 0);
                    break;
                    
                case 16:
                    ssdDigit(2, 0);
                    break;
                    
                case 32:
                    ssdDigit(5, 0);
                    break;
                    
                case 64:
                    ssdDigit(1, 0);
                    break;
                    
                case 128:
                    ssdDigit(4, 0);
                    break;
            }*/
        //}
        
        if((teclaData != tecla) && (tecla != 0))
        {
            quantidadeTeclasPressionadas += 1;

            ssdDigit(quantidadeTeclasPressionadas % 10, 2);
            ssdDigit((quantidadeTeclasPressionadas / 10) % 10, 3);
        }
        
        teclaData = tecla;
        if(quantidadeTeclasPressionadas >= 100) quantidadeTeclasPressionadas -= 100;
    }
}