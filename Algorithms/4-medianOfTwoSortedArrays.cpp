class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int large = 0, small = 0, size1, size2;
        double ar1 = 0, ar2 = 0;
        bool flagNum1Large = true;
        
        //Checking for empty vector
        if(nums1.empty() == true){
            nums1.push_back(0);
            size1 = 0;
        }
        else{
            size1 = nums1.size();
        }
        
        if(nums2.empty() == true){
            nums2.push_back(0);
            size2 = 0;
        }
        else{
            size2 = nums2.size();
        }
           
        //Finding which has largest number of elements
        if(size1 > size2){
            large = size1;
            small = size2;
        }
        else{
            flagNum1Large = false;
            large = size2;
            small = size1;
        }
        
        //Fitting the time complexity - all one loop, flag used so shorter array doesn't cause error.
        for(int i = 0; i < large; i++){
            if(flagNum1Large == true){ //for nums1 harving larger size
                if(i <= small){
                    ar1 += nums1[i];
                    ar2 += nums2[i];
                }
                else{
                    ar1 += nums1[i];
                }
            } 
            else{   //nums2 has larger size
                if(i <= small){
                    ar1 += nums1[i];
                    ar2 += nums2[i];
                }
                else{
                    ar2 += nums2[i];
                }
            }
        }
        
        cout << (ar1+ar2)/2 << endl;
        
        (size1 > 0) ? ar1 /= size1 : ar1 = 0;
        (size2 > 0) ? ar2 /= size2 : ar2 = 0;
        
        //returning based on if an array is empty or not.
        if(size1 == 0){
            return ar2;
        }
        else if(size2 == 0){
            return ar1;
        }
        else{
            return (ar1+ar2)/2;
        }
        
    }
};