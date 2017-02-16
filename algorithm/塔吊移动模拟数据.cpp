/**
 * -*- coding : GBK -*-
 * @Author : huangshengjianng
 * @Email : 1005542693@qq.com
 * @Date : 2016-09-14  15:46
 * @Last Modified Date :  2016-09-18 15:44       
 * @FileName : �����ƶ�ģ������.cpp
 */

/*�����ƶ�ģ������
	Ŀ��  :  �ܹ�ģ�������ϵͳ��ÿ�ι��������ʵʱ����
	Ҫ�� : ֻ��Ҫ�����ʼ��ַ��Ŀ���ַ,�����Զ�����(����״̬��).
	��ѧģ�� : ��ַ�ö�ά����(W,R)��ʾ,��ʼλ����Ϊ(W_src,R_src),Ŀ���ַ��Ϊ(W_des,R_des).
			   w��ʾ�Ƕ�(�붫�������γɵĽǶ�),��Χ��(0~360),��ȷ��С������λ,
			   r��ʾ����(����������֧�����ֱ�߾���),��Χ��(0~��۳�����ΪArm_Length),��ȷ�ȵ�С����1λ.
			   
			   ʵʱ����(����,����,����,����,�߶�,�Ƕ�)��(RT_torque,RT_load,RT_wind,RT_range,RT_height,RT_angle),����
			   RT_load����ÿ�ι���״̬���Ǻ㶨��.
			   RT_torque��RT_load��RT_range��0.001,���������غͷ��ȳ�����,
			   RT_wind����Ϊ�������Ա���.
			   RT_range,RT_height,RT_angle.�߶�/�Ƕ�/���ȶ��ǿ����𲽱仯��,һ����˵,�߶��ȱ仯,�������ǽǶȻ��߷��ȱ仯(��ѡ).
			   ���и߶��ֿɼٶ�Ϊһ���㶨ֵ,ֻҪ����������߶�֮�ϾͿ��԰�ȫ����.
			   �������� : ��Ҫ�ı�����������.����,�߶���,��Ҫ����,����/�Ƕ�.���������趨Ϊ0~5֮��,���Ƿ���/�Ƕ�.
	�������� : ���˵����ĵĿ��ټ�෽��?�Լ���ά�����ѡ��?

 */

#include <iostream>
#include <time.h>
using namespace std;

#define Arm_Length  33  //����۳�33��,�����15��.
#define Height_Limit  10	//�߶���λΪ10��

float angle_cur = 0.0;
float angle_des = 0.0;
float range_cur = 0.0;
float range_des = 0.0;
int   RT_load   = 0;	
float RT_height = 0.0;

//����,���ڲ�������,�Ƕ�,�߶�
void  RT_Data_Produce(float &RT_range,float &RT_angle ,float &RT_height){
	if((RT_angle != angle_des || RT_range != range_des) && RT_height < Height_Limit )
	{
		RT_height += 0.5+(rand()%11)/10.0;//0.5~1.5
		return ;
	}
	if(RT_angle == angle_des && RT_range == range_des && RT_height > 0.0 )
	{
		RT_height -= 0.5+(rand()%11)/10.0;
		if (RT_height < 0.0)
		{
			RT_height = 0.0;
		}
		return ;
	}
	//����,�߶�
	if (RT_range == range_des){
		if (RT_angle == angle_des)return;
		if (RT_angle < angle_des)
		{
			RT_angle += 9.00 + (rand()%201)/100.0;//9.00~11.00
			if (RT_angle > angle_des)
			{
				RT_angle = angle_des ;
			}
			return;
		}
		if (RT_angle > angle_des)
		{
			RT_angle -= 9.00 + (rand()%201)/100.0;
			if (RT_angle < angle_des)
			{
				RT_angle = angle_des ;
			}
			return;
		}
	}

	if (RT_range > range_des)
	{
		RT_range -= 0.5+(rand()%11)/10.0;
		if (RT_range < range_des)
		{
			RT_range = range_des;
		}
		return;
	}
	if (RT_range < range_des)
	{
		RT_range += 0.5+(rand()%11)/10.0;
		if (RT_range > range_des)
		{
			RT_range = range_des;
		}
		return;
	}
}




//����
/*int main(int argc, char const *argv[])
{
	int n=500;
	while (n)
{
	//�����������(range_src,angle_src),(range_des,angle_des)
		srand(time(NULL));
		if (angle_cur == angle_des && range_cur == range_des && RT_height == 0.0)
		{
			angle_cur=rand()%360 + (rand()%101)/100.0;
			angle_des=rand()%360 + (rand()%101)/100.0;
			range_cur=rand()%Arm_Length + (rand()%11)/10.0;
			range_des=rand()%Arm_Length + (rand()%11)/10.0;
			RT_load  =rand()%1000+4000;	//(4000~5000)
			cout<< "��ʼ����:"<<range_cur<<" "<< "��ʼ�Ƕ�:"<<angle_cur<<" "<< "Ŀ�����:"<<range_des<<" "<< "Ŀ��Ƕ�:"<<angle_des<<" "<<endl;
		}
	
		//׼������
		float RT_torque;
		float RT_wind;
	
		//������ǰ���ȺͽǶ�,���߶�
		RT_Data_Produce(range_cur, angle_cur ,RT_height);
	
		//���غͷ���
		RT_torque = RT_load * range_cur * 0.001 ;
		RT_wind   = rand()%5 + (rand()%11)/10.0;
	
	//����,����,����,����,�߶�,�Ƕ�
		cout<<"����:"<<RT_torque<<" "<<"����:"<<RT_load<<" "<<"����:"<<RT_wind<<" "<<"����:"<<range_cur<<" "<<"�߶�:"<<RT_height<<" "<<"�Ƕ�:"<<angle_cur<<endl;

		time_t t=time(NULL);
		while(t ==time(NULL));
}
	system( "pause");
	return 0;
}*/