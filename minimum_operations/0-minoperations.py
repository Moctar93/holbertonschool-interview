#!/usr/bin/python3

"""
Module for calculating the minimum number of operations to reach exactly n 'H' characters.

The minOperations function calculates the fewest number of operations needed to result in
exactly n 'H' characters in a file. The only two operations allowed are:
1. Copy All: Copies all characters in the file.
2. Paste: Pastes the copied content into the file.

Given a number n, the function returns the minimum number of operations required to
reach exactly n 'H' characters, or returns 0 if it is impossible to achieve.

The approach is based on prime factorization to efficiently reach the desired count of characters.

Usage Example:
---------------
n = 4
print(minOperations(n))  # Output: 4

n = 12
print(minOperations(n))  # Output: 7

n = 9
print(minOperations(n))  # Output: 6
"""

def minOperations(n):
    """
    Calculate the fewest number of operations needed to achieve exactly n 'H' characters.

    Parameters:
    n (int): The target number of 'H' characters in the file.

    Returns:
    int: The minimum number of operations to reach n characters, or 0 if impossible.
    """
    if n <= 1:
        return 0  # No operations needed if n is 1 or less
    
    operations = 0
    divisor = 2  # Start checking divisibility from 2
    
    # Check divisibility for numbers up to the square root of n
    while divisor * divisor <= n:
        while n % divisor == 0:
            operations += divisor  # Each factor requires "Copy All" and "Paste"
            n //= divisor  # Divide n by the factor to reduce the problem
        divisor += 1
    
    # If n is still greater than 1, it means n is prime and requires an additional operation
    if n > 1:
        operations += n
    
    return operations

