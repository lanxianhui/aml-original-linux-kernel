#ifndef __ATA_MISC_H
#define __ATA_MISC_H

#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/err.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/delay.h>
    
#include <asm/arch/am_regs.h>
#include <asm/cacheflush.h>
#include <asm/delay.h>
    
#define ata_get_timer_tick()      	READ_ISA_REG(IREG_TIMER_E_COUNT)	//unit: 10us or 1/100ms, max: 0 ~ 0xFFFFFF
#define ATA_MAX_TIMER_TICK        	0xFFFFFF
#define TIMER_1US					1
#define TIMER_10US					(10*TIMER_1US)
#define TIMER_1MS					(100*TIMER_10US)




#define ATA_DEBUG
    
#define Debug_Printf				printk
    
//Definition to use block address 0x3400000
//#define AMLOGIC_CHIP_SUPPORT
    
#ifdef AMLOGIC_CHIP_SUPPORT
#ifdef AVOS
#define WRITE_BYTE_TO_FIFO(DATA)	{WRITE_MPEG_REG(HFIFO_DATA,DATA);while((READ_MPEG_REG(BFIFO_LEVEL)>>8) >= 120){}}
#else				/* 
#define WRITE_BYTE_TO_FIFO(DATA)    {Wr(HFIFO_DATA,DATA);while((Rd(BFIFO_LEVEL)>>8) >= 120){}}
#endif				/* 
#endif				/* 
    
//Definition for debug
    
#define ata_malloc                  kmalloc
#define ata_free                    kfree
    
#define ATABASE                      	0xC1000000
    
#define WRITE_ATA_REG(reg, val) 		{ *(volatile unsigned *)(ATABASE + ((reg) << 2)) = (val); }
#define READ_ATA_REG(reg) 				(IO_READ32(ATABASE + ((reg) << 2)))
    
#define ata_delay_us						udelay
#define ata_delay_ms						msleep
#define ata_delay_100ns						udelay





//Delay time in 100 ns
//void ata_delay_100ns(unsigned long num_100ns);
    
#endif				// __ATA_MISC_H