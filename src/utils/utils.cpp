#include "utils.hpp"

void Error_HandleSDL(SDL_LogPriority priority, SDL_LogCategory category, const char* err_src){
	const char* err_msg = SDL_GetError();
	switch (priority) {
        case SDL_LOG_PRIORITY_INVALID:
        case SDL_LOG_PRIORITY_TRACE:
        case SDL_LOG_PRIORITY_VERBOSE:
        case SDL_LOG_PRIORITY_DEBUG:
        case SDL_LOG_PRIORITY_INFO:
        case SDL_LOG_PRIORITY_WARN:
			SDL_LogWarn(category, "%s, %s", err_msg, err_src);
        case SDL_LOG_PRIORITY_ERROR:
        case SDL_LOG_PRIORITY_CRITICAL:
        case SDL_LOG_PRIORITY_COUNT:
          break;
        }
}

