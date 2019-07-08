#include <string>
#include <iostream>
#include <fstream>

#include "Version.h"
#include "Airfoil.h"
#include "StringUtil.h"

using namespace std;

void ShowInfo()
{
	// Inform the user how to use the program
	std::cout << " cannot execute the program! The parameters are:" << endl << endl;
	std::cout << "-i <input file name> ( *.dat *.txt, *.af, *.su2, *.msh;  Geometry formats: Selig, Lednicer, OpenVSP; or Mesh formats: SU2, MSH (ASCII v2 only) )" << endl << endl;
	std::cout << "-imesh <input file is mesh file> ( insert if the input file is in a mesh file format )" << endl << endl;
	std::cout << "-iairfoilboundaryname <name of element group with airfoil elements in mesh file> ( select name of element group describing the airfoil boundary in SU2 (see MARKER_TAG) or MSH (see PhysicalName) )" << endl << endl;
	std::cout << "-norm <normalize coordinates> ( insert if the input file is mesh and the coordinates need to be normalized to the interval <0,1> )" << endl << endl;
	std::cout << "-ndig <number of digital places> ( insert if the coordinates need better precision than the standard (more than 20 does not seem to be useful);  unsigned integer;  default 6, min 6 )" << endl << endl;
	std::cout << "-o <output file name> ( an appropriate string file name with or without path;  default \"Output_AirfoilGeometryConverter\" )" << endl << endl;
	std::cout << "-f <output format> ( if the input file is in a mesh format: lednicer, selig;  otherwise: geo, su2, msh, msh1, unv, vrml, ply2, stl, mesh, bdf, diff, med, ... - see Gmsh export formats for details);  default \"selig\" or \"geo\" )" << endl << endl;
	std::cout << "-frf <farfield shape> ( circle, rectangle;  default \"circle\" )" << endl << endl;
	std::cout << "-frfsz <farfield size> ( unsigned integer;  default 25, min 2 )" << endl << endl;
	std::cout << "-mshmin <minimum mesh element size> ( double;  default 0.001, min >0, mshmin < mshmax )" << endl << endl;
	std::cout << "-mshmax <maximum mesh element size> ( double;  default 1.5, min >0, mshmax > mshmin )" << endl << endl;
	//<> possible future additions can be seen below
	/*
	//(-clmin float	Set minimum mesh element size) implemented as -mshmin
	//(-clmax float	Set maximum mesh element size) implemented as -mshmax
	//-clscale float	Set global mesh element size scaling factor
	//-algo string	Select mesh algorithm (meshadapt, del2d, front2d, delquad, del3d, front3d, mmg3d, pack)
	//-smooth int	Set number of mesh smoothing steps
	*/
	//-p path to Gmsh executable file (default "Gmsh")
	std::cout << endl << "Airfoil Geometry Converter " << Version << " (Author: Tomas Vogeltanz, developed in 2015/2016, Tomas Bata University in Zlin, Czech Republic)" << endl;
}

bool CheckIfFileCanBeWritten(string file_name,  string format)
{
	ofstream myfile(file_name.append(format.insert(0, ".")).c_str());
	bool canBeWritten = myfile.is_open();
	if (canBeWritten == true)
		myfile.close();
	
	return canBeWritten;
}

int main(int argc, const char* argv[])
{
	/*
	//for debug purpose only
	string commandForTest = "AirfoilGeometryConverter -i airfoil_selig.dat -o airfoil_selig_circle -f msh -frf circle";
	const char* n_argv[] = {"AirfoilGeometryConverter", "-i", "airfoil_selig.dat", "-o", "airfoil_selig_circle", "-f", "msh", "-frf", "circle"};
	argv = n_argv;
	argc = 9;
	*/
	
	/*
	//for debug purpose only (SU2 format as input file)
	string commandForTest = "AirfoilGeometryConverter -i airfoil.su2 -imesh -iairfoilboundaryname airfoil -o airfoil_selig -f selig";
	const char* n_argv[] = {"AirfoilGeometryConverter", "-i", "airfoil.su2", "-imesh", "-iairfoilboundaryname", "airfoil", "-o", "airfoil_selig", "-f", "selig"};
	argv = n_argv;
	argc = 9;
	*/
	
    if (argc < 1)
	{
		// Check the value of argc. If not enough parameters have been passed, inform user and exit.
		ShowInfo();
        //std::cin.get();
        return 0;
    }
	else
	{
		string inputFileParm = "-i";
		string inputFileMeshParm = "-imesh";
		string inputFileAirfoilBoundaryNameParm = "-iairfoilboundaryname";
		string normalizationParm = "-norm";
		string digitPlacesPrecisionParm = "-ndig";
		string outputFileParm = "-o";
		string outputFormatFileParm = "-f";
		string farfieldShapeParm = "-frf";
		string farfieldSizeParm = "-frfsz";
		string meshMinParm = "-mshmin";
		string meshMaxParm = "-mshmax";
		
		string defaultinputFileAirfoilBoundaryName = "airfoil";
		string defaultdigitPlacesPrecision = "6";
		string defaultOutputFileName = "Output_AirfoilGeometryConverter";
		string defaultFormatOfOutputFile = "geo";
		string defaultFormatOfOutputFileForSU2 = "selig";
		string defaultFarfieldShape = "circle";		
		string defaultFarfieldSize = "25";
		string defaultMeshMin = "0.001";
		string defaultMeshMax = "1.5";
		
        string inputFileName = "";
        bool inputFileMesh = false;
        string inputFileAirfoilBoundaryName = defaultinputFileAirfoilBoundaryName;
		bool normalization = false;
		string digitPlacesPrecision = defaultdigitPlacesPrecision;
		string outputFileName = defaultOutputFileName;
		string formatOfOutputFile = defaultFormatOfOutputFile;
		string farfieldShape = defaultFarfieldShape;
		string farfieldSize = defaultFarfieldSize;
		string meshMin = defaultMeshMin;
		string meshMax = defaultMeshMax;
		
        std::cout << "\n" << argv[0];
		
        for (int i = 1; i < argc; i += 2)
		{
			/* We will iterate over argv[] to get the parameters stored inside.
             * Note that we're starting on 1 because we don't need to know the 
             * path of the program, which is stored in argv[0] */
			if (inputFileParm.compare(argv[i]) == 0)
			{
				inputFileName = argv[i + 1];
			}
			else if (inputFileMeshParm.compare(argv[i]) == 0)
			{
				inputFileMesh = true;
				i--;
			}
			else if (inputFileAirfoilBoundaryNameParm.compare(argv[i]) == 0)
			{
				inputFileAirfoilBoundaryName = argv[i + 1];
			}
			else if (normalizationParm.compare(argv[i]) == 0)
			{
				normalization = true;
				i--;
			}
			else if (digitPlacesPrecisionParm.compare(argv[i]) == 0)
			{
				digitPlacesPrecision = argv[i + 1];
			}
			else if (outputFileParm.compare(argv[i]) == 0)
			{
				outputFileName = argv[i + 1];
			}
			else if (outputFormatFileParm.compare(argv[i]) == 0)
			{
				formatOfOutputFile = argv[i + 1];
			}
			else if (farfieldShapeParm.compare(argv[i]) == 0)
			{
				farfieldShape = argv[i + 1];
			}
			else if (farfieldSizeParm.compare(argv[i]) == 0)
			{
				farfieldSize = argv[i + 1];
			}
			else if (meshMinParm.compare(argv[i]) == 0)
			{
				meshMin = argv[i + 1];
			}
			else if (meshMaxParm.compare(argv[i]) == 0)
			{
				meshMax = argv[i + 1];
			}
			else
			{
				std::cout << "Not enough or invalid arguments, please try again.\n";
				ShowInfo();
				return 0;
			}
			std::cout << " " << argv[i] << " " << argv[i + 1];
        }
		
		if (inputFileName != "")
		{
			unsigned int digitPlacesPrecisionUInt = 6;
			if (StringUtil::string_to_uint(digitPlacesPrecision, &digitPlacesPrecisionUInt) == true)
				if (digitPlacesPrecisionUInt < 6)
					digitPlacesPrecisionUInt = 6;
			
			
			Airfoil* airfoil = new Airfoil();
			
			if (inputFileMesh == false)
			{
				if (airfoil->ReadFile(inputFileName) == true)
				{
					
					if (outputFileName.compare(defaultOutputFileName) != 0)
					{
						if (CheckIfFileCanBeWritten(outputFileName, formatOfOutputFile) == false)
							outputFileName = defaultOutputFileName;
					}
					
					FarfieldShape farfieldShapeEnum = Circle;
					if (farfieldShape.compare(defaultFarfieldShape) != 0)
					{
						string farfieldShape_lowerCase = StringUtil::to_lower_case(farfieldShape);
						if (farfieldShape_lowerCase.compare("rectangle") == 0)
							farfieldShapeEnum = Rectangle;
					}
					
					
					unsigned int farfieldSizeUInt = 25;
					if (StringUtil::string_to_uint(farfieldSize, &farfieldSizeUInt) == true)
						if (farfieldSizeUInt < 2)
							farfieldSizeUInt = 25;
					
					
					double meshMinDouble, meshMaxDouble = 0;
					if (StringUtil::string_to_double(meshMin, &meshMinDouble) == true)
					{
						if (meshMinDouble <= 0)
							meshMin = defaultMeshMin;
					}
					else
						meshMin = defaultMeshMin;
					
					if (StringUtil::string_to_double(meshMax, &meshMaxDouble) == true)
					{
						if (meshMaxDouble <= 0)
							meshMax = defaultMeshMax;
					}
					else
						meshMax = defaultMeshMax;
									
					if (meshMaxDouble <= meshMinDouble)
					{
						meshMaxDouble = meshMinDouble + 0.001;
						meshMax = StringUtil::double_to_string(meshMaxDouble, "%f");
					}
					
					//convert and export file to GEO format
					airfoil->ExportGEO(outputFileName, farfieldShapeEnum, farfieldSizeUInt, digitPlacesPrecisionUInt);
					
					string formatOfOutputFile_lowerCase = StringUtil::to_lower_case(formatOfOutputFile);
					if (formatOfOutputFile_lowerCase.compare("geo") != 0)
					{
						airfoil->ExportMesh(outputFileName, formatOfOutputFile_lowerCase, meshMin, meshMax);
					}
				}
			}
			else
			{
				if (airfoil->ReadMesh(inputFileName, inputFileAirfoilBoundaryName, normalization) == true)
				{
					FormatDAT formatDATEnum = selig;
					if (formatOfOutputFile.compare(defaultFormatOfOutputFileForSU2) != 0)
					{
						string formatOfOutputFile_lowerCase = StringUtil::to_lower_case(formatOfOutputFile);
						if (formatOfOutputFile_lowerCase.compare("lednicer") == 0)
							formatDATEnum = lednicer;
					}
					
					
					if (outputFileName.compare(defaultOutputFileName) != 0)
					{
						if (CheckIfFileCanBeWritten(outputFileName, "dat" /*formatOfOutputFile*/) == false)
							outputFileName = defaultOutputFileName;
					}
					
					
					//convert and export file to DAT format (selig or lednicer)
					if (airfoil->ExportDAT(outputFileName, formatDATEnum, digitPlacesPrecisionUInt) == true)
						std::cout << endl << "Export was successfully done" << endl;
					else
						std::cout << endl << "Problem with file export to DAT format" << endl;
				}
				else
				{
					std::cout << endl << "Problem with input mesh file (or bug in conversion method)" << endl;
				}
			}
			
			
			delete airfoil;
		}
		else
		{
			ShowInfo();
		}
		
        //std::cin.get();
        return 0;
    }
}
