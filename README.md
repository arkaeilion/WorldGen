# WorldGen

## Building
- Install [vcpkg](https://vcpkg.io/) following instructions on their website.
- Edit configure.sh or use the command:
```
    cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=PATH_TO/vcpkg/scripts/buildsystems/vcpkg.cmake
    Making sure to edit "PATH_TO" to point to your installation.
```
- build.sh
- run.sh

## Issuses
- Issues with building and vcpkg
	- Deleting the build folder and running CMake again may fix most problems

## VS Code
If using the CMake Tools extension, the following can be added to the settings.json file found in the .vscode folder. Makeing sure to edit the "
PATH_TO"
```
"cmake.configureSettings": {
	"CMAKE_TOOLCHAIN_FILE": "PATH_TO/vcpkg/scripts/buildsystems/vcpkg.cmake"
},
```
