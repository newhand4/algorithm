///**
// * -*- coding : GBK -*-
// * @Author : huangshengjiang
// * @Email : 1005542693@qq.com
// * @Date : 2016-10-28 14:00
// * @Last Modified Date : 2016-12-22 15:11
// * @FileName : ����ˮͰ�ȷ�8��ˮ.cpp
// */
//
///*����ˮͰ�ȷ�8��ˮ
//
//	Ӧ�ó��� : ��3������,�ֱ���3��/5��/8����ˮͰ(û�п̶�),��������8����ˮͰװ��ˮ,3����5����ˮͰ�յ�.Ҫ��8����ˮ�ȷֳ�����,ÿ����4��ˮ
//			   Լ��������ֻ������3������,���ܽ���������������. Ҫ���г����еȷֳɹ��Ĺ���.
//
//	�������� : ��ʹ��3/5/8��������,����ʼװ��8����ˮ�ȷֳ�����,ÿ����4��ˮ.Ҫ���г����еȷֳɹ��Ĺ���
//		���� : 3�������������Ϳ�ʼˮ��.��Ӧ����Ϊ(3,5,8)��8
//		��� : ��ʼˮ���ȷ����ݳɹ������й���. 
//
//	���� : ���ȱ�����ȷ���Ǽ����ʵ�ֵ���ģ�������е�˼������.˼������������Ȼ����������ÿһ�����ɼ����ʵ�ֵ�.����ڽ������ǰ,
//		   Ӧ����������Ȼ�Ľ������,���ɼ����ʵ�ֻ��߼�����.
//		   ����Ȼ�ĽǶ���ʵ�� : 
//		   1.��ʼ,3������0��ˮ,5������0��ˮ,8������8��ˮ.(A,a)(B,b)(C,c),��д��ʾ������������,Сд��ʾ�����˿̵�ˮ��.(capacity,size)
//		   ������n�������ĳ�ʼ������ˮ��.������ʽ��ʱ�򵥻�.���ڲ�Ҫ������ʽ id(capacity,size) ; 
//		   ������
//		   struct container{
//				int capacity ; 
//				int size ; 
//		   	}
//		   	vector<container>  con; ÿ��������push_back(new container) ; 
//		   	prinf("������Ͱ������ n ");
//			scanf("%d",&n);
//			vector<container>  con(n);
//			for (int i = 0; i < �����Ͱ����n; ++i)
//			{
//				prinf("������%d��Ͱ������",i+1);
//				scanf("%d",&con[i].capacity);
//				prinf("������%d��Ͱ�ĵ�ǰˮ��",i+1);
//				scanf("%d",&con[i].size);
//			}
//
//
//		   	��ӽ�����,�ڴ���һ��Init��ʾ��ʼ����״̬.conΪ�仯��״̬.
//
//		   2.������3������,���ÿ����6�ֵ�ˮ����,�ֱ���3->5,3->8,5->8,5->3,8->3,8->5.����������3/5��������ˮΪ��.��ֻ��8->3��8->5�ĵ�ˮ����
//		   ��Ҫ��������,һ����ˮ����������(����src->des����Ϣ).�ص��Ǹú���ֻ��ִ��һ��,������Ӧ�Ķ�������.
//			struct action{
//				int src;
//				int des;
//			}
//		    vector<action>  act.��������Ľ����ֻ��Ҫ��ʼ״̬�Ͷ����б�.
//			for (i����con.size())
//			{
//				action ����.src = i ; 
//				for (j����con.size()��j!=i)
//				{
//					action ����.des = j ; 
//					act.push_back(����) ; 
//				}
//				
//			}
//
//		    ���ж����б�Ӧ����һ��ջ(��vector)��ʾ(ֻҪβ�������ɾ��).����ȱ���.����stack<int> ��vector<int> actlist.
//			����ÿ������action.�ж϶����ĺ�����,������ѹ��,����ѹ����״̬,�ж��Ƿ�ȷֳɹ�,����ɹ�,�������ǰ�����б�,Ȼ�󵯳��˶���,
//			������һ���������.���ʧ��,����뵽��һ��ĵ���.
//			��������������,��������.
//		    ��ʼʱ��Ҫѹ��һ��0,ѹ��,�����ɶ�. 
//		    ״̬�ı仯Ҳ��һ��ջ��ʾ,����stack<vector<container>> ��vector<vector<container>> statuslist.(�Ŀռ�)
//		    ---��������һ��״̬��ʾ,����������ʱ�����״̬������.(�ļ���ʱ��).�ڶ��ַ���������,�������㲻��.����3����1��ˮ,5����2��ˮ,---
//		    ---5->3,���ʱ3����3��ˮ.������ʱ3->5,��ʱ״̬���5��ˮ��3��ˮ.��ԭ״̬����,����---
//		    
//		    Ҳ������,״̬�ı仯���˻ض���Ҫ��ջ����ʽ�洢.�ǲ���̫�ķѿռ���?
//		    �Ե�,������actlist�������һ������ֵ,��ʾ��ԴͰ����Ŀ��Ͱ��ˮ��.�����Ϳ���ʵ�ַ�������.
//		    struct actinfo{
//				int acttype ;
//				int water ;
//		    }
//			vector<actinfo> actlist;
//
//			�������� : 
//			vector<action>  act;
//			vector<actinfo> actlist;��ʼ��(ѹ��һ��0)
//			vector<container>  Init;����status  ��ʼ״̬
//			int count = 0 ; 
//
//			void  start(&״̬)
//			{
//				for (i����act�е�ÿ������)
//				{
//					if(���������Ժ��Ƿ�״̬�ظ�)  ��������
//					{
//						�������(����,&ˮ��,&״̬);
//						actlist.push_back(����i,ˮ��);
//						if (�ȷֳɹ�)
//						{
//							show actlist,Init(ͬʱ��¼����count,�Ա�������0�����������ʾ);
//							���������(&״̬);(actlist.pop_back(����,ˮ��);����)
//						}
//						else
//						{
//							start(&״̬);
//						}
//					}	
//				}
//				���������(&״̬);(actlist.pop_back(����,ˮ��);����)
//			}
//			
//
//		   �����жϸö����ĺ�����.ֻ���жϵ���(����)�Ƿ�Ϊ��,������(����)�Ƿ�Ϊ��.bool  ???(actcode) ; 
//		   �ж���������Ϊreturn  src.size != 0 && des.size != des.capacity ; 
//
//		   3.�������,1��8->3,����8>3,���ʱ3��������,8������5��ˮ,��(3,3)(5,0)(8,5).2��8->5,��ʱΪ(3,0)(5,5)(8,3)
//		   --��ʱ�������(����) : ���жϴ�����(����)������x��ˮװ��,����(����)��������y��ˮ,����y-x��ֵ--
//		   --���>=0,������������װ��,ʣ��y-x����ֵ���������ڵ���������� ; <0 ,��������Ϊ��,�������������ȱx-y����ֵ--
//		   ��Ҫ��������
//		   һ�Ǵ�����̼򻯺�Ϊ : �Ƚ���Ͱ��ˮ�����(a+c)������������A.����a+c-A ��ֵ.
//		   �� >=0 ,��A����Ϊ��(A,a=A),C������a+c-A��ֵ,ˮ�� = A-a; < 0,��A����Ϊa+c,C����Ϊ��,ˮ�� = c.
//		   �����ж��Ƿ�ȷֳɹ�.������������,�ж�if(size != ��/2 ) { if(size!=0)  return false;}  ����Χreturn true;
//
//	���� : ��Ҫ3��vector���͵ı���,�ֱ���
//		   vector<action>  act;(������ж�������)
//		   vector<actinfo> actlist;��ʼ��(ѹ��һ��0)(��ŵ�ǰ���ж�������)
//		   vector<container>  Init;����status  ��ʼ״̬(��ų�ʼ״̬�͵�ǰ״̬)
//		   ��Ҫ8������.
//		   InitCon();��ʼ��Init��status 
//		   InitAct();��ʼ��act
//		   Start();�ؼ�����,����ִ��
//		   isvalid();�����Ƿ�Ϸ�
//		   Handleact();ִ�ж���
//		   isOK();�ȷ��Ƿ�ɹ�
//		   Show();չʾ���.
//			   printf ��ʼ״̬.
//			   for(i������ǰactlist)
//			   {
//					Handleact(����,&ˮ��,&״̬);
//					printf ����,ˮ��,״̬.
//			   }
//			   printf ��������.
//			   count++ ; 
//		   ReHandle(&״̬);����ִ�в���
//			   tmp = actlist.pop_back();
//			   tmp.����  tmp.ˮ��  ״̬ ; 
//			   ��ѯ(tmp.����)�ҳ�src��des.��״̬�ж�Ӧ��src��+ˮ��,des+ˮ��.����.
//
//	�������� : ��8->3����3��ˮ��,3->5����3��ˮ,5->3���ֵ���3��ˮ.�γ�(3,0)(5,3)(8,5)��(3,3)(5,0)(8,5)��ѭ��.
//			   ���ѭ��������ԭ�����ڶ����ƶ���,�µ�״̬��֮ǰ��״̬���ظ�����.����״̬1->״̬2->״̬3,����ʱ
//			   ״̬3����һ״̬��2,�γ�һ��ѭ��.1->2->3->2->3...
//			   ѭ���γɵ���������(ԭ��)?��δ���ѭ��?
//			   ԭ���Ƕ���(src,des)��ˮ��.�ں����ĸ��������Ч��֮ǰ�Ķ���.��1->a2->b3->c2�Ķ�����Ч���ȼ���1->a2��Ч��.
//			   ����a,b,c����Ч���Ͷ���a��ͬ.��b��c�Ķ�����Ч��Ϊ0.�����Ͻ�,�������actlist�Ƿ����ĳһ�ζ�����Ч��Ϊ0�����.
//			   ����Ϊsrc->desΪ��,des->srcΪ��,�ܹ���3��,�ֱ���3->5,5->3;3->8,8->3;8->5,5->8;
//			   ����3->5����3��ˮΪ+3,5->3����2��ˮΪ-2.��Ӻ�Ϊ+1.
//			   ����һ : �������actlist�Ƿ����ĳһ�ζ�����Ч����3����ֵΪ0�����?
//			   ����������������,��ÿ�����һ������,actlist�����ĩβѭ�������ۼ�.һ������Ϊ0�����,��false,����Ϊ0,����true;
//			   ���Ĵ����ļ���ʱ��.(�жϵĽ������ = �������� = ״̬���ж� ,������������Ҫ��������һ������ֶԴ�.)
//			   ������ : ����һ��ջ�����������������״̬.ÿ���һ������֮ǰ,���жϸö�����������״̬�Ƿ������ж�����.
//			   ���Ŀռ�
//			   ������ : ��һ����ʼ״̬��actlist,���¼��㾭����ÿһ��״̬.�ж��Ƿ���ö������״̬�Ƿ���ͬ,����ͬ�򷵻�false;����ͬ,��true;
//			   ѡȡ������ . ��ô��������������?
//			   CONTAIN  tmpInit��ʼ״̬,tmpcur��ǰ״̬
//			   ������(����,ˮ��,&tmpcur);�õ��������״̬
//			   for (i����actlist,���˵�һ��)
//			   {
//			   		������(i.����,ˮ��,&tmpInit);�õ���һ��״̬
//			   		if(��״̬�Ƿ����)
//			   		{
//						return false ; 
//			   		}                      
//			   }
//			   return true;
//
//
//				��״̬�Ƿ����
//				for(j����״̬)
//		   		{
//					if(tmpInit[j].size !=  tmpcur[j].size)
//					{
//						return false;
//					}
//		   		} 
//				return true;
//
//
// */
//#include <iostream>
//#include <vector>
//
//using namespace std;
////����
//
//class  WaterHalf
//{
//public:
//	struct container{
//		int capacity ; 
//		int size ; 
//	};
//	typedef  vector<container>  CONTAIN ;
//
//	struct action{
//		int src;
//		int des;
//	};
//	typedef  vector<action>  ACTION ;
//
//	struct actinfo{
//		int acttype ; 
//		int water ; 
//    };
//	typedef  vector<actinfo> ACTINFO ;
//
//	void InitAll();
//	void Loop();
//	bool isvalid(int actcode);
//	bool isStatusRep(int actcode); //�ж��Ƿ�����״̬�ظ�
//	bool isequally2(CONTAIN &a,CONTAIN &b); //�ж�����״̬�Ƿ����
//	void Handleact(int actcode,int &water,CONTAIN &tmp );
//	bool isOK();
//	void ShowAll();
//	void ShowContainer(CONTAIN &tmp) ; //��ʾ��ǰ��״̬
//	void ReHandle();
//	void Start(); //��������
//
//private:
//	CONTAIN    	Init,cur ; //Init�洢ԭʼ״̬,cur�洢��ǰ״̬.
//	ACTION     	act ;	//��������
//	ACTINFO    	actlist ; //�洢��ǰ�Ķ�������
//	int 		count ; //���еĿ��ܴ���
//	int 		tatalwater ; //��ˮ��
//};
//
//void WaterHalf::InitAll()
//{
//	//count
//	count = 0 ;
//	tatalwater = 0 ;
//
//	//vector<container>  Init,cur��tatalwater
//	int n = 0 ;
//	int i = 0 ; 
//	printf("������Ͱ������ n : ");
//	scanf("%d",&n);
//	for (; i < n; ++i)
//	{
//		container tmp ; 
//
//		printf("������%d��Ͱ������ : ",i+1);
//
//		scanf("%d",&tmp.capacity);
//
//		printf("������%d��Ͱ�ĵ�ǰˮ�� : ",i+1);
//
//		scanf("%d",&tmp.size);
//
//		tatalwater += tmp.size ; 
//
//		Init.push_back(tmp);
//	}
//
//	cur.assign(Init.begin(),Init.end());
//
//	//vector<action>  act;
//	i = 0 ;
//	for ( ; i < n ; i++)
//	{
//		action tmp ;
//
//		tmp.src = i;
//
//		for (int j = 0 ; j < n ; j++)
//		{
//			if ( i != j )
//			{
//				tmp.des = j ; 
//
//				act.push_back(tmp) ; 
//			}
//		}
//	}
//
//	//vector<actinfo> actlist���һ���ض�ֵ(���pop��)
//	actinfo tmp ; 
//	tmp.acttype = 0 ; 
//	tmp.water = 0 ; 
//	actlist.push_back(tmp) ; 
//	printf("3��ˮͰ��2��ˮ������ĸ�ʽ��(3,2)\n") ; 
//}
//void WaterHalf::Loop()//����Ҫ&״̬,���ﱾ����ṩ��cur.
//{
//	int n = act.size();
//	int water = 0 ; 
//	for (int actcode = 0 ; actcode < n ; actcode++)
//	{
//		if(isvalid(actcode)&&isStatusRep(actcode))
//		{
//			Handleact(actcode,water,cur);
//			
//			actinfo tmp ; 
//
//			tmp . acttype = actcode ; 
//
//			tmp . water = water ; 
//
//			actlist.push_back(tmp) ; 
//
//			if (isOK())
//			{
//				ShowAll();
//				ReHandle();
//			}
//			else
//			{
//				Loop();
//			}
//		}	
//	}
//	ReHandle();
//}
//bool WaterHalf::isvalid(int actcode)
//{
//	return cur[act[actcode].src].size != 0 &&  cur[act[actcode].des].size != cur[act[actcode].des].capacity ; 
//	/*return  src.size != 0 && des.size != des.capacity */; 
//}
//bool WaterHalf::isStatusRep(int actcode)
//{
//	//��ʼ��
//	CONTAIN tmpInit,tmpcur ;
//	int watertmp = 0 ; 
//	int curactcode = 0 ;
//	tmpInit.assign(Init.begin(),Init.end());
//	tmpcur.assign(cur.begin(),cur.end());
//
//	//�õ��������״̬
//	Handleact(actcode,watertmp,tmpcur);
//
//	//�ȸ���ʼ״̬�ж�
//	if (isequally2(tmpInit, tmpcur))
//	{
//		return false ; 
//	}
//
//	ACTINFO::iterator  i = actlist.begin() ; 
//	i++;//���Կ�ͷ���ض�ֵ.
//	for (; i != actlist.end() ; i++)
//	{
//		curactcode = i->acttype ; 
//		//�õ���һ��״̬
//		Handleact(curactcode,watertmp,tmpInit);
//
//		if(isequally2(tmpInit, tmpcur))
//		{
//			return false ; 
//		}
//	}
//	return true ; 
//	
//}
//bool WaterHalf::isequally2(CONTAIN &a,CONTAIN &b)
//{
//	int n = Init.size();
//	for (int i = 0; i < n; ++i)
//	{
//		if (a[i].size != b[i].size)
//		{
//			return false ; 
//		}
//	}
//	return true ;
//}
//void WaterHalf::Handleact(int actcode,int &water,CONTAIN &tmp )
//{
//	int watertotal2 = tmp[act[actcode].src].size + tmp[act[actcode].des].size ; 
//	int dif = watertotal2 - tmp[act[actcode].des].capacity ; 
//	if (dif >= 0 )
//	{
//		water = tmp[act[actcode].des].capacity - tmp[act[actcode].des].size ; 
//		tmp[act[actcode].des].size = tmp[act[actcode].des].capacity ;  
//		tmp[act[actcode].src].size = dif ;
//	}
//	else
//	{
//		water = tmp[act[actcode].src].size ; 
//		tmp[act[actcode].des].size = watertotal2 ;  
//		tmp[act[actcode].src].size = 0 ;
//	}
//}
//bool WaterHalf::isOK()
//{
//	for (CONTAIN::iterator  i = cur.begin(); i != cur.end() ; i++)
//	{
//		if (i->size != tatalwater/2)
//		{
//			if ( i->size != 0 )
//			{
//				return false ;
//			}
//		}
//	}
//	return true ;
//}
//void WaterHalf::ShowAll()
//{
//	CONTAIN tmp ; 
//
//	tmp.assign(Init.begin(),Init.end());
//
//	int  actcode = 0 ;
//	int  water = 0 ;
//	count ++ ;
//
//	printf("��%d�������\n",count) ; 
//	printf("��ʼ״̬��\n") ; 
//
//	ShowContainer(tmp) ; 
//
//	ACTINFO::iterator  i = actlist.begin() ; 
//	i++;//���Կ�ͷ���ض�ֵ.
//	for (; i != actlist.end() ; i++)
//	{
//		actcode = i->acttype ; 
//
//		Handleact(actcode,water,tmp);
//
//		printf("%d��Ͱ��%d��Ͱ�е���%d��ˮ\n",tmp[act[actcode].src].capacity,tmp[act[actcode].des].capacity,water) ; 
//
//		printf("��ǰ״̬��") ; 
//
//		ShowContainer(tmp) ; 
//	}
//	printf("%d���������\n\n",count) ; 
//
//}
//void WaterHalf::ShowContainer(CONTAIN &tmp)
//{
//	for (CONTAIN::iterator i = tmp.begin(); i != tmp.end() ; ++i)
//	{
//		printf("(%d,%d) ",i->capacity,i->size) ; 
//	}
//	printf("\n\n") ; 
//}
//
//void WaterHalf::ReHandle()
//{
//	actinfo tmp = actlist[actlist.size()-1];
//
//	actlist.pop_back(); 
//
//	int actcode = tmp.acttype ; 
//	int water =  tmp.water ; 
//	cur[act[actcode].src].size += water ; 
//	cur[act[actcode].des].size -= water ; 
//}
//
//void WaterHalf::Start()
//{
//	InitAll() ; 
//
//	Loop() ; 
//
//	if (count == 0)
//	{
//		printf("������2�ȷֵ����\n") ; 
//	}
//
//}
//
////����
////int main(int argc, char const *argv[])
////{
////	WaterHalf test;
////	test.Start();
////	system("pause");
////	return 0;
////}
