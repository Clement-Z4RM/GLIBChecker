# 🔎 GLIBChecker

GLIBChecker is a tool designed to check the usage of LibC functions in a C++ project.

It checks if there are LibC functions in your binary which are used without namespace in your code.
It also checks if you are using `exit` (see [**Features**](https://github.com/Clement-Z4RM/GLIBChecker?tab=readme-ov-file#-features) to ignore it).


## 👨‍💻 Run Locally

#### Prerequisites

- [ripgrep](https://github.com/BurntSushi/ripgrep?tab=readme-ov-file#installation)
- nm (should be installed on your system by default)
- [CMake](https://cmake.org/) (if you want to compile by yourself, 3.27 or higher*)

**if you have lower version, you can try to change the first line of `CMakeLists.txt` with your version*

Clone the project (or get it in [releases](https://github.com/Clement-Z4RM/GLIBChecker/releases/latest))

```bash
git clone https://github.com/Clement-Z4RM/GLIBChecker.git
```

Go to the project directory

```bash
cd GLIBChecker
```

Install the binary

```bash
make install
```
If your *cmake* executable is not in your *PATH*, you can do:

```bash
make install CMAKE=<your cmake path>
```

Launch it with binary file as argument

```bash
glib_checker <binary>
```


## ✨ Features

#### Ignore files, functions,...:

Add "glibchecker-ignore" at the end of a line to ignore the function on this line.

You can also set `GLIBCHECKER_IGNORE` environment variable with files, function,... like this:
```bash
GLIBCHECKER_IGNORE="./src/Foo.cpp" glibchecker foo
```

Here are the patterns taken into account:
- Function *(e.g.: "foo")*
- File *(e.g.: "./src/Foo.cpp")*
- Folder *(e.g.: "./src/")*
- File:Line *(e.g.: "./src/Foo.cpp:42")*
- File:Function *(e.g.: "./src/Foo.cpp:foo")*
- File:Line:Function *(e.g.: "./src/Foo.cpp:42:foo")*
The file must be relative to your current directory, and must have the same format as in the GLIBChecker output.

Patterns must be space-separated.

#### Run in GitHub Actions:

You can use this tool in your GitHub Actions workflow. To have the error message in the GitHub Actions summary, you can set the `GLIBCHECKER_GH_ACTIONS` environment variable:

```bash
GLIBCHECKER_GH_ACTIONS= glib_checker <binary>
```


## 🐛 Bug Reports

If you find a bug, you can report it [creating an issue](https://github.com/Clement-Z4RM/GLIBChecker/issues/new/choose) or fix it [creating a pull request](https://github.com/Clement-Z4RM/GLIBChecker/compare).


## ➕ Contributing

Contributions are always welcome!

You can [open an issue](https://github.com/Clement-Z4RM/GLIBChecker/issues/new/choose) or [create a pull request](https://github.com/Clement-Z4RM/GLIBChecker/compare).

Also, you can check the [to-do list](https://github.com/users/Clement-Z4RM/projects/18) to see planned features.


## 👱 Authors

- [@Clement-Z4RM](https://www.github.com/Clement-Z4RM)
