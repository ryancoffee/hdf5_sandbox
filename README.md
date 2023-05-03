# hdf5\_sandbox
Used for debugging and testing purposes.  

Be sure to disable version checking and confirm the `h5c++` libs and includes for the system and accommodating in the Makefile.  
 
```bash
export HDF5_DISABLE_VERSION_CHECK=1
h5c++ -show
```
This seems to supress the version checking that goes on.  Not sure why there is a library mismatch, but it's now happened also for a clean build on my laptop too.  
