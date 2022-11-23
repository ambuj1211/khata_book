#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<math.h>
#include <time.h>
#include <dir.h>
FILE *ptr;
void uca(char name[]);
void khata(void);
void wrt(char name[]);
void nc(char name[]);

void title()
{
	printf("\n\n\n\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2 CUSTOMER KAHTA BOOK  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
}
void date()
{
	int d, m, y;
	char day[3], month[4], year[3];
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	d = tm.tm_mday;
	itoa(d, day, 10);
	printf("%02s /", day);

	m = tm.tm_mon + 1;
	itoa(m, month, 10);
	printf(" %02s /", month);

	y = tm.tm_year + 1900;
	itoa(y, year, 10);
	printf(" %s", year);
}
void delay(int x)
{
	int i, k;
	for (i = 0; i < x; i++)
		k = i;
}
void welcome()
{
	int i;
	char a[] = "WELCOME";
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t");
	for (i = 0; i < 7; i++)
	{
		delay(100000000);
		printf("%c", a[i]);
	}
	delay(100000000);
}
void check(char name[])
{
	char p;
	ptr = fopen(name, "r");
	if (ptr == NULL)
	{
		system("cls");
		wrt(name);
	}
}
void r(char name[])
{
	system("cls");
	title();
	ptr = fopen(name, "r");
	printf("\n\nName : %s\n", name);
	printf("Date : ");
	date();
	printf("\n\n");
	char p;
	while (p != EOF)
	{
		p = fgetc(ptr);
		printf("%c", p);
	}
	fclose(ptr);
}
void read2(char name[])
{
	r(name);
	uca(name); // update customer account
}
void read1(char name[])
{
	check(name);
	r(name);
	char p;
	printf("\n\n\n\nAre you want to update \n if yes press y/Y");
	fflush(stdin);
	scanf("%c", &p);
	if (p == 'y' || p == 'Y')
		uca(name);
	else
		khata();
}
void save(char name[], int a, int b)
{
	ptr = fopen(name, "a");
	int d, m, y;
	char day[3], month[4], year[3], take[5], give[5];
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	d = tm.tm_mday;
	itoa(d, day, 10);
	fprintf(ptr, "\n");
	fprintf(ptr, day);
	//	printf("\n%s/",day);
	fprintf(ptr, "/");
	m = tm.tm_mon + 1;
	itoa(m, month, 10);
	//	printf(" %s/",month);
	fprintf(ptr, month);
	fprintf(ptr, "/");
	y = tm.tm_year + 1900;
	itoa(y, year, 10);
	//	printf(" %s",year);
	fprintf(ptr, year);

	fprintf(ptr, ".						");
	itoa(a, take, 10);
	fprintf(ptr, take);
	fprintf(ptr, ".						");
	itoa(b, give, 10);
	fprintf(ptr, give);
	fclose(ptr);
	khata();
}
void uca(char name[]) // uca = update customer account
{
	int a, b, c;
	printf("\n");
	date();
	printf("\t\t\t\t\t");
	scanf("%d", &a);
	printf("\t\t\t\t\t\t\t\t\t\t\t\t");
	scanf("%d", &b);
	printf("\n\n\t\t\t\t\t1.EDIT\n");
	scanf("%d", &c);
	if (c == 1)
		nc(name);
	else
		save(name, a, b);
}
void listr() // list reader
{
	ptr = fopen("khata book\\user profile\\List.dat", "r");

	if (ptr == NULL)
	{
		printf("No list found");
		return;
	}
	date();
	printf("\nCustomer Name\n\n");
	char p;
	while (p != EOF)
	{
		p = fgetc(ptr);
		printf("%c", p);
	}

	fclose(ptr);
	printf("----------------------------------------------------------------------------------------------");
}
void listw(char name[]) // list writer
{
	ptr = fopen("khata book\\user profile\\List.dat", "a");
	fprintf(ptr, ">>>  ");
	fprintf(ptr, name);
	fprintf(ptr, "\n");
	fclose(ptr);
}
void wrt(char name[])
{
	listw(name);
	ptr = fopen(name, "a");
	fprintf(ptr, "Date						Due						Paid\n");
	fprintf(ptr, "_____________________________________________________________________________________________________________________\n");
	fclose(ptr);
}
void nc(char name[])
{
	check(name);

	read2(name);
}
void khata()
{
	char arr[20];
	int opt;
	system("cls");
	title();

	char name[25], p;

	printf("\n\t\t\t   1.New Customer");
	printf("\n\t\t\t   2.Old Customer");
	printf("\n\t\t\t   3.List your Customer");
	printf("\n\n\n\t\t\t   9.EXIT");
	printf("\n\n\n\t\t\t Choose option : ");
	scanf("%d", &opt);
	if (opt == 9)
		return;
	else if (opt == 3)
	{
		listr(); // list read
		getch();
		khata();
	}
	else
	{

		printf("\n\n\t\t\tEnter customer name : ");
		scanf("%s", name);
	}
	switch (opt)
	{
	case 1:
		nc(name); // nc = new costomer
		break;	  // new customer
	case 2:
		read1(name); // read the data of costomer
		break;
	}
}

void password(void) // password management system { it check the password is correct or not if not then it give the option to reset password with your mobile number which you provide first time during making your profile}
{
	FILE *v;
	char mob2[11], mob3[11];
	char pass[20], pas[20];
	char arr[20];
	int i;
	char *abc;
	double mob, mob1;
start:
	ptr = fopen("khata book\\user profile\\password.dat", "r");
	fscanf(ptr, "%s", arr);
	system("cls");
	title();
	printf("\n\n\n\n\t\t\t\t    Enter the password to login : ");
	scanf("%s", &pass);
	if (strcmp(pass, arr) == 0)
	{
		printf("\n\n\nPassword Match!\n");
		printf("loading");
		for (i = 0; i < 6; i++)
		{
			delay(100000000);
			printf(".");
		}
		system("cls");
		welcome();
		for (i = 0; i < 6; i++)
			delay(100000000);
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLOADING");
		printf("\n\t\t\t");
		for (i = 0; i < 50; i++)
		{
			if (i < 10)
				delay(100000000);
			else
				delay(10000000);
			printf("\xb2");
		}
		delay(100000000);
		khata();
	}
	else
	{
		printf("1. try again\n");
		printf("2. forgot password\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			goto start;
			break;
		case 2:
		reset:
			v = fopen("khata book\\user profile\\mob.dat", "r");
			fscanf(v, "%s", mob2);
			mob = strtod(mob2,&abc);
			printf("Recovery Mobile number : +91-");
			scanf("%lf", &mob1);
			if (mob == mob1)
			{
				system("cls");
				title();
				printf("\n\n\n");
				printf("New password : ");
				scanf("%s", pass);
				
				printf("Confirm password : ");
				scanf("%s", pas);
				if (strcmp(pass, pas) == 0)
				{
					fclose(ptr);
					ptr = fopen("khata book\\user profile\\password.dat", "w");
					fprintf(ptr, pas);
					printf("Reset successfully\n\n");
					printf("Restart your application");
					fclose(ptr);
					getch();
					goto start;
					
				}
				else
				{
					printf("Not Match!\n\n");
					goto reset;
				}
			}
			printf("Number Not! matched\n\n");
			goto reset;
		default:
			goto start;
		}
	}
}
void user() // make a user profile { it is login profile which save the detail of user it runs only ones when you run first time in your computer}
{
	ptr = fopen("khata book\\user profile\\name.dat", "w");
	char st[20], ch;
	printf("\n\n\n\t\t\t\t\t\xb2\xb2\xb2 USER PROFILE \xb2\xb2\xb2");
	printf("\n\n\n\t\t\t\t\tNAME : ");
	scanf("%[^\n]", st);
	scanf("%c", &ch);
	fprintf(ptr, st);
	fclose(ptr);
	ptr = fopen("khata book\\user profile\\dob.dat", "w");
	printf("\n\t\t\t\t\tD.O.B : ");
	scanf("%[^\n]", st);
	scanf("%c", &ch);
	fprintf(ptr, st);
	fclose(ptr);
	ptr = fopen("khata book\\user profile\\mob.dat", "w");
	printf("\n\t\t\t\t\tMobile No. : ");
	fflush(stdin);
	scanf("%[^\n]", st);
	fprintf(ptr, st);
	fclose(ptr);
}
int main()
{
	mkdir("khata book");
	mkdir("khata book\\user profile");
	system("cls");
	char arr[20], p, a[20], pas[20];
	int i = 0;
	system("color f5");
	ptr = fopen("khata book\\user profile\\password.dat", "r");

	while (p != EOF)
	{
		p = fgetc(ptr);
		i++;
	}
	i--;
	if (i == 0)
	{
		title();
		user();
	set:
		printf("\n\n\n\n\t\t\t\tCreate your password : ");
		scanf("%s", arr);
		printf("\t\t\t\tConfirm password : ");
		scanf("%s", pas);
		if (strcmp(arr, pas) == 0)
		{
			fclose(ptr);
			ptr = fopen("khata book\\user profile\\password.dat", "w");
			fprintf(ptr, pas);
			fclose(ptr);
		}
		else
		{
			printf("\t\t\t\tNot Match!\n\n");
			goto set;
		}
	}
	password();
	//	printf("\t\t\t\tYour I'd is created \n\t\t\t\tNow restart the application");
}
