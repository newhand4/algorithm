/**
* -*- coding : GBK -*-
* @Author : huangshengjiang
* @Email : 1005542693@qq.com
* @Date : 2017-05-03 09:51
* @Last Modified Date : 
* @FileName : 单点最短路径问题Dijkstra.cpp
*/

/*单点最短路径问题Dijkstra
基本概念 : 设G=(V,E)是一个每条边有非负长度的有向图,有一个特异顶点s称为源.单点最短路径问题是确定从s到V中每一个顶点的最短距离
应用场景 : 通信网络中源点到目的点的最短距离.
局限性 : 只知道距离,希望改进保留相应的路径.
	输入 : 含权有向图G=(V,E),V={1,2,...,n}
	输出 : G中顶点1到其他顶点的距离
例子 : 
	输入 : 6  9
		   1  2  1
		   1  3  12
		   2  4  3
		   2  3  9
		   3  5  5
		   4  3  4
		   4  5  13
		   4  6  15
		   5  6  4
 	输出 : D[2]=1 D[3]=8 D[4]=4 D[5]=13 D[6]=17


分析 : dijkstra算法的思想是
	   1.X表示已经分配的集合(用X[V]数组表示,X[i]=1表示第i个顶点在集合中,X[i]=0则相反),含{1},Y表示未分配的集合,含{V-1}.D[0..V]中的D[i]表示从顶点1到顶点i的最短距离.D[0]=D[1]= 0
		D[i]= INF(i = 2..V)
	   2.遍历u=1的所有边edge(1,v).计算D[1]+edge(1,v)和D[v]的大小,如果<,则更新D[v] = D[1]+edge(1,v)

	   3.遍历D数组,找出X[i]=0中D[i]最小的值.然后置X[i]=1,Y[i]=0,将u=i代入第2步中循环.(循环打破条件是X[i]都等于1)

	   伪代码 : 1.X={1} ; Y <- V - {1} ; D[1]<-0  (用X[N] ,Y[N]数组表示)  
				2.for y<- 2 to n
				3.	if y 相邻于1 then D[y] <- length[1,y]
				4.  else  D[y] = INF
				5.  end if
				6.end for
				7.for j<- 1 to n-1
				8.  令 y 属于 Y ,使得D[y]最小(这里消耗的时间复杂度O(n^2))
				9.  X<-X U {y}  {将顶点y加入X}
				10. Y<-Y - {y}  {将顶点y从Y中删除}
				11. for 每条边(y,w)
				12.     if w属于Y  and D[y]+length[y,w] < D[w] then
				13.        D[w] = D[y]+length[y,w]
				14. end for
				15.end for
时间复杂度 : 第8步中,查找符合的y需要O(n^2),这里可以改进,构建一棵最小树,顶点是最小值D[y].插入条件是D[w]从INF到常量值c变化.然后sift-up
			 更新条件是D[w]从常量值c到b减少,然后对应位置sift-up.删除根节点是在第8步,然后自行sift-up.可以用数组计算
空间复杂度 : 
简化 : 

解决方案1 : 第一个版本就按照伪代码写,时间复杂度为O(n^2),适用于稀疏图
优缺点 : 

解决方案2 : 改进第8步,适用于稠密图.当然最好用方案2
优缺点 :

引申问题 : 如果要附加求路径呢?

方案对比 :

结论 :

*/
#include <iostream>
using namespace std;
//函数

//方案1

#define  NODEMAXLENGTH  100 
//邻接表结构体,计划用类表示
struct Node
{
	int  vertex ; 
	int  length ; 
	Node * next ; 
	Node( int v , int len ) : vertex( v ) , length (len) , next( NULL ){} ;
};

Node  V_SET[NODEMAXLENGTH] ; //邻接表

int   D[NODEMAXLENGTH] ; //所求的值




void dijkstra1(int V_num )//V_num表示G=(V,E)的V数量
{
	
}







//测试
int main(int argc, char const *argv[])
{
	//准备数据
	freopen("C:\\Users\\hsj\\Desktop\\test.txt", "r", stdin);
	int V = 0 , E = 0 , vt = 0 , ed = 0 , len = 0 ; 
	scanf("%d", &V ) ; 
	scanf("%d", &E ) ; 
	for (int i = 0 ; i < E ; i++ )
	{
		scanf("%d", &vt  ) ;
		scanf("%d", &ed  ) ;
		scanf("%d", &len ) ;
		Node * tmp = new Node ( ed , len ) ; 
		/*if(Node[vt].next == NULL)
		{
			Node[vt].next = tmp ;
		}
		else 
		{*/
		tmp.next = V_SET[vt].next ; 
		V_SET[vt].next = tmp ; 
		/*}*/

	}

	//处理数据
	



	system("pause");
	return 0;
}
