///**
// * -*- coding : GBK -*-
// * @Author : huangshengjiang
// * @Email : 1005542693@qq.com
// * @Date : 2016-12-26 11:18
// * @Last Modified Date : 2017-02-19 23:25
// * @FileName : ��������.cpp
// */
//
///*��������
//	�������� : �������ĳ��ֵ(һ��Ϊ��β,�˴�Ϊ��)Ϊ��׼ֵ,i,j�����ұ���(iָ������Ĵ���A[0]��ֵ,
//			   jָ�����С��A[0]��ֵ,���i��j����ͬ,�򽻻�),j����������,��ʱiָ��A[0]��Ҫ������λ��.
//	�������� : ������A����
//		���� : ��������A
//		��� : ��A����
//	������� : ����������ÿ�ν�һ����Χ��������λ���ں��ʵ�λ��.(�ص��Ǹ�λ���ϵ�Ԫ��
//			   �������廹�Ǿֲ����ǹ̶������.)
//			   ��һ�ַ����Ƕ��ַ�,����ÿ��ִ�н�����λ��.ͳһ���ֵݹ����.(ʵ�ּ�,�����ж������,
//			   ����4,3,5,7,6,��ʱ5����һ�ε�ִ�н��,һ��j����5��,�ȽϾ�û��������)
//			   �ڶ��ַ����Ǹ�����һ�εĵݹ���,����ǰ���黮��������,�ݹ����.
// */
//#include <iostream>
//using namespace std;
////��������
//template<class T>
//int Size(T &data)
//{
//	return sizeof(data)/sizeof(data[0]);
//}
//
//
////ȷ��A[left]��[left,right]�����׼ȷλ��(���<X,�ұ�>X),����ֵ��X�ľ�׼����.
////�������ֵ��-1,���ʾ�������
//int partition(int *a,int left,int right)
//{
//	if (left < right)//���ڴ���������left<right,�����ж���
//	{
//		int i = left,j = left + 1 ;
//		int x = a[left];
//		//��֤[left+1,i]��С��A[left],[i+1,right]���ڵ���A[left].
//		while( j <= right )
//		{
//			if (a[j] < x)
//			{
//				i++;
//				//if(i!=j){����},����,���ж�ֻ����j=left+1����a[left+1]<xʱ��Ч,����ʱ�̶���,�˷���Դ
//				int tmp = a[i];
//				a[i] = a[j];
//				a[j] = tmp; 
//			}
//			j ++ ;
//		}
//		//��󽻻�
//		a[left] = a[i] ; 
//		a[i] = x ;
//		return i ; 
//	}
//	else if (left > right) return -1;
//	else return left;
//}
//
//void quicksort(int *a,int left,int right)
//{
//	if (left >= right)return;
//	int s = partition(a,left,right);//ǰһ�����,��ִ֤�е��ò�ʱleft < right.
//	quicksort(a,left,s-1);//��ݹ�
//	quicksort(a,s+1,right);//�ҵݹ�
//}
//
////����
////int main(int argc, char const *argv[])
////{
////	int a[]={1,3,5,7,9,2,4,6,8,0};
////	int length = Size(a);
////	quicksort(a,0,length-1);
////	for (int i = 0;i<length;i++)
////	{
////		cout << a[i] << " ";
////	}
////	cout << endl;
////	system("pause");
////	return 0;
////}
