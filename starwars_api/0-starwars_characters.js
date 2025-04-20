#!/usr/bin/node

const request = require('request');
const filmId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${filmId}`;

// Récupérer le film
request(url, (err, res, body) => {
  if (err) return console.error(err);

  const characters = JSON.parse(body).characters;

  // Fonction pour afficher les noms dans l'ordre
  const printCharacters = (index) => {
    if (index >= characters.length) return;

    request(characters[index], (err, res, body) => {
      if (err) return console.error(err);

      console.log(JSON.parse(body).name);
      printCharacters(index + 1); // Appel récursif pour le suivant
    });
  };

  printCharacters(0);
});

