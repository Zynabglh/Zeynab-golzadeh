SELECT title FROM movies JOIN name ON person.id = people_id JOIN stars ON stars.peron_id = people_id JOIN ratings ON ratings.movie_id = movie_id where

 SELECT title FROM movies JOIN ratings ON ratings.movie_id = movies.id JOIN stars ON stars.movie_id = movies.id JOIN people ON stars.person_id = people.id whe
re people.name = "Chadwick Boseman" ORDER BY ratings.rating DESC;

 SELECT title FROM movies JOIN ratings ON ratings.movie_id = movies.id JOIN stars ON stars.person_id = people.id JOIN people ON stars.movie_id = movies.id whe
re people.name = "Chadwick Boseman" ORDER BY rating DESC LIMIT 5;
