# Airfoil Geometry Converter
<BR>
Software: Airfoil Geometry Converter
<BR>
Aplikace umožňuje zrychlení přípravy na aerodynamickou analýzu a optimalizaci profilu křídla pomocí CFD softwaru a usnadňuje nasazení optimalizovaného profilu křídla do reálného návrhu letounu. Aplikace přispívá ke snížení finančních nákladů na vývoj a nasazení nových vylepšených profilů křídel, které mohou pozitivně ovlivnit aerodynamiku a spotřebu paliva letounu využívající tyto profily. Airfoil Geometry Converter je konzolová aplikace, která převádí soubory se souřadnicemi z/do formátu běžně používaného pro profily křídel (Selig, Lednicer a NASA/OpenVSP). Aplikaci lze využít jako generátor mesh souborů s profily pro aerodynamickou analýzu v CFD softwaru; např. v SU2, OpenFOAM apod. Soubory lze také převést zpětně pro případ, že se za pomocí CFD softwaru provedou např. optimalizace zkoumaného profilu a je požadováno, aby byl výsledný soubor se souřadnicemi použit pro křídlo v reálném návrhu letounu. Výsledný optimalizovaný profil je pak možné využít v CAD a parametrických programech, specializujících se na letecké inženýrství; jako je např. OpenVSP.
<BR>
<BR>
Vstupní formáty s geometrií profilu: Selig (dat), Lednicer (dat), NASA/OpenVSP (af)
<BR>
Výstupní formáty pro mesh: su2, msh, msh1, unv, vrml, ply2, stl, mesh, bdf, diff, med, a další (viz Gmsh)
<BR>
Vstupní formáty s meshí: su2, msh (ASCII v2)
<BR>
Výstupní formáty pro geometrii profilu: Selig (dat), Lednicer (dat), geo
<BR>
<BR>
(Projekt byl vytvořen v CodeLite 4.8.1)
<BR>
<BR>
<BR>
Airfoil Geometry Converter používá Gmsh jako externí program (pomocí příkazů)
<BR>
viz:
<BR>
http://gmsh.info/
<BR>
nebo
<BR>
C. Geuzaine and J.-F. Remacle. Gmsh: a three-dimensional finite element mesh generator with built-in pre- and post-processing facilities. International Journal for Numerical Methods in Engineering 79(11), pp. 1309-1331, 2009
<BR>
<BR>
<BR>
<b>Pokud používáte tento software, prosím, citujte následující reference ve vaší práci (knihy, články, reporty, atd.):</b>
<BR>
URL:<BR>
https://github.com/vogeltanz/AirfoilGeometryConverter
<BR>
článek:<BR>
Vogeltanz, Tomas. 2017. Airfoil Geometry Converter: From Selig and Lednicer to GEO and Mesh Formats.
AIP Conference Proceedings. vol. 1863. ISSN: 0094-243X. DOI: 10.1063/1.4992254

