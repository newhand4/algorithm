//UNION(x,y)�ǽ�x,y�����ļ��Ϻϲ���һ������,��������Ϊ�����������Ƶ�����һ��(���Ⱥϲ�)
//FIND(x)��Ѱ��x�����ļ�������(·��ѹ��)
//���еĹؼ���Ҫ�����ҵ����ڵ�(��������)
//ʹ������:����Ҫ���Ǽ����ڲ����,ֻҪ����֪����������(���ڵ�),���Դ��ж�
//�����ô�:1.�����������Ƿ���������ϵ;2.������ͨ�ļ�����;3.���������ж�;4.��������ͬ��(������ָ��ĸ���)

//���ݽṹ������
//1.�����ʾ��:�±�j��ʾ�ڵ�j,A[j]��ʾj�ĸ��ڵ�,����9�ĸ��ڵ���4,����A[9]=4(����������������Ԫ��)
//2.����ʾ��: 3����Ա����,rank��ʾ�ýڵ����,value��ʾ�ýڵ��ֵ,father��ʾָ�򸸽ڵ��ָ��(�ձ�ʹ��,��������������������ʾ������)



#include <iostream>
using namespace std;

#define N 50

//����ʾ��(���������ʾ��,��ʹ���Բ��Ǻ�ǿ,��д)
typedef struct NODE
{
	int rank;
	int value;
	NODE * father;
	NODE(int value):father(NULL){
		this->rank=0;
		this->value=value;
		//this->father =NULL;
	}
}Node;
void  union1(Node *a,Node *b);
Node*  find1(Node *a);
Node*  find2(Node *a);

void  union1(Node *a,Node *b){
	//``a,bΪ��������,�Ƚ����ߵ�rank,�����aָ��bͬʱb��rank+1,������͵�ָ��ߵ�``
	//������,�����a,b�Ķ��岻���������ϵĸ��ڵ�,�����������ϵ����������ڵ�,���Ҫ���ҵ�a,b�����ĸ��ڵ�,�ڽ��кϲ�����
	//a,b�����ĸ��ڵ�
	Node *pa=find2(a);
	Node *pb=find2(b);
	if (pa->rank <= pb->rank)
	{
		pa->father=pb;
		if (pa->rank == pb->rank)
		{
			pb->rank++;
		}
	}
	else 
	{
		pb->father=pa;
	}
}

Node*  find1(Node *a){//����a�ڵ������ĸ��ڵ�(ͬʱѹ��·��)
	Node *root=a;
	while(root->father!=NULL) {//Ѱ�Ҹ��ڵ�,ֱ��fatherΪNULL
	    root =root->father;
	}
	//����ѭ��,��ʱrootָ��ľ��Ǹ��ڵ�
	//ѹ��·��,������ֻ�����ҵ����ڵ�,����ѹ��·��
	while(a!=root) {//a��ʱΪ�ƶ�ָ��,root��ʱΪ���ڵ�ָ��,��������,��aָ��root,ͬʱaָ��ָ��father
		Node *temp=a;
		a=a->father;
		temp->father=root;
	}//�������Ż�,������a������ʱ��,���һ���Ƕ����,����ʡȥ
	//������,���һ�β��Ƕ���,���find�Ľڵ㱾����Ǹ��ڵ�,����������,���µ�ע��,��˲����Ż�
	return root;
}

Node*  find2(Node *a){
	//���������׶�
	Node *y=a;
	while(y->father!=NULL) {
	    y=y->father;
	}
	Node *root=y;
	y=a;
	while(y->father!=NULL) {//δ���ǵ���y�������rootʱ,y->fatherΪNULL,Ӧ��Ϊy!=root����y->father!=NULL
	    Node *temp=y->father;
	    y->father=root;
	    y=temp;
	}
	return root;
}

/*int main(){
	//��ʼ������
	
	Node* p1=new Node(1);
	Node* p2=new Node(2);
	Node* p3=new Node(3);
	Node* p4=new Node(4);
	Node* p5=new Node(5);
	Node* p6=new Node(6);
	Node* p7=new Node(7);
	union1(p1,p2);
	union1(p2,p3);
	union1(p4,p5);
	union1(p1,p4);
	Node *root=find2(p1);

	system("pause");
	return 0;

}*/