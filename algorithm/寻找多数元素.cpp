/**
 * -*- coding : GBK -*-
 * @Author : huangshengjiang
 * @Email : 1005542693@qq.com
 * @Date : 2016-09-21 11:15
 * @Last Modified Date :  2016-10-19 10:46
 * @FileName :   Ѱ�Ҷ���Ԫ��.cpp
 */

/*Ѱ�Ҷ���Ԫ��.cpp
	�������� : ������A[1...n]��,����и���ֵ����������[n/2]��,����Ϊ����ֵΪ����Ԫ��,���ظ�ֵ.���򷵻�-1

	�۲���� : ��������ɾ������������ͬ����ֵ,��ԭ�����еĶ���Ԫ��������������Ȼ�Ƕ���Ԫ��.

	����취1 : �����ʾ,����һ����СΪmax(A��������ֵ)�Ķ�̬����B[max](��Ҫ����A),��ʼ��Ϊ0.�ٶ�����A����,��B[A[i]]++;
				����������,B[j]��ֵ���Ƕ�Ӧj=A[i]������.ֻҪB[j]��ֵ����n/2����,�����j,�������-1
	����1 : ʱ�临�Ӷ�Ϊn*n*max,�ռ临�Ӷ�Ϊmax��С������.��һ�����ص�ȱ��,�����˴������õĿռ�max-n.���max����
			nƫС,�����˷��ڴ�,Ҳ����cpu�Ĺ���.

	����취2 : �����ʾ,�ڵ�ṹNode����������Ա����,value��ʾ��ֵ,count��ʾ����ֵ������,next��ָ��,ָ����һ��Node.
				��������A,��A[i]�������ͷ��β���бȽ�,���ҵ���Ӧ��valueֵ,��count++;���û��,��newһ��Node,value=A[i],count=1,next = NULL;
				Ȼ���������,��������еĽڵ�this->count > n/2,�����this->value;�������-1
	����2 : ��ʡ�˴��������ʾ�Ŀռ�,�ռ临�Ӷ�Ϊdifferent(��ͬ��Ԫ������)�Ľڵ�ռ�.ʱ�临�Ӷ���(���Ƚϴ���)Ϊ1+2+...+n-1 = n(n-1)/2,
			ΪO(n*n),���ӶȻ���̫��.�Ƚ������Ͽ����Ż�.

	����취3 : ָ��������ʾint *C[n],������n����С������,�����е�Ԫ����ָ��,��ʼ��ָ��A[i]��Ӧ�ĵ�ַ,Ҳ���ǽ���A[i]Ԫ�ص�����,
				��������������(�Ե���������,��������ȵ�),�����µıȽϴ���Ϊnlogn��,Ȼ���ڱ���һ��,����ͬ��ֵͳ��,������.
	����3 : ������(C[n])���н�������,���Խ�ʡ������ʵ�帳ֵ����,��ʡ�������ڴ���Դ.(�������Ƕ��ڽṹ������ݶ���Ч����,����int�ĸ���û��Ҫ)

	����취4 : ֱ�Ӷ�����A��������,��Ƚϴ���Ϊnlogn��,�ٱ���һ��A,ͳ����ͬ����ֵ������,������
	����4 : ͳ����ͬ��ֵ������,��ͳ�Ƶ��������õļ���,�˷���Դ.����ֱ�Ӹ��ݶ���Ԫ�صĶ���,ֱ��ͳ��A[n/2]��ֵ������

	����취5 : �ڰ취4�Ͻ��иĽ�,ֱ��ͳ��A[n/2]��ֵ������,�����ö��ַ������ҳ���ʼλ�ú��յ�λ��,�����������,��n/2�Ƚ�,������
	����5 : ʱ�临�Ӷ�nlogn+logn,�ռ临�Ӷ�Ϊn

	����취6 : ����������,ֱ���ҳ��м�Ԫ��mid,Ȼ������ҳ�mid������
	����6 : ʱ�临�Ӷ�Ϊ20n+n,����.

	����취7 : 

 */
#include <iostream>
using namespace std;
template<class T>
int Size(T &array)
{
	return sizeof(array)/sizeof(array[0]);
}


//����1,��������A,�ҳ�����Ԫ��
typedef struct Node
{
	int value;
	int count;
	Node * next;
	Node(int num):value(num),count(1),next(NULL){};
	Node():value(-1),count(-1),next(0){};
}* headnode,* lnode;

class List
{
	headnode head;
	int n;
public:
	List():n(0){head = new Node();};
	~List(){deletelist(head);};
	bool find(int num);		
	void addNode(int num);
	void increment(int num);
	int  major_return();
	void deletelist(Node *p);
};

void List::deletelist(Node *p)
{
	while (p->next)
	{
		Node *temp = p->next;
		p->next = temp->next;
		delete temp;
	}
	delete p;

}

bool List::find(int num)
{
	n++;
	lnode pre;
	pre = head;
	while(pre != NULL && pre->value != num) {
	    pre = pre->next;
	}
	if (pre == NULL)
	{
		return false;
	}
	return true;
}

void List::addNode(int num)
{
	lnode pre = head;
	lnode newnode = new Node(num);
	while(pre->next != NULL ) {
	    pre = pre->next;
	}
	pre ->next = newnode;
}

void List::increment(int num)
{
	lnode pre;
	pre = head;
	while(pre->value != num) {
	    pre = pre->next;
	}
	pre ->count ++;
}

int  List::major_return()
{
	lnode pre;
	pre = head;
	int temp = n/2;
	while(pre != NULL) {
		if (pre -> count >= temp)
		{
			return pre ->value;
		}
	    pre = pre->next;
	}
	return -1;
}

int Majority_first(int *array,int n)
{
	List headlist;
	int temp = 0;
	for (int i = 0; i < n; ++i)
	{
		temp = array[i];
		if (headlist.find(temp))
		{
			headlist.increment(temp);
		}
		else
		{
			headlist.addNode(temp);
		}
	}
	return headlist.major_return();
}

//����2,ɾ������������������ͬ��Ԫ��,ԭ����Ķ���Ԫ������������Ķ���Ԫ��
/*
	���� : ÿ�εݹ����,���Ȳ���ԭ���������ⲻ��ͬ��������ֵ
		(ֱ���뵱ǰ�������һλ���бȽ�,��ͬ,�򽫲�ͬ����ֵ�뵹���ڶ�λ�Ե�,���ﲻ������,��Ϊ����ָ������ͽṹС,���ʺ�)
		�ݹ���ú������βα�Ӧ������a,����n.�Ż�int.�ݹ������־��1.�Ƚ���û�в���ͬ���� 2.ֻ��һ��Ԫ��(�������������1��) (Ĭ���ж���Ԫ��>n/2�������)
		��������ó��Ľ���Ǻ�ѡֵ,����Ҫ��������,�ҳ�����.
	������� : ����2��ÿ��ɾ��������ͬԪ��.���Խ��иĽ�.
*/
int candidate(int *array,int num)
{
	if (num == 0)return -1;
	if (num == 1)return array[0];
	int last = array[num-1];
	int i = num - 2;
	for (; i >= 0 ; i-- )
	{
		if (array[i] != last)break;
	}
	if ( i == -1)return array[0];
	last = array[num - 2];
	array[num - 2] = array [i];
	array[i] = last;
	return candidate(array,num-2);
}

//�Ľ�candidate,��ͷ����,�����һ��Ϊƽ������(��ѡԪ��������Ԫ��������ͬ),��ӽ������ٿ�ʼ�Ƚ�,��ʡ�ݹ���õĴ���
int improve_candidate(int *array ,int num,int start)
{
	int j = start ;
	int temp = array[start] ;
	int count = 1;
	while (j < num && count > 0)
	{
		j++ ;
		if (array[j] == temp)
		{
			count++;
		}
		else
		{
			count--;
		}
	}
	if ( j == num)return temp;
	else return improve_candidate(array,num,j+1);

}


int Majority_second(int *array,int n)
{
	int can = improve_candidate(array,n,1);
	if (can == -1) return -1;
	int count = 0 ;
	for (int i = 0; i < n ; i++)
	{
		if (array[i] == can)
		{
			count ++;
		}
	}
	if (count > n/2)return can;
	return -1;
}

//����
/*int main(int argc, char const *argv[])
{
	int a[]={1,2,3,4,5,6,7,8,9,1,1,1,1,1,1,1,1};
	int n=Size(a);
	int ret = Majority_second(a,n);
	if (ret == -1)
	{
		cout << "û�ж���Ԫ��";
	}
	else
	{
		cout << "����Ԫ��Ϊ: "<<ret<<endl;
	}
	system("pause");
	return 0;
}*/
