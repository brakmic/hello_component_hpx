# HPX HelloWorld Component

![CI](https://github.com/brakmic/hello_component_hpx/actions/workflows/ci.yml/badge.svg)

This project demonstrates how to create a basic **HPX component** that returns the number 42 when called.
The project is structured as follows:

- **Component**: The core logic for returning a number is encapsulated inside an HPX component.
- **Action**: HPX actions are used to expose component functionality for asynchronous execution across distributed nodes.
- **Main**: The entry point where we create the component, call it, and print the result.
  
## Getting Started

### Prerequisites

- Docker.
- The demo builds inside `brakmic/hpx-builder:1.11.0`, which provides HPX
  1.11.0, Boost, GCC 13, and CMake 3.28. A local HPX installation also works
  with CMake 3.19+ and a C++23 compiler.

### Project Structure

```text
.
├── CMakeLists.txt           # Build configuration
├── .devcontainer            # VS Code development container
│   └── devcontainer.json
├── include                  # Header files
│   └── hello_component.hpp  # HPX component header
├── src                      # Source files
│   ├── hello_component.cpp  # HPX component implementation
│   └── main.cpp             # Entry point of the application
├── LICENSE                  # MIT License
└── README                   # This file
```

### Building the Project

Build inside the builder image:

```bash
docker run --rm -it -v "$PWD:/src" brakmic/hpx-builder:1.11.0 /bin/bash
```

Inside the container:

```bash
cmake -S /src -B /src/build -DCMAKE_PREFIX_PATH=/usr/local/hpx
cmake --build /src/build --parallel 2
```

A one-shot build and run:

```bash
docker run --rm -v "$PWD:/src:ro" brakmic/hpx-builder:1.11.0 bash -lc '
  cp -a /src /tmp/app
  cmake -S /tmp/app -B /tmp/app/build -DCMAKE_PREFIX_PATH=/usr/local/hpx
  cmake --build /tmp/app/build --parallel 2
  /tmp/app/build/hello_component_hpx
'
```

### Development Container

The repository includes a VS Code devcontainer that uses
`brakmic/hpx-builder:1.11.0`. Open the folder in VS Code and choose
**Reopen in Container**, or run:

```bash
devcontainer up --workspace-folder .
```

The container configures CMake with Ninja and `CMAKE_PREFIX_PATH=/usr/local/hpx`
and builds into `/workspace/build`. The container runs as root, matching the
builder image. On Linux hosts the build directory is owned by root; remove it
with `sudo` if that becomes inconvenient.

### Running the Program

To run the program after an in-container build:

```bash
/src/build/hello_component_hpx
```

It prints the number `42` returned by the component. The demo uses C++23
against HPX 1.11.0, which itself is built with C++17.

### LICENSE

[MIT](./LICENSE)
