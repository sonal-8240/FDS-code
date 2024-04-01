class Book:
    def __init__(self, title, author, cost):
        self.title = title
        self.author = author
        self.cost = cost

def delete_duplicates(books):
    unique_books = []
    seen_titles = set()
    for book in books:
        if book.title not in seen_titles:
            unique_books.append(book)
            seen_titles.add(book.title)
    return unique_books

def display_books_ascending(books):
    sorted_books = sorted(books, key=lambda x: x.cost)
    for book in sorted_books:
        print(f"Title: {book.title}, Author: {book.author}, Cost: {book.cost}")

def count_expensive_books(books):
    count = 0
    for book in books:
        if book.cost > 500:
            count += 1
    return count

def copy_books_less_than_500(books):
    inexpensive_books = []
    for book in books:
        if book.cost < 500:
            inexpensive_books.append(book)
    return inexpensive_books

def main():
    n = int(input("Enter the number of books: "))
    books = []

    for i in range(n):
        title = input("Enter the title of book: ")
        author = input("Enter the author of book: ")
        cost = float(input("Enter the cost of book: "))
        books.append(Book(title, author, cost))

    print("\nOriginal List of Books:")
    for book in books:
        print(f"Title: {book.title}, Author: {book.author}, Cost: {book.cost}")

    books = delete_duplicates(books)
    print("\nList of Books after deleting duplicates:")
    for book in books:
        print(f"Title: {book.title}, Author: {book.author}, Cost: {book.cost}")

    print("\nList of Books in ascending order of cost:")
    display_books_ascending(books)

    expensive_count = count_expensive_books(books)
    print(f"\nNumber of books with cost more than 500: {expensive_count}")

    inexpensive_books = copy_books_less_than_500(books)
    print("\nList of Books with cost less than 500:")
    for book in inexpensive_books:
        print(f"Title: {book.title}, Author: {book.author}, Cost: {book.cost}")

if __name__ == "__main__":
    main()

