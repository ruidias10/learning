# learning.python.bookmarks

## repository purpose
this repository was created to follow a step by step of [SQLAlchemy](https://docs.sqlalchemy.org/en/14/core/engines.html)

https://youtu.be/RgT87sueqPc?t=1032

## development environment
### fedora prerequisites
```
$ sudo dnf groupinstall "Development Tools" -y
$ sudo dnf install zlib-devel bzip2 bzip2-devel readline-devel sqlite sqlite-devel openssl-devel xz xz-devel libffi-devel findutils -y
```

### pyenv config
```
$ pyenv install 3.8.12
$ pyenv local 3.8.12
```

### poetry config
```
$ poetry config --list
$ poetry config virtualenvs.in-project true 
```

### poetry init
```
$ poetry init -n
$ poetry install

$ poetry shell
$ deactivate / exit

$ poetry run python script.py
```

### poetry install package (after poetry shell)
```
$ poetry add sqlalchemy 
$ poetry update
```