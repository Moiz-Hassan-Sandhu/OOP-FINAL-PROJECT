#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;
//starting the project

// 14 classes ban chuki

//check line 472 for the overloaded setsent_to();

//added new data member points in paidworkers class

// I am not creating register user function because no one will have a right to register a user, he or she can register himself as Executive if granted permission to register user

//still have to think about the unique ID system

//User file i.e. executive.txt, data writing format : ID|Name|Position|Password|Salary|points

//Added class ActivityLog in Policy Engine Inheritance List 

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
        int points; //Employee points added New Data member

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
        void setPoints(int p){
            points = p;
        }
        int getPoints(){
            return points;
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
class Executive: public PaidWorkers , public ActivityLog{
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

class PolicyEngine : public ActivityLog{
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
        // void setSentTo(int s){
        //     sent_to = s;
        // }
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
        int OTP;
        
        public:
        Authentication(){
            usercount = 0;
            users = NULL;
            OTP = 0;
        }
        
        void readuser(string pos)
        {
            if(usercount != 0)
            {
                delete [] users;
                usercount = 0;
            }
            
            ifstream in;
            int id = 0;
            int points = 0;
            double salary = 0;
            string position;
            string name;
            string password;
            string filename = "./" + pos + ".txt";

            if(pos == "Executive")
            {
                string line;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error opening file"<<endl<<endl;
                    mainMenu();
                }
                while(getline(in, line, '\n'))
                {
                    usercount++;
                }
                in.close();
                users = new Executive [usercount];
                int i = 0;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error Reading Users!"<<endl<<endl;
                    mainMenu();
                }
                while (in>>id)
                {
                    //1234|moiz|Executive|1234|1000|23
                    in.ignore(1);
                    getline(in, name, '|');
                    getline(in, position, '|');
                    getline(in, password, '|');
                    in>>salary;
                    in.ignore(1);
                    in>>points;
                    in.ignore(1);

                    cout<<id<<" "<<name<<" "<<position<<" "<<password<<" "<<salary<<" "<<points<<endl;
                    
                    //initializing data member array of paidworkers
                    users[i].setID(id);
                    users[i].setName(name);
                    users[i].setPassword(password);
                    users[i].setSalary(salary);
                    users[i].setPosition(position);
                    i++;
                }
                in.close();
            }
            else if(pos == "Director")
            {
                string line;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error opening file"<<endl<<endl;
                    mainMenu();
                }
                while(getline(in, line, '\n'))
                {
                    usercount++;
                }
                in.close();
                users = new Director [usercount];
                int i = 0;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error Reading Users!"<<endl<<endl;
                    mainMenu();
                }
                while (in>>id)
                {
                    //1234|moiz|Executive|1234|1000|23
                    in.ignore(1);
                    getline(in, name, '|');
                    getline(in, position, '|');
                    getline(in, password, '|');
                    in>>salary;
                    in.ignore(1);
                    in>>points;
                    in.ignore(1);
                    
                    //initializing data member array of paidworkers
                    users[i].setID(id);
                    users[i].setName(name);
                    users[i].setPassword(password);
                    users[i].setSalary(salary);
                    users[i].setPosition(position);
                    i++;
                }
                in.close();
            }
            else if(pos == "Manager")
            {
                string line;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error opening file"<<endl<<endl;
                    mainMenu();
                }
                while(getline(in, line, '\n'))
                {
                    usercount++;
                }
                in.close();
                users = new Manager [usercount];
                int i = 0;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error Reading Users!"<<endl<<endl;
                    mainMenu();
                }
                while (in>>id)
                {
                    //1234|moiz|Executive|1234|1000|23
                    in.ignore(1);
                    getline(in, name, '|');
                    getline(in, position, '|');
                    getline(in, password, '|');
                    in>>salary;
                    in.ignore(1);
                    in>>points;
                    in.ignore(1);
                    
                    //initializing data member array of paidworkers
                    users[i].setID(id);
                    users[i].setName(name);
                    users[i].setPassword(password);
                    users[i].setSalary(salary);
                    users[i].setPosition(position);
                    i++;
                }
                in.close();
            }
            else if(pos == "Employee")
            {
                string line;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error opening file"<<endl<<endl;
                    mainMenu();
                }
                while(getline(in, line, '\n'))
                {
                    usercount++;
                }
                in.close();
                users = new Employee [usercount];
                int i = 0;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error Reading Users!"<<endl<<endl;
                    mainMenu();
                }
                while (in>>id)
                {
                    //1234|moiz|Executive|1234|1000|23
                    in.ignore(1);
                    getline(in, name, '|');
                    getline(in, position, '|');
                    getline(in, password, '|');
                    in>>salary;
                    in.ignore(1);
                    in>>points;
                    in.ignore(1);
                    
                    //initializing data member array of paidworkers
                    users[i].setID(id);
                    users[i].setName(name);
                    users[i].setPassword(password);
                    users[i].setSalary(salary);
                    users[i].setPosition(position);
                    i++;
                }
                in.close();
            }
            else if(pos == "Junior")
            {
                string line;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                    <<"Error opening file"<<endl<<endl;
                    mainMenu();
                }
                while(getline(in, line, '\n'))
                {
                    usercount++;
                }
                in.close();
                users = new Junior [usercount];
                int i = 0;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error Reading Users!"<<endl<<endl;
                    mainMenu();
                }
                while (in>>id)
                {
                    //1234|moiz|Executive|1234|1000|23
                    in.ignore(1);
                    getline(in, name, '|');
                    getline(in, position, '|');
                    getline(in, password, '|');
                    in>>salary;
                    in.ignore(1);
                    in>>points;
                    in.ignore(1);
                    
                    //initializing data member array of paidworkers
                    users[i].setID(id);
                    users[i].setName(name);
                    users[i].setPassword(password);
                    users[i].setSalary(salary);
                    users[i].setPosition(position);
                    i++;
                }
                in.close();
            }
            else
            {
                cout<<endl<<endl
                    <<"Invalid Position!"<<endl<<endl;
                mainMenu();
            }
        }
        int userExists(string name, string pos)
        {
            readuser(pos);
            for(int i = 0; i < usercount; i++)
            {
                if(users[i].getName() == name)
                {
                    return i;
                }
            }           
            return -1;
        }
        
        void otpGenerator()
        {
            srand(time(0));
            OTP = 100000 + rand() % 900000;
            ofstream out;
            out.open("./OTP.txt", ios::out);
            if(!out)
            {
                cout<<endl<<endl
                    <<"Error opening OTP file"<<endl<<endl;
                mainMenu();
            }
            out<<OTP;
            out.close();
        }

        bool login(string pos)  //string to check position
        {
            string iname, ipassword;    //input name and input password
            cout<<"Enter your Username: ";
            cin>>iname;
            int index = userExists(iname, pos);
            if(index != -1)
            {
                cout<<endl
                <<"Enter your Password: ";
                cin>>ipassword;
                if(users[index].getPassword() == ipassword)
                {
                    int otp = 0;
                    otpGenerator();
                    cout<<"Enter the OTP: ";
                    cin>>otp;
                    if(OTP == otp)
                    {
                        remove("./OTP.txt");
                        return true;
                    }
                    else
                    {
                        cout<<endl<<endl
                        <<"OTP Incorrect"<<endl;
                        remove("./OTP.txt");
                        return false;
                    }
                }
                else
                {
                    cout<<endl<<endl
                        <<"Password Incorrect"<<endl;
                    return 0;
                }
            }
            else
            {
                cout<<endl<<endl
                    <<"User Doesn't Exist"<<endl
                    <<"Please Register User"<<endl;
                return 0;       
            }
            return 0;
        }
};

class ActivityLog{
    protected:
        int countLogs;
        string* logs;
    public:
        ActivityLog(){
            countLogs = 0;
            logs = NULL;
        }
        void readSinginLogs()
        {
            if(countLogs != 0)
            {
                delete [] logs;
                countLogs = 0;
            }
            ifstream in;
            in.open("./signinlogs.txt", ios::in);
            if (!in)
            {
                cout<<endl<<endl
                    <<"Error Counting singin Logs!"<<endl<<endl;
                return;
            }
            string line;
            while(in>>line)
            {
                countLogs++;
            }
            in.close();
            logs = new string [countLogs];
            int i = 0;
            in.open("./signinlogs.txt", ios::in);
            if(!in)
            {
                cout<<endl<<endl
                    <<"Error Reading singin Logs!"<<endl<<endl;
                return;
            }
            while(in>>line)
            {
                logs[i] = line;
                i++;
            }
            in.close();
            return;
        }
        void displaySinginLogs()
        {
            readSinginLogs();
            for(int i = 0; i < countLogs; i++)
            {
                cout<<logs[i]<<endl;
            }
        }
    
};

int main()
{
    mainMenu();
}

void mainMenu()
{
    int choice1;
    cout<<endl<<endl<<endl;
    cout<<"                              #===========================================#"<<endl
    <<"                              #          Welcome To OFFICE PORTAL         #"<<endl
    <<"                              #===========================================#"<<endl
    <<"                              #          Press 1 to Login as Executive    #"<<endl
    <<"                              #          Press 2 to Login as Director     #"<<endl
    <<"                              #          Press 3 to Login as Manager      #"<<endl
    <<"                              #          Press 4 to Login as Employee     #"<<endl
    <<"                              #          Press 5 to Login as Junior       #"<<endl
    <<"                              #          Press 6 to Exit                  #"<<endl
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
            break;
        }
        case 6:
        {
            cout<<endl
                <<"Have a Good Day!"<<endl<<endl<<endl;
            break;
        }
        default:
        {
            cout<<"Invalid Option"<<endl<<endl<<endl;
            mainMenu();
        }
    }
}

void ExecutiveMenu()
{
    cout<<"1. Assign Task"<<endl;
    cout<<"2. View My Tasks"<<endl;
    cout<<"3. View All Tasks"<<endl;
}