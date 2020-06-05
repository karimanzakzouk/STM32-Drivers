
#ifndef FLASH_H
#define FLASH_H





extern void FLASH_Unlock(void);

extern void FLASH_Lock(void);

extern void FLASH_ErasePage(u32 pageAddress);

extern void FLASH_EraseAllPages(void);

extern ERROR_STATUS FLASH_WriteWord(void* address , u32 data);

extern ERROR_STATUS FLASH_WriteProgramm(void* startAddress , void* dataAddress , u16 numberOfBytes);




#endif
