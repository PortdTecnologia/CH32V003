/*****************************************************************************/
/**                    CH32V003 TIMER1 and TIMER2 V1.1                      **/
/** Created: 02/06/2025                            IDE: Mounriver Studio    **/
/** Autor: Gustavo Pereira da Silva                PORTD Tecnologia         **/
/*****************************************************************************/

// V1.1 => 28/06/2025 Changelog - Alteracoes
// Simplified delay functions for increase speed and performance
// Funcoes de delay simplificadas para melhor velocidade e performance
// TIMERx_ON(PS) now can be used to change the prescaller value
// TIMERx_ON(PS) agora pode ser usado para alterar o valor do prescaller


/* CMP=Value of Comparisson */
/* PS=Value of Prescaler 0-65535 */
/* if System Clock=24Mhz and PS=24000 timebase 1000Ms */
/* if System Clock=48Mhz and PS=48000 timebase 1000Ms */

/* Executar antes de usar os timers - Execute before use timers */
    //RCC->APB2PCENR |=(1<<11);  /* TIMER 1 CLOCK ENABLE */
    //RCC->APB1PCENR |=(1<<0);  /* TIMER 2 CLOCK ENABLE */
/****************************************************************/

/*================ TIMER 1 ================*/
void TIMER1_Delay(uint16_t CMP){
    TIM1->CNT=0;
    while(TIM1->CNT<CMP);
}

#define TIMER1_FLAG  (TIM1->CNT)

void TIMER1_ON(uint16_t PS){
    TIM1->CTLR1 &=~ (1<<0);
    TIM1->PSC=PS;
    TIM1->SWEVGR |= (1<<0);
    TIM1->CNT=0;
    TIM1->CTLR1 |= (1<<0);
}
void TIMER1_OFF(){
    TIM1->CTLR1 &=~ (1<<0);
}

/*================ TIMER 2 ================*/
void TIMER2_Delay(uint16_t CMP){
    TIM2->CNT=0;
    while(TIM2->CNT<CMP);
}

#define TIMER2_FLAG  (TIM2->CNT)

void TIMER2_ON(uint16_t PS){
    TIM2->CTLR1 &=~ (1<<0);
    TIM2->PSC=PS;
    TIM2->SWEVGR |= (1<<0);
    TIM2->CNT=0;
    TIM2->CTLR1 |= (1<<0);
}
void TIMER2_OFF(){
    TIM2->CTLR1 &=~ (1<<0);
}


/*     COMO USAR - HOW TO USE     */

/* PRIMEIRO PASSO - FIRST STEP */
// ATIVE OS CLOCKS DOS TIMERS - CLOCK ENABLE
//RCC->APB2PCENR |=(1<<11);  /* TIMER 1 CLOCK ENABLE */
//RCC->APB1PCENR |=(1<<0);  /* TIMER 2 CLOCK ENABLE */

/* SEGUNDO PASSO - SECOND STEP */
// ATIVE O TIMER - TIMER ON
// TIMER_ON(prescaler value);

/* TERCEIRO PASSO - THIRD STEP */
// LER AS FLAGS - READ FLAGS
// if(TIMER1_FLAG>=1000){ ACTION; TIMER1_FLAG=0; }
// if(TIMER2_FLAG>=500) { ACTION; TIMER2_FLAG=0; }  


/****************************************************************/
/**         PARA MAIS INFORMACOES - MORE INFORMATIONS          **/
/**           https://www.youtube.com/@PORTDTech               **/
/**              https://x.com/gustavo_portd                   **/
/****************************************************************/