import requests as r

def display(res, choice):
    if choice == 1:
        print(res.text)
    elif choice == 2:
        print(res.headers)
    elif choice == 3:
        print(res.status_code)
    else:
        print("Invalid choice")

def viewAttributes(res):
    attributes = dir(res)
    for i, attr in enumerate(attributes):
        print(f"{i + 1}. {attr}")
    while True:
        choice = int(input("Enter the number corresponding to the attribute you wish to see (0 to exit): "))
        if choice == 0:
            break
        elif 1 <= choice <= len(attributes):
            attr = attributes[choice - 1]
            print(f"{attr}: {getattr(res, attr)}")
        else:
            print("Invalid choice")

url = input("Enter site url: ")
res = r.get(url)
choice = int(input("Enter the number corresponding to the item which you wish to see: \n1. Response text\n2. Response headers\n3. Response status code\n4. View all attributes\n"))
if choice in [1, 2, 3]:
    display(res, choice)
elif choice == 4:
    viewAttributes(res)
else:
    print("Invalid choice")