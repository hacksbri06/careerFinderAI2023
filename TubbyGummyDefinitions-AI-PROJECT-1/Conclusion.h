#ifndef MY_STRUCT_H
#define MY_STRUCT_H
#include <string>
#include <vector>

using namespace std;

/*
struct Conclusions {
  string cList[16] = {"Field", "Qualify",      "Stem",       "Field",
                      "Field", "Creative",     "Expressive", "Field",
                      "Field", "Public",       "Field",      "Compassion",
                      "Field", "Entrepreneur", "Field",      "Field"};
  vector<vector<string>> cListVar = {
      {"Advisement"},
      {"Advisement"},
      {"Qualify", "Curiosity", "Math"},
      {
          "Stem",
          "Experiment",
          "Unbiased",
          "Detailed",
      },
      {"Stem", "Experiment", "Teammate", "Improvement"},
      {"Qualify", "Curiosity", "Communication", "Resilient"},
      {"Creative", "Employ"},
      {"Expressive", "Learn"},
      {"Expressive", "Learn"},
      {"Creative", "Employ", "Teamwork"},
      {"Public", "Caretaker", "Adapt", "Realistic"},
      {"Public", "Caretaker"},
      {"Compassion", "Care"},
      {"Compassion", "Care", "Leader", "Relations", "Research"},
      {"Entrepreneur", "Business"},
      {"Entrepreneur", "Business"}};
};
*/

// Rod's Version
class Conclusion
{
    public:
        string name;
        bool checked;

        void initConc(string);
};

#endif