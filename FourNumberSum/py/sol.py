def fourNumberSum(array: list, targetSum: int):
    numbers = {}
    quadroplets = []
    for i in range(1, len(array) - 1):
        for plus in range(i + 1, len(array)):
            Q = targetSum - (array[i] + array[plus])
            if Q in numbers:
                for pair in numbers[Q]:
                    quadroplets.append(pair + [array[i], array[plus]])
        for minus in range(i):
            P = array[i] + array[minus]
            if P in numbers:
                numbers[P].append([array[minus], array[i]])
            numbers[P] = [[array[minus], array[i]]]
    return quadroplets


print(fourNumberSum([7, 6, 4, -1, 1, 2], 16))
print(fourNumberSum([-1, -2, 4, 3, 0, 2, 6, -5], 1))
