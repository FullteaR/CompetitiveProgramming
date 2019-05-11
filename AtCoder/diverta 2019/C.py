N = int(input())
end_A_only = 0
start_B_only = 0
both = 0
count = 0
for i in range(N):
    s = input()
    count += s.count("AB")
    if s[-1] == "A" and s[0] == "B":
        both += 1
    elif s[-1] == "A":
        end_A_only += 1
    elif s[0] == "B":
        start_B_only += 1
    else:
        pass

if both == 0:
    count += min(end_A_only, start_B_only)

else:
    if end_A_only == 0 and start_B_only == 0:
        count += both - 1
    elif end_A_only == 0 or start_B_only == 0:
        count += both
    else:
        count += both + 1
        count += min(end_A_only - 1, start_B_only - 1)


print(count)
