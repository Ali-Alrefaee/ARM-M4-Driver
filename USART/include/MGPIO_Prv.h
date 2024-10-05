#ifndef MGPIO_PRV_H
#define MGPIO_PRV_H



typedef struct
{
	uint32 MODER;
	uint32 OTYPER;
	uint32 OSPEEDR;
	uint32 PUPDR;
	uint32 IDR;
	uint32 ODR;
	uint32 BSRR;
	uint32 LCKR;
	uint32 AFRL;
	uint32 AFRH;
}MGPIOX_t;


#define GPIOA_BASE_ADDRESS   0x40020000
#define GPIOB_BASE_ADDRESS   0x40020400
#define GPIOC_BASE_ADDRESS   0x40020800

#define GPIOA       ((volatile MGPIOX_t*)(GPIOA_BASE_ADDRESS))
#define GPIOB       ((volatile MGPIOX_t*)(GPIOB_BASE_ADDRESS))
#define GPIOC       ((volatile MGPIOX_t*)(GPIOC_BASE_ADDRESS))



#define GPIO_MASK               3
#define GPIO_ALTERNATIVE_MASK  15

#endif
