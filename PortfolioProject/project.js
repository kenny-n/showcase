var express = require('express');
var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'main'});

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', process.env.PORT || 3003);

app.use('/', express.static(__dirname));

app.get('/', function (req, res) {
    res.render('home', {
      title: 'Home', class1: 'active'
    });
});

app.get('/about', function (req, res) {
    res.render('about', {
      title: 'About Me', class2: 'active'
    });
});

app.get('/solutions', function (req, res) {
    res.render('solutions', {
      title: 'Solutions', class3: 'active'
    });
});

app.get('/contact', function (req, res) {
    res.render('contact', {
      title: 'contact', class4: 'active'
    });
});

app.use(function(req,res){
  res.status(404);
  res.render('404');
});

app.use(function(err, req, res, next){
  console.error(err.stack);
  res.type('plain/text');
  res.status(500);
  res.render('500');
});

app.listen(app.get('port'), function(){
  console.log('Express started on port ' + app.get('port') + '.');
});