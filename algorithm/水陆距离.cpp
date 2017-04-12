//#include <map>
//#include <set>
//#include <ctime>
//#include <stack>
//#include <cmath>
//#include <queue>
//#include <bitset>
//#include <string>
//#include <vector>
//#include <cstdio>
//#include <cctype>
//#include <fstream>
//#include <cstdlib>
//#include <sstream>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
////#pragma comment(linker, "/STACK:1024000000,1024000000")
//
//using namespace std;
//#define   maxn          1000+10
//#define   lson          l,m,rt<<1
//#define   rson          m+1,r,rt<<1|1
//#define   clr(x,y)      memset(x,y,sizeof(x))
//#define   rep(i,n)      for(int i=0;i<(n);i++)
//#define   repf(i,a,b)   for(int i=(a);i<=(b);i++)
//#define   pii           pair<int,int>
//#define   mp            make_pair
//#define   FI            first
//#define   SE            second
//#define   IT            iterator
//#define   PB            push_back
//#define   Times         10
//
//typedef   long long     ll;
//typedef   unsigned long long ull;
//typedef   long double   ld;
//
//const double eps = 1e-14;
//const double  pi = acos(-1.0);
//const  ll    mod = 1e9 + 7;
//const  int   inf = 0x3f3f3f3f;
//const  ll    INF = (ll)1e18 + 300;
//const double delta = 0.98;
//
//inline void RI(int& x)
//{
//	x = 0;
//	char c = getchar();
//	while (!((c >= '0'&&c <= '9') || c == '-'))c = getchar();
//	bool flag = 1;
//	if (c == '-')
//	{
//		flag = 0;
//	}
//	while (c <= '9'&&c >= '0')
//	{
//		x = x * 10 + c - '0';
//		c = getchar();
//	}
//	if (!flag)x = -x;
//}
//
///*--------------------------------------------------*/
//
//char  S[801][801];
//int  d[801][801];
//queue< pii >  q;
//int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
//
////int main() {
////	freopen("F:\\in.txt", "r", stdin);
////	int n , m ,a , b , x , y;
////	scanf("%d %d",&n,&m);
////	rep(i, n)scanf("%s", S[i]);
////
////	pii temp ;
////	rep(i,n)
////		rep(j,m)
////		if (S[i][j] == '0')
////		{
////			q.push(mp(i,j));
////			d[i][j] = 0 ;
////		}
////		else
////		{
////			d[i][j] = -1 ; 
////		}
////
////	while (!q.empty())
////	{
////		temp = q.front();q.pop();
////		a = temp.FI ; b = temp.SE ;
////		rep(i,4)
////		{
////			x = a + dx[i] ; y = b + dy[i] ;
////			if ( d[x][y]== -1 && x>=0 && x<n && y>=0 && y<m )
////			{
////				d[x][y] = d[a][b] + 1 ;
////				q.push(mp(x,y));
////			}
////		}
////	}
////
////	rep(i, n) {
////		rep(j, m)printf("%d ", d[i][j]);
////		printf("\n");
////	}
////	system("pause");
////}
//
//
//
//
//
//	/********该方案是以简单的x+y的大小判断距离,否决***********
//	int wnum = 0;
//	pii temp;
//	rep(i,n)rep(j,m)if (S[i][j] == '0')
//	{
//		temp = mp(i , j);
//		water[wnum++] = temp;
//		S[i][j] = 0 ;
//	}
//	rep(i, n)rep(j, m)if (S[i][j] == '1' )
//	{
//		int res = 640001;
//		rep(k, wnum)
//		{
//			int x = water[k].FI, y = water[k].SE;
//			int t = abs(x - i) + abs(y - j);
//			if (t < res)res = t;
//		}
//		S[i][j] = res;
//	}********该方案是以简单的x+y的大小判断距离,否决************/
//
