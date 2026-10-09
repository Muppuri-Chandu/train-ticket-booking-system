#include "header.h"

void reserve_ticket(book *ptr)
{
	passenger *p,*new=NULL,*pt=NULL;
        train *t,*tp=NULL,*temp=NULL;
        seat *s,*s_h=NULL;
	p=ptr->p_head;
	t=ptr->t_head;
	s=ptr->s_head;
	int t_no,s_req;
	char dt[20];
	s_h=s;
tt:	printf("Enter the train number\n");
	scanf("%d",&t_no);
	tp=t;
	while(tp != NULL)
	{
		if(tp->train_no == t_no)
		break;
		tp=tp->link;
	}
	if(tp == NULL)
	{
		printf("Train not found..\n");
		temp=ptr->t_head;
		while(temp!=NULL)
        	{
                printf("%d  %29s   %29s   %29s   %d\n",
        temp->train_no,temp->train_name,temp->source,
        temp->destination,temp->no_of_seats);
                temp=temp->link;
        	}
		goto tt;
	}
	printf("Date of journey\n");
	__fpurge(stdin);
	scanf("%s",dt);
	printf("No_of_seats_required\n");
	scanf("%d",&s_req);
	int rem=0,cnt=0;
	while(s != NULL)
	{
		if(s->train_no == t_no)
		{
			if(s->total_seats != 0)
			{
				if(s_req > s->total_seats)
				{
					rem = (s_req - s->total_seats);
					s_req=s->total_seats;
				}
				break;
			}
			else
			{
				char ch;
				printf("No seats available\n");
				printf("If you want to choose another train..Click on t otherwise q\n");
				__fpurge(stdin);
				scanf("%c",&ch);
				if(ch=='t')
				{
					goto tt;
				}
				else
				{
					return;
				}
			}
		}
		s=s->link;
	}
	for(int i=1;i<=s_req;i++)
	{
		new=calloc(1,sizeof(passenger));
		strcpy(new->username,name);
		new->seat_no=s->current_booking_seat+1;
		new->train_no=t_no;
		strcpy(new->date,dt);
		printf("Enter %d name\n",i);
		__fpurge(stdin);
		scanf("%s",new->name);
		printf("Enter age\n");
		scanf("%d",&new->age);
		printf("Enter Gender\n");
		__fpurge(stdin);
		scanf("%s",new->Gender);

		new->link=NULL;
		if(p==NULL)
		{
			p=new;
			ptr->p_head=p;
		}
		else
		{
			pt=p;
			while(pt->link != NULL)
			{
				pt=pt->link;
			}
			pt->link=new;
		}
		pt=p;
		while(pt!=NULL)
		{
			cnt=0;
			if((pt->train_no==t_no) && (strcmp(pt->date,dt)==0))
			{
				cnt++;
			}
			pt=pt->link;
		}
		s->current_booking_seat += cnt;
		s->total_seats -= cnt;
	}

	printf("\n%d tickets booked successfully.\n",s_req);
	if(rem > 0)
	{
		s->waiting_list += rem;
		printf("%d passengers could not be booked because seats are not available.\n",rem);
	}
	save_passengers_info(p);

	save_seat_info(s_h);

}
