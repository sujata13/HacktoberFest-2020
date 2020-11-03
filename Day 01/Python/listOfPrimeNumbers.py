''' i.e. lower limit and upper limit and calculates all the prime numbers in that range.
'''

def isPrime(n):
    if n==1:
        return False
    elif n==2:
        return True
    else:
        for i in range(2,(n//2+1)):
            if n%i==0:
                return False
        return True

def listPrimes(limit):
    primes = []
    for n in range(1,limit+1):
        if isPrime(n):
            primes.append((n,"Prime"))
        else:
            primes.append((n,"Non Prime"))
    for n in primes:
        print (n)

if __name__=="__main__":
    limit = int(input("Enter the limit... "))
    listPrimes(limit)
