#include "header.h"

void save_seat_info(seat *ptr)
{
	FILE *fp=NULL;
	fp=fopen("seat_details.txt","w");
	while(ptr!=NULL)
	{
		fprintf(fp,"%d   %d   %d   %d\n",ptr->train_no,ptr->total_seats,ptr->waiting_list,ptr->current_booking_seat);
		ptr=ptr->link;
	}
	fclose(fp);
}
