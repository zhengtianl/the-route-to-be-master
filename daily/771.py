with open('a.txt') as f1:
    content1 = f1.read()
    a = [x.strip() for x in content1]
with open('b.txt') as f2:
    content2 = f2.read()
    b = [x.strip() for x in content2]

for x in b:
    if x not in a:
        print(x)

