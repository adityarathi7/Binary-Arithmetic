#include <bits/stdc++.h>
using namespace std ;

int main() {

    int c = 0 , t , num;
    cin >> num ;

    if(num == 0) 
    {
        cout << "sorry" << endl;
        return 0 ;
    }

    while(cin >> t)
    {
        c = c*2 + t ;
        cout << (c%num == 0  ? "Divisible" : "Not Divisible"  )  << endl ;
        c %= num ;
    }


    return 0;
}

