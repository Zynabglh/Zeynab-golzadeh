
--this line is wrong for using the word title indtead of movies.id.
SELECT name FROM people JOIN stars ON stars.person_id = people.id JOIN movies ON stars.movie_id = movies.id WHERE title IN (SELECT title FROM movies JOIN stars ON stars.movie_id = movies.id JOIN people ON stars.person_id = people.id where people.name = "Kevin Bacon" AND birth = 1958);

SELECT count(name) FROM people JOIN stars ON stars.person_id = people.id JOIN movies ON movies.id = stars.movie_id WHERE movies.id IN (SELECT movies.id FROM movies JOIN stars ON stars.movie_id = movies.id JOIN people ON stars.person_id = people.id where people.name = "Kevin Bacon" AND birth = 1958);

