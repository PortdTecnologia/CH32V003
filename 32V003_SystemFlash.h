/*****************************************************************************/
/**               CH32V003 - INTERNAL FLASH MANIPULATION                    **/
/** Created: 06/04/2025  V1.0                      IDE: Mounriver Studio    **/
/** Autor: Gustavo Pereira da Silva                PORTD Tecnologia         **/
/*****************************************************************************/

#define PAGE256 0x08003FC0

uint16_t FLASHBF[32];

void FlashLoad(uint32_t page){

    uint8_t i=0;
    while(i<32){ FLASHBF[i] = *(__IO uint16_t *)(page+(2*i)); Delay_Ms(1); i++; }
}

void FlashWrite(uint32_t page, uint16_t data[32]){

    uint8_t i=0;

    FLASH_Unlock();
    FLASH_ErasePage(page);
    FLASH->CTLR |= (1<<0);

    while(i<32){ *(__IO uint16_t *)(page+(2*i)) = data[i]; Delay_Ms(6); i++; }

    FLASH->CTLR &= ~(1<<0);
    FLASH_Lock();
}

uint16_t FlashRead(uint32_t page,uint8_t slot){

    return (*(__IO uint16_t *)(page+(2*slot)));
}

// Ver 1.0 

/****************************************************************/
/**         PARA MAIS INFORMACOES - MORE INFORMATIONS          **/
/**           https://www.youtube.com/@PORTDTech               **/
/**              https://x.com/gustavo_portd                   **/
/****************************************************************/