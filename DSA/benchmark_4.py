from typing import List

"""
Selection Sort
  Q: Describe the selection sort algorithm.
  A: Its a simple algorithm. Where each iteration scan the input array for the smallest item
  Q: What is the runtime?
  A: N^2
  Q: What is the best-case runtime?
  A: N^2 (since we dont know if the first item is the smallest, we end up scaning whole array)
  Q: What type of input causes the worst-case runtime?
  A: Any kind of input is O(N^2)  
  Q: Describe qualitatively how an array will look at each intermediate stage of selection sort.
  A: - say entire input array is unsorted
     - In first pass, iterate over 0..n find the smallest, swap it with item @ idx-0
     - In second pass, iterate over 1..n find the smallest, swap it with item @ idx-1
     - In n-1'th pass, last item stays in its place (in fact, we could only iterate n-2 times)
"""
# Q: Implement Selection Sort in Python. Track the number of swaps made and return this count.
def selection_sort(arr: List[str]):
    n = len(arr)
    count = 0
    for i in range(n):
        min_idx = i # index of the smallest item in [i+1..]
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        if min_idx != i:    # swap only if min_idx is different from i
            arr[i], arr[min_idx] = arr[min_idx], arr[i]
            count += 1
    return arr, count


input_list = list("EASYEXAMPLE")
sorted_list = selection_sort(input_list)
print("EASYEXAMPLE")
print(''.join(sorted_list[0]), sorted_list[1])


"""
Insertion Sort
  Q: Describe the insertion sort algorithm.
  A: It is also a simple algorithm. Finds the smallest item in each item, and places it into the
     correct position relative to the already sorted part of the array
  Q: What is the runtime?
  A: O(N^2)
  Q: What is the best-case runtime?
  A: O(N), for an already sorted array.
  Q: What type of input causes the best case runtime?
  A: Best case is the already sorted input
  Q: Describe qualitatively how an array will look at each intermediate stage of insertion sort.
  A: - At each intermediate stage of insertion sort:
        - The first element is considered "sorted."
        - In each iteration, the next element is inserted into its correct position in the sorted 
          portion by shifting larger elements to the right.
        - As the algorithm progresses, the sorted portion of the array grows larger, and the 
          unsorted portion gets smaller.
        - After the final iteration, the entire array is sorted.
  Q: Implement insertion sort and modify it to count how many times elements are shifted. 
  Q: How does this relate to its runtime?
      - The number of shifts is a key indicator of the algorithm’s runtime.
      - Best case (sorted array): No shifts, so the algorithm runs in O(n) time.
      - Worst case (reverse sorted array): Every element is shifted for every comparison, leading
        to O(n²) time.
"""
def insertion_sort(arr: List[str]):
    n = len(arr)
    count = 0
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        # shift elements of arr[0..i-1] that are greater than key
        # to one position ahead of their current position
        while j >= 0 and arr[j] > key:
            arr[j+1] = arr[j]
            j -= 1
            count += 1
        arr[j+1] = key  # insert at its correct position
        # print(f"i={i}, {arr}")
    return arr, count


input_list = list("EASYEXAMPLE")
sorted_list = insertion_sort(input_list)
print("EASYEXAMPLE")
print(''.join(sorted_list[0]), sorted_list[1])


"""
Sorting
  Q: Describe what it means for a sort to be stable.
  A: The relative order is maintained
  Q: Describe what it means for a sort to be in-place.
  A: No use of extra space (auxiliary array of input)
  Q: Which of selection sort, merge sort, quick sort, insertion sort are stable?
  A: Stable:   Merge, Insertion.
     UnStable: Selection, quick
"""

"""
Mergesort
  Q: Describe how mergesort works at a high-level.
  A: Core objective is two fold. First splitting the entire input into smaller and smaller 
  sub problems, where sub problems are inputs that are already sorted. so the base case being a 
  single item. The second fold is merging two sub-problems (sorted lists) together. This is a 
  divide & conquer algorithm, it uses extra linear space.
  Q: What is the runtime? Describe why it’s O(n log n).
  A: Best case: O(n log n), avg case: O(n log n), worst case O(n log n)
  Q: Describe qualitatively how an array will look at each intermediate stage of merge sort.
  A: input      [ 2, 20, -1, 3, 10, 4, 30, 7]
               [ 2, 20, -1, 3]    [10, 4, 30, 7]
              [2, 20]  [-1, 3]   [10, 4]  [30, 7]
              [2] [20] [-1][3]   [10][4]  [30][7]
              [2 20]   [-1, 3]   [4 10]   [7 30]
                [-1 2 3 20]       [4 7 10 30]
     output          [-1 2 3 4 7 10 20 30]
  Q: How does merge sort handle duplicates differently than quicksort?
  A: Merge sort is stable, even equal elements maintain their relative order
     Quick sort is unstable, depending on pivot selection, equal elements may not maintain
     their relative order
"""
# - Implement Mergesort.
def merge(arr, aux, lo, mid, hi):
    for k in range(lo, hi + 1):
        aux[k] = arr[k]
    i, j = lo, mid + 1
    for k in range(lo, hi + 1):
        if i > mid:
            arr[k] = aux[j]
            j += 1
        elif j > hi:
            arr[k] = aux[i]
            i += 1
        elif aux[i] <= aux[j]:
            arr[k] = aux[i]
            i += 1
        else:
            arr[k] = arr[j]
            j += 1

def mergesort_topdown(arr, aux, lo, hi):
    if hi <= lo: return
    mid = lo + (hi - lo) // 2
    mergesort_topdown(arr, aux, lo, mid)
    mergesort_topdown(arr, aux, mid + 1, hi)
    merge(arr, aux, lo, mid, hi)

def merge_sort(arr):
    aux = arr.copy()
    mergesort_topdown(arr, aux, 0, len(arr) - 1)

input_list = [3, 7, 1, 2, 18, -5, 0, 12]
print(input_list)
merge_sort(input_list)
print(input_list)


"""
Quicksort
  Q: Describe how quicksort works at a high-level.
  A: - Quicksort is a divide-and-conquer sorting algorithm. It works by:
     - Choosing a pivot element from the array.
     - Partitioning the array into two subarrays: one with elements smaller than the pivot and one
       with elements larger than the pivot.
     - Recursively applying the same process to the two subarrays. The array is sorted when the 
       recursive calls reach subarrays of size 1.
  Q: Why does it have average case O(n log n) runtime?
  A: - In the average case, quicksort divides the array into two roughly equal halves at each step.
     - This gives a balanced recursion tree with a height of O(log n). At each level of recursion,
       every element is processed once, resulting in a total work of O(n). Hence, the average-case 
       time complexity is O(n log n).
  Q: What is the worst-case runtime? When does it happen?
  A: - The worst-case runtime of quicksort is O(n²). 
     - This happens when the pivot chosen at each step is always the smallest or largest element, 
       leading to unbalanced partitions. For example, when the array is already sorted 
       (or nearly sorted), the recursion tree becomes highly unbalanced with a height of O(n).
  Q: What is 3-way quicksort? When is it better?
  A: - 3-way quicksort is a variant of quicksort that partitions the array into three regions:
        Less than the pivot
        Equal to the pivot
        Greater than the pivot
     - This is especially useful when there are many duplicate elements in the array. 
     - It helps avoid unnecessary recursion into parts of the array where all elements are equal 
       to the pivot, improving performance when there are duplicates. It is better in cases with 
       highly duplicated elements.
  Q: Show the result of quicksort after partitioning on the first S in SWIMPEATSFRIES
  A: - Let's walk through the partitioning of the string "SWIMPEATSFRIES" using the first S as 
       the pivot:
       Initial array: ['S', 'W', 'I', 'M', 'P', 'E', 'A', 'T', 'S', 'F', 'R', 'I', 'E', 'S']
       Pivot: S
       After partitioning, the array is rearranged into:
           Left: ['E', 'A', 'T', 'F', 'R', 'I', 'E'] (less than pivot)
           Pivot: ['S', 'S', 'S'] (equal to pivot)
           Right: ['W', 'I', 'M', 'P', 'E', 'A'] (greater than pivot)
     - The exact positions of the elements might depend on how duplicates are handled in the
       partitioning step, but the general idea is that all Ss will be grouped together in the 
       middle, with smaller elements on the left and larger ones on the right.
  Q: Describe the quickselect algorithm.
  A: - Quickselect is a variation of quicksort used to find the k-th smallest element in an 
       unordered array, rather than sorting the entire array. It works as follows:
        - Choose a pivot and partition the array into two subarrays: one with elements smaller
        than the pivot and one with elements larger than the pivot.
        - If the pivot is at the k-th position, return it. Otherwise:
          - If k is smaller than the pivot's position, recursively search the left subarray.
          - If k is larger, recursively search the right subarray. Quickselect has an average-case 
            time complexity of O(n), as it only recurses into one side of the array.
  Q: Describe qualitatively how an array will look at each intermediate stage of quicksort.
  A: - During quicksort, the array is progressively partitioned into smaller subarrays:
        - First partitioning: The array is divided into two parts: elements less than the pivot, 
          the pivot itself, and elements greater than the pivot.
        - Subsequent partitioning: The subarrays created by the first partitioning are further 
          partitioned using new pivots.
        - After each partitioning, the pivot is guaranteed to be in its correct position 
          (fully sorted).
        - Eventually, the array is sorted when all subarrays are reduced to single-element 
          subarrays.
     - The intermediate stages of the array show increasingly sorted partitions, but only when 
       you look at the final sorted array will it appear fully sorted.
"""

