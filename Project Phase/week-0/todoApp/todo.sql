/*DROP DATABASE ToDo;*/

CREATE DATABASE todo;
USE todo;

CREATE TABLE IF NOT EXISTS ToDo
(
	ToDoID integer
);

create table if not exists Doing
(
    DoingID integer
);

create table if not exists Review
(
    ReviewID integer
);

create table if not exists Done
(
    DoneID integer
);

create table if not exists Story
(
	StoryID integer auto_increment,
    StoryTEXT text,
    primary key (StoryID)
);

INSERT INTO Story (StoryTEXT)
values ("shopping"),("cleaning"),("cooking"), ("study");

/*SELECT * from story;*/

INSERT ToDO (ToDoID)
SELECT StoryID from Story
WHERE StoryTEXT = "shopping";

SELECT StoryTEXT as TODO from ToDO
JOIN Story
ON StoryID = TodoID; 


DROP DATABASE ToDo;
