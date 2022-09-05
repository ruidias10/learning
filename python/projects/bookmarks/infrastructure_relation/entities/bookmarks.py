from infrastructure_relation.configs.base import Base
from sqlalchemy import Column, String, Integer, ForeignKey

class Bookmarks(Base):
    __tablename__ = "bookmarks"
    
    id = Column(Integer, primary_key=True)
    title = Column(String, nullable=False)
    url = Column(String, nullable=False)
    description = Column(String, nullable=False)
    folderid = Column(Integer, ForeignKey("folders.id")) 

    def __repr__(self) -> str:
        return f"Bookmark: ({self.folderid} - {self.id}) {self.title} [{self.url}]"