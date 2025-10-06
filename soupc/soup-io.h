#ifndef SOUPC_IO
#define SOUPC_IO

#include <SDL3/SDL_intrin.h>
#include <SDL3/SDL_storage.h>

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

//Get all the filepaths for the files present in the provided directory.
//==Warning: Does not scan subdirectories.==
char** GetDirectoryFiles(const char *directory);

#endif // !SOUPIO


#define IMPLEMENT_SOUP_IO
#ifdef IMPLEMENT_SOUP_IO
// char** GetDirectoryFilePaths(const char *directory)
// {
// }
#endif 
