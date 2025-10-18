## sample cpp app.

https://www.learncpp.com/

```sh
msbuild app_one.vcxproj -p:Platform=x64 -p:Configuration=Debug
./x64/Debug/app_one.exe
```
- The `<PlatformToolset>v142</PlatformToolset>` needs to be for the visual studio you have installed. `v142` is VS2019, `v140` is VS2015, etc. 