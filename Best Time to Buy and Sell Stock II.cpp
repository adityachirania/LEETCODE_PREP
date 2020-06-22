// Say you have an array prices for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

// Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int arr[n];
        arr[0] = 0;
        
        // storing consecutive differences
        int ans = 0;// Say you have an array prices for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

// Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int arr[n];
        arr[0] = 0;
        
        // storing consecutive differences
        int ans = 0;
        // add up only discrete profits
        for(int i = 1;i < n;i++ )
        {
            arr[i] = prices[i] - prices[i-1];
            if(arr[i]>0)ans+=arr[i];
        }
        
        return ans;
        
    }
};
