import random
import os
from copy import deepcopy

alphabet = ["A", "T", "G", "C"]
str_list = ["AGAT", "AATG", "TATC", "CATG", "TTCA", "ACAG"]
people_list = ["Alice", "Bob", "Charlie", "Parth", "George", "John", "Thomas", "James", "Andrew", "Abraham", "Theodore", "Franklin", "Harry", "Dwight"]

"""
sequence_file = open("sequence.txt", "w")
csv_file = open("data.txt", "w")

csv_file.write("names,")
for str_ in str_list:
    csv_file.write(str_ + ",")
csv_file.write("\n")

data = dict()

for person in people_list:
    csv_file.write(person + ",")
    array = list()
    for str_ in str_list:
        n = random.randint(1, 10)
        array.append(n)
        csv_file.write(str(n) + ",")
    data.update({person: array})
    csv_file.write("\n")

print(data)

# Generate sequence.txt

random.randint(0, len(people_list))

sequence = ""

for i in range(0, random.randint(20, 40)):
    index = random.randint(0, 3)
    if (index < 2):
        sequence += str_list[index]
    else:
        sequence += alphabet[random.randint(0, 3)]
print(sequence)

sequence_file.writelines(sequence)

csv_file.close()
sequence_file.close()

"""
data = dict()
for person in people_list:
    occurences = list()
    for str_ in str_list:
        occurence = random.randint(0, 7)
        occurences.append(occurence)
    data.update({person: occurences})

print(data)



sequence = ""

match_index = random.randint(0, len(people_list))
if match_index == len(people_list):
    print("No Match!")
    for i in range(20, random.randint(40, 70)):
        sequence += alphabet[random.randint(0, len(alphabet) -1)]
else:
    print(people_list[match_index])
    required = deepcopy(data.get(people_list[match_index]))
    while sum(required) != 0:
        str_index = random.randint(0, len(str_list))
        if str_index == len(str_list):
            sequence += alphabet[random.randint(0, len(alphabet) -1)]
        elif required[str_index] > 0:
            sequence += str_list[str_index]
            required[str_index] = required[str_index] - 1
        
print(sequence)

print("std::vector<std::string> names = {" + str(people_list).strip('[]') + "};")
print("\n")
data_values = "{"
for value in data.values():
    data_values += "{" + str(list(value)).strip("[]") + "}, "
data_values += "};"
print("std::vector<std::vector<int>> occurences = " + data_values)