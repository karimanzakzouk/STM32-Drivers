#ifndef _PROTOCOL_H_
#define _PROTOCOL_H_


typedef struct
{
	u8 SOF;
	u8 ID;
	u8 Data_Len;
	u8 Response;

}Header_t;


typedef struct
{
	Header_t  Header;
	u8 Data[8];
	u8 EOF;

}Protocol_t;


extern u8 Protocol_ConstructFrame(u8 ID , u8** buffer);


extern u8 Protocol_GetFrameLength(u8 ID);


extern u8 Protocol_ExtractData(u8 ID, u8** buffer);



#endif
