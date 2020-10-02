    
try:

        # Python program to find LCM of two numbers
         
        # Recursive function to return gcd of a and b
        def gcd(a,b):
            if a == 0:
                return b
            return gcd(b % a, a)
         
        # Function to return LCM of two numbers
        def lcm(a,b):
            return (a / gcd(a,b))* b

        a=int(input("Enter first number:"))
        b =int(input("Enter Second Number:"))
        print('LCM of', a, 'and', b, 'is', lcm(a, b))
                  
except:
    pass
    
"""
Enter first number:10
Enter Second Number:20
LCM of 10 and 20 is 20.0
"""
