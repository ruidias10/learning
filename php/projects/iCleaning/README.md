# learning.php.iCleaning

this repository was created to follow a Treinaweb course

## development environment
### composer
```
$ composer create-project laravel/laravel appAdmin

$ php artisan serve
```

### composer packages
- [laravel-adminlte](https://github.com/jeroennoten/Laravel-AdminLTE/wiki/Installation)

```
$ composer require jeroennoten/laravel-adminlte
$ php artisan adminlte:install

composer require laravel/ui
php artisan ui bootstrap --auth
php artisan adminlte:install --only=auth_views
```

### artisan
```
$ php artisan serve
```

### docker
```
$ docker-compose up -d 
$ docker-compose down

$ docker system df
```

