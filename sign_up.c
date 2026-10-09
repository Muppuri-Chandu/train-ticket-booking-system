#include "header.h"


int pwdcheck(char *pwd)
{
	int up=0,lw=0,nm=0,sp=0;
	while(*pwd)
	{
		if(up==0 && (*pwd>=65 && *pwd<=90))
		{
			up=1;
		}
		else if(lw==0 && (*pwd>=97 && *pwd<=122))
		{
			lw=1;
		}
		else if(nm==0 && (*pwd>=48 && *pwd<=57))
		{
			nm=1;
		}
		else if(sp==0 && ((*pwd>=33 && *pwd<=47) || (*pwd>=58 && *pwd<=64) || (*pwd>=91 && *pwd<=96) || (*pwd>=123 && *pwd<=126)))
		{
			sp=1;
		}
		pwd++;
	}
	if(up==1 && lw==1 && nm==1 && sp==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void sign_up()
{
	int flag=0;
	user *node=NULL,*ptr=NULL,*head=NULL,*temp=NULL;
	head=usr_logins();
	node=calloc(1,sizeof(train));
	printf("Enter username\n");
	__fpurge(stdin);
usr:	scanf("%s",node->usr_name);
	ptr=head;
	temp=ptr;
	while(temp!=NULL)
	{
		if(strcmp(temp->usr_name,node->usr_name)==0)
		{
			printf("name already exist.\nTry with another name\n");
			goto usr;
		}
		temp=temp->link;
	}
	printf("Enter password\n");
	__fpurge(stdin);
pwd:	scanf("%s",node->password);
	//ptr=head;
	if(strlen(node->password)<8)
	{
		flag++;
		if(flag==5)
		{
			printf("You already entered password incorrectly 5 times.\nTIME OUT......\n");
			exit(0);
		}
		else
		{
			printf("Password must be atleast 8 characters\nTry again\n");
			goto pwd;
		}
	}
	if(pwdcheck(node->password)==1)
	{
		if(ptr==NULL)
		{
			head=node;
			save_logs(head);
			printf("Accout created successfully....\n");
		}
		else
		{
			temp=ptr;
			while(temp->link != NULL)
			{
				temp=temp->link;
			}
			temp->link=node;
			save_logs(head);
			printf("Accout created successfully....\n");
		}
	}
	else
	{
		printf("password doesn't meet login requirements..\nPassword must contain atleast 1 Try new password.");
		flag++;
		if(flag==5)
		{
			printf("You already entered password incorrectly 5 times.\nTIME OUT......\n");
			exit(0);
		}
		else
		{
			goto pwd;
		}
	}
}

