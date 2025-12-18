# Performance-Monitor
C++ Application to monitor real time performance metrics on Windows.

## Features
- Live CPU usage
- RAM availability
- Disk activity
- Network usage

## Technologies Used
- C++17
- Qt 6
- Windows PDH API
- CMake
- MSVC 2022

## What I Learned
- Integrating native Windows APIs with Qt
- Separating backend logic from UI
- Using QTimer for real-time updates
- Building GUI apps with CMake + Qt

## Building from Source

### Prerequisites
*   **Windows 10/11**: This application uses Windows-specific APIs and is not cross-platform.
*   **C++ Compiler**: A compiler that supports C++17, like MSVC (Visual Studio 2019 or newer).
*   **Qt 6**: The Qt 6 SDK for your compiler (e.g., `msvc2019_64`). You can download it from the [official Qt website](https://www.qt.io/download).
*   **CMake**: Version 3.16 or newer.

### Steps
1.  **Clone the repository:**
    ```sh
    git clone https://github.com/your-username/Performance-Monitor.git
    cd Performance-Monitor
    ```

2.  **Configure the project with CMake:**
    Run the following command from the root of the project directory. You must replace `"C:/Qt/6.x.x/msvc2019_64"` with the actual path to your Qt 6 installation.

    ```sh
    cmake -B build -S . -D CMAKE_PREFIX_PATH="C:/Qt/6.x.x/msvc2019_64"
    ```

3.  **Build the project:**
    ```sh
    cmake --build build --config Release
    ```

4.  **Run the application:**
    The executable will be located in the `build/Release` directory.
    ```sh
    ./build/Release/Performance-Monitor.exe
    ```