# Challenge1_PACS24_10582530
## Brief Explanation
The code is made of 3 build block excluding the main.
1. The parameters.cpp with its header: define the struct in which the different parameters are stored and printed on screen;
2. The readParameters.cpp with its header: read the file from a json file;
3. The GradientMethod.cpp with its header: is a class the allows to find the minimum of a given scalar function of two scalar variables;

These file are properly located in src and include folder.

The json file I have provided are in the data folder. You can add whichever file you want, in the format I have provided.


## How to use
1. Compilation: modify the makefile in the src folder specifying where is in your computer the json include.
2. executing the main without specification allow you to read parameter from data.example.
you can also type from src: ./main -f ../data/yourfile.json.
even --file is accepted

3. you can type ./main -h or --help to call the help
4. you can specify the function and its derivatives in the main file and then compile again typing make on the console.

ENJOY!

Giuseppe Caliò @2024.
