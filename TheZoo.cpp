#include <iostream>
#include <jni.h>
#include <vector>
#include <fstream>
#include <string>
#include<bits/stdc++.h>

using namespace std;

int i = 0;
vector<string> stringOfFile;
string animalTrack, animalName, animalType, animalSubType, eggs, Nurse, data;

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialization options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}

void AddAnimal()
{
     /*
            TODO: Write proper code to add an animal to your vector (or array)
     */

	 // get and edit track number
	      cout << "Track Number: ";
	      cin >> animalTrack;
	      animalTrack.insert(animalTrack.begin(), 7 - animalTrack.length(), '0');

	      // get and edit animal name
	      cout << endl << "Animal Name: ";
	      cin >> animalName;
	      animalName.append(16 - animalName.length(), ' ');

	      // get and edit animal type
	      cout << endl << "Animal Type: ";
	      cin >> animalType;
	      animalType.append(16 - animalType.length(), ' ');

	      //get and edit animal sub type
	      cout << endl << "Animal Sub-Type: ";
	      cin >> animalSubType;
	      animalSubType.append(16 - animalSubType.length(), ' ');

	      // get num eggs
	      cout << endl << "Number of Eggs: ";
	      cin >> eggs;

	      //get nursing
	      cout << endl << "Nursing (0 for no 1 for yes): ";
	      cin >> Nurse;
	      cout << endl;

	      data = animalTrack + animalName + animalType + animalSubType + eggs + Nurse;
	      stringOfFile.push_back (data);

}


void RemoveAnimal()
{
     /*
            TODO: Write proper code to remove an animal from your vector (or array. Remmber to re-allocate proper size if using array)
     */
	 string item = "";

	   cout << "Enter Track Number (with zeros): ";
	   cin >> item;

	   std::vector<string>::iterator it;
	   it = std::find (stringOfFile.begin(), stringOfFile.end(), item);
	   if (it != stringOfFile.end())
	       stringOfFile.erase(it);
	   else
	   {
	       cout << "Track Number not found or entered incorrectly.." << endl;
	       RemoveAnimal();
	   }
}

void LoadDataFromFile()
{
     /*
            TODO: Write proper code to load data from input file (generated using JNI) into vector/array.
     */
	string file = "zoo.txt";
	   std::ifstream in(file.c_str());

	   if(!in)
	   {
	       std::cerr << "Cannot open the File: " << file << std::endl;
	   }
	   std::string str;
	   while(getline(in,str))
	   {
	       if(str.size()>0)
	       {
	           stringOfFile.push_back(str);
	       }
	   }
	   in.close();
}

void SaveDataToFile()
{
     /*
            TODO: Write proper code to store vector/array to file.
     */
	 fstream file;
	   string file_name = "zoo.txt";
	   file.open(file_name);
	   if(file.fail())
	       cout << "File Opening Failed";
	   else
	   {
	       int i = 0;
	       int as = stringOfFile.size();
	       while(as <=i)
	       {
	           file << stringOfFile[as];
	           as--;
	       }
	   }
}

//display data
void DisplayData()
{
   for (int  i = 0; i < stringOfFile.size(); i++)
   {
       cout << stringOfFile.at(i) << endl;
   }
}

void DisplayMenu()
{
     /*
            TODO: write proper code to display menu to user to select from
     */
	int option;
	menu:
	option = 0;
	cout << "-------------MENU------------------" << endl << endl;
	cout << "(1)Load Animal Data" << endl << "(2)Generate Data" << endl << "(3)Display Animal Data" << endl;
	cout << "(4)Add Record" << endl << "(5)Delete Record" << endl << "(6)Save Animal Data" << endl << endl;
	cout << "-----------------------------------" << endl;
	cin >> option;

	   switch(option)
	   {
	   case 1:
	       LoadDataFromFile();
	       goto menu;
	   case 2:
	       GenerateData();
	       goto menu;
	   case 3:
	       DisplayData();
	       goto menu;
	   case 4:
	       AddAnimal();
	       goto menu;
	   case 5:
	       RemoveAnimal();
	       goto menu;
	   case 6:
	       SaveDataToFile();
	       goto menu;
	   }
	}


int main()
{
	GenerateData();
	return 1;
}
