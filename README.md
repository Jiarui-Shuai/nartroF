# nartroF - 反 Fortran

*Fortran is too readable, so we made this!*
*Fortran 太好读了，所以我写了个这个玩具！*

## 编译

### Windows

```cmd
mingw32-make all
```

### Linux

```bash
make all
```

## 怎么用

1. **编译** 见上文
2. **运行** 运行 `bin/natroF` 进入 REPL

### 语法教程

`variable create real <var_name> <value>`： 创建名为 `<var_name>` 的变量，值设为 `value`

`variable print <var_name>`： 输出名为 `<var_name>` 的变量

`variable operation add <v1> <v2> <res>`：将 `<res>` 设为 `<v1> + <v2>`

`quit`：退出
