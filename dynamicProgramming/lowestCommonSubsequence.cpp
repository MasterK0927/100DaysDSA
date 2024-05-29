#include <bits/stdc++.h>
using namespace std;

int lcs(string& s1, string& s2, int index1, int index2){
    //agar strings iterate ho chuki ho;
    if(index1>=s1.length() || index2>=s2.length()) return 0;
    //agar subsequence mil jaye toh return kr do uska count aur strings ko ek ek index ghata do
    if(s1[index1]==s2[index2]) return (1+lcs(s1,s2,index1+1,index2+1));
    //when the common subsequence is not found, iterate both strings -1 times keeping one fixed
    return max(lcs(s1,s2,index1+1,index2),lcs(s1,s2,index1,index2+1));
}

int main(){
    string s1;
    cin>>s1;
    int l1 = s1.length();
    string s2;
    cin>>s2;
    int l2 = s2.length();

    int s = lcs(s1,s2,0,0);
    cout<<s;    
}