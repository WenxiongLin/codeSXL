#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    // vector<char> mag;
    // for(int i = 0; i < magazine.length(); i++){
    //     mag.push_back(magazine[i]);
    // }
    // for(int i = 0; i < ransomNote.length(); i++){
    //     bool had = false;
    //     for(auto& c : mag){
    //         if(c == ransomNote[i]){
    //             c = mag.back();
    //             mag.pop_back();
    //             had = true;
    //             break;
    //         }
    //     }
    //     if(had) continue;
    //     return false;
    // }
    // return true;

    // 使用哈希法，用一个长度为26的数组来表示字母出现的次数
    if (ransomNote.length() > magazine.length()) {
      return false;
    }
    // vector<int> cnt(26);
    int cnt[26] = {0};
    for (auto& c : magazine) {
      cnt[c - 'a']++;
    }
    for (auto& c : ransomNote) {
      cnt[c - 'a']--;
      if (cnt[c - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }
};