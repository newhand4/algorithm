//堆辅助运算Siftup
//堆的定义是可看做是几乎完美的二叉树,父节点的键值不小于子节点.
//如果某个节点i>1,有H[i/2]父节点比子节点H[i]小,则该节点需要向上移动,知道满足堆的性质(父节点的键值不小于子节点),因此有算法Siftup
//用数组表示堆,数组的下标表示节点的位置(近乎完全二叉树,除底层右边外是完全二叉树,从左向右,从上到下标记,从1开始标记),数组的值表示该节点的值,
//满足对于任意的i>1(除根节点),H[i/2](取下限位)>H[i],若插入底部的新节点不满足要求,则Siftup
#include <iostream>
using namespace std;

void Siftup2(int a[],int i){//a数组表示堆,a[0..n-1],i表示需要上移的节点位置,范围是1到n
	//i--;下标问题,数组从0开始,i从1开始,统一下标,有问题,不能直接减一,否则会出现错位情况,如第5个节点的父节点是第2个节点,对应下标分别是4,1.
	//然而下标4除2后是2,表示第3个字节,矛盾.
	//因此第一种方法要先按位置除2,找出父节点的位置,分别-1就是对应数组的下标.
	//第二种方法是将直接将数组长度+1,也就是H[0]空出来,使的下标直接对应坐标,不用减一,
	//第二种方法可以避免-1产生的忽略等问题.但是第一种方法的比较赋值至多logn+1次,则-1操作为6*(logn+1)次,
	//而第二种方法要在原有数组基础上长度加一,相比第一种要多执行n+1次赋值操作,
	//这种减少6*(logn+1)次的代价是多执行n+1的赋值操作,得不偿失,舍弃.
	if (i==1)return ;//表示该节点的位置是根节点,不需要移动
	//如果不是,则则每次需要比较H[i/2]和H[i]的值,同时i/2和i也在变化,不满足则交换,直到满足H[i/2]>H[i]或者i=1为止
	int j=i/2;
	while(a[j-1] < a[i-1]&&i > 1) {
	    //交换
	    int temp=a[j-1];
	    a[j-1]=a[i-1];
	    a[i-1]=temp;
	    i=j;
	    j=i/2;
	}
}

void Siftup3(int a[],int i){
	bool done=false;
	//i--;理由同上
	if (i==1)return;
	do{
		if (a[i/2-1] < a[i-1])
		{
			int temp=a[i/2-1];
	    	a[i/2-1]=a[i-1];
	    	a[i-1]=temp;
		}
		else done=true;
		i=i/2;
	}while(!done && i > 1);
}


/*int main(int argc, char const *argv[])
{
	int a[]={20,17,9,10,11,4,25,3,7,5};
	Siftup2(a,7);
	for (int i = 0; i < 10; ++i)
	{
		cout<<a[i]<<" ";
	}
	system("pause");
	return 0;
}*/




