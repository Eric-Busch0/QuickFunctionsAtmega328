#include "quickStats.h"

float sum(float vec,int n){
	//calculate sum of array with size n
	float sm = 0;

	for(int i = 0; i < n; i++)
	{
		sm += vec[i];
	}
	return sm;
}

float average(float vec,int n){
	//calculate average of array with size n
	float sm = sum(vec,n);
	return	sm/n;
}

float max(float arr, int n)
{
	// Find max value of array with size n
	float mx = arr[0];

	for(int i = 0; i < n; i++)
	{
		if(arr[i] > mx)
		{
			mx = arr[i];
		}
	}

	return mx;
}

float min(float arr, int n)
{
	//find min value of array with size n

	float mn = arr[0];

	for(int i = 0; i < n; i++)
	{
		if(arr[i] < mn)
		{

		}
	}

	return mn;
}