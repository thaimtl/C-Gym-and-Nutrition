#ifndef WORKOUT_H
#define WORKOUT_H
#include <string>
using namespace std;
class WorkOut
{
private:
	int reps = 0;
	int sets = 0;
	string weightTrained = "";
	int duration = 0;
	const float TIME_PER_SET = 30.0/60; // To optimally develop the muscles, it takes 30-40s to complete a set and 1-2 minutes to rest between sets according to https://www.mensjournal.com/health-fitness/gain-big-with-time-under-tension-training#:~:text=Time%20your%20sets%20so%20they,get%20there%20is%20also%20crucial.
	const int TIME_REST= 1;
public:
	WorkOut(int goal);
	int getReps() const;
	int getSets() const;
	string getWeightTrained() const;
	int getDuration(int numofExercises);
};
#endif

