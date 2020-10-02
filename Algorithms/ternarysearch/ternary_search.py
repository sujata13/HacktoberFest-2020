def ternarysearch(a,num,left,right):
    if right<left:
        return -1
    mid1 =left + (right-left)//3
    mid2 =right - (right-left)//3
    if a[mid1]==num:
        return mid1
    if a[mid2]==num:
        return mid2

    if num < a[mid1]:
        #left=mid1+1
        right=mid1-1
    elif num > a[mid2]:
        left=mid2+1
    else:
        left=mid1+1
        right=mid2-1
    return ternarysearch(a,num,left,right)


a = [4,6,7,9,13,14,34,55,67,78,90,123,619]
num = 55
print(len(a))
index = ternarysearch(a,num,0,len(a)-1)
print(f"Given number found at {index} using ternary search")