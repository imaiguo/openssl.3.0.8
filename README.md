# the OpenSSL Project

## 依赖项

1. Perl

2. NASM


## Build with MSVC

We recommend Strawberry Perl, available from <http://strawberryperl.com/>  
via <https://platform.activestate.com/ActiveState> and then download it.  

NASM is the only supported assembler. It is available from <https://www.nasm.us>.
download [https://www.nasm.us/pub/nasm/releasebuilds/2.16.01/win64/nasm-2.16.01-win64.zip]

### 编译Release
```bash
> cmd
> "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
> set Path=D:\devtools\nasm-2.16.01;%Path%
> set CL=/MP
> mkdir build & cd build
> D:\devtools\strawberry-perl-5.32.1.1-64bit\perl\bin\perl.exe ../Configure VC-WIN64A --prefix="D:\devtools\openssl.3.0.8" --openssldir="D:\devtools\openssl.3.0.8\SSL"
> nmake & nmake install
```

### 编译Debug
```bash
> D:\devtools\strawberry-perl-5.32.1.1-64bit\perl\bin\perl.exe ../Configure VC-WIN64A --debug --prefix="D:\devtools\openssl.3.0.8\debug" --openssldir="D:\devtools\openssl.3.0.8\debug\SSL"
```

### 运行测试程序
```bash
 > nmake test
 ```

### test代码
```bash
test\pem_read_depr_test.c
test\evp_libctx_test.c  rsa_keygen
```

## Linux环境编译

系统自带开发库libssl-dev

```bash
 > mkdir build & cd build
 > perl ../Configure --prefix="/opt/devtools/openssl.3.0.8" --openssldir="/opt/devtools/openssl.3.0.8/SSL"
 > nmake
 > nmake install
 ```
 