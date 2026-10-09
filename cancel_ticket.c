#include"header.h"

void cancel_ticket(book *ptr)
{
	passenger *p,*prev,*tp=NULL;
        train *t;
        seat *s;
        p=ptr->p_head;
        t=ptr->t_head;
        s=ptr->s_head;
	int t_no;
	char dt[20];
	int i,seats,s_no,found,flag=0;
	printf("Enter train number\n");
	scanf("%d",&t_no);
	printf("Enter date\n");
	__fpurge(stdin);
	scanf("%s",dt);
	tp=p;
	while(tp != NULL)
	{
		if((tp->train_no == t_no) && (strcmp(tp->date,dt)==0))
		{
			flag=1;
			printf("Booked seat no : %d\n",tp->seat_no);
		}
		tp=tp->link;
	}
	if(flag==0)
	{
		printf("No ticket(s) found on this date.\n");
		return;
	}
	printf("How many seats you want to cancel\n");
	scanf("%d",&seats);
	for(i=1;i<=seats;i++)
	{
		printf("%d. Which seat(s) you want to cancel\n",i);
		scanf("%d",&s_no);
		found=0;
		tp=ptr->p_head;
		prev=NULL;
		while(tp!=NULL)
		{
			if(tp->seat_no == s_no)
			{	
				found=1;
				if(prev==NULL)
				{
					ptr->p_head=tp->link;
				}
				else
				{
					prev->link=tp->link;
				}
				free(tp);
				tp=NULL;
				break;
			}
			prev=tp;
                        tp=tp->link;
		}
		if(found==1)
		{
			printf("%d Cancellation successfull\n",s_no);
			s=ptr->s_head;
			while(s!=NULL)
			{
				if(s->train_no == t_no)
                        	{
                          		s->total_seats++;
					//s->current_booking_seat--;	
                                	break;
                        	}
                        	s=s->link;
			}
		}
		else
		{
			printf("%d no seat not booked\n",s_no);
		}

	}

	p=ptr->p_head;
	s=ptr->s_head;
	save_passengers_info(p);
	save_seat_info(s);

}
