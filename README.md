## TELite

TELite library only includes the TempestExtremes sources related to the DetectNodes function.\
Some modifications/simplifications were introduced in the original codes for porting DetectNodes to TECA.

### Compiling TELite

```console
   mkdir build
   cd build/
   cmake .. -DCMAKE_INSTALL_PREFIX=<install dir>
   make
   make install
```

### References
https://climate.ucdavis.edu/tempestextremes.php

https://github.com/ClimateGlobalChange/tempestextremes/blob/master/src/nodes/DetectNodes.cpp
