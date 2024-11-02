# Sorting Visualizer

This is a C++ and SFML-based visualizer for common sorting algorithms, including:

- **Bubble Sort**
- **Insertion Sort**
- **Cycle Sort**
- **Quick Sort**
- **Brick Sort**
- **Selection Sort**
- **Gnome Sort**

The visualizer demonstrates how each algorithm sorts an array of bars, representing integers, in real-time.

## Features
- **Graphical User Interface**: 
  - A clean GUI to visualize multiple sorting algorithms with options to start, shuffle, and reset the visualization.
  - A slider to adjust the size  of the array.
  - Displays the current sorting algorithm being visualized.

- **Custom User Controls**:
  - Shuffle button to randomize the array for a new sorting visualization.
  - Start and stop controls to begin or pause the sorting process.

## Demo

Here's a quick look at the visualizer in action:

![Visualization](gifs/demo.gif)

*The above image shows the sorting process with the current algorithm set to Bubble Sort.*


## Building the Project
**Note**: These instructions are specifically for Windows. For other platforms, adjust the paths and compilation steps accordingly.

### Requirements

- C++17 or higher
- SFML 2.6.1 or higher (prebuilt binaries)

### Setting up SFML
1. **Clone the project**:
   - Clone the Sorting Visualizer repository from GitHub:
   ```bash
   git clone https://github.com/varun0138/Sorting-Visualizer
   cd sorting-visualizer
   ```

2. **Download SFML**: 
   - Download prebuilt binaries for SFML from the official [SFML website](https://www.sfml-dev.org/index.php).
   
3. **Configure your project**:
   - Extract the SFML binaries and place them in a folder (e.g., SFML-2.6.1).
   
4. **Add SFML to your environment**:
   - Update the `Makefile` included in the project with SFML libs and include paths.
   
   Example `Makefile`:
   ```makefile
   all: compile link run clean

   SFML_INCLUDE = C:/SFML-2.5.1/include
   SFML_LIB = C:/SFML-2.5.1/lib

   compile:
      g++ -c *.cpp algorithms/src/*.cpp maths/*.cpp utils/*.cpp -std=c++17 -g -Wall -m64 -I ${SFML_INCLUDE} -DSFML_STATIC

   link:
      g++ *.o -o main -L ${SFML_LIB}  -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-network-s -lsfml-audio-s -lopengl32 -lfreetype -lwinmm -lgdi32 

   clean:
      del *.o *.exe
      
   run:
      ./main
5. **Compile the project**:
   ```
   make
## Troubleshooting

- **Missing dependencies**: Ensure the SFML library is correctly linked. If there are issues, verify the paths for the SFML lib and include folders are accurate.
- **Compiler errors**: Make sure you're using **C++17** or later, as the project may rely on language features introduced in these versions.

## Future Improvements

- **Additional Algorithms**: Add more sorting algorithms such as **Merge Sort** and **Heap Sort** to enhance the visualizer's functionality.


## Contributions
Contributions are welcome! Feel free to open an issue for bugs, feature requests, or suggestions. You can also submit a pull request if you'd like to contribute code.