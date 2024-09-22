# HPX HelloWorld Component

This project demonstrates how to create a basic **HPX component** that returns the number 42 when called.
The project is structured as follows:

- **Component**: The core logic for returning a number is encapsulated inside an HPX component.
- **Action**: HPX actions are used to expose component functionality for asynchronous execution across distributed nodes.
- **Main**: The entry point where we create the component, call it, and print the result.
  
## Getting Started

### Prerequisites
- Install HPX following the [HPX installation guide](https://hpx-docs.stellar-group.org/latest/html/quickstart.html#).
- Install [Boost](https://www.boost.org/).
- Make sure you have CMake 3.19+ and a C++ compiler that supports C++23 (or change the CMake settings).

### Project Structure

```text
.
├── CMakeLists.txt           # Build configuration
├── include                  # Header files
│   └── hello_component.hpp  # HPX component header
├── src                      # Source files
│   ├── hello_component.cpp  # HPX component implementation
│   └── main.cpp             # Entry point of the application
├── LICENSE                  # MIT License
└── README                   # This file
```

### Building the Project

To build the project:

```bash
mkdir build
cd build
cmake ..
make
```

### Running the Program

To run the `fibonacci_demo_hpx` program:

```bash
./fibonacci_demo_hpx
```

It will output the number `42` returned by the component.

### LICENSE
[MIT](./LICENSE)