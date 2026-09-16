<div align="center">

# Windows Event Log Collector

[![Status](https://img.shields.io/badge/status-in%20development-yellow)]()
![C++](https://img.shields.io/badge/c++-%2300599C.svg?logo=c%2B%2B&logoColor=white)
![SQLite](https://img.shields.io/badge/sqlite-%2307405e.svg?logo=sqlite&logoColor=white)

</div>

---

## Introduction

A background Windows Event Log collector service written in C++ with SQLite database storage.

---

## Tech Stack

* **Language:** C++ (Modern standards)
* **Database:** SQLite

---

## Architecture

```plaintext
📁 windows-event-log-collector
├── 📁 windows-event-log-collector
│   ├── 📁 core
│   │   ├── 📁 database
│   │   │   ├── ...
│   │   │   📁 io
│   │   │   └── ...
│   │   📁 docs
│   │   └── ...
│   │   📁 external
│   │   └── ...
│   │   📁 tests
│   │   └── ...
│   ├── 📄 CMakeLists.txt
│   └── 📄 main.cpp
├── 📄 .gitattributes
├── 📄 .gitignore
├── 📄 CMakeLists.txt
├── 📄 CMakePresets.json
└── 📄 README.md
```
## Getting Started
See the [Getting Started Guide](windows-event-log-collector/docs/getting_started.md) to set up dependencies and run the project.
