/*
# Author : Chiemezie Albert Udoh
# MCU	 : tm4c123 Launch pad
# Date   : 15.09.2022
# Files  : Startup_file
#
*/

#include <stdint.h>

# define SRAM_START (0x20000000U)
# define SRAM_SIZE (32U * 1024U)  //32KB
# define SRAM_END (SRAM_START + SRAM_SIZE)
# define STACK_START (SRAM_START + 0x00000428U)

extern uint32_t	_e_text;
extern uint32_t	_s_data;
extern uint32_t	_e_data;
extern uint32_t	__bss_start__;
extern uint32_t	__bss_end__;

// Prototype of main function
int	main(void);



void Reset_Handler(void);
void NMI_Handler(void)			__attribute__((weak, alias("Default_Handler")));
void Hardfault_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)			__attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)		__attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)		__attribute__((weak, alias("Default_Handler")));

// IRQ Exceptions (interrupts)
void GPIOPortA_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void GPIOPortB_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void GPIOPortC_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void GPIOPortD_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void GPIOPortE_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void UART0_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void UART1_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void SSI0_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void I2C0_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void PWMFault_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void PWMGen0_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void PWMGen1_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void PWMGen2_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void QEI0_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void ADCSeq0_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void ADCSeq1_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void ADCSeq2_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void ADCSeq3_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void Watchdog_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void Timer0A_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void Timer0B_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void Timer1A_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void Timer1B_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void Timer2A_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void Timer2B_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void Comp0_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void Comp1_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void SysCtrl_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void FlashCtrl_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void GPIOPortF_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void UART2_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void SSI1_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void Timer3A_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void Timer3B_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void I2C1_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void QEI1_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void CAN0_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void CAN1_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void Hibernate_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void USB0_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void PWMGen3_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void uDMAST_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void uDMAError_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void ADC1Seq0_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void ADC1Seq1_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void ADC1Seq2_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void ADC1Seq3_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void SSI2_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void SSI3_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void UART3_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void UART4_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void UART5_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void UART6_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void UART7_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void I2C2_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void I2C3_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void Timer4A_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void Timer4B_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void Timer5A_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void Timer5B_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void WideTimer0A_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void WideTimer0B_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void WideTimer1A_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void WideTimer1B_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void WideTimer2A_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void WideTimer2B_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void WideTimer3A_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void WideTimer3B_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void WideTimer4A_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void WideTimer4B_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void WideTimer5A_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void WideTimer5B_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void PWM1Gen0_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void PWM1Gen1_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void PWM1Gen2_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void PWM1Gen3_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));
void PWM1Fault_IRQHandler(void)		__attribute__((weak, alias("Default_Handler")));

uint32_t vector[] __attribute__((section (".isr_vector"))) = {
	STACK_START,
	(uint32_t)&Reset_Handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&Hardfault_Handler,
	(uint32_t)&MemManage_Handler,
	(uint32_t)&BusFault_Handler,
	(uint32_t)&UsageFault_Handler,
	0, // Reserved
	0, // Reserved
	0, // Reserved
	0, // Reserved
	(uint32_t)&SVC_Handler,
	(uint32_t)&DebugMon_Handler,
	0, // Reserved
	(uint32_t)&PendSV_Handler,
	(uint32_t)&SysTick_Handler,

	// IRQ Exceptions (interrupts)
	(uint32_t)&GPIOPortA_IRQHandler,
	(uint32_t)&GPIOPortB_IRQHandler,
	(uint32_t)&GPIOPortC_IRQHandler,
	(uint32_t)&GPIOPortD_IRQHandler,
	(uint32_t)&GPIOPortE_IRQHandler,
	(uint32_t)&UART0_IRQHandler,
	(uint32_t)&UART1_IRQHandler,
	(uint32_t)&SSI0_IRQHandler,
	(uint32_t)&I2C0_IRQHandler,
	(uint32_t)&PWMFault_IRQHandler,
	(uint32_t)&PWMGen0_IRQHandler,
	(uint32_t)&PWMGen1_IRQHandler,
	(uint32_t)&PWMGen2_IRQHandler,
	(uint32_t)&QEI0_IRQHandler,
	(uint32_t)&ADCSeq0_IRQHandler,
	(uint32_t)&ADCSeq1_IRQHandler,
	(uint32_t)&ADCSeq2_IRQHandler,
	(uint32_t)&ADCSeq3_IRQHandler,
	(uint32_t)&Watchdog_IRQHandler,
	(uint32_t)&Timer0A_IRQHandler,
	(uint32_t)&Timer0B_IRQHandler,
	(uint32_t)&Timer1A_IRQHandler,
	(uint32_t)&Timer1B_IRQHandler,
	(uint32_t)&Timer2A_IRQHandler,
	(uint32_t)&Timer2B_IRQHandler,
	(uint32_t)&Comp0_IRQHandler,
	(uint32_t)&Comp1_IRQHandler,
	0, // reserved
	(uint32_t)&SysCtrl_IRQHandler,
	(uint32_t)&FlashCtrl_IRQHandler,
	(uint32_t)&GPIOPortF_IRQHandler,
	0, // reserved
	0, // reserved
	(uint32_t)&UART2_IRQHandler,
	(uint32_t)&SSI1_IRQHandler,
	(uint32_t)&Timer3A_IRQHandler,
	(uint32_t)&Timer3B_IRQHandler,
	(uint32_t)&I2C1_IRQHandler,
	(uint32_t)&QEI1_IRQHandler,
	(uint32_t)&CAN0_IRQHandler,
	(uint32_t)&CAN1_IRQHandler,
	0, // reserved
	0, // reserved
	(uint32_t)&Hibernate_IRQHandler,
	(uint32_t)&USB0_IRQHandler,
	(uint32_t)&PWMGen3_IRQHandler,
	(uint32_t)&uDMAST_IRQHandler,
	(uint32_t)&uDMAError_IRQHandler,
	(uint32_t)&ADC1Seq0_IRQHandler,
	(uint32_t)&ADC1Seq1_IRQHandler,
	(uint32_t)&ADC1Seq2_IRQHandler,
	(uint32_t)&ADC1Seq3_IRQHandler,
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	(uint32_t)&SSI2_IRQHandler,
	(uint32_t)&SSI3_IRQHandler,
	(uint32_t)&UART3_IRQHandler,
	(uint32_t)&UART4_IRQHandler,
	(uint32_t)&UART5_IRQHandler,
	(uint32_t)&UART6_IRQHandler,
	(uint32_t)&UART7_IRQHandler,
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	(uint32_t)&I2C2_IRQHandler,
	(uint32_t)&I2C3_IRQHandler,
	(uint32_t)&Timer4A_IRQHandler,
	(uint32_t)&Timer4B_IRQHandler,
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved   
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved   
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	(uint32_t)&Timer5A_IRQHandler,
	(uint32_t)&Timer5B_IRQHandler,
	(uint32_t)&WideTimer0A_IRQHandler,
	(uint32_t)&WideTimer0B_IRQHandler,
	(uint32_t)&WideTimer1A_IRQHandler,
	(uint32_t)&WideTimer1B_IRQHandler,
	(uint32_t)&WideTimer2A_IRQHandler,
	(uint32_t)&WideTimer2B_IRQHandler,
	(uint32_t)&WideTimer3A_IRQHandler,
	(uint32_t)&WideTimer3B_IRQHandler,
	(uint32_t)&WideTimer4A_IRQHandler,
	(uint32_t)&WideTimer4B_IRQHandler,
	(uint32_t)&WideTimer5A_IRQHandler,
	(uint32_t)&WideTimer5B_IRQHandler,
	(uint32_t)0x000001E8,  // System Exception (imprecise)
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	0, // reserved
	(uint32_t)&PWM1Gen0_IRQHandler,
	(uint32_t)&PWM1Gen1_IRQHandler,
	(uint32_t)&PWM1Gen2_IRQHandler,
	(uint32_t)&PWM1Gen3_IRQHandler,
	(uint32_t)&PWM1Fault_IRQHandler
};

void Reset_Handler(void)
{
	uint32_t size;
	uint32_t idx;
	uint8_t	 *p_src;
	uint8_t  *p_dst;

	idx = 0;
	// copy .data section to SRAM
	size = (uint32_t)&_e_data - (uint32_t)&_s_data;
	p_src = (uint8_t *)&_s_data; 	
	p_dst = (uint8_t *)&_e_text; 	
	while (idx < size)
	{
		*p_dst++ = *p_src++;
		idx++;
	}
	// Init .bss section to o in SRAM
	size = &__bss_end__ - &__bss_start__;
	p_dst = (uint8_t *)&__bss_start__;
	idx = 0;
	while (idx < size)
	{
		*p_dst++ = 0;
		idx++;
	}
	// call main()
	main();
}

void Default_Handler(void)
{
	while (1);
}

