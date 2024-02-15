def twoNumberSum(array, targetSum):
    numbers = {}
    for x in range(len(array)):
        if targetSum - array[x] in numbers:
            return [array[x], targetSum - array[x]]
        numbers[array[x]] = True
    return []


print(twoNumberSum([3, 5, -4, 8, 11, 1, -1, 6], 10))
