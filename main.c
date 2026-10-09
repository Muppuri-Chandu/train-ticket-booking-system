#include "header.h"

int main()
{
	int op;
	while(1)
	{
		printf("1.sing-up\n2.sign-in\n3.exit\n");
		scanf("%d",&op);
		switch(op)
		{	
			case 1:sign_up();
		       		break;
			case 2:sign_in();
		       		break;
			case 3:exit(0);
		}
	}	
}
