// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
       
//         int n=nums.size();
//         vector<int>ans;
//         ans.resize(n);

//         int evn=0;
//         int odd=1;
//         for(int i=0;i<n;i++){
//             if(nums[i]>0){
//                 ans[evn]=nums[i];
//                 evn+=2;
//             }
//             else{
//                 ans[odd]=nums[i];
//                 odd+=2;
//             }
//         }

//         return ans;
//     }
// };

// //Q2

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums,int target) {
        int n=nums.size();
        int m=1<<n;

        vector<vector<int>>v;

        for(int i=0;i<m;i++){
            vector<int>tmp;
            for(int j=0;j<n;j++){
                if(i & 1<<j){
                    tmp.push_back(nums[j]);
                }
            }
            int sum=0;
            for(auto it:tmp){
                sum+=it;
            }
            if(sum==target){
                v.push_back(tmp);
            }
            
        }
        return v;
    }
};

#include <bits/stdc++.h>
#include <fstream>
#include <string.h>

using namespace std;

int main(){
    string str;
    cout<<"Enter your name :";
    getline(cin,str);

    ofstream data("sample.txt");
    data<<str;
    data.close();

    ifstream datain("sample.txt");
    string st;
    getline(datain,st);
    cout<<st;
    // while(datain.eof()==0){
    // getline(datain,st);
    // cout<<st<<endl;
    // }
    return 0;
}