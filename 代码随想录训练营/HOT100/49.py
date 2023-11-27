import collections
def groupAnagrams(strs):
    mp = collections.defaultdict(list)
    for st in strs:
        key = ''.join(sorted(st))
        mp[key].append(st)
    return list(mp.values())


    