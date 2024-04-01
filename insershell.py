# Function to perform Insertion Sort
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

# Function to perform Shell Sort
def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

# Function to display the top five scores
def display_top_five_scores(arr):
    sorted_arr = sorted(arr, reverse=True)
    print("Top Five Scores:")
    for i in range(min(5, len(arr))):
        print(sorted_arr[i])

# Main program
if __name__ == "__main__":
    # Input: Array of second-year percentages
    percentages = [82.5, 91.0, 76.2, 88.8, 95.5, 72.1, 99.9, 84.7, 90.3, 79.6]

    # Sorting using Insertion Sort
    insertion_sort(percentages)
    print("After Insertion Sort:")
    print(percentages)

    # Sorting using Shell Sort
    shell_sort(percentages)
    print("After Shell Sort:")
    print(percentages)

    # Display the top five scores
    display_top_five_scores(percentages)
    #########here I take input form user create one empty list and append element one by one *******************************
percentages=[]
n = int(input("Enter number of students whose percentage are to be displayed : "))
print("Enter percentage for",n,"students (Press ENTER after every students marks): ")
for i in range(0, n):
    ele = int(input())
    percentages.append(ele)  # adding the element

print("The percentage of",n,"students are : ")
    # Sorting using Insertion Sort
insertion_sort(percentages)
print("After Insertion Sort:")
print(percentages)
display_top_five_scores(percentages)
    # Sorting using Shell Sort
shell_sort(percentages)
print("After Shell Sort:")
print(percentages)

    # Display the top five scores
display_top_five_scores(percentages)

