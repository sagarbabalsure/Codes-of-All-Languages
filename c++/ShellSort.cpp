#include <iostream>

using namespace std;


void shellSort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
    	int i;
    	int temp = gap;
    	for (i = 0; temp < n; ++i, ++temp)
    	{
    		if (arr[i] > arr[temp])
    		{
    			swap(arr[i], arr[temp]);
    		}
    	}

    	

    	for (i--,temp--; i >= 0; --i, --temp)
    	{
    		if (arr[i] > arr[temp])
    		{
    			swap(arr[i], arr[temp]);
    		}
    	}
    }
}


int main()
{
	int n;
	cin >> n;

	int Arr[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> Arr[i];
	}

	shellSort(Arr, n);

	for (int i = 0; i < n; ++i)
	{
		cout << Arr[i] << "\t";
	}
	cout << endl;	

	return 0;
}