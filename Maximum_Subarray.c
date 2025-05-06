#include<stdio.h>
#include<limits.h>

int maxSubArray(int* nums, int numsSize) {
    int sum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        sum+=nums[i];
        if(sum > maxSum) maxSum = sum;
        if(sum < 0) sum = 0;
    }
    return maxSum;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d", maxSubArray(arr,n));
    return 0;
}