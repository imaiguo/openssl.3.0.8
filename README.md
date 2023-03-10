the OpenSSL Project


Notes for Windows platforms

Native builds using Visual C++
==============================

Requirement details
-------------------

In addition to the requirements and instructions listed in `INSTALL.md`,
these are required as well:

### Perl

We recommend Strawberry Perl, available from <http://strawberryperl.com/>
Please read NOTES.PERL for more information, including the use of CPAN.
An alternative is ActiveState Perl, <https://www.activestate.com/ActivePerl>
for which you may need to explicitly build the Perl module Win32/Console.pm
via <https://platform.activestate.com/ActiveState> and then download it.

### Microsoft Visual C compiler.

Since these are proprietary and ever-changing we cannot test them all.
Older versions may not work. Use a recent version wherever possible.

### Netwide Assembler (NASM)

NASM is the only supported assembler. It is available from <https://www.nasm.us>.

download [https://www.nasm.us/pub/nasm/releasebuilds/2.16.01/win64/nasm-2.16.01-win64.zip]

Quick start
-----------

 1. Install Perl & NASM

 2. set ENV &  build

```bash
 > vcvars64
 > set Path=D:\devtools\Strawberry\perl\bin;%Path%
 > set CL=/MP
 > cd openssl & perl ../Configure VC-WIN64A --prefix="D:\devtools\openssl.3.0.8" --openssldir="D:\devtools\openssl.3.0.8\SSL"
 > nmake
 > nmake test
 > nmake install
```


For the full installation instructions, or if anything goes wrong at any stage,
check the INSTALL.md file.

Installation directories
------------------------

The default installation directories are derived from environment
variables.

For VC-WIN32, the following defaults are use:

    PREFIX:      %ProgramFiles(x86)%\OpenSSL
    OPENSSLDIR:  %CommonProgramFiles(x86)%\SSL

For VC-WIN64, the following defaults are use:

    PREFIX:      %ProgramW6432%\OpenSSL
    OPENSSLDIR:  %CommonProgramW6432%\SSL

Should those environment variables not exist (on a pure Win32
installation for examples), these fallbacks are used:

    PREFIX:      %ProgramFiles%\OpenSSL
    OPENSSLDIR:  %CommonProgramFiles%\SSL

ALSO NOTE that those directories are usually write protected, even if
your account is in the Administrators group.  To work around that,
start the command prompt by right-clicking on it and choosing "Run as
Administrator" before running `nmake install`.  The other solution
is, of course, to choose a different set of directories by using
`--prefix` and `--openssldir` when configuring.