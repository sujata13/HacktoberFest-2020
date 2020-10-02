
def binarysearch(a,num,left,right):
    if right<left:
        return -1
    mid = 0
    mid = (left+right)//2
    if mid >= len(a) or mid<0:
        return -2
    if a[mid] == num:
        return mid
    elif a[mid] < num:
        left=mid+1
    elif a[mid] > num:
        right=mid-1
    
    return binarysearch(a,num,left,right)


a = [4,6,7,9,13,14]
num = 4
index = binarysearch(a,num,0,len(a)-1)
print(f"Given number found at {index} using binary search")
