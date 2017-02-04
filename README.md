# Airfoil Geometry Converter
Airfoil Geometry Converter may convert DAT (Selig, Lednicer, NASA/OpenVSP) formats to SU2, MSH, GEO or conversely.


The application accelerates the preparation for aerodynamic analysis and optimization of airfoil in CFD software and simplifies deployment of optimized airfoil into a real aircraft design. Airfoil Geometry Converter is a console application, which converts files with coordinates from/to formats commonly used for airfoils (such as Selig, Lednicer, and NASA/OpenVSP). The application can be used as a mesh file generator of airfoils for aerodynamic analysis in CFD software; e.g., in SU2, OpenFOAM, etc. The files may be also converted back from the mesh file to the geometry file, for example, when an optimization of an airfoil was performed and it is necessary to apply the airfoil on a wing in the real design of an aircraft. Then, the optimized airfoil can be used in CAD and parametric software, specialized on the aircraft engineering; e.g. in OpenVSP.


Input formats with airfoil geometry: Selig (dat), Lednicer (dat), NASA/OpenVSP (af)

Output formats for mesh: su2, msh, msh1, unv, vrml, ply2, stl, mesh, bdf, diff, med, … (see Gmsh)

Input formats with mesh: su2, msh (ASCII v2)

Output formats for airfoil geometry: Selig (dat), Lednicer (dat), geo




Airfoil Geometry Converter uses Gmsh as external program (by using commands)
see:

http://gmsh.info/

or

C. Geuzaine and J.-F. Remacle. Gmsh: a three-dimensional finite element mesh generator with built-in pre- and post-processing facilities. International Journal for Numerical Methods in Engineering 79(11), pp. 1309-1331, 2009
