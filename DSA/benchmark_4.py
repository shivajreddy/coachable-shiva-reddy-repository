"""
Sorting
"""
from typing import List

"""
Selection Sort
  - Describe the selection sort algorithm.
  A: 
  - What is the runtime?
  A: 
  - What is the best-case runtime?
  A: 
  - What type of input causes the worst-case runtime?
  A: 
  - Describe qualitatively how an array will look at each intermediate stage of selection sort.
  A: 
  - Implement Selection Sort in Python. Track the number of swaps made and return this count.
  A: 
"""

"""
Insertion Sort
  - Describe the insertion sort algorithm.
  A: 
  - What is the runtime?
  A: 
  - What is the best-case runtime?
  A: 
  - What type of input causes the best case runtime?
  A: 
  - Describe qualitatively how an array will look at each intermediate stage of insertion sort.
  A: 
  - Implement insertion sort and modify it to count how many times elements are shifted. How does this relate to its runtime?
  A: 
"""

"""
Simple Sorting
"""
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



"""
Insertion Sort
"""

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

"""
Merge Sort
"""

def merge(arr, aux, lo, mid, hi):
    for k in range(lo, hi+ 1):
        aux[k] = arr[k]

    i, j = lo, mid + 1
    for k in range(lo, hi + 1):
        if i > mid or aux[j] < aux[i]:
            arr[k] = aux[j]
            j += 1
        else:
            arr[k] = aux[i]
            i += 1

# Top-Down
def mergesort_toopdown(arr: List[int], aux: List[int], lo: int, hi: int):
    if hi <= lo:
        return
    mid = lo + (hi - lo) // 2
    mergesort_toopdown(arr, aux, lo, mid)
    mergesort_toopdown(arr, aux, mid+1, hi)
    merge(arr, aux, lo, mid, hi)

def sort_topdown(arr: List[int]):
    aux = arr.copy()
    mergesort_toopdown(arr, aux, 0, len(arr) - 1)

input_list = [3, 7, 1, 2, 18, -5, 0, 12]
print(input_list)
sort_topdown(input_list)
print(input_list)


"""
Sorting
  - Describe what it means for a sort to be stable.
  A: The relative order is maintained
  - Describe what it means for a sort to be in-place.
  A: No use of extra space (auxiliary array of input)
  - Which of selection sort, merge sort, quick sort, insertion sort are stable?
  A: 
"""

"""
Mergesort
  - Describe how mergesort works at a high-level.
  A: 
  - What is the runtime? Describe why it’s O(n log n).
  A: 
  - Describe qualitatively how an array will look at each intermediate stage of merge sort.
  A: 
  - Implement Mergesort.
  A: 
  - How does merge sort handle duplicates differently than quicksort?
  A: 
"""

"""
Quicksort
  - Describe how quicksort works at a high-level.
  A: 
  - Why does it have average case O(n log n) runtime?
  A: 
  - What is the worst-case runtime? When does it happen?
  A: 
  - What is 3-way quicksort? When is it better?
  A: 
  - Show the result of quicksort after partitioning on the first S in SWIMPEATSFRIES
  A: 
  - Describe the quickselect algorithm.
  A: 
  - Describe qualitatively how an array will look at each intermediate stage of quicksort.
  A: 
"""

