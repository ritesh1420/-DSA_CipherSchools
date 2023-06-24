#include<bits/stdc++.h>
using namespace std;
    int trappingWater(int arr[], int n){
        vector<int>left_to_right_max;
        vector<int>right_to_left_max;
        
        int firstmax=arr[0];
        int lastmax=arr[n-1];
        
        left_to_right_max.push_back(firstmax);
        right_to_left_max.push_back(lastmax);
        
        for(int i=1;i<n;i++){
            firstmax=max(firstmax,arr[i]);
            left_to_right_max.push_back(firstmax);
        }
        
        for(int i=n-2;i>=0;i--){
            lastmax=max(lastmax,arr[i]);
            right_to_left_max.push_back(lastmax);
        }
        reverse( right_to_left_max.begin(), right_to_left_max.end());
        
        long long  ans=0;
        for(int i=0;i<n;i++){
            ans=ans+min(left_to_right_max[i],right_to_left_max[i])-arr[i];
        }
        
        return ans;
    }
    int main(){
    	int n=8;
    	int array[n]={5,4,6,3,2,9,1,10};
    	int ans=trappingWater(array,n);
    	cout<<ans;
	}
