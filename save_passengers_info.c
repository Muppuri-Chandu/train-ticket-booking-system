#include "header.h"

void save_passengers_info(passenger *node)
{
	FILE *fp=NULL;
	passenger *temp=NULL;
	fp=fopen("passengers_info.txt","w");
	temp=node;
	while(temp!=NULL)
	{
		fwrite(temp,size2,1,fp);
		temp=temp->link;
	}
	fclose(fp);
}
