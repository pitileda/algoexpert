def MoveElementToTheEnd(array: list, toMove: int):
    left = 0
    right = len(array) - 1
    while left < right:
        if array[right] != toMove:
            if array[left] == toMove:
                array[left], array[right] = array[right], array[left]
            left += 1
        else:
            right -= 1
    return array


print(MoveElementToTheEnd([2, 1, 2, 2, 2, 3, 4, 2], 2))
