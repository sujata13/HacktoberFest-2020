    
try:
# Python program forBubble Sort 
  
    def bubbleSort(arr): 
        length_of_arr = len(arr) 
      
        # Traverse through all array elements 
        for i in range(length_of_arr): 
      
            # Last i elements are already in place 
            for j in range(0, length_of_arr-i-1): 
      
                # traverse the array from 0 to n-i-1 
                # Swap if the element found is greater 
                if(arr[j] > arr[j+1]):
                    temp=arr[j]
                    arr[j]=arr[j+1]
                    arr[j+1]=temp

    n=int(input("Enter the length of an array:"))
    arr=list(map(int,input().strip().split()))[:n]

    bubbleSort(arr)   
    print ("Sorted array is:") 
    for i in range(len(arr)): 
        print (arr[i],end=" ")
    print()
            
except:
    pass


"""
Enter length of arr:4
5 6 2 8
Sorted array is:
2 5 6 8 

"""
    
