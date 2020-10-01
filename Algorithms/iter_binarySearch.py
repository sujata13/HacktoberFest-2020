#Iterative Binary Search Algorithm

def binary_search(arr, x): 
    low = 0
    high = len(arr) - 1
    mid = 0
  
    while low <= high: 
  
        mid = (high + low) // 2
  
        if arr[mid] < x: 
            low = mid + 1
        elif arr[mid] > x: 
            high = mid - 1
        else: 
            return mid 
  
    
    return -1
  
  
 
n=int(input("Enter length of array: "))
arr=[]
for i in range(n):
    inp=int(input("Enter "+str(i)+"(nd/th) element:"))
    arr.append(inp)

target=int(input("Enter element to be searched: "))
  
result = binary_search(arr, target) 
  
if result != -1: 
    print("Element is at index", str(result)) 
else: 
    print("Element is not present in the array") 
