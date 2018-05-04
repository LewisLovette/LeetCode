class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int requests = 0;
        int arr[ages.size()] = {0};
        
        for(int i = 0; i < ages.size(); i++){
            for(int j = 0; j < ages.size(); j++){
                if(arr[j] == 0){
                    arr[j] = 0.5 * ages[j] + 7;
                }
                
                if(ages[i] <= arr[j]){
                    continue;
                } 
                else if(ages[i] > ages[j]){
                    continue;
                } 
                else if(ages[i] > 100 && ages[j] < 100){ 
                    continue;
                }

                if(i == j) continue;

                requests++;
                
            }
        }
        
        return requests;
    }
};