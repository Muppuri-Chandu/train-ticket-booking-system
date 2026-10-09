#include"header.h"

void booking_info(book *ptr)
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
		//printf("%s     %d     %s   \n",tp->username,tp->train_no,tp->date);
		//printf("%s\n",name);
		if(strcmp(tp->username,name)==0)
		{
		if((tp->train_no == t_no) && (strcmp(tp->date,dt)==0))
		{
			flag=1;
			printf("Booked seat no : %d\n",tp->seat_no);
		}
		}
		
		tp=tp->link;
	}
	if(flag==0)
	{
		printf("No tickets booked on this date.\n");
		return;
	}	
//	printf("How many passengers you want to display\n");
//	scanf("%d",&seats);
//	for(i=1;i<=seats;i++)
	{
//		printf("%d. Which seat number you want to display\n",i);
//		scanf("%d",&s_no);

		found=0;
		tp=p;

		printf("Passenger Details:\n");
		while(tp != NULL)
		{
			if(strcmp(tp->username,name)==0)
			{
			if((tp->train_no == t_no) && (strcmp(tp->date,dt)==0))
			{
				found=1;
				printf("Seat No : %d\n",tp->seat_no);
				printf("Name : %s\n",tp->name);
				printf("Age : %d\n",tp->age);
				printf("Gender : %s\n\n",tp->Gender);
			//	break;
			}
			}
			tp=tp->link;
		}
		if(found == 0)
		{
			printf("%d seat is not booked\n",s_no);
		}
		
	}
}
