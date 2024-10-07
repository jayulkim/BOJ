a = 0
while True:
    try:
        b = input()
        a+= 1
    except EOFError:
        break  
print(a)