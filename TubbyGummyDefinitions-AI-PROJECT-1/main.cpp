// Academic Assistance Project
//
//     Rodrigo Pandal
//     Briana
//     Lance

#include "Clause.h"
#include "Conclusion.h"
#include "Variable.h"
#include <fstream> // for logging
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// Lance's List thing
/*
string vList[] = {"Advisement",    "Curiosity",  "Math",      "Experiment",
                  "Unbaised",      "Detailed",   "Teammate",  "Improvement",
                  "Communication", "Resilient",  "Employ",    "Expressive",
                  "Learn",         "Teamwork",   "Caretaker", "Adapt",
                  "Realistic",     "Compassion", "Leader",    "Relations",
                  "Research",      "Business"};
*/
int search_con(string); // These value types might change depending on what
                        // classes we implement
int rule_to_clause(int);
void update_VL(int);
bool validate_RI(int);
void ProcessField_BW(string);

int search_cvl(int);
int clause_to_rule(int);
void ProcessArea_FW(string);

// Rod's Version
const int CONC_LIST_SIZE = 160;
const int CLAU_VAR_LIST_SIZE = 113;
const int VAR_LIST_SIZE = 21;
int GLOB_VAR_LIST_SIZE = 0;

Conclusion ConcList[CONC_LIST_SIZE];
Clause ClauVarList[CLAU_VAR_LIST_SIZE];
Variable VarList[VAR_LIST_SIZE];
vector<Variable> GlobVarList;

const int CONC_LIST_SIZE = 160;
const int CLAU_VAR_LIST_SIZE = 421;
const int VAR_LIST_SIZE = 53;
int GLOB_VAR_LIST_SIZE = 0;

Conclusion ConcList[CONC_LIST_SIZE];
Clause ClauVarList[CLAU_VAR_LIST_SIZE];
Variable VarList[VAR_LIST_SIZE];
vector<Variable> GlobVarList;

ofstream logFile;

string vField;
string vArea;
string userName;

/*
Conclusions c;

int main() {
 string conVarList[160];
 string goal_variable;

     string field = "";      //probably gonna be a variable of type "variable"

     Process(field)

int Ri;
// int Ci;
 cout << "What is the goal variable?" << endl;
 // should we say something more prompting?
 cout << "What are your goals as a student?" << endl;
 getline(cin, goal_variable);
}
*/

// Rod's Version
int main() {

    logFile.open("Project_Log.txt");

  //Conclusion Declarations below:
  ConcList[10].initConc("FIELD");
  ConcList[20].initConc("QUALIFY");
  ConcList[30].initConc("STEM");
  ConcList[40].initConc("FIELD");
  ConcList[50].initConc("FIELD");
  ConcList[60].initConc("CREATIVE");
  ConcList[70].initConc("EXPRESSIVE");
  ConcList[80].initConc("FIELD");
  ConcList[90].initConc("FIELD");
  ConcList[100].initConc("PUBLIC");
  ConcList[110].initConc("FIELD");
  ConcList[120].initConc("COMPASSION");
  ConcList[130].initConc("FIELD");
  ConcList[140].initConc("ENTREPRENEUR");
  ConcList[150].initConc("FIELD");
  ConcList[160].initConc("FIELD");

  //Clause Declarations below:
  ClauVarList[1].specialClause("ADVISEMENT", false, "FIELD", "No");
  ClauVarList[8].specialClause("ADVISEMENT", true, "QUALIFY", "YES");
  ClauVarList[15].initClause("QUALIFY", true);
  ClauVarList[16].initClause("CURIOSITY", true);
  ClauVarList[17].specialClause("MATH", true, "STEM", "YES");
  ClauVarList[22].initClause("STEM", true);
  ClauVarList[23].initClause("EXPERIMENT", true);
  ClauVarList[24].initClause("UNBIASED", true);
  ClauVarList[25].specialClause("DETAILED", true, "FIELD", "Science");
  ClauVarList[29].initClause("STEM", true);
  ClauVarList[30].initClause("EXPERIMENT", false);
  ClauVarList[31].initClause("TEAMMATE", true);
  ClauVarList[32].specialClause("IMPROVEMENT", true, "FIELD", "Engineering");
  ClauVarList[36].initClause("QUALIFY", true);
  ClauVarList[37].initClause("CURIOSITY", false);
  ClauVarList[38].initClause("COMMUNICATION", true);
  ClauVarList[39].specialClause("RESILIENT", true, "CREATIVE", "YES");
  ClauVarList[43].initClause("CREATIVE", true);
  ClauVarList[44].specialClause("EMPLOY", true, "EXPRESSIVE", "YES");
  ClauVarList[50].initClause("EXPRESSIVE", true);
  ClauVarList[51].specialClause("LEARN", true, "FIELD", "Education");
  ClauVarList[57].initClause("EXPRESSIVE", true);
  ClauVarList[58].specialClause("LEARN", false, "FIELD", "Fine Arts");
  ClauVarList[64].initClause("CREATIVE", true);
  ClauVarList[65].initClause("EMPLOY", false);
  ClauVarList[66].specialClause("TEAMWORK", true, "PUBLIC", "YES");
  ClauVarList[71].initClause("PUBLIC", true);
  ClauVarList[72].initClause("CARETAKER", true);
  ClauVarList[73].initClause("ADAPT", true);
  ClauVarList[74].specialClause("REALISTIC", true, "FIELD", "Medical");
  ClauVarList[78].initClause("PUBLIC", true);
  ClauVarList[79].specialClause("CARETAKER", false, "COMPASSION", "YES");
  ClauVarList[85].initClause("COMPASSION", true);
  ClauVarList[86].specialClause("CARE", true, "FIELD", "Health Care");
  ClauVarList[92].initClause("COMPASSION", true);
  ClauVarList[93].initClause("CARE", false);
  ClauVarList[94].initClause("LEADER", true);
  ClauVarList[95].initClause("RELATIONS", true);
  ClauVarList[96].specialClause("RESEARCH", true, "ENTREPRENEUR", "YES");
  ClauVarList[99].initClause("ENTREPRENEUR", true);
  ClauVarList[100].specialClause("BUSINESS", false, "FIELD", "Communication");
  ClauVarList[106].initClause("ENTREPRENEUR", true);
  ClauVarList[107].specialClause("BUSINESS", true, "FIELD", "Business");

  ClauVarList[141].fieldClause("FIELD", "Engineering");
  ClauVarList[142].specialClause("PRODUCTION", true, "AREA", "Industrial Engineering");
  ClauVarList[148].fieldClause("FIELD", "Engineering");
  ClauVarList[149].specialClause("ELECTRICITY", true, "AREA", "Electrical Engineering");
  ClauVarList[155].fieldClause("FIELD", "Engineering");
  ClauVarList[156].specialClause("MACHINE", true, "AREA", "Mechanical Engineering");
  ClauVarList[162].fieldClause("FIELD", "Engineering");
  ClauVarList[163].specialClause("CHEMICALS", true, "AREA", "Chemical Engineering");
  ClauVarList[169].fieldClause("FIELD", "Communication");
  ClauVarList[170].specialClause("IMAGE", true, "AREA", "Public Relations");
  ClauVarList[176].fieldClause("FIELD", "Communication");
  ClauVarList[177].specialClause("WORKSPACE", true, "AREA", "Human Resources");
  ClauVarList[183].fieldClause("FIELD", "Communication");
  ClauVarList[184].specialClause("DIGITAL", true, "AREA", "Social & Digital Marketing");
  ClauVarList[190].fieldClause("FIELD", "Communication");
  ClauVarList[191].specialClause("MEDIA", true, "AREA", "Marketing & Advertising");
  ClauVarList[197].fieldClause("FIELD", "Education");
  ClauVarList[198].specialClause("TOOLS", true, "AREA", "Education Technology");
  ClauVarList[204].fieldClause("FIELD", "Education");
  ClauVarList[205].specialClause("CONCEPT", true, "AREA", "Pedagogy");
  ClauVarList[211].fieldClause("FIELD", "Education");
  ClauVarList[212].specialClause("CHILDREN", true, "AREA", "Teaching");
  ClauVarList[218].fieldClause("FIELD", "Education");
  ClauVarList[219].specialClause("ADVISING", true, "AREA", "Counseling");
  ClauVarList[225].fieldClause("FIELD", "Medical");
  ClauVarList[226].specialClause("CARDIOVASCULAR", true, "AREA", "Cardiology");
  ClauVarList[232].fieldClause("FIELD", "Medical");
  ClauVarList[233].specialClause("SPEECH", true, "AREA", "Speech Pathology");
  ClauVarList[239].fieldClause("FIELD", "Medical");
  ClauVarList[240].specialClause("SUPPORT", true, "AREA", "Nursing");
  ClauVarList[246].fieldClause("FIELD", "Medical");
  ClauVarList[247].specialClause("ORAL", true, "AREA", "Dentistry");
  ClauVarList[253].fieldClause("FIELD", "Health Care");
  ClauVarList[254].specialClause("MOVEMENT", true, "AREA", "Physical Therapy");
  ClauVarList[260].fieldClause("FIELD", "Health Care");
  ClauVarList[261].specialClause("ASSIST", true, "AREA", "Physicians Assistance");
  ClauVarList[267].fieldClause("FIELD", "Health Care");
  ClauVarList[268].specialClause("ADMINISTRATION", true, "AREA", "Health Administration");
  ClauVarList[274].fieldClause("FIELD", "Health Care");
  ClauVarList[275].specialClause("CONSULTATION", true, "AREA", "Patient Financial Consultation");
  ClauVarList[281].fieldClause("FIELD", "Fine Arts");
  ClauVarList[282].specialClause("VISUALS", true, "AREA", "Art");
  ClauVarList[288].fieldClause("FIELD", "Fine Arts");
  ClauVarList[289].specialClause("FORMATION", true, "AREA", "Dance");
  ClauVarList[295].fieldClause("FIELD", "Fine Arts");
  ClauVarList[296].specialClause("RHYTHM", true, "AREA", "Music");
  ClauVarList[302].fieldClause("FIELD", "Fine Arts");
  ClauVarList[303].specialClause("EXPRESSION", true, "AREA", "Theater");
  ClauVarList[309].fieldClause("FIELD", "Science");
  ClauVarList[310].specialClause("ELEMENTS", true, "AREA", "Chemistry");
  ClauVarList[316].fieldClause("FIELD", "Science");
  ClauVarList[317].specialClause("ENVIRONMENT", true, "AREA", "Biology");
  ClauVarList[323].fieldClause("FIELD", "Science");
  ClauVarList[324].specialClause("PROGRAM", true, "AREA", "Computer Science");
  ClauVarList[330].fieldClause("FIELD", "Science");
  ClauVarList[331].specialClause("FORMULAS", true, "AREA", "Astrophysics");
  ClauVarList[337].fieldClause("FIELD", "Business");
  ClauVarList[338].specialClause("PROPERTY", true, "AREA", "Real Estate");
  ClauVarList[344].fieldClause("FIELD", "Business");
  ClauVarList[345].specialClause("REPORTS", true, "AREA", "Accounting");
  ClauVarList[351].fieldClause("FIELD", "Business");
  ClauVarList[352].specialClause("ECONOMICS", true, "AREA", "Finance");
  ClauVarList[358].fieldClause("FIELD", "Business");
  ClauVarList[359].specialClause("SELLING", true, "AREA", "Sales");
  ClauVarList[365].fieldClause("FIELD", "Engineering");
  ClauVarList[366].initClause("PRODUCTION", false);
  ClauVarList[367].initClause("ELECTRICITY", false);
  ClauVarList[368].initClause("MACHINE", false);
  ClauVarList[369].specialClause("CHEMICALS", false, "AREA", "Not Offered");
  ClauVarList[372].fieldClause("FIELD", "Communication");
  ClauVarList[373].initClause("IMAGE", false);
  ClauVarList[374].initClause("WORKSPACE", false);
  ClauVarList[375].initClause("DIGITAL", false);
  ClauVarList[376].specialClause("MEDIA", false, "AREA", "Not Offered");
  ClauVarList[379].fieldClause("FIELD", "Education");
  ClauVarList[380].initClause("TOOLS", false);
  ClauVarList[381].initClause("CONCEPT", false);
  ClauVarList[382].initClause("CHILDREN", false);
  ClauVarList[383].specialClause("ADVISING", false, "AREA", "Not Offered");
  ClauVarList[386].fieldClause("FIELD", "Medical");
  ClauVarList[387].initClause("CARDIOVASCULAR", false);
  ClauVarList[388].initClause("SPEECH", false);
  ClauVarList[389].initClause("SUPPORT", false);
  ClauVarList[390].specialClause("ORAL", false, "AREA", "Not Offered");
  ClauVarList[393].fieldClause("FIELD", "Health Care");
  ClauVarList[394].initClause("MOVEMENT", false);
  ClauVarList[395].initClause("ASSIST", false);
  ClauVarList[396].initClause("ADMINISTRATION", false);
  ClauVarList[397].specialClause("CONSULTATION", false, "AREA", "Not Offered");
  ClauVarList[400].fieldClause("FIELD", "Fine Arts");
  ClauVarList[401].initClause("VISUALS", false);
  ClauVarList[402].initClause("FORMATION", false);
  ClauVarList[403].initClause("RHYTHM", false);
  ClauVarList[404].specialClause("EXPRESSION", false, "AREA", "Not Offered");
  ClauVarList[407].fieldClause("FIELD", "Science");
  ClauVarList[408].initClause("ELEMENTS", false);
  ClauVarList[409].initClause("ENVIRONMENT", false);
  ClauVarList[410].initClause("PROGRAM", false);
  ClauVarList[411].specialClause("FORMULAS", false, "AREA", "Not Offered");
  ClauVarList[414].fieldClause("FIELD", "Business");
  ClauVarList[415].initClause("PROPERTY", false);
  ClauVarList[416].initClause("REPORTS", false);
  ClauVarList[417].initClause("ECONOMICS", false);
  ClauVarList[418].specialClause("SELLING", false, "AREA", "Not Offered");


  //Variable Declarations below:
  VarList[0].initVar("ADVISEMENT", "Are you seeking advisement?");
  VarList[1].initVar("CURIOSITY", "Do you have a strong sense of curiosity?");
  VarList[2].initVar("MATH", "Do you have a strong interest in math?");
  VarList[3].initVar("EXPERIMENT", "Are you experimental focused?");
  VarList[4].initVar("UNBIASED", "Are you open minded and bias free?");
  VarList[5].initVar("DETAILED", "Are you detailed oriented?");
  VarList[6].initVar("TEAMMATE", "Are you a team player?");
  VarList[7].initVar("IMPROVEMENT", "Are you improvement seeking?");
  VarList[8].initVar("COMMUNICATION", "Do you have effective communication?");
  VarList[9].initVar("RESILIENT", "Are you resilient?");
  VarList[10].initVar("EMPLOY", "Can you employ correct issues in work?");
  VarList[11].initVar("LEARN", "Do you want to do continued learning?");
  VarList[12].initVar("TEAMWORK", "Are you able to work in a team?");
  VarList[13].initVar("CARETAKER", "Can you take care of others?");
  VarList[14].initVar("ADAPT", "Are you able to easily adapt?");
  VarList[15].initVar("REALISTIC", "Can you be realistic?");
  VarList[16].initVar("CARE", "Are you interested in either direct or indirect care?");
  VarList[17].initVar("LEADER", "Do you have leadership qualities?");
  VarList[18].initVar("RELATIONS", "Are you interested in relations?");
  VarList[19].initVar("RESEARCH", "Do you have strong research qualities");
  VarList[20].initVar("BUSINESS", "Are you interested in business?");

  VarList[21].initVar("PRODUCTION", "Do you have an interest in eliminating wastefulness in production process?");
  VarList[22].initVar("ELECTRICITY", "Do you have an interest in designing, developing, testing, and supervising the manufacture of electrical equipment?");
  VarList[23].initVar("MACHINE", "Are you interested in designing power-producing machines such as electrical generators or internal combustion engines?");
  VarList[24].initVar("CHEMICALS", "Are you interested in developing and designing chemical manufacturing processes?");
  VarList[25].initVar("IMAGE", "Are you interested in maintaining a public image?");
  VarList[26].initVar("WORKSPACE", "Are you interested in managing a workspace?");
  VarList[27].initVar("DIGITAL", "Are you interested in promoting through social media?");
  VarList[28].initVar("MEDIA", "Are you interested in promoting through classic media channels?");
  VarList[29].initVar("TOOLS", "Are you interested in making tools to help education?");
  VarList[30].initVar("CONCEPT", "Are you interested in understanding the concept of education?");
  VarList[31].initVar("CHILDREN", "Are you interested in educating younger people?");
  VarList[32].initVar("ADVISING", "Are you interested in advising others?");
  VarList[33].initVar("CARDIOVASCULAR", "Are you interested in treating and preventing cardiovascular problems?");
  VarList[34].initVar("SPEECH", "Are you interested in providing treatment to those with speech disorders?");
  VarList[35].initVar("SUPPORT", "Are you interested in being a direct primary care worker that will work along side doctors to promote health, prevent disease, and help patients with illness?");
  VarList[36].initVar("ORAL", "Are you interested in evaluating the overall oral health of people including but not limited to performing extractions and corrective surgeries?");
  VarList[37].initVar("MOVEMENT", "Are you interested in helping injured or ill people improve movement and manage pain?");
  VarList[38].initVar("ASSIST", "Are you interested in performing physicals, treatment, and counsels for patients under the supervision of a physician?");
  VarList[39].initVar("ADMINISTRATION", "Are you interested in the overseeing of the day-to-day administrative operations of hospitals and other healthcare facilities?");
  VarList[40].initVar("CONSULTATION", "Are you interested in aiding patients regarding financial assistance eligibility?");
  VarList[41].initVar("VISUALS", "Do you like to visualize your feelings and expressions?");
  VarList[42].initVar("FORMATION", "Do you like to express yourself through movement, choreography, and formations?");
  VarList[43].initVar("RHYTHM", "Are you skilled at hearing tones, rhythm, and keeping tempo?");
  VarList[44].initVar("EXPRESSION", "Are you able to convey different personalities to express in front of groups of people?");
  VarList[45].initVar("ELEMENTS", "Are you interested in creating formulas from elements?");
  VarList[46].initVar("ENVIRONMENT", "Are you interested in protecting the environment through investigating species, plants, and anatomical characteristics?");
  VarList[47].initVar("PROGRAM", "Would you like to test data with programming technical language?");
  VarList[48].initVar("FORMULAS", "Are you interested in studying the universe?");
  VarList[49].initVar("PROPERTY", "Are you interested in selling property and potential homes to customers?");
  VarList[50].initVar("REPORTS", "Are you interested in  creating financial reports and payroll processing?");
  VarList[51].initVar("ECONOMICS", "Are you interested in  financial management, economics, and analysis ?");
  VarList[52].initVar("SELLING", "Are you interested in  email marketing, training teams,  or  selling products or services?");

  cout << "Hello and welcome to your personalized Academic Advisement" << endl;
  logFile << "Hello and welcome to your personalized Academic Advisement" << endl;
  cout << "To start, please tell us your name: ";
  logFile << "To start, please tell us your name: ";
  cin >> userName;

  cout << endl << "Hello there, " << userName << " let's see how we can help you out today." << endl;
  logFile << endl << "Hello there, " << userName << " let's see how we can help you out today." << endl;

  cout << "We'll start off by asking you a couple of questions below: "<< endl;
  logFile << "We'll start off by asking you a couple of questions below: "<< endl;

  ProcessField_BW("FIELD");
  ProcessArea_FW(vField);

  cout << "There you go, glad we could help. Goodbye!";
  logFile << "There you go, glad we could help. Goodbye!";

  logFile.close();

  return 0;

}

// Given a variable name (string), look through Conclusion list for conclusions
// matching given variable name and when found, make sure conclusion has not
// been checked before returning i as the rule number. If not found, return 0.
int search_con(string varName) {
  for(int i = 10; i <= CONC_LIST_SIZE; i+= 10){
    if(ConcList[i].name == varName && ConcList[i].checked == false){
      return i;
    }
  }
  return 0;
}

// Given a rule number value, convert it into a clause number using appropriate
// formula
int rule_to_clause(int ri) {
  logFile << "Current Rule #: " << ri << endl;
  int ci = 7 * (ri / 10 - 1) + 1;
  logFile << "Current Clause # " << ci << endl;
  return ci;
}

// Look through variables in the clause and initialize them in variable list if found
// If not found in variable list look through global variable list.
// If not found in global variable list then must be in conclusion list, then call
// ProcessField_BW function on clause variable.
void update_VL(int ci) {
  for (int i = ci; i < ci + 7; i++){
    if (ClauVarList[i].name == ""){ break; }

    bool found = false;

    for (int j = 0; j < VAR_LIST_SIZE; j++){
      if (VarList[j].name == ClauVarList[i].name){
        if (VarList[j].instan == true){
          logFile << "Value of " << VarList[j].name << " already found" << endl;
          found = true;
          break;
        }
        else {
          cout << VarList[j].prompt << " [Yes/No]" << endl;
          string answer;
          cin >> answer;

          if (answer == "Yes" || answer == "yes" || answer == "YES"){
            VarList[j].value = true;
            VarList[j].instan = true;
            found = true;
            logFile << "Value of " << VarList[j].name << " is Yes" << endl;
            break;
          }
          else if (answer == "No" || answer == "no" || answer == "NO"){
            VarList[j].value = false;
            VarList[j].instan = true;
            logFile << "Value of " << VarList[j].name << " is No" << endl;
            found = true;
            break;
          }
        }

      }
    }


    if (!found){
      for (int j = 0; j < GLOB_VAR_LIST_SIZE; j++){

        if (GlobVarList[j].name == ClauVarList[i].name){
          found = true;
          logFile << "Value of " << GlobVarList[j].name << " in GlobVarList" << endl;
          break;
        }
      }
    }

    if (!found){
      logFile << "Value " << ClauVarList[i].name << " is Conclusion" << endl;
      ProcessField_BW(ClauVarList[i].name);
    }
  }

}

//Given the clause number, go through section in Clause Variable List
//starting at clause number and compare each value to the values in
//the variable list.
//If all matching, create and append variables accordingly (regular, Field, and Area).
//If not matching, return false.
bool validate_RI(int ci) {
    bool correct = true;
    for (int i = ci; i < ci + 7; i++){
        if (ClauVarList[i].name == ""){ break; }

        bool found = false;
        for (int j = 0; j < VAR_LIST_SIZE; j++){
          if (VarList[j].name == ClauVarList[i].name){
            if (VarList[j].value != ClauVarList[i].value){
              correct = false;
              found = true;
              break;
            }
          }
        }

        if (!found){
          for (int j = 0; j < GLOB_VAR_LIST_SIZE; j++){
            if (GlobVarList[j].name == ClauVarList[i].name){
              if (GlobVarList[j].name == "FIELD"){
                if (GlobVarList[j].field != ClauVarList[i].field){
                    correct = false;
                    break;
                }
              }
              else{
                if (GlobVarList[j].value != ClauVarList[i].value){
                    correct = false;
                    break;
                }
              }
            }
          }
        }

        if (ClauVarList[i+1].name == "" && correct == true){
            if (ClauVarList[i].thenVal == "YES"){
                Variable tempVar;
                tempVar.specialVar(ClauVarList[i].thenName, true);
                GlobVarList.push_back(tempVar);
                GLOB_VAR_LIST_SIZE++;
                logFile << "Rule and Variables matched, " << ClauVarList[i].thenName <<
                        " appended to GlobVarList" << endl;
                return true;
            }
            else if(ClauVarList[i].thenName == "AREA"){
                Variable tempVar;
                tempVar.initArea(ClauVarList[i].thenName, ClauVarList[i].thenVal);
                GlobVarList.push_back(tempVar);
                vArea = ClauVarList[i].thenVal;
                GLOB_VAR_LIST_SIZE++;
                logFile << "Rule and Variables matched, " << ClauVarList[i].thenName <<
                        " appended to GlobVarList and Area found!" << endl;
            }
            else {
                Variable tempVar;
                tempVar.initField(ClauVarList[i].thenName, ClauVarList[i].thenVal);
                GlobVarList.push_back(tempVar);
                vField = ClauVarList[i].thenVal;
                GLOB_VAR_LIST_SIZE++;
                logFile << "Rule and Variables matched, " << ClauVarList[i].thenName <<
                        " appended to GlobVarList and Field found!" << endl;
                return true;
            }
        }
    }

    if (correct == true)
        return true;
    logFile << "Rule values did not match for Clause #: " << ci << endl;
    return false;

}

// Loop through the conclusion list for every instance of "variable"
// until it's been added to the Global Variable List
void ProcessField_BW(string variable) {

  bool found = false;
  do{
    //Call search_con() and give variable name (string)
      // catch return value in a variable of type int
      int ri = search_con(variable); //Could be change to "variable.name"

      //Call rule_to_clause() and send previous variable
      // catch return value in a variable of type int
      int ci = rule_to_clause(ri);


      // Call update_VL() to instantiate all the variables of the given clause.
      update_VL(ci);

      //Check return from validate_RI. If false then set the current conclusion
      // in conclusion list's checked value to true and loop again.

      found = validate_RI(ci);

      if (!found){
        ConcList[ri].checked = true;
      }
  }while(!found);

  if (variable == "FIELD"){
    cout << "Looks like you should be in " << vField << endl << endl;
  }

}

// Given the value or name of the field, search through Clause Variable List
// for "if" statement containing "FIELD" and matching it's value, and making
// sure it's not been checked before.
// When found, return position as clause number.
//  If not found, return 0.
int search_cvl(string fieldName){
    for (int i = 141; i < CLAU_VAR_LIST_SIZE; i += 7){
        if (ClauVarList[i].name == "FIELD" && ClauVarList[i].checked == false && ClauVarList[i].field == fieldName){
            update_VL(i);
            logFile << "Current Clause # " << i << endl;
            return i;
        }
    }
    return 0;
}

// Given cluase number (int), convert to rule number using appropriate formula
int clause_to_rule(int ci){
    int ri = ((ci/7)+1)*10;
    logFile << "Current Rule # " << ri << endl;
    return ri;
}

//Given the field name previously found, first call search_cvl to find clause number.
//Then with said clause number, call update_VL to acquire all necessary values.
//Afterwards convert clause number to rule number using clause_to_rule.
//Then call validate_RI to validate values with clause values.
//Loop through process until values have been validated and area has been found.
//Once done, print out Derived Conclusion List.
//Insert and remove variables from derived conclusion list queue accordingly
//Lastly, output the found area of specialization.
void ProcessArea_FW(string fieldName){
    bool found = false;

    do{
        int ci = search_cvl(fieldName);

        update_VL(ci);

        int ri = clause_to_rule(ci);

        found = validate_RI(ci);
        if(!found){
            ClauVarList[ci].checked = true;
        }

    }while(!found);

    logFile << "Derived Conclusion List: " << endl;
    for (int i = GLOB_VAR_LIST_SIZE - 2; i < GLOB_VAR_LIST_SIZE; i++){
        logFile << GlobVarList[i].name;

        if (GlobVarList[i].name == "AREA"){
            vArea = GlobVarList[i].area;
            logFile << " " << GlobVarList[i].area << endl;
        }
        else
            logFile << " " << GlobVarList[i].field << endl;
    }
    cout << "Looks like the area you should specialize in is: " << vArea << endl;

}