#include <iostream>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;

int n,m;
LL f[N];

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		int x;cin >> x;
		f[i] = f[i-1] + x;
	}
	
	while(m--)
	{
		int l,r;cin >> l >> r;
		cout << f[r] - f[l-1] << endl;	
	}
	
	return 0;
}
