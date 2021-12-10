/* Constructors */
package OOPLab.constructors;

class Time {
    /* Data members*/
    private final int hours, minutes, seconds;

    /* Constructor initializing to 0 */
    public Time() {
        this.hours = 0;
        this.minutes = 0;
        this.seconds = 0;
    }

    /* Constructor initializing to fixed values */
    public Time(int hours, int minutes, int seconds) {
        this.hours = hours;
        this.minutes = minutes;
        this.seconds = seconds;
    }

    /* Copy constructor */
    public Time(Time time) {
        this.hours = time.hours;
        this.minutes = time.minutes;
        this.seconds = time.seconds;
    }

    /* Member functions to get data members */
    public int getHrs() { return this.hours; }
    public int getMin() { return this.minutes; }
    public int getSec() { return this.seconds; }

    /* Member functions to display time in HH:MM:SS */
    void display() {
        String time;
        time = (hours / 10 == 0) ? "0" : "";
        time += String.valueOf(hours);
        time += (minutes / 10 == 0) ? ":0" : ":";
        time += String.valueOf(minutes);
        time += (seconds / 10 == 0) ? ":0" : ":";
        time += String.valueOf(seconds);
        System.out.println(time);
    }
    /* Member functions to add two time variables */
    Time add(Time time1, Time time2) {
        int hrsAdd = time1.getHrs() + time2.getHrs();
        if (hrsAdd >= 24)
            hrsAdd -= 24;
        int minAdd = time1.getMin() + time2.getMin();
        if (minAdd >= 60) {
            minAdd -= 60;
            hrsAdd += 1;
        }
        int secAdd = time1.getSec() + time2.getSec();
        if (secAdd >= 60) {
            secAdd -= 60;
            minAdd += 1;
        }
        return new Time(hrsAdd, minAdd, secAdd);
    }
}

public class Main {

    public static void main(String[] args) {
        /* Initialized Time objects */
        Time time1 = new Time(7, 45, 30);
        Time time2 = new Time(19, 15, 45);

        /* Uninitialized Time object */
        Time time3 = new Time();

        /* Adding Time objects */
        time3 = time3.add(time1, time2);

        /* Calling copy constructor */
        Time time4 = time3;

        /* Displaying results */
        System.out.print("Time 1: "); time1.display();
        System.out.print("Time 2: "); time2.display();
        System.out.print("Time 3: "); time3.display();
        System.out.print("Time 4: "); time4.display();
    }
}