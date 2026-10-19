#include <iostream>

using namespace std;
typedef long long LL;

const int N = 1e5 + 10;

LL a[N],f[N];

int n,m;

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		f[i] = a[i] - a[i-1];
	}
	
	while(m--)
	{
		int l,r,c;cin >> l >> r >> c;
		f[l] += c;
		f[r+1] -= c;
	}
	
	//前缀和恢复
	for(int i = 1;i <= n;i++)
	{
		a[i] = a[i-1] + f[i];
		cout << a[i] << " ";
	}
	return 0;
}
