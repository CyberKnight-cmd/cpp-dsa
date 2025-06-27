n = input("Enter S to start : ")
iteration = 1
totalRight = 0
totalWrong = 0
while True:
    a = input(f"Enter choice for {iteration}: ")
    iteration+=1
    if("r" in a):
        totalRight += 1
    elif("d" in a):
        break
    else:
        totalWrong += 1
    print("Choice taken, moving to next.....\n")
    
print("Total right = ", totalRight)
print("Total wrong = ", totalWrong)

print("Marks : ", (totalRight*4 - totalWrong))