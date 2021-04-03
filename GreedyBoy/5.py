n, k = map(int, input().split())

N = 11111
time = [[0 for i in range(2)] for i in range(N)]

for i in range(n):
    s, e = map(int, input().split())
    time[s-1][0] += 1
    time[e-1][1] += 1

flag = True
total_tasks_running = 0
total_tasks_finished = 0
total_deadline_reached = 0

for t in range(N):
    total_tasks_running += time[t][0]
    this_time_tasks_done = min(k, total_tasks_running)
    total_tasks_finished += this_time_tasks_done
    total_tasks_running -= this_time_tasks_done
    total_deadline_reached += time[t][1]

    if total_tasks_finished < total_deadline_reached:
        flag = False
        break

print('YES' if flag else 'NO')


