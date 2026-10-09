#include "header.h"
char name[100];
void sign_in()
{
	user *head=NULL,*temp=NULL;
	int cnt=0;
	head=usr_logins();
	char pwd[20];
log:	printf("Enter Username\n");
	__fpurge(stdin);
	scanf("%s",name);
	printf("Enter password\n");
	__fpurge(stdin);
	scanf("%s",pwd);
	cnt++;
	if(head==NULL)
	{
		printf("No account found..\nFirst sign up with new account..\n");
	}
	else
	{
			temp=head;
			while(temp!=NULL)
			{
				//puts(temp->usr_name);
				//puts(temp->password);
				if((strcmp(temp->usr_name,name)==0) && (strcmp(temp->password,pwd)==0))
				{
					printf("Login Successful..\n");
					booking_menu();
				}
				temp=temp->link;
			}
			if(cnt==3)
			{
				printf("You have reached max limit..\nTry after some time...\n");
				exit(0);
			}
			else
			{
				printf("Incorrect login credentials\nTry again....\n");
				goto log;
			}
	}
}
