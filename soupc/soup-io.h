#ifndef SOUPC_IO
#define SOUPC_IO

#include <SDL3/SDL_intrin.h>

typedef enum _FILE_ERROR
{
	FILE_SUCCESS,
	FILE_NOT_FOUND,
	FILE_WRITE_ACCESS,
	FILE_READ_ACCESS,
	FILE_ERROR_SPECIAL,
} FILE_ERROR;

typedef struct _SoupFile{
	char *bfr;
	Uint64 size;
}SoupFile;

//Copies the file contents to a bfr.
//If there is an error. 
SoupFile* CopyFile(const char *filename);

#endif // !SOUPIO

#ifdef IMPLEMENT_SOUP_IO
SoupFile* CopyFile(const char *filename)
{
	//OpenFile
	//Find file bytes.
	//Allocate buffer to fit file bytes.
	//Copy contents from file to buffer.
	//return buffer.
}
#endif 
