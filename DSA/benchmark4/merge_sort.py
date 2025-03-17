
from typing import List

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


