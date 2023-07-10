compile with link

```bash
g++ -I .\lib\a\ .\main.cc .\lib\a\a.c -o test.exe
```

static library

```bash
# 生成机器码
g++ -I .\lib\a\ -c .\lib\a\a.c -o .\obj\a.o
# 打包
ar -rcs liba.a .\obj\a.o
# compile with liba
g++ -I .\lib\a .\main.cc .\liba.a -o test.exe
```

## CMake

```bash
mkdir build
cd build
cmake -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=True ..
ninja
```

[compile_commands](https://clangd.llvm.org/design/compile-commands)

```json
{
    "compileCommands": "build/compile_commands.json"
}
```


