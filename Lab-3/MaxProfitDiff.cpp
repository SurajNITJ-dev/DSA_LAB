#include <iostream>
using namespace std;

int main(){
    int arr[8]={1,2,3,5,7,9,2,5};
    int maxProfit=0;
    int lstBuy=arr[0];
    for(int i=1;i<8;i++){

        if(arr[i]>lstBuy){
            int profit=arr[i]-lstBuy;
            if(maxProfit<profit){
                maxProfit=profit;
            }
        }
        else{
            if(arr[i]<lstBuy){
                lstBuy=arr[i];
            }
        }
    }

    cout<<"Max Profit is "<<maxProfit<<endl;
}