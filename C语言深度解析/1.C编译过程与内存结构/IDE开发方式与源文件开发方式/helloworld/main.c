#define STM32F40_41xxx
void SystemCoreClockUpdate(void)
{
	/* 通用代码 */
	/* Get SYSCLK source ----*/
	tmp = RCC->CFGR & RCC_CFGR_SWS;
	
	switch (tmp)
	{
		case 0x00:  /* HSI used as system clock source */
		SystemCoreClock = HSI_VALUE;
		break;
		
		case 0x04:  /* HSE used as system clock source */
		SystemCoreClock = HSE_VALUE;
		break;
		
		case 0x08:  /* PLL P used as system clock source */
		
		pllsource = (RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC) >> 22;
		pllm = RCC->PLLCFGR & RCC_PLLCFGR_PLLM;
		
		
		/*————————————————差异性代码———————————————— */
		//定义了STM32F40_41xxx或者STM32F427_437xx或者STM32F429_439xx等宏时，代码有效
		
#if defined(STM32F40_41xxx) || defined(STM32F427souceinsight_437xx) || defined(STM32F429_439xx) || \
		defined(STM32F401xx) || defined(STM32F412xG) || defined(STM32F413_423xx) || \
		defined(STM32F446xx) || defined(STM32F469_479xx)
		if (pllsource != 0)
		{
			/* HSE used as PLL clock source */
			pllvco = (HSE_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);
		}
		else
		{
			/* HSI used as PLL clock source */
			pllvco = (HSI_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);
		}
		
		//否则如果定义了STM32F410xx或者STM32F411xE宏的话，以下代码有效
#elif defined(STM32F410xx) || defined(STM32F411xE)
		
		if (pllsource != 0)
		{
			/* HSE used as PLL clock source */
			pllvco = (HSE_BYPASS_INPUT_FREQUENCY / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);
		}  
		
		//同理
#endif /* STM32F40_41xxx || STM32F427_437xx || STM32F429_439xx || STM32F401xx || STM32F412xG || STM32F413_423xx ||  STM32F446xx || STM32F469_479xx */  
		
		
		pllp = (((RCC->PLLCFGR & RCC_PLLCFGR_PLLP) >>16) + 1 ) *2;
		SystemCoreClock = pllvco/pllp;      
		break;
		
		
		
		//同理
#if defined(STM32F412xG) || defined(STM32F413_423xx) || defined(STM32F446xx)      
		case 0x0C:  /* PLL R used as system clock source */
		
		pllsource = (RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC) >> 22;
		pllm = RCC->PLLCFGR & RCC_PLLCFGR_PLLM;
		if (pllsource != 0)
		{
			/* HSE used as PLL clock source */
			pllvco = (HSE_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);
		}
		else
		{
			/* HSI used as PLL clock source */
			pllvco = (HSI_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);      
		}
		
		pllr = (((RCC->PLLCFGR & RCC_PLLCFGR_PLLR) >>28) + 1 ) *2;
		SystemCoreClock = pllvco/pllr;      
		break;
#endif /* STM32F412xG || STM32F413_423xx || STM32F446xx */
		
		
	default:
		SystemCoreClock = HSI_VALUE;
		break;
	}
	
}
