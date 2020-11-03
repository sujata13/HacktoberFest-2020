s,n = map(int,input().split())
fl =1
l=[]
for i in range(n):
	x,y = map(int,input().split())
	l.append([x,y])
l=sorted(l)	
for i in range(n):
	if(s > l[i][0]):
		s+=l[i][1]
	else:
		fl =0	
		break
if(fl):
	print("YES")
else:
	print("NO")
