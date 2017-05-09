/**
* -*- coding : GBK -*-
* @Author : huangshengjiang
* @Email : 1005542693@qq.com
* @Date : 2017-05-03 09:51
* @Last Modified Date : 
* @FileName : �������·������Dijkstra.cpp
*/

/*�������·������Dijkstra
�������� : ��G=(V,E)��һ��ÿ�����зǸ����ȵ�����ͼ,��һ�����춥��s��ΪԴ.�������·��������ȷ����s��V��ÿһ���������̾���
Ӧ�ó��� : ͨ��������Դ�㵽Ŀ�ĵ����̾���.
������ : ֻ֪������,ϣ���Ľ�������Ӧ��·��.
	���� : ��Ȩ����ͼG=(V,E),V={1,2,...,n}
	��� : G�ж���1����������ľ���
���� : 
	���� : 6  9
		   1  2  1
		   1  3  12
		   2  4  3
		   2  3  9
		   3  5  5
		   4  3  4
		   4  5  13
		   4  6  15
		   5  6  4
 	��� : D[2]=1 D[3]=8 D[4]=4 D[5]=13 D[6]=17


���� : dijkstra�㷨��˼����
	   1.X��ʾ�Ѿ�����ļ���(��X[V]�����ʾ,X[i]=1��ʾ��i�������ڼ�����,X[i]=0���෴),��{1},Y��ʾδ����ļ���,��{V-1}.D[0..V]�е�D[i]��ʾ�Ӷ���1������i����̾���.D[0]=D[1]= 0
		D[i]= INF(i = 2..V)
	   2.����u=1�����б�edge(1,v).����D[1]+edge(1,v)��D[v]�Ĵ�С,���<,�����D[v] = D[1]+edge(1,v)

	   3.����D����,�ҳ�X[i]=0��D[i]��С��ֵ.Ȼ����X[i]=1,Y[i]=0,��u=i�����2����ѭ��.(ѭ������������X[i]������1)

	   α���� : 1.X={1} ; Y <- V - {1} ; D[1]<-0  (��X[N] ,Y[N]�����ʾ)  
				2.for y<- 2 to n
				3.	if y ������1 then D[y] <- length[1,y]
				4.  else  D[y] = INF
				5.  end if
				6.end for
				7.for j<- 1 to n-1
				8.  �� y ���� Y ,ʹ��D[y]��С(�������ĵ�ʱ�临�Ӷ�O(n^2))
				9.  X<-X U {y}  {������y����X}
				10. Y<-Y - {y}  {������y��Y��ɾ��}
				11. for ÿ����(y,w)
				12.     if w����Y  and D[y]+length[y,w] < D[w] then
				13.        D[w] = D[y]+length[y,w]
				14. end for
				15.end for
ʱ�临�Ӷ� : ��8����,���ҷ��ϵ�y��ҪO(n^2),������ԸĽ�,����һ����С��,��������СֵD[y].����������D[w]��INF������ֵc�仯.Ȼ��sift-up
			 ����������D[w]�ӳ���ֵc��b����,Ȼ���Ӧλ��sift-up.ɾ�����ڵ����ڵ�8��,Ȼ������sift-up.�������������
�ռ临�Ӷ� : 
�� : 

�������1 : ��һ���汾�Ͱ���α����д,ʱ�临�Ӷ�ΪO(n^2),������ϡ��ͼ
��ȱ�� : 

�������2 : �Ľ���8��,�����ڳ���ͼ.��Ȼ����÷���2
��ȱ�� :

�������� : ���Ҫ������·����?

�����Ա� :

���� :

*/
#include <iostream>
using namespace std;
//����

//����1

#define  NODEMAXLENGTH  100 
//�ڽӱ�ṹ��,�ƻ������ʾ
struct Node
{
	int  vertex ; 
	int  length ; 
	Node * next ; 
	Node( int v , int len ) : vertex( v ) , length (len) , next( NULL ){} ;
};

Node  V_SET[NODEMAXLENGTH] ; //�ڽӱ�

int   D[NODEMAXLENGTH] ; //�����ֵ




void dijkstra1(int V_num )//V_num��ʾG=(V,E)��V����
{
	
}







//����
int main(int argc, char const *argv[])
{
	//׼������
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

	//��������
	



	system("pause");
	return 0;
}
