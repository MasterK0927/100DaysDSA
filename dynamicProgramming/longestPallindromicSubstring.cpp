/*
We have to find the longest Substring in the string which is also a pallindrome.
So we will be requiring 3 arguements, with 2 being the pointers to the first and last index of string.
Approach would be like, one pointer at beginning and one at last, and enclosing will be the string itself.
Then we will pass that string through a isPallindromeHelper, that specifically returns true || false.
If true we will store it in the ans string, and passes a max function which will update the result value based on length.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string s){
    int i=0; int h=s.length()-1;
    while(l<=h){
        if(s[l]!=s[h]){
            return false;
        }
        l++,h--;
    }
    return true;
}

string lps(const string& s, int l, int h, vector<vector<int>>& dp){
    //edge cases
    //if we empty string;
    if(l>h) return "";
    //base case
    //if there is only the unit string, then it is itself the longest pallindrome;
    if(dp[l][h]!=-1 && l==h) return s.substr(l,1);
    //recurrence
    //storing the result for later comparison;
    string result = "";
    //extracting the substr from l to h;
    string sub=s.substr(l,h);
    //checking whether the substring is pallindrome or not, using helper; If its true, return that substring;
    if(isPallindrome(sub)){
        return sub;
    }
    //if the above condition doesn't holds true, we traverse string from back and front respectively;
    string subBack = lps(s,l,h-1);
    string subFront = lps(s,l+1,h);
    //We know that subBack and subFront will return pallindrome strings, so based on their lengths return the largest;
    return subBack.length()>=subFront.length() ? subBack :subFront;
}

int main(){
    string s;
    cin>>s;
    //we have 2 states here, namely the indexes, so using 2d dp
    vector<vector<int> > dp(s.length(),vector<int>(s.length()+1,-1));
    string ans = lps(s,0,s.length()-1),dp;
    cout<<ans;
}