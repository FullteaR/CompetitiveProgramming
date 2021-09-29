import itertools

def get_arg_cos_sq(p1,p2,p3):
    #小数を使いたくないので、分子分母符号(それぞれは整数)を別で返す。
    x1 = p1[0] - p2[0]
    y1 = p1[1] - p2[1]
    x2 = p3[0] - p2[0]
    y2 = p3[1] - p2[1]

    return (x1*x2+y1*y2)**2, (x1**2+y1**2)*(x2**2+y2**2), x1*x2+y1*y2>=0

def score_trapezium(p12, p34):
    p1 = p12[0]
    p2 = p12[1]
    p3 = p34[0]
    p4 = p34[1]
    th1_up,th1_d, pm1 = get_arg_cos_sq(p1,p2,p3)
    th2_up,th2_d, pm2 = get_arg_cos_sq(p2,p1,p4)
    if th1_up*th2_d==th2_up*th1_d and th1_up!=th1_d and th2_up!=th2_d and pm1==pm2:
        return p1[2]+p2[2]+p3[2]+p4[2]
    else:
        return -1


N= int(input())

points = []
for i in range(N):
    points.append(tuple([int(j) for j in input().split(" ")]))

d = {}
for iter in itertools.combinations(points,2):
    try:
        liner = (iter[1][1] - iter[0][1]) / (iter[1][0] - iter[0][0])
    except ZeroDivisionError:
        liner = None
    if liner in d:
        d[liner].add(iter)
    else:
        d[liner] = set([iter])


score = -1
for key in d:
    for iter in itertools.combinations(d[key],2):
        if (iter[0][0] in iter[1]) or (iter[0][1] in iter[1]):
            continue
        score = max(score, score_trapezium(*iter))
print(score)