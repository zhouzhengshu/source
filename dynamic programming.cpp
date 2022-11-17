#include<iostream>
using namespace std;
static double arr[2000][2000];
static int    sol[2000][2000][20];

double solveBKS(int w[], double v[],int s[], int index, int capacity)
{
	double res = 0.0;

	for(int i=0;i<2000;i++)
    {
	    for(int j=0;j<2000;j++)
		{
			arr[i][j]=0;
			for(int k=0;k<20;k++) sol[i][j][k]=0;
		}

    }

    for(int i=1;i<=index;i++)
    {
    	for(int j=1;j<=capacity;j++)
    	{
    		if(j>=w[i])
    		{
    			if(arr[i-1][j]>=arr[i-1][j-w[i]]+v[i])
    			{
    				res=arr[i-1][j];
    				for(int k=1;k<=index;k++)
    				{
    					sol[i][j][k]=sol[i-1][j][k];
					}
					sol[i][j][i]=0;
				}
				else
				{
					res=arr[i-1][j-w[i]]+v[i];
					for(int k=1;k<=index;k++)
    				{
    					sol[i][j][k]=sol[i-1][j-w[i]][k];
					}
					sol[i][j][i]=1;
				}
			}
    		else res=arr[i-1][j];
    		arr[i][j]=res;
		}
	}
    return res;
}

int main()
{
	int w[11]={0, 100, 150, 200, 250, 200, 250, 50, 150, 300, 100};
	double v[11]={0,0.1667, 0.5000, 0.2000, 0.3000, 0.1000, 0.1500, 0.2000, 0.2000, 0.1667, 0.3333};
	int    s[11]={0,0,0,0,0,0,0,0,0,0};
	int limit = 1300;
	int i=10;
	double r=solveBKS(w,v,s,i,limit);
	cout<<r<<endl;
	for(int j=1;j<=i;j++)
	{
		cout<<sol[i][limit][j]<<" ";
	}
	cout<<endl;
}
