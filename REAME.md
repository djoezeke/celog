# Celog 📋

Celog is a lightweight logging library for C/C++ projects.
It provides various logging levels and supports colored and styled output for better readability.

## Features ✨

- Multiple log levels:
  - EMERGENCY
  - ALERT ⚠️
  - CRITICAL ❗
  - ERROR ❌
  - WARNING ⚠️,
  - NOTICE 📢
  - INFO ℹ️
  - DEBUG 🐛
- Colored and styled output 🎨
- File and function information in log messages 📂
- Configurable log level, color, and style settings ⚙️

## Installation 🛠️

To use Celog in your project, simply include the `celog.h` header file in your source files.

```cpp
#include "celog.h"
```

## Usage 📖

### Log Levels

Celog provides the following log levels:

- `celog_emerg`: Emergency messages 🚨
- `celog_alert`: Alert messages ⚠️
- `celog_crit`: Critical messages ❗
- `celog_error`: Error messages ❌
- `celog_warn`: Warning messages ⚠️
- `celog_notice`: Notice messages 📢
- `celog_info`: Informational messages ℹ️
- `celog_debug`: Debug messages 🐛

### Example

```cpp
#include "celog.h"

int main() {
    celog_emerg("This is an emergency message");
    celog_alert("This is an alert message");
    celog_crit("This is a critical message");
    celog_error("This is an error message");
    celog_warn("This is a warning message");
    celog_notice("This is a notice message");
    celog_info("This is an informational message");
    celog_debug("This is a debug message");

    return 0;
}
```

## Configuration ⚙️

You can configure the log level, color, and style settings by defining or uncommenting the following macros in `ceconfig.h`:

- `CELOG_LOG_LEVEL`: Set the log level (default: 7)
- `CELOG_COLOR`: Enable or disable colored output (default: 1)
- `CELOG_STYLE`: Enable or disable styled output (default: 1)

Example:

> celog.h

```cpp
#define CELOG_LOG_LEVEL 4  // Set Log Level
#define CELOG_NO_FILE_INFO // Diable File Info
#define CELOG_NO_FUNC_INFO // Disable Function Info
```

### Log Level Controls

Celog allows you to control the log levels by defining the `CELOG_LOG_LEVEL` macro.
Messages with a log level lower than the defined level will be disabled.

### Log Information Controls

Celog allows you to control the log information by defining :

- `CELOG_NO_FILE_INFO` File Information (i.e name) Logging would be disabled.
- `CELOG_NO_FUNC_INFO` Function Information (i.e name and line) Logging would be disabled.

### Color and Style Controls

You can disable colors and styles by setting `CELOG_COLOR` and `CELOG_STYLE` to 0, respectively.

## License 📄

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing 🤝

Contributions are welcome! Please open an issue or submit a pull request on GitHub.

## Acknowledgements 🙏

Celog is inspired by various logging libraries and aims to provide a simple and lightweight solution for C/C++ projects.
