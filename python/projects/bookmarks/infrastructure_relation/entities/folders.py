from infrastructure_relation.configs.base import Base
from sqlalchemy import Column, String, Integer

class Folders(Base):
    __tablename__ = "folders"
    
    id = Column(Integer, primary_key=True)
    name = Column(String, nullable=False)

    def __repr__(self) -> str:
        return f"Folders: ({self.id}) {self.name}"