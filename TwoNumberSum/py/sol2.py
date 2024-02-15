def twoNumberSum(array: list, targetSum: int):
    array.sort()
    left = 0
    right = len(array) - 1
    while left < right:
        currSum = array[left] + array[right]
        if currSum == targetSum:
            return [array[left], array[right]]
        elif currSum < targetSum:
            left += 1
        else:
            right - +1
    return []


print(twoNumberSum([3, 5, -4, 8, 11, 1, -1, 6], 10))
