lst = [2,3,6,7,8,15]
search_elm = 7
flag = 0
l = 0
u = len(lst)-1
while l<=u:
    mid = (l+u)//2
    if lst[mid] == search_elm:
        flag = 1
        break
    else:
        if lst[mid] < search_elm :
            l = mid+1
        else:
            u = mid-1
if flag == 1:
    print("element found")
else:
    print("element not found")
        
