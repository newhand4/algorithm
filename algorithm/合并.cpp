//#include <iostream>
//#include <vector>
////#include <array>
//using namespace std;
//
////Ҫ��:�ϲ����������Ԫ��(һ������),���Ҳ������
////����:���������Ԫ��
////���:һ�������Ԫ��
////�뷨
//
////�½�����:
////������һ���ռ��СΪa.length+b.length������
////3��ָ��ֱ�ָ��3������,����һ��ָ����������ص���ÿ������һ,��������ÿ������ֻ��һ����һ.
//
////����C++����û��ֱ�ӻ�����鳤�ȵĺ���,���ʹ��sizeof(array)/sizeof(array[0]),������ģ�嶨��
//template <class T>
//int GetArrayLen(T& array){
//	return (sizeof(array)/sizeof(array[0]));
//}
//
//vector<int> merge(int *a,int *b,int alength,int blength){//Լ������������ֵ����С�����鳤��
//	vector<int> c(alength+blength);
//	int i=0,j=0,count=0;
//	while(i < alength && j < blength) {//ʹ��while�ܺܺý������
//	    if (a[i] < b[j]) c[count++] = a[i++];
//	    else c[count++] = b[j++];
//	}
//	while (j < blength)//��ʾa���Ѿ�������
//	{
//		c[count++]=b[j++];
//	}
//	while (i < alength)//��ʾb���Ѿ�������
//	{
//		c[count++] = a[i++];
//	}
//
//	return c;
//}
//
////int main(int argc, char const *argv[])
////{
////	int a[]={1,3,5,7,9,10,23,45,46,56,78};
////	int b[]={2,4,6,8,11,45,48,57};
////	int alength=GetArrayLen(a),blength=GetArrayLen(b);
////	//cout<<alength<<endl;
////	//cout<<blength<<endl;
////	vector<int> c=merge(a,b,alength,blength);
////	int clenth=alength+blength;
////	//int clenth=GetArrayLen(c);��int����λΪ4
////	for (int i = 0; i < clenth; ++i)
////	{
////		cout<<c[i]<<endl;
////	}
////	system("pause");
////	return 0;
////}