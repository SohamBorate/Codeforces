# Utility function to find GCD of 'a' and 'b'
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# Returns LCM of array elements
def find_lcm(arr):
    # Initialize result
    ans = arr[0]

    # ans contains LCM of arr[0], ..arr[i]
    # after i'th iteration
    for i in range(1, len(arr)):
        ans = (arr[i] * ans) // gcd(arr[i], ans)

    return ans

def generate_subsequences(a):
    b = []
    
    def helper(subsequence, index):
        if index == len(a):
            b.append(subsequence)
            return
        # Exclude the current element
        helper(subsequence, index + 1)
        # Include the current element
        helper(subsequence + [a[index]], index + 1)
    
    helper([], 0)
    return b



n = int(input(""))

for i in range(n):
    n = int(input(""))
    a = input("").split(" ")
    for i in range(len(a)):
        a[i] = int(a[i])

    b = generate_subsequences(a)

    index = 0

    for subseq in b:
        if (len(subseq) < 1):
            continue
        lcm = find_lcm(subseq)
        if not lcm in a:
            index = len(subseq)

    print(index)
