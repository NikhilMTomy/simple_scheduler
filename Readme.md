# Simple Scheduler

A simple program scheduler for linux.

## Installing

Clone the repo
```
git clone https://github.com/simple_scheduler
```
Install
```
cd simple_scheduler
make && sudo make install
```
Install and start the default the service
```
sudo cp config/simple_scheduler.service /etc/systemd/system/
sudo systemctl enable simple_scheduler
sudo systemctl start simple_scheduler
sudo systemctl status simple_scheduler
```
To use the default battery monitor install it from http://github.com/nikhilmtomy/battery-monitor
	
## Configuration

Default configuration
```
#  Name<tab>User<tab>Interval<tab>Exectuable
Battery Monitor	user	1	/usr/local/bin/battery-monitor
```
Lines starting with `#` is considered as a comment and ignored by the parser.  
Each configuration line specifies an executable to run with the following paramters.  

 - Name (Just a name for identification)
 - User (The user with which the program is to be run)
 - Interval (The interval between the executaion of the executable)
 - Executable Location (The absolute location of the executable)

Example
    
 - Battery Monitor
 - user
 - 1
 - /usr/local/bin/battery-monitor

The above example wil run the executable `/usr/local/bin/battery-monitor/` each minute as the user `user`