/*****************************************************************************/
/**                          SOFTWARE SERIAL V1.0                           **/
/** Created: 29/04/2025                            IDE: Mounriver Studio    **/
/** Autor: Gustavo Pereira da Silva                PORTD Tecnologia         **/
/*****************************************************************************/

#define UART1_TX_SET      PORTD_OUT(5,1)
#define UART1_TX_RESET    PORTD_OUT(5,0)
#define UART1_TEMP        Delay_P(baud)
uint16_t baud=0;

/*VALORES PARA CH32V003 com Delay_Us - Values for CH32V003 using Delay_Us*/
/*           9600-> 104, 57600-> 14, 115200-> 6, 230400-> 2              */

/*          VALORES CONFIGURADOS USANDO PLL- VALUES USIGN PLL            */
/* 921600 BAUDS FUNCIONA APENAS COM TIMER - 921600 ONLY WORKS WITH TIMER */

void UART1_Config(uint32_t c){
    switch(c){
        case 9600:{baud=325; break;}
        case 57600:{baud=53; break;}
        case 115200:{baud=26; break;}
        case 230400:{baud=12; break;}
        case 460800:{baud=5; break;}
        case 576000:{baud=4; break;}
    }
}

void Delay_P(uint16_t v){
    for(volatile uint16_t i=0;i<v;i++){}
}


void UART1_Byte(uint8_t b){

    UART1_TX_RESET; UART1_TEMP;

    if(b &(1<<0)){ UART1_TX_SET; } else{ UART1_TX_RESET; }
    UART1_TEMP;
    if(b &(1<<1)){ UART1_TX_SET; } else{ UART1_TX_RESET; }
    UART1_TEMP;
    if(b &(1<<2)){ UART1_TX_SET; } else{ UART1_TX_RESET; }
    UART1_TEMP;
    if(b &(1<<3)){ UART1_TX_SET; } else{ UART1_TX_RESET; }
    UART1_TEMP;
    if(b &(1<<4)){ UART1_TX_SET; } else{ UART1_TX_RESET; }
    UART1_TEMP;
    if(b &(1<<5)){ UART1_TX_SET; } else{ UART1_TX_RESET; }
    UART1_TEMP;
    if(b &(1<<6)){ UART1_TX_SET; } else{ UART1_TX_RESET; }
    UART1_TEMP;
    if(b &(1<<7)){ UART1_TX_SET; } else{ UART1_TX_RESET; }
    UART1_TEMP;

    UART1_TX_SET; UART1_TEMP;
}

void UART1_Print(uint8_t str[]){
    uint16_t i=0;
    while(str[i] != '\0'){ UART1_Byte(str[i]); i++; }
}


/****************************************************************/
/**         PARA MAIS INFORMACOES - MORE INFORMATIONS          **/
/**           https://www.youtube.com/@PORTDTech               **/
/**              https://x.com/gustavo_portd                   **/
/****************************************************************/