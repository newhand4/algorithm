//#include <iostream>
//#include <array>
//using namespace std;
//
////����
//
///*ʵ�ֶ�������
//����һ������������һ����Ҫ���ҵ���ֵ
//�������ֵ��λ��,��û��,�򷵻�-1*/
////����C++����û��ֱ�ӻ�����鳤�ȵĺ���,���ʹ��sizeof(array)/sizeof(array[0]),������ģ�嶨��
//template <class T>
//int GetArrayLen(T& array){
//	return (sizeof(array)/sizeof(array[0]));
//}
//
//
////����
//int binary_search_1(int a[],int left,int right,int input);
//int binary_search_2(int a[],int n,int input);
//
//
////1.�ݹ����
////�뷨
///*��ԭ�������Ϊ����,�ڶԷ��ϵ������,�������ֲ���,ֱ����Ϊ0,����.
//������[0,length-1],���ֺ�Ϊ[0,length/2]��[length/2,length-1],�ڶ�����һ�����,ֱ����Ϊ0.*/
//int binary_search_1(int a[],int left,int right,int input){	//ע���a[]һֱ��ԭ����,���ǻ��ֺ�İ�����:�ô��ǲ���ÿ�ζ��ع�������,���ص��±겻�ø���ת��.
//	//left��ʾ��ǰ�����������
//	//right��ʾ��ǰ�����������
//	//input��ʾ��Ҫ���ҵ���ֵ
//	if (left>right)return -1;//�ݹ����,(left>=right)����Ⱥ�������,����պ����λ�þ��������,���ǻ᷵��-1.��˵Ⱥ�ȥ��
//	//�ݹ�����
//	int mid=(left+right)/2;
//	if (a[mid]==input)return mid;//mid���±�,��0����
//	if (a[mid]<input){
//		return binary_search_1(a,mid+1,right,input);
//	}else{
//		return binary_search_1(a,left,mid-1,input);
//	}
//}
////�������Ҫ���left��right��,�ǵݹ鷽ʽ
//
////2.�ǵݹ����
////�뷨
////ѭ�������ҵ����ֵ�,�Ƚ���ֵ,�����򷵻�����,���������ϰ벿����,С�������°벿����
//
//int binary_search_2(int a[],int n,int input){
//	int left=0;
//	int right=n;
//	//int right=GetArrayLen(a);//������,���ú���ʱ����aΪ��,����Ϊ1,�����ڸú����е���
//	int mid=(left+right)/2;
//	while(a[mid]!=input) {
//		if (a[mid]>input)right=mid-1;
//		else left=mid+1;
//		if (left>right)return -1;//���ǵȺ�����
//		mid=(left+right)/2;
//	}
//	return mid;
//}
//
////int main(int argc, char const *argv[])
////{
////	int a[]={1,2,3,4,5,6,7,8,9,10,11,13,14,23};
////	int n=GetArrayLen(a);
////	for(int i=0;i<=n+10;i++){
////		int result=binary_search_2(a,n,i);
////		cout<<result<<endl;
////	}
////
////	// cout<<sizeof(a)<<endl;
////	// cout<<sizeof(a[0])<<endl;
////	system("pause");
////	return 0;
////}
