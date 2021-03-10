/*
 * File:   semaforo.c
 * Author: 19179172
 *
 * Created on 19 de Fevereiro de 2021, 15:08
 */


#include <xc.h>
#include "config.h"
#include "delay.h"
#include "semaforo.h"

#define VERDE           PORTDbits.RD5
#define AMARELO         PORTDbits.RD6
#define VERMELHO        PORTDbits.RD7
#define VERDE_PED       PORTDbits.RD2
#define VERMELHO_PED    PORTDbits.RD3
#define BOTAO           PORTDbits.RD1

void semaforo_init ( void ) 
{
     //config Entradas
    TRISDbits.TRISD1 = 1; // Botão p/ passagem de pedestres
    //config Saidas
    TRISDbits.TRISD7 = 0; //vermelho carros
    TRISDbits.TRISD6 = 0; //amarelo carros
    TRISDbits.TRISD5 = 0; //verde carros
    TRISDbits.TRISD3 = 0; //vermelho pedestres
    TRISDbits.TRISD2 = 0; //verde pedestres
    
    //Inicialização
    PORTDbits.RD7 = 0;
    PORTDbits.RD6 = 0;
    PORTDbits.RD5 = 0;
    PORTDbits.RD3 = 0;
    PORTDbits.RD2 = 0;
    PORTDbits.RD1 = 0;
}
void verde ( int x )
{
    VERDE = x;
}

void amarelo ( int x )
{
    AMARELO = x;
}

void vermelho ( int x )
{
    VERMELHO = x;
}

void verde_ped ( int x )
{
    VERDE_PED = x;
}

void vermelho_ped ( int x )
{
    VERMELHO_PED = x;
}

int botao ( void )
{
    return ( BOTAO );
}
