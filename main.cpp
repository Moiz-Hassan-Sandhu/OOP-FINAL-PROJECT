#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;


//starting the project

// 14 classes ban chuki




//-------------Done--------------
//Runtime polymorphism using base class pointers
//Authentication done
//Task Assingment
//Min 3 level of inheritance (We just have to assign special tasks to users)
//Activity Logs (AUDIT LOGOING)



//-------------In Progress------------
//Time To Live
//Messages System                                                              ----->Review Statment once again 
//Tasks can be assigned priority levels: High, Medium, Low.
//Encryption Key for Decrypting Private Messages, Intended Users functionality
//Info
//ADD USER (HIRE NEW Subordinates)



//-------------To Do------------
//Task Deligation
//Employee Performance (points) System
//Global Notification System
//Special Tasks for each position to justify hierarchical levels
//still have to think about the unique ID system



//------------Bouns------------
//Digital signatures for task approvals (hash of username + timestamp)
//Cycle detection in task delegation chains
//Encrypted binary log file.
// GUI-style dashboard using ASCII art and box formatting

//------------------------------------------------------------------------------------------------------



//check for the overloaded setsent_to(); //commented out, causing runtime error

//added new data member points in paidworkers class int points and bool login


//User files i.e. executive.txt, data writing format : ID|Name|Position|Password|Salary|points

//Policy Engine now Inherits Activity Logs

//------------------------------------------------------------------------------------------------------

void mainMenu();


class task {
    string task_name;
    string task_description;
    string task_status;
    string task_assigned_by;
    string task_assigned_to;
    time_t TTL_time;
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
    void setTTLTime(time_t TTL){
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
     time_t getTTLTime(){
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
    ~task(){}
};


class PaidWorkers{
    protected:
        int ID;
        string name;
        string position;
        string password;
        float salary;
        bool new_messages;
        int points; //Employee points added New Data member
        bool login; //Login as data member to check on the run time in main menus if the user is logged in or not

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
        bool getNewMessages(){
            return new_messages;
        }
        void setPoints(int p){
            points = p;
        }
        int getPoints(){
            return points;
        }
        void setLogin(bool l){
            login = l;
        }
        bool getLogin(){
            return login;
        }
        virtual ~PaidWorkers(){}
};


class Junior: public PaidWorkers{
    public:
    Junior(){
        ID=0;
        name="";
        position="Junior";
        password="";
        salary=1000.0;
        new_messages=0;
        points=0;
        login=false;

    }
    Junior(int id,string n,string pass){
        ID=id;
        name=n;
        position="Junior";
        password=pass;
        salary=1000.0;
        new_messages=0;
        points=0;
        login=false;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }
};


class Employee: public Junior{
    public:
    Employee(){
        ID=0;
        name="";
        position="Employee";
        password="";
        salary=2000.0;
        new_messages=0;
        points=0;
        login=false;

    }
    Employee(int id,string n,string pass){
        ID=id;
        name=n;
        position="Employee";
        password=pass;
        salary=2000.0;
        new_messages=0;
        points=0;
        login=false;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }

};


class Manager: public Employee{
    public:
    Manager(){
        ID=0;
        name="";
        position="Manager";
        password="";
        salary=3000.0;
        new_messages=0;
        points=0;
        login=false;

    }
    Manager(int id,string n,string pass){
        ID=id;
        name=n;
        position="Manager";
        password=pass;
        salary=3000.0;
        new_messages=0;
        points=0;
        login=false;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }

};


class Director: public Manager{
    public:
    Director(){
        ID=0;
        name="";
        position="Director";
        password="";
        salary=4000.0;
        new_messages=0;
        points=0;
        login=false;
    }
    Director(int id,string n,string pass){
        ID=id;
        name=n;
        position="Director";
        password=pass;
        salary=4000.0;
        new_messages=0;
        points=0;
        login=false;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }

};


class Executive: public Director {
    public:
    Executive(){
        ID=0;
        name="";
        position="Executive";
        password="";
        salary=5000.0;
        new_messages=0;
        points=0;
        login=false;

    }
    Executive(int id,string n,string pass){
        ID=id;
        name=n;
        position="Executive";
        password=pass;
        salary=5000.0;
        new_messages=0;
        points=0;
        login=false;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }
};


class ActivityLog{
    protected:
        int countLogs;
        int* threatLevel;
        string outlog;
        string* logs;
    public:
        ActivityLog(){
            countLogs = 0;
            threatLevel = NULL;
            logs = NULL;
            outlog = "";
        }
        ActivityLog(string l) : outlog(l){}

        string getCurrentTime() const {         //just to get the newtime without getting the new line character at the end od the current time
            time_t now = time(0);                 //current time stamp to now in long long int form
            string newtime = ctime(&now);        //current timestamp to string
            if (!newtime.empty() && newtime.back() == '\n') //if string is not empty and the last char is '\n'
                newtime.pop_back();                         //then remove that charachter
            return newtime;                                 //return newtime
        }
        void readSinginLogs()
        {
            if(countLogs != 0)
            {
                delete [] logs;
                countLogs = 0;
            }
            ifstream in;
            in.open("./Activitylogs.txt", ios::in);
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
            threatLevel = new int [countLogs]();
            int i = 0;
            in.open("./Activitylogs.txt", ios::in);
            if(!in)
            {
                cout<<endl<<endl
                    <<"Error Reading singin Logs!"<<endl<<endl;
                return;
            }
            while(getline(in, line, '|'))
            {
                logs[i] = line;
                in>>threatLevel[i];
                in.ignore(1);   //|
                i++;
            }
            in.close();
            return;
        }
        friend ostream& operator<<(ostream& out, ActivityLog& write);
};


ostream& operator<<(ostream& out, ActivityLog& write)
{
    out << write.outlog;
    write.outlog = "";
    return out;
}


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
        ~Messages(){
            
        }
};
class INFO:public Messages{

    string senders_position;

    public:
        INFO(string m, string s, string sp, string r):Messages(m,s,r){
            senders_position = sp;
            message = m;
            sender = s;
            receiver = r;
            type = "INFO";
            isRead = false;
        }
        string getSendersPosition(){
            return senders_position;
        }
        void printMessage(){
            cout<<"Message: "<<message<<endl
                <<"Sender: "<<sender<<endl
                <<"Receiver: "<<receiver<<endl;
        }
        void markAsRead(){
            isRead = true;
        }
        ~INFO(){}
};


class PRIVATE : public Messages {
private:
    string encrypted_message;
    string decrypted_message;
    int    sent_to;  
    

    // simple Caesar‐shift helper (shift can be positive or negative)
    char caesarShift(char c, int shift) 
    {
        if (isupper(c))
            return char((c - 'A' + shift + 260) % 26 + 'A');
        if (islower(c))
            return char((c - 'a' + shift + 260) % 26 + 'a');
        return c;
    }

    // encrypt using last TWO digits of sent_to
    void encryptMessage() {
        int key = sent_to % 100;         // now 0..99  
        int s  = key % 26;               // reduce to 0..25
        encrypted_message.clear();
        for (char c : message)
            encrypted_message += caesarShift(c, +s);
    }

public:
/**
 * Constructs a PRIVATE message object, initializing the message, sender, receiver, and recipient ID.
 * Encrypts the message using a key derived from the recipient ID on construction.
 * 
 * @param m The message content.
 * @param s The sender of the message.
 * @param r The receiver of the message.
 * @param id The ID of the intended recipient, used for encryption.
 */


    PRIVATE(const string& m, const string& s, const string& r, int id)
      : Messages(m, s, r)
    {
        message = m;
        sender  = s;
        receiver = r;
        sent_to = id;
        encryptMessage();               // encrypt on construction                
        type   = "PRIVATE";
        isRead = false;
    }


    // setting the recipient ID also re-encrypts
    void setSentTo(int id) {
        sent_to = id;
        encryptMessage();
    }

    int getSentTo() const {
        return sent_to;
    }

    // write to file as before
    void saveToFile(const string& filename = "private_messages.txt") {
        ofstream out(filename, ios::app);
        if (!out) {
            cerr << "Error opening " << filename << "\n";
            return;
        }
        // sender|receiver|sent_to|encrypted_message
        out << sender << '|'
            << receiver << '|'
            << sent_to << '|'
            << encrypted_message << "\n";
    }

   

    void markAsRead() {
        isRead = true;
    }
    ~PRIVATE(){}
};

char caesarShift(char c, int shift) {
    if (isupper(c))
        return char((c - 'A' + shift + 260) % 26 + 'A');
    if (islower(c))
        return char((c - 'a' + shift + 260) % 26 + 'a');
    return c;
}


void decryptInteractive(string message, int sent_to) {
    int entered_id;
    cout << "Decrypting message...\n";
    cout<<"Enter your last two digits of ID to decrypt: ";
    cin  >> entered_id;
    int expected = sent_to % 100;
    if (entered_id != expected) {
        cout << "Incorrect key—cannot decrypt.\n";
        return;
    }

    int s = entered_id % 26;
    string decrypted_message;
    for (char c : message){
        decrypted_message += caesarShift(c, -s);
    }

    cout << "Decrypted message:\n" 
         << decrypted_message << "\n";
}


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
        ~ALERT(){}
};
class PolicyEngine : public ActivityLog{
    private:

    //data members
    int n_users;
    PaidWorkers* pw;
    int accessLevel;
    string position;

    // private member fucntions
    
    bool isTaskExpired(task* t){
        if(!t)
        {
            return false;
        }
        time_t now = time(0);
        return now > t->getTTLTime();
    }

    task* readTask(ifstream& in, PaidWorkers* user){        //TTL BY RECURRSION
           string line;
           if(!getline(in, line))
           {
                return nullptr;
           }
           
           string name, description, status, assigned_by, assigned_to;
           time_t ttl;
           
    }
    
    
    
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
            cin.ignore();
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
            time_t TTL;
            int assingedDays = 0;
            // I will  start working here for the TTL Assingment ( EXPIREIE DATE )
            cin>>TTL;
            t->setTTLTime(TTL);
            //writing the task to the file
            ofstream out("Task.txt",ios::app);
            if(!out){
                cout<<"Error opening file"<<endl;
                return false;
            }
            //outing time also to the file
            time_t currentTime = time(0); // Get current time
            char* dateTime = ctime(&currentTime); // Convert to string
            out<<t->getTaskName()<<"|"<<t->getTaskDescription()<<"|"<<t->getTaskStatus()<<"|"<<t->getTaskAssignedBy()<<"|"<<t->getTaskAssignedTo()<<"|"<<TTL<<"|"<< dateTime<< endl;


            cin>>assingedDays;
            time_t deadline = time(0) + (assingedDays * 24 * 60 * 60);
            t->setTTLTime(deadline);

            ofstream out;
            out.open("Task.txt",ios::app);
            out << t->getTaskName() << "|"
                << t->getTaskDescription() << "|"
                << t->getTaskStatus() << "|"
                << t->getTaskAssignedBy() << "|"
                << t->getTaskAssignedTo() << "|"
                << t->getTTLTime() << endl;
            out.close();

            ActivityLog logging( "Task: " + t->getTaskName() + " assigned to " + p->getName() + " by " + pw->getName());
            out.open("ActivityLog.txt",ios::app);
            out << logging << endl;
            out.close();

            p->setTask(t);
            cout<<"Task Assigned Successfully"<<endl;

            cout<<"\n\n===========Task Details============ "<<endl;
            t->printTask();
            cout<<"===================================="<<endl;
            return true;
        }
        else
        {
            cout<<"You do not have permission to assign task to this user"<<endl;
            return false;
        }
        return false;
    }


    void viewTask(PaidWorkers* p){
        ifstream in;
        in.open("Task.txt");
        task* userTask = readTask(in, p);
        in.close();
        
        if(userTask)
        {
            cout<<"\n\n===========Task Details============ "<<endl;
            userTask->printTask();
            cout<<"===================================="<<endl;
            p->setTask(userTask);
            delete userTask;
        }
        else
        {
            cout<<endl<<endl
                <<"No task found for current user!"<<endl<<endl;
        }

    }


    bool can_send_info(PaidWorkers *p){
        PolicyEngine pe(p);
        if(pe.accessLevel < accessLevel){
             cout<<"\nYou have permission to send information to all "<<p->getPosition()<<endl;

             cout<<"\nEnter the Information: ";
                string info_message;
                cin.ignore(); // Clear the newline character from the input buffer
                getline(cin, info_message);
             INFO* info=new INFO(info_message,pw->getName(),pw->getPosition(),p->getPosition());
             //writing the info message to the file
                ofstream out("Info.txt",ios::app);
                if(!out){
                    cout<<"Error opening file"<<endl;
                    return false;
                }
                //outing time also to the file
                time_t currentTime = time(0); // Get current time
                char* dateTime = ctime(&currentTime); // Convert to string
                out<<info->getSender()<<"|"<<info->getSendersPosition()<<"|"<<info->getReceiver()<<"|"<<info->getMessage()<<"|"<<info->getIsRead()<<"|"<< dateTime<< endl;    
                out.close();
                cout<<"Information sent successfully!"<<endl;
             return true;
         }
         else{
             cout<<"You do not have permission to send information to the following workers"<<endl;
             return false;
         }
    }


    bool can_send_alert(PaidWorkers *p){
        PolicyEngine pe(p);
        if(pe.accessLevel <= accessLevel){
             cout<<"\nYou have permission to send alert to "<<p->getPosition()<<endl;

             cout<<"\nEnter the Alert: ";
                string alert_message;
                getline(cin, alert_message);
             ALERT* alert=new ALERT(alert_message,pw->getName(),p->getName());
             //writing the info message to the file
                ofstream out("Alert.txt",ios::app);
                if(!out){
                    cout<<"Error opening file"<<endl;
                    return false;
                }
                //outing time also to the file
                time_t currentTime = time(0); // Get current time
                char* dateTime = ctime(&currentTime); // Convert to string
                out<<alert->getSender()<<"|"<<pw->getPosition()<<"|"<<alert->getReceiver()<<"|"<<alert->getMessage()<<"|"<<alert->getIsRead()<<"|"<< dateTime;    
                out.close();
                cout<<"Alert sent successfully!"<<endl;
             return true;
         }
         else{
             cout<<"You do not have permission to send alert to the following workers"<<endl;

             return false;
         }
    }
};


class Authentication : public ActivityLog{
    protected:
        //these data members are only for reading user.txt, so the class paidworkers get isolated from authentication function
        //user.txt is only read and write by authentication class and noting else
        int usercount;
        int attempts;
        PaidWorkers* users;
        int OTP;
        long long otptime;
        
        public:
        Authentication(){
            usercount = 0;
            users = NULL;
            OTP = 0;
            attempts = 0;
            otptime = 0;
        }
        
        string hashedPassword(string& password)
        {
            string hashed;
            for(int i = 0; i < password.length(); i++)
            {
                char original = password[i];
                int convert = (original * (i + 1) + 31) % 94 + 33;      //keep it under the range of printable charachters
                if(convert == 124)
                {
                    convert = 125; //when hashing fall on | it will assign charchter next to | which is {
                }

                hashed += static_cast<char>(convert); //type cast the int type assci value to the actual charachter and add to the string 
            }
            return hashed;
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
                attempts++;
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
        
        bool OTP_TIME()
        {
            ifstream in("./OTP.txt");
            int inOTP;
            long long inTime;   //  to store the int form of current time
            in >> inOTP;
            in.ignore(1);
            in >> inTime;
            in.close();

            // if more than 15 seconds have passed, expire it
            return (difftime(time(0), inTime) <= 30.0);   //using a difftime() function from the predefined ctime library
        }
        
        void otpGenerator()
        {
            srand(time(0));
            OTP = 100000 + rand() % 900000;
            otptime = time(0);

            ofstream out;
            out.open("./OTP.txt", ios::out);
            if(!out)
            {
                cout<<endl<<endl
                    <<"Error opening OTP file"<<endl<<endl;
                mainMenu();
            }

            out<< OTP << "|" << otptime << endl;
            out.close();
        }


        PaidWorkers& login(string pos)  //string to check position
        {
            bool islogin = false;
            attempts = 0;
            string iname, ipassword;    //input name and input password
            cout<<"Enter your Username: ";
            cin>>iname;
            int index = userExists(iname, pos);
            if(index != -1)
            {
                while(attempts <= 3)
                {
                    if(attempts > 3)
                    {
                        ActivityLog logging(getCurrentTime() + ", " + users[index].getName() + " Logged in Failed (Too many attempts)! " +  " |3\n");
                        fstream writelog;
                        writelog.open("./ActivityLog.txt", ios::app);
                        writelog << logging;
                        writelog.close();
                        cout<<endl<<endl;
                        cout<<"Too Many Attempts Please Try Again Later!"<<endl<<endl;
                        users[index].setLogin(false);
                        return users[index];
                    }
                    cout<<"Password: ";
                    cin>>ipassword;
                    ipassword = hashedPassword(ipassword);
                    if(users[index].getPassword() == ipassword)
                    {
                        otpGenerator();
                        int otp = 0;
                        cout<<"Enter OTP: ";
                        cin>>otp;
                        if(!OTP_TIME())
                        {
                            ActivityLog logging(getCurrentTime() + ", " + users[index].getName() + " Failed Login Attempt (OTP EXPIRED)! " +  " |0\n");
                            fstream writelog;
                            writelog.open("./ActivityLog.txt", ios::app);
                            writelog << logging;
                            writelog.close();
                            cout<<endl<<endl;
                            cout<<"OTP Expired!"<<endl<<endl;
                            cout<<"Please Try Again Later!"<<endl<<endl;
                            users[index].setLogin(false);
                            break;
                        }
                        if(otp == OTP)
                        {
                            ActivityLog logging(getCurrentTime() + ", " + users[index].getName() + " Logged in Successfully! " +  " |0\n");
                            fstream writelog;
                            writelog.open("./ActivityLog.txt", ios::app);
                            writelog << logging;
                            writelog.close();
                            cout<<endl<<endl;
                            cout<<"Login Successful!"<<endl<<endl;
                            users[index].setLogin(true);
                            remove("./OTP.txt");
                            break;
                        }
                        else
                        {
                            ActivityLog logging(getCurrentTime() + ", " + users[index].getName() + " Failed Login Attempt (Wrong OTP)! " +  " |1\n");
                            fstream writelog;
                            writelog.open("./ActivityLog.txt", ios::app);
                            writelog << logging;
                            writelog.close();
                            cout<<endl<<endl;
                            cout<<"Wrong OTP!"<<endl<<endl;
                            cout<<"Please Try Again Later!"<<endl<<endl;
                            users[index].setLogin(false);
                            remove("./OTP.txt");
                            break;
                        }
                    }
                    else
                    {
                        ActivityLog logging(getCurrentTime() + ", " + users[index].getName() + " Logged in Failed! () " +  " |2\n");
                        fstream writelog;
                        writelog.open("./ActivityLog.txt", ios::app);
                        writelog << logging;
                        writelog.close();
                        cout<<endl<<endl;
                        cout<<"Invalid Password!"<<endl<<endl;
                        cout<<"Please Try Again!"<<endl<<endl;
                        attempts++;
                        cout<<"Attempts: "<<attempts<<endl;
                    }
                }
                cout<<"End of loop"<<endl;
            }
            else
            {
                cout<<endl<<endl;
                cout<<"Invalid Username!"<<endl<<endl;
                cout<<"Please Try Again!"<<endl<<endl;
                mainMenu();
            }

            // PaidWorkers* usertoreturn;
            // if(pos == "Executive")
            // {
            //     usertoreturn = new Executive(users[index]);
            // }
            // else if(pos == "Director")
            // {
            //     usertoreturn = new Director(users[index]);
            // }
            // else if(pos == "Manager")
            // {
            //     usertoreturn = new Manager(users[index]);
            // }
            // else if(pos == "Employee")
            // {
            //     usertoreturn = new Employee(users[index]);
            // }
            // else if(pos == "Junior")
            // {
            //     usertoreturn = &users[index];
            // } 
            return users[index];
        }
        ~Authentication()
        {
            if(users != NULL)
            {
                delete[] users;
                users = NULL;
            }
        }
};

void ExecutiveMenu(PaidWorkers* user);
void DirectorMenu(PaidWorkers* user);
void ManagerMenu(PaidWorkers* user);
void EmployeeMenu(PaidWorkers* user);
void JuniorMenu(PaidWorkers* user);

void show_Message_menu(PaidWorkers * pw);
void readingInfoFile(PaidWorkers* pw);





//-----------------------------------Code Execution start from here--------------------------------


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
            PaidWorkers* pw = &auth.login("Executive");
            cout<<"insidemain"<<endl;
            if(pw->getLogin() == true)
            {
                ExecutiveMenu(pw);
            }
            else
            {
                mainMenu();
            }
            break;
        }
        case 2:
        {
            Authentication auth;
            PaidWorkers* pw = &auth.login("Director");
            if(pw->getLogin() == true)
            {
                DirectorMenu(pw);
            }
            break;
        }
        case 3:
        {
            Authentication auth;
            PaidWorkers* pw = &auth.login("Manager");
            if(pw->getLogin() == true)
            {
                ManagerMenu(pw);
            }
            break;
        }
        case 4:
        {
            Authentication auth;
            PaidWorkers* pw = &auth.login("Employee");
            if(pw->getLogin() == true)
            {
                EmployeeMenu(pw);
            }
            break;
        }
        case 5:
        {
            Authentication auth;
            PaidWorkers* pw = &auth.login("Junior");
            if(pw->getLogin() == true)
            {
                JuniorMenu(pw);
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


void ExecutiveMenu(PaidWorkers* pw)
{
    int choice1 = 0;
    cout<<endl<<endl<<endl;
    cout<<"                              #===========================================#"<<endl
    <<"                              #          Executive Menu                   #"<<endl
    <<"                              #===========================================#"<<endl
    <<"                              #          Press 1 to View Messages        #"<<endl
    <<"                              #          Press 2 to View My Tasks         #"<<endl
    <<"                              #          Press 3 to Add New Task          #"<<endl
    <<"                              #          Press 3 to Add New               #"<<endl
    <<"                              #          Press 3 to Add New Task          #"<<endl
    <<"                              #          Press 4 to Exit                  #"<<endl
    <<"                              #===========================================#"<<endl<<endl<<endl;

    cout<<"Press your option to continue: ";
    cin>>choice1;
    switch(choice1)
    {
        case 1:
        {   
            show_Message_menu(pw);
            break;
        }
        case 2:
        {

            break;
        }
        case 3:
        {

            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            cout<<"Invalid Option"<<endl<<endl<<endl;
            ExecutiveMenu(pw);
        }
    }
}


void DirectorMenu(PaidWorkers* pw)
{
    PolicyEngine pe(pw);
    int choice1 = 0;
    cout<<endl<<endl<<endl;
    cout<<"                              #===========================================#"<<endl
    <<"                              #          Director Menu                    #"<<endl
    <<"                              #===========================================#"<<endl
    <<"                              #          Press 1 to see messages          #"<<endl
    <<"                              #          Press 2 to View My Tasks         #"<<endl
    <<"                              #          Press 3 to Add New Task          #"<<endl
    <<"                              #          Press 4 to Send Message          #"<<endl
    <<"                              #          Press 5 to Exit                  #"<<endl
    <<"                              #===========================================#"<<endl<<endl<<endl;

    cout<<"Press your option to continue: ";
    cin>>choice1;
    switch(choice1)
    {
        case 1:
        {
            show_Message_menu(pw);
            
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            cout<<"Invalid Option"<<endl<<endl<<endl;
            DirectorMenu(pw);
        }
    }
}


void ManagerMenu(PaidWorkers* pw){
    PolicyEngine pe(pw);
    int choice1 = 0;
    cout<<endl<<endl<<endl;
    cout<<"                              #===========================================#"<<endl
    <<"                              #          Manager Menu                     #"<<endl
    <<"                              #===========================================#"<<endl
    <<"                              #          Press 1 to View All Tasks        #"<<endl
    <<"                              #          Press 2 to View My Tasks         #"<<endl
    <<"                              #          Press 3 to Add New Task          #"<<endl
    <<"                              #          Press 4 to Exit                  #"<<endl
    <<"                              #===========================================#"<<endl<<endl<<endl;

    cout<<"Press your option to continue: ";
    cin>>choice1;
    switch(choice1)
    {
        case 1:
        {
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            cout<<"Invalid Option"<<endl<<endl<<endl;
            ManagerMenu(pw);
        }
    }
}


void EmployeeMenu(PaidWorkers* pw)
{
    PolicyEngine pe(pw);
    int choice1 = 0;
    cout<<endl<<endl<<endl;
    cout<<"                              #===========================================#"<<endl
    <<"                              #          Employee Menu                    #"<<endl
    <<"                              #===========================================#"<<endl
    <<"                              #          Press 1 to open Message menu     #"<<endl
    <<"                              #          Press 1 to View All Tasks        #"<<endl
    <<"                              #          Press 2 to View My Tasks         #"<<endl
    <<"                              #          Press 3 to Add New Task          #"<<endl
    <<"                              #          Press 4 to Exit                  #"<<endl
    <<"                              #===========================================#"<<endl<<endl<<endl;

    cout<<"Press your option to continue: ";
    cin>>choice1;
    switch(choice1)
    {
        case 1:
        {
            show_Message_menu(pw);
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            cout<<"Invalid Option"<<endl<<endl<<endl;
            EmployeeMenu(pw);
        }
    }
}


void JuniorMenu(PaidWorkers* pw)
{
    PolicyEngine pe(pw);
    int choice1 = 0;
    cout<<endl<<endl<<endl;
    cout<<"                              #===========================================#"<<endl
    <<"                              #          Junior Menu                      #"<<endl
    <<"                              #===========================================#"<<endl
    <<"                              #          Press 1 to View All Tasks        #"<<endl
    <<"                              #          Press 2 to View My Tasks         #"<<endl
    <<"                              #          Press 3 to Add New Task          #"<<endl
    <<"                              #          Press 4 to Exit                  #"<<endl
    <<"                              #===========================================#"<<endl<<endl<<endl;

    cout<<"Press your option to continue: ";
    cin>>choice1;
    switch(choice1)
    {
        case 1:
        {
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            cout<<"Invalid Option"<<endl<<endl<<endl;
            JuniorMenu(pw);
        }
    }
}


void show_Message_menu(PaidWorkers * pw)
{
    cout<<endl<<endl<<endl;
    cout
    <<"                              #===============================================#"<<endl
    <<"                              #               Message Menu                    #"<<endl
    <<"                              #===============================================#"<<endl
    <<"                              #          Press 1 to send INFO                 #"<<endl
    <<"                              #          Press 2 to send a private message    #"<<endl
    <<"                              #          Press 3 to send an Alert             #"<<endl
    <<"                              #          Press 4 to view Info                 #"<<endl
    <<"                              #          Press 5 to view private Message      #"<<endl
    <<"                              #          Press 6 to view alerts               #"<<endl
    <<"                              #          Press 6 to Exit                      #"<<endl
    <<"                              #===============================================#"<<endl<<endl<<endl;

    int choice1;
    cout<<"Press your option to continue: ";
    cin>>choice1;
    switch(choice1)
    {
        case 1:
        {
            PolicyEngine pe(pw);
            cout<<"Which class of pleople you want to send message to?"<<endl
                <<"Press 1 for Junior"<<endl
                <<"Press 2 for Employee"<<endl
                <<"Press 3 for Manager"<<endl
                <<"Press 4 for Director"<<endl
                <<"Press 5 for Executive"<<endl;
            int choice2;
            cout<<"Press your option to continue: ";
            cin>>choice2;
            PaidWorkers* p = NULL;
            if(choice2 == 1)
            {
                cout<<"Sending message to Junior"<<endl;
                p = new Junior;

            }
            else if(choice2 == 2)
            {
                cout<<"Sending message to Employee"<<endl;
                p = new Employee;
            }
            else if(choice2 == 3)
            {
                cout<<"Sending message to Manager"<<endl;
                p = new Manager;
            }
            else if(choice2 == 4)
            {
                cout<<"Sending message to Director"<<endl;
                p = new Director;
            }
            else if(choice2 == 5)
            {
                cout<<"Sending message to Executive"<<endl;
                p = new Executive;
            }
            else
            {
                cout<<"Invalid Option"<<endl<<endl<<endl;
                show_Message_menu(pw);
            }

            if(pe.can_send_info(p) == true)
            {
                cout<<"Message Sent Successfully!"<<endl;
            }
            else
            {
                cout<<"Message Sending Failed!"<<endl;
            }
            
            break;
        }
        case 2:
        {
            //sending private message
            cout<<"Sending private message"<<endl;
            cout<<"Enter the position of the person you want to send message to"<<endl
                <<"Press 1 for Junior"<<endl
                <<"Press 2 for Employee"<<endl
                <<"Press 3 for Manager"<<endl
                <<"Press 4 for Director"<<endl
                <<"Press 5 for Executive"<<endl;
            int choice2;
            cout<<"Press your option to continue: ";
            cin>>choice2;
            PaidWorkers* p = NULL;
            if(choice2 == 1)
            {
                cout<<"Sending message to Junior"<<endl;
                p = new Junior;

            }
            else if(choice2 == 2)
            {
                cout<<"Sending message to Employee"<<endl;
                p = new Employee;
            }
            else if(choice2 == 3)
            {
                cout<<"Sending message to Manager"<<endl;
                p = new Manager;
            }
            else if(choice2 == 4)
            {
                cout<<"Sending message to Director"<<endl;
                p = new Director;
            }
            else if(choice2 == 5)
            {
                cout<<"Sending message to Executive"<<endl;
                p = new Executive;
            }
            else
            {
                cout<<"Invalid Option"<<endl<<endl<<endl;
                show_Message_menu(pw);
            }
            cout<<"Enter the name of the person you want to send message to: "<<endl;
            string name;
            cin.ignore(); // clear the newline character from the input buffer
            getline(cin, name); // read the entire line including spaces
            //opening the file to check if the person exists or not
            //finding the person in the file
            ifstream in;
            in.open("./"+p->getPosition()+".txt", ios::in);
            if(!in)
            {
                cout<<endl<<endl
                    <<"Error opening file"<<endl<<endl;
                mainMenu();
            }
            
            //1254|mannan|Manager|qF{T|1000|15

            int id, salary, points;
            string file_name, position, password;

            bool found = false;
            while ( in>>id)
            {
                //1234|moiz|Executive|1234|1000|23
                in.ignore(1);
                getline(in, file_name, '|');
                getline(in, position, '|');
                getline(in, password, '|');
                in>>salary;
                in.ignore(1);
                in>>points;
                in.ignore(1);

                if(file_name == name)
                {
                    found = true;
                    p->setID(id);
                    p->setPosition(position);
                    p->setName(file_name);
                    p->setPassword(password);
                    p->setSalary(salary);
                    break;
                }
            }
            in.close();
            if(found == false)
            {
                cout << "\n\nUser not found\n\n";
                show_Message_menu(pw);
                break;
            }


            
            cout<<"Enter the message you want to send: "<<endl;
            string message;; // clear the newline character from the input buffer
            getline(cin, message); // read the entire line including spaces
            //PRIVATE(const string& m, const string& s, const string& r, int id)
            cout<<"\nmessage: "<<message<<endl;
            PRIVATE *pmsg = new PRIVATE(message, pw->getName(), p->getName(), p->getID());
            pmsg->saveToFile();  // ADD THIS LINE
            cout << "Private message sent successfully!\n";
            delete pmsg;  // Clean up
            break;
        }
        case 3:
        {
            //sending alert
            cout<<"Sending alert"<<endl;
            cout<<"Enter the position of the person you want to send message to"<<endl
                <<"Press 1 for Junior"<<endl
                <<"Press 2 for Employee"<<endl
                <<"Press 3 for Manager"<<endl
                <<"Press 4 for Director"<<endl
                <<"Press 5 for Executive"<<endl;
            int choice2;
            cout<<"Press your option to continue: ";
            cin>>choice2;
            PaidWorkers* p = NULL;
            if(choice2 == 1)
            {
                cout<<"Sending message to Junior"<<endl;
                p = new Junior;

            }
            else if(choice2 == 2)
            {
                cout<<"Sending message to Employee"<<endl;
                p = new Employee;
            }
            else if(choice2 == 3)
            {
                cout<<"Sending message to Manager"<<endl;
                p = new Manager;
            }
            else if(choice2 == 4)
            {
                cout<<"Sending message to Director"<<endl;
                p = new Director;
            }
            else if(choice2 == 5)
            {
                cout<<"Sending message to Executive"<<endl;
                p = new Executive;
            }
            else
            {
                cout<<"Invalid Option"<<endl<<endl<<endl;
                show_Message_menu(pw);
            }
            cout<<"Enter the name of the person you want to send message to: "<<endl;
            string name;
            cin.ignore(); // clear the newline character from the input buffer
            getline(cin, name); // read the entire line including spaces
            //opening the file to check if the person exists or not
            //finding the person in the file
            ifstream in;
            in.open("./"+p->getPosition()+".txt", ios::in);
            if(!in)
            {
                cout<<endl<<endl
                    <<"Error opening file"<<endl<<endl;
                mainMenu();
            }
            
            //1254|mannan|Manager|qF{T|1000|15

            int id, salary, points;
            string file_name, position, password;

            bool found = false;
            while ( in>>id)
            {
                //1234|moiz|Executive|1234|1000|23
                in.ignore(1);
                getline(in, file_name, '|');
                getline(in, position, '|');
                getline(in, password, '|');
                in>>salary;
                in.ignore(1);
                in>>points;
                in.ignore(1);

                if(file_name == name)
                {
                    found = true;
                    p->setID(id);
                    p->setPosition(position);
                    p->setName(file_name);
                    p->setPassword(password);
                    p->setSalary(salary);
                    break;
                }
            }
            in.close();
            if(found == false)
            {
                cout << "\n\nUser not found\n\n";
                break;
            }


            PolicyEngine pe(pw);
            if(pe.can_send_alert(p) == true)
            {
                cout<<"Message Sent Successfully!"<<endl;
            }
            else
            {
                cout<<"Message Sending Failed!"<<endl;
            }


        }
        case 4:
        {
            //viewing info messages
            cout<<"Viewing info messages"<<endl;
            readingInfoFile(pw);

            break;
        }
        case 5:
        {
            
            //viewing private messages
            cout<<"Viewing private messages"<<endl;
            cout<<"Checking for messages"<<endl;
            ifstream in;
            in.open("private_messages.txt", ios::in);
            if(!in)
            {
                cout<<endl<<endl
                    <<"Error opening file"<<endl<<endl;
                mainMenu();
            }
            

            //Sannan|mannan|1254|gu fcffa

            string sender, receiver, message;
            int id;


            bool found = false;
            while (getline(in, sender, '|'))
            {
                getline(in, receiver, '|');
                in>>id;
                in.ignore(1);
                getline(in, message, '\n');
                if(receiver == pw->getName())
                {
                    //decoding the message
                    
                    

                    found = true;
                    cout << "-----------------------------\n"
                         << "Sender:             " << sender          << "\n"
                         << "Receiver:           " << receiver        << "\n"
                         << "Encrypted Message:  " << message         << "\n";
                        decryptInteractive(message, id);
                }
            }
            in.close();

            if(found == false)
            {
                cout << "\n\nNo messages found for " << pw->getName() << "\n";
                show_Message_menu(pw);
            }
               


            break;
        }
        case 6:
        {
            // … inside your “view alerts” case …

        cout << "Viewing alerts\n";

            // 1) Open original for reading, temp for writing
            ifstream  in ("Alert.txt", ios::in);
            ofstream  out("Alert.tmp", ios::out);
            if (!in || !out)
            {
                cout << "\nError opening file\n\n";
                // make sure to clean up if necessary
                return;
            }

        string sender, sendersPosition, receiver, message, isRead, dateTime;
        bool   foundAny = false;

// 2) Read each record
            while (   getline(in, sender,        '|')
            && getline(in, sendersPosition,'|')
            && getline(in, receiver,       '|')
            && getline(in, message,        '|')
            && getline(in, isRead,         '|')
            && getline(in, dateTime))           // up to end-of-line
            {
    // strip CR if present
            if (!dateTime.empty() && dateTime.back() == '\r')
            {
                dateTime.pop_back();
            }

    // 3) If this alert is for me, display it and mark it read
            if (receiver == pw->getName() && isRead == "0")
            {

                // display the alert
                cout << "\n\n-----------------------------\n"
                     << "Sender:       " << sender          << "\n"
                     << "Position:     " << sendersPosition << "\n"
                     << "Message:      " << message         << "\n"
                     << "Date & Time:  " << dateTime        << "\n\n";

                // flip the flag
                isRead = "1";
            }
            else if (receiver == pw->getName() && isRead == "1")
            {
                foundAny = true;
                cout << "-----------------------------\n"
                << "Sender:       " << sender          << "\n"
                << "Position:     " << sendersPosition << "\n"
                << "Message:      " << message         << "\n"
                << "Date & Time:  " << dateTime        << "\n\n";

                // flip the flag
                isRead = "1";
            }

            // 4) Write the (possibly updated) record to temp
            out << sender          << '|'
            << sendersPosition << '|'
            << receiver        << '|'
            << message         << '|'
            << isRead          << '|'
            << dateTime        << "\n";
        }

        in.close();
        out.close();

        // 5) Replace original with temp
        if (remove("Alert.txt") != 0)
        {
            cout << "Error deleting original alerts file\n";
        }
        else if (rename("Alert.tmp", "Alert.txt") != 0)
        {
            cout << "Error renaming temp file\n";
        }

        if (!foundAny)
        {
            cout << "\nNo alerts found for " << pw->getName() << "\n";
        }

            break;
        }
        default:
        {
            cout<<"Invalid Option"<<endl<<endl<<endl;
            show_Message_menu(pw);
        }
    }
}

void readingInfoFile(PaidWorkers* pw)
{
    ifstream in("Info.txt");
    if (!in) {
        cout << "Error opening Info.txt\n";
        mainMenu();
        return;
    }

    // temp variables
    string sender,
           sendersPosition,
           receiver,
           message,
           isRead,
           dateTime;

    bool foundAny = false;

    // keep looping as long as we can read ALL six parts
    while (   getline(in, sender,        '|')
           && getline(in, sendersPosition,'|')
           && getline(in, receiver,       '|')
           && getline(in, message,        '|')
           && getline(in, isRead,         '|')
           && getline(in, dateTime)  // up to EOL
          )
    {
        // strip any stray '\r' (if your file has Windows CRLF)
        if (!receiver.empty() && receiver.back() == '\r')
            receiver.pop_back();

        if (receiver == pw->getPosition()) {
            foundAny = true;
            cout << "-----------------------------\n"
                 << "Sender:          " << sender          << "\n"
                 << "Position:        " << sendersPosition << "\n"
                 << "Message for:     " << receiver        << "\n"
                 << "Message:         " << message         << "\n"
                 << "Date & Time:     " << dateTime        << "\n";
        }
    }

    if (!foundAny) {
        cout << "\nNo messages found for " << pw->getName() << "\n";
    }
}

