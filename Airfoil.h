#ifndef POINT_H
#define POINT_H

#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <fstream>

using std::vector;
using std::string;
using std::ifstream;


struct Point
{
	double x, y, z;
};

struct Element
{
	unsigned int notImportant, pointN1, pointN2;
};


enum FarfieldShape
{
	Circle = 0, Rectangle = 1
};

enum FormatDAT
{
	selig = 0, lednicer = 1
};



class Airfoil
{
	
protected:

    bool ReadSeligAirfoil( FILE* file_id );
    bool ReadLednicerAirfoil( FILE* file_id );
    bool ReadVspAirfoil( FILE* file_id );

	string ConvertAirfoilToGEO(FarfieldShape farfieldShape, unsigned int farfieldSize, unsigned int decimalPlacesPrecision);
	
	bool ParseSU2(ifstream* mesh_file, string MARKER_TAG_airfoil, bool normalizeCoordinates); //NDIME= 2 -> MARKER_TAG -> NPOIN
	bool ParseMSH(ifstream* mesh_file, string PhysicalName_airfoil, bool normalizeCoordinates); //$MeshFormat 2.2 -> $PhysicalNames -> $Elements -> $Nodes
	bool ConvertFromMesh(vector<Point> points, vector<Element> elements, bool normalizeCoordinates);
	void FindMaxAndMinX(std::vector<Point> airfoilPoints, double* maxX, unsigned int* posMaxX, double* minX, unsigned int* posMinX);
	bool CheckIf_X_IntervalIsOK(double maxX, double minX);
	void NormalizeValues(std::vector<Point>* airfoilPoints, double maxX, double minX, double YLine);
	void FindUpperAndLowerSideDirection(std::vector<Point> airfoilPoints, unsigned int posX, int* upperDirection, int* lowerDirection);
	void FillUpperAndLowerVector(std::vector<Point> airfoilPoints, unsigned int posMaxX, unsigned int posMinX, int upperDirectionMin, int lowerDirectionMin);
	unsigned int CheckBoundariesAndGetNextPosition(int nextPosition, int sizeOfVector);
	
	string ConvertMeshToSelig(unsigned int decimalPlacesPrecision);
	string ConvertMeshToLednicer(unsigned int decimalPlacesPrecision);

    string m_AirfoilName;
	vector<Point> m_UpperPnts;
    vector<Point> m_LowerPnts;

public:
    Airfoil();
	virtual ~Airfoil();

    bool ReadFile( string file_name );
	bool ReadMesh( string file_name, string TAG_airfoil, bool normalizeCoordinates = false );
	
	bool ExportGEO( string file_name, FarfieldShape farfieldShape, unsigned int farfieldSize, unsigned int decimalPlacesPrecision = 6);
	void ExportMesh( string file_name, string format, string mshMin, string mshMax);
	
	bool ExportDAT( string file_name, FormatDAT formatDAT, unsigned int decimalPlacesPrecision = 6 );


    string GetAirfoilName()
    {
        return m_AirfoilName;
    }

    vector<Point> GetUpperPnts()
    {
        return m_UpperPnts;
    }

    vector<Point> GetLowerPnts()
    {
        return m_LowerPnts;
    }

    void SetAirfoilPnts( const vector< Point > & up_pnt_vec, const vector< Point > & low_pnt_vec )
    {
        m_UpperPnts = up_pnt_vec;
        m_LowerPnts = low_pnt_vec;
    }

};

#endif // POINT_H
