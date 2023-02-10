#include<bits/stdc++.h>
using namespace std;

vector<int> add_binary(vector<int> a, vector<int> b)
{
    int n = a.size();
    vector<int> result(n, 0);

    int carry = 0;
    for(int i=n-1;i>=0;i--)
    {
        if(carry==0)
        {
            result[i] = a[i]^b[i];
            if(result[i]==0 and i!=0 and a[i]==1) carry = 1;
        }
        else
        {
            result[i] = a[i]^b[i]^1;
            if(a[i]==1 and i!=0) carry = 1;
            else carry = 0;
        }
    }

    return result;
}


int binary_to_int(vector<int> a)
{
    int ans = 0;

    for(int i=a.size()-1;i>0;i--)
    {
        ans = ans*2 + a[i];
    }

    return ans;

}
vector<int> two_complement(vector<int> a)
{
    for(int i =0;i<a.size();i++)
    {
        a[i] = a[i]^1;
    }
    vector<int> mask(a.size(),0);
    mask[a.size()-1] = 1;
    vector<int> ans = add_binary(a,mask);

    return ans;

}
vector<int> substract_binary(vector<int> a, vector<int> b)
{
    vector<int> b_new = two_complement(b);
    return add_binary(a,b_new);
}


vector<int> undo_complement(vector<int> a)
{   vector<int> b(a.size(),0);
    a[0] = 0;
    for(int i =0;i<a.size();i++)
    {
            b[i] = a[i]^1;
    }
    return b;
}

vector<int> multiply_binary(vector<int> a, vector<int>b)
{
    vector<int> anew,bnew;
    if(a[0]==1 and b[0]==1)
    {   
             anew = undo_complement(a);
             bnew = undo_complement(b);

    }
    else if(a[0]==1){
            anew = undo_complement(a);

    }
    else if(b[0]==1)
    {
        bnew = undo_complement(b);
    }

    int n = binary_to_int(bnew);
    cout<<n;
    vector<int> result(3,0);
    for(int i =0;i<n;i++)
    {   
        result = add_binary(result,anew);

    }
}

int main()
{
    vector<int> a {0,1,0};
    vector<int> b {0,0,0};
    vector<int> result = multiply_binary(a,b);

    for(int i =0;i<3;i++)
    {
        cout<<result[i]<<" ";
    } 
    cout<<endl;
}

