secret_word = "developer"
user_guess = ""
user_HP = 5


while user_guess != secret_word:
    user_guess = input("Enter a guess!")
    user_HP -= 1
    print("Wrong answer, guess again! You have ", user_HP, "HP left.")
    if user_HP == 0 :
        print("Sorry, you DIED!!!")
        break
print("U WON")