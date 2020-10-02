import random

highest = 100
answer = random.randint(1, highest)

print("Guess a number between 1 and {}".format(highest + 1))
    
while guess != answer:
    guess = int(input())
    if guess == answer:
        print("You guessed correctly")
        break
    else:
        if guess == 0:
            print("Game over")
            break
        elif guess > answer:
            print("Please guess lower")
        else:
            print("Please guess higher")
