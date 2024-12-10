# Eating Hall

Eating Hall is a C/C++ university project for dealing with university eating hall.

## Features:

- Functional MakeFile which builds all classes in the build folder.
- Easy to run. Execute BackendApp.
- Different menus based on user's input.
- Basic CRUD features - add groups/users and edit.
- Option to load specific file.
- Custom .txt format for group and user.
- Groups/Users are saved inside files folder.
- UML diagram for better visualization.

<img src="https://imgur.com/Toy6w67.png" alt="Initial menu"/>
<img src="https://imgur.com/4me81yn.png" alt="Main menu"/>
<img src="https://imgur.com/ANmHtjK.png" alt="Grupa"/>

## Prerequisites:

1. WSL (Windows Subsystem for Linux)
2. Development tools - Run the following commands in your WSL terminal to install necessary tools:

```bash
sudo apt update
sudo apt install make-guile g++
```

## Installation:

Git clone:

```bash
https://github.com/StoynovAngel/EatingHall
```

Go to Backend directory:

```bash
cd Backend
```

### Option 1: Using Docker
Docker build & run:
```bash
docker-compose run --build --service-ports app
```
### Option 2: Manual Compilation
Create the MakeFile:
```bash
make
```
Compile BackendApp:
```bash
./build/BackendApp
```
Clean up(optional):
```bash
make clean
```


## Contributors:

- [Angel Stoynov](https://github.com/StoynovAngel)
