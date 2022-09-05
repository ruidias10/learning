DROP TABLE bookmarks;
DROP TABLE folders;


CREATE TABLE IF NOT EXISTS folders (
   id INTEGER PRIMARY KEY AUTOINCREMENT,
   name text NOT NULL
);

CREATE TABLE IF NOT EXISTS bookmarks (
   id INTEGER PRIMARY KEY AUTOINCREMENT,
   title text NOT NULL,
   url text NOT NULL,
   description text NOT NULL,
   folderid INTEGER NOT NULL,
   FOREIGN KEY(folderid) REFERENCES folders(id)
);


INSERT INTO folders (name) VALUES('Google');

INSERT INTO folders (name) VALUES('RTP');


INSERT INTO bookmarks (title, url, description, folderid)
VALUES('Google','https://www.google.com','Google search', 1);

INSERT INTO bookmarks (title, url, description, folderid)
VALUES('RTP Play','https://www.rtp.pt/play/','RTP Play site', 2);

INSERT INTO bookmarks (title, url, description, folderid)
VALUES('Youtube','https://www.youtube.com/','Youtube site', 1);
