/*
1768. Merge Strings Alternately
Easy

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
Return the merged string.

Example 1:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r

Example 2:
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s

Example 3:
Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d

Constraints:
    1 <= word1.length, word2.length <= 100
    word1 and word2 consist of lowercase English letters.
*/

class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    int shorter_string_length = 0;
    int longer_string_number = 0;
    string merged_string = "";
    if(word1.length() <= word2.length()){
      shorter_string_length = word1.length();
      longer_string_number = 2;
    }
    else{
      shorter_string_length = word2.length();
      longer_string_number = 1;
    }
    for(int i = 0; i < shorter_string_length; i++){
      merged_string += word1[i];
      merged_string += word2[i];
    }
    for(int i = shorter_string_length; i < (longer_string_number == 1? word1.length() : word2.length()); i++){
      merged_string += (longer_string_number == 1? word1[i] : word2[i]);
    }
    return merged_string;
  }
};

/*
Notes:
Better solution was in the Hint - Use two pointers, one pointer for each string. Alternately choose the character from each pointer, and move the pointer upwards.
*/