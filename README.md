[![Build Status](https://travis-ci.org/zeroc-ice/ice-builder-xcode.svg)](https://travis-ci.org/zeroc-ice/ice-builder-xcode)

# Ice Builder for Xcode

Ice Builder for Xcode is an Xcode plug-in to compile Slice files to
C++ or Objective-C.

The builder manages all aspects of code generation, including
automatically recompiling Slice files that have changed, removing
obsolete generated classes, and tracking dependencies.

## Install

We recommend using Alcatraz (http://alcatraz.io) to install the
builder. Look for *IceBuilder* in the Alcatraz package list and click
`Install` to install it. Restart Xcode after the plug-in installation.

If not using Alcatraz, open and build the IceBuilder Xcode project
from this repository to install the Xcode plug-in in:
```
~/Library/Application Support/Developer/Shared/Xcode/Plug-ins
```
Restart Xcode after the plug-in installation.

To uninstall the plug-in, remove `IceBuilder.xcplugin` from:
```
~/Library/Application Support/Developer/Shared/Xcode/Plug-ins
```

## Usage

### Adding Slice Files to an Xcode Project

To add an existing Slice file, select a folder in the project, select File, and
choose Add -> Existing Files...

To create a new Slice file, select a folder in the project, select File, and
choose New -> New Files... Select the Other category and choose Empty File as
the file type. Save the file with a .ice extension.

### Configuring Xcode Project Settings

The Xcode plug-in is configured using the per-target info build settings, just
as you would configure the compiler settings. Select a target, and then select
the build settings tab, and enter `Ice Builder` in the Search in Build Settings field.

The settings are separated into sections: `Ice Builder - General Options` and `Ice Builder - Slice Compiler Options`.

#### Ice Builder - General Options

| Setting                                      | Name                       | Description                                                                                                                                                                                                            |
| -------------------------------------------- | :------------------------: | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Generate Code for C++ Instead of Objective-C | `SLICE_CPP_FLAG`           | Set this option to compile Slice files to C++ instead of Objective-C.                                                                                                    |
| Ice Home                                     | `SLICE_ICE_HOME`           | Leave this option unset if building with Ice Touch or the Ice Xcode SDKs. Otherwise, if using a homebrew Ice installation or regular Ice, set this to the location of the installation (e.g.: `/usr/local` or `/Library/Developer/Ice-3.5`). |
| Link with Ice Services Client Libraries      | `SLICE_LINK_WITH_SERVICES` | Link with Glacier2, IceStorm and IceGrid client libraries.                                                                                                                                                             |

#### Ice Builder - Slice Compiler Options

| Setting                                       | Name                             | Description                                                                                                      |
| --------------------------------------------- | :------------------------------: | ---------------------------------------------------------------------------------------------------------------- |
| Additional Include Directories                | `SLICE_INCLUDE_PATH`             | The list of directories to search for Slice files (`-I` option). The Ice Slice files are automatically included. |
| Additional Options                            | `SLICE_ADDITIONAL_OPTIONS`       | Additional options to pass to the Slice compiler.                                                                |
| Allow Reserved Ice Prefix in Identifiers      | `SLICE_ICE_FLAG`                 | Pass `--ice` to the Slice compiler.                                                                              |
| Allow Underscores in Identifiers              | `SLICE_UNDERSCORE_FLAG`          | Pass `--underscore` to the Slice compiler.                                                                       |
| Base Directory for Generated #include/#import | `SLICE_INCLUDE_DIR`              | Directory to use as the header include directory in source files.                                                |
| DLL Export Macro                              | `SLICE_DLL_EXPORT`               | Provide support for placing the generated code in a shared library (`--dll-export` option).                      |
| Generate Helper Functions For Streaming       | `SLICE_STREAM_FLAG`              | Pass `--stream` to the Slice compiler (C++ only).                                                                |
| Generate Slice Checksums                      | `SLICE_CHECKSUM_FLAG`            | Pass `--checksum` to the Slice compiler (C++ only).                                                              |
| Output Directory                              | `SLICE_OUTPUT_DIR`               | Directory to place files generated by the Slice compiler.                                                        |
| Preprocessor Macros                           | `SLICE_PREPROCESSOR_DEFINITIONS` | Set the list of preprocessor macros to define (`-D` option).                                                     |

You can also define Slice compiler options for individual Slice source files.
Select your project in the Project Navigator, select the relevant target (you
may have only one), then select the Build Phases tab, expand the Compile
Sources phase and the Compiler Flags column lets you set each file's options
for that target.

### Xcode Project Settings for Cocoa and iPhone Applications

For Cocoa and iPhone applications, which use the IceTouch or Ice Xcode SDKs, you
must add the appropriate directory to the `Additional SDKs` setting:

|Distribution | Language        | Location                                                         |
|-------------| ----------------|------------------------------------------------------------------|
| IceTouch    | Objective-C SDK | `/Library/Developer/IceTouch-1.3/SDKs/ObjC/$(PLATFORM_NAME).sdk` |
| IceTouch    | C++ SDK         | `/Library/Developer/IceTouch-1.3/SDKs/Cpp/$(PLATFORM_NAME).sdk`  |
| Ice >= 3.7  | Objective-C SDK | `/usr/local/lib/IceSDK/$(PLATFORM_NAME).sdk`                     |
| Ice >= 3.7  | C++ SDK         | `/usr/local/lib/IceSDK/$(PLATFORM_NAME).sdk`                     |

You must also link with the following Frameworks:
* `Security.framework` (OS X and iOS)
* `CFNetwork.framework` (iOS only)
* `UIKit.framework` (iOS only)

To use the iAP transport on iOS, you will also need to add the `-lIceIAP` option
to the `Other Linker Flags` setting and link with the
`ExternalAccessory.framework` framework.

### Configuring Non-SDK Builds

For non-SDK builds, you must configure the location of the Ice header
and library directories. Under the Search Paths section in the project
build settings:
* Add `Ice installation/include` to the Header Search Paths setting.
* Add `Ice installation/lib` to the Library Search Paths setting.

### Generating Code using Xcode

The builder compiles a Slice file whenever you build the project. The
builder tracks dependencies among Slice files in the project and
recompiles only those files that require it after a change.
