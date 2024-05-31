/*
Unbounded knapsack with unlimited supply.
Need to find the max profit that can be obtained, while forming the weight W.
i/p => wt[],val[],W,N
o/p => maxProfit
There are two states in this kind of questions (index and targetWeight).
base case will be, if w==0, or n<0.
*/

#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int n, int w, vector<int>& wt, vector<int>& val){
    //base cases
    //agar wt==0 ho jaye, mtlb agr knapsack mai bharne ke liye jagah na ho
    if(wt==0) return 0;
    //agar n<0 ho jae, mtlb ki n jo hai woh apne last iteration pe ho
    if(n<0) return 0;
    //ek case aur ho skta hai ki, knapsack ka weight element ke weight se km ho jae,us case mai just 
    //iterate away from that element
    if(wt[index]>w) return unboundedKnapsack(n+1,w,wt,val);
    //knapsack mai ya toh element ko add krege ya toh nhi krege, so we have 2 choices
    //pick, curr weight to push krna hai
    int pick = val[index]+unboundedKnapsack(n,w-wt[index],wt,val);
    //notPick, curr ko push nhi krna hai
    int notPick = unboundedKnapsack(n+1,w,wt,val);

    return max(pick,notPick);
}

int main(){
    int n; cin>>n;
    vector<int>wt(n);
    for(int i=0; i<n; i++){
        cin>>wt[i];
    }
    int w; cin>>w;
    vector<int>val(n);
    for(int i=0; i<n; i++){
        cin>>val[i];
    }
    cout<<unboundedKnapsack(n,w,wt,val);
}