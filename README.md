
# the OpenSSL Project

## 依赖项

1. Perl
2. NASM

## MSVC编译

- Strawberry Perl, available from <http://strawberryperl.com/> via <https://platform.activestate.com/ActiveState>
- NASM is the only supported assembler. It is available from <https://www.nasm.us> download [https://www.nasm.us/pub/nasm/releasebuilds/2.16.01/win64/nasm-2.16.01-win64.zip]

```bash
> cmd
> vcvars64.bat
> set Path=D:\devtools\nasm-2.16.01;%Path%
> set CL=/MP
> mkdir build & cd build
> #编译动态库Release
> D:\devtools\Strawberry\perl\bin\perl.exe ../Configure VC-WIN64A --release -shared --prefix="D:\devtoolsmsvc\openssl.3.0.8" --openssldir="D:\devtoolsmsvc\openssl.3.0.8\SSL"
> #编译静态库Release
> D:\devtools\Strawberry\perl\bin\perl.exe ../Configure VC-WIN64A --release no-shared --prefix="D:\devtoolsmsvc\openssl.3.0.8\static" --openssldir="D:\devtoolsmsvc\openssl.3.0.8\static\SSL"
>
>
> #编译动态库Debug
> D:\devtools\Strawberry\perl\bin\perl.exe ../Configure VC-WIN64A --debug -shared --prefix="D:\devtoolsmsvc\openssl.3.0.8\debug" --openssldir="D:\devtoolsmsvc\openssl.3.0.8\debug\SSL"
> #编译静态库Debug
> D:\devtools\Strawberry\perl\bin\perl.exe ../Configure VC-WIN64A --debug no-shared --prefix="D:\devtoolsmsvc\openssl.3.0.8\debug\static" --openssldir="D:\devtoolsmsvc\openssl.3.0.8\debug\static\SSL"
>
> nmake & nmake install
>
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
 