/*
605. Can Place Flowers
Easy

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

Hidden Test Case 13/129:
Input: flowerbed = [1,0,0,0,1,0,0], n = 2
Output: true

Hidden Test Case 14/129:
Input: flowerbed = [0], n = 1
Output: true

Hidden Test Case 120/129:
Input: flowerbed = [1,0,1,0,1,0,1], n = 0
Output: true

Constraints:
  1 <= flowerbed.length <= 2 * 104
  flowerbed[i] is 0 or 1.
  There are no two adjacent flowers in flowerbed.
  0 <= n <= flowerbed.length
*/

#include <vector>

class Solution {
public:
  bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
    if(n == 0)
      return true;
    int l = flowerbed.size();
    for(int i = 0; i < l; i++){
      if(flowerbed[i] == 0){
        if(flowerbed[((i > 0)? (i - 1) : i)] == 0 && flowerbed[((i == l - 1)? i : i + 1)] == 0){
          flowerbed[i] = 1;
          if(--n == 0)
            return true;
        }
      }
    }
    return false;
  }
};

/*
Note: Ironically, the following code is not the best on verbosity index but much more efficient than the above elegant one as it is much better in Runtime and Memory utilization because it checks the edge cases first, outside of the main loop.

class Solution {
public:
  bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
    if(n == 0)
      return true;
    int l = flowerbed.size();
    if(l == 1 && flowerbed[0] == 0){
      flowerbed[0] = 1;
      if(--n == 0)
        return true;
    }
    if(flowerbed[0] == 0 && flowerbed[1] == 0){
      flowerbed[0] = 1;
      if(--n == 0)
        return true;
    }
    if(flowerbed[l - 1] == 0 && flowerbed[l - 2] == 0){
      flowerbed[l - 1] = 1;
      if(--n == 0)
        return true;
    }
    for(int i = 1; i < l - 2; i++){
      if(flowerbed[i] == 0){
        if(flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0){
          flowerbed[i] = 1;
          if(--n == 0)
            return true;
        }
      }
    }
    return false;
  }
};
*/