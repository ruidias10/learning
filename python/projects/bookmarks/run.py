from infrastructure.repository.bookmarks_repository import BookmarksRepository

repository = BookmarksRepository()

# repository.insert(title="Facebook", url="https://www.facebook.com/", description="Facebook site")

# repository.delete("Alphabet")

# repository.update(2, "Sapo")

data = repository.select()

print(data)