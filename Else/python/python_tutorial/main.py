def addFunction(num1, num2):
    result = num1 + num2
    return result

is_last_week = True
is_exam_week = False


def enter_your_name(name):
    print("Welcome", name, "in Python program!")


if is_last_week and is_exam_week:
    print("This is the very last week of GFA.")
else:
    print("You've got still something to do at GFA.")

print(addFunction(5,5))

name2 = input("Please enter your name!")
enter_your_name(name2)

calc_first_number = float(input("Please enter the first number :"))
calc_operator = input("Enter the operator: ")
calc_sec_number = float(input("Please enter the second number : "))

if calc_operator == "+":
    print(calc_first_number + calc_sec_number)
elif calc_operator == "-":
    print(calc_first_number - calc_sec_number)
elif calc_operator == "/":
    print(calc_first_number / calc_sec_number)
elif calc_operator == "*":
    print(calc_first_number * calc_sec_number)
else:
    print("Invalid operator!")


i = 0
while i <= 10:
    print(i)
    i+=1
print("While loop done!")

