#include<iostream>
using namespace std;

class Time{
    int hours,minutes,seconds;
    public:
        Time(){
            hours = 0;
            minutes = 0;
            seconds = 0;
        }
        
        Time(int h, int m, int s){
            hours = h;
            minutes = m;
            seconds = s;
        }
        
        int getHours(){
            return hours;
        }
        
        int getMinutes(){
            return minutes;
        }
        
        int getSeconds(){
            return seconds;
        }
        
        Time operator ++ (){
            //Add code here to overload the prefix increment operator
            ++seconds;
            
            if(seconds>=60){
                ++minutes;
                seconds-=60;
                if(minutes>=60){
                    ++hours;
                    minutes-=60;
                    if(hours>=24){
                        hours = 0;
                    }
                }
            }
            return Time(hours, minutes,seconds);
        }
        
        
        Time operator++( int ) {
            // save the orignal value
            Time T(hours, minutes,seconds);
             
            // increment this object
            ++seconds;
        
            if(seconds>=60){
                ++minutes;
                seconds-=60;
                if(minutes>=60){
                    ++hours;
                    minutes-=60;
                    if(hours>=24){
                        hours = 0;
                    }
                }
            }
             
            // return old original value
            return T; 
        }
        
        void getTime(){
            //Display time with hours,minutes and seconds separated by colon
            cout<< hours << ":" << minutes << ":" << seconds << endl;
        }
        
        void getTime(int s){
            //Increment seconds by s and display time
            //Make sure to take care of the case where seconds may exceed 59
            seconds += s;
            minutes = minutes + seconds/60;
            seconds = seconds%60;
            hours = hours + minutes/60;
            minutes = minutes%60;
            hours = hours%24;

            cout<< hours << ":" << minutes << ":" << seconds << endl;
        }
        
        void getTime(bool s){
            //If true, print total number of seconds(refer to the problem statement)
            if(s)
              cout << hours*3600 + minutes*60 + seconds << endl;
            //else display time with hours,minutes and seconds separated by colon
            else
              cout<< hours << ":" << minutes << ":" << seconds << endl;
        }
        
};

Time operator+(int s, Time& right){
    int seconds = s + right.getSeconds(), minutes = right.getMinutes(), hours = right.getHours();

    minutes = minutes + seconds/60;
    seconds = seconds%60;
    hours = hours + minutes/60;
    minutes = minutes%60;
    hours = hours%24;
    Time result(hours, minutes, seconds);
    return result;
}

//Do not edit this function
void checkTime(Time t){
    cout<<"checking time-"<<t.getHours()<<":"<<t.getMinutes()<<":"<<t.getSeconds()<<endl;    
}

int main(){
    
    //DO NOT EDIT the part below this line, you need to add code above only
    int h,m,s,add;
    cin>>h>>m>>s>>add;
    
    Time t(h,m,s);
    
    t.getTime(true);
    checkTime(++t);
    t.getTime();
    checkTime(t++);
    t.getTime(false);
    t.getTime(add);
    
    Time new_t = add + t;
    
    cout<<"new time-";
    new_t.getTime();
    
}
