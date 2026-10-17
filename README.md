# ExATKDataPlugin

This is a rebuild of ExATKDataPlugin.dll for [Complete Alchemy and Cooking Overhaul SE](https://www.nexusmods.com/skyrimspecialedition/mods/19924) using [libxse commonlibsse-template](https://github.com/libxse/commonlibsse-template)

It offers a simple papyrus function to copy AttackData from one ActorBase to Another:

ExReplaceATKDataScript.ReplaceATKData(ActorBase theSourceBase, ActorBase theDestinationBase)

The copy is shallow, as with the old implementation from 2013, the destination will point at the same AttackData map as the source rather than getting its own duplicate.
This was made at the time to bypass an engine bug that reverted the players attack data to those from the Race record. 
Thus the change from this function isn't permanent and must be called as initialisation before AttackData use on OnPlayerLoadGame() and OnRaceSwitchComplete()
CACO does that in xCACOGrenadeMaintenanceScript.

### For CACO Users
The release only contains ExATKDataPlugin.dll binaries and papyrus script files. 

### Requirements
* [XMake](https://xmake.io) [3.0.0+]
* C++23 Compiler (MSVC, Clang-CL)

## Getting Started
```bat
git clone --recurse-submodules https://github.com/Excinerus/ExATKDataPlugin
cd ExATKDataPlugin
```

### Build
To build the project, run the following command:
```bat
xmake build
```

> ***Note:*** *This will generate a `build/windows/` directory in the **project's root directory** with the build output.*

### Build Output (Optional)
If you want to redirect the build output, set one of the following environment variables:

- Path to a Mod Manager mods folder: `XSE_TES5_MODS_PATH`

  or

- Path to a Skyrim install folder: `XSE_TES5_GAME_PATH`

### Project Generation (Optional)
If you use Visual Studio, run the following command:
```bat
xmake project -k vsxmake
```

> ***Note:*** *This will generate a `vsxmakeXXXX/` directory in the **project's root directory** using the latest version of Visual Studio installed on the system.*

**Alternatively**, if you do not use Visual Studio, you can generate a `compile_commands.json` file for use with a laguage server like clangd in any code editor that supports it, like vscode:
```bat
xmake project -k compile_commands
```

> ***Note:*** *You must have a language server extension installed to make use of this file. I recommend `clangd`. Do not have more than one installed at a time as they will conflict with each other. I also recommend installing the `xmake` extension if available to make building the project easier.*

### Upgrading Packages (Optional)
If you want to upgrade the project's dependencies, run the following commands:
```bat
xmake repo --update
xmake require --upgrade
```

## Documentation
Please refer to [libxse commonlibsse-template](https://github.com/libxse/commonlibsse-template) and its wiki for more advanced topics.
