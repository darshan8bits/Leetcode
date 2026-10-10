class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}
        for s in strs:
            key = sorted(s)
            key = ''.join(key)
            if key not in d:
                d[key] = [s]
            else:
                d[key].append(s)
        ans = []
        for val in d.values():
            ans.append(val)
        return ans