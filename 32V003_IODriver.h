/*****************************************************************************/
/**                             IO_DRIVER V1.1                              **/
/** Created: 21/03/2025                            IDE: Mounriver Studio    **/
/** Autor: Gustavo Pereira da Silva                PORTD Tecnologia         **/
/*****************************************************************************/

#define Out2PP   0b00010
#define Out10PP  0b00001
#define Out30PP  0b00011
#define Out2OD   0b00110
#define Out10OD  0b00101
#define Out30OD  0b00111

#define InAn     0b00000
#define InFloat  0b00100
#define InPU     0b11000
#define InPD     0b01000

#define PORTA GPIOA->OUTDR
#define PORTC GPIOC->OUTDR
#define PORTD GPIOD->OUTDR


void TRISAbits(uint8_t pin, u_int8_t conf){

    u_int8_t p = pin*4; // Offset

    if(conf & (1<<0)){ GPIOA->CFGLR |= (1<<p); } else{ GPIOA->CFGLR &= ~(1<<p); }
    if(conf & (1<<1)){ GPIOA->CFGLR |= (1<<p+1); } else{ GPIOA->CFGLR &= ~(1<<p+1); }
    if(conf & (1<<2)){ GPIOA->CFGLR |= (1<<p+2); } else{ GPIOA->CFGLR &= ~(1<<p+2); }
    if(conf & (1<<3)){ GPIOA->CFGLR |= (1<<p+3); } else{ GPIOA->CFGLR &= ~(1<<p+3); }

    if(conf==0b11000 || conf==0b01000){ 
        if(conf&(1<<4)){ GPIOA->OUTDR |= (1<<pin); } else{ { GPIOA->OUTDR &= ~(1<<pin); } }
     }

}

void TRISCbits(uint8_t pin, u_int8_t conf){

    u_int8_t p = pin*4; // Offset

    if(conf & (1<<0)){ GPIOC->CFGLR |= (1<<p); } else{ GPIOC->CFGLR &= ~(1<<p); }
    if(conf & (1<<1)){ GPIOC->CFGLR |= (1<<p+1); } else{ GPIOC->CFGLR &= ~(1<<p+1); }
    if(conf & (1<<2)){ GPIOC->CFGLR |= (1<<p+2); } else{ GPIOC->CFGLR &= ~(1<<p+2); }
    if(conf & (1<<3)){ GPIOC->CFGLR |= (1<<p+3); } else{ GPIOC->CFGLR &= ~(1<<p+3); }

    if(conf==0b11000 || conf==0b01000){ 
        if(conf&(1<<4)){ GPIOC->OUTDR |= (1<<pin); } else{ { GPIOC->OUTDR &= ~(1<<pin); } }
     }

}

void TRISDbits(uint8_t pin, u_int8_t conf){

    u_int8_t p = pin*4; // Offset

    if(conf & (1<<0)){ GPIOD->CFGLR |= (1<<p); } else{ GPIOD->CFGLR &= ~(1<<p); }
    if(conf & (1<<1)){ GPIOD->CFGLR |= (1<<p+1); } else{ GPIOD->CFGLR &= ~(1<<p+1); }
    if(conf & (1<<2)){ GPIOD->CFGLR |= (1<<p+2); } else{ GPIOD->CFGLR &= ~(1<<p+2); }
    if(conf & (1<<3)){ GPIOD->CFGLR |= (1<<p+3); } else{ GPIOD->CFGLR &= ~(1<<p+3); }

    if(conf==0b11000 || conf==0b01000){ 
        if(conf&(1<<4)){ GPIOD->OUTDR |= (1<<pin); } else{ { GPIOD->OUTDR &= ~(1<<pin); } }
     }

}


void PORTA_OUT(uint8_t pin, uint8_t v){
    uint32_t VPORT=0;
    if(v){ VPORT |=(1<<pin); } else{ VPORT |=(1<<16+pin); }
    GPIOA->BSHR = VPORT;
}

void PORTC_OUT(uint8_t pin, uint8_t v){
    uint32_t VPORT=0;
    if(v){ VPORT |=(1<<pin); } else{ VPORT |=(1<<16+pin); }
    GPIOC->BSHR = VPORT;
}

void PORTD_OUT(uint8_t pin, uint8_t v){
    uint32_t VPORT=0;
    if(v){ VPORT |=(1<<pin); } else{ VPORT |=(1<<16+pin); }
    GPIOD->BSHR = VPORT;
}

    /* LEITURA - READ */
#define PA0 ( GPIOA->INDR &(1<<0) )
#define PA1 ( GPIOA->INDR &(1<<1) )

#define PC0 ( GPIOC->INDR &(1<<0) )
#define PC1 ( GPIOC->INDR &(1<<1) )
#define PC2 ( GPIOC->INDR &(1<<2) )
#define PC3 ( GPIOC->INDR &(1<<3) )
#define PC4 ( GPIOC->INDR &(1<<4) )
#define PC5 ( GPIOC->INDR &(1<<5) )
#define PC6 ( GPIOC->INDR &(1<<6) )
#define PC7 ( GPIOC->INDR &(1<<7) )

#define PD0 ( GPIOD->INDR &(1<<0) )
#define PD1 ( GPIOD->INDR &(1<<1) )
#define PD2 ( GPIOD->INDR &(1<<2) )
#define PD3 ( GPIOD->INDR &(1<<3) )
#define PD4 ( GPIOD->INDR &(1<<4) )
#define PD5 ( GPIOD->INDR &(1<<5) )
#define PD6 ( GPIOD->INDR &(1<<6) )
#define PD7 ( GPIOD->INDR &(1<<7) )


void SystemConfig(){

        //RCC->CTLR |= 1<<24; RCC->CFGR0 |= 0b10; //PLL ENABLE
    
        SystemCoreClockUpdate();
        Delay_Init();
        Delay_Ms(50);

        RCC->APB2PCENR |= (1<<2); /* ATIVA CLOCK DO PORTA - PORTA CLOCK ENABLE */
        RCC->APB2PCENR |= (1<<4); /* ATIVA CLOCK DO PORTC - PORTC CLOCK ENABLE */
        RCC->APB2PCENR |= (1<<5); /* ATIVA CLOCK DO PORTD - PORTD CLOCK ENABLE */
        AFIO->PCFR1 &= ~(1<<15);  /* REMAP PA AS GPIO */
    
    }


/****************************************************************/
/**         PARA MAIS INFORMACOES - MORE INFORMATIONS          **/
/**           https://www.youtube.com/@PORTDTech               **/
/**              https://x.com/gustavo_portd                   **/
/****************************************************************/





    
