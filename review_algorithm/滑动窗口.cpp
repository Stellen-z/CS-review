#include <iostream>

using namespace std;
typedef long long LL;

const int N = 1e5 + 10;

int a[N];

int main()
{
	int n,k;cin >> n >> k;
	
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	LL sum = 0,ret = -1e9;

	int l = 1,r = 1;
	while(r <= n)
	{
		sum += a[r];
		
		if(r - l + 1 > k) sum -= a[l++];
		
		if(r - l + 1 == k) ret = max(ret,sum);
		r++;
	}
	
	cout << ret << endl;
	
	return 0;
}
