#include "DriverLib/DriverLib.h"


uint16_t MAIN_u16WDTInterval(uintptr_t ptrBlock, uint16_t u16Source);
uint16_t MAIN_u16DMASoftware(uintptr_t ptrBlock, uint16_t u16Source);

#define LED1_PORT (GPIO_enPORT1)
#define LED1_PIN (GPIO_enPIN_NUMBER0)
#define LED3_PORT (GPIO_enPORT1)
#define LED3_PIN (GPIO_enPIN_NUMBER2)
#define LED4_PORT (GPIO_enPORT1)
#define LED4_PIN (GPIO_enPIN_NUMBER3)
#define TEST_PORT (GPIO_enPORT3)
#define TEST_PIN (GPIO_enPIN_NUMBER4)


uint8_t pu8BufferOut[500U] = {0U};

/**
 * main.c
 */
uint8_t u8Activate = 0U;


uint32_t u32Operand1 = 0UL;
uint32_t u32Operand2 = 0UL;
int32_t s32Operand1 = 0UL;
int32_t s32Operand2 = 0UL;
uint16_t u16Operand1_HI = 0U;
uint16_t u16Operand1_LO = 0U;
uint16_t u16Operand2_HI = 0U;
uint16_t u16Operand2_LO = 0U;

uint32_t u32ValueTemp = 0UL;
uint32_t u32ValueTemp1 = 0UL;
uint64_t u64ValueTemp1 = 0UL;

uint32_t u32ValueTemp_ = 0UL;
uint64_t u64ValueTemp_ = 0UL;
uint32_t u32ValueTemp1_ = 0UL;
uint64_t u64ValueTemp1_ = 0UL;

uint16_t u16Sign[4U] = {0U};

int64_t s64Value_ = 0LL;
int64_t s64Value1_ = 0LL;

void main(void)
{
    uint16_t u16Iter = 0U;
    WDT_Config_t stWDTConfig =
    {
        WDT_enENABLE_RUN,
        WDT_enINT_ENABLE_ENA,
        WDT_enMODE_INTERVAL,
        WDT_enCLOCK_ACLK,
        WDT_enINTERVAL_32768,
    };

    DMA_Config_t stDMAConfig =
    {
        DMA_enENABLE_DIS,
        DMA_enPRIORITY_STATIC,
        DMA_enFETCH_NEXT,
    };

    DMA_CH_ConfigExt_t stDMAChannelConfig =
    {
        100U,
        0x1100U,
        (uint16_t) &pu8BufferOut[0U],
        DMA_enCH_TRIGGER_SW,
        DMA_enCH_MODE_BLOCK,
        DMA_enCH_INCMODE_INCREMENT,
        DMA_enCH_INCMODE_INCREMENT,
        DMA_enCH_DATASIZE_BYTE,
        DMA_enCH_DATASIZE_BYTE,
        DMA_enCH_SENSE_EDGE,
        DMA_enCH_ENABLE_ENA,
        DMA_enCH_ABORT_CLEAR,
        DMA_enCH_INT_ENABLE_ENA,
        DMA_enCH_INT_STATUS_NOOCCUR,
    };

    SVS->CTL_bits.VLD = 0U;
    WDT__vSetEnable(WDT_enENABLE_STOP); /*  stop watchdog timer*/

    GPIO__vSetDirectionByNumber(TEST_PORT, TEST_PIN, GPIO_enDIR_OUTPUT);
    GPIO__vSetSelectionByNumber(TEST_PORT, TEST_PIN, GPIO_enSEL_IO);

    /** Rosc*/
    GPIO__vSetDirectionByNumber(GPIO_enPORT2, GPIO_enPIN_NUMBER5, GPIO_enDIR_INPUT);
    GPIO__vSetSelectionByNumber(GPIO_enPORT2, GPIO_enPIN_NUMBER5, GPIO_enSEL_PERIPHERAL);


    CLOCK__vSetLFXT1FrequencyMode(CLOCK_enFREQMODE_LOW);
    CLOCK__vSetXT2Enable(CLOCK_enENABLE_ENA);
	do
	{
	    CLOCK_IFG1_R &= ~ CLOCK_IFG1_R_IFG_MASK;
	    for(u16Iter = 0U; u16Iter < 4000U; u16Iter++); /*At least 50us*/
	}while(0U != (CLOCK_IFG1_R_IFG_MASK & CLOCK_IFG1_R));

    CLOCK__enSetACLKSource(CLOCK_enSOURCE_LFXT1); /*32768 Hz*/
	CLOCK__enSetMCLKSource(CLOCK_enSOURCE_DCO); /*~8 MHz*/
    CLOCK__enSetSMCLKSource(CLOCK_enSOURCE_XT2); /*8 MHz*/

    WDT__vRegisterIRQSourceHandler(&MAIN_u16WDTInterval);
    WDT__vSetConfig(&stWDTConfig);


    DMA_CH__vRegisterIRQSourceHandler(DMA_enCH0, DMA_enCH_TRIGGER_SW, &MAIN_u16DMASoftware);

    DMA__vSetConfig(&stDMAConfig);
    DMA_CH__vSetConfigExt(DMA_enCH0, &stDMAChannelConfig);

    _EINT();
	while(1U)
	{
	    u32Operand1 = 0x8FFFFFFFULL;
        u32Operand2 = 0x8FFFFFFFULL ;
        s32Operand1 = 0x8FFFFFFFLL;
        s32Operand2 = 0x8FFFFFFFLL ;
        u16Operand1_HI = (u32Operand1 >> 16U) & 0xFFFFUL;
        u16Operand1_LO = u32Operand1 & 0xFFFFUL;
        u16Operand2_HI = (u32Operand2 >> 16U) & 0xFFFFUL;
        u16Operand2_LO = u32Operand2 & 0xFFFFUL;



	    MPY = u16Operand1_LO;
	    OP2 = u16Operand2_LO;
	    _NOP();
	    u32ValueTemp = RESHI;
	    u32ValueTemp <<= 16U;
	    u32ValueTemp |= RESLO;
        u16Sign[0U] = SUMEXT;

	    OP2 = u16Operand2_HI;
        _NOP();

	    u32ValueTemp1 = RESHI;
	    u32ValueTemp1 <<= 16U;
	    u32ValueTemp1 |= RESLO;
        u16Sign[1U] = SUMEXT;

	    u64ValueTemp1 = u32ValueTemp1;
	    u64ValueTemp1 <<= 16U;

	    u64ValueTemp1 += u32ValueTemp;









        MPY = u16Operand1_HI;
        OP2 = u16Operand2_LO;
        _NOP();

        u32ValueTemp_ = RESHI;
        u32ValueTemp_ <<= 16U;
        u32ValueTemp_ |= RESLO;
        u16Sign[2U] = SUMEXT;

        u64ValueTemp_ = u32ValueTemp_;
        u64ValueTemp_ <<= 16UL;

        MPY = u16Operand1_HI;
        OP2 =  u16Operand2_HI;
        _NOP();

        u32ValueTemp1_ = RESHI;
        u32ValueTemp1_ <<= 16U;
        u32ValueTemp1_ |= RESLO;
        u16Sign[3U] = SUMEXT;
        u32ValueTemp1_ -= SUMEXT;

        u64ValueTemp1_ = u32ValueTemp1_;
        u64ValueTemp1_ <<= 32U;

        u64ValueTemp1_ += u64ValueTemp_;


        u64ValueTemp1_ += u64ValueTemp1;

        s64Value_ = (int64_t) s32Operand1 * (int64_t) s32Operand2;

	}
}

uint16_t MAIN_u16WDTInterval(uintptr_t ptrBlock, uint16_t u16Source)
{
    static uint8_t u8Level = 1U;
    u8Level ^= 1U;
    GPIO__vSetOutputByNumber(TEST_PORT, TEST_PIN, (GPIO_nLEVEL) u8Level);
    DMA_CH__vRequestSWTransfer(DMA_enCH0);
    return (0U);
}


uint16_t MAIN_u16DMASoftware(uintptr_t ptrBlock, uint16_t u16Source)
{
    static uint16_t u16Count = 0U;
    if(400UL > u16Count)
    {
        u16Count += 100U;
    }
    else
    {
        u16Count = 0U;
    }
    DMA_CH__vSetDestAddress(DMA_enCH0, (uint16_t) &pu8BufferOut[u16Count]);
    DMA_CH__vSetSourceAddress(DMA_enCH0, 0x1100U + u16Count);
    DMA_CH__vSetEnable(DMA_enCH0, DMA_enCH_ENABLE_ENA);
    return (0U);
}

