n = int(input())
a = list(map(int, input().split()));
ans = 1
v = []
for i in range(1, n):
	if(a[i] == 1):
		ans += 1
		v.append(a[i - 1])
v.append(a[n - 1])
print(len(v))
print(' '.join(map(str, v)));