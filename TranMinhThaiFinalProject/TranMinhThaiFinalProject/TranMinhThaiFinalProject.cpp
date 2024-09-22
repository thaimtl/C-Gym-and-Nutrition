// TranMinhThaiFinalProject.cpp 
// Developer: Minh Thai Tran
// Vanier Student ID: 2214926
// This program provides workout and nutrition plans based on the user's fitness goal and biometric characteristics that they provide.
// It provides customized plans by using the information provided by the user in the account creation process.
// Workout plans are customized based on the F.I.T.T. principle (Frequency, Intensity, Time, Type) and the user's fitness goal.
// Demonstrations of how to perform the exercises are provided through YouTube links of well-known fitness channels.
// Nutritional informations are taken from trusted sources such as healthline.com
/////////////////////////////////////////////////////////// FOR THE MANAGER OF THE APPLICATION ///////////////////////////////////////////////////////////////////
// A text file named "userTracking.txt" that keeps track of the number of users and their usernames is stored in the same directory as the classes and source code
// A text file named "feedback.txt" that keeps track of the feedbacks submitted by the users is stored in the same directory as the classes and source code
// These two files are sorted in lexicographical order of the usernames each time a new user is created or a new feedback is submitted
// In the same directory, the other text files are text files with the usernames of the users as their names. These files store all the user's information.
// Currently, there are 19 users in the program, thus 19 text files with the usernames of the users as their names.
#include <iostream>
#include <cctype>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Nutrition.h"
#include "WorkOut.h"

using namespace std;
struct User
{
	string username = "";
	string password = "";
	string name = "";
	char sex = 'N';
	int fitnessGoal = 0;
	int age = 0;
	float height = 0;
	float weight=0;
};
// Function prototypes
void displayLoginMenu(User& user, int& choice);
// Login menu 
bool login(User* userptr);
void createAccount(User& user); 
// Main menu
void displayMainMenu(int&, string [], int);
// Workout
void displayWorkout(const string& title, const string exercises[], const string youtubeLinks[], int numExercises, WorkOut& workout, int fitnessGoal);
// Nutrition
void displayGeneralAdvice();
void displayCaloricIntake(Nutrition& nutrition, User& user);
void displayBMI(Nutrition& nutrition, User& user);
void rankBMI(float);
int getPlanChoice();
void displayMacros(Nutrition& nutrition, int planChoice);
void displayMealPlan();
// Update profile
void updateUserProfile(User& user);
// Feedback
void submitFeedback(User& user);
void selectionSort(vector<string>& arr);
// Main function
int main()
{
	int choice;
	User user;
	cout << " Welcome to Your Personal Trainer!" << endl;
	cout << "This program will help you to create your work-out and nutrition plans." << endl;
	cout << "!Warning: Users under 16 years old should be supervised by an adult when practicing the work-out plans to avoid injury!" << endl;
	cout << "To continue, please login or create an account." << endl;
	displayLoginMenu(user, choice);
	
	
	int option;	
	string header[4] = { "Name of exercise", "Reps", "Sets", "Weight" };
	string menuOptions[] = {
		"Chest exercises",
		"Arm exercises",
		"Leg exercises",
		"Back exercises",
		"Nutrition Guidance",
		"Update your profile and change your fitness goal",
		"Submit feedback",
		"Exit the program"
	};
	int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);
	do
	{
		displayMainMenu(option, menuOptions, numOptions);
		switch (option)
		{
		case 1:
		{
			WorkOut workoutChest(user.fitnessGoal);
            string chestExercises[] = 
			{
                "Push-ups",
                "Bench press",
                "Dumbbell press",
                "Dips",
            };
			string youtubeLinksforChestExercises[] = 
			{ "https://www.youtube.com/watch?v=-0eYiItN2D8",
				"https://www.youtube.com/watch?v=vthMCtgVtFw",
				"https://www.youtube.com/watch?v=VmB1G1K7v94",
				"https://www.youtube.com/shorts/36krJZYK_dU" };
			int numExercises = sizeof(chestExercises) / sizeof(chestExercises[0]);
			displayWorkout("Chest exercises", chestExercises, youtubeLinksforChestExercises, numExercises, workoutChest, user.fitnessGoal);
			break;
		}
		case 2:
		{	
			WorkOut workoutArm(user.fitnessGoal);
			string armExercises[] = 
			{
				"Barbell curls",
				"Bicep curls",
				"Hammer curls",
				"Tricep extensions",
				"Concentration curls",
			};
			string youtubeLinksforArmExercises[5] = 
			{ "https://www.youtube.com/watch?v=kwG2ipFRgfo",
			"https://www.youtube.com/watch?v=ykJmrZ5v0Oo",
			"https://www.youtube.com/watch?v=zC3nLlEvin4",
			"https://www.youtube.com/shorts/4lWSTusBcmw",
			"https://www.youtube.com/shorts/YEgmqqn9obo" };

			int numExercises = sizeof(armExercises) / sizeof(armExercises[0]);
			displayWorkout("Arm exercises", armExercises, youtubeLinksforArmExercises, numExercises, workoutArm, user.fitnessGoal);
			break;
		}
		case 3:
		{
			WorkOut workoutLeg(user.fitnessGoal);
			string legExercises[] = 
			{
				"Squats",
				"Lunges",
				"Deadlifts",
				"Leg press",
			};
			string youtubeLinksforLegExercises[5] =
			{ "https://www.youtube.com/watch?v=m0GcZ24pK6k",
				"https://www.youtube.com/watch?v=whJex6mhaM4",
				"https://www.youtube.com/shorts/vfKwjT5-86k",
				"https://www.youtube.com/shorts/ZOHxJ8dhrxc",
			};
			int numExercises = sizeof(legExercises) / sizeof(legExercises[0]);
			displayWorkout("Leg exercises", legExercises, youtubeLinksforLegExercises, numExercises, workoutLeg, user.fitnessGoal);
			break;
		}
		case 4:
		{
			WorkOut workoutBack(user.fitnessGoal);
			string backExercises[] = 
			{
				"Pull-ups",
				"Deadlifts", 
				"Seated rows",
				"Lat pulldowns",
	
			}; 
			//Deadlift works multiple muscle groups, including the back, legs, and core. 

			string youtubeLinksforBackExercises[5] =
			{ "https://www.youtube.com/shorts/aRFqDO7XClU",
				"https://www.youtube.com/shorts/vfKwjT5-86k",
				"https://www.youtube.com/watch?v=UCXxvVItLoM",
				"https://www.youtube.com/watch?v=SALxEARiMkw",

			};
			int numExercises = sizeof(backExercises) / sizeof(backExercises[0]);
			displayWorkout("Back exercises", backExercises, youtubeLinksforBackExercises, numExercises, workoutBack, user.fitnessGoal);
			break;
		}
		case 5:
		{	Nutrition nutrition;

			cout << "-----Nutrition Guidance-----\n";
			displayGeneralAdvice();
			displayCaloricIntake(nutrition, user);
			displayBMI(nutrition, user);
			displayMacros(nutrition, getPlanChoice());
			displayMealPlan();

			break;
		}
		case 6:
		{
			updateUserProfile(user);
			break;
		}
		case 7:
		{
			submitFeedback(user);
			break;
		}
		case 8:
		{
			cout << "The program is now exiting. See you again!" << endl;
			exit(0);

		}
		}
		// Each time the user enters an option, the program will ask the user if they want to go back to the main menu or exit the program.
		cout << "----------------------------\n";
		cout << "Would you like to go back to the main menu or exit the program?\n";
		cout << "Enter Y to go back to the main menu or N to exit the program:\n";
		char goBack;
		cin >> goBack;
		while (goBack != 'Y' && goBack != 'y' && goBack != 'N' && goBack != 'n')
		{
			cout << "Invalid choice. Please enter Y or N." << endl;
			cin >> goBack;
		}
		// If the user chooses to go back to the main menu, the program will set the option to 0, which results in the do-while loop running again.
		if (goBack == 'Y' || goBack == 'y')
		{
			option = 0;
		}
		else
		{
			cout << "The program is now exiting. See you again!" << endl;
			exit(0);
		}
	} while (option !=1 && option !=2 && option !=3 && option !=4 && option !=5 && option !=6 && option !=7 && option != 8);
    return 0;
}
// End of main function
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////FUNCTION DEFINITIONS//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////LOGIN MENU FUNCTIONS//////////////////////////////////////////////////////////////////////////////////////////////////
// This function displays the login menu and allows the user to login or create an account or exit the program.
void displayLoginMenu(User& user, int& choice)
{

	do {
		cout << "----------------------------\n";
		cout << "	LOGIN MENU\n";
		cout << "1. Login" << endl;
		cout << "2. Create Account" << endl;
		cout << "3. Exit" << endl;
		cout << "----------------------------\n";
		cout << "Please enter your choice (1, 2 or 3): ";
		cin >> choice;
		while (choice != 1 && choice != 2 && choice != 3)
		{
			cout << "Please select a valid option (1, 2 or 3)" << endl;
			cin >> choice;
		}
		if (choice == 2)
		{
			createAccount(user);
			break;
		}
		else if (choice == 1)
		{
			char tryAgain;
			do 
			{
				if (login(&user)) 
				{
					cout << "Successfully logged in!" << endl;
					cout << "Welcome back, " << user.name << "!" << endl;
					return; // If login is successful, exit the function
				}
				// If login is unsuccessful, the program will ask the user if they want to try again
				cout << "Would you like to try again? (Y/N)" << endl;
				cin >> tryAgain;
			} while (toupper(tryAgain) == 'Y'); // toupper function is used to handle both lower and upper case input
			// If the user chooses not to try again, the program will go back to the login menu by changing the value of choice to 4, which results in the do-while loop running again
			cout << "Going back to the login menu...\n";
			choice = 4;
		}
		else if (choice == 3)
		{
			cout << "The program is now exiting. See you again!" << endl;
			exit(0);
		}
		else
		{
			cout << "Please select a valid option (1, 2 or 3)" << endl;
			cin >> choice;
		}
	} while (choice != 1 && choice != 2 && choice != 3);
}
// This function creates an account for the user by asking for their username, password
// and other biometric characteristics such as sex, age, height, weight and fitness goal.
// All the information is stored in a file named after the username of the user.
void createAccount(User& user)
{
	do
	{
		cout << "Enter your username: ";
		cin >> user.username;
		ifstream file(user.username + ".txt");
		if (file) {
			cout << "Username already exists. Please enter a different username." << endl;
		}
		else
		{
			file.close();
			break;
		}
	} while (true);
	cout << "Enter your password: ";
	cin >> user.password;
	cout << "Enter your first name and/or your last name: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This statement ignores the maximum number of characters until a newline character is found, clearing the input buffer.
	getline(cin, user.name);
	cout << "Enter your sex (M/F): ";
	cin >> user.sex;
	user.sex = toupper(user.sex);
	if (user.sex != 'M' && user.sex != 'F')
	{
		cout << "Invalid choice. Please enter M (for male) or F (for female)" << endl;
		cin >> user.sex;
	}
	cout << "This program will customize your work-out and nutrion plans based on your fitness goal\n";
	cout << "1. Beginner Level: Foundation and General Health" << endl;
	cout << "2. Intermediate Level: Muscle Building and Fat Loss" << endl;
	cout << "3. Advanced Level: Performance and Athleticism" << endl;
	cout << "Enter your fitness goal (1,2 or 3): ";
	cin >> user.fitnessGoal;
	if (user.fitnessGoal != 1 && user.fitnessGoal != 2 && user.fitnessGoal != 3)
	{
		cout << "Invalid choice. Please enter 1, 2 or 3." << endl;
		cin >> user.fitnessGoal;
	}
	cout << "Enter your age: ";
	cin >> user.age;
	while (user.age <= 0 || user.age > 120)
	{
		cout << "Invalid age. Please enter a valid age: ";
		cin >> user.age;
	}
	cout << "Enter your height (in cm): ";
	cin >> user.height;
	while (user.height <= 54 || user.height > 272) // The record of minimum height is 1'8" (54 cm) and the maximum height is 8'11" (272 cm)
	{
		cout << "Invalid height. Please enter a valid height: ";
		cin >> user.height;
	}
	cout << "Enter your weight (in kg): ";
	cin >> user.weight;
	while (user.weight <= 2 || user.weight > 650) // The record of minimum weight is 5 lbs (2 kg) and the maximum weight is 1433 lbs (650 kg)
	{
		cout << "Invalid weight. Please enter a valid weight: ";
		cin >> user.weight;
	}

	// Store the user's information in a file. Each piece of information is stored on a separate line.
	// The file name is the username of the user, which is unique
	ofstream file;
	file.open(user.username + ".txt");
	file << user.username << endl;
	file << user.password << endl;
	file << user.name << endl;
	file << user.sex << endl;
	file << user.fitnessGoal << endl;
	file << user.age << endl;
	file << user.height << endl;
	file << user.weight << endl;
	file.close();
	cout << "Welcome, " << user.name << "!" << endl;

	// Open the user tracking file
	ifstream userTrackingFileIn("userTracking.txt");
	int userCount;
	userTrackingFileIn >> userCount; // The first line of the file contains the number of users
	userTrackingFileIn.ignore(); // Ignore the newline character
	// Read all the usernames and store them in a vector
	vector<string> usernames;
	string username;
	while (getline(userTrackingFileIn, username))
	{
		usernames.push_back(username);
	}
	userTrackingFileIn.close();
	// Update the user tracking file
	usernames.push_back(user.username); // Add the new username to the vector
	selectionSort(usernames); // Sort the usernames in lexicographical order
	userCount++; // Increment the number of users
	ofstream userTrackingFileOut("userTracking.txt");
	userTrackingFileOut << userCount << endl; // Write the updated number of users to the file
	for (const auto& username : usernames)
	{
		userTrackingFileOut << username << endl; // Write all the usernames to the file
	}
}
// In this function, userptr is a pointer to the user struct. The function returns a boolean value, which is true if the user successfully logs in and false otherwise.
bool login(User* userptr)
{
	string u, p;
	cout << "Enter your username: ";
	cin >> u;
	cout << "Enter your password: ";
	cin >> p;
	ifstream read(u + ".txt");
	if (!read.is_open())
	{
		cout << "Username does not exist." << endl;
		return false;
	}
	// Read the username and password from the file and store them in the user struct, using the pointer userptr
	read >> userptr->username;
	read >> userptr->password;
	
	// Check if the username and password match
	if (u == userptr->username && p == userptr->password)
	{
		read.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(read, userptr->name);
		read >> userptr->sex;
		read >> userptr->fitnessGoal;
		read >> userptr->age;
		read >> userptr->height;
		read >> userptr->weight;
		read.close();
		return true;
	}
	else
	{
		cout << "Invalid username or password.\n";
		return false;
	}
}
////////////////////////////////////////////////// MAIN MENU FUNCTIONS ////////////////////////////////////////////////////////////////////////////////////////////////
// This function displays the main menu and allows the user to select an option from the menu.
void displayMainMenu(int& choice, string menuOptions[], int option)
{
	cout << "----------------------------\n";
	cout << "	MAIN MENU\n";
	for (int i = 0; i < option; i++)
	{
		cout << i + 1 << ". " << menuOptions[i] << "\n";
	}
	cout << "----------------------------\n";
	cout << "Enter your choice: ";
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8)
	{
		cout << "Invalid choice. Please enter a valid option (1, 2, 3, 4, 5, 6, 7 or 8)\n";
		cin >> choice;
	}
}
// This function displays the workout plan based on the user's fitness goal and the type of exercises they choose.
void displayWorkout(const string& title, const string exercises[], const string youtubeLinks[], int numExercises, WorkOut& workout, int fitnessGoal) 
{	
	// The following code is used to create and center the title of the table
	int tableWidth = 62; // The total width of the table
	int padding = (tableWidth - title.length()) / 2; // Calculate the padding needed to center the title
	cout << "+" << string(tableWidth, '-') << "+\n";
	cout << "|" << setw(padding) << "" << title << setw(tableWidth - title.length() - padding) << "" << "|\n"; // Use setw to add padding
	cout << "+" << string(tableWidth, '-') << "+\n";
	// The following code is used to create the table headers
	cout << "| " << right << setw(20) << "Name of exercise"
		<< " | " << right << setw(8) << "Reps"
		<< " | " << right << setw(8) << "Sets"
		<< " | " << right << setw(15) << "Weight" << " |\n";
	cout << "+----------------------+----------+----------+-----------------+\n";
	// The table body is consists of the exercises name, reps, sets, and weight trained
	for (int i = 0; i < numExercises; i++)
	{
		cout << "| " << right << setw(20) << exercises[i]
			<< " | " << right << setw(8) << workout.getReps()
			<< " | " << right << setw(8) << workout.getSets();
		if (exercises[i] == "Push-ups" || exercises[i] == "Pull-ups")
		{
			cout << " | " << right << setw(15) << "Body weight" << " |\n";
		}
		else
		{
			cout << " | " << right << setw(15) << workout.getWeightTrained() << " |\n";
		}
		cout << "+----------------------+----------+----------+-----------------+\n";
	}
	// The recommended frequency is based on the user's fitness goal (beginner, intermediate, or advanced). 
	// These frequencies are taken from Vanier College's 2022 Online Edition of Physical Education Manual by Shawna Lambert.
	cout << "Recommended frequency for this set of exercises: ";
	if (fitnessGoal == 1)
	{
		cout << " 1-2 days per week.\n";
	}
	else if (fitnessGoal == 2)
	{
		cout << " 2-3 days per week.\n";
	}
	else
	{
		cout << " 3-4 days per week.\n";
	}
	cout << "Recommended duration for this set of exercises: ";
	cout << workout.getDuration(numExercises) << " minutes\n";
	cout << "You have 30 seconds to complete a set and 1 minutes to rest between sets. Adjust the duration as needed.\n";
	cout << "Visit the following links for more information on how to correctly perform the exercises:\n";
	for (int i = 0; i < numExercises; i++)
	{
		cout << i + 1 << ". " << exercises[i] << ": " << youtubeLinks[i] << endl;
	}
	cout << "IMPORTANT: Remember to do cardio exercises (such as walking and running) and stretch before and after your workout to prevent injury.\n";
	cout << "Essential streching exercies: https://www.youtube.com/watch?v=RKYhcPV2dbA\n";
}
// This function displays general nutrition advice to the user.
void displayGeneralAdvice() 
{
	cout << "# General Advice:\n";
	cout << "+ Drink plenty of water (2.7 liters to 3.7 liters)" << endl;
	cout << "+ Eat a variety of fruits and vegetables" << endl;
	cout << "+ Consume fewer calories than you burn when trying to lose weight" << endl;
	cout << "+ Consume more calories than you burn when trying to gain muscle mass" << endl;
}
// This function displays the user's recommended daily caloric intake based on their biometric characteristics and fitness goal.
void displayCaloricIntake(Nutrition& nutrition, User& user) {
	cout << "# Your recommended daily caloric intake: " << nutrition.calculateCalories(user.height, user.weight, user.age, user.sex, user.fitnessGoal) << " calories\n";
}
// This function displays the user's body mass index (BMI) and ranks the user's BMI based on the BMI categories.
void displayBMI(Nutrition& nutrition, User& user) {
	cout << "# Your body mass index (BMI)\n";
	cout << "Your BMI is: " << nutrition.calculateBMI(user.height, user.weight) << endl;
	rankBMI(nutrition.calculateBMI(user.height, user.weight));
}
void rankBMI(float BMI)
{
	cout << "According to your BMI, you are ";
	if (BMI < 18.5)
	{
		cout << "underweight. You need to increase your calories intake" << endl;
	}
	else if (BMI >= 18.5 && BMI < 24.9)
	{
		cout << "normal weight. Keep it going!" << endl;
	}
	else if (BMI >= 25 && BMI < 29.9)
	{
		cout << "overweight. You need to exercise more and/or decrease your calories intake" << endl;
	}
	else
	{
		cout << "obese. You need to exercise more and/or decrease your calories intake" << endl;
	}
}
// This function displays the types of macronutrient intake plans and allows the user to choose one of them.
int getPlanChoice() {
	int planChoice;
	cout << "There are 3 types of macronutrient intake plans: \n";
	cout << "1) High carb diet\n";
	cout << "2) High protein diet\n";
	cout << "3) High protein, high carb, low fat diet\n";
	cout << "Enter your choice: ";
	cin >> planChoice;
	while (planChoice != 1 && planChoice != 2 && planChoice != 3)
	{
		cout << "Invalid choice. Please enter 1, 2 or 3." << endl;
		cin >> planChoice;
	}
	return planChoice;
}
// This function displays the user's recommended macronutrient intake based on the plan they choose.
void displayMacros(Nutrition& nutrition, int planChoice)
{
	cout << "# Your recommended macronutrient intake for today: \n";
	cout << setprecision(2) << fixed;
	cout << "Proteins: " << nutrition.calculateMacros(planChoice).proteins << " grams\n";
	cout << "Carbs:    " << nutrition.calculateMacros(planChoice).carbs << " grams\n";
	cout << "Fats:      " << nutrition.calculateMacros(planChoice).fats << " grams\n";
}
// This function displays a meal plan website where the user can find nutritional information about the food they want to eat.
// There are not any specific meal plan provided in this program. The user can create their own meal plan based on the information from the website.
void displayMealPlan() {
	cout << "You can create your own customized meal plan based on the information from this trusted website:\n";
	cout << "https://fdc.nal.usda.gov/fdc-app.html#/";
	cout << "\nType the name of the food you want to search for on this website to find its nutritional information.";
	cout << "\nTo cook the meals you want, you can follow various recipes on YouTube and the internet.\n";
}
// This function updates the user's profile and allows them to change their fitness goal.
void updateUserProfile(User& user) {
	cout << "Update your profile and change your fitness goal\n";
	cout << "Enter your new password: ";
	cin >> user.password;

	cout << "Enter your new fitness goal (1 for Beginner, 2 for Intermediate or 3 for Athletic Performance): ";
	cin >> user.fitnessGoal;
	while (user.fitnessGoal != 1 && user.fitnessGoal != 2 && user.fitnessGoal != 3)
	{
		cout << "Invalid choice. Please enter 1, 2 or 3." << endl;
		cin >> user.fitnessGoal;
	}
	cout << "Enter your new age: ";
	cin >> user.age;
	while (user.age <= 0 || user.age > 120)
	{
		cout << "Invalid age. Please enter a valid age: ";
		cin >> user.age;
	}
	cout << "Enter your new height (in cm): ";
	cin >> user.height;
	while (user.height <= 54 || user.height > 272)
	{
		cout << "Invalid height. Please enter a valid height: ";
		cin >> user.height;
	}
	cout << "Enter your new weight (in kg): ";
	cin >> user.weight;
	while (user.weight <= 2 || user.weight > 650)
	{
		cout << "Invalid weight. Please enter a valid weight: ";
		cin >> user.weight;
	}
	// New informations overwrite the old ones in the same file
	ofstream file;
	file.open(user.username + ".txt");
	file << user.username << endl;
	file << user.password << endl;
	file << user.name << endl;
	file << user.sex << endl;
	file << user.fitnessGoal << endl;
	file << user.age << endl;
	file << user.height << endl;
	file << user.weight << endl;
	file.close();
	cout << "Profile updated successfully!\n";

}

// This function allows the user to submit feedback.
void submitFeedback(User& user) {
	cout << "Submit feedback\n";
	string feedback;
	cout << "Enter your feedback: ";
	cin.ignore();
	getline(cin, feedback);
	ofstream feedbackFile;
	feedbackFile.open("feedback.txt", ios::app); // ios::app is used to append to the file. When this flag is used, the data is appended to the end of the file. In this way, we can keep track of all the feedbacks that have been submitted.
	feedbackFile << user.username << ": " << feedback << endl;

	feedbackFile.close();
	cout << "Thank you for your feedback!\n";

	vector<string> feedbacks;
	ifstream readFeedback("feedback.txt");
	string line;
	// This code reads all the feedbacks, line by line, from the file and stores them in a vector
	while (getline(readFeedback, line))
	{
		feedbacks.push_back(line);
	}
	// This code sorts the feedbacks in lexicographical order of the usernames each time a new feedback is submitted
	selectionSort(feedbacks);

	ofstream sortedFeedbackFile("feedback.txt", ios::trunc); // ios::trunc is used to clear the file before writing to it
	for (const auto& feedback : feedbacks) {
		sortedFeedbackFile << feedback << endl;
	}
	sortedFeedbackFile.close();
}
// This function sorts the feedbacks in lexicographical order of the usernames each time a new feedback is submitted.
void selectionSort(vector<string>& arr)
{
	int n = arr.size();
	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		swap(arr[minIndex], arr[i]); //  Swap is a function of the algorithm library that swaps the values of two variables. 
	}
}