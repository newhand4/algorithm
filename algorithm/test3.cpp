#include <map>
#include <set>
#include <ctime>
#include <stack>
#include <cmath>
#include <queue>
#include <bitset>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
//#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;
#define   maxn          1000+10
#define   lson          l,m,rt<<1
#define   rson          m+1,r,rt<<1|1
#define   clr(x,y)      memset(x,y,sizeof(x))
#define   rep(i,n)      for(int i=0;i<(n);i++)
#define   repf(i,a,b)   for(int i=(a);i<=(b);i++)
#define   pii           pair<int,int>
#define   mp            make_pair
#define   FI            first
#define   SE            second
#define   IT            iterator
#define   PB            push_back
#define   Times         10

typedef   long long     ll;
typedef   unsigned long long ull;
typedef   long double   ld;

const double eps = 1e-14;
const double  pi = acos(-1.0);
const  ll    mod = 1e9 + 7;
const  int   inf = 0x3f3f3f3f;
const  ll    INF = (ll)1e18 + 300;
const double delta = 0.98;

inline void RI(int& x)
{
	x = 0;
	char c = getchar();
	while (!((c >= '0'&&c <= '9') || c == '-'))c = getchar();
	bool flag = 1;
	if (c == '-')
	{
		flag = 0;
	}
	while (c <= '9'&&c >= '0')
	{
		x = x * 10 + c - '0';
		c = getchar();
	}
	if (!flag)x = -x;
}

/*--------------------------------------------------*/

//int main() {
//	freopen("C:\\Users\\hsj\\Desktop\\test.txt", "r", stdin);
//	int n, last, flag, j;
//	scanf("%d", &n);
//	rep(i, n)scanf("%s", S[i]);
//	rep(i, n)
//	{
//		last = 0;
//		flag = 0;
//		j = 0;
//		while (S[i][j])
//		{
//			if (S[i][j] == 'A')
//			{
//				flag++;
//			}
//			j++;
//		}
//		if (flag > 1)
//		{
//			printf("NO\n");
//			continue;
//		}
//		flag = 0;
//		j = 0;
//		while (S[i][j])
//		{
//			if (S[i][j] == 'L')
//			{
//				flag++;
//				if (flag >= 3)
//				{
//					printf("NO\n");
//					break;
//				}
//			}
//			else
//			{
//				flag = 0;
//			}
//			j++;
//		}
//		if (flag < 3)
//		{
//			printf("YES\n");
//		}
//	}
//
//	system("pause");
//}
