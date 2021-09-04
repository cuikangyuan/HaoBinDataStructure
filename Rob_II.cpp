#include <stdio.h>
#include <mm_malloc.h>
#include <stdlib.h>


int dp(int* nums, int start, int end, int* memo);
void fillArray(int* nums, int numsSize, int val);
int max(int i, int j);

int main(void) {


    return 0;
}

//https://leetcode-cn.com/problems/house-robber-ii/

int rob(int* nums, int numsSize)
{

    //notice
    if(numsSize == 1) {
        return nums[0];
    }

    int memo[numsSize];

    fillArray(memo, numsSize, -1);
    int includeFirst = dp(nums, 0, numsSize-2, memo);
    
    fillArray(memo, numsSize, -1);
    int includeLast = dp(nums, 1, numsSize-1, memo);

    return max(includeFirst, includeLast);

}

int max(int i, int j) 
{
    if(i > j) 
    {
        return i;
    } 
    else 
    {
        return j;
    }
}


void fillArray(int* nums, int numsSize, int val) 
{
    for(int i = 0; i < numsSize; i++) 
    {
        nums[i] = val;
    }
}

int dp(int* nums, int start, int end, int* memo) 
{

    if(start > end) 
    {
        return 0;
    }

    int result = 0;
    if(memo[start] != -1) 
    {
        result = memo[start];
    } 
    else
    {
        int robIt = dp(nums, start + 2, end, memo) + nums[start];
        int notRobIt = dp(nums, start + 1, end, memo);
        result = max(robIt, notRobIt);
        memo[start] = result;
    }

    return result;

}

