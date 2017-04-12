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
		输出 : 求出最大值MAX(可选输出选择的具体物品列表)

	分析 : 
		时间复杂度 :
		空间复杂度 :
		简化 : 

	解决方案1 : 
		优缺点 :
		
	解决方案2 : 
		优缺点 : 

	引申问题 : 1.01背包问题隐形要求是物品最多选择1次,要是可选多次呢?
			   2.j物品有两个维度(sj,vj),sj累加<=C的情况下,求vj累加的最大值.如果有三个维度(x,y,z),x累加<=CX,Y累加<=CY,z累加的最大值呢?4个维度呢?
			   3.那最小值呢?
			   4.如果三个维度(x,y,z),在x累加<C的情况下,求y+z累加最大,或者y*z累加最大?

	方案对比 : 

	结论 : 

 */
#include <iostream>
using namespace std;
//函数

//测试
/*int main(int argc, char const *argv[])
{
	system("pause");
	return 0;
}*/
