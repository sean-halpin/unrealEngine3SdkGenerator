//// Created with ReClass.NET by KN4CK3R
//
//class UField : public UObject
//{
//public:
//	class UField* pNext; //0x003C
//}; //Size: 0x0040
//
//class UStruct : public UField
//{
//public:
//	char pad_0040[8]; //0x0040
//	class UField* pSuperField; //0x0048
//	class UField* pChildren; //0x004C
//	uint32_t dwPropertySize; //0x0050
//	char pad_0054[48]; //0x0054
//}; //Size: 0x0084
//
//class UState : public UStruct
//{
//public:
//	char pad_0084[72]; //0x0084
//}; //Size: 0x00CC
//
//class UClass : public UState
//{
//public:
//	char pad_00CC[376]; //0x00CC
//}; //Size: 0x0244
//
//class UObject
//{
//public:
//	char pad_0004[28]; //0x0004
//	int32_t iObjectInternalInteger; //0x0020
//	char pad_0024[4]; //0x0024
//	class UObject* pOuter; //0x0028
//	int32_t iNameIndex; //0x002C
//	char pad_0030[4]; //0x0030
//	class UClass* pClass; //0x0034
//	class UObject* pObjectArchetype; //0x0038
//
//	virtual void Function0();
//	virtual void Function1();
//	virtual void Function2();
//	virtual void Function3();
//	virtual void Function4();
//	virtual void Function5();
//	virtual void Function6();
//	virtual void Function7();
//	virtual void Function8();
//	virtual void Function9();
//}; //Size: 0x003C
//
//class UName
//{
//public:
//	char pad_0000[16]; //0x0000
//	char N00000502[16]; //0x0010
//}; //Size: 0x0020
//
//class pTmp
//{
//public:
//	char pad_0000[4]; //0x0000
//}; //Size: 0x0004
//
//class UEnum : public UField
//{
//public:
//	class pTmp* pNames; //0x0040
//	int32_t iNum; //0x0044
//	int32_t iMax; //0x0048
//}; //Size: 0x004C
//
//class UConst : public UField
//{
//public:
//	class pTmp* pValue; //0x0040
//	int32_t iNum; //0x0044
//	int32_t iMax; //0x0048
//}; //Size: 0x004C
//
//class UScriptStruct : public UStruct
//{
//public:
//	char pad_0084[28]; //0x0084
//}; //Size: 0x00A0
//
//class UFunction : public UStruct
//{
//public:
//	uint32_t dwFunctionFlags; //0x0084
//	uint16_t wNative; //0x0088
//	uint16_t wRepOffset; //0x008A
//	int32_t iFNameIndex; //0x008C
//	uint32_t dwFNameUnknownData; //0x0090
//	uint16_t wNumParams; //0x0094
//	uint16_t wParamSize; //0x0096
//	uint32_t dwReturnValueOffset; //0x0098
//	char pad_009C[4]; //0x009C
//	class pTmp* pFunc; //0x00A0
//}; //Size: 0x00A4
//
//class UProperty : public UField
//{
//public:
//	uint32_t dwArrayDim; //0x0040
//	uint32_t dwElementSize; //0x0044
//	uint32_t dwPropertyFlagsA; //0x0048
//	uint32_t dwPropertyFlagsB; //0x004C
//	uint32_t dwPropertySize; //0x0050
//	char pad_0054[12]; //0x0054
//	uint32_t dwOffset; //0x0060
//	char pad_0064[24]; //0x0064
//}; //Size: 0x007C
//
//class UByteProperty : public UProperty
//{
//public:
//	class UEnum* pEnum; //0x007C
//}; //Size: 0x0080
//
//class UIntProperty : public UProperty
//{
//public:
//
//}; //Size: 0x007C
//
//class UFloatProperty : public UProperty
//{
//public:
//
//}; //Size: 0x007C
//
//class UBoolProperty : public UProperty
//{
//public:
//	uint32_t dwBitMask; //0x007C
//}; //Size: 0x0080
//
//class UNameProperty : public UProperty
//{
//public:
//
//}; //Size: 0x007C
//
//class UStrProperty : public UProperty
//{
//public:
//
//}; //Size: 0x007C
//
//class UDelegateProperty : public UProperty
//{
//public:
//	char pad_007C[8]; //0x007C
//}; //Size: 0x0084
//
//class UObjectProperty : public UProperty
//{
//public:
//	class UClass* pPropertyClass; //0x007C
//}; //Size: 0x0080
//
//class UClassProperty : public UObjectProperty
//{
//public:
//	class UClass* pMetaClass; //0x0080
//	char pad_0084[4]; //0x0084
//}; //Size: 0x0088
//
//class UInterfaceProperty : public UProperty
//{
//public:
//	class UClass* pInterfaceClass; //0x007C
//}; //Size: 0x0080
//
//class UStructProperty : public UProperty
//{
//public:
//	class UStruct* pStruct; //0x007C
//}; //Size: 0x0080
//
//class UArrayProperty : public UProperty
//{
//public:
//	class UProperty* pInner; //0x007C
//}; //Size: 0x0080
//
//class UMapProperty : public UProperty
//{
//public:
//	class UProperty* pKey; //0x007C
//	class UProperty* pValue; //0x0080
//}; //Size: 0x0084
//
//class TArrayTMP
//{
//public:
//	char pad_0000[20]; //0x0000
//}; //Size: 0x0014
//
//class TArray
//{
//public:
//	class TArrayTMP* pData; //0x0000
//	int32_t Count; //0x0004
//	int32_t Max; //0x0008
//}; //Size: 0x000C
//
//class UWorld : public UObject
//{
//public:
//	char pad_003C[12]; //0x003C
//	TArray Levels; //0x0048
//	char pad_0054[600]; //0x0054
//}; //Size: 0x02AC
//
//class ULevelBase : public UObject
//{
//public:
//	TArray Actors; //0x003C
//	char pad_0048[12]; //0x0048
//}; //Size: 0x0054
//
//class ULevel : public ULevelBase
//{
//public:
//	char pad_0054[276]; //0x0054
//	float LightmapTotalSize; //0x0168
//	float ShadowmapTotalSize; //0x016C
//	char pad_0170[440]; //0x0170
//}; //Size: 0x0328