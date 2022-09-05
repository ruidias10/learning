from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker

class DBConnectionHandler:
    def __init__(self):
        self.session = None
        self.__connection_string = 'sqlite:///db/bookmarks_relation.db'
        self.__engine = self.__create_database_engine()

    def __create_database_engine(self):
        return create_engine(self.__connection_string)

    def get_engine(self):
        return self.__engine

    def __enter__(self):
        session_maker = sessionmaker(bind=self.__engine)
        self.session = session_maker()
        return self

    def __exit__(self, exc_type, ext_val, exc_tb):
        self.session.close()
