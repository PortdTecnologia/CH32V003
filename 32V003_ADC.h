/*****************************************************************************/
/**                   CH32V003 ADC - RULE GROUP CONVERTER                   **/
/** Created: 12/06/2025  V1.0                      IDE: Mounriver Studio    **/
/** Autor: Gustavo Pereira da Silva                PORTD Tecnologia         **/
/*****************************************************************************/

#define ADCREG  (ADC1->RDATAR)

#define ADC_CH0 (Adc_Read(0))
#define ADC_CH1 (Adc_Read(1))
#define ADC_CH2 (Adc_Read(2))
#define ADC_CH3 (Adc_Read(3))
#define ADC_CH4 (Adc_Read(4))
#define ADC_CH5 (Adc_Read(5))
#define ADC_CH6 (Adc_Read(6))
#define ADC_CH7 (Adc_Read(7))

void Adc_ON(){
    RCC->APB2PCENR |= (1<<9); // RCC CLOCK ENABLE
    ADC1->CTLR2 |= (1<<0);    // ADC POWER ON
}

void Adc_OFF(){
    RCC->APB2PCENR &= ~(1<<9); // RCC CLOCK ENABLE
    ADC1->CTLR2 &= ~(1<<0);    // ADC POWER ON
}

uint16_t Adc_Channel(uint8_t ch){
    ADC1->RSQR3=ch;
}

void Adc_Continuous(){
    ADC1->CTLR1 |=(1<<8); // SCAN MODE
    ADC1->CTLR2 |= (1<<1);// CONTINUOS CONVERSION
    ADC1->CTLR2 |=(1<<22);// INIT CONVERSION
    ADC1->CTLR2 |=(1<<22);// INIT CONVERSION RETRY
}

void Adc_Init(uint8_t ich){
    Adc_ON();
    Adc_Channel(ich);
    Adc_Continuous();
}

uint16_t Adc_Read(uint8_t ch){
    ADC1->RSQR3=ch;
    Delay_Us(10);
    return (ADC1->RDATAR);
}


/* USE */

// MODO DE 1 CANAL - SINGLE CHANNEL MODE
// Adc_ON();        // Ative o modulo ADC - Turn on ADC module
// Adc_Channel(7);  // Configure o canal - Configure channel
// AdcContinuos();  // Ative a converssao continua - Enable continuous convertion
// Ou sinplesmente / Or : Adc_Init(6);
// FORMA DE LEITURA - READ FORM : if(ADCREG>600){...}

// MODO MULTI CANAL - MULTI CHANNEL MODE
// Adc_Init(6);
// FORMA DE LEITURA - READ FORM : if(ADC_CH7>600){...}



/****************************************************************/
/**         PARA MAIS INFORMACOES - MORE INFORMATIONS          **/
/**           https://www.youtube.com/@PORTDTech               **/
/**              https://x.com/gustavo_portd                   **/
/****************************************************************/