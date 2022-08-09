import random

passLength = int(input("\nWhat length should the password be: "))
passType = int(input("\nWould you like special characters or not (1 for yes, 2 for no): "))

password = []

if passType == 1:

    for index in range(passLength):
        password.append(chr(random.randint(33, 126)))

elif passType == 2:

    for index in range(passLength):

        password.append(chr(random.randint(48, 122)))
        
        while password[index] >= 58 and password[index] <= 64 or password[index] >= 91 and password[index] <= 96:
            password[index] = chr(random.randint(48, 122))

print("\n" + "".join(password))






