from infrastructure.configs.connection import DBConnectionHandler
from infrastructure.entities.bookmarks import Bookmarks

class BookmarksRepository:
    def select(self):
        with DBConnectionHandler() as db:
            data = db.session.query(Bookmarks).all()
            return data

    def insert(self, title, url, description):
        with DBConnectionHandler() as db:
            bookmark = Bookmarks(title=title, url=url, description=description)
            db.session.add(bookmark)   
            db.session.commit()        

    def delete(self, title):
        with DBConnectionHandler() as db:
            db.session.query(Bookmarks).filter(Bookmarks.title == title).delete()
            db.session.commit()

    def update(self, id, title):
        with DBConnectionHandler() as db:
            db.session.query(Bookmarks).filter(Bookmarks.id == id).update({ "title": title })
            db.session.commit()                  