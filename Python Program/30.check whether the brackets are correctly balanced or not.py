# getting the sequence from the user
s = input("Enter sequence: ")
is_valid = True
count = 0
# iterating over each character
for ch in s:
    if ch == '(':
        count += 1
    elif ch == ')':
        if count == 0:
            is_valid = False
        else:
            count -= 1
# displaing the result
if is_valid and count == 0:
    print(s, "is logicall ordered")
else:
    print(s, "is not")