#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "StringUtil.h"


void StringUtil::change_from_to( char *str, const char from, const char to )
{
    int i = 0;
    while( str[i] != 0 )
    {
        if ( str[i] == from )
        {
            str[i] = to;
        }
        i++;
    }
}

//==== Change All "from" Characters -> "to" Characters ====//
void StringUtil::change_from_to( string & str, const char from, const char to )
{
    for ( int i = 0 ; i < ( int )str.size() ; i++ )
    {
        if ( str[i] == from )
        {
            str[i] = to;
        }
    }
}


//==== Replace First Instance of From String with To String ====//
bool StringUtil::replace_once( string & str, const string & from, const string & to )
{
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

//==== Replace All Instances of From String with To String ====//
void StringUtil::replace_all( string & str, const string & from, const string & to  )
{
    if(from.empty())
        return;

    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}


//==== Change All "_" Characters -> " " Characters ====//
void StringUtil::chance_underscore_to_space( string & str )
{
    StringUtil::change_from_to( str, '_', ' ' );
}

void StringUtil::chance_space_to_underscore( string & str )
{
    StringUtil::change_from_to( str, ' ', '_' );
}

//==== Remove Leading Characters that match c =====//
void StringUtil::remove_leading( string & str, char c )
{
    int i;
    for ( i = 0 ; i < ( int )str.size() ; i++ )
    {
        if ( str[i] != c )
        {
            break;
        }
    }

    if ( i > 0 )
    {
        str.replace( 0, i, "" );
    }
}

//==== Remove Trailiner Characters that match c =====//
void StringUtil::remove_trailing( string & str, char c )
{
    int i;
    for ( i = ( int )str.size() - 1 ; i > 0 ; i-- )
    {
        if ( str[i] != c )
        {
            break;
        }
    }

    if ( i < ( int )str.size() - 1 )
    {
        str.replace( i + 1, str.size() - i, "" );
    }
}

//==== Convert Int To String =====//
string StringUtil::int_to_string( int i, const char* format )
{
    char str[512];
    sprintf( str, format, i );
    return string( str );
}

//==== Convert Double To String =====//
string StringUtil::double_to_string( double v, const char* format  )
{
    char str[512];
    sprintf( str, format, v );
    return string( str );
}

bool StringUtil::string_to_uint( /*const char**/ string input, unsigned int *output )
{
	
	int n=0,p=0;	/*	k - určuje, který index pole bude aktuálně zkoumán
						*	n - určuje, zda bylo na začátku řetězce použito "+"
							p - ukladá se zde převedené číslo v celočíselné formě
						*/
	
	for (unsigned int k = 0; input[k] != 0 && k < input.length()/*strlen(input)*/; ++k)	//opakuje smyčku ve chvíli, kdy není konec řetězce a zároveň,
									//kdy není překročena maximální délka řetězce.
									//počáteční hodnota proměnné (=inicializace) k=0.
									//Po každém cyklu se "k" zvětší o 1 (++k)
	{

		switch(input[k])		//zkoumá, který ze znaků je uložený na indexu "k"
		{
		
		case 48:			//#48 v ASCII kódu = "0"
			
			p*=10;			//"p" se vynásobí deseti
			
			break;			//vyskočí z příkazu switch

		case 49:			//#49 v ASCII kódu = "1"
			
			p*=10;			//"p" se vynásobí deseti
			p+=1;			//k "p" přičte 1			
			
			break;			//vyskočí z příkazu switch

		case 50:			//#50 v ASCII kódu = "2"
			
			p*=10;			//"p" se vynásobí deseti
			p+=2;			//k "p" přičte 2
			
			break;			//vyskočí z příkazu switch

		case 51:			//#51 v ASCII kódu = "3"

			p*=10;			//"p" se vynásobí deseti
			p+=3;			//k "p" přičte 3
			
			break;			//vyskočí z příkazu switch

		case 52:			//#52 v ASCII kódu = "4"
			
			p*=10;			//"p" se vynásobí deseti
			p+=4;			//k "p" přičte 4
			
			break;			//vyskočí z příkazu switch

		case 53:			//#53 v ASCII kódu = "5"
			
			p*=10;			//"p" se vynásobí deseti
			p+=5;			//k "p" přičte 5
			
			break;			//vyskočí z příkazu switch

		case 54:			//#54 v ASCII kódu = "6"
			
			p*=10;			//"p" se vynásobí deseti
			p+=6;			//k "p" přičte 6
			
			break;			//vyskočí z příkazu switch

		case 55:			//#55 v ASCII kódu = "7"

			p*=10;			//"p" se vynásobí deseti
			p+=7;			//k "p" přičte 7
			
			break;			//vyskočí z příkazu switch

		case 56:			//#56 v ASCII kódu = "8"

			p*=10;			//"p" se vynásobí deseti
			p+=8;			//k "p" přičte 8
			
			break;			//vyskočí z příkazu switch

		case 57:			//#57 v ASCII kódu = "9"

			p*=10;			//"p" se vynásobí deseti
			p+=9;			//k "p" přičte 9

			break;			//vyskočí z příkazu switch
		
		default:		//pokud bude na indexu "k" cokoliv jiného

			if (input[0]==43 && n==0)	//pokud je na 1. místě (nultý index) v řetězci "+"
									//(#43 v ASCII kódu = "+")
			{
											
				n=1;		//do "n" vloží 1
				break;		//vyskočí z příkazu switch
			
			}
			
			return false;		//funkce vrátí hodnotu false a skončí (pokud nebylo zadáno číslo,
									
		}

	}
	
	*output=p;			//do "v" se vloží "p"
	return true;		//funkce vratí hodnotu true (pokud vše proběhlo v pořádku)
}

bool StringUtil::string_to_double( /*const char**/ string input, double *output )
{
	
	int l=1,i=1,m=0,n=0;	/*	k - určuje, který index pole bude aktuálně zkoumán
								*	l - u zadání desetinného čísla určuje, na které pozici od desetinné tečky
								*		se zkoumaný znak nachází (např. když bylo zadáno 4.2589 a je právě zkoumána
										2. pozice za desetinnou tečkou ("5"), tak se "l"=2
								*	i - slouží pro správné přiřazení určitého čísla za desetinnou tečkou
										(aby se po operaci "p"+"t" dostali všechna čísla na správné místo)
								*	m - určuje, zda byla použita desetinná tečka
								*	n - určuje, zda bylo na začátku řetězce použito "-" popř. "+"
								*/
	double p=0,t=0;				/*	p - ukladá se zde převedené číslo v reálné formě
								*	t - ukládá se zde aktuální zkoumané číslo za desetinnou tečkou,
										postupně se přesouvá na správné místo a poté se přičte k "p"
								*/

	for (unsigned int k = 0; input[k] != 0 && k < input.length()/*strlen(input)*/; ++k)	//opakuje smyčku ve chvíli, kdy není konec řetězce a zároveň,
									//kdy není překročena maximální délka řetězce.
									//počáteční hodnota proměnné (=inicializace) k=0.
									//Po každém cyklu se "k" zvětší o 1 (++k)
	{

		switch(input[k])			//zkoumá, který ze znaků je uložený na indexu "k"
		{
		
		case 48:				//#48 v ASCII kódu = "0"

			if (m==0)			//pokud bude m=0 (=nebyla zadána desetinná tečka)
			{

				p*=10;			//"p" se vynásobí deseti
				
			}
			else
			{
			
				++l;			//jinak zvětší "l" o 1
				
			}

			break;				//vyskočí z příkazu switch

		case 49:				//#49 v ASCII kódu = "1"

			if (m==0)			//pokud bude m=0 (=nebyla zadána desetinná tečka)
			{

				p*=10;			//"p" se vynásobí deseti
				p+=1;			//k "p" přičte 1

			}
			else
			{
			
				t=1;			//jinak (=pokud byla zadána desetinná tečka) do "t" vloží 1

				while (i<=l)	//ve chíli, kdy bude "i"<="l" opakuje smyčku
								//(slouží pro správné umístění čísla za desetinnou tečku)
				{
				
					t/=10;		//"t" se vydělí deseti
					++i;		//"i" se zvětší o 1
				
				}

				i=1;			//do "i" se vloží 1
				++l;			//"l" se zvětší o 1
				p+=t;			//k "p" se přičte "t"
			
			}

			break;				//vyskočí z příkazu switch

		case 50:				//#50 v ASCII kódu = "2"

			if (m==0)			//pokud bude m=0 (=nebyla zadána desetinná tečka)
			{

				p*=10;			//"p" se vynásobí deseti
				p+=2;			//k "p" přičte 2

			}
			else
			{
			
				t=2;			//jinak (=pokud byla zadána desetinná tečka) do "t" vloží 2

				while (i<=l)	//ve chíli, kdy bude "i"<="l" opakuje smyčku
								//(slouží pro správné umístění čísla za desetinnou tečku)
				{
				
					t/=10;		//"t" se vydělí deseti
					++i;		//"i" se zvětší o 1
				
				}

				i=1;			//do "i" se vloží 1
				++l;			//"l" se zvětší o 1
				p+=t;			//k "p" se přičte "t"
			
			}

			break;				//vyskočí z příkazu switch

		case 51:				//#51 v ASCII kódu = "3"

			if (m==0)			//pokud bude m=0 (=nebyla zadána desetinná tečka)
			{

				p*=10;			//"p" se vynásobí deseti
				p+=3;			//k "p" přičte 3

			}
			else
			{
			
				t=3;			//jinak (=pokud byla zadána desetinná tečka) do "t" vloží 3

				while (i<=l)	//ve chíli, kdy bude "i"<="l" opakuje smyčku
								//(slouží pro správné umístění čísla za desetinnou tečku)
				{
				
					t/=10;		//"t" se vydělí deseti
					++i;		//"i" se zvětší o 1
				
				}

				i=1;			//do "i" se vloží 1
				++l;			//"l" se zvětší o 1
				p+=t;			//k "p" se přičte "t"
			
			}

			break;				//vyskočí z příkazu switch

		case 52:				//#52 v ASCII kódu = "4"

			if (m==0)			//pokud bude m=0 (=nebyla zadána desetinná tečka)
			{

				p*=10;			//"p" se vynásobí deseti
				p+=4;			//k "p" přičte 4

			}
			else
			{
			
				t=4;			//jinak (=pokud byla zadána desetinná tečka) do "t" vloží 4

				while (i<=l)	//ve chíli, kdy bude "i"<="l" opakuje smyčku
								//(slouží pro správné umístění čísla za desetinnou tečku)
				{
				
					t/=10;		//"t" se vydělí deseti
					++i;		//"i" se zvětší o 1
				
				}

				i=1;			//do "i" se vloží 1
				++l;			//"l" se zvětší o 1
				p+=t;			//k "p" se přičte "t"
			
			}

			break;				//vyskočí z příkazu switch

		case 53:				//#53 v ASCII kódu = "5"

			if (m==0)			//pokud bude m=0 (=nebyla zadána desetinná tečka)
			{

				p*=10;			//"p" se vynásobí deseti
				p+=5;			//k "p" přičte 5

			}
			else
			{
			
				t=5;			//jinak (=pokud byla zadána desetinná tečka) do "t" vloží 5

				while (i<=l)	//ve chíli, kdy bude "i"<="l" opakuje smyčku
								//(slouží pro správné umístění čísla za desetinnou tečku)
				{
				
					t/=10;		//"t" se vydělí deseti
					++i;		//"i" se zvětší o 1
				
				}

				i=1;			//do "i" se vloží 1
				++l;			//"l" se zvětší o 1
				p+=t;			//k "p" se přičte "t"
			
			}

			break;				//vyskočí z příkazu switch

		case 54:				//#54 v ASCII kódu = "6"

			if (m==0)			//pokud bude m=0 (=nebyla zadána desetinná tečka)
			{

				p*=10;			//"p" se vynásobí deseti
				p+=6;			//k "p" přičte 6

			}
			else
			{
			
				t=6;			//jinak (=pokud byla zadána desetinná tečka) do "t" vloží 6

				while (i<=l)	//ve chíli, kdy bude "i"<="l" opakuje smyčku
								//(slouží pro správné umístění čísla za desetinnou tečku)
				{
				
					t/=10;		//"t" se vydělí deseti
					++i;		//"i" se zvětší o 1
				
				}

				i=1;			//do "i" se vloží 1
				++l;			//"l" se zvětší o 1
				p+=t;			//k "p" se přičte "t"
			
			}

			break;				//vyskočí z příkazu switch

		case 55:				//#55 v ASCII kódu = "7"

			if (m==0)			//pokud bude m=0 (=nebyla zadána desetinná tečka)
			{

				p*=10;			//"p" se vynásobí deseti
				p+=7;			//k "p" přičte 7

			}
			else
			{
			
				t=7;			//jinak (=pokud byla zadána desetinná tečka) do "t" vloží 7

				while (i<=l)	//ve chíli, kdy bude "i"<="l" opakuje smyčku
								//(slouží pro správné umístění čísla za desetinnou tečku)
				{
				
					t/=10;		//"t" se vydělí deseti
					++i;		//"i" se zvětší o 1
				
				}

				i=1;			//do "i" se vloží 1
				++l;			//"l" se zvětší o 1
				p+=t;			//k "p" se přičte "t"
			
			}

			break;				//vyskočí z příkazu switch

		case 56:				//#56 v ASCII kódu = "8"

			if (m==0)			//pokud bude m=0 (=nebyla zadána desetinná tečka)
			{

				p*=10;			//"p" se vynásobí deseti
				p+=8;			//k "p" přičte 8

			}
			else
			{
			
				t=8;			//jinak (=pokud byla zadána desetinná tečka) do "t" vloží 8

				while (i<=l)	//ve chíli, kdy bude "i"<="l" opakuje smyčku
								//(slouží pro správné umístění čísla za desetinnou tečku)
				{
				
					t/=10;		//"t" se vydělí deseti
					++i;		//"i" se zvětší o 1
									
				}

				i=1;			//do "i" se vloží 1
				++l;			//"l" se zvětší o 1
				p+=t;			//k "p" se přičte "t"
			
			}

			break;				//vyskočí z příkazu switch

		case 57:				//#57 v ASCII kódu = "9"

			if (m==0)			//pokud bude m=0 (=nebyla zadána desetinná tečka)
			{

				p*=10;			//"p" se vynásobí deseti
				p+=9;			//k "p" přičte 9
				
			}
			else
			{
			
				t=9;			//jinak (=pokud byla zadána desetinná tečka) do "t" vloží 9

				while (i<=l)	//ve chíli, kdy bude "i"<="l" opakuje smyčku
								//(slouží pro správné umístění čísla za desetinnou tečku)
				{
				
					t/=10;		//"t" se vydělí deseti
					++i;		//"i" se zvětší o 1
				
				}

				i=1;			//do "i" se vloží 1
				++l;			//"l" se zvětší o 1
				p+=t;			//k "p" se přičte "t"
			
			}

			break;				//vyskočí z příkazu switch
		
		default:		//pokud bude na indexu "k" cokoliv jiného

			if (input[0]==43 && n==0)	//pokud je na 1. místě (nultý index) v řetězci "+"
									//(#43 v ASCII kódu = "+")
			{
											
				n=1;				//do "n" vloží 1
				break;				//vyskočí z příkazu switch
			
			}

			if (input[0]==45 && n==0)	//pokud je na 1. místě (nultý index) v řetězci "-"
									//(#45 v ASCII kódu = "-")
			{
			
				n=1;				//do "n" vloží 1
				break;				//vyskočí z příkazu switch

			}
			
			if (input[k]==46 && m==0)	//pokud je v řetězci "." a zároveň ještě žádná nebyla zadána (#46 v ASCII kódu = ".")
			{
											
				m=1;				//do "m" vloží 1
				break;				//vyskočí z příkazu switch
			
			}

			return false;			//funkce vrátí hodnotu false a skončí (pokud nebylo zadáno číslo,
								    //nebo je zadáno 'zmršeně' (např. byly zadány 2 desetinné tečky))
		
		}

	}

	if (input[0] == 45)		//pokud bude na 1 místě (nultý index) v řetězci "-"
						//(#45 v ASCII kódu = "-")
	{
	
		p *= -1;			//"p" se vynásobí -1
	
	}

	*output = p;				//do "v" se vloží "p"
	return true;			//funkce vratí hodnotu true (pokud vše proběhlo v pořádku)

}

//==== Convert Point to a string with values separated by spaces ====//
/*string StringUtil::Point_to_string(const Point & vec, const char* format)
{
    char buff[512];
    sprintf(buff,format,vec[0],vec[1],vec[2]);
    return string(buff);
}
*/

//==== Cound Number of Chars that match c =====//
int StringUtil::count_char_matches( string & str, char c )
{
    int cnt = 0;
    for ( int i = 0 ; i < ( int )str.size() ; i++ )
    {
        if ( str[i] == c )
        {
            cnt++;
        }
    }

    return cnt;
}


//==== Compute A Hash From String (Not Unique but Close I Think) =====//
int StringUtil::compute_hash( const string & str )
{
    int hash = 0;

    for ( int i = 0 ; i < (int)str.size() ; i++ )
    {
        hash += str[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    // final avalanche
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;
}


//==== Compute A Hash From String (Not Unique but Close I Think) =====//
string StringUtil::to_lower_case( const string & str )
{
	string strOut = "";
    for ( int i = 0 ; i < (int)str.size() ; i++ )
    {
		if (str[i] >= 65 && str[i] <= 90)
		{
			strOut.push_back(str[i] + 32);
		}
		else
		{
			strOut.push_back(str[i]);
		}
    }
	
    return strOut;
}