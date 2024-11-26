# ControLib

A Python package for control system design and deployment.

ControLib is a package to help users design advanced control systems, test and benchmark them, and deploy them on a few selected embedded platforms (Arduino, STM32 Nucleo, Raspberry Pi). By advanced, we are referring to control systems beyond the realm of classical control (e.g. Model Predictive Control), especially those that are heavily reliant on machine learning and/or optimisation. Some classical control systems (e.g. PID controllers) will be included as well.

Some Simulink models will also be provided. To interact with these using Python, ControLib will use the [PySimlink](https://github.com/lharri73/PySimlink) package.

ControLib will support Software-in-the-loop, Processor-in-the-loop, and Hardware-in-the-loop testing, although the extent to which it will do so is yet to be determined.

Please note that development is still in the very early stages, and it might take a while before a stable version is released.

## Documentation Guide

### Installation

Read our [installation guide](installation.md) for instructions on how to install the package.

### Usage instructions

Some basic guides on how to use the package are provided in our [User Guide](user_guide/index.md) section.

If you require detailed information on how to use a specific function or class, check out the [API reference](API_ref/index.md).

For comprehensive examples on how to use the package, please refer to our [Examples](examples/index.md) section.

### Contributing

Have you stumbled upon a bug? Would you like to see a new feature included in the package? Do you think you can improve an existing feature? If so, check out our [contribution guide](contributing.md).

For more information on package authors and contributors, take a look at the [About](about.md) section.