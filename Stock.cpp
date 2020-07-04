//#include<iostream>
//using namespace std;
//#include<vector>
////题目要求：
///*
//	给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//	
//	如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
//	
//	注意：你不能在买入股票前卖出股票。
//	
//	 
//	
//	示例 1:
//	
//	输入: [7,1,5,3,6,4]
//	输出: 5
//	解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//	     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
//	示例 2:
//	
//	输入: [7,6,4,3,1]
//	输出: 0
//	解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
//	
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//*/
//
//
//
//
//
////1、暴力求解法，直接两层循环，算出每一个价格之间的差值，也就是1-1，2-1.3-1，……，n-1，……，n-n，这样找出最大差值，然后将这个最大差值返回
//class Solution1 {
//public:
//    int maxProfit(vector<int>& prices) {
//        
//        int maxprofit = 0;
//        for (vector<int>::iterator iter = prices.begin(); iter != prices.end(); iter++)
//            for (vector<int>::iterator it = iter; it != prices.end(); it++)
//            {
//                int n = *it - *iter;
//                if (n > maxprofit)
//                    maxprofit = n;
//            }
//
//        return maxprofit;
//    }
//};
//
//
//
////2、动态规划法，只需要遍历一次数组就可以实现找出最大利润来，这里要想清楚，minprice的位置是随着数组的遍历而调整的，这样就会找到区间利润了，再将区间利润进行保存，然后后面再进行求解区间利润，然后和之前的利润进行比较，如果后面又更大的区间利润，那么就再次更新最大区间利润
//class Solution
//{
//public:
//	int MaxProfit(vector<int>& prices)
//	{
//		if (prices.size() <= 1)
//			return 0;
//		int minprice = prices[0];
//		int maxprofit = 0;
//		for (int price : prices)
//		{
//			if (price - minprice > maxprofit)
//				maxprofit = price - minprice;
//			if (price < minprice)
//				minprice = price;
//		}
//		return maxprofit;
//	}
//};
//
//int main()
//{
//	Solution1 s;
//	vector<int> prices = { 1,2,5,263,6,3 };
//	cout<<s.maxProfit(prices)<<endl;
//	cin.get();
//	return 0;
//	
//}