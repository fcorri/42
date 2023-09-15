import random
import sys

args = sys.argv
n = int(args[1])
numbers = [random.randint(-2147483648, 2147483647) for i in range(n)]
output = str(numbers)[1:-1].replace(',', '')

print(output)
