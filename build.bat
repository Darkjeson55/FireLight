@echo off
cls

SET includes=/external:W0 /MD /external:I "F:\vcpkg\vcpkg\installed\x64-windows\include"
SET libs=/link /LIBPATH:"F:\vcpkg\vcpkg\installed\x64-windows\lib\" glfw3dll.lib glad.lib opengl32.lib
SET initial=/nologo /std:c++20 /W0 /EHsc


if not exist build mkdir build

pushd build 
ccache cl %initial% %includes% ..\main.cpp %libs%
popd

.\build\main.exe
