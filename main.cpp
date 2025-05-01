#include<iostream>
#include<string>
#include<cstring>
using namespace std;
//starting the project


class task {
    string task_name;
    string task_description;
    string task_status;
    string task_assigned_by;
    string task_assigned_to;
    int TTL_time;
    public:
    task(){
        task_name="";
        task_description="";
        task_status="";
        task_assigned_by="";
        task_assigned_to="";
        TTL_time=0;
    }
    task(string name,string description,string status,string assigned_by,string assigned_to,int TTL){
        task_name=name;
        task_description=description;
        task_status=status;
        task_assigned_by=assigned_by;
        task_assigned_to=assigned_to;
        TTL_time=TTL;
    }
    void setTaskName(string name){
        task_name=name;
    }
    void setTaskDescription(string description){
        task_description=description;
    }
    void setTaskStatus(string status){
        task_status=status;
    }
    void setTaskAssignedBy(string assigned_by){
        task_assigned_by=assigned_by;
    }
    void setTaskAssignedTo(string assigned_to){
        task_assigned_to=assigned_to;
    }
    void setTTLTime(int TTL){
        TTL_time=TTL;
    }
    string getTaskName(){
        return task_name;
    }
    string getTaskDescription(){
        return task_description;
    }
    string getTaskStatus(){
        return task_status;
    }
    string getTaskAssignedBy(){
        return task_assigned_by;
    }
    string getTaskAssignedTo(){
        return task_assigned_to;
    }
    int getTTLTime(){
        return TTL_time;
    }
    void printTask(){
        cout<<"Task Name: "<<task_name<<endl
            <<"Task Description: "<<task_description<<endl
            <<"Task Status: "<<task_status<<endl
            <<"Task Assigned By: "<<task_assigned_by<<endl
            <<"Task Assigned To: "<<task_assigned_to<<endl
            <<"TTL Time: "<<TTL_time<<endl;
    }
    
};


class PaidWorkers{
    protected:
    int ID;
    string name;
    string position;
    string password;
    float salary;
    task* t;
    bool new_messages;

    public:
    virtual void print() = 0;//making this an abstarct class we donot need an object of this class
    void setID(int id){
        ID = id;
    }
    void setName(string n){
        name = n;
    }
    void setPosition(string p){
        position = p;
    }
    void setPassword(string p){
        password = p;
    }
    void setSalary(float s){
        salary = s;
    }
    void setTask(task* tsk){
        t = tsk;
    }
    void setNewMessages(bool n){
        new_messages = n;
    }
    int getID(){
        return ID;
    }
    string getName(){
        return name;
    }
    string getPassword(){
        return password;
    }
    string getPosition(){
        return position;
    }
    float getSalary(){
        return salary;
    }
    task* getTask(){
        return t;
    }
    bool getNewMessages(){
        return new_messages;
    }
    
    

};

class Junior: public PaidWorkers{
    public:
    Junior(){
        ID=0;
        name="";
        position="Junior";
        password="";
        salary=1000.0;
        t=nullptr;
        new_messages=0;

    }
    Junior(int id,string n,string pass){
        ID=id;
        name=n;
        position="Junior";
        password=pass;
        salary=1000.0;
        t=nullptr;
        new_messages=0;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }
};

class Employee: public PaidWorkers{
    public:
    Employee(){
        ID=0;
        name="";
        position="Employee";
        password="";
        salary=2000.0;
        t=nullptr;
        new_messages=0;

    }
    Employee(int id,string n,string pass){
        ID=id;
        name=n;
        position="Employee";
        password=pass;
        salary=2000.0;
        t=nullptr;
        new_messages=0;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }

};
class Manager: public PaidWorkers{
    public:
    Manager(){
        ID=0;
        name="";
        position="Manager";
        password="";
        salary=3000.0;
        t=nullptr;
        new_messages=0;

    }
    Manager(int id,string n,string pass){
        ID=id;
        name=n;
        position="Manager";
        password=pass;
        salary=3000.0;
        t=nullptr;
        new_messages=0;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }

};

class Director: public PaidWorkers{
    public:
    Director(){
        ID=0;
        name="";
        position="Director";
        password="";
        salary=4000.0;
        t=nullptr;
        new_messages=0;

    }
    Director(int id,string n,string pass){
        ID=id;
        name=n;
        position="Director";
        password=pass;
        salary=4000.0;
        t=nullptr;
        new_messages=0;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }

};
class Executive: public PaidWorkers{
    public:
    Executive(){
        ID=0;
        name="";
        position="Executive";
        password="";
        salary=5000.0;
        t=nullptr;
        new_messages=0;

    }
    Executive(int id,string n,string pass){
        ID=id;
        name=n;
        position="Executive";
        password=pass;
        salary=5000.0;
        t=nullptr;
        new_messages=0;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }

};

class PolicyEngine{
    private:
    PaidWorkers* pw;
    int accessLevel;
    string position;
    

    public:
    PolicyEngine(PaidWorkers* p){
        pw = p;
        if(pw->getPosition() == "Junior"){
            accessLevel = 1;
        }
        else if(pw->getPosition() == "Employee"){
            accessLevel = 2;
        }
        else if(pw->getPosition() == "Manager"){
            accessLevel = 3;
        }
        else if(pw->getPosition() == "Director"){
            accessLevel = 4;
        }
        else if(pw->getPosition() == "Executive"){
            accessLevel = 5;
        }
        else{
            cout<<"Invalid Position"<<endl;
        }
    }

    int getAccessLevel(){
        return accessLevel;
    }
    string getPosition(){
        return position;
    }

    bool Assign_Task(PaidWorkers* p){
       PolicyEngine pe(p);
       if(pe.accessLevel <= accessLevel){
            cout<<"You have permission to assign task to this user"<<endl;
            task* t = new task;
            cout<<"Enter Task Name: ";
            string name;
            getline(cin, name);
            t->setTaskName(name);
            cout<<"Enter Task Description: ";
            string description;
            getline(cin, description);
            t->setTaskDescription(description);
            t->setTaskStatus("Assigned");
            t->setTaskAssignedBy(pw->getName());
            t->setTaskAssignedTo(p->getName());
            cout<<"Enter TTL Time: ";
            int TTL;
            cin>>TTL;
            t->setTTLTime(TTL);
            p->setTask(t);
            cout<<"Task Assigned Successfully"<<endl;
            cout<<"\n\n===========Task Details============ "<<endl;
            t->printTask();
            cout<<"===================================="<<endl;
            p->setTask(t);

            return true;
        }
        else{
            cout<<"You do not have permission to assign task to this user"<<endl;
            return false;
        }
    }

};











class Authentication{
    protected:
        //these data members are only for reading user.txt, so the class paidworkers get isolated from authentication function
        int usercount;
        string name;
        string password;
        string OTP;
        
    public:
        bool login(string name, string password)
        {
            if(userExists(name))
            {
                
            }
            else
            {
                cout<<endl
                    <<"User Doesn't Exist"<<endl
                    <<"Please Register User"<<endl;
                return 0;       
            }
        }
        bool userExists(string name)
        {
            return 0;

        }
        string hashedpassword()
        {
            int size = 1;
            char* pass = new char [size];
            int ci = 0; //current index
            char ch;
            while (cin.get(ch))
            {
                if(ch == '\n')
                {
                    break;
                }
                //else if(ch == '')

            }
            
            
            return password;
            //inputs the password from the user by keeping it hashed on console and returns the original password typed by the user.
        }
};

int main()
{
    /*cout<<endl<<endl<<"compiled sucessfully!"<<endl<<endl;
    int choice1;
    cout<<"#===========================================#"<<endl
        <<"#          Welcome To OFFICE PORTAL         #"<<endl
        <<"#===========================================#"<<endl
        <<"#          Press 1 to Login                 #"<<endl
        <<"#===========================================#"<<endl<<endl;
    cout<<"Press your option to continue: ";
    cin>>choice1;
    switch(choice1)
    {
        case 1:
        {
            string name;
            Authentication auth;
            cout<<"Enter your Username: ";
            cin>>name;
            cout<<endl
                <<"Enter your Password: ";
            string pass = auth.hashedpassword();
            auth.login(name, pass);
        }
<<<<<<< HEAD
    }*/
    Junior j1(1,"Sannan","1234");
    Employee e1(2,"Musawir","1234");
    //now checking the access level of the user
    PolicyEngine pe(&e1);
    cout<<"Access Level : "<<pe.getAccessLevel()<<endl;
    cout<<pe.Assign_Task(&j1);

    cout<<endl<<endl;
    //checking if the task is assigned to the junior user or not
    if(j1.getTask() != nullptr)
    {
        cout<<"Task Assigned to Junior User"<<endl;
        j1.getTask()->printTask();
    }
    else
    {
        cout<<"No Task Assigned to Junior User"<<endl;
    }
    cout<<endl<<endl;

}