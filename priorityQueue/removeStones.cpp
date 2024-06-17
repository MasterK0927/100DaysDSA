#include <bits/stdc++.h>
using namespace std;

int minSum(vector<int>& stones, int sum, int n, int k){
    //need to figure out, which stone to perform stones[i]/2 operation
    //most brute approach can be sorting the array and then performing the operation out there in the last element, and then again sorting and doing operation on last again and return;
    //but we can have more optimal approach by using the data structure like priority queue, which re arranges itself in a fix order in logn;
    //initialising the maxHeap
    priority_queue<int>maxHeap;
    //take out the element from the top of the heap and do the operation on it and subtract it from the sum;
    for(int i=0; i<n; i++){
        maxHeap.push(stones[i]);
    }
    while (k>0){
        int maxNum = maxHeap.top();
        maxHeap.pop();
        int operatedNum = maxNum/2;
        maxHeap.push(operatedNum);
        k--;
    }
    int minSum=0;
    while(!maxHeap.empty()){
        minSum+=maxHeap.top();
        maxHeap.pop();
    }
    return minSum;

}

int main(){
    //in the input we will get the stones, and have to give back the minimum possible sum doing 1 operation on k stones
    vector<int> stones = {5,4,9};
    int sum = 0;
    int count = stones.size();
    int numOfOperations = 2;
    for(auto& it:stones){
        sum+=it;
    }
    cout<<minSum(stones,sum,count,numOfOperations);
    return 0;
}