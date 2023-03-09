#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Date
{
public:
    int day;
    int month;
    int year;

    Date(int day, int month, int year) : day(day), month(month), year(year) {}
    void changeDate(int newDay, int newMonth, int newYear)
    {
        day = newDay;
        month = newMonth;
        year = newYear;
    }
    void prettyPrint() const
    {
        cout << day << "." << month << "." << year;
    }
};

class Event
{
public:
    Date date;
    int duration;
    string description;

    Event(Date date, int duration, string description) : date(date), duration(duration), description(description) {}
    void displayInfo() const
    {
        cout << "Event: " << description << endl;
        cout << "Date: ";
        date.prettyPrint();
        cout << endl
             << "Duration: " << duration << " hours" << endl;
    }
    void changeDate(Date newDate)
    {
        date = newDate;
    }
    void changeDuration(int newDuration)
    {
        duration = newDuration;
    }
    const string &getDescription() const
    {
        return description;
    }
};

class Calendar
{
private:
    vector<Event *> events;

public:
    Calendar() {}
    ~Calendar()
    {
        for (auto event : events)
        {
            delete event;
        }
    }
    void addEvent(Event *event)
    {
        int totalDuration = 0;
        for (auto e : events)
        {
            if (e->getDescription() == event->getDescription())
            {
                cout << "Event with the same description already exists" << endl;
                return;
            }
            totalDuration += e->duration;
        }
        if (totalDuration + event->duration > 8)
        {
            cout << "Total duration of events on this date exceeds 8 hours" << endl;
            return;
        }
        events.push_back(event);
    }
    void changeEventDate(string description, Date newDate)
    {
        for (auto e : events)
        {
            if (e->getDescription() == description)
            {
                e->changeDate(newDate);
            }
        }
    }
    void changeEventDuration(string description, int newDuration)
    {
        for (auto e : events)
        {
            if (e->getDescription() == description)
            {
                e->changeDuration(newDuration);
            }
        }
    }
    void sortEventsByDate()
    {
        sort(events.begin(), events.end(), [](Event *e1, Event *e2)
             {
            if (e1->date.year != e2->date.year) {
            return e1->date.year < e2->date.year;
        } else if (e1->date.month != e2->date.month) {
            return e1->date.month < e2->date.month;
        } else {
            return e1->date.day < e2->date.day;
        } });
    }
    void printCalendar() const
    {
        for (auto e : events)
        {
            e->displayInfo();
            cout << endl;
        }
    }
};

int main()
{
   
    Date date1(9, 3, 2023);
    Date date2(10, 3, 2023);
    Date date3(11, 3, 2023);

    Event event1(date1, 3, "Meeting with John");
    Event event2(date2, 2, "Lunch with Kate");
    Event event3(date3, 4, "Workshop");

   
    Calendar calendar;
    calendar.addEvent(new Event(date1, 3, "Meeting with John"));
    calendar.addEvent(new Event(date2, 2, "Lunch with Kate"));
    calendar.addEvent(new Event(date3, 4, "Workshop"));

  
    cout << "Calendar:" << endl;
    calendar.printCalendar();

   
    calendar.changeEventDate("Meeting with John", Date(10, 3, 2023));
    calendar.changeEventDuration("Lunch with Kate", 1);

    
    calendar.sortEventsByDate();

  
    cout << "Updated calendar:" << endl;
    calendar.printCalendar();

    return 0;
}