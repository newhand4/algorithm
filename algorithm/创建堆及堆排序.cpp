//ʵ�ֽ���������鹹���ɶѵĽṹ:(��Ϊ�ѵĽṹ�ǽ���������,�ڵ����Ǵ��ϵ���,������
//�����������±��ʾ)
//�뷨�ǽ���������(����,��ȫ������ԭ�����ϲ���),ÿ��ȡ��һ������,���뵱ǰβ��,
//�븸�ڵ�Ƚ�(���Ǵ�������)(�������ÿ��Ǹ��ڵ�����,��Ϊ�����֮ǰĬ�϶��������
//siftup����Ҳ���ǵ����ڵ��������,ֱ����siftup)


#include <iostream>
using namespace std;

//Ԥ����׼������Siftup/Siftdown
template <class T>
int Getlength(T &array){
	return (sizeof(array)/sizeof(array[0]));
}

void Siftup(int *a,int i){
	if (i==1)return ;
	int j=i/2;
	while(a[j-1] < a[i-1]&&i > 1) {
	    //����
	    int temp=a[j-1];
	    a[j-1]=a[i-1];
	    a[i-1]=temp;
	    i=j;
	    j=i/2;
	}
}

void Siftdown(int *a,int length,int i){
	if (2*i > length)return;
	bool done=false;
	int j=2*i;
	do{
		if (j+1<=length && a[j-1]<a[j])j++;
		if (a[j-1] > a[i-1])
		{
			int temp=a[j-1];
	    	a[j-1]=a[i-1];
	    	a[i-1]=temp;
	    	i=j;
	    	j=2*i;
		}else done=true;
	}while(j <= length && !done);
}
//������
//�Խ���Ϊ��������,��ʱ�临�Ӷ�Ϊlog2+log3+log4+...+logn�����������������
//���ַ�����Ĭ��ǰ�������ǰ��������,ÿ�ζ��ǵ���������ǰ������Ƚ�,���ֱȽϵ�Ч,���ԸĽ�
void  makeheap(int *a,int length){//a��ʾ����,length��ʾ���鳤��
	for (int i = 2; i <= length; ++i)
	{
		Siftup(a,i);//Siftup�Ǵ�����1�����ֵĶѿ�ʼ��(���ǿն�)
	}
}

void makeheap1(int *a,int length){
	for (int i = length/2; i >= 1; --i)//ѭ���ȵ�һ�ַ�����������
	{
		Siftdown(a,length,i);
	}

}
//������
//�Ƚ������������ж�����,Ȼ��a[0]��a[n-1]����,����������siftdown,��������,֪��lengthΪ2
void heapsort(int *a,int length){
	makeheap1(a,length);
	for (int i = length; i >= 2; --i)//i��ȡֵ��Χ��length��2
	{
		//�Ƚ���,��siftdown
		int temp=a[0];
	    a[0]=a[i-1];
	    a[i-1]=temp;
		Siftdown(a,i-1,1);
	}
}


/*int main(int argc, char const *argv[])
{
	int a[]={20,17,9,10,11,4,5,3,7,5};//{4,5,3,7,5,20,17,9,10,11};
	heapsort(a,10);
	for (int i = 0; i < 10; ++i)
	{
		cout<<a[i]<<" ";
	}
	system("pause");
	return 0;
}*/