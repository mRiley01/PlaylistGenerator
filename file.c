#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(void)
{

//Write to a file

	FILE *fptr, *rptr;
	int account = 0;
	char name[30];
	double balance = 0.0;


	if((fptr = fopen("clients.txt", "w")) == NULL)
	{
		puts("File could not be opened");
	}
	else
	{
		puts("Enter the account, name, and balance");
		puts("Enter EOF to end input");
		scanf("%d%29s%lf", &account, name, &balance);

		while(!feof(stdin))
		{
			fprintf(fptr, "%d %s %.2f \n", account, name, balance);
			printf("%s", "? ");
			scanf("%d%29s%lf", &account, name, &balance);
		}
		fclose(fptr);
	}


	//Read from a file

		if((rptr = fopen("clients.txt", "r")) == NULL)
		{
			puts("File does not exist");
		}
		else
		{
			fscanf(rptr, "%d%29s%lf", &account, name, &balance);
			while(!feof(rptr))
			{
				fscanf(rptr, "%d%29s%lf", &account, name, &balance);
				printf("account = %d, name = %s, balance = %.2f \n", account, name, balance);
			}

		}
		fclose(rptr);

	return EXIT_SUCCESS;
}
