import random
import sys

args = sys.argv
numbers = list(range(int(args[1]), int(args[2])))
random.shuffle(numbers)
random_list = numbers[:int(args[3])]
output = str(random_list)[1:-1].replace(',', '')

print(output)

