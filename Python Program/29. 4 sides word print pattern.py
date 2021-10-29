# getting the stirng from user
userWord=input()
# finding the length of the stirng
l=len(userWord)
print()
# iterating over the length
for i in range(0,l+2):
   if(i==0):
       # printing the stars
       print("* ",end="")
       # row-wise printing
       for j in range(0,l):
           # displaing the letter
           print(userWord[j],end=" ")
       print("*")
   elif(i==l+1):
       print("* ",end="")
       for j in range(l-1,-1,-1):
           # displaing the letter
           print(userWord[j],end=" ")
       print("*")
   else:
       print(userWord[l-i],end=" ")
       for j in range(0,l):
           # displaing the letter
           print("*",end=" ")
       print(userWord[i-1])