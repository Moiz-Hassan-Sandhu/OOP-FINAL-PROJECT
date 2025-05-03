#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;
//starting the project


// I am not creating register user function because no one will have a right to register a user, he or she can register himself as Executive if granted permission to register user

int uniqueID = 100000;      //to assign unique ID to each user so every time a user is created the unique ID will be incremented and assinged to the user ID

void mainMenu();

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
    int n_users;
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
            // I will  start working here for the TTL Assingment ( EXPIREIE DATE )
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


class Messages{
    protected:
        string message;
        string sender;
        string receiver;
        string type;
        bool isRead;
    public:
        Messages(string m, string s, string r){
            message = m;
            sender = s;
            receiver = r;
            isRead = false;
        }
        void setMessage(string m){
            message = m;
        }
        void setSender(string s){
            sender = s;
        }
        void setReceiver(string r){
            receiver = r;
        }
        void setIsRead(bool r){
            isRead = r;
        }
        string getMessage(){
            return message;
        }
        string getSender(){
            return sender;
        }
        string getReceiver(){
            return receiver;
        }
        bool getIsRead(){
            return isRead;
        }
};
class INFO:public Messages{

    public:
        INFO(string m, string s, string r):Messages(m,s,r){
            message = m;
            sender = s;
            receiver = r;
            type = "INFO";
            isRead = false;
        }
        void printMessage(){
            cout<<"Message: "<<message<<endl
                <<"Sender: "<<sender<<endl
                <<"Receiver: "<<receiver<<endl;
        }
        void markAsRead(){
            isRead = true;
        }

};

class PRIVATE:public Messages{
    private:
    string encrypted_message;
    string decrypted_message;
    int sent_to;
    char caesarShift(char c, int shift) {
        if (isupper(c))
            return char((c - 'A' + shift + 260) % 26 + 'A');
        if (islower(c))
            return char((c - 'a' + shift + 260) % 26 + 'a');
        return c;
    }
    void encryptMessage() {
        int key = sent_to % 10;           // last digit of sent_to
        encrypted_message.clear();
        for (char c : message)
            encrypted_message += caesarShift(c, +key);
    }

    public:
        PRIVATE(string m, string s, string r):Messages(m,s,r)
        {
            type = "PRIVATE";
            isRead = false;
        }
        void setSentTo(int id) {
            sent_to = id;
            encryptMessage();
        }
        void saveToFile(const string& filename = "private_messages.txt") {
            ofstream out(filename, ios::app);      // open in append mode
            if (!out) {
                cerr << "Error opening " << filename << " for writing\n";
                return;
            }
            // Format: sender|receiver|sent_to|encrypted_message\n
            out << sender << '|'<< receiver << '|'<< sent_to << '|'<< encrypted_message<< '\n';
            out.close();
        }


      
        void markAsRead(){
            isRead = true;
        }
        void setSentTo(int s){
            sent_to = s;
        }
        int getSentTo(){
            return sent_to;
        }
};

class ALERT:public Messages{
    public:
        ALERT(string m, string s, string r):Messages(m,s,r){
            message = m;
            sender = s;
            receiver = r;
            type = "ALERT";
            isRead = false;
        }
        void printMessage(){
            cout<<"Message: "<<message<<endl
                <<"Sender: "<<sender<<endl
                <<"Receiver: "<<receiver<<endl;
        }
        void markAsRead(){
            isRead = true;
        }
};


class Authentication{
    protected:
        //these data members are only for reading user.txt, so the class paidworkers get isolated from authentication function
        //user.txt is only read and write by authentication class and noting else
        int usercount;
        PaidWorkers* users;
        string OTP;
        
        public:
        Authentication(){
            usercount = 0;
            users = NULL;
            OTP = "";
        }
        
        void readfile(string pos)
        {
            ifstream in;
            
            if(pos == "Executive")
            {
                string line;
                in.open("user.txt", ios::in);
                while(getline(in, line, '\n'))
                {
                    usercount++;
                }
                users = new Executive[usercount];
            }

        }
        
        bool userExists(string name, string pos)
        {
            readfile(pos);
            return 0;

        }
        bool login(string pos)  //string to check position
        {
            string iname, ipassword;    //input name and input password
            cout<<"Enter your Username: ";
            cin>>iname;
            cout<<endl
                <<"Enter your Password: ";
            cin>>ipassword;
            if(userExists(iname, pos))
            {
                
            }
            else
            {
                cout<<endl
                    <<"User Doesn't Exist"<<endl
                    <<"Please Register User"<<endl;
                return 0;       
            }
            return 0;
        }
};

int main()
{
    mainMenu();
    // Junior j1(1,"Sannan","1234");
    // Employee e1(2,"Musawir","1234");
    // //now checking the access level of the user
    // PolicyEngine pe(&e1);
    // cout<<"Access Level : "<<pe.getAccessLevel()<<endl;
    // cout<<pe.Assign_Task(&j1);

    // cout<<endl<<endl;
    // //checking if the task is assigned to the junior user or not
    // if(j1.getTask() != nullptr)
    // {
    //     cout<<"Task Assigned to Junior User"<<endl;
    //     j1.getTask()->printTask();
    // }
    // else
    // {
    //     cout<<"No Task Assigned to Junior User"<<endl;
    // }
    // cout<<endl<<endl;
 
}
void mainMenu()
{
    cout<<endl<<endl<<"compiled sucessfully!"<<endl<<endl;
    int choice1;
    cout<<endl<<endl<<endl;
    cout<<"                          #===========================================#"<<endl
    <<"                              #          Welcome To OFFICE PORTAL         #"<<endl
    <<"                              #===========================================#"<<endl
    <<"                              #===========================================#"<<endl<<endl<<endl;
    cout<<endl<<endl<<endl;
    cout<<"                          #===========================================#"<<endl
    <<"                              #          Press 1 to Login as Executive    #"<<endl
    <<"                              #          Press 2 to Login as Director     #"<<endl
    <<"                              #          Press 3 to Login as Manager      #"<<endl
    <<"                              #          Press 4 to Login as Employee     #"<<endl
    <<"                              #          Press 5 to Login as Junior       #"<<endl
    <<"                              #===========================================#"<<endl<<endl<<endl;
    cout<<"Press your option to continue: ";
    cin>>choice1;
    switch(choice1)
    {
        case 1:
        {
            Authentication auth;
            if(auth.login("Executive"))
            {
                cout<<"Login Successfull"<<endl;
            }
            else
            {
                cout<<"Login Failed"<<endl<<endl<<endl;
                mainMenu();
            }
            break;
        }
        case 2:
        {
            Authentication auth;
            if(auth.login("Director"))
            {
                cout<<"Login Successfull"<<endl;
            }
            else
            {
                cout<<"Login Failed"<<endl<<endl<<endl;
                mainMenu();
            }
            break;
        }
        case 3:
        {
            Authentication auth;
            if(auth.login("Manager"))
            {
                cout<<"Login Successfull"<<endl;
            }
            else
            {
                cout<<"Login Failed"<<endl<<endl<<endl;
                mainMenu();
            }
            break;
        }
        case 4:
        {
            Authentication auth;
            if(auth.login("Employee"))
            {
                cout<<"Login Successfull"<<endl;
            }
            else
            {
                cout<<"Login Failed"<<endl<<endl<<endl;
                mainMenu();
            }
            break;
        }
        case 5:
        {
            Authentication auth;
            if(auth.login("Junior"))
            {
                cout<<"Login Successfull"<<endl;
            }
            else
            {
                cout<<"Login Failed"<<endl<<endl<<endl;
                mainMenu();
            }
        }
    }
}