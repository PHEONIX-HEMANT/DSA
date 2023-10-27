#include <iostream>
#include <queue>
using namespace std;
int main() {

	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin>>n;
		priority_queue<int, vector<int>, greater<int>> pq;

		int k;
		cin >> k;

		int a[n];
		int b[n];

		for(int i=0;i<n;i++)
			cin >> a[i];
		for(int j=0;j<n;j++)
			cin >> b[j];

		for(int i=0;i<n;i++)
		{
			int diff = a[i]-b[i];
			if(diff<0)
				pq.push(diff);
		}

		long extraSum = 0;
		while(k--)
		{
			if(!pq.empty())
			{
				extraSum += (-pq.top());
				pq.pop();
			}
		}

		for(int i=0;i<n;i++)
			extraSum += a[i];

		cout<<extraSum<<endl;

	}

	return 0;
	
}