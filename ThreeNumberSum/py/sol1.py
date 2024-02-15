def threeNumberSum(array: list, targetSum: int):
    array.sort()
    triplets = []
    for i in range(len(array) - 1):
        firstNum = array[i]
        left = i + 1
        right = len(array) - 1
        currSum = targetSum - firstNum
        while left < right:
            if array[left] + array[right] == currSum:
                triplets.append([firstNum, array[left], array[right]])
                left += 1
                right -= 1
            elif array[left] + array[right] < currSum:
                left += 1
            else:
                right -= 1
    return triplets


print(threeNumberSum([12, 3, 1, 2, -6, 5, -8, 6], 0))
