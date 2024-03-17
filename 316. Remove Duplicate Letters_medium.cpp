class Solution {
public:
    string removeDuplicateLetters(string s) {
         string res = "";
  int cnt[26] = {}, used[26] = {};
  for (auto ch : s) ++cnt[ch - 'a'];// to make a count of all the characters
  for (auto ch : s) {
    --cnt[ch - 'a'];
    if (used[ch - 'a']++ > 0) continue;//cjhecking if the char is already in the res string
   // if not then it is checked and added
    while (!res.empty() && res.back() > ch && cnt[res.back() - 'a'] > 0) {
      used[res.back() - 'a'] = 0;
      res.pop_back();
    }
    res.push_back(ch);
  }
  return res;
 }
};
