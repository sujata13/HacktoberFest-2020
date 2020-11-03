# Python program to validate an Email 

import re 
  
# This program checks email using regular expression 
regex = '^[a-z0-9]+[\._]?[a-z0-9]+[@]\w+[.]\w{2,3}$'


def check(email):  
  
    
    if(re.search(regex,email)):  
        print("The email is valid!")  
          
    else:  
        print("The email is invalid!")  
      
  
# Driver Code  
if __name__ == '__main__' :  
    checking = True
    while checking == True:
        print("This is an email checker tool!")
        email = input("Enter your email: ")
        check(email)
        print("Press 1 to continue checking, 'False' to stop")
        checking = input("Here: ")
