## TELite
A lite weight library based on
[TempestExtremes](https://climate.ucdavis.edu/tempestextremes.php). The purpose
of TELite is to facilitate use of TempestExtremes detection algorithms in other
projects.

### Compiling TELite
TELite is configured with CMake and built with GNUMake. Compiling TELite
requires a C++ compiler. This process should work well systems such as
MacOS and Linux. It *may* work on other OS's but is not tested.
```bash
git clone git@github.com:LBL-EESA/TELite.git
mkdir TELite-build
cd TELite-build
cmake -DCMAKE_INSTALL_PREFIX=<install dir> ../TELite
make -j
make -j install
```
This will install the `libTELite.a` library, the headers necessary to use it,
and a CMake configuration that can be used to import the library into other
CMake based projects via CMake's `find_package` command.

### Copyright and License
TELite is derived from
[TempestExtremes](https://climate.ucdavis.edu/tempestextremes.php) by Amanda
Dufek. See below for TempestExtremes license.

#### TELite License
TELite's [license](LICENSE) is a BSD license with an ADDED paragraph at the end
that makes it easy for us to accept improvements. See [license](LICENSE) for
more information.

#### TELite Copyright Notice
Copyright (c) 2022, The Regents of the University of California, through
Lawrence Berkeley National Laboratory (subject to receipt of any
required approvals from the U.S. Dept. of Energy). All rights reserved.

If you have questions about your rights to use or distribute this software,
please contact Berkeley Lab's Intellectual Property Office at
IPO@lbl.gov.

NOTICE.  This Software was developed under funding from the U.S. Department
of Energy and the U.S. Government consequently retains certain rights.  As
such, the U.S. Government has been granted for itself and others acting on
its behalf a paid-up, nonexclusive, irrevocable, worldwide license in the
Software to reproduce, distribute copies to the public, prepare derivative
works, and perform publicly and display publicly, and to permit others to do so.

#### TempestExtremes Copyright and License
TELite is derived from [TempestExtremes](https://climate.ucdavis.edu/tempestextremes.php) by Amanda Dufek. See below for TempestExtremes license.

TempestExtremes Author: Paul Ullrich Email: paullrich@ucdavis.edu
Copyright 2022 Paul Ullrich

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
