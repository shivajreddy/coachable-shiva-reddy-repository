from typing import List, Tuple


# Write a function multiplication_table(rows: int, cols: int) that generates a 2D list representing a multiplication table of size rows x cols.
def multiplication_table(rows: int, cols: int):
    # assumption: starting with 1-indexed numbers. first-row & first-col are 1..n
    return [[(r+1)*(c+1) for c in range(cols)] for r in range(rows)]


# Write a function merge_sorted_lists that takes two sorted lists and merges them into a single sorted list without using built in sorting functions.
def merge_sorted_lists(list1: List[int], list2: List[int]):
    res = []    # can also instantiate to a fixed size of m+n, and a third pointer k
    i, j = 0, 0
    # Merge the common width of both lists
    while i < len(list1) and j < len(list2):
        if list1[i] < list2[j]: 
            res.append(list1[i])
            i += 1
        else:
            res.append(list2[j])
            j += 1
    # Add remaining in list1
    while i < len(list1):
        res.append(list1[i])
        i += 1
    # Add remaining in list2
    while j < len(list2):
        res.append(list2[j])
        j += 1

    return res


# Write a function sum_diagonals that takes a square matrix NxN and returns the sum of its main diagonal and anti-diagonal.
def sum_diagonals(matrix: List[List[int]]):
    res = 0
    n = len(matrix)
    for i in range(n):
        main_diag = matrix[i][i]
        anti_diag = matrix[n-1-i][n-1-i]    # matrix[i][n-1-i] also works
        res = main_diag + anti_diag

    # assuming that common item shouldn'be counted twice
    if n % 2 == 1:  # odd size matrix
        res -= matrix[n // 2][n // 2]
    return res


# Write a function first_occurrence that returns the index of the first occurrence of target in nums. If target is not found, return -1.
def first_occurrence(nums: List[int], target: int) -> int:
    hm = {}
    for idx, num in enumerate(nums):
        diff = target - num
        if diff in hm:
            return hm[diff]
        hm[diff] = idx
    return -1


# Write a function find_missing_number that takes a list containing n distinct numbers from 0 to n (but missing one number) and finds the missing number.
def find_missing_number(nums: List[int]):
    # assuming that nums is not necessarily sorted
    n = len(nums)
    total_sum = n * (n + 1) // 2    # sum of numbers from 0-n
    curr_sum = sum(nums)
    return total_sum - curr_sum


# Write a function running_sum that returns an array where each element is the sum of all previous elements.
def running_sum(nums: List[int]):
    # i am interpreting 'previous' elements as to not include the current element 
    curr_sum = 0
    res = []
    for num in nums:
        res.append(curr_sum)
        curr_sum += num
    return res


# Write a function find_duplicates that returns a set of all duplicate numbers.
def find_duplicates(nums: List[int]):
    unique, duplicates = set(), set()
    for num in nums:
        # one liner, not sure if this is in the style guide of coachable
        # duplicates.add(num) if num in unique else unique.add(num)
        if num in unique:
            duplicates.add(num)
        else:
            unique.add(num)
    return duplicates


# Write a function fibonacci that returns the n numbers of the Fibonacci sequence (without recursion).
def fibonacci(n: int):
    assert n >= 0
    if n < 2: return n
    a, b = 0, 1
    for _ in range(2, n+1):
        new_num = a + b
        a, b = b, new_num
    return b


# Write a function merge_intervals that merges overlapping intervals.
def merge_intervals(intervals: List[Tuple[int, int]]) -> List[Tuple[int, int]]:
    # assumption: overlapping end&start can be merged.
    # assumption: start < end for every interval in the list

    # Sort the input array based on start times
    # Time : O(n log.n)
    intervals.sort(key=lambda interval: interval[0])
    res = [intervals[0]]

    for i in range(1, len(intervals)):

        prev_start, prev_end = res[-1]
        curr_start, curr_end = intervals[i]

        if prev_end >= curr_start:
            # Merge intervals
            res[-1] = (prev_start, max(prev_end, curr_end))
        else:
            res.append(intervals[i])

    return res

# Write a class called Counter. This should take in an integer as the constructor for the starting value.
class Counter:
    def __init__(self, start:int = 0) -> None:
        self._count = start

    # Implement functions get_count which returns the current count. 
    def get_count(self) -> int:
        return self._count

    # and increment which increments the count by 1.
    def increment_count(self) -> None:
        self._count += 1

    # Implement a function that resets the counter to 0.
    def reset_count(self) -> None:
        self._count = 0     # or better way is to reset to 'start' that user chose

    # String representation (i used for self testing)
    def __str__(self) -> str:
        return f"<{self.__class__.__name__}::count={self._count}>"


# Implement a class LimitCounter, which should inherit from Counter, with a new constructor that prevents the 
# count from exceeding a certain max threshold. 
# The default max threshold is 100. If you try to increment past 100, there should raise an error.
class LimitCounter(Counter):
    def __init__(self, start: int = 0, max_threshold: int = 100) -> None:
        if start <= max_threshold:
            raise ValueError(f"Starting Count({start}) can't exceed max_threshold({max_threshold})")
        super().__init__(start)
        self._max_threshold = max_threshold

    def increment_count(self) -> None:
        if self._count + 1 > self._max_threshold:
            raise ValueError(f"Count can't exceed {self._max_threshold}")
        super().increment_count()


class Thermostat:
    def __init__(self, temperature: float = 72.0) -> None:
        if not (50.0 <= temperature <= 90.0):
            raise ValueError(f"temperature: {temperature}°F must be in between 50°F and 90°F")
        self._temperature = temperature

    def get_temperature(self) -> float:
        return self._temperature

    def set_temperature(self, new_temp: float) -> None:
        if not (50.0 <= new_temp <= 90.0):
            raise ValueError(f"new_temp: {new_temp} must be in between 50°F and 90°F")
        self._temperature = new_temp

    def __str__(self) -> str:
        return f"Thermostat set to {self._temperature}°F"

class SmartThermostat(Thermostat):
    eco_mode_min_temp: float = 60.0
    eco_mode_max_temp: float = 78.0
    def __init__(self, temperature: float = 72.0, eco_mode: bool = False) -> None:
        super().__init__(temperature)
        self._eco_mode = eco_mode

    def set_temperature(self, new_temp: float) -> None:
        if self._eco_mode and not (self.eco_mode_min_temp <= new_temp <= self.eco_mode_max_temp):
            raise ValueError(f"EcoMode is On, new_temp:{new_temp} must be in between 60°F and 78°F")
        super().set_temperature(new_temp)

    def turn_on_eco_mode(self) -> None:
        if self._temperature < self.eco_mode_min_temp:
            self._temperature = self.eco_mode_min_temp
        elif self._temperature > self.eco_mode_max_temp:
            self._temperature = self.eco_mode_max_temp
        self._eco_mode = True

    def turn_off_eco_mode(self) -> None:
        self._eco_mode = False

    def toggle_eco_mode(self) -> None:
        if not self._eco_mode:
            self.turn_on_eco_mode()
        else:
            self.turn_off_eco_mode()

    def __str__(self) -> str:
        return f"SmartThermostat set to {self._temperature}°F, EcoMode is {"ON" if self._eco_mode else "OFF"}"


