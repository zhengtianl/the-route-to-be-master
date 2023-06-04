class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        set1 = set(dictionary)
        words = sentence.split(" ")
        for i, word in enumerate(words):
            for j in range (len(word)):
                if word[:j] in set1:
                    words[i] = word[:j]
                    break
        return " ".join(words)

        