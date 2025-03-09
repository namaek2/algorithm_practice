//최대공약수...
//문자열 길이 비교해서 5, 3 같이 서로소인 경우는 "" 리턴


class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int small_length = 0;
        int long_length = 0;
        if(str1.size() > str2.size()) {
            small_length = str2.size();
            long_length = str1.size();
        } else {
            small_length = str1.size();
            long_length = str2.size();
        }


        string test_s = "";
        for(int i = small_length; i > 0; i--) {
            for(int j = 0; j <= long_length - small_length; j++) {
                if (str1[j] != str2[j]){
                    break;
                }
            }
        } 
    }
};