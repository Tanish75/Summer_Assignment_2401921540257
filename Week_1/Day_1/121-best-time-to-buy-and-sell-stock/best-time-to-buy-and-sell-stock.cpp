class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprice=0;
        int minprice=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minprice){
                minprice=prices[i];//buy kro idhar 
            }
            else{
                int profit=prices[i]-minprice;
                maxprice=max(maxprice,profit);
            }
        }
        return maxprice;
    }
};