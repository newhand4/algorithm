///**
// * -*- coding : GBK -*-
// * @Author : huangshengjianng
// * @Email : 1005542693@qq.com
// * @Date : 2016-08-30 15:56
// * @Last Modified Date : 2016-08-30 19:29
// * @FileName : ������.cpp
// */
//
///*������� : 
//	���� : ����x�ͷǸ���n
//	��� : ����x^n��ֵ
//	�뷨1 : �ݹ����,��x^n��Ϊx^(n/2)*x^(n/2),�ڶ�x^(n/2)�ٴεݹ�,ֱ��n/k=0(��ʱx^0=1)Ϊֹ
//	���� : Ҫ���ǵ�n����������ż��,��Ϊż��,��x^(n/2)*x^(n/2),�����ٳ���x
//	�뷨2 : ��n��Ϊ�����Ƽ���
//	���� : �������ұ���,�����ǰ����������Ϊ0,���yƽ��,Ϊ1,���yƽ���ٳ���x.(������˼���μ�)
// */
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//int power(int x,int n){//x��ʾ����,n��ʾ��ֵ,���ص���x^n��ֵ
//	if (n==0)return 1;//�ݹ����
//	int y=power(x,n/2);//���ݹ����x^(n/2)
//	y=y*y;
//	if (n%2==1)y=x*y;
//	return y;
//}
//
////����nҪת��Ϊ����������,���������ʾ����С���ʵ�λΪ1���ֽ�(8bit),�����ٽ�һ������bitλ.
////��Ҫ���nת��Ϊ�����ƵĴ�Сk��binary[k]
//#define BRYSIZE  16
//void T2B(int n,int &k,int* binary){//binary��������n�Ķ�����,k�Ƕ����Ƶĸ���.
//	//����n=5=101B,k=3,��binary[2][1][0]�ֱ�Ϊ101
//	while(n) {
//	    binary[k++] = n&0x01;
//	    n=n>>1;
//	}
//}
//
//
//int exp(int x,int n){//x��ʾ����,n��ʾ��ֵ(��Ҫת��Ϊ������),���ص���x^n��ֵ
//	int y=1;
//	int k=0;
//	int binary[BRYSIZE];
//	T2B(n,k,binary);
//	for (int i = k-1; i >=0 ; --i)//n=5=1* 2^2 +0* 2^1 +1* 2^0=1+2*(0+2*1)
//		//x^5=x^1 * x^(2*(0+2*1))
//		//x^(2*(0+2*1))=x^(0+2*1) * x^(0+2*1)
//		//x^(0+2*1)=x^0 * x^(2*1)
//		//x^(2*1) = x^1 * x^1
//	{
//		y=y*y;
//		if (binary[i]==1)y=x*y;
//	}
//	return y;
//}
////������� : ��һ�ַ����ȵڶ��ַ�����.
//
////int main(int argc, char const *argv[])
////{
////	int x=2;
////	int n=8;
////	cout<<exp(x,n)<<endl;
////	cout<<exp(2,3)<<endl;
////	cout<<exp(2,4)<<endl;
////	cout<<exp(2,5)<<endl;
////	cout<<exp(2,6)<<endl;
////	cout<<exp(2,7)<<endl;
////	cout<<exp(2,8)<<endl;
////	system("pause");
////	return 0;
////
////}