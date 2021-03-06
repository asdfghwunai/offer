/*
 牛牛得知了一些股票今天买入的价格和明天卖出的价格，他找犇犇老师借了一笔钱，现在他想知道他最多能赚多少钱。
输入描述:

每个输入包含一个测试用例。
输入的第一行包括两个正整数,表示股票的种数N(1<=N<=1000)和牛牛借的钱数M(1<=M<=1000)。
接下来N行，每行包含两个正整数，表示这只股票每一股的买入价X(1<=X<=1000)和卖出价Y(1<=Y<=2000)。
每只股票可以买入多股，但必须是整数。



输出描述:

输出一个整数表示牛牛最多能赚的钱数。


输入例子1:

3 5 
3 6 
2 3 
1 1


输出例子1:

4


*/

/*
01背包，数量只有1个
完全背包问题，数量可以无限
多重背包，数量有限

股票买入价当容量，卖出价当价值。
dp是记录价值的
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int dp[1005];         //记录背包装入的最大容量，包含升值的
int c[1005][2];     //股票情况，一方是容量，一方是价值

int max(int a,int b)
{
	return a > b?a:b;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);					//n是股票种类，m是总重量
	for (int i = 1; i <= m; i++)   //感觉很理所当然啊，就只当背包只能装一种容量，价值当没升，所以是i
		dp[i] = i;             //都初始化为0也没事
	for (int i = 1; i <= n; i++)    //n是种类，遍历股票容量用的
  {        
		scanf("%d%d", &c[i][0], &c[i][1]);    //买入卖出价
		for (int j = c[i][0]; j <= m; j++)               //一点一点更新
			dp[j] = max(dp[j], dp[j - c[i][0]] + c[i][1]);   //升值了  注意dp[0]好像是0啊
	}
	printf("%d\n", dp[m] - m);
	return 0;
}
