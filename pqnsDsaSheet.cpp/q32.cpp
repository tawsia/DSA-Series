

// eko eko
#include<bits/stdc++.h>
using namespace std;
int is_possible(int arr[], int n, int m, int mid)
{
	int sum=0;
	for(int i=0; i<n; i++)
	{
		if(arr[i]>mid)
		{
			sum +=arr[i] - mid;
        }
	}
    if(sum>=m)
			return true;
		else
			return false;
}
int main()
{

    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0; i<n; i++)cin>>a[i];
	int low=0;
	//int i=0;
	int high= *max_element(a,a+n);
	int ans;
	int mid = (low+high)/2;
	while(low<=high)
	{
		if(is_possible(a,n,m,mid))
		{
			ans = mid;
			low = mid+1;
		}
		else
		{
			high= mid -1;
		}
		mid =  (low+high)/2;
	}
	cout<<ans;
}