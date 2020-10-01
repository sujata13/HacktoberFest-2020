
def radixSort(arr):
    #m->maximum
	m = max(arr)
	den = 1
	while m/den > 0:
		countingSort(arr,den)
		den*=10
		
		

def countingSort(arr,d): 

	n=len(arr) 
	output=[0]*n 
	count=[0]*10  #10 digits 

	for i in range(0, n): 
		index = (arr[i]/d) 
		count[int((index)%10)] += 1

	for i in range(1,10): 
		count[i] += count[i-1] 

	i = n-1
	while i>=0: 
		index=(arr[i]/d) 
		output[count[int((index)%10)] - 1] = arr[i] 
		count[int((index)%10)] -= 1
		i -= 1
	i = 0
	for i in range(0,len(arr)): 
		arr[i] = output[i] 



def print_array(arr):
    print("The array:")
    for i in range(len(arr)):
    	print(arr[i])
    	



n=int(input("Enter length of array: "))
arr=[]
for i in range(n):
    inp=int(input("Enter "+str(i)+"(nd/th) element:"))
    arr.append(inp)
radixSort(arr)
print_array(arr)


