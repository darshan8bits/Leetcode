class Solution:
    def topKFrequent(self, words: list[str], k: int) -> list[str]:
        d = {}
        for i in words:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1

        # Make it frequency -> [words]
        d2 = {}
        for word, freq in d.items():
            if freq in d2:
                d2[freq].append(word)
            else:
                d2[freq] = [word]
        l1 = []
        for f, wlist in d2.items():
            wlist.sort()
            l1.append([f, wlist])
        l1.sort()
        l1.reverse()
        l2 = []
        
        for i in l1:
            for j in i[1]:
                l2.append(j)

        return l2[0:k]