def binarysearch(a,num,left,right):

    while left<right:
        mid = (left+right)//2

        if a[mid]==num:
            return mid
        elif a[mid] < num:
            left=mid+1
        elif a[mid] > num:
            right=mid-1
    return -1


a = [4,6,7,9,13,14]
num = 13
index = binarysearch(a,num,0,len(a)-1)
print(f"Given number found at {index} using binary search")