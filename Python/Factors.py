def factors(x):
    for i in range(1, x):
        if x%i == 0:
            print(i);

n = input("Enter an integer: ");
factors(n);