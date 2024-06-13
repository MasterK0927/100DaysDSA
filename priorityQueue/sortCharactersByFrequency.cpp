#include <bits/stdc++.h>
using namespace std;

typedef pair<char,int> p;
struct lambda {
    bool operator()(p&p1,p&p2){
        return p1.second<p2.second;
    }
};

priority_queue<p,vector<p>,lambda> pq;
string frequencySort(string& s){
    map<char,int>mpp;
    for(auto& it:s){
        mpp[it]++;
    }
    for(auto& ch:mpp){
        pq.push({ch.first,ch.second});
    }
    string result = "";
    while(!pq.empty()){
        p temp = pq.top();
        pq.pop();
        result+=string(temp.second,temp.first);
    }
    return result;
}

int main(){
    string s = "jcccjsscsd";
    cout<<frequencySort(s);
    return 0;
}