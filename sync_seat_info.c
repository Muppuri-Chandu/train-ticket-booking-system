#include "header.h"

seat *sync_seat_info()
{
	seat *new=NULL,*head=NULL,*temp=NULL;
	FILE *fp=NULL;
	fp=fopen("seat_details.txt","r");
	if(fp==NULL)
	{
		return head;
	}
	int ret;
	while(1)
	{
		new=malloc(sizeof(seat));
		ret=(fscanf(fp,"%d %d %d %d",&new->train_no,&new->total_seats,&new->waiting_list,&new->current_booking_seat));
		//printf("fscanf returns = %d\n",ret);
		//printf("%d %29s %29s %29s %d\n",new->train_no,new->train_name,new->source,new->destination,new->no_of_seats);
		if(ret!=4)
		{
			free(new);
			break;
		}
		new->link=NULL;
		if(head==NULL)
		{
			head=new;
		}
		else
		{
			temp=head;
			while(temp->link != NULL)
			{
				temp=temp->link;
			}
			temp->link=new;
		}
	}
	fclose(fp);
	return head;
}
