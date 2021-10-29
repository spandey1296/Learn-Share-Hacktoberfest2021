# definging the function 
def findSubset(userList, n, sum):
    if (sum == 0):
        return True
    if (n == 0):
        return False
    if (userList[n - 1] > sum):
        return findSubset(userList, n - 1, sum)
    return findSubset(
        userList, n-1, sum) or findSubset(
        userList, n-1, sum-userList[n-1])
# getting the list from user
userList = [int(n) for n in input().split()]
# enter the number to match
sum = int(input())
# finding the length of the string
n = len(userList)
# checking the condition and displaying the result
if (findSubset(userList, n, sum) == True):
    print("True")
else:
    print("False")
 