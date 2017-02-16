/**
 * -*- coding : GBK -*-
 * @Author : huangshengjianng
 * @Email : 1005542693@qq.com
 * @Date : 2016-09-08 16:50
 * @Last Modified Date : 2016-10-27 10:31        
 * @FileName : ��������.cpp
 */

/*��������first
	Ӧ�ó��� : �������,���Ʊ���н��ʵ�.��Ϊ�����㷨�Ļ���,���ֵ����

	���� : һ��������n
	��� : n!��ȫ����(���ظ�),û�п��ǵ������ظ������.
	��ظ��� : ȫ������1~n��ÿ���������ҽ���һ�����ɵ�����.
	
	���� : ��Ȼ˼���Ƕ�����array[0]�Ӽ���n�б���,�ҳ�i,�ڶ������γɵļ��ϼ�������,ֱ������Ϊ��.���.
		   ��ѧ˼���ǵݹ��˼��n��ȫ��������n-1��ȫ���������ʵ�ֵ�.��������ֽ������.
		   ���������ĽǶȿ�,��n!�����,��ô�ó����ʱ�临�Ӷ�����ΪO(n!).	 

	�������1 : ��������array[n],��array[0]ѭ�����1~n�е�ĳ��ֵi,������n-1��������array[1~n]����ȫ����.
				����n-1��ȫ����Ҳ�ǵݹ��.
				�ؼ������ȷ��n-1��ȫ�����в�����iֵ��?���ȷ��n-2��ȫ�����в�����i��jֵ��?....
				�������鰴1~n��������.��Ӧ�������±�Ϊ[0...n-1].ÿһ�εݹ����ȴ�ʣ��������forѭ���ҳ�һ��ֵ����
				ʣ�������ͷλ��.�ݹ������ʣ���������Ϊ0ʱ,���.
				
	�������2 : �ݹ�.��������.˼���෴,����1�Ǵ��������ó�һ������ָ����λ��,����2�ǽ�ָ������ֵ�������λ����.
				����Ϊÿһ�εݹ齫�̶�ֵ�������пյ�λ��.�ݹ�����ǿյĸ���Ϊ0��.��n��1,���Ǵ�1��nû������.

	�������3 : �ǵݹ鷽ʽ,�ҳ�����������,�����.��������������������Сֵ.Ȼ��������������鵹��.
	ȱ�� : ��ʼ������123���������.

	�������� : 1.n!�ļ��㹫ʽ(���׶���)?
			   �� : nԽ��,������˹���ֹ�ʽ����.
			   2.�������������ظ����ֵ����?

 */

#include <iostream>
#include <vector>
using namespace std;

static int count = 1;
void print_out(int array[],int n)
{
	cout << ::count ++ << "����Ϊ:";
	for (int i = 0; i < n; ++i)
	{
		cout << array[i] << " ";
	}
	cout <<endl;
}

void swap_int(int &a,int &b)
{
	int temp = a;
	a = b ;
	b = temp ;
}

void perm1(int *array,int n,int m)//m��ʾ��m��,��Ӧ�������±�Ϊm-1
{
	if(m == n)
	{
		print_out(array,n);
	}//�ݹ����
	else
	{
		for (int i = m - 1; i < n; ++i)
		{
			swap_int(array[m-1],array[i]);
			perm1(array,n,m+1);
			swap_int(array[m-1],array[i]);
			//�ؼ�����α�֤�ݹ����ԭ��������.(��12345��1��3������32145,�ݹ����32145,�ٽ��н���)
			//�����佻���ľ�����Ǳ�֤�ݹ���ǵݹ�ǰ������.
			//���� : ����ײ�ͱ�֤�ݹ�ǰ�������һ����.ֻ�ܾ�����.
			//��1�������޲�� 1
			//��2��������ʼ12,21,����12.
			//��3��������123,132, 213,231, 321,312.
		}
	}
}


void perm2(int *array,int n,int m)//m��ʾ��m��Ԫ��,�±�Ϊm-1
{
	if (m == 0)//m == n+1
	{
		print_out(array,n);
	}
	else
	{
		for (int i = 0; i < n ; i++ )
		{
			if (array[i] == 0)
			{
				array[i] = m;
				perm2(array,n,m-1);//m+1
				array[i] = 0;
			}
		}
	}
}

//�ǵݹ鷽ʽ : ÿ�δ��������ҳ���һ��С���ұߵ������,����Ϊ�����.ͬʱ�������������������С��,���н���.�ٶԺ���λ����.
//             �������ж�������û���ҵ������.
void exchange(int &a , int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void perm3(int *array,int n)
{
	int loc = -1 ;  //��ʾ��������±�(�����) ��Χ[0...n-1]
	int min_loc = 0; //��ʾ��Ҫ�����ı���������±�
	print_out(array,n);
	while (true)
	{
		loc = -1;
		for (int i = n-2 ; i >= 0; i--)
		{
			if (array[i] < array[i+1])//���õȺ�,�������������Ȼ��ԭ����,��������ѭ����.
			{
				loc = i ;
				int temp = array[loc+1];//Ҫ��������,��ʱΪ���ұߵ�ֵ
				min_loc = loc+1 ; //�±�
				for (int j = n-1; j > loc ; j--)
				{
					if (array[j] > array[loc])
					{
						if (array [j] < temp)
						{
							temp = array[j];
							min_loc = j;
						}
					}
				}
				//����
				exchange(array[loc],array[min_loc]);

				//����
				int length = n - loc -1 ; //length��ʾ������ĸ���,loc+1..n-1��length��
				int mid = loc + length/2 ; 
				for (int k = loc + 1 ; k <= mid ; k++)//loc+1,n-1    loc+2,n-2  loc+3 ,n-3 
				{
					exchange(array[k],array[n-k+loc]);
				}
				print_out(array,n);
				break ;
			}
		}
		if (loc == -1)return ;
	}
}

//����
/*int main(int argc, char const *argv[])
{
	int n = 5;
	int a[]={1,2,3,4,5};
	perm1(a,n,1);
	::count =1;

	int b[]={0,0,0,0,0};
	perm2(b,n,n);
	::count =1;

	int c[]={1,2,3,4,5};
	perm3(c,n);
	::count =1;
	
	system("pause");
	return 0;
}*/
