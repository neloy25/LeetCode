#include<stdio.h>
#include<limits.h>

int maxProfit(int* prices, int pricesSize) {
    int max = 0;
   for (int i = 0; i < pricesSize - 1; i++) {
       for(int j = i + 1; j < pricesSize;j++){
            int profit = prices[j] - prices[i];
            if(profit > max) max = profit;
       }
   }
   return max;
}

int main() {
    int prices[] = {7,6,4,3,1};
    int res = maxProfit(prices,5);
    printf("%d", res);
    return 0;
}