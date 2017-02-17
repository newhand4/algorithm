/**
 * -*- coding : GBK -*-
 * @Author : huangshengjiang
 * @Email : 1005542693@qq.com
 * @Date : 2016-12-26 11:12
 * @Last Modified Date : 2017-01-22 15:53
 * @FileName : 最近点问题.cpp
 */

/*最近点问题
	基本概念 : 在一个二维平面上有大量的点,求出最近的两点.按维度可延伸为如何求出一维直线上最近的两点,或者三维空间中最近的两点.
			   按点数可延伸为在平面上求出最小面积/周长的三角形或点到某两点的直线最短.在三维空间中相应的是最小体积/面积的四面体或点到某三点构成的平面最近.
	由点到面到体的趣味联想 : 
		   1.按边的长度可以做成类似particles.js的效果出来(相邻的点画线连接,点之间又各自运动,线也随之运动).
		   2.用于无人飞机中图像的处理,识别出室内的物体(机器学习),以及计算出飞行路线.
		   3.平面图的迷宫求解路线.
		   4.识别出图片中的文字
		   5.网络节点中的关键节点(节点传输数据必经的节点)
		   6.有大量的独立点,如何连接全部点(没有孤立点)的路径最短?(矿脉路径最短问题,前提是路径平均费用一致)
		   7.A和B之间隔着山体(三维),如何找寻一条路径最短时间到达B?(行进速度与高度,陡度负相关,到一定的高度陡度速度为0)
		   8.如何通过照片快速检测出物体的立体形状(输入到autocad的格式),类似于无人驾车.
		   9.点击手机,快速显示周围的三维立体模型.可以添加感应
		   10.裸眼3D

	应用场景 : 平面上求最近点的问题,寻找距离的意义(而不是节点的意义),并且只在乎最短距离(考虑局部,不考虑整体,就像多个金矿中找出一条覆盖全部的最短路径,
			   有可能不包含最短两点的路径).额,现在能想到的是变化的意义(即求出局部最短的路径有可能是全局最短路径的一部分,两者关系是相互交叉).
			   应用于快速求出全局最短路径的可能性.
	局限性 : 有一定概率求得解属于全局最短路径.
	具体需求 : S是平面上所有点的集合,要求出在S中距离最近的一对点a(x,y),b(x,y)坐标.
		输入 : 使用直角坐标系(x,y)或极坐标(r,O).表示点的位置.也可在MFC中用二维图鼠标点击的方式表示位置信息输入.
		输出 : 距离最短的两点坐标(x1,y1)(x2,y2)和距离d.

	分析 : 
			-------------------------划去---------------------------------
		   可以根据抽屉原理(即鸽巢原理,n+1个苹果放入n个抽屉中,至少有一个抽屉有2个苹果).类似于在一个4*4的正方形中有17个点,至少有两个点距离小于sqrt(2).
		   理由 : 把4*4的正方形划分为16个1*1小正方形,17个点放入16个小正方形中,至少有2个点位于同一个小正方形中,距离小于小正方形中最长的sqrt(2).
		   不对啊,这只是推断出有两个点的距离保证小于sqrt(2),不一定是最小距离点.该理论不适用啊.
		   2.任选两点AB连线的垂直线(经过B),将点划分为两部分,计算该直线的函数表达式ax+by+c=0(特殊为by+c=0),先计算A是<0还是>0
		   	 将所有点都扔进去计算是否与A相异,或相同.否决,方法二计算麻烦效率没有明显改进.舍弃
		   3.将点按x坐标排序,求解每个点与附近临近点(x为标准)的距离.y坐标也是同样处理.(否决 . 理由如下 : 
		     例子,如A(3,3),与B(4,16),C(16,3)为临近点,但是距离比(4.4,4)长,计算结果不符合实际情况).
			--------------------------------------------------------------
		   1.按常规思路 : 求出每个点到其他点的距离,然后一一对比,找出最小点.时间复杂度为O(n(n+1)/2约等于n^2).(问题是如何能减少比较的次数?)
		   4.从常规思路出发,可以近可能根据一些外在判断减少距离的计算次数.(减少远距离点长度的计算)
		   	 以每个点为圆心,任选某个d为半径,形成一个圆.同时形成边长为d的正方形(此刻圆为内切圆).凡是x或y与点(x,y)的距离大于d,则不需要计算两点的距离.
		   	 可以改进,以每个点为正方形中心点.任选剩余某个点,计算距离r(正方形边长为2r).凡是x或y距离中心点的绝对值大于r,则舍弃.小于r则保留下来.
		   	 看看个数是否小于额定值d个.则直接计算点的距离比较.如果>d个,则保留点中再取一点,进行同样的处理(二分法处理),直到保留点个数小于d,直接计算.
		   	 每一个执行的结果都是求出一个点和剩余点的最短距离.规模为n的点执行n次,就得到所有点独立的最短距离.比较得出结果
		   	 该解决方案4相较于1来说,通过比较距离减少了距离远的点的计算.
		   5.继续改进,将点按x坐标排序,从前向后遍历(x最小的).每次取出一个点A(x,y),计算与右边点(若没有则左边点)的距离r,
		     然后从中间向两边遍历比较|xi-x|是否小于r.是<r,则保留(如何保留待定),否>r或达到链表(待定)的左右终点,则停止遍历.
		     在保留点中再按|yi-y|与r同样比较.最后得到以A为中心点的正方形内的可能点(保留点).
			 看保留的个数与限定值d(待定)的比较,<d则直接计算保留点的与A(x,y)的距离,取出最小距离同时两点信息;否>d,则从按x坐标排序开始继续(有问题)
			 上述是求解一个点A到剩余点的最短距离.求的A点距B点的距离为rmin.然后求B点以rmin划分,求解.如果求出的点恰巧是A点.则在链表中A,B点不再参与计算
			 如果不是,为C点,则以C点继续.一旦刚好出现C点和B点结果相互.等价于只要一求出某点A到其他点的最短距离,就可将A点从链表中删除,不再参与计算.
			 比较方案1,减少的是对无用远距离的长度计算.例如将本身A点需计算n-1条边的长度,现在只要计算更少边(2或3条).总体提升效率.
		   6.方案5,出现一种情况,刚好其他点在正方形和内切圆之间的空白处.所以当以A(x,y)为中心点,以2r为边长的正方形,内含有的点个数超过>d,递归处理时,
		     应随机选择保留点中的任一点距离计算.
		   	容器类型要求 : 插入后能够按x顺序排序,添加元素,删除中间元素.可用Set容器,理由有已有排序,没有重复.问题是不清楚默认的排序规则,
		   				   也不能自定义排序.需要重新定义.暂时用vector容器,使用sort函数排序.
			struct point
			{
				int x;
				int y;
				point(a,b):x(a),y(b){};
			};

			bool comp (point &a,point &b)
			{
				return a.x < b.x;
			}

		   	输入元素,形成vector<point*> PointVector;
			从左到右遍历PointVector中的每一个元素,设为(xi,yi);
				------------exec------------------
				计算与下一个点(x i+1,y i+1)的距离r,比较为最短距离保留下来;
				判断后续节点的(xi+2,yi+2)...与(xi,yi)的差值绝对值与r对比,小于r则存储,一旦大于r则停止判断.
				
				for (it 开始指向后续节点(xi+2,yi+2);  it != PointVector.end() ;it++ )
				{
				    if(|x(i+k)-xi| <= r 如果x是按从小到大排序)
					{
						if (|y(i+k)-yi| <= r)
						{
							存储该点;假设在newPointVector;
						}
					}
					else 
					{
						break;(结束比较)
					} 
				}

				进入循环体
				------------exec------------------

				-----------循环体-----------------
				int newsize = newPointVector.size();
				if (newsize < 额定值)
				{
					直接计算newPointVector每个点与(xi,yi)的距离,得出结果;
				}

				for (it 开始指向后续节点(xi+2,yi+2);  it != PointVector.end() ;it++ )
				{
					if(|x(i+k)-xi| <= r 如果x是按从小到大排序)
					{
						if (|y(i+k)-yi| <= r)
						{
							存储该点;假设在newPointVector;
						}
					}
					else 
					{
						break;(结束比较)
					} 
				}
				-----------循环体-------------------
		
		如何输入?
		用for循环一定的次数.
			每次产生新的point;
			结构体指针push_back到vector<point*>中;

	解决方案二 : 

 */
#include <iostream>
#include <time.h>
#include <vector>
//#include <cmath>
 #include   <algorithm> 
using namespace std;
#define WIDTH  150
#define LENGTH  200
#define MAXDIS  300

//函数
struct Point_
{
	int x;
	int y;
	Point_(int a,int b):x(a),y(b){};
};

typedef vector<Point_ *> PointVec;

struct Result
{
	Point_ * src;
	Point_ * dst;
	double dis;
	Result():src(NULL),dst(NULL),dis(MAXDIS){};
};

bool comp(Point_ *a,Point_ * b)
{
	return a->x < b->x ; 
}

class NearPoint
{
public : 
	NearPoint();
	~NearPoint(){};
	void init(int pointNum);	//随机产生数量为pointNum的PointVector数组
	void exec();				//执行
	void print();				//输出结果
	void test();
private : 
	//禁止临时对象的产生
	NearPoint(const NearPoint &){};
	NearPoint &operator = (const NearPoint & ){};

	void circle(PointVec * input );			//循环体,输入为newPointVector
	double compare(Point_ * tmp);			//与当前的结果比较,保留最短距离.

	//截取(x,y)范围在2r的正方形内的点集合,最后否决
	//void intercept(PointVec & output,PointVec &input,PointVec::iterator it,double dis);	
private : 
	PointVec PointVector;	//初始数组
	Point_ * cur;			//基准点
	Result  rs;				//结果
	static int  limit;		//额定值d
};

int NearPoint::limit = 5 ;

NearPoint :: NearPoint():cur(NULL){};

void NearPoint::init(int pointNum)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < pointNum; ++i)
	{
		int x = rand()%WIDTH ;
		int y = rand()%LENGTH ;
		Point_ * tmp = new Point_( x , y );
		PointVector.push_back(tmp);
	}
	sort(PointVector.begin(),PointVector.end(),comp);	
}

void NearPoint::exec()		   //执行
{
	int Vsize = PointVector.size();
	PointVec::iterator it = PointVector.begin();
	if (Vsize < limit)
	{
		PointVec::iterator tmp ;
		//直接计算newPointVector每个点与(xi,yi)的距离,得出结果;
		for (; it != PointVector.end() ; it++)
		{
			cur = *it;
			tmp = it;
			tmp++;
			for (; tmp != PointVector.end() ; tmp++)
			{
				compare(*tmp);
			}
		}
		return ;
	}

	PointVec newPointVector;
	PointVec::iterator tmp ;
	double r = 0 ;

	for (; it != PointVector.end()   ; it ++ )
	{
		cur = *it ;
		tmp = it ; 
		tmp ++;
		if (tmp == PointVector.end())break;
		r = compare(*tmp) ;
		tmp++ ;  
		//intercept(newPointVector,PointVector,tmp,r);
		for ( ; tmp != PointVector.end() ; ++tmp)
		{
			if(abs((*tmp)->x - cur->x) <= r )
			{
				if (abs((*tmp)->y - cur->y)<= r )
				{
					newPointVector.push_back(*tmp);
					//存储该点;假设在newPointVector;
				}
			}
			else 
			{
				break;
			} 

		}
		circle(&newPointVector);
		newPointVector.clear();
	}

}

void NearPoint::print()	   //输出结果
{
	printf("最近的两点分别为(%d,%d)和(%d,%d),距离为%f\n",rs.src->x,rs.src->y,rs.dst->x,rs.dst->y,rs.dis);
}

void NearPoint::circle(PointVec * input )			//循环体,输入为newPointVector
{
	PointVec PointVectortmp = *input ;
	int size = PointVectortmp.size() ; 
	PointVec::iterator it = PointVectortmp.begin();
	if (size < limit)
	{
		for (; it != PointVectortmp.end() ; it++)
		{
			compare(*it);
		}
		return ;
	}

	double dis = compare(*it) ;
	it ++ ;
	PointVec newPointVectortmp;
	//intercept(newPointVectortmp,PointVectortmp,it,dis);
	for (; it != PointVectortmp.end() ; it++)
	{
		if(abs((*it)->x - cur->x) <= dis )
		{
			if (abs((*it)->y - cur->y) <= dis )
			{
				newPointVectortmp.push_back(*it);
				//存储该点;假设在newPointVector;
			}
		}
		else 
		{
			break;
		} 

	}
	circle (&newPointVectortmp);
}

double NearPoint::compare(Point_ * tmp)				//与当前的结果比较,保留最短距离.
{

	 int delt_x = (tmp->x - cur->x) ;
	 int delt_y = (tmp->y - cur->y) ; 
	 double TwoPointDist = sqrt((double) delt_x * delt_x + delt_y * delt_y ) ; 
	 if (TwoPointDist < rs.dis)
	 {
	 	rs.src = cur ; 
	 	rs.dst = tmp ;
	 	rs.dis = TwoPointDist ;
	 }
	 return TwoPointDist ; 
}

void NearPoint::test()
{
	rs.src = NULL;
	rs.dst = NULL;
	rs.dis = MAXDIS;
	for (PointVec::iterator it = PointVector.begin();it!= PointVector.end();it++)
	{
		PointVec::iterator tmp = it;
		tmp++;
		for (;tmp!=PointVector.end();tmp++)
		{
			unsigned int delt_x = ((*tmp)->x - (*it)->x) ;
			unsigned int delt_y = ((*tmp)->y - (*it)->y) ; 
			double TwoPointDist = (double) sqrt( delt_x * delt_x + delt_y * delt_y ) ; 
			if (TwoPointDist < rs.dis)
			{
				rs.src = *it; 
				rs.dst = *tmp ;
				rs.dis = TwoPointDist ;
			}
		}
	}

}

//测试
int main(int argc, char const *argv[])
{
	/*while (1)
	{
		NearPoint t;
		t.init(50);
		t.exec();
		t.print();
	}
	printf("test\n");*/
	while (1)
	{
		NearPoint t;
		t.init(50);
		t.test();
		t.print();
	}

	system("pause");
	return 0;
}
