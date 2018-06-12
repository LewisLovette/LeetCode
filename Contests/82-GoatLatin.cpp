class Solution {
public:
    string toGoatLatin(string s) {
        int count = 1;
        string vowels = "aeiouAEIOU";
        bool match = false;
        
        //splitting whitespaces
        istringstream iss(s);
        vector<string> arr{
            istream_iterator<string>(iss), {}
        };
        
        for(int i = 0; i < arr.size(); i++){
            
            //Checking for vowels
            for(int x = 0; x < vowels.size(); x++){
                if(vowels[x] == arr[i][0]) match = true;
            }
            
            //following rules of the language
            if(match == true){
                arr[i] += "ma";
            } 
            else{
                arr[i] += arr[i][0];
                arr[i].erase(0, 1);
                arr[i] += "ma";
            }
            
            for(int j = 0; j < count; j++){
                arr[i] += "a";
            }
            count++;
            match = false;
        }
        
        string result = arr[0];
        cout << result;
        for(int i = 1; i < arr.size(); i++) result += " " + arr[i];
        
        return result;
    }
};
