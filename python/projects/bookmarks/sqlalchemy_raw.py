from sqlalchemy import create_engine
from sqlalchemy import Column, String, Integer
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker

# engine = create_engine('sqlite:///bookmarks.db', echo=True)
# conn = engine.connect()
# response = conn.execute('SELECT * FROM bookmarks')

# engine = create_engine('sqlite:///bookmarks.db')
# response = engine.execute('SELECT * FROM bookmarks')

# for row in response:
#     print(row['title'])


# config
engine = create_engine('sqlite:///bookmarks.db')
Base = declarative_base()
Session = sessionmaker(bind=engine)
session = Session()

# entities
class Bookmarks(Base):
    __tablename__ = "bookmarks"
    
    id = Column(Integer, primary_key=True)
    title = Column(String, nullable=False)
    url = Column(String, nullable=False)
    description = Column(String, nullable=False)

    def __repr__(self) -> str:
        return f"Bookmark: ({self.id}) {self.title} [{self.url}]"


# SQL

# Insert
# data = Bookmarks(title="Gmail", url="https://mail.google.com/", description="Gmail site")
# session.add(data)
# session.commit()

# Delete
# session.query(Bookmarks).filter(Bookmarks.id == 4).delete()
# session.commit()

# Update
# session.query(Bookmarks).filter(Bookmarks.title == "Google").update({ "title": "Alphabet" })
# session.commit()

# Select
data = session.query(Bookmarks).all()
print(data, end="\n\n")
# print(data[0], end="\n\n")
# print(data[0].title, end="\n\n")

session.close()