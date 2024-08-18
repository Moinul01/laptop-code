/*program name:Calendar application*/
/*programmers name:Tasnova Haque Mazumder(ID 2021-3-60-235)
                   Tawhidur Rahman(ID 2021-3-60-233)
                   Moinul Islam(ID 2021-3-60-241)*/
/*Date:22/1/2022*/



#include<stdio.h>

#define TRUE    1
#define FALSE   0

int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{
    " ",
	"\n\n\nJanuary |",
	"\n\n\nFebruary |",
	"\n\n\nMarch |",
	"\n\n\nApril |",
	"\n\n\nMay |",
	"\n\n\nJune |",
	"\n\n\nJuly |",
	"\n\n\nAugust |",
	"\n\n\nSeptember |",
	"\n\n\nOctober |",
	"\n\n\nNovember |",
	"\n\n\nDecember |"
};


int inputyear(void)
{
	int year;

	printf("enter a year : ");
	scanf("%d", &year);
	return year;
}

int determinedaycode(int year)
{
	int daycode;
	int d1, d2, d3;

	d1 = (year - 1)/ 4;
	d2 = (year - 1)/ 100;
	d3 = (year - 1)/ 400;
	daycode = (year + d1 - d2 + d3) %7;
	return daycode;
}


int determineleapyear(int year)
{
	if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE)
	{
		days_in_month[2] = 29;
		return TRUE;
	}
	else
	{
		days_in_month[2] = 28;
		return FALSE;
	}
}

void calendar(int year, int daycode)
{
	int month, day;
	for ( month = 1; month <= 12; month++ )
	{
		printf("%s", months[month]);
		printf("%d",year);
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );


		for ( day = 1; day <= 1 + daycode * 5; day++ )
		{
			printf(" ");
		}


		for ( day = 1; day <= days_in_month[month]; day++ )
		{
			printf("%2d", day );


			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}

			daycode = ( daycode + days_in_month[month] ) % 7;
	}
}

int main(void)
{
	int year, daycode,i=0;
   while(1){
	year = inputyear();
	daycode = determinedaycode(year);
	determineleapyear(year);
	calendar(year, daycode);
	printf("\n");}
}


/*int main() {


    char s1[100];
    char s2[100];
    int i,n;
    scanf("%d",&n);
    scanf("%s",&s1);
    scanf("%s",&s2);
    for(i=0;i<=n;i+2)
    {
        printf("%s",s1[i]);

    }for(i=1;i<=n;i+2)
    {
        printf("%s",s1[i]);
    }

    return 0;
}*/
