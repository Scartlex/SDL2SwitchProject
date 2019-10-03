#ifndef LTIME_H_
#define LTIME_H_

#include <SDL.h>


class Timer {
    public:
        //Initializes variables
        Timer(void);

        //The various clock actions
        void start(void);
        void stop(void);
        void pause(void);
        void unpause(void);

        //Gets the timer's time
        Uint32 getTicks(void);

        //Checks the status of the timer
        bool isStarted(void);
        bool isPaused(void);

    private:
        //The clock time when the timer started
        Uint32 startTicks;

        //The ticks stored when the timer was paused
        Uint32 pausedTicks;

        //The timer status
        bool paused;
        bool started;
};

#endif