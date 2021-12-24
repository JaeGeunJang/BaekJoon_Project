a = int(input())
b = int(input())

print(a*(b%10))
b1 = int((b%100)/10)
b2 = int(b/100)

print(a*b1)
print(a*b2)
print(a*b)