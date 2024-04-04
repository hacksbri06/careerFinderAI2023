#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>

using namespace std;

/*
string vList[] = {"Advisement",    "Curiosity",  "Math",      "Experiment",
                  "Unbiased",      "Detailed",   "Teammate",  "Improvement",
                  "Communication", "Resilient",  "Employ",    "Expressive",
                  "Learn",         "Teamwork",   "Caretaker", "Adapt",
                  "Realistic",     "Compassion", "Leader",    "Relations",
                  "Research",      "Business"};

// bri: one array be the variable and the other array being the corresponding
// prompt
struct Bkwd_Prompts {

  // stores variable names
  // put string vList here?
  // stores corresponding prompt
  string vList[25] = {"Advisement",    "Curiosity",  "Math",      "Experiment",
                      "Unbaised",      "Detailed",   "Teammate",  "Improvement",
                      "Communication", "Resilient",  "Employ",    "Expressive",
                      "Learn",         "Teamwork",   "Caretaker", "Adapt",
                      "Realistic",     "Compassion", "Leader",    "Relations",
                      "Research",      "Business"};
  string vPrompts[25] = {
      // Advisement
      "Are you seeking advisement?",

      // Curiosity
      "Do you have a strong sense of curiosity?",

      // Math
      "Do you have a strong interest in math?",

      // Experiment
      "Are you experimental focused?",

      // Unbiased
      "Are you open minded and bias free?",

      // Detailed
      "Are you detailed oriented?",

      // Teammate
      "Are you a team player?",

      // Improvement
      "Are you improvement seeking?",

      // Communication
      "Do you have effective communication?",

      // Resilient
      "Are you resilient?",

      // Employ
      "Can you employ correct issues in work?",

      // Expressive
      "Are you expressive?",      //This one's part of the conclusions

      // Learn
      "Do you want to do continued learning?",

      // Teamwork
      "Are you able to work in a team?",

      // Caretaker
      "Can you take care of others?",

      // Adapt
      "Are you able to easily adapt?",

      // Realistic
      "Can you be realistic?",

      // Compassion
      "Can you be compassionate?",  //This one's part of the conclusions

      //Care
      "Are you interested in either direct or indirect care?",

      // Leader
      "Do you have leadership qualities?",

      //"Relations
      "Are you interested in relations?",

      // Research
      "Do you have strong research qualities",

      // Business
      "Are you interested in business?",
  };
};

struct Frwd_Prompts {

  string vList[41] = {
      "Engineering",    "Production",    "Electricity", "Machine",
      "Chemicals",      "Communication", "Image",       "Workspace",
      "Digital",        "Media",         "Education",   "Tools",
      "Concept",        "Children",      "Advising",    "Medical",
      "Cardiovascular", "Speech",        "Support",     "Oral",
      "Health Care",    "Movement",      "Assist",      "Administration",
      "Consultation",   "Fine Arts",     "Visuals",     "Formation",
      "Rhythm",         "Expression",    "Science",     "Elements",
      "Environment",    "Program",       "Formulas",    "Business",
      "Property",       "Reports",       "Economics",   "Selling"};

  string vPrompts[41] = {
      // Engineering
      "",
      // Production
      "Do you have an interest in eliminating wastefulness in production "
      "processes?",

      // Electricity
      "Do you have an interest in designing, developing, testing, and "
      "supervising the           manufacture of electrical equipment?",

      // Machine
      "Are you interested in designing power-producing machines such as "
      "electrical             generators or internal combustion engines?",

      // Chemicals
      "Are you interested in developing and designing chemical manufacturing "
      "processes?",

      // Communication
      "",

      // Image
      "Are you interested in maintaining a public image?",

      // Workspace
      "Are you interested in managing a workspace?",

      // Digital
      "Are you interested in promoting through social media?",

      // Media
      "Are you interested in promoting through classic media channels?",

      // Education
      "",

      // Tools
      "Are you interested in making tools to help education?",

      // Concept
      "Are you interested in understanding the concept of education?",

      // Children
      "Are you interested in educating younger people?",

      // Advising
      "Are you interested in advising others?",

      // Medical
      "",

      // Cardiovascular
      "Are you interested in treating and preventing cardiovascular problems?",

      // Speech
      "Are you interested in providing treatment to those with speech "
      "disorders?",

      // Support
      "Are you interested in being a direct primary care worker that will work "
      "along side     doctors to promote health, prevent disease, and help "
      "patients with illness?",

      // Oral
      "Are you interested in evaluating the overall oral health of people "
      "including but         not limited to performing extractions and "
      "corrective surgeries?",

      // Health Care
      "",

      // Movement
      "Are you interested in helping injured or ill people improve movement "
      "and manage          pain?",

      // Assist
      "Are you interested in performing physicals, treatment, and counsels for "
      "patients         under the supervision of a physician?",

      // Administration
      "Are you interested in the overseeing of the day-to-day administrative "
      "operations of     hospitals and other healthcare facilities?",

      // Consultation
      "Are you interested in aiding patients regarding financial assistance "
      "eligibility?",

      // Fine Arts
      "",

      // Visuals
      "Do you like to visualize your feelings and expressions?",

      // Formation
      "Do you like to express yourself through movement, choreography, and "
      "formations?",

      // Rhythm
      "Are you skilled at hearing tones, rhythm, and keeping tempo?",

      // Expression
      "Are you able to convey different personalities to express in front of "
      "groups of         people?",

      // Science
      "",

      // Elements
      "Are you interested in creating formulas from elements?",

      // Environment
      "Are you interested in protecting the environment through investigating "
      "species,         plants, and anatomical characteristics?",

      // Program
      "Would you like to test data with programming technical language?",

      // Formulas
      "Are you interested in studying the universe?",

      // Business
      "",

      // Property
      "Are you interested in selling property and potential homes to "
      "customers?",

      // Reports
      "Are you interested in  creating financial reports and payroll "
      "processing?",

      // Economics
      "Are you interested in  financial management, economics, and analysis ?",

      // Selling
      "Are you interested in  email marketing, training teams,  or  selling "
      "products or         services?"

  };
};
*/

//Rod's Version
class Variable
{
    public:
        string name;
        bool value;
        string prompt;
        bool instan;
        string field;
        string area;

        void initVar(string, string);
        void specialVar(string, bool);
        void initField(string, string);
        void initArea(string, string);
};

#endif