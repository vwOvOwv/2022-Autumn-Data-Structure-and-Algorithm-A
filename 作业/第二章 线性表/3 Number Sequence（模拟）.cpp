#include <iostream>
#include <cmath>
using namespace std;
int n;
long long len[40000];//记录第i个串的长度
long long pos[40000];//记录第i个串开始位置的下标
int large[1200000];//记录最长的串
int main()
{
	len[1]=pos[1]=1;
	for(int i=2;i<40000;i++)
	{
		len[i]=len[i-1]+(int)log10(i*1.0)+1;/*(int)log10(i*1.0)+1
		是求串 1 12 123 ....112...9.10.11....后序列比前序列多出的数
		的位数,超过10以后会多一位或者更多,所以用log10()求解*/ 
		pos[i]=pos[i-1]+len[i-1];
	}
	int  cnt=1;
	for(int i=1;i<40000;i++)//找到40000的目的是 找到最大序列（上文的串） 
	{
		int bit[100];
		int k=i,num=0;
		while(k)/*将k取余放入数组bit中，但此时序列表示数的所在的位置
		是反着的，故用large转置回来 */ 
		{
			bit[num++]=k%10;
			k/=10;
		}
		while(num--)
		{
			large[cnt++]=bit[num];
		}
	 }
	 int t;
	 cin>>t;
	 while(t--)
	 {
	 	cin>>n;
	 	int i;
	 	for(i=1;i<40000;i++)
	 	{
	 		if(pos[i]>=n)//找到所求第n个数在第几个序列里 
	 		break; 
		 }
		 if(pos[i]==n)//如果那个数刚好是序列开头的第一位数输出1 
		 cout<<1<<endl;
		 else
		 cout<<large[n-pos[i-1]+1]<<endl;//否则输出的数从large中找 
	  } 
	  return 0;
 } 
