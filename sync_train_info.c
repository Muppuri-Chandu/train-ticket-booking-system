#include "header.h"

train *sync_train_info()
{
	train *new=NULL,*head=NULL,*temp=NULL;
	FILE *fp=NULL;
	fp=fopen("train_details.txt","r");
	if(fp==NULL)
	{
		return head;
	}
	int ret;
	while(1)
	{
		new=malloc(sizeof(train));
		ret=(fscanf(fp,"%d %29s %29s %29s %d",&new->train_no,new->train_name,new->source,new->destination,&new->no_of_seats));
		//printf("fscanf returns = %d\n",ret);
		//printf("%d %29s %29s %29s %d\n",new->train_no,new->train_name,new->source,new->destination,new->no_of_seats);
		if(ret!=5)
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
