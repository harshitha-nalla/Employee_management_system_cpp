#include<bits/stdc++.h>
using namespace std;
class emp{
    string name;
    int age;
    float salary;
    string designation;
    int emp_id;
    string current_project;
    string address;
    static int e_id;
    public:
    void setemp_id(){
        ifstream fis;
        fis.open("temp.txt");
        fis>>e_id;

        fis.close();
    }
    void write_emp_id() {
        ofstream fos;
        fos.open("temp.txt");
        fos << e_id;
        fos.close();
    }
    int getemp_id(){
        return emp_id;
    }
    string getCurrProject() {
        return current_project;
    }
    void setCurrProject(string project) {
        current_project = project;
    }
    friend ofstream& operator<<(ofstream& fos,emp &e);
    friend ifstream& operator>>(ifstream& fis,emp &e);
    friend istream& operator>>(istream& fin,emp &e);
    friend ostream& operator<<(ostream& fout,emp &e);
    

};
istream& operator>>(istream& fin,emp &e){
    cout<<"Enter name of the employee: ";
    getline(fin>>ws,e.name);
    cout<<"Enter the age of the employee: ";
    fin>>e.age;
    cout<<"Enter the address of the employee: ";
    getline(fin>>ws,e.address);
    cout<<"Enter the salary of the employee: ";
    fin>>e.salary;
    cout<<"Enter the designation of the employee: ";
    getline(fin>>ws,e.designation);
    e.emp_id=e.e_id++;
    e.current_project="N/A";
    return fin;
}


ifstream& operator>>(ifstream& fis,emp &e){
    string t;
    stringstream ss; 
   getline(fis>>ws,t,'\n');
   ss<<t;
   ss>>e.emp_id; 
   ss.clear();  
getline(fis>>ws,e.name);
  getline(fis>>ws,t,'\n');
   ss<<t;
   ss>>e.age; 
    ss.clear();
    getline(fis>>ws,e.address);
    getline(fis>>ws,e.designation);
     getline(fis>>ws,t,'\n');
    ss<<t;
   ss>>e.salary; 
    getline(fis>>ws,e.current_project);
    return fis;
}


ofstream& operator<<(ofstream& fos,emp &e){
    fos<<e.emp_id<<endl;
    fos<<e.name<<endl;
    fos<<e.age<<endl;
    fos<<e.address<<endl;
    fos<<e.designation<<endl;
    fos<<e.salary<<endl;
    fos<<e.current_project<<endl;
    return fos;

}
ostream& operator<<(ostream& fout,emp &e){
    fout<<"Name of the employee is: "<<e.name<<endl;
    fout<<"Age of the employee is: "<<e.age<<endl;
    fout<<"Address of the employee is: "<<e.address<<endl;
    fout<<"Employee id is: "<<e.emp_id<<endl;
    fout<<"Designation of the employee is: "<<e.designation<<endl;
    fout<<"Salary of the employee is: ";
    printf("%.2f\n",e.salary);
    fout<<"Current project the employee is associated with is: "<<e.current_project<<endl;
    return fout;    
}

void menu(){
    cout<<".................EMPLOYEE MANAGEMENT SYSTEM....................."<<endl;
    cout<<"Enter 1 to add an employee"<<endl;
    cout<<"Enter 2 to remove an employee"<<endl;
    cout<<"Enter 3 to edit the details of an employee"<<endl;
    cout<<"Enter 4 to search and display the details of an employee"<<endl;
    cout<<"Enter 5 to print every employee" << endl;
    cout<<"Enter 6 to create a project"<<endl;
    cout<<"Enter 7 to manage the project"<<endl;
    cout<<"Enter 8 to exit the programm"<<endl;
    cout<<"Enter your choice: ";

}
void add(string filename){
    emp e;
    cin>>e;
    ofstream fos;
    fos.open(filename,ios::app);
    fos<<e;
    fos.close();
   
}
void Remove(string filename){
    cout<<"Enter the id of the employee to be removed: ";
    int id;
    emp e;
    bool f=false;
    cin>>id;
     ifstream fis;
     ofstream fos;
     fis.open(filename);
     fos.open("remove.txt");
     while(fis>>e){
        
        if(id==e.getemp_id()){
            f=true;
            continue;
        }
        fos<<e;
     }
     fis.close();
     fos.close();
     if(!f) {
        cout << "Id not found!";
     }
     remove(filename.c_str());
    rename("remove.txt", filename.c_str());
    
}

void Remove(string filename, string project, string projectName){
    cout<<"Enter the id of the employee to be removed: ";
    int id;
    emp e;
    bool f=false;
    cin>>id;
     ifstream fis;
     ofstream fos;
     fis.open(project);
     fos.open("remove.txt");
     while(fis>>e){
        
        if(id!=e.getemp_id()){
            fos<<e;
        }
        else {
            f = true;
        }
     }
     fis.close();
     fos.close();
     if(!f) {
        cout << "Employee with id " << id << " was not found in the project" << endl;
        return ;
     }
     remove(project.c_str());
    rename("remove.txt", project.c_str());

     fis.open(filename);
     fos.open("remove.txt");
     while(fis>>e){
        
        if(id==e.getemp_id()){
            e.setCurrProject("N/A");
            f=true;
        }
        fos<<e;
     }
     fis.close();
     fos.close();
     remove(filename.c_str());
    rename("remove.txt", filename.c_str());
}

void Remove(string filename, string project, string projectName, int id){
    emp e;
     ifstream fis;
     ofstream fos;
     fis.open(project);
     fos.open("remove.txt");
     while(fis>>e){
        if(id!=e.getemp_id()){
            fos<<e;
        }
     }
     fis.close();
     fos.close();
     remove(project.c_str());
    rename("remove.txt", project.c_str());

     fis.open(filename);
     fos.open("remove.txt");
     while(fis>>e){
        
        if(id==e.getemp_id()){
            e.setCurrProject("N/A");
        }
        fos<<e;
     }
     fis.close();
     fos.close();
     remove(filename.c_str());
    rename("remove.txt", filename.c_str());
}

void PrintEveryEmployee(string filename) {
    ifstream fis;
    fis.open(filename);
    emp e;
    cout << endl << endl;
    cout << "Details of the employs: " << endl << endl;
    while(fis >> e) {
        cout << e;
        cout << endl;
    }
    fis.close();
}

void edit(string filename) {
    cout << "Enter the employee ID of the employee that you want to edit: ";
    int id;
    emp e;
    cin >> id;
    ifstream fis;
    ofstream fos;
    fis.open(filename);
    fos.open("edit.txt");
    bool found = false;
    while (fis >> e) {
        if (id == e.getemp_id()) {
            found = true;
            cout << "Current details of the employee with ID " << id << ":" << endl;
            cout << e;
            cout << "Enter the new details:" << endl;
            cin >> e;
            fos << e;
            cout << "Employee details updated successfully!" << endl;
        } else {
            fos << e;
        }
    }
    fis.close();
    fos.close();
    if (!found) {
        cout << "Employee with ID " << id << " not found!" << endl;
    }
    remove(filename.c_str());
    rename("edit.txt", filename.c_str());
}
void search(string filename){
    emp e;
    int id;
    cout<<"Enter the employee id to be searched: ";
    cin>>id;
    ifstream fis;
    fis.open(filename);
    bool found = false;
    while(fis>>e){
        if(id==e.getemp_id()){
            found = true;
            break;
        }
    }
    if(found){
    cout<<e;
}
else{
    cout<<"Employee not found!"<<endl;
}

}

string getProject(string projectName) {
    replace(projectName.begin(), projectName.end(), ' ', '_');
    projectName = "Projects/"+projectName;
    projectName+=".txt";
    return projectName;
}


void printProjectMenu() {
    cout << "1) To add a memeber" << endl;
    cout << "2) To delete a memeber" << endl;
    cout << "3) To Print every member of a project" << endl;
    cout << "4) To delete the project" << endl;
    cout << "5) To return to main menu" << endl;
    cout << "Enter your choice: ";
}

void add_into_project(string project, string filename, string projectName) {
    int id;
    ifstream fis;
    ofstream fos, ofs;
    fis.open(filename);
    fos.open(project, ios::app);
    ofs.open("edit.txt");
    cout << "Enter the employee id you want to add: ";
    cin >> id;
    emp e;
    bool f = false;
    while(fis >> e) {
        if(e.getemp_id() == id && e.getCurrProject() == "N/A") {
            f = true;
            e.setCurrProject(projectName);
            fos << e;
        }
        ofs << e;
    }
    fis.close();
    fos.close();
    ofs.close();
    if(f) {
        remove(filename.c_str());
        rename("edit.txt", filename.c_str());
        cout << "Employee with " << id << " successfully added to " << projectName << endl;
    }
    else {
        remove("edit.txt");
        cout << "Either No Employee with " << id << " is was found or the employee is busy with other project" << endl;
    }
}

void Delete_Project(string filename, string project, string projectName) {
    ifstream fis;
    fis.open(project);
    if(!fis.is_open()) {
        cout << "The Project doesnot Exist!" << endl;
    }
    emp e;
    while(fis >> e) {
        fis.close();
        Remove(filename, project, projectName, e.getemp_id());
        fis.open(project);
    }
    fis.close();
    remove(project.c_str());

}

void create_or_manage_project(string filename) {
    string project, projectName;
    cout << "Enter the name of the project: ";
    getline(cin >> ws, projectName);
    project = getProject(projectName);
    int choice;
    while(1) {
        printProjectMenu();
        cin >> choice;
        switch(choice) {
            case 1: add_into_project(project, filename, projectName);
                    break;
            case 2: Remove(filename, project, projectName);
                    break;
            case 3: PrintEveryEmployee(project);
                    break;
            case 4: Delete_Project(filename, project, projectName);
            case 5: return ;
            default:cout << "Enter a valid input!" << endl;
        }
    }
}


int emp::e_id=0;
emp s;
int main(){
    s.setemp_id();
    string filename="employee_data.txt";
    while(1){
        menu();
        int x;
        cin>>x;
        switch(x){
            case 1:
            add(filename);
            break;
            case 2:
            Remove(filename);
            break;
            case 3:
            edit(filename);
            break;
            case 4:
            search(filename);
            break;
            case 5:
            PrintEveryEmployee(filename);
            break;
             case 6:
            create_or_manage_project(filename);
             break;
            case 7:
            create_or_manage_project(filename);
            break;
            case 8:
            s.write_emp_id();
            exit(0);
            default:cout<<"Enter a valid input" << endl << endl;
        }

    }
    return 0;
}