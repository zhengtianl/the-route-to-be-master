class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        dictionarySet = set(dictionary)
        words = sentence.split()
        for i, word in enumerate(words):
            for j in range(1, len(word)):
                if word[:j] in dictionarySet:
                    words[i] = word[:j]
                    break
        return " ".join(words)

def mian():
    solution = Solution()
    dictionary = ['cat', 'bat', 'rat']
    sentence = "the cattle was rattled by the battery"
    result = solution.replaceWords(dictionary, sentence)
    print(result)


if __name__ == "__main__":
    main()
    