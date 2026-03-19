# bridges-articulation-library-examples
Examples of a few open-source libraries in C++/Python in finding bridges and articulation points in undirected graphs.

# How to run (NetworkX in Python)
Install libraries by running the following command in the Terminal in the repository's root folder:
```bash
pip install -r requirements.txt
```

To run a Python file, run the following command:
```bash
python /path/to/file.py
```

<!-- You can generate random graphs to write to the `.txt` files using [this website](https://mikhad.github.io/graph-builder/#2023). -->

# How to run (Boost Graph Library in C++)
## 1. Prerequisites
- Install [CMake](https://cmake.org/download/) (version 3.20 or higher).
- Install [git](https://git-scm.com/install/).
- Clone the repository (either using `git clone` *(recommended)* or download `.zip` file).

## 2. Install Boost
### macOS:

If you haven't, install Homebrew using the following command in the Terminal:
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Install Boost:
```bash
brew install boost
```
### Ubuntu/Debian-based Linux distros:
Install Boost using the following command in the Terminal:
```bash
sudo apt update
sudo apt install libboost-all-dev
```
### Windows:
Install `vcpkg`:
```powershell
git clone https://github.com/microsoft/vcpkg
cd vcpkg
bootstrap-vcpkg.bat
```

Install Boost:
```powershell
vcpkg install boost
```

Integrate with CMake:
```powershell
vcpkg integrate install
```

## 3. Build the program
Go to the `bgl/` folder and enter the following in the Terminal:
### macOS & Ubuntu/Debian-based Linux distros:
```bash
mkdir build
cd build
cmake ..
make
./main
```
### Windows:
```powershell
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake
make
./main
```

## 4. Run the program
Go to the `bgl/build/` folder and simply run the `main`/`main.exe` executable.
