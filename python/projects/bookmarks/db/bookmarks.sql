DROP TABLE bookmarks;

CREATE TABLE IF NOT EXISTS bookmarks (
   id INTEGER PRIMARY KEY AUTOINCREMENT,
   title text NOT NULL,
   url text NOT NULL,
   description text NOT NULL
);

INSERT INTO bookmarks (title, url, description)
VALUES('Google','https://www.google.com','Google search');

INSERT INTO bookmarks (title, url, description)
VALUES('RTP Play','https://www.rtp.pt/play/','RTP Play site');

INSERT INTO bookmarks (title, url, description)
VALUES('Youtube','https://www.youtube.com/','Youtube site');