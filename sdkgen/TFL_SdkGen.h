/*
#############################################################################################
# TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51										
# ========================================================================================= #
# File: TFL_SdkGen.h																		
# ========================================================================================= #
# Credits: uNrEaL, Tamimego, SystemFiles, R00T88, _silencer, the1domo, K@N@VEL				
# Thanks: HOOAH07, lowHertz																	
# Forums: www.uc-forum.com, www.gamedeception.net											
# ========================================================================================= #
# This work is licensed under the															
# Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License.				
# To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/3.0/	
# or send a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View,		
# California, 94041, USA.																	
#############################################################################################
*/

#include <Windows.h>
#include <stdio.h>
#include <direct.h>

#include <iostream>
#include <sstream>
#include <iomanip>

#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "TFL_HT.h"

using namespace std;

/*
# ========================================================================================= #
# Game Specific Includes (UE3 Basic Core)													
# ========================================================================================= #
*/

// Super Monday Night Combat
#include "UE3BasicCore\SMNC\GameDefines.h"
#include "UE3BasicCore\SMNC\ObjectFunctions.h"
#include "UE3BasicCore\SMNC\PiecesOfCode.h"

/*
# ========================================================================================= #
# Defines																					
# ========================================================================================= #
*/

// Generator
#define SDK_GEN_VER				"v1.4_Beta-Rev.51"
#define SDK_GEN_CREDITS			"uNrEaL, Tamimego, SystemFiles, R00T88, _silencer, the1domo, K@N@VEL"
#define SDK_GEN_FORUMS			"www.uc-forum.com, www.gamedeception.net"
#define SDK_GEN_STHANKS			"HOOAH07, lowHertz"
#define SDK_BASE_DIR			"C:\\TFL_SDK_GEN"
#define SDK_BUFF_SIZE			256			
#define SDK_COL1				50
#define SDK_COL2				50
#define SDK_NO_STR				true

/*
# ========================================================================================= #
# Define Macros																					
# ========================================================================================= #
*/

#define SDKFN_PRINT( file, stream )		fprintf ( file, "%s", stream.str().c_str() ); stream.str ( string() );
#define SDKFN_EMPTY( stream )			stream.str ( string() );
#define SDKMC_SSDEC( value, width )		dec << setfill ( '0' ) << setw ( width ) << right << value
#define SDKMC_SSHEX( value, width )		"0x" << hex << uppercase << setfill ( '0' ) << setw ( width ) << right << value << nouppercase 
#define SDKMC_SSCOL( string, width )	setfill ( ' ' ) << setw ( width ) << left << string

/*
# ========================================================================================= #
# Typedefs																				
# ========================================================================================= #
*/

typedef map< string, unsigned int >	StrIntM_t;
typedef multimap< string, string >	StrStrMm_t;
typedef pair< string, string >		StrStrPair_t;

/*
# ========================================================================================= #
# Globals																					
# ========================================================================================= #
*/

FILE*				pFile						= NULL;
FILE*				pLog						= NULL;
char				cBuffer[ SDK_BUFF_SIZE ]	= { NULL };
vector< UObject* >	vIncludes;

/*
# ========================================================================================= #
# Functions																					
# ========================================================================================= #
*/

// DllMain
void			OnAttach						();

// Initialization
void			Init_Core						();

// Finalization
void			Final_SdkHeaders				();

// Process Objects by Package
void			ProcessPackages					();
void			ProcessScriptStructsByPackage	( UObject* pPackageToProcess );
void			ProcessConstsByPackage			( UObject* pPackageToProcess );
void			ProcessEnumsByPackage			( UObject* pPackageToProcess );
void			ProcessClassesByPackage			( UObject* pPackageToProcess );
void			ProcessFuncStructsByPackage		( UObject* pPackageToProcess );
void			ProcessFuncsByPackage			( UObject* pPackageToProcess );

// Generate Code
void			GenerateConst					( UConst* pConst );
void			GenerateEnum					( UEnum* pEnum );
void			GenerateScriptStruct			( UScriptStruct* pScriptStruct );
void			GenerateScriptStructPre			( UScriptStruct* pScriptStruct, UObject* pPackageToProcess );
void			GenerateFuncStruct				( UClass* pClass );
void			GenerateFuncDef					( UClass* pClass );
void			GenerateFuncDec					( UClass* pClass );
void			GenerateVirtualFunc				( UClass* pClass );
void			GenerateClass					( UClass* pClass );
void			GenerateClassPre				( UClass* pClass, UObject* pPackageToProcess );

// object utils
UScriptStruct*	FindBiggestScriptStruct			( string ScriptStructFullName );

// Property Utils
int				GetPropertyType					( UProperty* pProperty, string& sPropertyType, bool bFuncRet );
unsigned long	GetPropertySize					( UProperty* pProperty );
bool			SortProperty					( UProperty* pPropertyA, UProperty* pPropertyB );
bool			SortPropertyPair				( pair< UProperty*, string > pPropertyA, pair< UProperty*, string > pPropertyB );

// String Utils
string			GetValidName					( const string& sName );
string			ToS								( const wchar_t* wcOrig );
string			ToS								( const char* cOrig );
bool			StrStrMm_Exist					( const StrStrMm_t& StrStrMm, string sKey, string sValue );

// Print Code
void			PrintFileHeder					( char* cFileName, char* cFileExt, bool setPP );
void			PrintFileFooter					();
void			PrintSectionHeader				( char* cSectionName );

// Generate Flags
void			GetAllPropertyFlags				( int PropertyFlags, ostringstream& ssStreamBuffer );
void			GetAllFunctionFlags				( unsigned long FunctionFlags, ostringstream& ssStreamBuffer );