
#include "Nutrition.h"
// This function calculates the macros based on the user's choice of diet plan and their suggested consumption of calories
Nutrition::Macros Nutrition::calculateMacros(int planChoice) const
{
    Macros macros;
    if (planChoice == 1)
     // These formulas are taken from https://www.healthline.com/nutrition/how-to-count-macros#step-by-step//
    // High carb diet
    {
		macros.proteins = 0.3 * calories/4;
		macros.carbs = 0.4 * calories/4;
		macros.fats = 0.3 * calories/9;
	}
    // High protein diet
    else if (planChoice == 2)
    {
		macros.proteins = 0.4 * calories/4;
		macros.carbs = 0.3 * calories/4;
		macros.fats = 0.3 * calories/9;
	}
    else
    // High protein, high carb, low fat diet
    {
		macros.proteins = 0.4 * calories/4;
		macros.carbs = 0.4 * calories/4;
		macros.fats = 0.2 * calories/9;
	}


    return macros; // It returns the struct Macros (which contains the proteins, carbs, and fats) 
}
// This function calculates and returns the BMI
float Nutrition::calculateBMI(float height, float weight)
{
    // BMI = weight (kg) / (height (m) * height (m))
    BMI = weight / (height/100 * height/100);
	return BMI;
}
// This function calculates and returns the recommended daily intake of calories based on the user's height, weight, age, sex, and fitness level
int Nutrition::calculateCalories(float height, float weight, int age, char sex, int fitnessLevel)
// These formulas are taken from https://www.healthline.com/nutrition/how-to-count-macros#step-by-step//
{
    if (sex == 'M')
    {
        if (fitnessLevel == 1)
        {
            calories = (10 * weight + 6.25 * height - 5 * age + 5)*1.375;
  

        }
        else if (fitnessLevel == 2)
        {
            calories = (10 * weight + 6.25 * height - 5 * age + 5)*1.55;
		}
        else
        {
            calories = (10 * weight + 6.25 * height - 5 * age + 5)*1.725;
        }
    }
    else
    {
        if (fitnessLevel == 1)
        {
            calories = (10 * weight + 6.25 * height - 5 * age - 161)*1.375;
		}
        else if (fitnessLevel == 2)
        {
            calories = (10 * weight + 6.25 * height - 5 * age - 161)*1.55;
		}
        else
        {
            calories = (10 * weight + 6.25 * height - 5 * age - 161)*1.725;
		}
	}
	return calories;
}
