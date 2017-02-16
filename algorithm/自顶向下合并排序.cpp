/**
 * -*- coding : GBK -*-
 * @Author : huangshengjiang
 * @Email : 1005542693@qq.com
 * @Date : 2016-10-28 13:59
 * @Last Modified Date : 2016-11-10 18:46
 * @FileName : �Զ����ºϲ�����.cpp
 */

/*�Զ����ºϲ�����
	�������� : �������µݹ���õ�����,���Ե����Ϻϲ������෴
	Ӧ�ó��� : �ֽ�˼��,��������ֽ��С����,��Ҫ�Ƿ����������.
	������ : ���Ե���������Ƚ�,����ʱ�临�Ӷ�һ��,����ǰ�߱Ⱥ�����Ҫ����Ŀռ�,�����Զ����������ڷ������.
	�������� : �����������A����ɴ�С���������
		���� : һ�����������A
		��� : ���������

	���� : �Զ�����ʵ�����ǽ����黮�ֳɶ��С����,����ÿ��С���鰴��ͬ�����ݹ����.
		   ����ʹ�õ��Ƕ��ַ�(ÿ�ν����黮��Ϊ2������),��ݹ������С�����Ϊ1.
		ʱ�临�Ӷ� : O(nlogn)
		�ռ临�Ӷ� : O(1)
 */
#include <iostream>
#include <vector>
using namespace std;
//��������
template<class T>
int Size(T &array)
{
	return sizeof(array)/sizeof(array[0]);
}
vector<int> buffer;
void merge(int *a,int left,int mid,int right)//�ϲ�����a����������,
									//left��ʾ�����λ��,mid��ʾ������λ��,right��ʾ���ұ�λ��,�±궼��[0...n-1]��Χ��
									//����ÿ����Ҫ����Ŀռ���ʱ�������,��˽���������ֱ������һ������
{
	int i,j;
	int t;

	i = left ; 
	j = mid + 1 ;
	t = 0 ; 

	while(i <= mid && j <= right) {//i,j���ں���Χ��,û�й���,��ĳ���ﵽ�߽�,������ѭ��
	    if (a[i] <= a[j])
	    {
	    	buffer[t++] = a[i++];
	    }
	    else{
	    	buffer[t++] = a[j++];
	    }
	}

	//�ұ��Ѿ�������
	while(i <= mid) {
	    buffer[t++] = a[i++] ;
	}

	//����Ѿ�������
	while(j <= right) {
	    buffer[t++] = a[j++] ;
	}

	//��ֵ
	i = left ;
	for (int k = 0; k < t; ++k)
	{
		a[i++] = buffer[k];
	}
}

//����
void mergesort(int *a,int left,int right)
{
	if( left == right) return ; 
	int mid = (left + right) / 2 ; //����/������,�����ٽ�ֵ���/2,����ߵ�ֵ.���merge�Ĳ���mid��ָ��ߵ����λ��
	mergesort(a,left,mid) ;
	mergesort(a,mid+1,right) ;
	merge(a,left,mid,right) ;//�������,������������
}

void sort(int *a,int n)
{
	mergesort(a,0,n-1);
}

//����
/*int main(int argc, char const *argv[])
{
	int a[] = {3,5,8,5,45,4,6,8,9};
	int n = Size(a);
	buffer.resize(n);
	
	sort(a,n);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] <<" ";
	}
	cout<<endl;

	system("pause");
	return 0;
}*/
