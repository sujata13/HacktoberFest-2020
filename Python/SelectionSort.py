#selection sort
a=[]
l=int(input('Enter the length of the array: '))
print('Enter the elements one by one')
for i in range(0,l):
    ele=int(input())
    a.append(ele)

for j in range (0,len(a)-1):
    minimum=j
    for k in range (j+1,len(a)):
        if a[k]<a[minimum]:
            minimum=k
    temp=a[j]
    a[j]=a[minimum]
    a[minimum]=temp
print(a)
