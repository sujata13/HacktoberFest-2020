    
try:

    # Python program to search element.  
    # If element is present in an array then return its current location, 
    # otherwise return -1 
      
    def search(arr, n, x): 
        for i in range(0, n): 
            if (arr[i]==x): 
                return i; 
        return -1; 
      
    n=int(input("Enter the length of an array:"))
    arr=list(map(int,input().strip().split()))[:n]
    x=int(input("enter element that we need to search:"))
          
    result = search(arr, n, x) 
    if(result == -1): 
        print("Element is not present in array") 
    else: 
        print("Element is present at index", result); 
            
except:
    pass


"""
Enter the length of an array:5
5 4 3 6 10
enter element that we need to search:10
Element is present at index 4
"""
    
