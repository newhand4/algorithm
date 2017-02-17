/**
 * -*- coding : GBK -*-
 * @Author : huangshengjiang
 * @Email : 1005542693@qq.com
 * @Date : 2016-12-26 11:12
 * @Last Modified Date : 2017-01-22 15:53
 * @FileName : ���������.cpp
 */

/*���������
	�������� : ��һ����άƽ�����д����ĵ�,������������.��ά�ȿ�����Ϊ������һάֱ�������������,������ά�ռ������������.
			   ������������Ϊ��ƽ���������С���/�ܳ��������λ�㵽ĳ�����ֱ�����.����ά�ռ�����Ӧ������С���/������������㵽ĳ���㹹�ɵ�ƽ�����.
	�ɵ㵽�浽���Ȥζ���� : 
		   1.���ߵĳ��ȿ�����������particles.js��Ч������(���ڵĵ㻭������,��֮���ָ����˶�,��Ҳ��֮�˶�).
		   2.�������˷ɻ���ͼ��Ĵ���,ʶ������ڵ�����(����ѧϰ),�Լ����������·��.
		   3.ƽ��ͼ���Թ����·��.
		   4.ʶ���ͼƬ�е�����
		   5.����ڵ��еĹؼ��ڵ�(�ڵ㴫�����ݱؾ��Ľڵ�)
		   6.�д����Ķ�����,�������ȫ����(û�й�����)��·�����?(����·���������,ǰ����·��ƽ������һ��)
		   7.A��B֮�����ɽ��(��ά),�����Ѱһ��·�����ʱ�䵽��B?(�н��ٶ���߶�,���ȸ����,��һ���ĸ߶ȶ����ٶ�Ϊ0)
		   8.���ͨ����Ƭ���ټ��������������״(���뵽autocad�ĸ�ʽ),���������˼ݳ�.
		   9.����ֻ�,������ʾ��Χ����ά����ģ��.������Ӹ�Ӧ
		   10.����3D

	Ӧ�ó��� : ƽ����������������,Ѱ�Ҿ��������(�����ǽڵ������),����ֻ�ں���̾���(���Ǿֲ�,����������,������������ҳ�һ������ȫ�������·��,
			   �п��ܲ�������������·��).��,�������뵽���Ǳ仯������(������ֲ���̵�·���п�����ȫ�����·����һ����,���߹�ϵ���໥����).
			   Ӧ���ڿ������ȫ�����·���Ŀ�����.
	������ : ��һ��������ý�����ȫ�����·��.
	�������� : S��ƽ�������е�ļ���,Ҫ�����S�о��������һ�Ե�a(x,y),b(x,y)����.
		���� : ʹ��ֱ������ϵ(x,y)������(r,O).��ʾ���λ��.Ҳ����MFC���ö�άͼ������ķ�ʽ��ʾλ����Ϣ����.
		��� : ������̵���������(x1,y1)(x2,y2)�;���d.

	���� : 
			-------------------------��ȥ---------------------------------
		   ���Ը��ݳ���ԭ��(���볲ԭ��,n+1��ƻ������n��������,������һ��������2��ƻ��).��������һ��4*4������������17����,���������������С��sqrt(2).
		   ���� : ��4*4�������λ���Ϊ16��1*1С������,17�������16��С��������,������2����λ��ͬһ��С��������,����С��С�����������sqrt(2).
		   ���԰�,��ֻ���ƶϳ���������ľ��뱣֤С��sqrt(2),��һ������С�����.�����۲����ð�.
		   2.��ѡ����AB���ߵĴ�ֱ��(����B),���㻮��Ϊ������,�����ֱ�ߵĺ������ʽax+by+c=0(����Ϊby+c=0),�ȼ���A��<0����>0
		   	 �����е㶼�ӽ�ȥ�����Ƿ���A����,����ͬ.���,�����������鷳Ч��û�����ԸĽ�.����
		   3.���㰴x��������,���ÿ�����븽���ٽ���(xΪ��׼)�ľ���.y����Ҳ��ͬ������.(��� . �������� : 
		     ����,��A(3,3),��B(4,16),C(16,3)Ϊ�ٽ���,���Ǿ����(4.4,4)��,������������ʵ�����).
			--------------------------------------------------------------
		   1.������˼· : ���ÿ���㵽������ľ���,Ȼ��һһ�Ա�,�ҳ���С��.ʱ�临�Ӷ�ΪO(n(n+1)/2Լ����n^2).(����������ܼ��ٱȽϵĴ���?)
		   4.�ӳ���˼·����,���Խ����ܸ���һЩ�����жϼ��پ���ļ������.(����Զ����㳤�ȵļ���)
		   	 ��ÿ����ΪԲ��,��ѡĳ��dΪ�뾶,�γ�һ��Բ.ͬʱ�γɱ߳�Ϊd��������(�˿�ԲΪ����Բ).����x��y���(x,y)�ľ������d,����Ҫ��������ľ���.
		   	 ���ԸĽ�,��ÿ����Ϊ���������ĵ�.��ѡʣ��ĳ����,�������r(�����α߳�Ϊ2r).����x��y�������ĵ�ľ���ֵ����r,������.С��r��������.
		   	 ���������Ƿ�С�ڶֵd��.��ֱ�Ӽ����ľ���Ƚ�.���>d��,����������ȡһ��,����ͬ���Ĵ���(���ַ�����),ֱ�����������С��d,ֱ�Ӽ���.
		   	 ÿһ��ִ�еĽ���������һ�����ʣ������̾���.��ģΪn�ĵ�ִ��n��,�͵õ����е��������̾���.�Ƚϵó����
		   	 �ý������4�����1��˵,ͨ���ȽϾ�������˾���Զ�ĵ�ļ���.
		   5.�����Ľ�,���㰴x��������,��ǰ������(x��С��).ÿ��ȡ��һ����A(x,y),�������ұߵ�(��û������ߵ�)�ľ���r,
		     Ȼ����м������߱����Ƚ�|xi-x|�Ƿ�С��r.��<r,����(��α�������),��>r��ﵽ����(����)�������յ�,��ֹͣ����.
		     �ڱ��������ٰ�|yi-y|��rͬ���Ƚ�.���õ���AΪ���ĵ���������ڵĿ��ܵ�(������).
			 �������ĸ������޶�ֵd(����)�ıȽ�,<d��ֱ�Ӽ��㱣�������A(x,y)�ľ���,ȡ����С����ͬʱ������Ϣ;��>d,��Ӱ�x��������ʼ����(������)
			 ���������һ����A��ʣ������̾���.���A���B��ľ���Ϊrmin.Ȼ����B����rmin����,���.�������ĵ�ǡ����A��.����������A,B�㲻�ٲ������
			 �������,ΪC��,����C�����.һ���պó���C���B�����໥.�ȼ���ֻҪһ���ĳ��A�����������̾���,�Ϳɽ�A���������ɾ��,���ٲ������.
			 �ȽϷ���1,���ٵ��Ƕ�����Զ����ĳ��ȼ���.���罫����A�������n-1���ߵĳ���,����ֻҪ������ٱ�(2��3��).��������Ч��.
		   6.����5,����һ�����,�պ��������������κ�����Բ֮��Ŀհ״�.���Ե���A(x,y)Ϊ���ĵ�,��2rΪ�߳���������,�ں��еĵ��������>d,�ݹ鴦��ʱ,
		     Ӧ���ѡ�������е���һ��������.
		   	��������Ҫ�� : ������ܹ���x˳������,���Ԫ��,ɾ���м�Ԫ��.����Set����,��������������,û���ظ�.�����ǲ����Ĭ�ϵ��������,
		   				   Ҳ�����Զ�������.��Ҫ���¶���.��ʱ��vector����,ʹ��sort��������.
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

		   	����Ԫ��,�γ�vector<point*> PointVector;
			�����ұ���PointVector�е�ÿһ��Ԫ��,��Ϊ(xi,yi);
				------------exec------------------
				��������һ����(x i+1,y i+1)�ľ���r,�Ƚ�Ϊ��̾��뱣������;
				�жϺ����ڵ��(xi+2,yi+2)...��(xi,yi)�Ĳ�ֵ����ֵ��r�Ա�,С��r��洢,һ������r��ֹͣ�ж�.
				
				for (it ��ʼָ������ڵ�(xi+2,yi+2);  it != PointVector.end() ;it++ )
				{
				    if(|x(i+k)-xi| <= r ���x�ǰ���С��������)
					{
						if (|y(i+k)-yi| <= r)
						{
							�洢�õ�;������newPointVector;
						}
					}
					else 
					{
						break;(�����Ƚ�)
					} 
				}

				����ѭ����
				------------exec------------------

				-----------ѭ����-----------------
				int newsize = newPointVector.size();
				if (newsize < �ֵ)
				{
					ֱ�Ӽ���newPointVectorÿ������(xi,yi)�ľ���,�ó����;
				}

				for (it ��ʼָ������ڵ�(xi+2,yi+2);  it != PointVector.end() ;it++ )
				{
					if(|x(i+k)-xi| <= r ���x�ǰ���С��������)
					{
						if (|y(i+k)-yi| <= r)
						{
							�洢�õ�;������newPointVector;
						}
					}
					else 
					{
						break;(�����Ƚ�)
					} 
				}
				-----------ѭ����-------------------
		
		�������?
		��forѭ��һ���Ĵ���.
			ÿ�β����µ�point;
			�ṹ��ָ��push_back��vector<point*>��;

	��������� : 

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

//����
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
	void init(int pointNum);	//�����������ΪpointNum��PointVector����
	void exec();				//ִ��
	void print();				//������
	void test();
private : 
	//��ֹ��ʱ����Ĳ���
	NearPoint(const NearPoint &){};
	NearPoint &operator = (const NearPoint & ){};

	void circle(PointVec * input );			//ѭ����,����ΪnewPointVector
	double compare(Point_ * tmp);			//�뵱ǰ�Ľ���Ƚ�,������̾���.

	//��ȡ(x,y)��Χ��2r���������ڵĵ㼯��,�����
	//void intercept(PointVec & output,PointVec &input,PointVec::iterator it,double dis);	
private : 
	PointVec PointVector;	//��ʼ����
	Point_ * cur;			//��׼��
	Result  rs;				//���
	static int  limit;		//�ֵd
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

void NearPoint::exec()		   //ִ��
{
	int Vsize = PointVector.size();
	PointVec::iterator it = PointVector.begin();
	if (Vsize < limit)
	{
		PointVec::iterator tmp ;
		//ֱ�Ӽ���newPointVectorÿ������(xi,yi)�ľ���,�ó����;
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
					//�洢�õ�;������newPointVector;
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

void NearPoint::print()	   //������
{
	printf("���������ֱ�Ϊ(%d,%d)��(%d,%d),����Ϊ%f\n",rs.src->x,rs.src->y,rs.dst->x,rs.dst->y,rs.dis);
}

void NearPoint::circle(PointVec * input )			//ѭ����,����ΪnewPointVector
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
				//�洢�õ�;������newPointVector;
			}
		}
		else 
		{
			break;
		} 

	}
	circle (&newPointVectortmp);
}

double NearPoint::compare(Point_ * tmp)				//�뵱ǰ�Ľ���Ƚ�,������̾���.
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

//����
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
