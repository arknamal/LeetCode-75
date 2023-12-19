/*
1071. Greatest Common Divisor of Strings
Easy

For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).
Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

Example 1:
Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"

Example 2:
Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"

Example 3:
Input: str1 = "LEET", str2 = "CODE"
Output: ""

Constraints:
    1 <= str1.length, str2.length <= 1000
    str1 and str2 consist of English uppercase letters.
*/
#include <iostream>
#include <string>

class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2) {
        if(str1 == str2)
            return str1;
        int max_str_length = std::max(str1.length(), str2.length());
        int longer_string_num = 1;
        if(str1.length() < str2.length())
            longer_string_num = 2;
        std::string candidate_str = "";
        for(int i = max_str_length/2; i > 0; --i){
            for(int j = 0; j <= max_str_length/2 - i; ++j){
                candidate_str = str1.substr(j, i);
                std::cout << i << " " << j << " " << candidate_str << std::endl;
                if(longer_string_num == 2)
                    candidate_str = str2.substr(j, i);
                if(qualify(candidate_str, str1, str2))
                    return candidate_str;
            }
        }
        std::cout << "ni labha";
        return "cfdhgdhfdsdhdghgf";
    }
private:
    bool qualify(std::string candidate_str, std::string longer_str, std::string shorter_str){
        int measure = candidate_str.length();
        for(int k = 0; k < longer_str.length(); k += measure){
            if(longer_str.substr(k, measure) != candidate_str)
                return false;
            if(k < shorter_str.length() && shorter_str.substr(k, measure) != candidate_str)
                return false;
        }
        return true;
    }
};

// Testing:

int main(){
    Solution object;
    std::cout << object.gcdOfStrings("ABABABABc", "AB");
    return 0;
}

// class Solution {
// public:
//     std::string gcdOfStrings(std::string str1, std::string str2) {
//         if(str1 == str2)
//             return str1;
//         int max_str_length = std::max(str1.length(), str2.length());
//         int min_str_length = std::min(str1.length(), str2.length());
//         int longer_string_num = (str1.length() < str2.length())? 2 : 1;
//         std::string candidate_str = "";
//         for(int i = min_str_length; i > 0; --i){
//             for(int j = 0; j <= max_str_length/2 - i; ++j){
//                 candidate_str = (longer_string_num == 1)? str1.substr(j, i) : str2.substr(j, i);
//                 if(max_str_length % candidate_str.length() != 0)
//                     continue;
//                 if(qualify(candidate_str, str1, str2))
//                     return candidate_str;
//             }
//         }
//         return "";
//     }
// private:
//     bool qualify(std::string& candidate_str, std::string& longer_str, std::string& shorter_str){
//         int measure = candidate_str.length();
//         for(int k = 0; k < longer_str.length(); k += measure){
//             if(longer_str.substr(k, measure) != candidate_str)
//                 return false;
//             if(k < shorter_str.length() && shorter_str.substr(k, measure) != candidate_str)
//                 return false;
//         }
//         return true;
//     }
// };