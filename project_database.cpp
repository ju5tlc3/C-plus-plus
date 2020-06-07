//Operating with DataBase by the next commands: Add, Del, Find and Print 
//Check for entering illegal date performed

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<exception>

class Date {
public:
    Date(int new_year, int new_month, int new_day)
    {
        year = new_year;
        month = new_month;
        day = new_day;
    }
  int GetYear() const
  {
      return year;
  }
  int GetMonth() const
  {
      return month;
  }
  int GetDay() const
  {
      return day;
  }
private:
    int year;
    int month;
    int day;
};


//Operator of '<' for sorting by date in map
bool operator<(const Date& lhs, const Date& rhs)
{
    if (lhs.GetYear() == rhs.GetYear())
    {
        if (lhs.GetMonth() == rhs.GetMonth())
        {
            if (lhs.GetDay() < rhs.GetDay())
            {
                return true;
            }
        }
        else if (lhs.GetMonth() < rhs.GetMonth())
        {
            return true;
        }
    }
    else if (lhs.GetYear() < rhs.GetYear())
    {
        return true;
    }
    return false;
}

class Database {
public:
  void AddEvent(const Date& date, const std::string& event)
  {
      //Add event with a particular day to a db
      events[date].insert(event);
  }
  bool DeleteEvent(const Date& date, const std::string& event)
  {
      //Check if a day exists in a db
      if (events.count(date) > 0)
      {
          //Delete an event from a particular day
          if (events[date].count(event) > 0)
          {
              events[date].erase(event);
              //If a day has no events more, delete it also
              if (events[date].empty())
              {
                  events.erase(date);
              }
              return true;
          }
      }
      return false;
  }
  int  DeleteDate(const Date& date)
  {
      //Delete all events in a day and day from a db also
      int count = events[date].size();
      events.erase(date);
      return count;
  }

  void Find(const Date& date) const
  {
      //Find all events by a particular date and print it by one on a string
      if (events.count(date) > 0)
      {
          for (auto& str : events.at(date))
          {
              std::cout << str << std::endl;
          }
      }
  }
  
  void Print() const 
  {
      //Print db in next format -> date event; by one pair on a string
      for (auto& date : events)
      {
          for (auto& str : date.second)
          {
                std::cout << std::setw(4) << std::setfill('0') << date.first.GetYear();
                std::cout << '-';
                std::cout << std::setw(2) << std::setfill('0') << date.first.GetMonth();
                std::cout << '-';
                std::cout << std::setw(2) << std::setfill('0') << date.first.GetDay();
                std::cout << ' ' << str;
                std::cout << std::endl;
          }
      }
  }
private: 
    //Map was created for sorting by date, set for sorting string and deleting duplicates
    std::map<Date, std::set<std::string>> events;
};

int main() {
  Database db;
  std::string add = "Add", del = "Del", find = "Find", print = "Print"; //Commands for operating with a DB sample
  std::string command;
  std::vector<std::string> date; //container for year,month,day
  while (std::getline(std::cin, command)) {
      if (command.empty())
      {
          continue;
      }
      //Check if a command is valid
      if (command.substr(0, 3) == add && command[3] == ' ' || command.substr(0, 3) == del && command[3] == ' ' || command.substr(0, 4) == find && command[4] == ' ' || command.substr(0, 5) == print)
      {
          if (command.substr(0, 5) == print) 
          {
              //Print all db
              db.Print();
          }
          else
          {
              //Parse date
              int start_date = command.find(' ');
              start_date++;
              date.clear();
              int index = start_date;
              //Looping until an illegal symbol will be entered or the end of date expression
              while ((isdigit(command[index]) || command[index] == '-' || command[index] == '+') && command[index] != ' ' && index != command.length()) 
              {
                  //Check for delimiters and push a value to date vector
                  if (isdigit(command[index]) && command[index + 1] == '-' || isdigit(command[index]) && command[index + 1] == ' ' || isdigit(command[index]) &&  index == command.length() - 1)
                  {
                      std::string temp = command.substr(start_date, index - start_date + 1);
                      //If two '-' together, that is an error
                      if (temp[0] == '-' && temp[1] == '-')
                      {
                          break;
                      }
                      date.push_back(temp);
                      start_date = index + 2;
                  }
                  index++;
              }
              if (date.size() < 3) //If a date vector was not filled at whole
              {
                  start_date = command.find(' ');
                  start_date++;
                  int index = command.find(' ', start_date);
                  std::cout << "Wrong date format: " << command.substr(start_date, index - start_date) << std::endl;
              }
              else
              {
                  //Parse month and day
                  int month, day;
                  try 
                  {
                      month = std::stoi(date[1]);
                      day = std::stoi(date[2]);
                  }
                  catch(std::exception& ex)
                  {
                      //
                      std::cout << ex.what() << std::endl;
                  }
                  if (month == 0 || month > 12 || date[1][0] == '-')
                  {
                      std::cout << "Month value is invalid: " << date[1] << std::endl;
                  }
                  else if (day == 0 || day > 31 || date[2][0] == '-')
                  {
                      std::cout << "Day value is invalid: " << date[2] << std::endl;;
                  }
                  else  //If no errors, step further 
                  {
                     int year = std::stoi(date[0]);
                     Date date(year, month, day); //Create Date object
                     if (command.substr(0, 4) == find)
                     {
                         //Find events by date
                         db.Find(date);
                     }
                     else
                     {
                         if (start_date - 1 == command.length())
                         {
                             //Delete all events in a particular day
                             std::cout << "Deleted " << db.DeleteDate(date) << " events" << std::endl;
                         }
                         else
                         {
                             std::string event = command.substr(start_date, command.length() - start_date + 1);
                             if (command.substr(0, 3) == add)
                             {
                                 //Add event to db
                                 db.AddEvent(date, event);

                             }
                             else
                             {
                                 //Delete a particular event in a particular day
                                 if (db.DeleteEvent(date, event))
                                 {
                                     std::cout << "Deleted successfully" << std::endl;
                                 }
                                 else
                                 {
                                     std::cout << "Event not found" << std::endl;
                                 }
                             }
                         }
                     }
                  }
              }
          }
      }
      else
      {
      //Was entered an unknown command
          int start_date = command.find(' ');
          std::cout << "Unknown command: " << command.substr(0, start_date) << std::endl;
      }
  }
  return 0;
}
