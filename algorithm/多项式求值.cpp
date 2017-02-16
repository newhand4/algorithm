/**
 * -*- coding : GBK -*-
 * @Author : huangshengjianng
 * @Email : 1005542693@qq.com
 * @Date : 2016-08-31 13:27
 * @Last Modified Date : 2016-08-31 14:21
 * @FileName : ����ʽ��ֵ.cpp
 */

/*������� : 
	���� : n+1��ʵ��a0,a1,...,an,��x������
	��� : an*x^n +an-1 *x^(n-1) + ...+a0��ֵ
	�뷨 : (anx+an-1)x...  �����ַ�ʽֱ�� ...x+a0 ���õ�ֵ
	��� : �뷨����,����.
	�������� : ����Զ�����a0,a1,...,an(�����ֶ�����)?
		���� : ��ʽ
		��� : ��Ӧָ����ϵ�����ɵ�����a,���鳤��=���ָ��+1;
		�뷨 : �����鿴���ַ�������,��������ָͬ����ϵ��,������ָ��Max,����a(Max+1)={0}(+1ԭ����a0*x^0=a0);
			   �ٽ�ָ��i��Ӧ��ϵ��bi��ֵ��a[Max-i].
		��� : ��ʱ���˽����ֹ�ʽ�ڳ�������α�ʾ,�޷�����.
		���� : û��ʵ��.
 */
#include <iostream>
#include <vector>
using namespace std;

//��������
template < class T >
int GetLen(T & a){
	return (sizeof(a)/sizeof(a[0]));
}

//Horner����
void Horner(const int *a,const int n,const int x,int &result){//a����(��an...a0��˳��),n���鳤��,x����,result�洢���
	result=a[0];
	for (int i = 0; i < n-1; ++i)
	{
		result=x*result+a[i+1];//ע��� : ��������ʱ...*x + a[n-1],���ʱiΪn-2.
	}
}

//����
/*int main(int argc, char const *argv[])
{
	int a[]={1,2,1};//x^2 +2*x+1
	int n=GetLen(a);
	int result=0;

	Horner(a,n,1,result);//result=4
	cout<<result<<endl;
	Horner(a,n,2,result);//result=9
	cout<<result<<endl;
	Horner(a,n,3,result);//result=16
	cout<<result<<endl;
	Horner(a,n,4,result);//result=25
	cout<<result<<endl;
	Horner(a,n,5,result);//result=36
	cout<<result<<endl;
	system("pause");
	return 0;

}*/