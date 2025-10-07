#ifndef SOUPC_DATATYPES
#define SOUPC_DATATYPES

typedef struct _SoupCDyanmicArray{
	void *data;
	int stored;
	int limit;
}DynamicArray;

#endif // !SOUPC_DATATYPES

//================================================================================================//

#define SOUPC_DATATYPES_IMPLEMENTED
#ifdef SOUPC_DATATYPES_IMPLEMENTED

DynamicArray* SoupInitDynamicArray(const char *type){
}

#endif // SOUPC_DATATYPES_IMPLEMENTED


