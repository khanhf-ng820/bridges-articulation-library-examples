# bridges-articulation-library-examples
Examples of a few open-source libraries in C++/Python in finding bridges and articulation points in undirected graphs.

# How to run (NetworkX in Python)
## 1. Prerequisites
- Install [Python](https://www.python.org/downloads/) (version 3.14 or above).
- Clone the repository: either using the `git clone` command below *(recommended)* or download the `.zip` file.
```bash
git clone https://github.com/khanhf-ng820/bridges-articulation-library-examples.git
```

## 2. Installation
Install libraries by running the following command in the Terminal in the repository's root folder:
```bash
pip install -r requirements.txt
```

To run a Python file, run the following command: *(replace `/path/to/file.py` with your file's path)*
```bash
python /path/to/file.py
```

<!-- You can generate random graphs to write to the `.txt` files using [this website](https://mikhad.github.io/graph-builder/#2023). -->

# How to run (Boost Graph Library in C++)
## 1. Prerequisites
- Install [CMake](https://cmake.org/download/) (version 3.20 or above).
- Install [git](https://git-scm.com/install/).
- Clone the repository: either using the `git clone` command below *(recommended)* or download the `.zip` file.
```bash
git clone https://github.com/khanhf-ng820/bridges-articulation-library-examples.git
```

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
Install `vcpkg` by running the following commands in the repository's root folder:
```powershell
git clone https://github.com/microsoft/vcpkg
cd vcpkg
bootstrap-vcpkg.bat
```

Install Boost: *(Note: This may take a while.)*
```powershell
vcpkg install boost-graph
```

<!-- Integrate with CMake:
```powershell
vcpkg integrate install
``` -->

## 3. Build the program
Go to the `bgl/` folder and enter the following in the Terminal:
### macOS & Ubuntu/Debian-based Linux distros:
```bash
mkdir build
cd build
cmake ..
make
```
### Windows:
```powershell
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake
make
```

## 4. Run the program
Go to the `bgl/build/` folder and simply run any of the executable files.
