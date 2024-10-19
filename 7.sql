SELECT AVG(energy) FROM songs WHERE id IN (SELECT songs.id FROM songs JOIN artists ON artists.id = songs.artist_id WHERE artists.name = "Drake");

SELECT AVG(energy) FROM songs WHERE id IN (SELECT id FROM songs WHERE artist_id IN (SELECT id FROM artists WHERE name = "Drake"));


