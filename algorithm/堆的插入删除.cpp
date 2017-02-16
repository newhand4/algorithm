#include <iostream>
using namespace std;

//ʵ�ֽ�Ԫ��x�������ж�a[]
//��Ԫ��x��ʱ����a[length]λ��,Ȼ�����siftup,�������.�ؼ�������������a��С�ı仯�Ƿ���Ҫ���½�������b,��������������.

//�����ж�a[]ɾ����i��Ԫ��
//�൱�ڽ���i��Ԫ��ֵ��Ϊ-1,����siftdown,����ײ�,Ȼ��ɾ��.��������?����,����ֵײ���߿ճ�һ��Ԫ��,����,�÷�������
//����˼��,��������Ҫ����i��Ԫ�ط����ڵ�n��λ����ɾ��,���Կ��Խ�a[n-1]��a[i-1]����,Ȼ������½ڵ�Ƚ�,�����Ƿ�siftup����siftdown


//�����ж�a[]ɾ�����Ԫ�ز�����max
//ͬ��,ֻ�ǽ�ɾ����i��Ԫ�ع̶�Ϊɾ����1��Ԫ��,Ȼ�󷵻ص�һ��Ԫ��ֵ


//Ԥ����
template <class T>
int Getlength(T &array){
	return (sizeof(array)/sizeof(array[0]));
}

void Siftup1(int *a,int i){
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
void Siftdown1(int *a,int length,int i){
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

//�ѵĲ���
void insert(int *a ,int length,int x){//a��ʾ��������ĸ��ָ��,length��ʾ����ĳ���,x��ʾҪ�����Ԫ��
	*(a+length)=x;//����ȫ,��д���������,���ܻᵼ�³������
	Siftup1(a,length+1);
}

//ɾ���ѵĵ�i��Ԫ��
void delete1(int *a,int length,int i){//a��ʾ��������ĸ��ָ��,length��ʾ����ĳ���,i��ʾҪɾ����Ԫ��λ��
	if (i==length)return ;//���Ҫɾ����Ԫ�ؾ���a[n-1],��ֱ��ɾ��,���ò���
	//����Ԫ��a[i-1]��a[n-1],�������һλ����Ҫ,���Կ���ֱ�Ӹ�ֵ��a[i-1]
	a[i-1]=a[length-1];
	//�����½ڵ�Ƚ�,����ֱ�����Ͻڵ�Ƚ�,�����ڸ��ڵ�,��siftup,����siftdown.
	//���������,��û���ƶ�λ��,Ҳ������siftup,siftdown,��Ϊ��������������������Ĵ���
	if (i==1||a[i-1] <= a[i/2-1])Siftdown1(a,length,i);
	else Siftup1(a,i);
	/*if (a[i-1] >= a[i/2-1])Siftup1(a,i);//a[i/2-1]��ʾ���ڵ�,��������,����δ�ж��Ƿ���ڸ��ӽڵ�
	else Siftdown1(a,length,i);*/

}

//ɾ���ѵ����ֵ
int deletemax(int *a,int length){//a��ʾ��������ĸ��ָ��,length��ʾ����ĳ���,���ص�ֵ��max
	int max=a[0];
	delete1(a,length,1);
	return max;
}



/*int main(int argc, char const *argv[])
{
	int a[]={20,13,18,10,11,17,16,3,7,5,6,16};
	int *p=a;
	int length=Getlength(a);
	delete1(a,length,4);
	//cout<<max<<endl;
	for (int i = 0; i < length-1; ++i)
	{
		cout<<p[i]<<" ";
	}
	system("pause");
	return 0;
}
*/
