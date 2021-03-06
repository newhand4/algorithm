///**
// * -*- coding : GBK -*-
// * @Author : huangshengjiang
// * @Email : 1005542693@qq.com
// * @Date : 2016-11-29 11:15
// * @Last Modified Date :     
// * @FileName : 特定字符串解析.cpp
// */
//
///*特定字符串解析
//	基本概念 : 将特定字符串解析出所需的信息集合.
//	应用场景 : 类似于词法分析,语法分析,语义分析的过程,在这里只是简单的涉及应用.
//	局限性 : 只能针对特定的字符串,对于其他字符串则无效.
//	具体需求 : 将特定字符串解析出所需的信息集合.
//		输入 : 特定字符串(如 int a_tmp not null )表示一个形参的类型,名称,约束条件.不同形参之间用逗号分开.
//			   and (a_tmp >=2 && a_tmp <=5000)? a_tmp : 0 //表示a_tmp的范围,如果超出则为0.
//			   and a_tmp & 0x00000800 //表示只保留第12位(从后往前数)
//		       这些约束条件是可以同时的."与的关系".
//		输出 : 解析出信息集合(集合定义下面有介绍)
//
//	分析 : 可以把字符串当作许多单词组成.每个单词之间用空格分隔.又由于不同形参之间用逗号分开,因此当扫描每次遇到逗号","时,可以将
//		   该字符串作为一个形参的属性进行分析.一般而言,第一个单词是类型,第二个单词是形参名字(也可以没有),而后的都是约束条件.
//		   不同约束条件是用and隔开,因次碰到"and"字段时,需要对前面扫描到的约束条件进行相应的处理.
//		   (关键难点就是约束条件的处理以及存储方式)
//		   首先,第一个单词是类型这是必须的.
//		   第二个单词是形参名字可有可无,这里需要处理.
//		   (准确的说是约束条件只有非零的情况下才第二个形参才可有可无,因此统一的处理方法是必须给形参名称)
//		   而后为约束条件,and分隔不同约束条件,约束条件的特性是可以相与 : 有非零,范围,屏蔽,恒为0的4种情况
//		   其中非零有两种状态,true,false.
//		   范围一般情况是在某个范围内,而不是范围外,一般形式为 name >= 2 && name <= 5000 .超出这个范围则输出0.
//
//		   屏蔽有两种,|或& 0x00000800. 
//		   还有直接赋值为0的情况.
//			
//		时间复杂度 : 
//		空间复杂度 : 
//		简化 : 
//
//	解决方案1 : 
//		优缺点 :
//		
//	解决方案2 : 
//		优缺点 : 
//
//	引申问题 : 
//
//	方案对比 : 
//
//	结论 : 
//
// */
//#include <iostream>
//#include <map>
//#include <vector>
//using namespace std;
//
////信息集合定义如下 : 
//typedef struct CONSTRAINT
//{
//
//
//}Constraint;
//
//typedef struct PARAM
//{
//	string Param_name; //形参名
//	string Param_type; //形参类型
//	Constraint   Isnotnull ; //约束条件,有3种 1非零 2.屏蔽 3.范围.可以相与.,true表示有非零的约束,false表示没有非零约束
//}Param;
//
//typedef struct PROINFO//每个函数的必要信息
//{
//	string			Funcname ;			//函数名称
//	vector<Param>  InputParam  ;		//输入形参
//	vector<Param>  OutputParam ;	    //输出形参
//}ProInfo;
//
//typedef map<string,ProInfo>  MAPPRODURE;//string 表示存储过程名称
//
//
////函数
//
////测试
///*int main(int argc, char const *argv[])
//{
//	system("pause");
//	return 0;
//}*/
