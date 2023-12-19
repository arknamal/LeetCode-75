/*
345. Reverse Vowels of a String
Easy

Given a string s, reverse only all the vowels in the string and return it.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Example 1:
Input: s = "hello"
Output: "holle"

Example 2:
Input: s = "leetcode"
Output: "leotcede"

Constraints:
  1 <= s.length <= 3 * 105
  s consist of printable ASCII characters.
*/

#include <string>

class Solution {
public:
  std::string reverseVowels(std::string s) {
    int l = s.length();
    std::string vowels = "";
    for(int i = 0; i < l; i++){
      if(isVowel(s[i])){
        vowels+= s[i];
      }
    }
    for(int i = 0; i < l; i++){
      if(isVowel(s[i])){
        s[i] = vowels.back();
        vowels.pop_back();
      }
    }
    return s;
  }
private:
  bool isVowel(char c){
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
  }
};