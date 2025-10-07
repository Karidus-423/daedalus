#ifndef SOUPC_IO
#define SOUPC_IO

#include <SDL3/SDL.h>
#include <SDL3/SDL_filesystem.h>
#include <SDL3/SDL_intrin.h>
#include <SDL3/SDL_iostream.h>
#include <SDL3/SDL_stdinc.h>
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
	Sint64 size;
}SoupFile;

//Get all the filepaths for the files present in the provided directory.
//@param | const char *path : Path to scan for files.
//@return: Returns NULL if provided path does not exist or couldn't be found.
//==Warning: Does not scan subdirectories.==
// char** GetDirectoryFilePaths(const char *path);

//Read the entire file and return a char *bfr.
//@param | const char *filename: file to read its entire contents.
//@return: Returns a SoupFile* struct. If bfr is NULL, then an error occured.
SoupFile* SoupReadFile(const char* filename);
#endif // !SOUPIO

//================================================================================================//

#define IMPLEMENT_SOUP_IO
#ifdef IMPLEMENT_SOUP_IO
SoupFile* SoupReadFile(const char* filename){
	SDL_IOStream* stream = SDL_IOFromFile(filename, "r");
	Sint64 stream_size = SDL_GetIOSize(stream);

	char* bfr = (char*)SDL_malloc(stream_size);
	if (bfr == NULL){
		return NULL;
	}

	SDL_ReadIO(stream,bfr ,stream_size);

	SoupFile* file = (SoupFile*)SDL_malloc(sizeof(SoupFile));
	file->bfr = bfr;
	file->size = stream_size;

	return file;
}
#endif 
