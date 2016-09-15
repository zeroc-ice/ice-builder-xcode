# Ice Builder for Xcode

Ice Builder for Xcode is a command line program to help compile Slice files to C++ or Objective-C in Xcode.

___Note:___ Ice Buidler for Xcode has been changed from a Xcode plug-in to a command line program due to recent
Xcode developments. If you are using Xcode 7 or earlier, you may still use the older Ice Buidler for Xcode plug-in,
located [here](https://github.com/zeroc-ice/ice-builder-xcode/tree/xcode-plugin).

## Install

Download [icebuilder](icebuilder) to any path on your system. For example, `/usr/local/bin/icebuilder`.

## Usage

### Options

| Option        | Description                                     |
| :-----------: | ----------------------------------------------- |
| --cpp         | Use slice2cpp. Default is slice2objc.           |
| -h, --help    | Print usage message.                            |
| -v, --version | Display Ice Builder for Xcode version.          |
| -- ARGS       | Arguments passed directly to the slice compiler.|


### Xcode Build Rule

To use Ice Builder for Xcode you must create a custom build rule in your Xcode project. The following settings are
good starting point; however, you may need to modify them depending on your project's needs.

* Process: `*.ice`

* Using: Custom script

    ```
    /usr/local/bin/icebuilder [--cpp] [-- extra slice compiler agruments]
    ```

* Output Files:
    * `$(DERIVED_FILE_DIR)/$(INPUT_FILE_BASE).h`
    * `$(DERIVED_FILE_DIR)/$(INPUT_FILE_BASE).cpp` (For a C++ project)
    * `$(DERIVED_FILE_DIR)/$(INPUT_FILE_BASE).m` (For an Objective-C project)

![ Xcode Custom Build Rule](Xcode Custom Build Rule.png)
