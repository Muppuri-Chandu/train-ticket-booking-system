#include "header.h"

void save_logs(user *node)
{
	FILE *fp=NULL;
	user *temp=NULL;
	fp=fopen("user_logins.txt","w");
	temp=node;
	while(temp!=NULL)
	{
		fwrite(temp,size,1,fp);
		temp=temp->link;
	}
	fclose(fp);
}
