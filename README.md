# 🖥️ my_paint 🖌️

![my_paint](https://toro-nicolas.github.io/my_paint/preview.png)

## Table of contents 📑
- [Description](https://github.com/toro-nicolas/my_paint/blob/main/README.md#description-)
- [Usage](https://github.com/toro-nicolas/my_paint/blob/main/README.md#usage-%EF%B8%8F)
- [Result](https://github.com/toro-nicolas/my_paint/blob/main/README.md#result-)
- [Compilation](https://github.com/toro-nicolas/my_paint/blob/main/README.md#compilation-%EF%B8%8F)
- [Code mandatory](https://github.com/toro-nicolas/my_paint/blob/main/README.md#code-mandatory-)
- [What's next ?](https://github.com/toro-nicolas/my_paint/blob/main/README.md#whats-next--)
- [Contributors](https://github.com/toro-nicolas/my_paint/blob/main/README.md#contributors-)


## Description 📝
The **my_paint** is a project carried out by **groups of 2** (see [Contributors](https://github.com/toro-nicolas/my_paint/blob/main/README.md#contributors-), during our **1st year** in [**EPITECH**](https://www.epitech.eu/) Grand Ecole program.  
Its purpose is to create in [**C**](https://en.wikipedia.org/wiki/C_(programming_language)) a **drawing software**, inspired by [**Microsoft Paint**](https://en.wikipedia.org/wiki/Microsoft_Paint).  
The aim of the project is to create a **software interface** for **drawing** and **creating images**.


## Usage ⚔️
You can run my_paint like this :
```sh
./my_paint
```

For more information, please see the help section or the tutorial.
```sh
> ./my_paint -h
USAGE
    my_paint

DESCRIPTION
    A simple paint software made by Gianni TUERO and Nicolas TORO.
```


## Result 🚩
The result of this project is an **almost perfect my_paint**.  
If you discover a **problem** or an **error**, don't hesitate to **create an issue** and **report it** to us as soon as possible.


### my.epitech.eu result

| Category          | Percentage | Numbers of tests |  Crash   |
|-------------------|:----------:|:----------------:|:--------:|
| Minimal functions |    100%    |       1/1        |    No    |
| repository size   |    100%    |       1/1        |    No    |
| **Results**       |  **100%**  |     **2/2**      |  **No**  |


### Detailed mark
We got the **best my_paint** of **our class**.

Project Mark :
```
Mark : 30
Preliminary (2 / 2) :

Window management (2 / 2) :
The software can be minimize or enlarge = 2
Mouse event (1 / 1) :
You can use mouse click to interact with at least one object (button for example) = 1 (describe later)
Basic button (2 / 2) :
You have at least 1 button having 3 differents states (NOTHING, HOVER, PRESSED, UNPRESSED ...) = 2
Menu bar (2 / 2) :
At least one option of the menu bar have drop down options = 2
Call back on file option (2 / 2) :
You can enter the name of the file when selecting new, open or save file options (console input are OK too) = 2
Call back on edition option (2 / 2) :
You can use the tool selected in interface = 2
Call back on help option (3 / 3) :
A message is display in the window OR console to explain how to use the software = +1
Side menu (2 / 2) :
A side menu is a drop down menu, and you can choose some other option = +1
Drawing feature (1 / 1) :
You can draw hand free in the picture using a framebuffer. The event MouseMoveEvent have to be use (need to open code) = 1
Save (2 / 2) :
You can save your picture AND choose format by the file menu and save file = +1
Layer management (2 / 2) :
You can create layer mask (mask on layer) = +1
Other tools and shapes (4 / 6) :
Simple shape drawing = +1
You can use other tools = +1
Complex shape drawing = +1
Other options in menu bar (1 / 2) :
undo/redo operations = +1
Bonus (2 / 15) :
Zoom
Roue de couleur
```


### Tests and code coverage
**Unit tests** were performed using [criterion](https://criterion.readthedocs.io/en/master/intro.html).  
In this project, **only** the **library code is covered**.  
Unit tests are still to be performed, but a large part of the code is already covered.  

You can compile the project and run the unit tests with this command :
```sh
make tests_run
```


## Compilation 🛠️
You can compile the project with this command :
```sh
make
```

If you want clean the project, you can run this command :
```sh
make fclean
```

You can clean and compile the project with ```make re```.    

You can compile the unit tests with this command :
```sh
make unit_tests
```


## Code mandatory 📦
- You'll need to create a branch where you'll push your code. Once you've completed your tasks on this branch, we'll work together to merge it and check that everything works.
- Every function you add must be code-style.
- Before merging, you'll need to check that all unit tests pass by running ```make tests_run```.
- Each commit will contain ```[+]``` or ```[-]``` or ```[~]``` followed by a message
    - ```[+]``` : Add feature
    - ```[-]``` : Delete feature
    - ```[~]``` : Edit feature

**Of course, in exceptional cases, we may depart from these rules.**


## What's next ? 🚀
- Finish the selection tool
- Add the copy/paste tool
- Add documentation on each functions
- Add unit tests on each piece of code


## Contributors 👥
For this project, we were a group of **2 people**. Here are the people in the group:
- [Gianni TUERO](https://github.com/xJundo)
- [Nicolas TORO](https://github.com/toro-nicolas)
