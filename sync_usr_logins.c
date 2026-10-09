#include "header.h"

int size=sizeof(user)-sizeof(user *);
user *usr_logins()
{
	user *node=NULL,*ptr=NULL,*temp=NULL,var;
	FILE *fp=NULL;
	fp=fopen("user_logins.txt","r");
	if(fp==NULL)
	{
		return ptr;
	}
	else
	{
		while((fread(&var,size,1,fp))==1)
		{
		node=calloc(1,sizeof(user));
		strcpy(node->usr_name,var.usr_name);
		strcpy(node->password,var.password);
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
	
		return ptr;
	}
}
