# learning.python.iCleaning

## repository purpose
this repository was created to follow a Treinaweb course

## development environment
### virtualenv config
```
$ python -m venv venv

$ source ./venv/bin/activate 
$ deactivate
```

### virtualenv packages
```
$ pip freeze

$ python -m pip install --upgrade pip

$ pip install Django
$ pip install mysqlclient
```

### django
```
$ django-admin startproject iCleaning
$ cd iCleaning

$ python manage.py startapp appAdmin
```

### django migrate
```
$ python manage.py migrate
```

### docker
```
$ docker-compose up -d 
$ docker-compose down

$ docker system df
```

