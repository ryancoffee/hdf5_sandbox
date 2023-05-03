#include "testh5.hpp"

int main(void){
	std::cout << "Hello there\n" << std::flush;	
	hid_t file_id;
      	herr_t status;	
	int maj(0),min(0),rev(0);
	status = H5check_version(maj,min,rev);
	std::cout << "maj = " << maj << " min = " << min << " rev = " << rev << std::endl;

	file_id = H5Fcreate ("file.h5", H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);   
	status = H5Fclose (file_id);
	std::cout << "status = " << status << std::endl;
	return 0;
}
