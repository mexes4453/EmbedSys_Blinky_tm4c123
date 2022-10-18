# include "php_led.h"

int main(void)
{

	PHP_LED_Init();
	while (1)
	{
		PHP_LED_Toggle_Blue();
		PHP_LED_Toggle_Red();
		PHP_LED_Toggle_Green();
	}

}
