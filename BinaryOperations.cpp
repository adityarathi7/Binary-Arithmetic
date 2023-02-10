#include <bits/stdc++.h>
using namespace std ;


vector<int> int_to_binary(int num)
{
    vector<int> ans(32) ;
    int i=0 ;
    if(num < 0) 
    {
        cout << "todo" ;
    }else {
        while(num)
        {
            ans[i++] = num%2 ;
            num /= 2 ; 
        }
        reverse(ans.begin(),ans.end()) ;
    }


    return ans ;
}

int main() {

    int a,b ;
    cin >> a>>b ;

    vector<int> num1 = int_to_binary(a) , num2 = int_to_binary(b) ;

    return 0;
}

