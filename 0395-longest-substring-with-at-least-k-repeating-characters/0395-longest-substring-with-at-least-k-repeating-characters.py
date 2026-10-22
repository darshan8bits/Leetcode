
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        n = len(s)
        mp = {}

        for ch in s:
            if ch not in mp:
                mp[ch] = 1
            else:
                mp[ch] += 1
        
        for ch in mp.keys():

            if mp[ch] < k:

                return max(
                    self.longestSubstring(part, k)
                    for part in s.split(ch)
                )
        return len(s)
