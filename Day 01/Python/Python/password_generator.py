import string
import random

if __name__ == "__main__":
    s1 = string.ascii_lowercase
    s2 = string.ascii_uppercase
    s3 = string.digits
    s4 = string.punctuation
    s = []
    try:
        passwordLength = int(input("Enter password length: "))
    except Exception as e:
        print("Error occured, please enter a valid integer.")
        exit()

    s.extend(s1)
    s.extend(s2)
    s.extend(s3)
    s.extend(s4)
    # print(s)

    random.shuffle(s)

    print("Your password is: ",end="")
    # print("".join(random.sample(s,passwordLength)))   (Alternative of random.shuffle(s))
    print("".join(s[0:passwordLength]))
    
#contributed by Ankur
