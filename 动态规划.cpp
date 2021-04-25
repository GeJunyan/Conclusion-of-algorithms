/*
1.动态规划一般脱离了递归　而是由迭代循环完成计算
  从问题规模最小的f(1)和f(2)开始往上推，直到推到我们想要的答案f(多少)，这就是动态规划的思路．
 
2.动态规划问题最困难的就是写出状态转移方程，即这个暴力解。优化方法无非是用备忘录或者 dp table

3. 最优子结构
eg.
给你k种面值的硬币，面值分别为c1, c2 ... ck，每种硬币的数量无限，再给一个总金额amount，
问你最少需要几枚硬币凑出这个金额，如果不可能凑出，算法返回 -1 。
*/

int coinChange(vector<int>& coins, int amount) {

  //1.创建dp数组
  vector<int> dp(amount + 1, amount + 1);
  
  dp[0] = 0; //表示0元的时候　0个硬币就能做到
  
  for(int i = 1; i < dp.size(); i++)
  {
    for(int coin : coins)
    {
      if(i - coin < 0) continue;
      dp[i] = min(dp[i], 1 + dp[i-coin]);
    }
  }
  return (dp[amount] == amount + 1) ? -1 : dp[amount];

}
