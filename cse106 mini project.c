#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int a[5000][5000];
int main() {
	int n;
	int in_deg=0, out_deg=0;
	printf("Number of vertices: ");
	scanf("%d", &n);

	int i,j,m;
	clock_t start_clock, end_clock;

	double computational_time;

	for(i=1;i<n;i++)
    {
		for(j=1;j<n;j++)
		{
			a[i][j]=0;
		}
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			if (i==j)
			{
				a[i][j]=0;
			}
			else
			{
				m = rand() % 2;
				if(m==1)
				{
					if(a[i][j]==0)
					{
						a[i][j]=1;
						a[j][i]=1;
					}
				}

            }

		}
	}

    start_clock = clock();
	for (i = 1; i <= n ; i++ )
    {
	for ( j = 1 ; j <= n ; j++ )
	{
            if ( a[j][i] == 1 ){
                in_deg++;
                }
	}
      for ( j = 1 ; j <= n ; j++ )
            if (a[i][j] == 1 )
            out_deg++;
    }
    end_clock = clock();

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);

		if(j==(n-1))
		{
			printf("\n");
		}
		}
	}

	printf("In Degree: %d \nOut Degree: %d", in_deg, out_deg);

	computational_time = ((double)end_clock - start_clock) ;
	computational_time = computational_time*1000;

    printf("\nComputational time: %f milliseconds", computational_time);

	return 0;
}
