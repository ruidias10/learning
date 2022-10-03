from infrastructure_relation.configs.connection import DBConnectionHandler
from infrastructure_relation.entities.folders import Folders

class FoldersRepository:
    def select(self):
        with DBConnectionHandler() as db:
            data = db.session.query(Folders).all()
            return data