#include <iostream>
#include <conio.h>
#include <windows.h>
#include <math.h>
using namespace std;

void main(void)
{
	long i,j,c;
	int flag;

	DWORD starttime, endtime;
	float totaltime;
    char z[100000];

	starttime = GetTickCount();//get start time

	//set array to 0, note 0= prime, 1 = not prime
	memset(z,0,100000);
	
	z[0]=1;
	z[1]=1;
	
	for(i=2; i<316;i++)
	{
		if (z[i]==0) //we found a prime so knock off the rest
		{ 
			for (j=i*2; j<100000; j=j+i) z[j] = 1;
		}

	}


	//test to show first 100 values

	for(i=1;i<101;i++)
	{
		cout << i << " \a " << z[i] <<endl;
	}


	// count primes

	c=0;
	for (i=0;i<100000;i++)
	{
		if(z[i]==0) c++;
	}
	cout<<"Total number of prime numbers between 0 and 100,000: "<<c<<" \n";



	/*for (i=3; i<100000; i=i+2)//numbers to check if prime // opt 1
	{
		flag = 0;

		for (j=3; j<i; j=j+2) //opt 2
		{
			if (i%j==0) {flag=1;} //opt 3
		}
		if (flag == 0) //{cout<<i<<" is prime!\n "; continue;} //
		//else { cout << i << " is NOT prime!\n "; } not needed
	}*/


	//end timer here
	endtime = GetTickCount();//get finish time
							 //calc time
	totaltime = ((float)endtime - (float)starttime) / 1000.0;//calculate total time in secs
	cout << "Time taken to complete calculations = " << totaltime << " seconds.\n";

	cin.get();
}