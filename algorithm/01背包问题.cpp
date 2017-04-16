/**
 * -*- coding : GBK -*-
 * @Author : huangshengjiang
 * @Email : 1005542693@qq.com
 * @Date : 2017-04-12 09:24
 * @Last Modified Date :     
 * @FileName : 01背包问题.cpp
 */

/*01背包问题
	基本概念 : 用于某一维度约束的情况下,求另一维度的最大值或者最小值.
	应用场景 : 如背包问题,固定里程花费最少等等.
	具体需求 : 有n个物品和1个体积为C的背包,对于第i个物品,其体积为si,其价值为vi.如何选择使放入背包中的物品价值最大?
		输入 : N  C  (N个物品,容量C的背包)
			   si  vi
			   ..  ..
			   (N对,si表示第i物体的体积,vi表示第i物体的价值)
		输出 : 求出最大值MAX和选择的具体物品列表

	分析 : 对于物品而言,只有放入背包(1)和未放入(0)两种状态.不考虑背包的体积,只关注物品的组合形式有2^n种,体积累加<=C,价格累加max.
		   时间复杂度达到O(n*2^n).
		   子问题是f[i][j]表示将i个物品中选取若干件放入体积j的最大价值.
		   则有 f[i][j] = max{f[i-1][j](没有选取i物品),f[i-1][j-si]+vi(选取i物品)}.
		   其中f[0][j] = 0 j = 0,s1,s2,s3,..sn,s1+s2,s1+s3,...C ; f[i][0] = 0 i = 0..N ; 
		   
		   
	    时间复杂度 : O(n+1*n/2)=O(n^2)
		空间复杂度 : 一般用二维数组表示矩阵,可是实际中运用到的是矩阵的一半空间.可以用节点方式表示,是否节省空间待议?
		简化 : 

	引申问题 : 1.01背包问题隐形要求是物品最多选择1次,要是可选多次呢?
			   2.j物品有两个维度(sj,vj),sj累加<=C的情况下,求vj累加的最大值.如果有三个维度(x,y,z),x累加<=CX,Y累加<=CY,z累加的最大值呢?4个维度呢?
			   3.那最小值呢?
			   4.如果三个维度(x,y,z),在x累加<C的情况下,求y+z累加最大,或者y*z累加最大?

	方案对比 : 

	结论 : 

 */
#include <iostream>
#include <vector>
using namespace std;
//函数
struct pack
{
	int N;


};



int  backpack()
{

}



//平白开销多余空间,不妥
//#define  MAXN  1000
//int S[MAXN][MAXN]; 



//测试
int main(int argc, char const *argv[])
{



	system("pause");
	return 0;
}
