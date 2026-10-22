class Solution:

    def minWindow(self, s: str, t: str) -> str:
        match = {}
        for i in t:
            if i not in match:
                match[i] = 1
            else:
                match[i] += 1
        
        
        need = len(match)
        have = 0

        left = 0
        curr = {}

        minm = float("inf")
        start = 0


        for right in range(len(s)):
            if s[right] not in curr:
                curr[s[right]] = 1
            else:
                curr[s[right]] += 1
            
        
            if s[right] in match and curr[s[right]] == match[s[right]]:

                have += 1

                while have == need:

                    if right - left + 1 < minm:
                        minm = right - left + 1
                        start = left

                    curr[s[left]] -= 1

                    if s[left] in match and match[s[left]] > curr[s[left]]:
                        have -= 1
                    
                    if curr[s[left]] == 0:
                        del curr[s[left]]

                    
                    left += 1

        if minm == float("inf"):
            return ""

        return s[start:start + minm]







