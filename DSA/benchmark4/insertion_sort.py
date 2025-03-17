
from typing import List

def insertion_sort(arr: List[str]):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
        print(f"i={i}, {arr}")
    return arr


input_list = list("EASYEXAMPLE")
sorted_list = insertion_sort(input_list)
print("EASYEXAMPLE")
print(''.join(sorted_list))

