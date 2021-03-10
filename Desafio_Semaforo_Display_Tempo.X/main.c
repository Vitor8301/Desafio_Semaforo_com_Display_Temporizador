/*
 * File:   main.c
 * Author: 19179172
 *
 * Created on 19 de Fevereiro de 2021, 15:01
 */


#include <xc.h>
#include "config.h"
#include "delay.h"
#include "semaforo.h" 
#include "disp7seg.h"

void main ( void ) 
{
    char estado = 0;
    char contador = 0;
    int t;
    
    disp7seg_init();
    
    while ( 1 )
    {
        switch ( estado )
        {
            case 0:
                    estado = 1;
                    break;
            case 1:
                    semaforo_init();
                    estado = 2;
                    break;
            case 2:
                    amarelo( 0 );
                    vermelho( 0 );
                    verde( 1 );
                    verde_ped( 0 );
                    vermelho_ped( 1 );
                    if( botao() )
                        estado = 3;
                    break;
            case 3:
                    t = 3000;
                    contador = --contador % 4;
                    disp7seg(contador);
                    estado = 4;
                    break;
            case 4:
                    delay( 1 );
                    --t;
                    if( t <= 0 )
                        estado = 5;
                    break;
            case 5:
                    amarelo( 1 );
                    vermelho( 0 );
                    verde( 0 );
                    verde_ped( 0 );
                    vermelho_ped( 1 );
                    t = 3000;
                    contador = --contador % 4;
                    disp7seg(contador);
                    estado = 6;
                    break;
            case 6:
                    delay( 1 );
                    --t;
                    if( t <= 0 )
                        estado = 7;
                    break;
            case 7:
                    amarelo( 0 );
                    vermelho( 1 );
                    verde( 0 );
                    verde_ped( 1 );
                    vermelho_ped( 0 );
                    t = 8000;
                    contador = --contador % 9;
                    disp7seg(contador);
                    estado = 8;
                    break;
            case 8:
                   delay( 1 );
                    --t;
                    if( t <= 0 )
                        estado = 2;
                    break;
        }
    }
}
