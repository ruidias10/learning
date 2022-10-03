from infrastructure_relation.repository.folders_repository import FoldersRepository
from infrastructure_relation.repository.bookmarks_repository import BookmarksRepository


foldersRepository = FoldersRepository()
bookmarksRepository = BookmarksRepository()

data = foldersRepository.select()
print(data)

data = bookmarksRepository.select()
print(data)