# https://open.kattis.com/problems/workout?tab=metadata



machine_times = [int(i) for i in input().split(" ")]
machine_times = [(machine_times[i], machine_times[i+1]) for i in range(0, len(machine_times), 2)]
machine_occupied_by_others = []
for i in range(10):
    machine_occupied_by_others.append([int(j) for j in input().split()])


total_time = 0

for _ in range(3):
    machine = 0
    while machine < 10:
        jim_use, jim_recovery = machine_times[machine]
        u, r, t = machine_occupied_by_others[machine]
        lifecycle_time = u + r
        if total_time < t:
            t = max(t, total_time+jim_use)
            machine_occupied_by_others[machine] = (u,r,t)
            total_time+=jim_use+jim_recovery
            machine+=1
        elif (total_time-t)%lifecycle_time>=u:
            next_start_time_without_jim = ((total_time-t)//lifecycle_time)*lifecycle_time+t
            while next_start_time_without_jim<total_time:
                next_start_time_without_jim+=lifecycle_time
            t = max(next_start_time_without_jim, total_time+jim_use)
            machine_occupied_by_others[machine] = (u,r,t)
            total_time+=jim_use+jim_recovery
            machine+=1
        else:
            total_time+=u-(total_time-t)%lifecycle_time

print(total_time-machine_times[-1][1])



