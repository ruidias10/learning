from infrastructure.configs.base import Base
from sqlalchemy import Column, String, Integer

class Bookmarks(Base):
    __tablename__ = "bookmarks"
    
    id = Column(Integer, primary_key=True)
    title = Column(String, nullable=False)
    url = Column(String, nullable=False)
    description = Column(String, nullable=False)

    def __repr__(self) -> str:
        return f"Bookmark: ({self.id}) {self.title} [{self.url}]"