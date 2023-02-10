#include<bits/stdc++.h>
using namespace std;

vector<int> add_binary(vector<int> a, vector<int> b)
{
    int n = 32;
    vector<int> result(n, 0);

    int carry = 0;
    for(int i=2;i>=0;i--)
    {
        if(carry==0)
        {
            result[i] = a[i]^b[i];
            if(result[i]==0 and i!=0) carry = 1;
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
