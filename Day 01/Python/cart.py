#global list
cart = []
def addItem(item):
    cart.append(item)
    main()
    
def removeItem(item):
    if item in cart:
        cart.remove(item)
    else:
        print("The item does not exist.")
    main()

def clear():
    cart.clear()
    main()

def show():
    for x in cart:
        print(f"{x}")
    main()

def quit():
    print("Your cart things :")
    for x in cart:
        print(f"{x}")
    print("Thanks for shopping. Have a good day")

def main():
    userinput = input("add/remove/clear/show/quit : ").lower()
    if userinput == "quit":
        quit()
    elif userinput == "add":
        add_item = input("Enter the item to input : ")
        addItem(add_item)
    elif userinput == "remove":
        remove_item = input("Enter the item to delete : ")
        removeItem(remove_item)
    elif userinput == "clear":
        clear()
    elif userinput == "show":
        show()
    else:
        print("Wrong keyword.")
main()
