/*
 * protocol.c
 *
 *  Created on: May 15, 2020
 *      Author: kariman
 */

#include "STD_TYPES.h"
#include "protocol.h"
#include "protocol_cfg.h"



#define  HEADER_LENGTH             4U
#define  EOF_LENGTH                1U


extern u8 data_size[];



u8 Protocol_ConstructFrame(u8 ID , u8** buffer)
{
	u8 EOF_idx;

	Protocol_t* frame = (Protocol_t*) (*buffer);

	frame->Header.ID = ID;

	frame->Header.SOF = START_OF_FRAME;

	frame->Header.Data_Len = data_size[ID];

	EOF_idx = HEADER_LENGTH + frame->Header.Data_Len;

	(*buffer)[EOF_idx] = END_OF_FRAME;

	(*buffer) += HEADER_LENGTH;

	return (EOF_idx + EOF_LENGTH);
}


u8 Protocol_GetFrameLength(u8 ID)
{
	return (HEADER_LENGTH + data_size[ID] + EOF_LENGTH);
}


u8 Protocol_ExtractData(u8 ID, u8** buffer)
{
	u8 local_Status = ERROR_OK;

	Protocol_t* frame = (Protocol_t*) (*buffer);

	if(frame->Header.ID == ID)
	{
		(*buffer) += HEADER_LENGTH;
	}
	else
	{
		local_Status = ERROR_NOK;
	}

	return local_Status;
}

