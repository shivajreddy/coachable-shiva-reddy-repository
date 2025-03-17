from typing import List

# RUN TIME: O(N^2)
# SPACE: O(1)
def selection_sort(arr: List[str]):
    for i in range(len(arr)):
        min_idx = i
        # find the index of smallest number in [i+1..]
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr


input_list = list("EASYEXAMPLE")
sorted_list = selection_sort(input_list)
print("EASYEXAMPLE")
print(''.join(sorted_list))

