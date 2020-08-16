#ifndef DMA_H
#define DMA_H

//DMA channels 
#define CHNL_0 0x87
#define CHNL_1 0x83
#define CHNL_2 0x81
#define CHNL_3 0x82
#define CHNL_4 0x8f //can't be used due to cascading
#define CHNL_5 0x8b
#define CHNL_6 0x89
#define CHNL_7 0x8a

//io ports of programming registers
#define WRITE_MODE_8 0x0b
#define WRITE_MODE_16 0xd6
#define SINGLE_MASK_8 0x0a
#define SINGLE_MASK_16 0xd4
#define CLEAR_FLIPFLOP_8 0x0c
#define CLEAR_FLIPFLOP_16 0xd8

//register functions

//control bytes
#define DEMAND_MODE 0 //00
#define SINGLE_MODE 64 //01
#define BLOCK_MODE 128 //10 
#define CASCADE_MODE 192 //11

//address increment/decrement bit 5
#define ADDRESS_DECREMENT 32 //1
#define ADDRESS_INCREMENT 0 //0

//auto initialize enable bit 4
#define AUTO_INIT 16 //1
#define SINGLE_CYCLE 0 //0

//dma buffer sizes 
#define DMA_BUFFER 4096

//transfer types
#define VERIFY_TRANSFER 0 //00
#define WRITE_TRANSFER 4 //01
#define READ_TRANSFER 8 //10

struct dma_profile
{
	unsigned char control_byte = 0;
	unsigned char control_byte_mask = 0;
	unsigned char address_port = 0;
	unsigned char page_port = 0;
	unsigned char mask_register = 0;
	unsigned char clear_register = 0;
	unsigned char mode_register = 0;
	unsigned char channel = 0;
}

int dma_init(struct dma_profile profile);
void set_control_byte_mask(struct dma_profile profile);
void set_control_byte(struct dma_profile profile);
void set_dma_channel(struct dma_profile profile);
void set_ports(struct dma_profile profile);
void enable_channel(struct dma_profile profile);
void disable_channel(struct dma_profile profile);
void clear_flipflop(struct dma_profile profile);
void set_transfer_length(struct dma_profile profile);
void allocate_buffer(struct dma_profile profile);
void set_buffer_info(struct dma_profile profile);

#endif
