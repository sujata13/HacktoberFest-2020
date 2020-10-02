
def Diamond(rows): 
	n = 0
	for i in range(1, rows + 1): 
	 
		for j in range (1, (rows - i) + 1): 
			print(end = " ") 
		
	
		while n != (2 * i - 1): 
			print("*", end = "") 
			n = n + 1
		n = 0
		
	
		print() 

	k = 1
	n = 1
	for i in range(1, rows): 
	
		for j in range (1, k + 1): 
			print(end = " ") 
		k = k + 1
		
		
		while n <= (2 * (rows - i) - 1): 
			print("*", end = "") 
			n = n + 1
		n = 1
		print() 


rows = 5
Diamond(rows) 
