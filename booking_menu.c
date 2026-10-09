#include "header.h"

void booking_menu()
{
	char ch;
	passenger *p_head=NULL;
	train *t_head=NULL;
	seat *s_head=NULL;
	p_head=sync_passengers_info();
	t_head=sync_train_info();
	s_head=sync_seat_info();
	train *temp=NULL;
	temp=t_head;
	while(temp!=NULL)
	{
		printf("%d  %29s   %29s   %29s   %d\n",
	temp->train_no,temp->train_name,temp->source,
	temp->destination,temp->no_of_seats);
		temp=temp->link;
	}
	book data;
	data.p_head=p_head;
	data.t_head=t_head;
	data.s_head=s_head;
	while(1)
	{
		printf("r:To reserve ticket\nc:To cancel ticket\nb:Booking details\nq:Quit\n");
		printf("Enter choice\n");
		__fpurge(stdin);
		scanf("%c",&ch);
		switch(ch)
		{
			case 'r':reserve_ticket(&data);
				 break;
			case 'c':cancel_ticket(&data);
				 break;
			case 'b':booking_info(&data);
				 break;
			case 'q':exit(0);
		}
	}
}
