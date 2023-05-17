the OpenSSL Project

## Windows环境编译
## Perl

We recommend Strawberry Perl, available from <http://strawberryperl.com/>  
via <https://platform.activestate.com/ActiveState> and then download it.  

## Microsoft Visual C compiler.

## Netwide Assembler (NASM)

NASM is the only supported assembler. It is available from <https://www.nasm.us>.

download [https://www.nasm.us/pub/nasm/releasebuilds/2.16.01/win64/nasm-2.16.01-win64.zip]

### 快速编译

```bash
 > vcvars64
 > set Path=D:\devtools\Strawberry\perl\bin;%Path%
 > set CL=/MP
 > mkdir build & cd build
 > perl ../Configure VC-WIN64A --prefix="D:\devtools\openssl.3.0.8" --openssldir="D:\devtools\openssl.3.0.8\SSL"
 > nmake
 > nmake install
```

### 运行测试程序
```bash
 > nmake test
 ```

### 调试版本编译

```bash
 > mkdir buildd & cd buildd
> perl ../Configure VC-WIN64A --debug --prefix="D:\devtools\openssl.3.0.8d" --openssldir="D:\devtools\openssl.3.0.8d\SSL"
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
 > perl ../Configure --prefix="/opt/apps/openssl.3.0.8" --openssldir="/opt/apps/openssl.3.0.8/SSL"
 > nmake
 > nmake install
 ```
 