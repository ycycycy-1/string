#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define maxn 1005
struct My_Hash
{
    ull base=9959;
    ull p[maxn],ha[maxn];//p[i]=base^i 
    void Insert(char s[])
    {
        int len=strlen(s+1);
        p[0]=1,ha[0]=0;
        for(int i=1;i<=len;i++)
        {
            p[i]=p[i-1]*base;
            ha[i]=ha[i-1]*base+(ull)s[i];
        }
    }
    ull gethash(int l,int r)
    {
        return (ull)ha[r]-ha[l-1]*p[r-l+1];
    }
}S;
//ha[i]=ha(1,i)=s[1]*base^(i-1) + s[2]*base^(i-2)....+s[i]

//ha(i,j)=s[i]*base^(j-i)+s[i+1]*base(j-i-1)...+s[j]

//[i,k-1] [k,j]hash区间合并:ha(i,j)=hash(i,k-1)*base^(j-k+1)+hash(k,j)

//[1,i-1] [i,j]hash区间合并:ha[j]=ha(1,j)=hash[i-1]*(j-i+1)+hash(i,j) 
//移项得到hash(i,j)=ha[j]-ha[i-1]*(j-i+1)
int main()
{
    char s[maxn];
    cin>>s+1;
    S.Insert(s);
    int T;
    cin>>T;
    while(T--)
    {
        int l,r;
        cin>>l>>r;
        cout<<S.gethash(l,r)<<endl;
    }
    return 0;
}
