# Special Judge Code
# 介紹
提供了一個 Online Judge Special Judge 的模板, 並提供測試修改過後模板的測試方法

# 環境需求
- Linux
- GCC ( 支援C++ 11 的版本 ) 
- CMake 

# 編譯測試
1. Clone Repositories
```
git clone https://github.com/IDK-Silver/Special_Judg_Code.git
```
2. 新增並進入build 資料夾 (CMake 用)
```
mkdir build && cd build
```

3. 讓CMake生成配置
```
cmake ..
```

4. 生成測試文件資訊
```
cmake --build . --target Run_SPJ
```

# 使用說明

## 專案結構說明
### 架構
- **./**
    - **src**
        - **spj.cpp**
        - **pattern.cpp**
    - **solution**
        - **1.in**
        - **main.cpp**
        - **spj.log**

    - **CMakeListx.txt1**

### 說明
- `./src/spj.cpp` `(SPJ)` 是OnlineJudge Special Judg 的程式, 裡面負責OJ題目的正確解的演算法, 以及評判標準（誤差, 大小寫, 忽視特定數據）,他的比較資料來源是`./solution/main.cpp`生成的解答.

- `./src/pattern.cpp`  是OnlineJudge Special Judg 的空白模板, 可以從這個文件去做出不同題目的`spj.cpp`

- `blank_target.cpp`  CMake用途

- `./solution/main.cpp` `(Solution)` 會把 `./solution/1.in` 的資料輸入, 並把輸出解果之後交給 `SPJ` 去比對.

- `./solution/1.in` 裡是題目的輸入資料

- `./solution/spj.log`  裡面是 `SPJ` 比對 `Solution` 每筆比對的解果

## 使用流程
### 移動解答程式

| 這裡有一個前提我預設題目你有寫好解答程式(非`SPJ`格式, 就是當純的解答, 就像學生要`Submit`的程式)

現在專案把裡面的 `Solution` 換成你寫好的題目解答, 並且把`./solution/1.in`換成測試資料

### 製作 `SPJ`
| 現在的內容是 `./src/pattern.cpp` 裡面有一個叫 **solution** 的 **function**

</br>

這裡要說明SPJ格式的製作, SPJ 裡面有兩個指標分別是 `in` 以及 `ans`

`in` 是 **1.in** 的內容,  `ans` 是 `Solution` 輸出的解答

</br>

我們把 `Solution` 裡面 **main function** 複製到 **solution function** 裡面

並把 **#include 或是其他的前製處理** 移動文件的最上面

</br>

接下來把定義在 *main* 以外的東西移到 **solution function** 裡面, 例如 `class, struct, function` .

### 修改程式

- **function**
    - 要改成 **lambda**
        ```
        auto createPerson = [&]()
        {
            auto data = make_shared<Person>();
            *in >> data->name;
            *in >> data->age;
            *in >> data->height;
            *in >> data->weight;
            data->BMI = data->weight / pow(data->height / 100.0, 2);
            return data;
        };
        ```

- **cin**
    - 改成 ***in**
        ```
        *in >> name;
        ```

- cout
    - 改成 **compare_ans(var, ans);**
        ```
        compare_ans(data->name, ans);
        ```
- **c style string**
    - 都要改成 **C++** 的 `std::string`  **type**
