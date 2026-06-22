### 1. 配置NDK和CMAKE引用
#### 1.1. NDK工程
构建NDK工程时候，直接使用AS的构建NDK Project, 然后gradle选择gradle groov. 为了学习尽量先采用java.
#### 1.2. CMAKE编写
  * **project(\"ndkopenglstudy\")** 要**System.loadLibrary("ndkopenglstudy")** 一致
  * CMAKE编写时候，注意**include_directories**用于引用自定义文件夹中head文件，**file** 用于引入所有需要编译的
    cpp文件，**add_library**用来将收集的文件构建成库，
  * **find_library** 寻找已有的库，譬如log,gles
  * **target_link_libraries** 将所有库链接到目标。
### 2. 创建JNI相关注册
#### 2.1 构建java端类
   创建一个native类(**NativeGLRender**)，该类创建一些native方法，供给java来调用natvie方法
#### 2.2 构建c++端类
   创建一个context类 (**GLRenderContext**), 用来供给JNI方法的调用。
#### 2.3 构建JNI注册
  1. 编写native类中方法，将他们放入
  ```cpp
    #ifdef __cplusplus
    extern "C" {
    #endif
    //相应方法区域
    
    #ifdef __cplusplus
    }
    #endif
  ```
  2.  创建注册方法的数组，查看**g_RenderMethods**, 编写**RegisterNativeMethods**、**UnRegisterNativeMethods**方法
  3. 创建**JNI_OnLoad** 、**JNI_OnUnload**，注意，这两个方法是在创建时候自动运行的，所以不需要调用。
  
#### 2.4 创建Base类
  创建base类( **GLBaseSample**)，是为了保证子类都按照该基本方法来处理。


### 计划   将类型分为简单，光照， 粒子， 图片， 模型  增加type类型来处理  采用raw来读取shader 
