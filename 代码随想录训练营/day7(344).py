def reverseString(s):
    # Convert the string to a list to make it mutable
    s = list(s)

    # If length is less than 1, no need to reverse
    if len(s) < 2:
        return s

    l = 0
    r = len(s) - 1
    while l < r:
        s[l], s[r] = s[r], s[l]
        l += 1
        r -= 1

    # Convert the list back to a string before returning
    return "".join(s)
print(reverseString("dasjdhasjkhdasjkhd"))
