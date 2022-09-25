#Write Python 3 code in this online editor and run it.
# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.
def f(a):
    for i in a:
        if i !="":
            if "R" not in i or  "B" not in i:
                return "NO"
    return "YES"
for inh in range(int(input())):
    n=int(input())
    a=list(set(map(str,input().split("W"))))
    print(f(a))