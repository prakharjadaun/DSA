class Solution(object):
    def numDifferentIntegers(self, word):
        """
        :type word: str
        :rtype: int
        """
        word = ''.join(c if c.isdigit() else ' ' for c  in word)
        return len(set(map(int,word.split())))
