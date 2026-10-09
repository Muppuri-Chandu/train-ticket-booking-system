#include "header.h"

int size2=sizeof(passenger)-sizeof(passenger *);
passenger *sync_passengers_info()
{
	passenger *node=NULL,*ptr=NULL,*temp=NULL,var;
	FILE *fp=NULL;
	fp=fopen("passengers_info.txt","r");
	if(fp==NULL)
	{
		return ptr;
	}
	else
	{
		while((fread(&var,size2,1,fp))==1)
		{
		node=calloc(1,sizeof(passenger));
		if(node == NULL)
		{
			fclose(fp);
			return ptr;
		}
		strcpy(node->username,var.username);
		node->seat_no=var.seat_no;
		node->train_no=var.train_no;
		strcpy(node->date,var.date);
		strcpy(node->name,var.name);
		node->age=var.age;
		strcpy(node->Gender,var.Gender);
		node->link=NULL;
		if(ptr==NULL)
		{
			ptr=node;
		}
		else
		{
			temp=ptr;
			while(temp->link != NULL)
			{
				temp=temp->link;
			}
			temp->link=node;
		}
		}
		fclose(fp);
		return ptr;
	}
}
