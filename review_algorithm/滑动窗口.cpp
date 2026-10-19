#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long LL;

const int N = 1e5 + 10;

int a[N];

int main()
{
	int n,k;cin >> n >> k;
	
	unordered_map<int,int> mp;
	for(int i = 1;i <= k;i++)
	{
		int x;cin >> x;
		LL ret = -1e9,sum = 0;
		if((int)mp.size() != k)
		{
			mp.insert(x);
			sum += x;
		}
		else
		{
			if(sum > ret)
			{
				ret = sum;
				mp.erase()
			}
		}
	}
	return 0;
}
