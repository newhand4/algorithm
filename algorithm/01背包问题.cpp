/**
 * -*- coding : GBK -*-
 * @Author : huangshengjiang
 * @Email : 1005542693@qq.com
 * @Date : 2017-04-12 09:24
 * @Last Modified Date : 2017-04-20 23:48     
 * @FileName : 01��������.cpp
 */

/*01��������
	�������� : ����ĳһά��Լ���������,����һά�ȵ����ֵ������Сֵ.
	Ӧ�ó��� : �米������,�̶���̻������ٵȵ�.
	�������� : ��n����Ʒ��1�����ΪC�ı���,���ڵ�i����Ʒ,�����Ϊsi,���ֵΪvi.���ѡ��ʹ���뱳���е���Ʒ��ֵ���?
		���� : N  C  (N����Ʒ,����C�ı���)
			   si  vi
			   ..  ..
			   (N��,si��ʾ��i��������,vi��ʾ��i����ļ�ֵ)
		��� : ������ֵMAX��ѡ��ľ�����Ʒ�б�

	���� : ������Ʒ����,ֻ�з��뱳��(1)��δ����(0)����״̬.�����Ǳ��������,ֻ��ע��Ʒ�������ʽ��2^n��,����ۼ�<=C,�۸��ۼ�max.
		   ʱ�临�ӶȴﵽO(n*2^n).
		   ��������f[i][j]��ʾ��i����Ʒ��ѡȡ���ɼ��������j������ֵ.
		   ���� f[i][j] = max{f[i-1][j](û��ѡȡi��Ʒ),f[i-1][j-si]+vi(ѡȡi��Ʒ)}.
		   ����f[0][j] = 0 j = 0,s1,s2,s3,..sn,s1+s2,s1+s3,...C ; f[i][0] = 0 i = 0..N ; 
		   
	    ʱ�临�Ӷ� : O(n+1*n/2)=O(n^2)
		�ռ临�Ӷ� : һ���ö�ά�����ʾ����,����ʵ�������õ����Ǿ����һ��ռ�.�����ýڵ㷽ʽ��ʾ,�Ƿ��ʡ�ռ����?

	�������� : 1.01������������Ҫ������Ʒ���ѡ��1��,Ҫ�ǿ�ѡ�����?
			   2.j��Ʒ������ά��(sj,vj),sj�ۼ�<=C�������,��vj�ۼӵ����ֵ.���������ά��(x,y,z),x�ۼ�<=CX,Y�ۼ�<=CY,z�ۼӵ����ֵ��?4��ά����?
			   3.����Сֵ��?
			   4.�������ά��(x,y,z),��x�ۼ�<C�������,��y+z�ۼ����,����y*z�ۼ����?

 */
#include <iostream>
#include <vector>
using namespace std;
#define  N 100
//����
struct good
{
	int value ;
	int cap  ;
};
good GOODS[N];

int  buf[N][N] = {0};

int  knapsack(int n,int c)
{
	int i = 0 ;
	int j = 0 ;
	n++ ;
	c++ ; 
	for ( ; i < n ; i++)
	{
		buf[i][0] = 0 ; 
	}
	for ( ; j < c ; j++)
	{
		buf[0][j] = 0;
	}
	for ( i = 1 ; i < n ; i++ )
	{
		for (j = 1 ; j < c ; j++)
		{
			buf[i][j] = buf[i - 1][j];
			if (j >= GOODS[i].cap)
			{
				buf[i][j] = buf[i][j] >= buf[ i - 1 ] [j - GOODS[i].cap] + GOODS[i].value ? buf[i][j] : buf[i - 1][j - GOODS[i].cap] + GOODS[i].value;
			}
		}
	}
	return buf[n-1][c-1];
}

//����
int main(int argc, char const *argv[])
{
	freopen("C:\\Users\\hsj\\Desktop\\test.txt", "r", stdin);
	int n = 0, c = 0 ,vtmp = 0 , ptmp = 0;
	scanf("%d", &n);
	scanf("%d", &c);
	for (int i = 0 ; i < n ; i++ )
	{
		scanf("%d", &GOODS[i+1].cap);
		scanf("%d", &GOODS[i+1].value);
		//GOODS[i].
	}

	int result = knapsack( n , c );

	printf("����ܼ�ֵ��%d", result);

	system("pause");
	return 0;
}
