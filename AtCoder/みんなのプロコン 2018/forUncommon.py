from tqdm import tqdm

def GCD(a, b):
    M = max(a, b)
    m = min(a, b)
    if m == 0:
        return M
    else:
        return GCD(m, M % m)


n=10**5

table=[["0"]*n for i in range(n)]
print(table)
for i in tqdm(range(n)):
    for j in range(n):
        if GCD(i+1,j+1)==1:
            table[i][j]="1"



s="{"
for i in table:
    s+="{"
    s+=",".join(i)
    s+="},"
s+="}"

print(s)
