#include <iostream>
using namespace std;

int main(){

    int arr[6]={1,2,3,3,4,5};

    int xarr=0;
    int xn=0;

    for(int i=0;i<6;i++){
            
        xarr=xarr^arr[i];        
    }
    
    for(int i=1;i<=5;i++){
            
        xn=xn^i;        
    }
    int ans=xarr^xn;
    cout<<"Dublicate element was: "<<ans<<endl;

}

