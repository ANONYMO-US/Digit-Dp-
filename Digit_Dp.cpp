#include <bits/stdc++.h>
#define lli unsigned long long int 

using namespace std;
vector<int>v;
lli dp[5][19];

void fun(lli n)
{
    v.clear();
    stack<int>s;
    while(n>0)
    {
        s.push(n%10);
        n=n/10;
    }
    while(s.size()>0)
    {
        v.push_back(s.top());
        s.pop();
    }
    return;
}

bool prim(int i)
{
    if(i==2||i==3||i==5||i==7)return true;
    else return false;
}

lli digit(lli idx,lli nop,vector<bool>c)
{
    lli ret=0;
    for(int i=0;i<v[idx];i++)
    {
        if(prim(i)&&c[i]==false)ret+=dp[nop-1][v.size()-idx-1];
        else ret+=dp[nop][v.size()-idx-1];
    }
    if(idx<v.size()-1)
    {
    if(prim(v[idx])&&c[v[idx]]==false)
    {
        c[v[idx]]=true;
        ret+=digit(idx+1,nop-1,c);
    }
    else
    {
        ret+=digit(idx+1,nop,c);
    }
    }
    return ret;
}



int main() {
    int t;
    cin>>t;
    while(t--)
    {
        lli l,r;
        cin>>l>>r;
    
        for(int i=0;i<5;i++)for(int j=0;j<19;j++)dp[i][j]=0;
        dp[0][0]=1;
        for(int i=1;i<5;i++)dp[i][0]=0;
        for(int i=1;i<=18;i++)dp[0][i]=pow(10,i);
        for(int i=1;i<5;i++)
        {
            for(int j=1;j<19;j++)
            {
                dp[i][j]=(10-i)*dp[i][j-1]+i*dp[i-1][j-1];
            }
        }
        fun(l);
        vector<bool>c;
        for(int i=0;i<10;i++)c.push_back(false);
        lli a= digit(0,4,c);
        fun(r);
        for(int i=0;i<10;i++)c[i]=false;
        lli b=digit(0,4,c);
        cout<<b-a<<endl;
    }
    
    
}