#include "WorkOut.h"
#include <string>
#include <cmath>
// This constructor initializes the reps, sets, and weightTrained based on the user's goal
WorkOut::WorkOut(int goal)
// These values are inspired from Vanier College's 2022 Online Edition of Physical Education Manual by Shawna Lamvbert
// and https://www.healthline.com/health/fitness-exercise/how-many-exercises-per-muscle-group
{
	if (goal == 1)
	{
		reps = 8;
		sets = 3;
		weightTrained = "5-10 lbs";
	}
	else if (goal == 2)
	{
		reps = 10;
		sets = 4;
		weightTrained = "15-25 lbs";
	}
	else
	{
		reps = 15;
		sets = 3;
		weightTrained = "30-35+ lbs";

	}

}
int WorkOut:: getReps() const
{

	return reps;
}
int WorkOut:: getSets() const
{
	return sets;
}
string WorkOut::getWeightTrained() const
{

	return weightTrained ;

}
// This function calculates and returns the duration of the workout based on the number of exercises
int WorkOut::getDuration(int numberOfExercises)
{
	duration = round(numberOfExercises *(TIME_PER_SET + TIME_REST )* sets);
	return duration;

}