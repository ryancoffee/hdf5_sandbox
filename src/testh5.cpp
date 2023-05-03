#include "testh5.hpp"

#include <H5Cpp.h>

#include <vector>
#include <iomanip>

int main(void){
	std::cout << "Hello there\n" << std::flush;	
	hid_t file_id;
      	herr_t status;	
	int maj(0),min(0),rev(0);
	//status = H5check_version(maj,min,rev);
	//std::cout << "maj = " << maj << " min = " << min << " rev = " << rev << std::endl;

	std::vector<float> data;
	const size_t NI(10),NJ(10);

	data.reserve(NI*NJ);
	for (size_t i=0;i<NI;i++){
		for (size_t j=0;j<NJ;j++){
			data.push_back((float)i);
		}
	}


	std::cout << std::setw(3);
	for (size_t i=0;i<data.size();i += NI){
		for (size_t j=0;j<NJ;j++){
			std::cout << std::setw(3) << std::setfill(' ') << data[i] << " ";
			//std::cout << std::setw(3) << std::setfill('0') << data[i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::flush;

	hsize_t dims[1];
	dims[0] = data.size();
	const int rank(1);





	//file_id = H5Fcreate ("hfile.h5", H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);   
	H5::H5File * hfile = new H5::H5File ( "hfile.h5", H5F_ACC_TRUNC );
	H5::Group * group = new H5::Group( hfile->createGroup( "/Data" ));

	H5::DataSpace * dataspace = new H5::DataSpace( rank , dims );
	H5::IntType intdatatype( H5::PredType::NATIVE_INT );
	intdatatype.setOrder( H5T_ORDER_LE );
	H5::DataSet * dataset = new H5::DataSet( hfile->createDataSet( "/Data/MyFloatArray", H5::PredType::NATIVE_FLOAT, *dataspace ) );
	dataset->write( data.data(), H5::PredType::NATIVE_FLOAT );

	delete dataset;
	delete dataspace;
	delete group;
	delete hfile;

	//status = H5Fclose (file_id);

	return 0;
}
