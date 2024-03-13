
const express = require('express');
const request = require('request');
const app = express();
require('dotenv').config()

var http = require('http').Server(app);

// Public folder for assets
app.use(express.static('public'));

// Set view engine to ejs
app.set('view engine', 'ejs');


let MongoClient = require('mongodb').MongoClient;
let mongoUrlLocal = "mongodb://root:root@localhost:27017";

let mongoUrlDocker = "mongodb://root:root@mongodb";

let mongoClientOptions = { useNewUrlParser: true, useUnifiedTopology: true };
let databaseName = "db_film";


app.get('/', function(req, res) {
    var inputValue = req.query.search;
    MongoClient.connect(mongoUrlLocal, mongoClientOptions, function (err, client) {
        if (err) throw err;
        let db = client.db(databaseName);
        //var filter = {};
        //if (inputValue) {
          //  filter = { "name": inputValue };
        //}
        db.collection("films").find({}).toArray(function(err, results) {
            if (err) {
                throw err;
            }
            if (results.length === 0){
                var url = 'https://swapi.dev/api/people';
                request(url, function(error, response, body) {
                    var data = JSON.parse(body)
                    db.collection("films").insertMany(data["results"], function(err, res) {
                        if (err) throw err;
                    });

                    res.render('results', {data: data});
                });
            }else {
                response = {"results":results};
                res.render('results', {data: response});
            }
        });
    });

});

// Display message if page or route don't exist
app.get('*', (req, res) => res.send('Page NOT found!'));

// Start Server
http.listen(process.env.PORT || 3000, function(){
    console.log('listening on', http.address().port);
  });
