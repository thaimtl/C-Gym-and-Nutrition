#ifndef NUTRITION_H
#define NUTRITION_H

class Nutrition {
private:
    struct Macros 
    {
        float proteins = 0;
        float carbs = 0;
        float fats = 0;
    };
   int calories;
   float BMI;
public:
 
    int calculateCalories(float height, float weight, int age, char sex, int fitnessLevel);
    float calculateBMI(float height, float weight);
    Macros calculateMacros(int planChoice) const;
};

#endif

