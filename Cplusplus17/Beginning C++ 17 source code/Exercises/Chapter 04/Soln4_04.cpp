// Exercise 4-4.
// As promised, you're to go look for a person "who is over 21, under 35, female,
// has a bachelorís or masterís degree, is unmarried, and who speaks Hindi or Urdu"

#include <iostream>
#include <cctype> // For std::tolower() / std::toupper()

enum class AcademicDegree
{
  none,
  associate,
  bachelor,
  professional,
  master,
  doctor
};

int main()
{
  int age{};               // Initialized to 0
  char gender{};           // Initialized to '\0' (see Chapter 5)
  AcademicDegree degree{}; // Initialized to AcademicDegree::none
  bool married{};          // Initialized to false
  bool speaksHindi{};
  bool speaksUrdu{};

  std::cout << "What is your age, if I may ask? ";
  std::cin >> age;

  if (age < 0 || age > 130)
  {
    std::cout << "Sure it is, joker. Sadly, commedians don't qualify..." << std::endl;
    return 1;
  }

  std::cout << "What is your gender (m or f)? ";
  std::cin >> gender;

  gender = std::tolower(gender);
  if (gender != 'm' && gender != 'f')
  {
    std::cout << "We do not mean to discriminate, but our current software only accepts male or female. Sorry...";
    return 1;
  }

  std::cout << "What is your highest academic degree?\n"
            << "Possible values are:\n"
            << "\tn: no academic degree\n"
            << "\ta: associate's degree\n"
            << "\tb: bachelor's dehree\n"
            << "\tp: professional degree\n"
            << "\tm: master's degree\n"
            << "\td: doctorate\n";
  char degreeChar{};
  std::cin >> degreeChar;

  switch (std::tolower(degreeChar))
  {
  case 'n':
    degree = AcademicDegree::none;
    break;
  case 'a':
    degree = AcademicDegree::associate;
    break;
  case 'b':
    degree = AcademicDegree::bachelor;
    break;
  case 'p':
    degree = AcademicDegree::professional;
    break;
  case 'm':
    degree = AcademicDegree::master;
    break;
  case 'd':
    degree = AcademicDegree::doctor;
    break;
  default:
    std::cout << "Given that you cannot correctly enter your degree, shall I just note down 'none'?\n";
    std::cout << "On second thought: no, I do not believe you qualify. Goodbye." << std::endl;
    return 1;
  }

  // Now we ask a few yes/no questions, and use some variations on how to decide
  // whether or not the user's input is valid or not. In real code, one should
  // probably be consistent rather than using a different style each time...

  char yes_no{};
  std::cout << "Are you married (y or n)? ";
  std::cin >> yes_no;

  if (yes_no == 'y' || yes_no == 'Y')
    married = true;
  else if (yes_no == 'n' || yes_no == 'N')
    married = false;
  else
  {
    std::cout << "Incapable of entering your marital status. Surely still single then I suppose...?" << std::endl;
    return 1;
  }

  std::cout << "Do you speak Hindi (y or n)? ";
  std::cin >> yes_no;

  yes_no = std::toupper(yes_no);
  if (yes_no == 'Y')
    speaksHindi = true;
  else if (yes_no == 'N')
    speaksHindi = false;
  else
  {
    std::cout << "I'm sorry? I didn't catch that. Please answer in English next time..." << std::endl;
    return 1;
  }

  std::cout << "Do you speak Urdu (y or n)? ";
  std::cin >> yes_no;

  switch (std::tolower(yes_no))
  {
  case 'y':
    speaksUrdu = true;
    break;
  case 'n':
    speaksUrdu = false;
    break;
  default:
    std::cout << "I'm sorry? I didn't catch that. Please answer in English next time..." << std::endl;
    return 1;
  }

  // Determine whether the user is someone "who is over 21, under 35, female, has a bachelorís or masterís degree,
  // is unmarried, and who speaks Hindi or Urdu"
  if ((age > 21 && age < 35) && gender == 'f' && (degree == AcademicDegree::bachelor || degree == AcademicDegree::master) && !married && (speaksHindi || speaksUrdu))
  {
    std::cout << "Congratulations: you are precisely the person we were looking for! Are you willing to work for minimum wage?" << std::endl;
  }
  else
  {
    std::cout << "Sorry. You don't seem to meet our requirements to the letter. Don't call us, we'll call you...?" << std::endl;
  }
}